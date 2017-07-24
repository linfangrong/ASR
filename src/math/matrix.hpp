#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <math/cblas_wrappers.hpp>
#include <math/float_compare.hpp>

#include <iostream>

namespace ASR {

template<typename T> class Matrix;
template<typename T> std::ostream& operator<<(std::ostream&, const Matrix<T>&);

template<typename T>
class Matrix {
    friend std::ostream& operator<< <T>(std::ostream&, const Matrix<T>&);
public:
    // Constructors
    Matrix() : mRows(0), mCols(0), mStride(0), mSize(0), mData(nullptr) {}

    Matrix(const size_t rows, const size_t cols,
           T const value = 0.0) {
        Initialize(rows, cols, value);
    }

    ~Matrix() {
        Destroy();
    }

    // Getters and Setters
    size_t GetRows() const { return mRows; }
    size_t GetCols() const { return mCols; }
    size_t GetStride() const { return mStride; }
    size_t GetSize() const { return mSize; }

    T& operator[](const size_t index) { return mData[index]; }
    const T& operator[](const size_t index) const { return mData[index]; }

    T& operator()(const size_t row, const size_t col) { return mData[row * mStride + col]; }
    const T& operator()(const size_t row, const size_t col) { return mData[row * mStride + col]; }

private:

    void Initialize(const size_t rows, const size_t cols,
                    const T value) {
        mCols = cols;
        mRows = rows;
        const bool aligned = (cols * sizeof(T)) % 16 == 0;
        mStride = aligned ? cols : ((cols / 16) + 1) * 16;
        mSize = mRows * mStride;
        AlignedMalloc(&mData, mSize, value);
    }

    void Destroy() {
        if (mData) AlignedFree(mData);
    }

    mutable size_t mRows;
    mutable size_t mCols;
    mutable size_t mStride;
    mutable size_t mSize;
    mutable T *mData;
};

template<typename T>
std::ostream& operator<<(std::ostream &os, const Matrix<T> &mat) {
    for (size_t i = 0; i < mat.mRows; ++i) {
        for (size_t j = 0; j < mat.mCols - 1; ++j) {
            os << mat(i, j) << " ";
        }
        if (mat.mCols != 0 && i != mat.mRows - 1) {
            os << mat[mat.mCols - 1] << std::endl;
        }
    }
    return os;
}

typedef Matrix<float> SMatrix; // single precision
typedef Matrix<double> DMatrix; // double precision

} // end ASR namespace

#endif // end matrix

