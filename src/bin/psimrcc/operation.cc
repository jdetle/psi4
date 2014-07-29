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

#include <libutil/libutil.h>
#include <cstdio>

#include "blas.h"
#include "debugging.h"
#include "matrix.h"
#include "psi4-dec.h"
namespace psi{
    extern FILE *outfile;
    namespace psimrcc{

double* CCOperation::local_work = NULL;
double* CCOperation::out_of_core_buffer = NULL;
double CCOperation::zero_timing=0.0;
double CCOperation::numerical_timing=0.0;
double CCOperation::contract_timing=0.0;
double CCOperation::tensor_timing=0.0;
double CCOperation::dot_timing=0.0;
double CCOperation::plus_timing=0.0;
double CCOperation::product_timing=0.0;
double CCOperation::division_timing=0.0;
double CCOperation::sort_timing=0.0;
double CCOperation::PartA_timing=0.0;
double CCOperation::PartB_timing=0.0;
double CCOperation::PartC_timing=0.0;

CCOperation::CCOperation(double in_factor,std::string in_assignment,
            std::string in_reindexing,std::string in_operation,
            CCMatrix* in_A_Matrix, CCMatrix* in_B_Matrix, CCMatrix* in_C_Matrix,double* work,double* buffer)
: factor(in_factor), assignment(in_assignment), reindexing(in_reindexing),operation(in_operation),
A_Matrix(in_A_Matrix),B_Matrix(in_B_Matrix),C_Matrix(in_C_Matrix)
{
  local_work = work;
  out_of_core_buffer = buffer;
}

CCOperation::~CCOperation()
{
}

void CCOperation::print()
{
  if(reindexing.size())
    psi::fprintf(outfile,"\n\tReindexing = %s",reindexing.c_str());
  psi::fprintf(outfile,"\n\tNumericalFactor = %lf",factor);
  psi::fprintf(outfile,"\tAssigment = %s",assignment.c_str());
  psi::fprintf(outfile,"\tOperation = %s",operation.c_str());
  psi::fprintf(outfile,"\n\tA = %s",A_Matrix->get_label().c_str());
  if(B_Matrix!=NULL)
    psi::fprintf(outfile,"\tB = %s",B_Matrix->get_label().c_str());
  if(C_Matrix!=NULL)
    psi::fprintf(outfile,"\tC = %s",C_Matrix->get_label().c_str());
}

void CCOperation::print_operation()
{
  psi::fprintf(outfile,"%s",A_Matrix->get_label().c_str());
  psi::fprintf(outfile," %s",assignment.c_str());
  if(reindexing.size())
    psi::fprintf(outfile," %s",reindexing.c_str());
  psi::fprintf(outfile," %lf",factor);
  if(B_Matrix!=NULL)
    psi::fprintf(outfile," %s",B_Matrix->get_label().c_str());
  psi::fprintf(outfile," %s",operation.c_str());
  if(C_Matrix!=NULL)
    psi::fprintf(outfile," %s",C_Matrix->get_label().c_str());
}

void CCOperation::print_timing()
{
  DEBUGGING(1,
  psi::fprintf(outfile,"\n-----------------------------------------");
  psi::fprintf(outfile,"\nzero_timing             = %f",zero_timing);
  psi::fprintf(outfile,"\nnumerical_timing        = %f",numerical_timing);
  psi::fprintf(outfile,"\ncontract_timing         = %f",contract_timing);
  psi::fprintf(outfile,"\ntensor_timing           = %f",tensor_timing);
  psi::fprintf(outfile,"\ndot_timing              = %f",dot_timing);
  psi::fprintf(outfile,"\nplus_timing             = %f",plus_timing);
  psi::fprintf(outfile,"\nproduct_timing          = %f",product_timing);
  psi::fprintf(outfile,"\ndivision_timing         = %f",division_timing);
  psi::fprintf(outfile,"\nsort_timing             = %f",sort_timing);
  psi::fprintf(outfile,"\nPartA_timing            = %f",PartA_timing);
  psi::fprintf(outfile,"\nPartB_timing            = %f",PartB_timing);
  psi::fprintf(outfile,"\nPartC_timing            = %f",PartC_timing);
  psi::fprintf(outfile,"\n-----------------------------------------\n");
  );
}

}} /* End Namespaces */
