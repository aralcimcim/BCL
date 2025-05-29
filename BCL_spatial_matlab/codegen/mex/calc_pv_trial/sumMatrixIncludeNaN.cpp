//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sumMatrixIncludeNaN.cpp
//
// Code generation for function 'sumMatrixIncludeNaN'
//

// Include files
#include "sumMatrixIncludeNaN.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
real_T sumColumnB(const real_T x_data[], int32_T col)
{
  real_T y;
  int32_T i0;
  i0 = (col - 1) * 12;
  y = x_data[i0];
  for (int32_T k{0}; k < 11; k++) {
    y += x_data[(i0 + k) + 1];
  }
  return y;
}

} // namespace coder

// End of code generation (sumMatrixIncludeNaN.cpp)
