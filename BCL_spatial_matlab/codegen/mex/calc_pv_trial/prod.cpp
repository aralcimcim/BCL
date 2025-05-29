//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// prod.cpp
//
// Code generation for function 'prod'
//

// Include files
#include "prod.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
real_T prod(const real_T x_data[], int32_T x_size)
{
  real_T y;
  if (x_size == 0) {
    y = 1.0;
  } else {
    y = x_data[0];
    for (int32_T k{2}; k <= x_size; k++) {
      y *= x_data[k - 1];
    }
  }
  return y;
}

} // namespace coder

// End of code generation (prod.cpp)
