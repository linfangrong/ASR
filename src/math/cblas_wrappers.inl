namespace ASR
{

/**** LEVEL ONE BLAS ROUTINES ****/

float cblas_asum(const MKL_INT n, const float *x, const MKL_INT incx) {
    return cblas_sasum(n, x, incx);
}

double cblas_asum(const MKL_INT n, const double *x, const MKL_INT incx) {
    return cblas_dasum(n, x, incx);
}

void cblas_axpy(const MKL_INT n, const float a, const float *x, const MKL_INT incx,
                float *y, const MKL_INT incy) {
    return cblas_saxpy(n, a, x, incx, y, incy);
}

void cblas_axpy(const MKL_INT n, const double a, const double *x, const MKL_INT incx,
                double *y, const MKL_INT incy) {
    return cblas_daxpy(n, a, x, incx, y, incy);
}

void cblas_copy(const MKL_INT n, const float *x, const MKL_INT incx, float *y,
                const MKL_INT incy) {
    return cblas_scopy(n, x, incx, y, incy);
}

void cblas_copy(const MKL_INT n, const double *x, const MKL_INT incx, double *y,
                const MKL_INT incy) {
    return cblas_dcopy(n, x, incx, y, incy);
}

float cblas_dot(const MKL_INT n,const float *x, const MKL_INT incx, const float *y,
                const MKL_INT incy) {
    return cblas_dsdot(n, x, incx, y, incy);
}

double cblas_dot(const MKL_INT n, const double *x, const MKL_INT incx,
                 const double *y, const MKL_INT incy) {
    return cblas_ddot(n, x, incx, y, incy);
}

float cblas_nrm2(const MKL_INT n, const float *x, const MKL_INT incx) {
    return cblas_snrm2(n, x, incx);
}

double cblas_nrm2(const MKL_INT n, const double *x, const MKL_INT incx) {
    return cblas_dnrm2(n, x, incx);
}

void cblas_scal(const MKL_INT n, const float a, float *x, const MKL_INT incx) {
    return cblas_sscal(n, a, x, incx);
}
void cblas_scal(const MKL_INT n, const double a, double *x, const MKL_INT incx) {
    return cblas_dscal(n, a, x, incx);
}

void cblas_swap(const MKL_INT n, float *x, const MKL_INT incx, float *y,
                const MKL_INT incy) {
    cblas_sswap(n, x, incx, y, incy);
}

void cblas_swap(const MKL_INT n, double *x, const MKL_INT incx, double *y,
                const MKL_INT incy) {
    cblas_dswap(n, x, incx, y, incy);
}

size_t cblas_iamax(const MKL_INT n, const float *x, const MKL_INT incx) {
    return static_cast<size_t>(cblas_isamax(n, x, incx));
}

size_t cblas_iamax(const MKL_INT n, const double *x, const MKL_INT incx) {
    return static_cast<size_t>(cblas_idamax(n, x, incx));
}

size_t cblas_iamin(const MKL_INT n, const float *x, const MKL_INT incx) {
    return static_cast<size_t>(cblas_isamin(n, x, incx));
}

size_t cblas_iamin(const MKL_INT n, const double *x, const MKL_INT incx) {
    return static_cast<size_t>(cblas_idamin(n, x, incx));
}


} // end ASR namespace
