//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// find.cpp
//
// Code generation for function 'find'
//

// Include files
#include "find.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo v_emlrtRSI{
    144,                                                           // lineNo
    "eml_find",                                                    // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    402,                                                           // lineNo
    "find_first_indices",                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo jc_emlrtRSI{
    138,                                                           // lineNo
    "eml_find",                                                    // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo kc_emlrtRSI{
    253,                                                           // lineNo
    "find_first_nonempty_triples",                                 // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    254,                                                           // lineNo
    "find_first_nonempty_triples",                                 // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo mc_emlrtRSI{
    255,                                                           // lineNo
    "find_first_nonempty_triples",                                 // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRTEInfo e_emlrtRTEI{
    392,                                                           // lineNo
    1,                                                             // colNo
    "find_first_indices",                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    239,                                                           // lineNo
    1,                                                             // colNo
    "find_first_nonempty_triples",                                 // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

// Function Definitions
namespace coder {
int32_T eml_find(const emlrtStack &sp, const real_T x[12], int32_T i_data[])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_iv[2];
  int32_T i_size;
  int32_T ii;
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &v_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i_size = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 12)) {
    if (x[ii] != 0.0) {
      i_size++;
      i_data[i_size - 1] = ii + 1;
      if (i_size >= 12) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (i_size < 1) {
    i_size = 0;
  }
  b_iv[0] = 1;
  b_iv[1] = i_size;
  b_st.site = &w_emlrtRSI;
  internal::indexShapeCheck(b_st, 12, b_iv);
  return i_size;
}

void eml_find(const emlrtStack &sp, const real_T x_data[],
              const int32_T x_size[2], int32_T i_data[], int32_T i_size[2])
{
  emlrtStack st;
  int32_T idx;
  int32_T ii;
  int32_T nx;
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  nx = x_size[1];
  st.site = &v_emlrtRSI;
  idx = 0;
  i_size[0] = 1;
  i_size[1] = x_size[1];
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii] != 0.0) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x_size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (x_size[1] == 1) {
    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  } else if (idx < 1) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

int32_T eml_find(const emlrtStack &sp, const real_T x_data[],
                 const int32_T x_size[2], int32_T i_data[], int32_T j_data[],
                 int32_T &j_size)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i_size;
  int32_T nx;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nx = 12 * x_size[1];
  if (nx == 0) {
    i_size = 0;
    j_size = 0;
  } else {
    int32_T idx;
    int32_T ii;
    int32_T jj;
    boolean_T exitg1;
    st.site = &jc_emlrtRSI;
    idx = 0;
    i_size = nx;
    j_size = nx;
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= x_size[1])) {
      boolean_T guard1;
      guard1 = false;
      if (x_data[(ii + 12 * (jj - 1)) - 1] != 0.0) {
        idx++;
        i_data[idx - 1] = ii;
        j_data[idx - 1] = jj;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        ii++;
        if (ii > 12) {
          ii = 1;
          jj++;
        }
      }
    }
    if (idx > nx) {
      emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nx == 1) {
      if (idx == 0) {
        i_size = 0;
        j_size = 0;
      }
    } else {
      int32_T b_iv[2];
      if (idx < 1) {
        i_size = 0;
      } else {
        i_size = idx;
      }
      b_iv[0] = 1;
      b_iv[1] = i_size;
      b_st.site = &kc_emlrtRSI;
      internal::indexShapeCheck(b_st, nx, b_iv);
      b_iv[0] = 1;
      b_iv[1] = i_size;
      b_st.site = &lc_emlrtRSI;
      internal::indexShapeCheck(b_st, nx, b_iv);
      j_size = i_size;
      b_iv[0] = 1;
      b_iv[1] = i_size;
      b_st.site = &mc_emlrtRSI;
      internal::indexShapeCheck(b_st, nx, b_iv);
    }
  }
  return i_size;
}

} // namespace coder

// End of code generation (find.cpp)
