//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mtimes.cpp
//
// Code generation for function 'mtimes'
//

// Include files
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    fc_emlrtRSI{
        142,      // lineNo
        "mtimes", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pathName
    };

static emlrtRSInfo
    gc_emlrtRSI{
        178,           // lineNo
        "mtimes_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pathName
    };

static emlrtRTEInfo
    y_emlrtRTEI{
        218,      // lineNo
        20,       // colNo
        "mtimes", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pName
    };

static emlrtRTEInfo
    ab_emlrtRTEI{
        140,      // lineNo
        5,        // colNo
        "mtimes", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pName
    };

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void b_mtimes(const real_T A_data[], const int32_T A_size[2],
              const real_T B_data[], const int32_T B_size[2], real_T C_data[],
              int32_T C_size[2])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  if ((A_size[0] == 0) || (A_size[1] == 0) || (B_size[0] == 0) ||
      (B_size[1] == 0)) {
    int32_T loop_ub;
    C_size[0] = A_size[0];
    C_size[1] = B_size[1];
    loop_ub = A_size[0] * B_size[1];
    if (loop_ub - 1 >= 0) {
      std::memset(&C_data[0], 0,
                  static_cast<uint32_T>(loop_ub) * sizeof(real_T));
    }
  } else {
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A_size[0];
    n_t = (ptrdiff_t)B_size[1];
    k_t = (ptrdiff_t)A_size[1];
    lda_t = (ptrdiff_t)A_size[0];
    ldb_t = (ptrdiff_t)B_size[0];
    ldc_t = (ptrdiff_t)A_size[0];
    C_size[0] = A_size[0];
    C_size[1] = B_size[1];
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

void mtimes(const emlrtStack &sp, const real_T A_data[],
            const int32_T A_size[2], const real_T B_data[],
            const int32_T B_size[2], array<real_T, 2U> &C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((A_size[0] == 0) || (B_size[0] == 0)) {
    int32_T loop_ub;
    C.set_size(&ab_emlrtRTEI, &sp, A_size[0], B_size[0]);
    loop_ub = A_size[0] * B_size[0];
    for (int32_T i{0}; i < loop_ub; i++) {
      C[i] = 0.0;
    }
  } else {
    st.site = &fc_emlrtRSI;
    b_st.site = &gc_emlrtRSI;
    TRANSB1 = 'T';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A_size[0];
    n_t = (ptrdiff_t)B_size[0];
    k_t = (ptrdiff_t)12;
    lda_t = (ptrdiff_t)A_size[0];
    ldb_t = (ptrdiff_t)B_size[0];
    ldc_t = (ptrdiff_t)A_size[0];
    C.set_size(&y_emlrtRTEI, &b_st, A_size[0], B_size[0]);
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &(C.data())[0], &ldc_t);
  }
}

int32_T mtimes(const real_T A_data[], const int32_T A_size[2],
               const real_T B[12], real_T C_data[])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  int32_T C_size;
  char_T TRANSA1;
  char_T TRANSB1;
  if (A_size[0] == 0) {
    C_size = 0;
  } else {
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A_size[0];
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)12;
    lda_t = (ptrdiff_t)A_size[0];
    ldb_t = (ptrdiff_t)12;
    ldc_t = (ptrdiff_t)A_size[0];
    C_size = A_size[0];
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
  return C_size;
}

void mtimes(const real_T A_data[], const int32_T A_size[2],
            const real_T B_data[], const int32_T B_size[2], real_T C_data[],
            int32_T C_size[2])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  if ((A_size[0] == 0) || (B_size[0] == 0) || (B_size[1] == 0)) {
    int32_T loop_ub;
    C_size[0] = A_size[0];
    C_size[1] = B_size[0];
    loop_ub = A_size[0] * B_size[0];
    if (loop_ub - 1 >= 0) {
      std::memset(&C_data[0], 0,
                  static_cast<uint32_T>(loop_ub) * sizeof(real_T));
    }
  } else {
    TRANSB1 = 'T';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A_size[0];
    n_t = (ptrdiff_t)B_size[0];
    k_t = (ptrdiff_t)A_size[1];
    lda_t = (ptrdiff_t)A_size[0];
    ldb_t = (ptrdiff_t)B_size[0];
    ldc_t = (ptrdiff_t)A_size[0];
    C_size[0] = A_size[0];
    C_size[1] = B_size[0];
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (mtimes.cpp)
