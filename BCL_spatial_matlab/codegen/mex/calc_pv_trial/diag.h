//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// diag.h
//
// Code generation for function 'diag'
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
void diag(const real_T v_data[], int32_T v_size, real_T d_data[],
          int32_T d_size[2]);

}

// End of code generation (diag.h)
