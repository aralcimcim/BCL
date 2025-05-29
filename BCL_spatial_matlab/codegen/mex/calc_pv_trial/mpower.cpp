//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mpower.cpp
//
// Code generation for function 'mpower'
//

// Include files
#include "mpower.h"
#include "calc_pv_trial_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ab_emlrtRSI{
    71,                                                           // lineNo
    "power",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m" // pathName
};

static emlrtRTEInfo r_emlrtRTEI{
    82,                                                           // lineNo
    5,                                                            // colNo
    "fltpower",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m" // pName
};

// Function Definitions
namespace coder {
real_T mpower(const emlrtStack &sp, real_T a, real_T b)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &ab_emlrtRSI;
  if ((a < 0.0) && (!muDoubleScalarIsNaN(b)) && (muDoubleScalarFloor(b) != b)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &r_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  return muDoubleScalarPower(a, b);
}

} // namespace coder

// End of code generation (mpower.cpp)
