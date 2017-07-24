// OpenML

#ifndef CBLAS_WRAPPERS_H_
#define CBLAS_WRAPPERS_H_

#include <stddef.h>
#include <mkl.h>

namespace ASR
{

/**** LEVEL ONE BLAS ROUTINES ****/
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html

// Computes the sum of the magnitudes of elements of a real vector
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html
inline float cblas_asum(const MKL_INT n, const float *x, const MKL_INT incx);
inline double cblas_asum(const MKL_INT n, const double *x, const MKL_INT incx);

// Computes a vector-scalar product and adds the result to a vector
// y := a * x + y
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html
inline void cblas_axpy(const MKL_INT n, const float a, const float *x, const MKL_INT incx,
                       float *y, const MKL_INT incy);
inline void cblas_axpy(const MKL_INT n, const double a, const double *x, const MKL_INT incx,
                       double *y, const MKL_INT incy);
// Copies vector to another vector
// y = x
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html
inline void cblas_copy(const MKL_INT n, const float *x, const MKL_INT incx, float *y,
                       const MKL_INT incy);
inline void cblas_copy(const MKL_INT n, const double *x, const MKL_INT incx, double *y,
                       const MKL_INT incy);

// Computes a vector-vector dot product
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html
inline float cblas_dot(const MKL_INT n,const float *x, const MKL_INT incx, const float *y,
                       const MKL_INT incy);

inline double cblas_dot(const MKL_INT n, const double *x, const MKL_INT incx,
                        const double *y, const MKL_INT incy);

// Computes the Euclidean norm of a vector
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html
inline float cblas_nrm2(const MKL_INT n, const float *x, const MKL_INT incx);
inline double cblas_nrm2(const MKL_INT n, const double *x, const MKL_INT incx);

// Scales the vector
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html
inline void cblas_scal(const MKL_INT n, const float a, float *x, const MKL_INT incx);
inline void cblas_scal(const MKL_INT n, const double a, double *x, const MKL_INT incx);

// Swaps vectors
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html
inline void cblas_swap(const MKL_INT n, float *x, const MKL_INT incx, float *y, const MKL_INT incy);
inline void cblas_swap(const MKL_INT n, double *x, const MKL_INT incx, double *y, const MKL_INT incy);

// Returns the index of the maximum value in a vector
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html
inline size_t cblas_iamax(const MKL_INT n, const float *x, const MKL_INT incx);
inline size_t cblas_iamax(const MKL_INT n, const double *x, const MKL_INT incx);

// Returns the index of the minimum value in a vector
// file:///opt/intel/documentation_2017/en/mkl/common/mklman_c/index.htm#GUID-83E7A0D2-13EB-4003-A875-A538CBBCCC40.html
inline size_t cblas_iamin(const MKL_INT n, const float *x, const MKL_INT incx);
inline size_t cblas_iamin(const MKL_INT n, const double *x, const MKL_INT incx);

} // end ASR namespace

#include "cblas_wrappers.inl"

#endif
