//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// any1.cpp
//
// Code generation for function 'any1'
//

// Include files
#include "any1.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder {
boolean_T any(const real_T x_data[], int32_T x_size)
{
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= x_size)) {
    if ((x_data[ix] == 0.0) || muDoubleScalarIsNaN(x_data[ix])) {
      ix++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  return y;
}

} // namespace coder

// End of code generation (any1.cpp)
