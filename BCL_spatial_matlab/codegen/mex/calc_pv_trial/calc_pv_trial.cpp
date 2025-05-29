//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calc_pv_trial.cpp
//
// Code generation for function 'calc_pv_trial'
//

// Include files
#include "calc_pv_trial.h"
#include "any1.h"
#include "calc_pv_trial_data.h"
#include "det.h"
#include "diag.h"
#include "eml_mtimes_helper.h"
#include "eye.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "mldivide.h"
#include "mpower.h"
#include "mtimes.h"
#include "prod.h"
#include "rt_nonfinite.h"
#include "sub2ind.h"
#include "sum.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    5,                                                             // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    7,                                                             // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    11,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    13,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    16,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    27,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    28,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    29,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    32,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    33,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    34,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    39,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    48,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    51,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    54,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo p_emlrtRSI{
    55,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    67,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    68,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    75,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    76,                                                            // lineNo
    "calc_pv_trial",                                               // fcnName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    39,                                                            // lineNo
    "find",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo
    dc_emlrtRSI{
        94,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pathName
    };

static emlrtRSInfo
    ec_emlrtRSI{
        69,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pathName
    };

static emlrtRSInfo ic_emlrtRSI{
    35,                                                            // lineNo
    "find",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    39,                                                               // lineNo
    "cat",                                                            // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

static emlrtRSInfo oc_emlrtRSI{
    113,                                                              // lineNo
    "cat_impl",                                                       // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

static emlrtRSInfo pc_emlrtRSI{
    16,                                                               // lineNo
    "sub2ind",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/sub2ind.m" // pathName
};

static emlrtECInfo emlrtECI{
    2,                                                             // nDims
    3,                                                             // lineNo
    12,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    23,                                                             // lineNo
    28,                                                             // colNo
    "SigmaInv",                                                     // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtECInfo b_emlrtECI{
    -1,                                                            // nDims
    23,                                                            // lineNo
    13,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo c_emlrtECI{
    1,                                                             // nDims
    27,                                                            // lineNo
    21,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo d_emlrtECI{
    2,                                                             // nDims
    27,                                                            // lineNo
    21,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo e_emlrtECI{
    1,                                                             // nDims
    29,                                                            // lineNo
    17,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo f_emlrtECI{
    2,                                                             // nDims
    29,                                                            // lineNo
    17,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo g_emlrtECI{
    -1,                                                            // nDims
    30,                                                            // lineNo
    9,                                                             // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo h_emlrtECI{
    1,                                                             // nDims
    54,                                                            // lineNo
    27,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo i_emlrtECI{
    1,                                                             // nDims
    55,                                                            // lineNo
    27,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo j_emlrtECI{
    -1,                                                            // nDims
    51,                                                            // lineNo
    13,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo k_emlrtECI{
    -1,                                                            // nDims
    54,                                                            // lineNo
    13,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtECInfo l_emlrtECI{
    -1,                                                            // nDims
    55,                                                            // lineNo
    13,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtRTEInfo emlrtRTEI{
    288,                                                              // lineNo
    27,                                                               // colNo
    "check_non_axis_size",                                            // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pName
};

static emlrtRTEInfo
    b_emlrtRTEI{
        13,               // lineNo
        13,               // colNo
        "toLogicalCheck", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
        "toLogicalCheck.m" // pName
    };

static emlrtRTEInfo c_emlrtRTEI{
    13,                                                            // lineNo
    9,                                                             // colNo
    "sqrt",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m" // pName
};

static emlrtBCInfo b_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    22,                                                             // lineNo
    27,                                                             // colNo
    "xAct",                                                         // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    22,                                                             // lineNo
    32,                                                             // colNo
    "A",                                                            // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    29,                                                             // lineNo
    78,                                                             // colNo
    "A",                                                            // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    29,                                                             // lineNo
    51,                                                             // colNo
    "A",                                                            // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    39,                                                             // lineNo
    28,                                                             // colNo
    "phi",                                                          // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    1,                                                              // iFirst
    12,                                                             // iLast
    40,                                                             // lineNo
    34,                                                             // colNo
    "omegaBU",                                                      // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    51,                                                             // lineNo
    62,                                                             // colNo
    "omegaProductMatrix",                                           // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    51,                                                             // lineNo
    96,                                                             // colNo
    "phiProductMatrix",                                             // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    51,                                                             // lineNo
    13,                                                             // colNo
    "SigmaCtllhInv",                                                // aName
    "calc_pv_trial",                                                // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo s_emlrtRTEI{
    63,                                                            // lineNo
    9,                                                             // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    58,                                                            // lineNo
    13,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    47,                                                            // lineNo
    13,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    50,                                                            // lineNo
    13,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    1,                                                             // lineNo
    42,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    51,                                                            // lineNo
    43,                                                            // colNo
    "calc_pv_trial",                                               // fName
    "/home/ari/Desktop/chunkLearner_IBP_optimized/calc_pv_trial.m" // pName
};

// Function Declarations
static void b_times(real_T in1_data[], int32_T &in1_size,
                    const real_T in2_data[], const int32_T &in2_size);

static void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                             const real_T in2_data[], const int32_T in2_size[2],
                             const real_T in3_data[],
                             const int32_T in3_size[2]);

static void binary_expand_op_1(const emlrtStack &sp, real_T in1_data[],
                               int32_T in1_size[2], const emlrtRSInfo in2,
                               const real_T in3_data[],
                               const int32_T in3_size[2],
                               const real_T in4_data[],
                               const int32_T in4_size[2]);

static void binary_expand_op_2(real_T in1_data[], int32_T in1_size[2],
                               const real_T in2_data[],
                               const int32_T in2_size[2],
                               const real_T in3_data[],
                               const int32_T &in3_size);

static void times(real_T in1_data[], int32_T &in1_size, const real_T in2_data[],
                  const int32_T &in2_size);

// Function Definitions
static void b_times(real_T in1_data[], int32_T &in1_size,
                    const real_T in2_data[], const int32_T &in2_size)
{
  real_T b_in2_data[192];
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in1_size == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in1_size;
  }
  stride_0_0 = (in2_size != 1);
  stride_1_0 = (in1_size != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] * in1_data[i * stride_1_0];
  }
  in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    std::copy(&b_in2_data[0], &b_in2_data[loop_ub], &in1_data[0]);
  }
}

static void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                             const real_T in2_data[], const int32_T in2_size[2],
                             const real_T in3_data[], const int32_T in3_size[2])
{
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
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
  for (int32_T i{0}; i < b_loop_ub; i++) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      in1_data[i1 + in1_size[0] * i] =
          in2_data[i1 * stride_0_0 + in2_size[0] * aux_0_1] -
          in3_data[i1 * stride_1_0 + in3_size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_1(const emlrtStack &sp, real_T in1_data[],
                               int32_T in1_size[2], const emlrtRSInfo in2,
                               const real_T in3_data[],
                               const int32_T in3_size[2],
                               const real_T in4_data[],
                               const int32_T in4_size[2])
{
  emlrtStack st;
  real_T b_in3_data[256];
  int32_T b_in3_size[2];
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  st.prev = &sp;
  st.tls = sp.tls;
  if (in1_size[0] == 1) {
    loop_ub = in3_size[0];
  } else {
    loop_ub = in1_size[0];
  }
  b_in3_size[0] = loop_ub;
  if (in1_size[1] == 1) {
    b_loop_ub = in3_size[1];
  } else {
    b_loop_ub = in1_size[1];
  }
  b_in3_size[1] = b_loop_ub;
  stride_0_0 = (in3_size[0] != 1);
  stride_0_1 = (in3_size[1] != 1);
  stride_1_0 = (in1_size[0] != 1);
  stride_1_1 = (in1_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < b_loop_ub; i++) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      b_in3_data[i1 + loop_ub * i] =
          in3_data[i1 * stride_0_0 + in3_size[0] * aux_0_1] +
          in1_data[i1 * stride_1_0 + in1_size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = const_cast<emlrtRSInfo *>(&in2);
  coder::mldivide(st, b_in3_data, b_in3_size, in4_data, in4_size, in1_data,
                  in1_size);
}

static void binary_expand_op_2(real_T in1_data[], int32_T in1_size[2],
                               const real_T in2_data[],
                               const int32_T in2_size[2],
                               const real_T in3_data[], const int32_T &in3_size)
{
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1_size[0] = 12;
  if (in3_size == 1) {
    loop_ub = in2_size[1];
  } else {
    loop_ub = in3_size;
  }
  in1_size[1] = loop_ub;
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < loop_ub; i++) {
    for (int32_T i1{0}; i1 <= 10; i1 += 2) {
      __m128d r;
      r = _mm_loadu_pd(&in2_data[i1 + 12 * aux_0_1]);
      _mm_storeu_pd(&in1_data[i1 + 12 * i],
                    _mm_mul_pd(r, _mm_set1_pd(in3_data[aux_1_1])));
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void times(real_T in1_data[], int32_T &in1_size, const real_T in2_data[],
                  const int32_T &in2_size)
{
  real_T b_in1_data[192];
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in2_size == 1) {
    loop_ub = in1_size;
  } else {
    loop_ub = in2_size;
  }
  stride_0_0 = (in1_size != 1);
  stride_1_0 = (in2_size != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_0] * in2_data[i * stride_1_0];
  }
  in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    std::copy(&b_in1_data[0], &b_in1_data[loop_ub], &in1_data[0]);
  }
}

void calc_pv_trial(const emlrtStack *sp, const real_T x[12], const real_T v[24],
                   const real_T y_data[], const int32_T y_size[1],
                   const real_T Z_data[], const int32_T Z_size[2],
                   real_T sigmaU, real_T sigmaV, real_T phi,
                   coder::array<real_T, 2U> &SigmaCtllhInv, real_T wt_data[],
                   int32_T wt_size[3], real_T Psit[2], boolean_T zc_data[],
                   int32_T zc_size[2])
{
  __m128d r;
  __m128d r1;
  coder::array<real_T, 2U> omegaProductMatrix;
  coder::array<real_T, 2U> phiProductMatrix;
  coder::array<real_T, 1U> r4;
  coder::array<uint16_T, 1U> r3;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T SigmaInv_data[3072];
  real_T SigmaCVInv_data[256];
  real_T SigmaC_data[256];
  real_T b_SigmaCVInv_data[256];
  real_T b_y_data[256];
  real_T tmp_data[256];
  real_T A_data[192];
  real_T ZAct_data[192];
  real_T b_ZAct_data[192];
  real_T b_availLinks_data[192];
  real_T phiTerms_data[192];
  real_T phi_data[192];
  real_T omegaBU[144];
  real_T omega_data[144];
  real_T vnan[24];
  real_T A_xi_data[16];
  real_T ptAct_data[16];
  real_T b_phiSum[12];
  real_T phiSum[12];
  real_T sSq[12];
  real_T sSq_data[12];
  real_T b_sSq;
  real_T d;
  real_T detSigmaC;
  real_T invSqrtProdSSq;
  int32_T availLinks_data[384];
  int32_T c_ii_data[192];
  int32_T jj_data[192];
  int32_T b_ii_data[16];
  int32_T b_tmp_data[12];
  int32_T ii_data[12];
  int32_T xAct_data[12];
  int32_T SigmaInv_size[3];
  int32_T SigmaCVInv_size[2];
  int32_T SigmaC_size[2];
  int32_T SigmaInv[2];
  int32_T ZAct_size[2];
  int32_T a_size[2];
  int32_T activeMatrix_size[2];
  int32_T availLinks_size[2];
  int32_T b_ii_size[2];
  int32_T b_y_size[2];
  int32_T omegaTerms_size[2];
  int32_T omega_size[2];
  int32_T phi_size[2];
  int32_T ptAct_size[2];
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T ii_size;
  int32_T k;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T vlen;
  int32_T xoffset;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if ((y_size[0] != Z_size[1]) && ((Z_size[1] != 1) && (y_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(Z_size[1], y_size[0], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (y_size[0] == Z_size[1]) {
    ZAct_size[1] = Z_size[1];
    loop_ub = Z_size[1];
    for (i = 0; i < loop_ub; i++) {
      for (loop_ub_tmp = 0; loop_ub_tmp <= 10; loop_ub_tmp += 2) {
        r = _mm_loadu_pd(&Z_data[loop_ub_tmp + 12 * i]);
        _mm_storeu_pd(&ZAct_data[loop_ub_tmp + 12 * i],
                      _mm_mul_pd(r, _mm_set1_pd(y_data[i])));
      }
    }
  } else {
    binary_expand_op_2(ZAct_data, ZAct_size, Z_data, Z_size, y_data, y_size[0]);
  }
  phi_size[0] = 12;
  phi_size[1] = ZAct_size[1];
  loop_ub = 12 * ZAct_size[1];
  xoffset = (loop_ub / 2) << 1;
  b_i = xoffset - 2;
  for (i = 0; i <= b_i; i += 2) {
    r = _mm_loadu_pd(&ZAct_data[i]);
    _mm_storeu_pd(&phi_data[i], _mm_mul_pd(_mm_set1_pd(phi), r));
  }
  for (i = xoffset; i < loop_ub; i++) {
    phi_data[i] = phi * ZAct_data[i];
  }
  loop_ub = ZAct_size[1];
  for (i = 0; i < loop_ub; i++) {
    for (loop_ub_tmp = 0; loop_ub_tmp <= 10; loop_ub_tmp += 2) {
      r = _mm_loadu_pd(&phi_data[loop_ub_tmp + 12 * i]);
      r1 = _mm_loadu_pd(&x[loop_ub_tmp]);
      _mm_storeu_pd(&A_data[loop_ub_tmp + 12 * i], _mm_mul_pd(r, r1));
    }
  }
  st.site = &emlrtRSI;
  loop_ub = 12 * ZAct_size[1];
  for (k = 0; k < loop_ub; k++) {
    if (muDoubleScalarIsNaN(A_data[k])) {
      emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI, "MATLAB:nologicalnan",
                                    "MATLAB:nologicalnan", 0);
    }
  }
  zc_size[0] = 12;
  zc_size[1] = ZAct_size[1];
  for (i = 0; i < loop_ub; i++) {
    zc_data[i] = (A_data[i] != 0.0);
  }
  st.site = &b_emlrtRSI;
  b_st.site = &u_emlrtRSI;
  ii_size = coder::eml_find(b_st, x, ii_data);
  if (ii_size - 1 >= 0) {
    std::copy(&ii_data[0], &ii_data[ii_size], &xAct_data[0]);
  }
  vlen = ZAct_size[1];
  if (ZAct_size[1] == 0) {
    std::memset(&phiSum[0], 0, 12U * sizeof(real_T));
  } else {
    std::copy(&phi_data[0], &phi_data[12], &phiSum[0]);
    for (k = 2; k <= vlen; k++) {
      xoffset = (k - 1) * 12;
      for (b_i = 0; b_i <= 10; b_i += 2) {
        r = _mm_loadu_pd(&phiSum[b_i]);
        r1 = _mm_loadu_pd(&phi_data[xoffset + b_i]);
        _mm_storeu_pd(&phiSum[b_i], _mm_add_pd(r, r1));
      }
    }
  }
  for (b_i = 0; b_i <= 10; b_i += 2) {
    r = _mm_loadu_pd(&phiSum[b_i]);
    _mm_storeu_pd(&sSq[b_i], _mm_add_pd(r, _mm_set1_pd(1.0)));
  }
  k = ZAct_size[1];
  loop_ub = ZAct_size[1];
  for (i = 0; i < loop_ub; i++) {
    for (loop_ub_tmp = 0; loop_ub_tmp <= 10; loop_ub_tmp += 2) {
      r = _mm_loadu_pd(&phi_data[loop_ub_tmp + 12 * i]);
      r1 = _mm_loadu_pd(&sSq[loop_ub_tmp]);
      _mm_storeu_pd(&A_data[loop_ub_tmp + 12 * i], _mm_div_pd(r, r1));
    }
  }
  st.site = &c_emlrtRSI;
  b_st.site = &y_emlrtRSI;
  invSqrtProdSSq = sigmaV * sigmaV;
  for (i = 0; i <= 10; i += 2) {
    r = _mm_loadu_pd(&sSq[i]);
    _mm_storeu_pd(&sSq[i], _mm_div_pd(_mm_set1_pd(invSqrtProdSSq), r));
  }
  st.site = &d_emlrtRSI;
  vlen = ZAct_size[1];
  loop_ub = ZAct_size[1];
  for (i = 0; i < loop_ub; i++) {
    for (loop_ub_tmp = 0; loop_ub_tmp <= 10; loop_ub_tmp += 2) {
      r = _mm_loadu_pd(&ZAct_data[loop_ub_tmp + 12 * i]);
      r1 = _mm_loadu_pd(&x[loop_ub_tmp]);
      _mm_storeu_pd(&b_ZAct_data[loop_ub_tmp + 12 * i], _mm_mul_pd(r, r1));
    }
  }
  ZAct_size[0] = 12;
  for (i = 0; i < vlen; i++) {
    std::copy(
        &b_ZAct_data[i * 12],
        &b_ZAct_data[static_cast<int32_T>(static_cast<uint32_T>(i * 12) + 12U)],
        &ZAct_data[i * 12]);
  }
  coder::sum(ZAct_data, ZAct_size, ptAct_data, ptAct_size);
  b_st.site = &u_emlrtRSI;
  coder::eml_find(b_st, ptAct_data, ptAct_size, b_ii_data, b_ii_size);
  ptAct_size[1] = b_ii_size[1];
  loop_ub = b_ii_size[1];
  for (i = 0; i < loop_ub; i++) {
    ptAct_data[i] = b_ii_data[i];
  }
  std::memset(&omegaBU[0], 0, 144U * sizeof(real_T));
  st.site = &e_emlrtRSI;
  b_st.site = &y_emlrtRSI;
  detSigmaC = 1.0 / muDoubleScalarPower(sigmaV, 4.0);
  for (i = 0; i < ii_size; i++) {
    sSq_data[i] = sSq[xAct_data[i] - 1];
  }
  coder::diag(sSq_data, ii_size, omega_data, omega_size);
  b_y_size[0] = omega_size[0];
  b_y_size[1] = omega_size[1];
  loop_ub_tmp = omega_size[0] * omega_size[1];
  xoffset = (loop_ub_tmp / 2) << 1;
  b_i = xoffset - 2;
  for (i = 0; i <= b_i; i += 2) {
    r = _mm_loadu_pd(&omega_data[i]);
    _mm_storeu_pd(&b_y_data[i], _mm_mul_pd(_mm_set1_pd(detSigmaC), r));
  }
  for (i = xoffset; i < loop_ub_tmp; i++) {
    b_y_data[i] = detSigmaC * omega_data[i];
  }
  if (b_ii_size[1] > 0) {
    real_T a_data[192];
    real_T c_y_data[192];
    SigmaInv_size[0] = b_ii_size[1];
    SigmaInv_size[1] = b_ii_size[1];
    SigmaInv_size[2] = ii_size;
    loop_ub = b_ii_size[1] * b_ii_size[1] * ii_size;
    if (loop_ub - 1 >= 0) {
      std::memset(&SigmaInv_data[0], 0,
                  static_cast<uint32_T>(loop_ub) * sizeof(real_T));
    }
    if (ii_size - 1 >= 0) {
      b_loop_ub = ptAct_size[1];
      tmp_size[0] = ptAct_size[1];
      tmp_size[1] = ptAct_size[1];
      scalarLB = (b_loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      i1 = SigmaInv_size[0];
      c_loop_ub = SigmaInv_size[1];
      d_loop_ub = SigmaInv_size[0];
    }
    for (xoffset = 0; xoffset < ii_size; xoffset++) {
      if (xoffset + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(xoffset + 1, 1, ii_size, &b_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      vlen = xAct_data[xoffset];
      for (i = 0; i < b_loop_ub; i++) {
        loop_ub_tmp = static_cast<int32_T>(ptAct_data[i]);
        if ((loop_ub_tmp < 1) || (loop_ub_tmp > k)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub_tmp, 1, k, &c_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        A_xi_data[i] = A_data[(vlen + 12 * (loop_ub_tmp - 1)) - 1];
      }
      if (xoffset + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(xoffset + 1, 1, ii_size, &emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_sSq = sSq[vlen - 1];
      for (i = 0; i < b_loop_ub; i++) {
        for (loop_ub_tmp = 0; loop_ub_tmp <= vectorUB; loop_ub_tmp += 2) {
          r = _mm_loadu_pd(&A_xi_data[loop_ub_tmp]);
          r = _mm_mul_pd(r, _mm_set1_pd(A_xi_data[i]));
          _mm_storeu_pd(
              &tmp_data[loop_ub_tmp + b_loop_ub * i],
              _mm_div_pd(_mm_add_pd(_mm_set1_pd(0.0), r), _mm_set1_pd(b_sSq)));
        }
        for (loop_ub_tmp = scalarLB; loop_ub_tmp < b_loop_ub; loop_ub_tmp++) {
          d = A_xi_data[loop_ub_tmp] * A_xi_data[i];
          tmp_data[loop_ub_tmp + b_loop_ub * i] = d / b_sSq;
        }
      }
      SigmaInv[0] = SigmaInv_size[0];
      SigmaInv[1] = SigmaInv_size[1];
      emlrtSubAssignSizeCheckR2012b(&SigmaInv[0], 2, &tmp_size[0], 2,
                                    &b_emlrtECI, (emlrtCTX)sp);
      for (i = 0; i < c_loop_ub; i++) {
        for (loop_ub_tmp = 0; loop_ub_tmp < d_loop_ub; loop_ub_tmp++) {
          SigmaInv_data[(loop_ub_tmp + SigmaInv_size[0] * i) +
                        SigmaInv_size[0] * SigmaInv_size[1] * xoffset] =
              tmp_data[loop_ub_tmp + i1 * i];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    coder::b_sum(SigmaInv_data, SigmaInv_size, SigmaCVInv_data, SigmaInv);
    st.site = &f_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    invSqrtProdSSq = 1.0 / (sigmaU * sigmaU);
    st.site = &f_emlrtRSI;
    coder::eye(st, static_cast<real_T>(b_ii_size[1]), SigmaC_data, SigmaC_size);
    loop_ub = SigmaC_size[0] * SigmaC_size[1];
    xoffset = (loop_ub / 2) << 1;
    b_i = xoffset - 2;
    for (i = 0; i <= b_i; i += 2) {
      r = _mm_loadu_pd(&SigmaC_data[i]);
      _mm_storeu_pd(&SigmaC_data[i],
                    _mm_mul_pd(_mm_set1_pd(invSqrtProdSSq), r));
    }
    for (i = xoffset; i < loop_ub; i++) {
      SigmaC_data[i] *= invSqrtProdSSq;
    }
    if ((SigmaInv[0] != SigmaC_size[0]) &&
        ((SigmaInv[0] != 1) && (SigmaC_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(SigmaInv[0], SigmaC_size[0], &c_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((SigmaInv[1] != SigmaC_size[1]) &&
        ((SigmaInv[1] != 1) && (SigmaC_size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(SigmaInv[1], SigmaC_size[1], &d_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    st.site = &g_emlrtRSI;
    coder::eye(st, static_cast<real_T>(b_ii_size[1]), tmp_data, tmp_size);
    if ((SigmaInv[0] == SigmaC_size[0]) && (SigmaInv[1] == SigmaC_size[1])) {
      SigmaCVInv_size[0] = SigmaInv[0];
      SigmaCVInv_size[1] = SigmaInv[1];
      loop_ub = SigmaInv[0] * SigmaInv[1];
      xoffset = (loop_ub / 2) << 1;
      b_i = xoffset - 2;
      for (i = 0; i <= b_i; i += 2) {
        r = _mm_loadu_pd(&SigmaCVInv_data[i]);
        r1 = _mm_loadu_pd(&SigmaC_data[i]);
        _mm_storeu_pd(&b_SigmaCVInv_data[i], _mm_add_pd(r, r1));
      }
      for (i = xoffset; i < loop_ub; i++) {
        b_SigmaCVInv_data[i] = SigmaCVInv_data[i] + SigmaC_data[i];
      }
      st.site = &g_emlrtRSI;
      coder::mldivide(st, b_SigmaCVInv_data, SigmaCVInv_size, tmp_data,
                      tmp_size, SigmaC_data, SigmaC_size);
    } else {
      st.site = &g_emlrtRSI;
      binary_expand_op_1(st, SigmaC_data, SigmaC_size, g_emlrtRSI,
                         SigmaCVInv_data, SigmaInv, tmp_data, tmp_size);
    }
    vlen = b_ii_size[1];
    loop_ub = b_ii_size[1];
    for (i = 0; i < loop_ub; i++) {
      b_ii_data[i] = static_cast<int32_T>(ptAct_data[i]);
    }
    a_size[0] = ii_size;
    a_size[1] = b_ii_size[1];
    for (i = 0; i < vlen; i++) {
      for (loop_ub_tmp = 0; loop_ub_tmp < ii_size; loop_ub_tmp++) {
        i1 = b_ii_data[i];
        if ((i1 < 1) || (i1 > k)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, k, &d_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        a_data[loop_ub_tmp + ii_size * i] =
            A_data[(xAct_data[loop_ub_tmp] + 12 * (i1 - 1)) - 1];
      }
    }
    st.site = &h_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    st.site = &h_emlrtRSI;
    b_st.site = &ec_emlrtRSI;
    coder::dynamic_size_checks(b_st, SigmaC_size, a_size, SigmaC_size[1],
                               b_ii_size[1]);
    b_st.site = &dc_emlrtRSI;
    coder::internal::blas::mtimes(SigmaC_data, SigmaC_size, a_data, a_size,
                                  c_y_data, ZAct_size);
    st.site = &h_emlrtRSI;
    a_size[0] = ii_size;
    a_size[1] = b_ii_size[1];
    for (i = 0; i < vlen; i++) {
      for (loop_ub_tmp = 0; loop_ub_tmp < ii_size; loop_ub_tmp++) {
        i1 = b_ii_data[i];
        if ((i1 < 1) || (i1 > k)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, k, &e_emlrtBCI, &st);
        }
        a_data[loop_ub_tmp + ii_size * i] =
            A_data[(xAct_data[loop_ub_tmp] + 12 * (i1 - 1)) - 1];
      }
    }
    b_st.site = &ec_emlrtRSI;
    coder::dynamic_size_checks(b_st, a_size, ZAct_size, b_ii_size[1],
                               ZAct_size[0]);
    b_st.site = &dc_emlrtRSI;
    coder::internal::blas::b_mtimes(a_data, a_size, c_y_data, ZAct_size,
                                    omega_data, omega_size);
    SigmaInv[0] = omega_size[0];
    SigmaInv[1] = omega_size[1];
    loop_ub = omega_size[0] * omega_size[1];
    xoffset = (loop_ub / 2) << 1;
    b_i = xoffset - 2;
    for (i = 0; i <= b_i; i += 2) {
      r = _mm_loadu_pd(&omega_data[i]);
      _mm_storeu_pd(&SigmaCVInv_data[i], _mm_mul_pd(_mm_set1_pd(detSigmaC), r));
    }
    for (i = xoffset; i < loop_ub; i++) {
      SigmaCVInv_data[i] = detSigmaC * omega_data[i];
    }
    if ((b_y_size[0] != omega_size[0]) &&
        ((b_y_size[0] != 1) && (omega_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(b_y_size[0], omega_size[0], &e_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((b_y_size[1] != omega_size[1]) &&
        ((b_y_size[1] != 1) && (omega_size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(b_y_size[1], omega_size[1], &f_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((b_y_size[0] == omega_size[0]) && (b_y_size[1] == omega_size[1])) {
      omega_size[0] = b_y_size[0];
      omega_size[1] = b_y_size[1];
      loop_ub = b_y_size[0] * b_y_size[1];
      xoffset = (loop_ub / 2) << 1;
      b_i = xoffset - 2;
      for (i = 0; i <= b_i; i += 2) {
        r = _mm_loadu_pd(&b_y_data[i]);
        r1 = _mm_loadu_pd(&SigmaCVInv_data[i]);
        _mm_storeu_pd(&omega_data[i], _mm_sub_pd(r, r1));
      }
      for (i = xoffset; i < loop_ub; i++) {
        omega_data[i] = b_y_data[i] - SigmaCVInv_data[i];
      }
    } else {
      binary_expand_op(omega_data, omega_size, b_y_data, b_y_size,
                       SigmaCVInv_data, SigmaInv);
    }
    xoffset = (ii_size / 4) << 2;
    b_i = xoffset - 4;
    for (i = 0; i <= b_i; i += 4) {
      __m128i r2;
      r2 = _mm_loadu_si128((const __m128i *)&xAct_data[i]);
      r2 = _mm_sub_epi32(r2, _mm_set1_epi32(1));
      _mm_storeu_si128((__m128i *)&ii_data[i], r2);
      _mm_storeu_si128((__m128i *)&b_tmp_data[i], r2);
    }
    for (i = xoffset; i < ii_size; i++) {
      loop_ub_tmp = xAct_data[i];
      ii_data[i] = loop_ub_tmp - 1;
      b_tmp_data[i] = loop_ub_tmp - 1;
    }
    SigmaInv[0] = ii_size;
    SigmaInv[1] = ii_size;
    emlrtSubAssignSizeCheckR2012b(&SigmaInv[0], 2, &omega_size[0], 2,
                                  &g_emlrtECI, (emlrtCTX)sp);
    for (i = 0; i < ii_size; i++) {
      for (loop_ub_tmp = 0; loop_ub_tmp < ii_size; loop_ub_tmp++) {
        omegaBU[ii_data[loop_ub_tmp] + 12 * b_tmp_data[i]] =
            omega_data[loop_ub_tmp + ii_size * i];
      }
    }
    st.site = &i_emlrtRSI;
    if (coder::any(Z_data, 12 * Z_size[1])) {
      real_T omegaTerms_data[2304];
      boolean_T activeMatrix_data[36864];
      boolean_T activeLinks_data[192];
      st.site = &j_emlrtRSI;
      b_st.site = &ic_emlrtRSI;
      k = coder::eml_find(b_st, Z_data, Z_size, c_ii_data, jj_data, vlen);
      for (i = 0; i < vlen; i++) {
        phiTerms_data[i] = jj_data[i];
      }
      st.site = &k_emlrtRSI;
      b_st.site = &nc_emlrtRSI;
      c_st.site = &oc_emlrtRSI;
      if (vlen != k) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
      }
      availLinks_size[0] = k;
      availLinks_size[1] = 2;
      if (k - 1 >= 0) {
        std::copy(&c_ii_data[0], &c_ii_data[k], &availLinks_data[0]);
      }
      for (i = 0; i < vlen; i++) {
        availLinks_data[i + k] = static_cast<int32_T>(phiTerms_data[i]);
      }
      wt_size[0] = k;
      wt_size[1] = 1;
      wt_size[2] = 2;
      loop_ub = k << 1;
      if (loop_ub - 1 >= 0) {
        std::memset(&wt_data[0], 0,
                    static_cast<uint32_T>(loop_ub) * sizeof(real_T));
      }
      st.site = &l_emlrtRSI;
      for (i = 0; i < k; i++) {
        phiTerms_data[i] = availLinks_data[i];
        b_availLinks_data[i] = availLinks_data[i + k];
      }
      b_st.site = &pc_emlrtRSI;
      k = coder::internal::sub2ind(b_st, phi_size, phiTerms_data, k,
                                   b_availLinks_data, k, c_ii_data);
      st.site = &l_emlrtRSI;
      coder::internal::indexShapeCheck(st, phi_size, k);
      i = 12 * phi_size[1];
      for (loop_ub_tmp = 0; loop_ub_tmp < k; loop_ub_tmp++) {
        i1 = c_ii_data[loop_ub_tmp];
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &f_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        phiTerms_data[loop_ub_tmp] = phi_data[i1 - 1];
      }
      omegaTerms_size[0] = availLinks_size[0];
      omegaTerms_size[1] = 12;
      loop_ub = availLinks_size[0];
      for (i = 0; i < 12; i++) {
        for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
          i1 = availLinks_data[loop_ub_tmp];
          if ((i1 < 1) || (i1 > 12)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, 12, &g_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          omegaTerms_data[loop_ub_tmp + omegaTerms_size[0] * i] =
              omegaBU[(i1 + 12 * i) - 1];
        }
      }
      for (b_i = 0; b_i < 24; b_i++) {
        vnan[b_i] = v[b_i];
        if (muDoubleScalarIsNaN(v[b_i])) {
          vnan[b_i] = 0.0;
        }
      }
      vlen = availLinks_size[0];
      loop_ub = availLinks_size[0];
      for (i = 0; i < loop_ub; i++) {
        activeLinks_data[i] = (x[availLinks_data[i] - 1] == 1.0);
      }
      activeMatrix_size[0] = availLinks_size[0];
      activeMatrix_size[1] = availLinks_size[0];
      for (i = 0; i < vlen; i++) {
        for (loop_ub_tmp = 0; loop_ub_tmp < vlen; loop_ub_tmp++) {
          activeMatrix_data[loop_ub_tmp + vlen * i] =
              (activeLinks_data[i] && activeLinks_data[loop_ub_tmp]);
        }
      }
      phiProductMatrix.set_size(&u_emlrtRTEI, sp, k, k);
      for (i = 0; i < k; i++) {
        xoffset = (k / 2) << 1;
        b_i = xoffset - 2;
        for (loop_ub_tmp = 0; loop_ub_tmp <= b_i; loop_ub_tmp += 2) {
          r = _mm_loadu_pd(&phiTerms_data[loop_ub_tmp]);
          r = _mm_mul_pd(r, _mm_set1_pd(phiTerms_data[i]));
          _mm_storeu_pd(
              &phiProductMatrix[loop_ub_tmp + phiProductMatrix.size(0) * i], r);
        }
        for (loop_ub_tmp = xoffset; loop_ub_tmp < k; loop_ub_tmp++) {
          phiProductMatrix[loop_ub_tmp + phiProductMatrix.size(0) * i] =
              phiTerms_data[loop_ub_tmp] * phiTerms_data[i];
        }
      }
      st.site = &m_emlrtRSI;
      b_st.site = &dc_emlrtRSI;
      coder::internal::blas::mtimes(b_st, omegaTerms_data, omegaTerms_size,
                                    omegaTerms_data, omegaTerms_size,
                                    omegaProductMatrix);
      SigmaCtllhInv.set_size(&v_emlrtRTEI, sp, availLinks_size[0],
                             availLinks_size[0]);
      loop_ub_tmp = availLinks_size[0] * availLinks_size[0];
      for (i = 0; i < loop_ub_tmp; i++) {
        SigmaCtllhInv[i] = 0.0;
      }
      ZAct_size[0] = (*(int32_T(*)[2])omegaProductMatrix.size())[0];
      ZAct_size[1] = (*(int32_T(*)[2])omegaProductMatrix.size())[1];
      st.site = &n_emlrtRSI;
      coder::internal::indexShapeCheck(st, ZAct_size, activeMatrix_size);
      ZAct_size[0] = (*(int32_T(*)[2])phiProductMatrix.size())[0];
      ZAct_size[1] = (*(int32_T(*)[2])phiProductMatrix.size())[1];
      st.site = &n_emlrtRSI;
      coder::internal::indexShapeCheck(st, ZAct_size, activeMatrix_size);
      xoffset = loop_ub_tmp - 1;
      vlen = 0;
      for (b_i = 0; b_i <= xoffset; b_i++) {
        if (activeMatrix_data[b_i]) {
          vlen++;
        }
      }
      r3.set_size(&w_emlrtRTEI, sp, vlen);
      vlen = 0;
      for (b_i = 0; b_i <= xoffset; b_i++) {
        if (activeMatrix_data[b_i]) {
          r3[vlen] = static_cast<uint16_T>(b_i);
          vlen++;
        }
      }
      vlen = omegaProductMatrix.size(0) * omegaProductMatrix.size(1);
      loop_ub = r3.size(0);
      for (i = 0; i < loop_ub; i++) {
        if (r3[i] > vlen - 1) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(r3[i]), 0,
                                        vlen - 1, &h_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
      }
      vlen = phiProductMatrix.size(0) * phiProductMatrix.size(1);
      loop_ub = r3.size(0);
      for (i = 0; i < loop_ub; i++) {
        if (r3[i] > vlen - 1) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(r3[i]), 0,
                                        vlen - 1, &i_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
      }
      r4.set_size(&x_emlrtRTEI, sp, r3.size(0));
      loop_ub = r3.size(0);
      for (i = 0; i < loop_ub; i++) {
        r4[i] = omegaProductMatrix[static_cast<int32_T>(r3[i])] *
                phiProductMatrix[static_cast<int32_T>(r3[i])];
      }
      if (r3.size(0) != r4.size(0)) {
        emlrtSubAssignSizeCheck1dR2017a(r3.size(0), r4.size(0), &j_emlrtECI,
                                        (emlrtConstCTX)sp);
      }
      loop_ub = r4.size(0);
      for (i = 0; i < loop_ub; i++) {
        if (r3[i] > loop_ub_tmp - 1) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(r3[i]), 0,
                                        loop_ub_tmp - 1, &j_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        SigmaCtllhInv[static_cast<int32_T>(r3[i])] = r4[i];
      }
      st.site = &o_emlrtRSI;
      for (i = 0; i <= 10; i += 2) {
        r = _mm_loadu_pd(&phiSum[i]);
        r1 = _mm_loadu_pd(&vnan[i]);
        _mm_storeu_pd(&b_phiSum[i],
                      _mm_mul_pd(_mm_add_pd(r, _mm_set1_pd(1.0)), r1));
      }
      b_st.site = &dc_emlrtRSI;
      vlen = coder::internal::blas::mtimes(omegaTerms_data, omegaTerms_size,
                                           b_phiSum, b_availLinks_data);
      if ((k != vlen) && ((k != 1) && (vlen != 1))) {
        emlrtDimSizeImpxCheckR2021b(k, vlen, &h_emlrtECI, (emlrtConstCTX)sp);
      }
      if (k == vlen) {
        vlen = k;
        xoffset = (k / 2) << 1;
        b_i = xoffset - 2;
        for (i = 0; i <= b_i; i += 2) {
          r = _mm_loadu_pd(&phiTerms_data[i]);
          r1 = _mm_loadu_pd(&b_availLinks_data[i]);
          _mm_storeu_pd(&b_availLinks_data[i], _mm_mul_pd(r, r1));
        }
        for (i = xoffset; i < k; i++) {
          b_availLinks_data[i] *= phiTerms_data[i];
        }
      } else {
        b_times(b_availLinks_data, vlen, phiTerms_data, k);
      }
      emlrtSubAssignSizeCheckR2012b(&availLinks_size[0], 1, &vlen, 1,
                                    &k_emlrtECI, (emlrtCTX)sp);
      loop_ub = availLinks_size[0];
      if (loop_ub - 1 >= 0) {
        std::copy(&b_availLinks_data[0], &b_availLinks_data[loop_ub],
                  &wt_data[0]);
      }
      st.site = &p_emlrtRSI;
      for (i = 0; i <= 10; i += 2) {
        r = _mm_loadu_pd(&phiSum[i]);
        r1 = _mm_loadu_pd(&vnan[i + 12]);
        _mm_storeu_pd(&b_phiSum[i],
                      _mm_mul_pd(_mm_add_pd(r, _mm_set1_pd(1.0)), r1));
      }
      b_st.site = &dc_emlrtRSI;
      vlen = coder::internal::blas::mtimes(omegaTerms_data, omegaTerms_size,
                                           b_phiSum, b_availLinks_data);
      if ((k != vlen) && ((k != 1) && (vlen != 1))) {
        emlrtDimSizeImpxCheckR2021b(k, vlen, &i_emlrtECI, (emlrtConstCTX)sp);
      }
      if (k == vlen) {
        xoffset = (k / 2) << 1;
        b_i = xoffset - 2;
        for (i = 0; i <= b_i; i += 2) {
          r = _mm_loadu_pd(&phiTerms_data[i]);
          r1 = _mm_loadu_pd(&b_availLinks_data[i]);
          _mm_storeu_pd(&phiTerms_data[i], _mm_mul_pd(r, r1));
        }
        for (i = xoffset; i < k; i++) {
          phiTerms_data[i] *= b_availLinks_data[i];
        }
      } else {
        times(phiTerms_data, k, b_availLinks_data, vlen);
      }
      emlrtSubAssignSizeCheckR2012b(&wt_size[0], 1, &k, 1, &l_emlrtECI,
                                    (emlrtCTX)sp);
      loop_ub = wt_size[0];
      for (i = 0; i < loop_ub; i++) {
        wt_data[i + wt_size[0]] = phiTerms_data[i];
      }
    } else {
      SigmaC_size[0] = 1;
      SigmaC_size[1] = 1;
      SigmaC_data[0] = 1.0;
      SigmaCtllhInv.set_size(&t_emlrtRTEI, sp, 1, 1);
      SigmaCtllhInv[0] = 0.0;
      wt_size[0] = 1;
      wt_size[1] = 1;
      wt_size[2] = 1;
      wt_data[0] = 0.0;
    }
  } else {
    SigmaC_size[0] = 1;
    SigmaC_size[1] = 1;
    SigmaC_data[0] = 1.0;
    SigmaCtllhInv.set_size(&s_emlrtRTEI, sp, 1, 1);
    SigmaCtllhInv[0] = 0.0;
    wt_size[0] = 1;
    wt_size[1] = 1;
    wt_size[2] = 1;
    wt_data[0] = 0.0;
  }
  st.site = &q_emlrtRSI;
  detSigmaC = coder::det(st, SigmaC_data, SigmaC_size);
  st.site = &r_emlrtRSI;
  for (i = 0; i < ii_size; i++) {
    sSq_data[i] = sSq[xAct_data[i] - 1];
  }
  b_st.site = &r_emlrtRSI;
  invSqrtProdSSq = coder::prod(sSq_data, ii_size);
  if (invSqrtProdSSq < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  invSqrtProdSSq = muDoubleScalarSqrt(invSqrtProdSSq);
  invSqrtProdSSq = 1.0 / invSqrtProdSSq;
  p = (detSigmaC < 0.0);
  for (vlen = 0; vlen < 2; vlen++) {
    for (i = 0; i <= 10; i += 2) {
      r = _mm_loadu_pd(&phiSum[i]);
      r1 = _mm_loadu_pd(&v[i + 12 * vlen]);
      _mm_storeu_pd(&sSq[i], _mm_mul_pd(_mm_add_pd(r, _mm_set1_pd(1.0)), r1));
    }
    for (b_i = 0; b_i < 12; b_i++) {
      if (muDoubleScalarIsNaN(sSq[b_i])) {
        sSq[b_i] = 0.0;
      }
    }
    st.site = &t_emlrtRSI;
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    b_sSq = 0.0;
    for (i = 0; i < 12; i++) {
      d = 0.0;
      for (loop_ub_tmp = 0; loop_ub_tmp < 12; loop_ub_tmp++) {
        d += omegaBU[i + 12 * loop_ub_tmp] * sSq[loop_ub_tmp];
      }
      b_sSq += sSq[i] * d;
    }
    st.site = &s_emlrtRSI;
    Psit[vlen] =
        coder::mpower(st, 6.2831853071795862,
                      -static_cast<real_T>(ii_size) / 2.0) *
        coder::mpower(st, sigmaU, -static_cast<real_T>(ptAct_size[1])) *
        invSqrtProdSSq * muDoubleScalarSqrt(detSigmaC) *
        muDoubleScalarExp(-0.5 * b_sSq);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

// End of code generation (calc_pv_trial.cpp)
