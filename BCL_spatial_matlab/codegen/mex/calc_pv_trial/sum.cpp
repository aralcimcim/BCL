//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sum.cpp
//
// Code generation for function 'sum'
//

// Include files
#include "sum.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>

// Function Definitions
namespace coder {
void b_sum(const real_T x_data[], const int32_T x_size[3], real_T y_data[],
           int32_T y_size[2])
{
  int32_T vlen;
  vlen = x_size[2];
  if (x_size[2] == 0) {
    y_size[0] = static_cast<int8_T>(x_size[0]);
    y_size[1] = static_cast<int8_T>(x_size[1]);
    vlen = static_cast<int8_T>(x_size[0]) * static_cast<int8_T>(x_size[1]);
    if (vlen - 1 >= 0) {
      std::memset(&y_data[0], 0, static_cast<uint32_T>(vlen) * sizeof(real_T));
    }
  } else {
    int32_T vstride_tmp;
    vstride_tmp = x_size[0] * x_size[1];
    y_size[0] = static_cast<int8_T>(x_size[0]);
    y_size[1] = static_cast<int8_T>(x_size[1]);
    std::copy(&x_data[0], &x_data[vstride_tmp], &y_data[0]);
    for (int32_T k{2}; k <= vlen; k++) {
      int32_T scalarLB;
      int32_T vectorUB;
      int32_T xoffset;
      xoffset = (k - 1) * vstride_tmp;
      scalarLB = (vstride_tmp / 2) << 1;
      vectorUB = scalarLB - 2;
      for (int32_T xj{0}; xj <= vectorUB; xj += 2) {
        __m128d r;
        __m128d r1;
        r = _mm_loadu_pd(&y_data[xj]);
        r1 = _mm_loadu_pd(&x_data[xoffset + xj]);
        _mm_storeu_pd(&y_data[xj], _mm_add_pd(r, r1));
      }
      for (int32_T xj{scalarLB}; xj < vstride_tmp; xj++) {
        y_data[xj] += x_data[xoffset + xj];
      }
    }
  }
}

void sum(const real_T x_data[], const int32_T x_size[2], real_T y_data[],
         int32_T y_size[2])
{
  if (x_size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    int32_T i;
    y_size[0] = 1;
    y_size[1] = x_size[1];
    i = x_size[1];
    for (int32_T col{0}; col < i; col++) {
      y_data[col] = sumColumnB(x_data, col + 1);
    }
  }
}

} // namespace coder

// End of code generation (sum.cpp)
