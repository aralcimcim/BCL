/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "rt_nonfinite.h"

/* Function Definitions */
real_T sumColumnB(const real_T x_data[], int32_T vlen)
{
  real_T y;
  int32_T k;
  if (vlen <= 1024) {
    int32_T i;
    y = x_data[0];
    i = (uint16_T)(vlen - 1);
    for (k = 0; k < i; k++) {
      y += x_data[k + 1];
    }
  } else {
    real_T b_y;
    int32_T i;
    y = x_data[0];
    for (k = 0; k < 1023; k++) {
      y += x_data[k + 1];
    }
    b_y = x_data[1024];
    i = (uint16_T)(vlen - 1025);
    for (k = 0; k < i; k++) {
      b_y += x_data[k + 1025];
    }
    y += b_y;
  }
  return y;
}

/* End of code generation (sumMatrixIncludeNaN.c) */
