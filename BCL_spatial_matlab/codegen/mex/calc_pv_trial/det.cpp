//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// det.cpp
//
// Code generation for function 'det'
//

// Include files
#include "det.h"
#include "calc_pv_trial_data.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>

// Variable Definitions
static emlrtRSInfo
    ob_emlrtRSI{
        27,       // lineNo
        "xgetrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgetrf.m" // pathName
    };

static emlrtRSInfo
    pb_emlrtRSI{
        91,             // lineNo
        "ceval_xgetrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgetrf.m" // pathName
    };

static emlrtRSInfo tc_emlrtRSI{
    21,                                                            // lineNo
    "det",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/det.m" // pathName
};

static emlrtRTEInfo p_emlrtRTEI{
    12,                                                            // lineNo
    15,                                                            // colNo
    "det",                                                         // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/det.m" // pName
};

// Function Definitions
namespace coder {
real_T det(const emlrtStack &sp, const real_T x_data[], const int32_T x_size[2])
{
  ptrdiff_t ipiv_t_data[16];
  ptrdiff_t tmp_data[16];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_x_data[256];
  real_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (x_size[0] != x_size[1]) {
    emlrtErrorWithMessageIdR2018a(&sp, &p_emlrtRTEI, "Coder:MATLAB:square",
                                  "Coder:MATLAB:square", 0);
  }
  if (x_size[0] == 0) {
    y = 1.0;
  } else {
    ptrdiff_t info_t;
    int32_T ipiv_data[16];
    int32_T i;
    int32_T loop_ub;
    int32_T x_size_idx_0;
    boolean_T isodd;
    st.site = &tc_emlrtRSI;
    x_size_idx_0 = x_size[0];
    loop_ub = x_size[0] * x_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&x_data[0], &x_data[loop_ub], &b_x_data[0]);
    }
    b_st.site = &ob_emlrtRSI;
    i = muIntScalarMin_sint32(x_size[0], x_size[1]);
    loop_ub = repmat((ptrdiff_t)0.0, muIntScalarMax_sint32(i, 1), tmp_data);
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)x_size[0],
                                 (ptrdiff_t)x_size[1], &b_x_data[0],
                                 (ptrdiff_t)x_size[0], &ipiv_t_data[0]);
    c_st.site = &pb_emlrtRSI;
    if ((int32_T)info_t < 0) {
      if ((int32_T)info_t == -1010) {
        emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &g_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      19, &cv[0], 12, (int32_T)info_t);
      }
    }
    i = loop_ub - 1;
    for (int32_T k{0}; k <= i; k++) {
      ipiv_data[k] = (int32_T)ipiv_t_data[k];
    }
    y = b_x_data[0];
    for (int32_T k{0}; k <= x_size_idx_0 - 2; k++) {
      y *= b_x_data[(k + x_size_idx_0 * (k + 1)) + 1];
    }
    isodd = false;
    for (int32_T k{0}; k <= loop_ub - 2; k++) {
      if (ipiv_data[k] > k + 1) {
        isodd = !isodd;
      }
    }
    if (isodd) {
      y = -y;
    }
  }
  return y;
}

} // namespace coder

// End of code generation (det.cpp)
