/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calc_px_training_api.c
 *
 * Code generation for function '_coder_calc_px_training_api'
 *
 */

/* Include files */
#include "_coder_calc_px_training_api.h"
#include "calc_px_training.h"
#include "calc_px_training_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T *b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2]);

static real_T *c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier, int32_T y_size[2]);

static real_T *d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2]);

static real_T *e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier, int32_T y_size[2]);

static real_T *emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier, int32_T y_size[2]);

static const mxArray *emlrt_marshallOut(const real_T u);

static real_T *f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2]);

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier);

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T *i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2]);

static real_T *j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2]);

static real_T *k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2]);

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T *b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2])
{
  real_T *y_data;
  y_data = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T *c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y_data = d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y_size);
  emlrtDestroyArray(&nullptr);
  return y_data;
}

static real_T *d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2])
{
  real_T *y_data;
  y_data = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T *e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y_data = f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y_size);
  emlrtDestroyArray(&nullptr);
  return y_data;
}

static real_T *emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y_data = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y_size);
  emlrtDestroyArray(&nullptr);
  return y_data;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static real_T *f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2])
{
  real_T *y_data;
  y_data = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T *i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2])
{
  static const int32_T dims[2] = {12, 144};
  real_T *ret_data;
  int32_T iv[2];
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret_data;
}

static real_T *j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2])
{
  static const int32_T dims[2] = {16, 144};
  real_T *ret_data;
  int32_T iv[2];
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret_data;
}

static real_T *k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2])
{
  static const int32_T dims[2] = {12, 16};
  real_T *ret_data;
  int32_T iv[2];
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret_data;
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void calc_px_training_api(const mxArray *const prhs[6], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*Y_data)[2304];
  real_T(*X_data)[1728];
  real_T(*Z_data)[192];
  real_T eps;
  real_T lda;
  real_T varargin_1;
  int32_T X_size[2];
  int32_T Y_size[2];
  int32_T Z_size[2];
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  *(real_T **)&X_data = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X", X_size);
  *(real_T **)&Y_data =
      c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Y", Y_size);
  *(real_T **)&Z_data =
      e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Z", Z_size);
  lda = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "lda");
  eps = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "eps");
  varargin_1 = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "varargin_1");
  /* Invoke the target function */
  lda = calc_px_training(&st, *X_data, X_size, *Y_data, Y_size, *Z_data, Z_size,
                         lda, eps, varargin_1);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(lda);
}

/* End of code generation (_coder_calc_px_training_api.c) */
