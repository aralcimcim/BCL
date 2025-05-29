//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sum.h
//
// Code generation for function 'sum'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
void b_sum(const real_T x_data[], const int32_T x_size[3], real_T y_data[],
           int32_T y_size[2]);

void sum(const real_T x_data[], const int32_T x_size[2], real_T y_data[],
         int32_T y_size[2]);

} // namespace coder

// End of code generation (sum.h)
