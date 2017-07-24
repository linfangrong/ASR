#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <util/str.hpp>

#include <cstring>
#include <exception>

#include <errno.h>
#include <stdlib.h>

namespace ASR {

template <typename T>
static void AlignedMalloc(T **ptr, const size_t size, const T value = 0.0,
                          const size_t alignment = 16) {
    void *memptr;
    int error = posix_memalign(&memptr, alignment, size * sizeof(T));
    if (error) {
        throw std::runtime_error(Str() << "Error allocating " << size << " bytes"
                                 " with an alignment of " << alignment << ": "
                                 << strerror(error));
    }
    *ptr = static_cast<T*>(memptr);
    std::fill(*ptr, *ptr + size, value);
}

template <typename T>
static void AlignedFree(T *ptr) {
    free(ptr);
}

} // end ASR namespace

#endif
