//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// diag.cpp
//
// Code generation for function 'diag'
//

// Include files
#include "diag.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace coder {
void diag(const real_T v_data[], int32_T v_size, real_T d_data[],
          int32_T d_size[2])
{
  int32_T loop_ub;
  d_size[0] = v_size;
  d_size[1] = v_size;
  loop_ub = v_size * v_size;
  if (loop_ub - 1 >= 0) {
    std::memset(&d_data[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }
  for (loop_ub = 0; loop_ub < v_size; loop_ub++) {
    d_data[loop_ub + v_size * loop_ub] = v_data[loop_ub];
  }
}

} // namespace coder

// End of code generation (diag.cpp)
