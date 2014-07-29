/*
 *@BEGIN LICENSE
 *
 * PSI4: an ab initio quantum chemistry software package
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *@END LICENSE
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>

#include <liboptions/liboptions.h>

#include "scf.h"

extern FILE* outfile;

namespace psi{ namespace mcscf{

void SCF::iterate_scf_equations()
{
  psi::fprintf(outfile,"\n\n  =========================================================================================");
  psi::fprintf(outfile,"\n         Cycle          Energy               D(Energy)            D(Density)            DIIS");
  psi::fprintf(outfile,"\n  ===========================================================================================");


  bool   converged  = false;
  int    cycle      = 0;
  double old_energy = 0.0;
  double new_energy = 0.0;
  while(!converged){
    C_T = C;
    C_T.transpose();
    
    //Save the odl matrix
    Dc_old = Dc;
    if(reference == tcscf){
      for(int I = 0 ; I < nci; ++I)
        Dtc_old[I] = Dtc[I];
    }

    // Guess the occupation
    guess_occupation();

    // Compute the density matrix
    density_matrix();

    // Form F in the AO basis
    construct_F();

    // Compute energy
    old_energy = new_energy;
    new_energy = energy(cycle,old_energy);
    double delta_energy = new_energy - old_energy;

    // Transform F to the MO basis
    transform(Fc,Fc_t,C);
    if(reference == rohf)
      transform(Fo,Fo_t,C);
    if(reference == tcscf){
      for(int I = 0 ; I < nci; ++I)
        transform(Ftc[I],Ftc_t[I],C);
      transform(Favg,Favg_t,C);
    }

    construct_Feff(cycle);

    if(use_diis){
      diis(cycle);
      if(cycle >= ndiis){
        Feff_oAO.diagonalize(C_t,epsilon);
        C.multiply(false,false,S_sqrt_inv,C_t);
        C_T = C;
        C_T.transpose();
      }else{
        Feff_t.diagonalize(C_t,epsilon);
        T.multiply(false,false,C,C_t);
        C = T;
      }
    }else{
      Feff_t.diagonalize(C_t,epsilon);
      T.multiply(false,false,C,C_t);
      C = T;
    }
    // Compute the change of the density matrix 
    Dc_old -= Dc;
    double delta_dens = dot(Dc_old,Dc_old);
    if(reference == tcscf){
      for(int I = 0 ; I < nci; ++I){
        Dtc_old[I] -= Dtc[I];
         delta_dens += dot(Dtc_old[I],Dtc_old[I]);
    }}

    double rms_dens = sqrt(delta_dens/(nso*nso*nci));

    //Print SCF energy,energy difference and RMS density change
     psi::fprintf(outfile,"\n  @SCF %4d  %20.12f %20.12f %20.12f",cycle,total_energy,total_energy-old_energy, rms_dens);
  if(reference == tcscf){
    psi::fprintf(outfile,"\n    ci      = [");
    for(int I = 0 ; I < nci; ++I)
      psi::fprintf(outfile,"%11.8f%s",ci[I], I != nci -1 ? "," : "");
    psi::fprintf(outfile,"]");

    psi::fprintf(outfile,"\n    ci_grad = [");
    for(int I = 0 ; I < nci; ++I)
      psi::fprintf(outfile,"%11.8f%s",ci_grad[I], I != nci -1 ? "," : "");
    psi::fprintf(outfile,"]");
  }
  fflush(outfile);

    if( (fabs(delta_energy) < options_.get_double("E_CONVERGENCE"))
          && (rms_dens < options_.get_double("D_CONVERGENCE") )){
      if(reference == tcscf){
        if(2.0 * fabs(norm_ci_grad) < options_.get_double("D_CONVERGENCE"))
          converged = true;
      }else{
        converged = true;
      }
    }

    if(cycle>options_.get_int("MAXITER")){
      psi::fprintf(outfile,"\n\n  The calculation did not converge in %d cycles",options_.get_int("MAXITER"));
      psi::fprintf(outfile,"\n  Quitting MCSCF.\n");
      fflush(outfile);
      exit(1);
    }

    cycle++;
  }

  psi::fprintf(outfile,"\n  =========================================================================================");

  psi::fprintf(outfile,"\n\n%6c* SCF total energy   = %20.12f\n",' ',new_energy);


  if(reference == tcscf){
    psi::fprintf(outfile,"\n\n      CI coefficients  = [");
    for(int I = 0 ; I < nci; ++I)
      psi::fprintf(outfile,"%12.9f%s",ci[I], I != nci -1 ? "," : "");
    psi::fprintf(outfile,"]");
  }

  if(moinfo_scf->get_guess_occupation()){
    psi::fprintf(outfile,"\n  Final occupation");
    psi::fprintf(outfile,"\n  docc = [");
    for(int h = 0; h < nirreps; ++h){
      psi::fprintf(outfile," %d",docc[h]);
      if(h==! nirreps)psi::fprintf(outfile,", ");
    }
    psi::fprintf(outfile," ]");
    psi::fprintf(outfile,"\n  actv = [");
    for(int h = 0; h < nirreps; ++h){
      psi::fprintf(outfile," %d",actv[h]);
      if(h==! nirreps)psi::fprintf(outfile,", ");
    }
    psi::fprintf(outfile," ]");
    int sym = 0;
    for(int h = 0; h < nirreps; ++h)
      for(int n = 0; n < actv[h]; ++n) sym ^= h;
    psi::fprintf(outfile,"\n  sym  = %d",sym);
  }

  psi::fprintf(outfile,"\n\n  End of SCF");
  fflush(outfile);
}

}} /* End Namespaces */
