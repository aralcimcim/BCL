//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sub2ind.cpp
//
// Code generation for function 'sub2ind'
//

// Include files
#include "sub2ind.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRTEInfo n_emlrtRTEI{
    28,        // lineNo
    19,        // colNo
    "sub2ind", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sub2ind.m" // pName
};

static emlrtRTEInfo o_emlrtRTEI{
    18,        // lineNo
    23,        // colNo
    "sub2ind", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/sub2ind.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
int32_T sub2ind(const emlrtStack &sp, const int32_T siz[2],
                const real_T varargin_1_data[], int32_T varargin_1_size,
                const real_T varargin_2_data[], int32_T varargin_2_size,
                int32_T idx_data[])
{
  int32_T idx_size;
  int32_T k;
  uint8_T varargin_1[2];
  uint8_T varargin_2[2];
  boolean_T exitg1;
  boolean_T p;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= varargin_1_size - 1)) {
    if (!(varargin_1_data[k] <= 12.0)) {
      emlrtErrorWithMessageIdR2018a(&sp, &n_emlrtRTEI,
                                    "MATLAB:sub2ind:IndexOutOfRange",
                                    "MATLAB:sub2ind:IndexOutOfRange", 0);
    } else {
      k++;
    }
  }
  varargin_1[0] = static_cast<uint8_T>(varargin_1_size);
  varargin_1[1] = 1U;
  varargin_2[0] = static_cast<uint8_T>(varargin_2_size);
  varargin_2[1] = 1U;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (varargin_1[k] != varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&sp, &o_emlrtRTEI,
                                  "MATLAB:sub2ind:SubscriptVectorSize",
                                  "MATLAB:sub2ind:SubscriptVectorSize", 0);
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= varargin_2_size - 1)) {
    if (!(varargin_2_data[k] <= siz[1])) {
      emlrtErrorWithMessageIdR2018a(&sp, &n_emlrtRTEI,
                                    "MATLAB:sub2ind:IndexOutOfRange",
                                    "MATLAB:sub2ind:IndexOutOfRange", 0);
    } else {
      k++;
    }
  }
  idx_size = varargin_1_size;
  for (k = 0; k < varargin_1_size; k++) {
    idx_data[k] = static_cast<int32_T>(varargin_1_data[k]) +
                  12 * (static_cast<int32_T>(varargin_2_data[k]) - 1);
  }
  return idx_size;
}

} // namespace internal
} // namespace coder

// End of code generation (sub2ind.cpp)
