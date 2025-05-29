//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sub2ind.h
//
// Code generation for function 'sub2ind'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
namespace internal {
int32_T sub2ind(const emlrtStack &sp, const int32_T siz[2],
                const real_T varargin_1_data[], int32_T varargin_1_size,
                const real_T varargin_2_data[], int32_T varargin_2_size,
                int32_T idx_data[]);

}
} // namespace coder

// End of code generation (sub2ind.h)
