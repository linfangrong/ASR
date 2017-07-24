#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <math/cblas_wrappers.hpp>
#include <math/float_compare.hpp>
#include <system/memory.hpp>

#include <iostream>

namespace ASR {

// NOTE: These are math vectors. Not containers.
template<typename T> class Vector;
template<typename T> std::ostream& operator<<(std::ostream&, const Vector<T>&);

template<typename T>
class Vector {
    friend std::ostream& operator<< <T>(std::ostream&, const Vector<T>&);
public:
    // Constructors
    Vector() : mSize(0), mData(nullptr) {}

    explicit Vector(const size_t size) : mSize(size) {
        AlignedMalloc(&mData, size);
    }

    Vector(const size_t size, const T value) : mSize(size) {
        AlignedMalloc(&mData, size, value);
    }

    Vector(const Vector<T> &rhs) {
        mSize = rhs.mSize;
        AlignedMalloc(&mData, mSize);
        cblas_copy(mSize, rhs.mData, 1, mData, 1);
    }

    Vector(Vector<T> &&rhs) {
        mSize = std::move(rhs.mSize);
        mData = std::move(rhs.mData);
    }

    // Assignment Operators
    Vector<T>& operator=(const Vector<T> &rhs) {
        if (rhs == *this) return *this;
        mSize = rhs.mSize;

        if (mData) AlignedFree(mData);
        AlignedMalloc(&mData, mSize);

        cblas_copy(mSize, rhs.mData, 1, mData, 1);
        return *this;
    }

    Vector<T>& operator=(Vector<T> &&rhs) {
        mSize = std::move(rhs.mSize);
        mData = std::move(rhs.mData);
        return *this;
    }

    // Destructor
    ~Vector() {
        if (mData) AlignedFree(mData);
    }

    // Getters and Setters
    uint32_t GetSize() const { return mSize; }

    T& operator[](const int index) { return mData[index]; }
    const T& operator[](const int index) const { return mData[index]; }

    // boolean operators
    bool operator==(const Vector<T> &rhs) const {
        bool ret = (mSize == rhs.mSize);
        for (size_t i = 0; i < mSize; ++i) {
            if (!ret) break;
            ret &= Equal(mData[i], rhs[i]);
        }
        return ret;
    }

    bool operator!=(const Vector<T> &rhs) const {
        return !(*this == rhs);
    }

    // Arithmetic Operators
    void operator+=(const Vector<T> &rhs) {
        cblas_axpy(mSize, 1.0, rhs.mData, 1, mData, 1);
    }

    Vector<T> operator+(const Vector<T> &rhs) const {
        Vector<T> ret(*this);
        ret += rhs;
        return ret;
    }

    // prefix
    Vector<T>& operator++() {
        Vector<T> rhs(mSize, 1.0);
        *this += rhs;
        return *this;
    }

    // postfix
    Vector<T> operator++(int unused) {
        Vector<T> ret(*this);
        Vector<T> rhs(mSize, 1.0);
        *this += rhs;
        return ret;
    }

    void operator-=(const Vector<T> &rhs) {
        cblas_axpy(mSize, -1.0, rhs.mData, 1, mData, 1);
    }

    Vector<T> operator-(const Vector<T> &rhs) const {
        Vector<T> ret(*this);
        ret -= ret;
        return ret;
    }

    // prefix
    Vector<T>& operator--() {
        Vector<T> rhs(mSize, 1.0);
        *this -= rhs;
        return *this;
    }

    // postfix
    Vector<T> operator--(int unused) {
        Vector<T> ret(*this);
        Vector<T> rhs(mSize, 1.0);
        *this -= rhs;
        return ret;
    }

    void operator*=(const T scale) {
        cblas_scal(mSize, scale, mData, 1);
    }

    Vector<T> operator*(const T scale) const {
        Vector<T> ret(*this);
        ret *= scale;
        return ret;
    }

    // Constant Vector operations
    T Dot(const Vector<T> &rhs) const {
       return cblas_dot(mSize, mData, 1, rhs.mData, 1);
    }

    T Sum() const {
       return cblas_asum(mSize, mData, 1);
    }

    T Magnitude() const {
        return cblas_nrm2(mSize, mData, 1);
    }

    size_t MaxIndex() const {
        return cblas_iamax(mSize, mData, 1);
    }

    size_t MinIndex() const {
        return cblas_iamin(mSize, mData, 1);
    }

    // Non-constant Vector operations
    void Swap(const Vector<T> &rhs) {
       cblas_swap(mSize, mData, 1, rhs.mData, 1);
    }

    void Scale(const T scale) {
        cblas_scal(mSize, scale, mData, 1);
    }

    // y := a * x + y
    void Add(const Vector<T> &rhs, const T a = 1.0) {
        cblas_axpy(mSize, a, rhs.mData, 1, mData, 1);
    }

    void Normalize() {
        T scalar = static_cast<T>(1.0) / Magnitude();
        cblas_scal(mSize, scalar, mData, 1);
    }

    void Softmax() {
        T expSum = 0.0;
        for (size_t i = 0; i < mSize; ++i) {
            mData[i] = std::exp(mData[i]);
            expSum += mData[i];
        }
        T scalar = 1.0 / expSum;
        cblas_scal(mSize, scalar, mData, 1);
    }

private:
    size_t mSize;
    T *mData;
};

template<typename T>
std::ostream& operator<<(std::ostream &os, const Vector<T> &vec) {
    for (size_t i = 0; i < vec.mSize - 1; ++i) {
        os << vec[i] << " ";
    }

    if (vec.mSize != 0) os << vec[vec.mSize - 1];

    return os;
}

typedef Vector<float> SVector; // single precision
typedef Vector<double> DVector; // double precision

} // end ASR namespace

#endif // end vector
