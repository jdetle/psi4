/** Standard library includes */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector> 

/** Required PSI4 includes */ 
#include <psifiles.h>
#include <libciomr/libciomr.h> 
#include <libpsio/psio.h>
#include <libchkpt/chkpt.h>
#include <libpsio/psio.hpp>
#include <libchkpt/chkpt.hpp>
#include <libiwl/iwl.h>
#include <libqt/qt.h>
#include <libtrans/mospace.h>
#include <libtrans/integraltransform.h>

/** Required libmints includes */
#include <libmints/mints.h>
#include <libmints/factory.h>
#include <libmints/wavefunction.h>

#include "occwave.h"
#include "defines.h"

using namespace boost;
using namespace psi;
using namespace std;

namespace psi{ namespace occwave{

void OCCWave::ocepa_response_pdms()
{   
        //fprintf(outfile,"\n response_pdms is starting... \n"); fflush(outfile);

        // Build G intermediates 
        timer_on("G int");
	ocepa_g_int(); 
        timer_off("G int");

 if (reference_ == "RESTRICTED") {
        // Initialize
	gamma1corr->zero();
	g1symm->zero();

        // OPDM
        timer_on("OPDM");
	// OO-block alpha contrb.
	#pragma omp parallel for
	for(int h = 0; h < nirrep_; ++h){
	  for(int i = 0 ; i < aoccpiA[h]; ++i){
            for(int j = 0 ; j < aoccpiA[h]; ++j){
                g1symm->set(h, i, j, GooA->get(h, i, j) + GooA->get(h, j, i));
            }
	  }
	}

	// VV-block alpha contrb.
        #pragma omp parallel for
	for(int h = 0; h < nirrep_; ++h){
	  for(int a = 0 ; a < avirtpiA[h]; ++a){
            for(int b = 0 ; b < avirtpiA[h]; ++b){
                int aa = a + occpiA[h];
                int bb = b + occpiA[h];
                g1symm->set(h, aa, bb, GvvA->get(h, a, b) + GvvA->get(h, b, a));
            }
	  }
	}

	g1symm->scale(-1.0);
	gamma1corr->copy(g1symm); // correlation opdm
  
        // REF contribution 
	// alpha contrb.
        #pragma omp parallel for
	for(int h=0; h<nirrep_; h++) {
	  if (occpiA[h] != 0) {
	    for (int i=0; i<occpiA[h];i++) {
	      g1symm->add(h,i,i,2.0);
	    }
	  }
	}
        timer_off("OPDM");

        //print
        if (print_ > 1) {
	  g1symm->print();
        }

        // TPDM
        timer_on("V int");
        v_int(); 
        timer_off("V int");
        timer_on("TPDM OOVV");
	tpdm_oovv();
        timer_off("TPDM OOVV");
        timer_on("TPDM OOOO");
	tpdm_oooo();
        timer_off("TPDM OOOO");

        if (twopdm_abcd_type == "COMPUTE") {
           timer_on("TPDM VVVV");
           ocepa_tpdm_vvvv();
           timer_off("TPDM VVVV");
        }

        timer_on("TPDM OVOV");
        tpdm_ovov();
        timer_off("TPDM OVOV");
        timer_on("TPDM REF");
	tpdm_ref(); 
        timer_off("TPDM REF");
        timer_on("TPDM CORR OPDM");
	tpdm_corr_opdm();
        timer_off("TPDM CORR OPDM");
 }// end if (reference_ == "RESTRICTED") 

 else if (reference_ == "UNRESTRICTED") {
        // Initialize
	gamma1corrA->zero();
	gamma1corrB->zero();
	g1symmA->zero();
	g1symmB->zero();

        // OPDM
        timer_on("OPDM");
	// OO-block alpha contrb.
	#pragma omp parallel for
	for(int h = 0; h < nirrep_; ++h){
	  for(int i = 0 ; i < aoccpiA[h]; ++i){
            for(int j = 0 ; j < aoccpiA[h]; ++j){
                g1symmA->set(h, i, j, GooA->get(h, i, j) + GooA->get(h, j, i));
            }
	  }
	}

	// OO-block beta contrb.
	#pragma omp parallel for
	for(int h = 0; h < nirrep_; ++h){
	  for(int i = 0 ; i < aoccpiB[h]; ++i){
            for(int j = 0 ; j < aoccpiB[h]; ++j){
                g1symmB->set(h, i, j, GooB->get(h, i, j) + GooB->get(h, j, i));
            }
	  }
	}

	// VV-block alpha contrb.
        #pragma omp parallel for
	for(int h = 0; h < nirrep_; ++h){
	  for(int a = 0 ; a < avirtpiA[h]; ++a){
            for(int b = 0 ; b < avirtpiA[h]; ++b){
                int aa = a + occpiA[h];
                int bb = b + occpiA[h];
                g1symmA->set(h, aa, bb, GvvA->get(h, a, b) + GvvA->get(h, b, a));
            }
	  }
	}

        // VV-block beta contrb.
        #pragma omp parallel for
	for(int h = 0; h < nirrep_; ++h){
	  for(int a = 0 ; a < avirtpiB[h]; ++a){
            for(int b = 0 ; b < avirtpiB[h]; ++b){
                int aa = a + occpiB[h];
                int bb = b + occpiB[h];
                g1symmB->set(h, aa, bb, GvvB->get(h, a, b) + GvvB->get(h, b, a));
            }
	  }
	}

	g1symmA->scale(-0.5);
	g1symmB->scale(-0.5);
	gamma1corrA->copy(g1symmA); // correlation opdm
	gamma1corrB->copy(g1symmB); // correlation opdm
  
        // REF contribution 
	// alpha contrb.
        #pragma omp parallel for
	for(int h=0; h<nirrep_; h++) {
	  if (occpiA[h] != 0) {
	    for (int i=0; i<occpiA[h];i++) {
	      g1symmA->add(h,i,i,1.0);
	    }
	  }
	}
	
	// beta contrb.
        #pragma omp parallel for
	for(int h=0; h<nirrep_; h++) {
	  if (occpiB[h] != 0) {
	    for (int i=0; i<occpiB[h];i++) {
	      g1symmB->add(h,i,i,1.0);
	    }
	  }
	}
        timer_off("OPDM");

        //print
        if (print_ > 1) {
	  g1symmA->print();
	  g1symmB->print();
        }

        // TPDM
        timer_on("V int");
        v_int(); 
        timer_off("V int");
        timer_on("TPDM OOVV");
	tpdm_oovv();
        timer_off("TPDM OOVV");
        timer_on("TPDM OOOO");
	tpdm_oooo();
        timer_off("TPDM OOOO");

        if (twopdm_abcd_type == "COMPUTE") {
           timer_on("TPDM VVVV");
           ocepa_tpdm_vvvv();
           timer_off("TPDM VVVV");
        }

        timer_on("TPDM OVOV");
        tpdm_ovov();
        timer_off("TPDM OVOV");
        timer_on("TPDM VOVO");
        tpdm_vovo();
        timer_off("TPDM VOVO");
        timer_on("TPDM OVVO");
        tpdm_ovvo();
        timer_off("TPDM OVVO");
        timer_on("TPDM REF");
	tpdm_ref(); 
        timer_off("TPDM REF");
        timer_on("TPDM CORR OPDM");
	tpdm_corr_opdm();
        timer_off("TPDM CORR OPDM");
 }// end if (reference_ == "UNRESTRICTED") 
  //fprintf(outfile,"\n response_pdms done... \n"); fflush(outfile);
} // end of response_pdms
}} // End Namespaces




