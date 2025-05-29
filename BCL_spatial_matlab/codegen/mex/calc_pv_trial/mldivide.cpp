//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mldivide.cpp
//
// Code generation for function 'mldivide'
//

// Include files
#include "mldivide.h"
#include "calc_pv_trial_data.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo db_emlrtRSI{
    20,                                                              // lineNo
    "mldivide",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/mldivide.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    44,                                                              // lineNo
    "mldiv",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/mldivide.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    42,                                                              // lineNo
    "mldiv",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/mldivide.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    67,        // lineNo
    "lusolve", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/lusolve.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    109,          // lineNo
    "lusolveNxN", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/lusolve.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    112,          // lineNo
    "lusolveNxN", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/lusolve.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    124,          // lineNo
    "InvAtimesX", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/lusolve.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    19,        // lineNo
    "xgetrfs", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    108,      // lineNo
    "cmldiv", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" // pathName
};

static emlrtRSInfo rb_emlrtRSI{
    90,              // lineNo
    "warn_singular", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/lusolve.m" // pathName
};

static emlrtRSInfo sb_emlrtRSI{
    61,        // lineNo
    "qrsolve", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    72,        // lineNo
    "qrsolve", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m" // pathName
};

static emlrtRSInfo ub_emlrtRSI{
    85,        // lineNo
    "qrsolve", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m" // pathName
};

static emlrtRSInfo
    vb_emlrtRSI{
        63,       // lineNo
        "xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo
    wb_emlrtRSI{
        138,            // lineNo
        "ceval_xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo xb_emlrtRSI{
    173,          // lineNo
    "rankFromQR", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    172,          // lineNo
    "rankFromQR", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m" // pathName
};

static emlrtRSInfo ac_emlrtRSI{
    119,         // lineNo
    "LSQFromQR", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/qrsolve.m" // pathName
};

static emlrtRSInfo bc_emlrtRSI{
    31,         // lineNo
    "xunormqr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xunormqr.m" // pathName
};

static emlrtRSInfo cc_emlrtRSI{
    102,              // lineNo
    "ceval_xunormqr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xunormqr.m" // pathName
};

static emlrtMCInfo c_emlrtMCI{
    53,        // lineNo
    19,        // colNo
    "flt2str", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/flt2str.m" // pName
};

static emlrtRTEInfo i_emlrtRTEI{
    16,                                                              // lineNo
    19,                                                              // colNo
    "mldivide",                                                      // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/mldivide.m" // pName
};

static emlrtRSInfo wc_emlrtRSI{
    53,        // lineNo
    "flt2str", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/flt2str.m" // pathName
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[14]);

static const mxArray *b_sprintf(const emlrtStack &sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo &location);

static void emlrt_marshallIn(const emlrtStack &sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[14]);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[14]);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2]{1, 14};
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtConstCTX)&sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static const mxArray *b_sprintf(const emlrtStack &sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo &location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 2, &pArrays[0],
                               "sprintf", true, &location);
}

static void emlrt_marshallIn(const emlrtStack &sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[14])
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

namespace coder {
void mldivide(const emlrtStack &sp, const real_T A_data[],
              const int32_T A_size[2], const real_T B_data[],
              const int32_T B_size[2], real_T Y_data[], int32_T Y_size[2])
{
  static const int32_T offsets[4]{0, 1, 2, 3};
  static const int32_T b_iv[2]{1, 6};
  static const char_T b_fname[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                  '_', 'd', 'o', 'r', 'm', 'q', 'r'};
  static const char_T fname[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                '_', 'd', 'g', 'e', 'q', 'p', '3'};
  static const char_T rfmt[6]{'%', '1', '4', '.', '6', 'e'};
  ptrdiff_t IPIV_data[16];
  ptrdiff_t jpvt_t_data[16];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T b_A_data[256];
  real_T b_B_data[256];
  real_T tau_data[16];
  int32_T jpvt_data[16];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  if (B_size[0] != A_size[0]) {
    emlrtErrorWithMessageIdR2018a(&sp, &i_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  st.site = &db_emlrtRSI;
  if (A_size[1] == 0) {
    Y_size[0] = 0;
    Y_size[1] = B_size[1];
  } else if (A_size[0] == A_size[1]) {
    ptrdiff_t INFO;
    ptrdiff_t LDA;
    ptrdiff_t info_t;
    int32_T i;
    int32_T minmana;
    int32_T minmn;
    b_st.site = &fb_emlrtRSI;
    c_st.site = &gb_emlrtRSI;
    Y_size[0] = B_size[0];
    Y_size[1] = B_size[1];
    minmana = B_size[0] * B_size[1];
    if (minmana - 1 >= 0) {
      std::copy(&B_data[0], &B_data[minmana], &Y_data[0]);
    }
    d_st.site = &hb_emlrtRSI;
    e_st.site = &jb_emlrtRSI;
    i = muIntScalarMin_sint32(A_size[0], A_size[1]);
    minmn = muIntScalarMin_sint32(B_size[0], i);
    f_st.site = &kb_emlrtRSI;
    minmana = A_size[0] * A_size[1];
    if (minmana - 1 >= 0) {
      std::copy(&A_data[0], &A_data[minmana], &b_A_data[0]);
    }
    repmat((ptrdiff_t)0.0, minmn, jpvt_t_data);
    info_t = (ptrdiff_t)minmn;
    LDA = (ptrdiff_t)A_size[0];
    INFO = LAPACKE_dgetrf_work(102, info_t, info_t, &b_A_data[0], LDA,
                               &IPIV_data[0]);
    g_st.site = &lb_emlrtRSI;
    if ((int32_T)INFO < 0) {
      if ((int32_T)INFO == -1010) {
        emlrtErrorWithMessageIdR2018a(&g_st, &h_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&g_st, &g_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      19, &cv[0], 12, (int32_T)INFO);
      }
    }
    LAPACKE_dgetrs_work(102, 'N', info_t, (ptrdiff_t)B_size[1], &b_A_data[0],
                        LDA, &IPIV_data[0], &Y_data[0], (ptrdiff_t)B_size[0]);
    if (((A_size[0] != 1) || (A_size[1] != 1)) && ((int32_T)INFO > 0)) {
      d_st.site = &ib_emlrtRSI;
      e_st.site = &rb_emlrtRSI;
      internal::warning(e_st);
    }
  } else {
    ptrdiff_t info_t;
    real_T tol;
    int32_T A_size_idx_0;
    int32_T A_size_idx_1;
    int32_T B_size_idx_0;
    int32_T B_size_idx_1;
    int32_T i;
    int32_T minmana;
    int32_T minmn;
    int32_T na;
    int32_T rankA;
    int8_T unnamed_idx_0;
    boolean_T p;
    b_st.site = &eb_emlrtRSI;
    c_st.site = &sb_emlrtRSI;
    A_size_idx_0 = A_size[0];
    A_size_idx_1 = A_size[1];
    minmana = A_size[0] * A_size[1];
    if (minmana - 1 >= 0) {
      std::copy(&A_data[0], &A_data[minmana], &b_A_data[0]);
    }
    na = A_size[1] - 1;
    if (A_size_idx_1 - 1 >= 0) {
      std::memset(&jpvt_data[0], 0,
                  static_cast<uint32_T>(A_size_idx_1) * sizeof(int32_T));
    }
    d_st.site = &vb_emlrtRSI;
    minmana = muIntScalarMin_sint32(A_size[0], A_size[1]);
    for (i = 0; i < A_size_idx_1; i++) {
      jpvt_t_data[i] = (ptrdiff_t)0;
    }
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)A_size[0], (ptrdiff_t)A_size[1],
                            &b_A_data[0], (ptrdiff_t)A_size[0], &jpvt_t_data[0],
                            &tau_data[0]);
    e_st.site = &wb_emlrtRSI;
    if ((int32_T)info_t != 0) {
      p = true;
      if ((int32_T)info_t != -4) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&e_st, &h_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&e_st, &g_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)info_t);
        }
      }
    } else {
      p = false;
    }
    if (p) {
      for (int32_T j{0}; j <= na; j++) {
        for (int32_T b_i{0}; b_i < A_size_idx_0; b_i++) {
          b_A_data[j * A_size_idx_0 + b_i] = rtNaN;
        }
      }
      minmn = muIntScalarMin_sint32(A_size[0], A_size[1]) - 1;
      for (int32_T k{0}; k <= minmn; k++) {
        tau_data[k] = rtNaN;
      }
      i = minmn + 2;
      if (i <= minmana) {
        std::memset(&tau_data[i + -1], 0,
                    static_cast<uint32_T>((minmana - i) + 1) * sizeof(real_T));
      }
      minmana = (A_size[1] / 4) << 2;
      minmn = minmana - 4;
      for (int32_T k{0}; k <= minmn; k += 4) {
        __m128i r;
        r = _mm_add_epi32(
            _mm_add_epi32(_mm_set1_epi32(k),
                          _mm_loadu_si128((const __m128i *)&offsets[0])),
            _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&jpvt_data[k], r);
      }
      for (int32_T k{minmana}; k <= na; k++) {
        jpvt_data[k] = k + 1;
      }
    } else {
      for (int32_T k{0}; k <= na; k++) {
        jpvt_data[k] = (int32_T)jpvt_t_data[k];
      }
    }
    c_st.site = &tb_emlrtRSI;
    rankA = 0;
    tol = 0.0;
    if (A_size[0] < A_size[1]) {
      minmn = A_size[0];
      minmana = A_size[1];
    } else {
      minmn = A_size[1];
      minmana = A_size[0];
    }
    if (minmn > 0) {
      tol = 2.2204460492503131E-15 * static_cast<real_T>(minmana) *
            muDoubleScalarAbs(b_A_data[0]);
      while ((rankA < minmn) &&
             (!(muDoubleScalarAbs(b_A_data[rankA + A_size_idx_0 * rankA]) <=
                tol))) {
        rankA++;
      }
    }
    if (rankA < minmn) {
      char_T str[14];
      d_st.site = &xb_emlrtRSI;
      y = nullptr;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(&d_st, 6, m, &rfmt[0]);
      emlrtAssign(&y, m);
      b_y = nullptr;
      m = emlrtCreateDoubleScalar(tol);
      emlrtAssign(&b_y, m);
      e_st.site = &wc_emlrtRSI;
      emlrt_marshallIn(e_st, b_sprintf(e_st, y, b_y, c_emlrtMCI),
                       "<output of sprintf>", str);
      d_st.site = &yb_emlrtRSI;
      internal::warning(d_st, rankA, str);
    }
    c_st.site = &ub_emlrtRSI;
    B_size_idx_0 = B_size[0];
    B_size_idx_1 = B_size[1];
    minmana = B_size[0] * B_size[1];
    if (minmana - 1 >= 0) {
      std::copy(&B_data[0], &B_data[minmana], &b_B_data[0]);
    }
    unnamed_idx_0 = static_cast<int8_T>(A_size[1]);
    Y_size[0] = static_cast<int8_T>(A_size[1]);
    Y_size[1] = static_cast<int8_T>(B_size[1]);
    minmana = static_cast<int8_T>(A_size[1]) * static_cast<int8_T>(B_size[1]);
    if (minmana - 1 >= 0) {
      std::memset(&Y_data[0], 0,
                  static_cast<uint32_T>(minmana) * sizeof(real_T));
    }
    d_st.site = &ac_emlrtRSI;
    e_st.site = &bc_emlrtRSI;
    na = muIntScalarMin_sint32(A_size[0], A_size[1]);
    info_t = (ptrdiff_t)B_size[0];
    info_t = LAPACKE_dormqr(102, 'L', 'T', info_t, (ptrdiff_t)B_size[1],
                            (ptrdiff_t)na, &b_A_data[0], (ptrdiff_t)A_size[0],
                            &tau_data[0], &b_B_data[0], info_t);
    f_st.site = &cc_emlrtRSI;
    if ((int32_T)info_t != 0) {
      boolean_T b_p;
      p = true;
      b_p = false;
      if ((int32_T)info_t == -7) {
        b_p = true;
      } else if ((int32_T)info_t == -9) {
        b_p = true;
      } else if ((int32_T)info_t == -10) {
        b_p = true;
      }
      if (!b_p) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &h_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &f_st, &g_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &b_fname[0], 12,
              (int32_T)info_t);
        }
      }
    } else {
      p = false;
    }
    if (p) {
      if (((int32_T)info_t == -10) && (B_size[1] > 1)) {
        for (int32_T j{0}; j < na; j++) {
          if (tau_data[j] != 0.0) {
            i = j + 2;
            for (int32_T k{0}; k < B_size_idx_1; k++) {
              int32_T wj_tmp;
              wj_tmp = B_size_idx_0 * k;
              minmn = j + wj_tmp;
              tol = b_B_data[minmn];
              for (int32_T b_i{i}; b_i <= A_size_idx_0; b_i++) {
                tol += b_A_data[(b_i + A_size_idx_0 * j) - 1] *
                       b_B_data[(b_i + wj_tmp) - 1];
              }
              tol *= tau_data[j];
              if (tol != 0.0) {
                b_B_data[minmn] -= tol;
                minmana = (((((A_size_idx_0 - j) - 1) / 2) << 1) + j) + 2;
                minmn = minmana - 2;
                for (int32_T b_i{i}; b_i <= minmn; b_i += 2) {
                  __m128d r1;
                  __m128d r2;
                  r1 = _mm_loadu_pd(&b_A_data[(b_i + A_size_idx_0 * j) - 1]);
                  r2 = _mm_loadu_pd(&b_B_data[(b_i + B_size_idx_0 * k) - 1]);
                  _mm_storeu_pd(
                      &b_B_data[(b_i + B_size_idx_0 * k) - 1],
                      _mm_sub_pd(r2, _mm_mul_pd(r1, _mm_set1_pd(tol))));
                }
                for (int32_T b_i{minmana}; b_i <= A_size_idx_0; b_i++) {
                  minmn = (b_i + wj_tmp) - 1;
                  b_B_data[minmn] -=
                      b_A_data[(b_i + A_size_idx_0 * j) - 1] * tol;
                }
              }
            }
          }
        }
      } else {
        B_size_idx_0 = B_size[0];
        minmana = B_size[0] * B_size[1];
        for (i = 0; i < minmana; i++) {
          b_B_data[i] = rtNaN;
        }
      }
    }
    for (int32_T k{0}; k < B_size_idx_1; k++) {
      for (int32_T b_i{0}; b_i < rankA; b_i++) {
        Y_data[(jpvt_data[b_i] + unnamed_idx_0 * k) - 1] =
            b_B_data[b_i + B_size_idx_0 * k];
      }
      for (int32_T j{rankA}; j >= 1; j--) {
        i = jpvt_data[j - 1];
        minmn = (i + static_cast<int8_T>(A_size_idx_1) * k) - 1;
        minmana = A_size_idx_0 * (j - 1);
        Y_data[minmn] /= b_A_data[(j + minmana) - 1];
        for (int32_T b_i{0}; b_i <= j - 2; b_i++) {
          minmn = static_cast<int8_T>(A_size_idx_1) * k;
          Y_data[(jpvt_data[b_i] + static_cast<int8_T>(A_size_idx_1) * k) - 1] =
              Y_data[(jpvt_data[b_i] + minmn) - 1] -
              Y_data[(jpvt_data[j - 1] + minmn) - 1] * b_A_data[b_i + minmana];
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (mldivide.cpp)
