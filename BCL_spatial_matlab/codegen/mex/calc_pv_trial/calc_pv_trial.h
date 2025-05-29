//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calc_pv_trial.h
//
// Code generation for function 'calc_pv_trial'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void calc_pv_trial(const emlrtStack *sp, const real_T x[12], const real_T v[24],
                   const real_T y_data[], const int32_T y_size[1],
                   const real_T Z_data[], const int32_T Z_size[2],
                   real_T sigmaU, real_T sigmaV, real_T phi,
                   coder::array<real_T, 2U> &SigmaCtllhInv, real_T wt_data[],
                   int32_T wt_size[3], real_T Psit[2], boolean_T zc_data[],
                   int32_T zc_size[2]);

// End of code generation (calc_pv_trial.h)
