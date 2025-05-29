/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_px_training.h
 *
 * Code generation for function 'calc_px_training'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T calc_px_training(const emlrtStack *sp, const real_T X_data[],
                        const int32_T X_size[2], const real_T Y_data[],
                        const int32_T Y_size[2], const real_T Z_data[],
                        const int32_T Z_size[2], real_T lda, real_T eps,
                        real_T varargin_1);

/* End of code generation (calc_px_training.h) */
