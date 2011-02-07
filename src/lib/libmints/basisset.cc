/*!
    \defgroup MINTS libmints: Integral library
    \ingroup MINTS
*/

#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <libciomr/libciomr.h>
#include <libparallel/parallel.h>
#include <psifiles.h>

#include "vector3.h"
#include "molecule.h"
#include "basisset.h"
#include "dimension.h"
#include "sobasis.h"
#include "integral.h"
#include "symmetry.h"
#include "gshell.h"
#include "factory.h"
#include "basisset_parser.h"
#include "pointgrp.h"
#include "wavefunction.h"

using namespace std;
using namespace psi;
using namespace boost;

once_flag BasisSet::initialized_shared_ = BOOST_ONCE_INIT;

std::vector<Vector3> BasisSet::exp_ao[LIBINT_MAX_AM];

BasisSet::BasisSet()
{
    call_once(initialize_singletons, initialized_shared_);
}

BasisSet::~BasisSet()
{

}

void BasisSet::initialize_singletons()
{
    // Populate the exp_ao arrays
    for (int l=0; l<LIBINT_MAX_AM; ++l) {
        for (int i=0; i<=l; ++i) {
            int x = l-i;
            for (int j=0; j<=i; ++j) {
                int y = i-j;
                int z = j;

                Vector3 xyz_ao(x, y, z);
                BasisSet::exp_ao[l].push_back(xyz_ao);
            }
        }
    }
}

void BasisSet::print(FILE *out) const
{
    fprintf(out, "  Basis Set\n");
    fprintf(out, "    Number of shells: %d\n", nshell());
    fprintf(out, "    Number of basis function: %d\n", nbf());
    fprintf(out, "    Number of Cartesian functions: %d\n", nao());
    fprintf(out, "    Spherical Harmonics?: %s\n", has_puream() ? "true" : "false");
    fprintf(out, "    Max angular momentum: %d\n\n", max_am());

//    fprintf(out, "    Shells:\n\n");
//    for (int s=0; s<nshell(); ++s)
//        shells_[s]->print(out);
}
void BasisSet::print_by_level(FILE* out, int level) const
{
    if (level < 1)
        return;
    else if (level == 1)
        print(out);
    else if (level == 2)
        print_summary(out);
    else if (level > 2)
        print_detail(out);
}
void BasisSet::print_summary(FILE* out) const
{
    fprintf(out, "  -AO BASIS SET INFORMATION:\n");
    fprintf(out, "    Total number of shells = %d\n", nshell_);
    fprintf(out, "    Number of primitives   = %d\n", nprimitive_);
    fprintf(out, "    Number of AO           = %d\n", nao_);
    fprintf(out, "    Number of SO           = %d\n", nbf_);
    fprintf(out, "    Maximum AM             = %d\n", max_am_);
    fprintf(out, "    Spherical Harmonics    = %s\n", (puream_ ? "TRUE" : "FALSE"));
    fprintf(out, "\n");

    fprintf(out,"  -Contraction Scheme:\n");
    fprintf(out, "    Atom   Type   All Primitives // Shells:\n");
    fprintf(out, "   ------ ------ --------------------------\n");

    int nprims[max_am_ + 1];
    int nunique[max_am_ + 1];
    int nshells[max_am_ + 1];
    char amtypes[max_am_ + 1];

    for (int A = 0; A < molecule_->natom(); A++) {

        memset((void*) nprims , '\0', (max_am_ + 1) * sizeof(int));
        memset((void*) nunique, '\0', (max_am_ + 1) * sizeof(int));
        memset((void*) nshells, '\0', (max_am_ + 1) * sizeof(int));

        fprintf(out, "    %4d    ", A+1);
        fprintf(out, "%2s     ", molecule_->label(A).c_str());

        int first_shell = center_to_shell_[A];
        int n_shell = center_to_nshell_[A];
        shared_ptr<GaussianShell> shell;

        for (int Q = 0; Q < n_shell; Q++) {
            shell = shells_[Q + first_shell];
            nshells[shell->am()]++;
            nunique[shell->am()]+= shell->nprimitive();
            nprims [shell->am()]+= shell->nprimitive();
            amtypes[shell->am()] = shell->amchar();
        }

        // All Primitives
        for (int l = 0; l < max_am_ + 1; l++) {
            if (nprims[l] == 0)
                continue;
            fprintf(out, "%d%c ", nprims[l], amtypes[l]);
        }
        // Shells
        fprintf(out, "// ");
        for (int l = 0; l < max_am_ + 1; l++) {
            if (nshells[l] == 0)
                continue;
            fprintf(out, "%d%c ", nshells[l], amtypes[l]);
        }

        fprintf(out, "\n");
    }

    fprintf(out, "\n");
}

void BasisSet::print_detail(FILE* out) const
{
    print_summary(out);

    //TODO: Use unique atoms (C1 for now)
    for (int A = 0; A < molecule_->natom(); A++) {
        fprintf(out, "  -Basis set on unique center %d: %s\n", A+1,molecule_->label(A).c_str());

        shared_ptr<GaussianShell> shell;
        int first_shell = center_to_shell_[A];
        int n_shell = center_to_nshell_[A];

        for (int Q = 0; Q < n_shell; Q++) {
            shell = shells_[Q + first_shell];

            for (int K = 0; K < shell->nprimitive(); K++) {
                if (K == 0)
                    fprintf(outfile, "     %c ", shell->AMCHAR());
                else
                    fprintf(outfile, "       ");
                fprintf(outfile, "(%20.8f %20.8f)\n",shell->exp(K), shell->coef(K));

            }
        }
        fprintf(out, "\n");
    }
}


shared_ptr<GaussianShell> BasisSet::shell(int si) const
{
    if (si < 0 || si > nshell())
        throw PSIEXCEPTION("BasisSet::shell: requested shell is out-of-bounds.");
    return shells_[si];
}

shared_ptr<GaussianShell> BasisSet::shell(int center, int si) const
{
    return shell(center_to_shell_[center] + si);
}

shared_ptr<BasisSet> BasisSet::zero_ao_basis_set()
{
    shared_ptr<BasisSet> new_basis(new BasisSet());

    // Setup all the parameters needed for a zero basis set
//    new_basis->shell_first_basis_function_ = NULL;
//    new_basis->shell_first_ao_ = NULL;
//    new_basis->shell_center_ = new int[1];
//    new_basis->shell_center_[0] = 0;
    new_basis->shell_center_.push_back(0);
    new_basis->max_nprimitive_ = 1;
    new_basis->max_am_ = 0;

    new_basis->puream_ = false;

    // Add "ghost" atom to the molecule for this basis
    new_basis->molecule_ = shared_ptr<Molecule>(new Molecule);
    // Ghost atoms are now handled differently, they are not added to the normal xyz information array,
    // but to the fxyz array.
    new_basis->molecule_->add_atom(0, 0.0, 0.0, 0.0);
    Vector3 center = new_basis->molecule_->fxyz(0);

    new_basis->nshell_ = 1;
    new_basis->nprimitive_ = 1;
    new_basis->nao_ = 1;
    new_basis->nbf_ = 1;

    // Create shell array
    new_basis->shells_.push_back(shared_ptr<GaussianShell>(new GaussianShell));

    // Spherical and SO-transforms are expected even if not used.
//    new_basis->sphericaltransforms_.push_back(SphericalTransform(0));

    // Create out basis set arrays
    // null basis set
    int am   = 0;
    double e = 0.0;
    double c = 1.0;

    // Add the null-s-function
    new_basis->shells_[0]->init(1, &e, am, Cartesian, &c, 0, center, 0, Normalized);

    return new_basis;
}

shared_ptr<SOBasisSet> BasisSet::zero_so_basis_set(const shared_ptr<IntegralFactory>& factory)
{
    shared_ptr<BasisSet> zero = BasisSet::zero_ao_basis_set();
    shared_ptr<SOBasisSet> sozero(new SOBasisSet(zero, factory));
    return sozero;
}

shared_ptr<BasisSet> BasisSet::construct(const shared_ptr<BasisSetParser>& parser,
        const shared_ptr<Molecule>& mol,
        const std::string& basisname)
{
    // Construct vector with the same basis name for each element and pass to
    // the other version of construct
    vector<string> basisnames;

    // Update geometry in molecule, if there is a problem an exception is thrown
    mol->update_geometry();

    for (int i=0; i<mol->natom(); ++i) {
        basisnames.push_back(basisname);
    }

    return construct(parser, mol, basisnames);
}

shared_ptr<BasisSet> BasisSet::construct(const shared_ptr<BasisSetParser>& parser,
        const shared_ptr<Molecule>& mol,
        const std::vector<std::string>& basisnames)
{
    shared_ptr<BasisSet> basisset(new BasisSet);

    // Update geometry in molecule, if there is a problem an exception is thrown.
    mol->update_geometry();

    basisset->molecule_ = mol;
    parser->parse(basisset, basisnames);

    return basisset;
}

void BasisSet::refresh()
{
    // Reset data to initial values
    nshell_ = shells_.size();
    nprimitive_ = 0;
    nao_ = 0;
    nbf_ = 0;
    max_am_ = 0;
    max_nprimitive_ = 0;
    puream_ = false;

    shell_first_basis_function_.clear(); shell_first_basis_function_.resize(nshell_, 0);
    shell_first_ao_.clear();             shell_first_ao_.resize(nshell_, 0);
    shell_center_.clear();               shell_center_.resize(nshell_, 0);
    center_to_nshell_.clear();           center_to_nshell_.resize(molecule_->natom(), 0);
    center_to_shell_.clear();            center_to_shell_.resize(molecule_->natom(), 0);
    center_to_shell_[0] = 0;

    int current_center = 0;

    for (int i=0; i<nshell(); ++i) {
        shell_center_[i]   = shells_[i]->ncenter();
        shell_first_ao_[i] = nao_;
        shell_first_basis_function_[i] = nbf_;
        shells_[i]->set_function_index(nbf_);

        center_to_nshell_[shell_center_[i]]++;
        if (current_center != shell_center_[i]) {
            center_to_shell_[shell_center_[i]] = i;
            current_center = shell_center_[i];
        }

        nprimitive_ += shells_[i]->nprimitive();
        nao_        += shells_[i]->ncartesian();
        nbf_        += shells_[i]->nfunction();

        if (max_am_ < shells_[i]->am())
            max_am_ = shells_[i]->am();

        if (max_nprimitive_ < shells_[i]->nprimitive())
            max_nprimitive_ = shells_[i]->nprimitive();

        if (puream_ == false && shells_[i]->is_pure())
            puream_ = true;
    }

    function_to_shell_.resize(nbf());
    int ifunc = 0;
    for (int i=0; i<nshell_; ++i) {
        int nfun = shell(i)->nfunction();
        for (int j=0; j<nfun; ++j) {
            function_to_shell_[ifunc] = i;
            ifunc++;
        }
    }
}
std::pair<std::vector<std::string>, boost::shared_ptr<BasisSet> > BasisSet::test_basis_set(int max_am)
{
    int max_centers = 4;
    int max_primitives = 10;
    int max_shells;

    std::vector<int> nprim;
    nprim.push_back(10);
    nprim.push_back(1);
    nprim.push_back(6);
    nprim.push_back(1);
    nprim.push_back(2);
    nprim.push_back(1);
    nprim.push_back(1);
    nprim.push_back(1);
    nprim.push_back(1);
    nprim.push_back(1);

    std::vector<int> am;
    am.push_back(0);
    am.push_back(0);
    am.push_back(1);
    am.push_back(1);
    am.push_back(2);
    am.push_back(2);
    am.push_back(3);
    am.push_back(4);
    am.push_back(5);
    am.push_back(2);

    std::vector<double*> c;
    c.push_back(new double[10]);
    c.push_back(new double[1]);
    c.push_back(new double[6]);
    c.push_back(new double[1]);
    c.push_back(new double[2]);
    c.push_back(new double[1]);
    c.push_back(new double[1]);
    c.push_back(new double[1]);
    c.push_back(new double[1]);
    c.push_back(new double[1]);

    std::vector<double*> e;
    e.push_back(new double[10]);
    e.push_back(new double[1]);
    e.push_back(new double[6]);
    e.push_back(new double[1]);
    e.push_back(new double[2]);
    e.push_back(new double[1]);
    e.push_back(new double[1]);
    e.push_back(new double[1]);
    e.push_back(new double[1]);
    e.push_back(new double[1]);

    c[0][0] = 0.458878E-03;
    c[0][1] = 0.355070E-02;
    c[0][2] = 0.182618E-01;
    c[0][3] = 0.716650E-01;
    c[0][4] = 0.212346E+00;
    c[0][5] = 0.416203E+00;
    c[0][6] = 0.373020E+00;
    c[0][7] = 0.625054E-01;
    c[0][8] = 0.624532E-02;
    c[0][9] = 0.243374E-02;
    c[1][0] =     1.0;
    c[2][0] = 0.458878E-03;
    c[2][1] = 0.355070E-02;
    c[2][2] = 0.182618E-01;
    c[2][3] = 0.716650E-01;
    c[2][4] = 0.212346E+00;
    c[2][5] = 0.416203E+00;
    c[3][0] =     1.0;
    c[4][0] = 0.458878E-03;
    c[4][1] = 0.355070E-02;
    c[5][0] =     1.0;
    c[6][0] =     1.0;
    c[7][0] =     1.0;
    c[8][0] =     1.0;
    c[9][0] =     1.0;

    e[0][0] = 31700.0;
    e[0][1] =  4755.0;
    e[0][2] =  1082.0;
    e[0][3] =   306.0;
    e[0][4] =    99.0;
    e[0][5] =    33.0;
    e[0][6] =    13.0;
    e[0][7] =     4.0;
    e[0][8] =     2.0;
    e[0][9] =     0.5;
    e[1][0] =     1.0;
    e[2][0] = 31700.0;
    e[2][1] =  4755.0;
    e[2][2] =  1082.0;
    e[2][3] =   306.0;
    e[2][4] =    99.0;
    e[2][5] =    33.0;
    e[3][0] =     1.0;
    e[4][0] = 31700.0;
    e[4][1] =  4755.0;
    e[5][0] =     1.0;
    e[6][0] =     1.0;
    e[7][0] =     1.0;
    e[8][0] =     1.0;
    e[9][0] =     1.0;

    std::vector<std::string> labels;
    if (max_am > -1) {
        labels.push_back("S");
        labels.push_back("s");
        max_shells = 2;
    }
        labels.push_back("P");
    if (max_am > 0) {
        labels.push_back("p");
        max_shells = 4;
    }
    if (max_am > 1) {
        labels.push_back("D");
        labels.push_back("d");
        max_shells = 6;
    }
    if (max_am > 2) {
        labels.push_back("f");
        max_shells = 7;
    }
    if (max_am > 3) {
        labels.push_back("g");
        max_shells = 8;
    }
    if (max_am > 4) {
        labels.push_back("h");
        max_shells = 9;
    }
    if (max_am > 5) {
        labels.push_back("i");
        max_shells = 10;
    }

    shared_ptr<BasisSet> new_basis(new BasisSet());

    // Add 4 atoms to the molecule for this basis (max integal centers is 4 at the moment)
    new_basis->molecule_ = shared_ptr<Molecule>(new Molecule);
    // Ghost atoms are now handled differently, they are not added to the normal xyz information array,
    // but to the fxyz array.
    double x = 0.0;
    for (int A = 0; A < max_centers; A++) {
        new_basis->molecule_->add_atom(0, x, x, x);
        x += 1.0;
    }

    // Setup all the parameters needed for a zero basis set
    new_basis->shell_center_.resize(max_shells * max_centers);
    for (int A = 0; A < max_centers; A++)
        for (int Q = 0; Q < max_shells; Q++)
            new_basis->shell_center_[A*max_shells + Q] = A;
    new_basis->max_nprimitive_ = max_primitives;
    new_basis->max_am_ = max_am;

    // We'll time puream for now
    new_basis->puream_ = true;

    // Create shell array
    for (int A = 0; A < max_centers; A++)
        for (int Q = 0; Q < max_shells; Q++)
            new_basis->shells_.push_back(shared_ptr<GaussianShell>(new GaussianShell));
    // Add shells
    for (int A = 0; A < max_centers; A++) {
        Vector3 center = new_basis->molecule_->fxyz(A);
        for (int Q = 0; Q < max_shells; Q++) {
            new_basis->shells_[A*max_shells + Q]->init(nprim[Q], e[Q], am[Q], Pure, c[Q], A, center, 0, Normalized);
        }
    }

    // Initialize SphericalTransform
    //for (int i=0; i<=max_am; ++i) {
    //    new_basis->sphericaltransforms_.push_back(SphericalTransform(i));
    //}
    //new_basis->refresh();

    /**
    //Initialize SOTransform
    new_basis->sotransform_ = shared_ptr<SOTransform>(new SOTransform);
    new_basis->sotransform_->init(new_basis->nshell());

    int so_global=0;
    int ao_global=0;
    for (int i=0; i < new_basis->nshell(); ++i) {
        SphericalTransform st(new_basis->shell(i)->am());
        SphericalTransformIter iter(st);

        ao_global = new_basis->shell_to_function(i);
        so_global = new_basis->shell_to_basis_function(i);

        for (iter.first(); !iter.is_done(); iter.next()) {
            new_basis->sotransform_->add_transform(i, 0, iter.pureindex() + so_global, iter.coef(),
                                                  iter.cartindex(), iter.pureindex() + so_global);
        }
    }
    **/

    new_basis->refresh();

    for (int A = 0; A < e.size(); A++) {
        delete[] e[A];
        delete[] c[A];
    }

    return make_pair(labels, new_basis);
}

shared_ptr<BasisSet> BasisSet::atomic_basis_set(int center)
{
    //May only work in C1!!!!
    //Construct a blank BasisSet on the heap
    shared_ptr<BasisSet> bas(new BasisSet);
    //Construct a blank Molecule on the heap
    shared_ptr<Molecule> mol(new Molecule);

    int Z = molecule_->Z(center);
    double x = molecule_->x(center);
    double y = molecule_->y(center);
    double z = molecule_->z(center);
    double mass = molecule_->fmass(center);
    double charge = molecule_->fcharge(center);
    std::string lab = molecule_->flabel(center);
    char* label = new char[lab.length() + 1];
    strcpy(label,lab.c_str());

    //Put the atomic info into mol
    mol->add_atom(Z, 0.0, 0.0, 0.0, label, mass, charge);
    Vector3 v(0.0,0.0,0.0);

    //Assign the atomic molecule to bas
    bas->molecule_ = mol;

    //Go through shells in current basis set
    //Push shells that belong to center
    //to bas
    int current_shells = 0;
    int shell_start = -1;
    int ao_start = 0;
    int so_start = 0;
    for (int i = 0; i<nshell(); i++) {
        if (shell_center_[i] < center) {
            ao_start += shells_[i]->ncartesian();
            so_start += shells_[i]->nfunction();
        }
        if (shell_center_[i] == center) {
            if (shell_start == -1)
                shell_start = i;
            shared_ptr<GaussianShell> shell(new GaussianShell);
            int nprm = shells_[i]->nprimitive();
            int am = shells_[i]->am();
            GaussianType harmonics = (shells_[i]->is_pure() ? Pure : Cartesian);
            int nc = 0; // In the atomic basis, always on the 0th atom
            int start = 0; //Will be reset later
            double* e = shells_[i]->exps();
            double* c = shells_[i]->coefs();

            shell->init(nprm,e,am, harmonics, c,nc,
              v,start);

            bas->shells_.push_back(shell);
            current_shells++;
        }
        if (shell_center_[i] > center)
            break;
    }

    //Setup the indexing in the atomic basis
    bas->refresh();

    //And ... return
    return bas;
}

