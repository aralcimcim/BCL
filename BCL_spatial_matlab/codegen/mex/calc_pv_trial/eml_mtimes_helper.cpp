//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eml_mtimes_helper.cpp
//
// Code generation for function 'eml_mtimes_helper'
//

// Include files
#include "eml_mtimes_helper.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRTEInfo
    j_emlrtRTEI{
        138,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

static emlrtRTEInfo
    k_emlrtRTEI{
        133,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

// Function Definitions
namespace coder {
void dynamic_size_checks(const emlrtStack &sp, const int32_T a_size[2],
                         const int32_T b_size[2], int32_T innerDimA,
                         int32_T innerDimB)
{
  if (innerDimA != innerDimB) {
    if (((a_size[0] == 1) && (a_size[1] == 1)) ||
        ((b_size[0] == 1) && (b_size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &k_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&sp, &j_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
}

} // namespace coder

// End of code generation (eml_mtimes_helper.cpp)
