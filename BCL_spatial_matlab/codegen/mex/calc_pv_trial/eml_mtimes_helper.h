//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eml_mtimes_helper.h
//
// Code generation for function 'eml_mtimes_helper'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
void dynamic_size_checks(const emlrtStack &sp, const int32_T a_size[2],
                         const int32_T b_size[2], int32_T innerDimA,
                         int32_T innerDimB);

}

// End of code generation (eml_mtimes_helper.h)
