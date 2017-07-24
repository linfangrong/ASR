#ifndef FLOAT_COMPARE_HPP_
#define FLOAT_COMPARE_HPP_

#include <cmath>
#include <limits>
namespace ASR {

template <typename T>
static bool Equal(T lhs, T rhs) {
    return std::fabs(lhs - rhs) <= std::numeric_limits<T>::epsilon() *
           std::fmax(std::fabs(lhs), std::fabs(rhs));
}

} // end ASR namespace

#endif
