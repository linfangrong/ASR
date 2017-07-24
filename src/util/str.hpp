#ifndef STR_HPP
#define STR_HPP

#include <sstream>
#include <string>

namespace ASR {

struct SSWrapper {
    std::stringstream ss;
    operator std::string() { return ss.str(); }
};

template <typename T>
SSWrapper& operator<<(SSWrapper &str, const T &value) {
    str.ss << value;
    return str;
}

template <typename T>
SSWrapper& operator<<(SSWrapper &&str, const T &value) {
    str.ss << value;
    return str;
}

SSWrapper Str();

} // end ASR namespace

#endif // END STR
