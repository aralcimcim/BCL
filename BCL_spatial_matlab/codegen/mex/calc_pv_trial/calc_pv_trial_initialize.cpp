//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calc_pv_trial_initialize.cpp
//
// Code generation for function 'calc_pv_trial_initialize'
//

// Include files
#include "calc_pv_trial_initialize.h"
#include "_coder_calc_pv_trial_mex.h"
#include "calc_pv_trial_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void calc_pv_trial_once();

// Function Definitions
static void calc_pv_trial_once()
{
  mex_InitInfAndNan();
}

void calc_pv_trial_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    calc_pv_trial_once();
  }
}

// End of code generation (calc_pv_trial_initialize.cpp)
