//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_calc_pv_trial_mex.cpp
//
// Code generation for function '_coder_calc_pv_trial_mex'
//

// Include files
#include "_coder_calc_pv_trial_mex.h"
#include "_coder_calc_pv_trial_api.h"
#include "calc_pv_trial_data.h"
#include "calc_pv_trial_initialize.h"
#include "calc_pv_trial_terminate.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void calc_pv_trial_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
                               const mxArray *prhs[7])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[4];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        13, "calc_pv_trial");
  }
  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "calc_pv_trial");
  }
  // Call the function.
  calc_pv_trial_api(prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&calc_pv_trial_atexit);
  // Module initialization.
  calc_pv_trial_initialize();
  try {
    // Dispatch the entry-point.
    calc_pv_trial_mexFunction(nlhs, plhs, nrhs, prhs);
    // Module termination.
    calc_pv_trial_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_calc_pv_trial_mex.cpp)
