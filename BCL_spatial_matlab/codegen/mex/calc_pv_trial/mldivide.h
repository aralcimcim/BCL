//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mldivide.h
//
// Code generation for function 'mldivide'
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
void mldivide(const emlrtStack &sp, const real_T A_data[],
              const int32_T A_size[2], const real_T B_data[],
              const int32_T B_size[2], real_T Y_data[], int32_T Y_size[2]);

}

// End of code generation (mldivide.h)
