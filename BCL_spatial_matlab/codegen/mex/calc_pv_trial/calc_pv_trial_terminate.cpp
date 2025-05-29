//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calc_pv_trial_terminate.cpp
//
// Code generation for function 'calc_pv_trial_terminate'
//

// Include files
#include "calc_pv_trial_terminate.h"
#include "_coder_calc_pv_trial_mex.h"
#include "calc_pv_trial_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void calc_pv_trial_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void calc_pv_trial_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (calc_pv_trial_terminate.cpp)
