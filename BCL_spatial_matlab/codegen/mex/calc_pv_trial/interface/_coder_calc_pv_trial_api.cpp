//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_calc_pv_trial_api.cpp
//
// Code generation for function '_coder_calc_pv_trial_api'
//

// Include files
#include "_coder_calc_pv_trial_api.h"
#include "calc_pv_trial.h"
#include "calc_pv_trial_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static const int32_T iv[3]{0, 0, 0};

// Function Declarations
static real_T (*b_emlrt_marshallIn(const emlrtStack &sp,
                                   const mxArray *b_nullptr,
                                   const char_T *identifier))[24];

static real_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[24];

static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T &ret_size);

static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2]);

static const mxArray *b_emlrt_marshallOut(const boolean_T u_data[],
                                          const int32_T u_size[2]);

static real_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier);

static real_T (*d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[12];

static real_T (*e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[24];

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[12];

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[12];

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                const char_T *identifier, int32_T &y_size);

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T &y_size);

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                const char_T *identifier, int32_T y_size[2]);

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T y_size[2]);

static const mxArray *emlrt_marshallOut(const real_T u_data[],
                                        const int32_T u_size[3]);

static const mxArray *emlrt_marshallOut(const real_T u[2]);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static real_T f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

// Function Definitions
static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2])
{
  static const int32_T dims[2]{12, 16};
  real_T *ret_data;
  int32_T b_iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret_size[0] = b_iv[0];
  ret_size[1] = b_iv[1];
  ret_data = static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret_data;
}

static real_T (*b_emlrt_marshallIn(const emlrtStack &sp,
                                   const mxArray *b_nullptr,
                                   const char_T *identifier))[24]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[24];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[24]
{
  real_T(*y)[24];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T &ret_size)
{
  static const int32_T dims{16};
  real_T *ret_data;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &ret_size);
  ret_data = static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret_data;
}

static const mxArray *b_emlrt_marshallOut(const boolean_T u_data[],
                                          const int32_T u_size[2])
{
  static const int32_T b_iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateLogicalArray(2, &b_iv[0]);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u_size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[12]
{
  static const int32_T dims{12};
  real_T(*ret)[12];
  int32_T i;
  boolean_T b{false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[12])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[24]
{
  static const int32_T dims[3]{12, 1, 2};
  real_T(*ret)[24];
  int32_T b_iv[3];
  boolean_T bv[3]{false, false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 3U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[24])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[12]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[12];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[12]
{
  real_T(*y)[12];
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                const char_T *identifier, int32_T &y_size)
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y_data = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y_size);
  emlrtDestroyArray(&b_nullptr);
  return y_data;
}

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T &y_size)
{
  real_T *y_data;
  y_data = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y_data = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y_size);
  emlrtDestroyArray(&b_nullptr);
  return y_data;
}

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T y_size[2])
{
  real_T *y_data;
  y_data = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T b_iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[2])
{
  static const int32_T b_iv[3]{1, 1, 2};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(3, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &b_iv[0], 3);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u_data[],
                                        const int32_T u_size[3])
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(3, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u_size[0], 3);
  emlrtAssign(&y, m);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

void calc_pv_trial_api(const mxArray *const prhs[7], int32_T nlhs,
                       const mxArray *plhs[4])
{
  coder::array<real_T, 2U> SigmaCtllhInv;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*wt_data)[384];
  real_T(*Z_data)[192];
  real_T(*v)[24];
  real_T(*y_data)[16];
  real_T(*x)[12];
  real_T(*Psit)[2];
  real_T phi;
  real_T sigmaU;
  real_T sigmaV;
  int32_T wt_size[3];
  int32_T Z_size[2];
  int32_T zc_size[2];
  int32_T y_size;
  boolean_T(*zc_data)[192];
  st.tls = emlrtRootTLSGlobal;
  wt_data = (real_T(*)[384])mxMalloc(sizeof(real_T[384]));
  Psit = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  zc_data = (boolean_T(*)[192])mxMalloc(sizeof(boolean_T[192]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  x = emlrt_marshallIn(st, emlrtAlias(prhs[0]), "x");
  v = b_emlrt_marshallIn(st, emlrtAlias(prhs[1]), "v");
  *(real_T **)&y_data = emlrt_marshallIn(st, emlrtAlias(prhs[2]), "y", y_size);
  *(real_T **)&Z_data = emlrt_marshallIn(st, emlrtAlias(prhs[3]), "Z", Z_size);
  sigmaU = c_emlrt_marshallIn(st, emlrtAliasP(prhs[4]), "sigmaU");
  sigmaV = c_emlrt_marshallIn(st, emlrtAliasP(prhs[5]), "sigmaV");
  phi = c_emlrt_marshallIn(st, emlrtAliasP(prhs[6]), "phi");
  // Invoke the target function
  calc_pv_trial(&st, *x, *v, *y_data, &y_size, *Z_data, Z_size, sigmaU, sigmaV,
                phi, SigmaCtllhInv, *wt_data, wt_size, *Psit, *zc_data,
                zc_size);
  // Marshall function outputs
  SigmaCtllhInv.no_free();
  plhs[0] = emlrt_marshallOut(SigmaCtllhInv);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*wt_data, wt_size);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(*Psit);
  }
  if (nlhs > 3) {
    plhs[3] = b_emlrt_marshallOut(*zc_data, zc_size);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_calc_pv_trial_api.cpp)
