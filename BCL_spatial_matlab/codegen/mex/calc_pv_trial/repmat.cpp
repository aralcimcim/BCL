//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "rt_nonfinite.h"
#include <cstddef>

// Function Definitions
namespace coder {
int32_T repmat(ptrdiff_t a, int32_T varargin_1, ptrdiff_t b_data[])
{
  int32_T b_size;
  b_size = varargin_1;
  for (int32_T i{0}; i < varargin_1; i++) {
    b_data[i] = a;
  }
  return b_size;
}

} // namespace coder

// End of code generation (repmat.cpp)
