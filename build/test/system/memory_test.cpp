#include <system/memory.hpp>

#include <gtest/gtest.h>

using namespace ASR;

namespace {

typedef unsigned long long ull;

const ull kLargeSize = -1;
const int kSize = 100;
const int kValue = 10;

TEST(Memory, testAlignedMalloc) {
    int *ptr;
    AlignedMalloc(&ptr, kSize, kValue);

    EXPECT_TRUE(!!ptr);

    const ull addr = (ull)ptr;

    EXPECT_TRUE(addr % 16 == 0);

    for (size_t i = 0; i < kSize; ++i) {
        EXPECT_EQ(kValue, ptr[i]);
    }

    AlignedFree(ptr);
}

TEST(Memory, testAlignedMallocFailure) {
    int *ptr;
    EXPECT_THROW(AlignedMalloc(&ptr, kLargeSize, kValue), std::runtime_error);
}

} // end anonymous namespace
