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

#include <libparallel/parallel.h>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <psiconfig.h>
#include <psi4-dec.h>

#include "gitversion.h"

namespace psi {

/*! Print PSI version information that was set in configure.ac */
void print_version(FILE *myout)
{
  psi::fprintf(myout, "    -----------------------------------------------------------------------\n");
  psi::fprintf(myout, "          PSI4: An Open-Source Ab Initio Electronic Structure Package\n");
  psi::fprintf(myout, "                              PSI %s Driver\n", PSI_VERSION);

  // Are we using git? If so,what version string
#ifdef GIT_VERSION
  psi::fprintf(myout, "\n               Git: Rev " GIT_VERSION "\n");
#endif

  psi::fprintf(myout, "\n");
  psi::fprintf(myout, "    J. M. Turney, A. C. Simmonett, R. M. Parrish, E. G. Hohenstein,\n");
  psi::fprintf(myout, "    F. A. Evangelista, J. T. Fermann, B. J. Mintz, L. A. Burns, J. J. Wilke,\n");
  psi::fprintf(myout, "    M. L. Abrams, N. J. Russ, M. L. Leininger, C. L. Janssen, E. T. Seidl,\n");
  psi::fprintf(myout, "    W. D. Allen, H. F. Schaefer, R. A. King, E. F. Valeev, C. D. Sherrill,\n");
  psi::fprintf(myout, "    and T. D. Crawford, WIREs Comput. Mol. Sci. 2, 556-565 (2012)\n");
  psi::fprintf(myout, "    (doi: 10.1002/wcms.93)\n");

  psi::fprintf(myout, "\n");
  psi::fprintf(myout, "                         Additional Contributions by\n");
  psi::fprintf(myout, "    A. E. DePrince, M. Saitow, U. Bozkaya, A. Yu. Sokolov\n");
  psi::fprintf(myout, "    -----------------------------------------------------------------------\n\n");
  pid_t pid = getpid();
  psi::fprintf(myout, "    Process ID: %6d\n",pid);
  psi::fprintf(myout, "    PSI4DATADIR: %s\n", Process::environment("PSIDATADIR").c_str());
}

}
