/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_px_training.c
 *
 * Code generation for function 'calc_px_training'
 *
 */

/* Include files */
#include "calc_px_training.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    10,                 /* lineNo */
    "calc_px_training", /* fcnName */
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_px_training.m" /* pathName
                                                                       */
};

static emlrtRSInfo b_emlrtRSI = {
    13,                 /* lineNo */
    "calc_px_training", /* fcnName */
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_px_training.m" /* pathName
                                                                       */
};

static emlrtRSInfo c_emlrtRSI = {
    19,                 /* lineNo */
    "calc_px_training", /* fcnName */
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_px_training.m" /* pathName
                                                                       */
};

static emlrtRSInfo d_emlrtRSI = {
    21,                 /* lineNo */
    "calc_px_training", /* fcnName */
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_px_training.m" /* pathName
                                                                       */
};

static emlrtRSInfo f_emlrtRSI =
    {
        69,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    71,                                                           /* lineNo */
    "power",                                                      /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    14,                                                           /* lineNo */
    9,                                                            /* colNo */
    "log",                                                        /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/log.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    82,                                                           /* lineNo */
    5,                                                            /* colNo */
    "fltpower",                                                   /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI =
    {
        133,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI =
    {
        138,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    2,                  /* nDims */
    16,                 /* lineNo */
    10,                 /* colNo */
    "calc_px_training", /* fName */
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_px_training.m" /* pName
                                                                       */
};

static emlrtECInfo b_emlrtECI = {
    1,                  /* nDims */
    16,                 /* lineNo */
    10,                 /* colNo */
    "calc_px_training", /* fName */
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_px_training.m" /* pName
                                                                       */
};

static emlrtECInfo c_emlrtECI = {
    2,                  /* nDims */
    16,                 /* lineNo */
    32,                 /* colNo */
    "calc_px_training", /* fName */
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_px_training.m" /* pName
                                                                       */
};

static emlrtECInfo d_emlrtECI = {
    1,                  /* nDims */
    16,                 /* lineNo */
    32,                 /* colNo */
    "calc_px_training", /* fName */
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_px_training.m" /* pName
                                                                       */
};

/* Function Declarations */
static void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                             const real_T in2_data[],
                             const int32_T in2_size[2]);

static void binary_expand_op_1(real_T in1_data[], int32_T in1_size[2],
                               const real_T in2_data[],
                               const int32_T in2_size[2],
                               const real_T in3_data[],
                               const int32_T in3_size[2]);

static void plus(real_T in1_data[], int32_T in1_size[2],
                 const real_T in2_data[], const int32_T in2_size[2]);

/* Function Definitions */
static void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                             const real_T in2_data[], const int32_T in2_size[2])
{
  real_T b_in1_data[1728];
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  if (in2_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in2_size[0];
  }
  if (in2_size[1] == 1) {
    b_loop_ub = in1_size[1];
  } else {
    b_loop_ub = in2_size[1];
  }
  stride_0_0 = (in1_size[0] != 1);
  stride_0_1 = (in1_size[1] != 1);
  stride_1_0 = (in2_size[0] != 1);
  stride_1_1 = (in2_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + loop_ub * i] =
          in1_data[i1 * stride_0_0 + in1_size[0] * aux_0_1] *
          (1.0 - in2_data[i1 * stride_1_0 + in2_size[0] * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = loop_ub;
  in1_size[1] = b_loop_ub;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = b_in1_data[i1 + loop_ub * i];
    }
  }
}

static void binary_expand_op_1(real_T in1_data[], int32_T in1_size[2],
                               const real_T in2_data[],
                               const int32_T in2_size[2],
                               const real_T in3_data[],
                               const int32_T in3_size[2])
{
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  if (in3_size[0] == 1) {
    loop_ub = in2_size[0];
  } else {
    loop_ub = in3_size[0];
  }
  in1_size[0] = loop_ub;
  if (in3_size[1] == 1) {
    b_loop_ub = in2_size[1];
  } else {
    b_loop_ub = in3_size[1];
  }
  in1_size[1] = b_loop_ub;
  stride_0_0 = (in2_size[0] != 1);
  stride_0_1 = (in2_size[1] != 1);
  stride_1_0 = (in3_size[0] != 1);
  stride_1_1 = (in3_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] =
          (1.0 - in2_data[i1 * stride_0_0 + in2_size[0] * aux_0_1]) *
          in3_data[i1 * stride_1_0 + in3_size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void plus(real_T in1_data[], int32_T in1_size[2],
                 const real_T in2_data[], const int32_T in2_size[2])
{
  real_T b_in1_data[1728];
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  if (in2_size[0] == 1) {
    loop_ub = in1_size[0];
  } else {
    loop_ub = in2_size[0];
  }
  if (in2_size[1] == 1) {
    b_loop_ub = in1_size[1];
  } else {
    b_loop_ub = in2_size[1];
  }
  stride_0_0 = (in1_size[0] != 1);
  stride_0_1 = (in1_size[1] != 1);
  stride_1_0 = (in2_size[0] != 1);
  stride_1_1 = (in2_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + loop_ub * i] =
          in1_data[i1 * stride_0_0 + in1_size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2_size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = loop_ub;
  in1_size[1] = b_loop_ub;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] = b_in1_data[i1 + loop_ub * i];
    }
  }
}

real_T calc_px_training(const emlrtStack *sp, const real_T X_data[],
                        const int32_T X_size[2], const real_T Y_data[],
                        const int32_T Y_size[2], const real_T Z_data[],
                        const int32_T Z_size[2], real_T lda, real_T eps,
                        real_T varargin_1)
{
  __m128d r;
  __m128d r1;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T ZY_data[1728];
  real_T pp_data[1728];
  real_T alpha1;
  real_T beta1;
  real_T p;
  int32_T ZY_size[2];
  int32_T pp_size[2];
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T vectorUB;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T b_p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &f_emlrtRSI;
  if (Y_size[0] != Z_size[1]) {
    if (((Z_size[0] == 1) && (Z_size[1] == 1)) ||
        ((Y_size[0] == 1) && (Y_size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &d_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  if ((Z_size[0] == 0) || (Z_size[1] == 0) || (Y_size[0] == 0) ||
      (Y_size[1] == 0)) {
    ZY_size[0] = Z_size[0];
    ZY_size[1] = Y_size[1];
    loop_ub = Z_size[0] * Y_size[1];
    if (loop_ub - 1 >= 0) {
      memset(&ZY_data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
    }
  } else {
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)Z_size[0];
    n_t = (ptrdiff_t)Y_size[1];
    k_t = (ptrdiff_t)Z_size[1];
    lda_t = (ptrdiff_t)Z_size[0];
    ldb_t = (ptrdiff_t)Y_size[0];
    ldc_t = (ptrdiff_t)Z_size[0];
    ZY_size[0] = Z_size[0];
    ZY_size[1] = Y_size[1];
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&Z_data[0],
          &lda_t, (real_T *)&Y_data[0], &ldb_t, &beta1, &ZY_data[0], &ldc_t);
  }
  st.site = &b_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  if (1.0 - lda < 0.0) {
    i = ZY_size[0] * ZY_size[1];
    b_p = false;
    for (k = 0; k < i; k++) {
      if (b_p) {
        b_p = true;
      } else {
        alpha1 = ZY_data[k];
        if ((!muDoubleScalarIsNaN(alpha1)) &&
            (muDoubleScalarFloor(alpha1) != ZY_data[k])) {
          b_p = true;
        }
      }
    }
  } else {
    b_p = false;
  }
  if (b_p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  loop_ub = ZY_size[0] * ZY_size[1];
  for (i = 0; i < loop_ub; i++) {
    alpha1 = ZY_data[i];
    ZY_data[i] = muDoubleScalarPower(1.0 - lda, alpha1) * (1.0 - eps);
  }
  if ((ZY_size[0] != X_size[0]) && ((ZY_size[0] != 1) && (X_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(ZY_size[0], X_size[0], &b_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((ZY_size[1] != X_size[1]) && ((ZY_size[1] != 1) && (X_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(ZY_size[1], X_size[1], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((ZY_size[0] != X_size[0]) && ((ZY_size[0] != 1) && (X_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(ZY_size[0], X_size[0], &d_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((ZY_size[1] != X_size[1]) && ((ZY_size[1] != 1) && (X_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(ZY_size[1], X_size[1], &c_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((ZY_size[0] == X_size[0]) && (ZY_size[1] == X_size[1])) {
    pp_size[0] = ZY_size[0];
    pp_size[1] = ZY_size[1];
    k = (loop_ub / 2) << 1;
    vectorUB = k - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&ZY_data[i]);
      r1 = _mm_loadu_pd(&X_data[i]);
      _mm_storeu_pd(&pp_data[i],
                    _mm_mul_pd(_mm_sub_pd(_mm_set1_pd(1.0), r), r1));
    }
    for (i = k; i < loop_ub; i++) {
      pp_data[i] = (1.0 - ZY_data[i]) * X_data[i];
    }
  } else {
    binary_expand_op_1(pp_data, pp_size, ZY_data, ZY_size, X_data, X_size);
  }
  if ((ZY_size[0] == X_size[0]) && (ZY_size[1] == X_size[1])) {
    k = (loop_ub / 2) << 1;
    vectorUB = k - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&X_data[i]);
      r1 = _mm_loadu_pd(&ZY_data[i]);
      _mm_storeu_pd(&ZY_data[i],
                    _mm_mul_pd(r1, _mm_sub_pd(_mm_set1_pd(1.0), r)));
    }
    for (i = k; i < loop_ub; i++) {
      ZY_data[i] *= 1.0 - X_data[i];
    }
  } else {
    binary_expand_op(ZY_data, ZY_size, X_data, X_size);
  }
  if ((pp_size[0] != ZY_size[0]) && ((pp_size[0] != 1) && (ZY_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(pp_size[0], ZY_size[0], &b_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((pp_size[1] != ZY_size[1]) && ((pp_size[1] != 1) && (ZY_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(pp_size[1], ZY_size[1], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((pp_size[0] == ZY_size[0]) && (pp_size[1] == ZY_size[1])) {
    loop_ub = pp_size[0] * pp_size[1];
    k = (loop_ub / 2) << 1;
    vectorUB = k - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&pp_data[i]);
      r1 = _mm_loadu_pd(&ZY_data[i]);
      _mm_storeu_pd(&pp_data[i], _mm_add_pd(r, r1));
    }
    for (i = k; i < loop_ub; i++) {
      pp_data[i] += ZY_data[i];
    }
  } else {
    plus(pp_data, pp_size, ZY_data, ZY_size);
  }
  if (varargin_1 == 0.0) {
    st.site = &c_emlrtRSI;
    loop_ub = pp_size[0] * pp_size[1];
    if (loop_ub == 0) {
      p = 1.0;
    } else {
      p = pp_data[0];
      for (k = 2; k <= loop_ub; k++) {
        p *= pp_data[k - 1];
      }
    }
  } else {
    real_T x_data[1728];
    st.site = &d_emlrtRSI;
    loop_ub = pp_size[0] * pp_size[1];
    b_p = false;
    for (k = 0; k < loop_ub; k++) {
      x_data[k] = pp_data[k];
      if (b_p || (pp_data[k] < 0.0)) {
        b_p = true;
      }
    }
    if (b_p) {
      emlrtErrorWithMessageIdR2018a(
          &st, &b_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
    }
    for (k = 0; k < loop_ub; k++) {
      x_data[k] = muDoubleScalarLog(x_data[k]);
    }
    st.site = &d_emlrtRSI;
    if (loop_ub == 0) {
      p = 0.0;
    } else {
      p = sumColumnB(x_data, loop_ub);
    }
  }
  return p;
}

/* End of code generation (calc_px_training.c) */
