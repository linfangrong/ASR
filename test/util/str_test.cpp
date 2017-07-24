#include <util/str.hpp>

#include <gtest/gtest.h>

using namespace ASR;

namespace {

const std::string kTestString("testing..1..2..3");

TEST(Str, testLValueToStream) {
    SSWrapper str;
    str << kTestString;
    EXPECT_TRUE(str.ss.str() == kTestString);
}

TEST(Str, testRValueToStream) {
    SSWrapper str;
    EXPECT_TRUE((Str() << kTestString).ss.str() == kTestString);
}

} // end anonymous namespace
