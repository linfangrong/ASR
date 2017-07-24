#include <math/vector.hpp>

#include <gtest/gtest.h>

#include <cstdlib>
#include <ctime>

using namespace ASR;

namespace {

const int kSize = 1000;

void InitRandVector(SVector &vec) {
    size_t size = vec.GetSize();
    for (size_t i = 0; i < size; ++i) {
        std::srand(std::time(0));
        vec[i] = static_cast<float>(std::rand() % size) / size;
    }
}

SVector GenerateRValue(const float value) {
    SVector vec(kSize, value);
    return vec;
}

TEST(Vector, testDefaultConstructor) {
    SVector vec;
    EXPECT_EQ(0, vec.GetSize());
}

TEST(Vector, testConstructorWithSize) {
    SVector vec(kSize);
    EXPECT_EQ(kSize, vec.GetSize());
}

TEST(Vector, testConstructorWithSizeAndDefaultValue) {
    const float kValue = 5.0f;
    SVector vec(kSize, kValue);

    for (size_t i = 0; i < kSize; ++i) {
        EXPECT_FLOAT_EQ(kValue, vec[i]);
    }
}

TEST(Vector, testCopyConstructor) {
    SVector original(kSize);
    InitRandVector(original);

    SVector copy(original);
    EXPECT_EQ(original.GetSize(), copy.GetSize());

    for (size_t i = 0; i < kSize; ++i) {
        EXPECT_FLOAT_EQ(original[i], copy[i]);
    }
}

TEST(Vector, testMoveConstructor) {
    const float kValue = 10.0f;
    SVector vec(GenerateRValue(kValue));
    SVector reference(kSize, kValue);

    EXPECT_TRUE(reference == vec);
}

TEST(Vector, testAssignmentOperator) {
    SVector original(kSize);
    InitRandVector(original);

    SVector copy = original;
    EXPECT_EQ(original.GetSize(), copy.GetSize());

    for (size_t i = 0; i < kSize; ++i) {
        EXPECT_FLOAT_EQ(original[i], copy[i]);
    }
}

TEST(Vector, testMoveAssignment) {
    const float kValue = 10.0f;
    SVector vec = GenerateRValue(kValue);
    SVector reference(kSize, kValue);

    EXPECT_TRUE(reference == vec);
}

TEST(Vector, testEqualityOperator) {
    SVector left(kSize);
    InitRandVector(left);

    SVector right(left);
    EXPECT_TRUE(left == right);
}

TEST(Vector, testInequalityOperator) {
    SVector left(kSize);
    InitRandVector(left);

    SVector right(left);
    right[0] += std::numeric_limits<float>::epsilon();

    EXPECT_TRUE(left != right);
}

TEST(Vector, testAdditionEqualsOperator) {
    SVector left(kSize);
    InitRandVector(left);

    SVector right(kSize);
    InitRandVector(right);

    SVector reference(left);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] += right[i];
    }

    left += right;
    EXPECT_TRUE(reference == left);
}

TEST(Vector, testAdditionOperator) {
    SVector left(kSize);
    InitRandVector(left);

    SVector right(kSize);
    InitRandVector(right);

    SVector reference(kSize);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] = left[i] + right[i];
    }

    SVector result = left + right;
    EXPECT_TRUE(result == reference);
}

TEST(Vector, testPrefixIncrementOperator) {
    SVector vec(kSize);
    InitRandVector(vec);

    SVector reference(vec);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] += 1.0;
    }

    ++vec;
    EXPECT_TRUE(reference == vec);
}

TEST(Vector, testPostfixIncrementOperator) {
    SVector vec(kSize);
    InitRandVector(vec);

    SVector preReference(vec);
    SVector postReference(vec);
    for (size_t i = 0; i < kSize; ++i) {
        postReference[i] += 1.0;
    }

    SVector retValue = vec++;
    EXPECT_TRUE(preReference == retValue);
    EXPECT_TRUE(postReference == vec);
}

TEST(Vector, testSubtractionEqualsOperator) {
    SVector left(kSize);
    InitRandVector(left);

    SVector right(kSize);
    InitRandVector(right);

    SVector reference(left);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] -= right[i];
    }

    left -= right;
    EXPECT_TRUE(reference == left);
}

TEST(Vector, testSubtractionOperator) {
    SVector left(kSize);
    InitRandVector(left);

    SVector right(kSize);
    InitRandVector(right);

    SVector reference(kSize);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] = left[i] - right[i];
    }

    SVector result = left - right;
    EXPECT_TRUE(result == reference);
}

TEST(Vector, testPrefixDecrementOperator) {
    SVector vec(kSize);
    InitRandVector(vec);

    SVector reference(vec);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] -= 1.0;
    }

    --vec;
    EXPECT_TRUE(reference == vec);
}

TEST(Vector, testPostfixDecrementOperator) {
    SVector vec(kSize);
    InitRandVector(vec);

    SVector preReference(vec);
    SVector postReference(vec);
    for (size_t i = 0; i < kSize; ++i) {
        postReference[i] -= 1.0;
    }

    SVector retValue = vec--;
    EXPECT_TRUE(preReference == retValue);
    EXPECT_TRUE(postReference == vec);
}

TEST(Vector, testMultiplicationEqualsOperator) {
    SVector left(kSize);
    InitRandVector(left);

    const float kScale = 4.0f;

    SVector reference(left);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] *= kScale;
    }

    left *= kScale;
    EXPECT_TRUE(reference == left);
}

TEST(Vector, testMultiplicationOperator) {
    SVector left(kSize);
    InitRandVector(left);

    const float kScale = 4.0f;

    SVector reference(kSize);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] = left[i] * kScale;
    }

    SVector result = left * kScale;
    EXPECT_TRUE(reference == result);
}

TEST(Vector, testDotMethod) {
    SVector left(kSize);
    InitRandVector(left);

    SVector right(kSize);
    InitRandVector(right);

    double dotProduct = 0.0;
    for (size_t i = 0; i < kSize; ++i) {
        dotProduct += (left[i] * right[i]);
    }

    EXPECT_FLOAT_EQ(static_cast<float>(dotProduct), left.Dot(right));
}

TEST(Vector, testSumMethod) {
    SVector vec(kSize);
    InitRandVector(vec);

    double sum = 0.0;
    for (size_t i = 0; i < kSize; ++i) {
        sum += vec[i];
    }

    EXPECT_FLOAT_EQ(static_cast<float>(sum), vec.Sum());
}

TEST(Vector, testMagnitudeMethod) {
    SVector vec(kSize);
    InitRandVector(vec);

    double magnitude = 0.0;
    for (size_t i = 0; i < kSize; ++i) {
        magnitude += std::pow(vec[i], 2);
    }

    magnitude = std::sqrt(magnitude);

    EXPECT_FLOAT_EQ(static_cast<float>(magnitude), vec.Magnitude());
}

TEST(Vector, testMaxIndexMethod) {
    SVector vec(kSize, 2.0f);

    const size_t index = kSize / 2;
    vec[index] += std::numeric_limits<float>::epsilon() * 2;

    EXPECT_EQ(index, vec.MaxIndex());
}

TEST(Vector, testMinIndexMethod) {
    SVector vec(kSize, 2.0f);

    const size_t index = kSize / 2;
    vec[index] -= std::numeric_limits<float>::epsilon() * 2;

    EXPECT_EQ(index, vec.MinIndex());
}


TEST(Vector, testSwapMethod) {
    SVector original(kSize);
    InitRandVector(original);

    SVector copy(original);
    EXPECT_EQ(original.GetSize(), copy.GetSize());

    for (size_t i = 0; i < kSize; ++i) {
        original[i] *= 2.0f;
    }

    SVector reference(copy);

    original.Swap(copy);

    for (size_t i = 0; i < kSize; ++i) {
        EXPECT_FLOAT_EQ(reference[i], original[i]);
        EXPECT_FLOAT_EQ(reference[i] * 2.0f, copy[i]);
    }
}

TEST(Vector, testScaleMethod) {
    SVector vec(kSize);
    InitRandVector(vec);

    const float kScale = 6.0f;

    SVector reference(vec);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] *= kScale;
    }

    vec.Scale(kScale);
    EXPECT_TRUE(reference == vec);
}

TEST(Vector, testAddMethod) {
    SVector left(kSize);
    InitRandVector(left);

    SVector right(kSize);
    InitRandVector(right);

    const float kScale = 6.0f;

    SVector reference(left);
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] += right[i] * kScale;
    }

    left.Add(right, kScale);
    EXPECT_TRUE(reference == left);
}

TEST(Vector, testNormalizeMethod) {
    SVector vec(kSize);
    InitRandVector(vec);

    SVector reference(vec);
    double magnitude = 0.0;
    for (size_t i = 0; i < kSize; ++i) {
        magnitude += std::pow(reference[i], 2);
    }

    float scalar = 1.0f / static_cast<float>(std::sqrt(magnitude));
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] *= scalar;
    }

    vec.Normalize();
    EXPECT_TRUE(reference == vec);
}

TEST(Vector, testSoftmaxMethod) {
    SVector vec(kSize);
    InitRandVector(vec);

    SVector reference(vec);
    float sum = 0.0f;
    for (size_t i = 0; i < kSize; ++i) {
        reference[i] = std::exp(reference[i]);
        sum += reference[i];
    }

    for (size_t i = 0; i < kSize; ++i) {
        reference[i] *= (1.0 / sum);
    }

    vec.Softmax();
    EXPECT_TRUE(reference == vec);
}

} // end anonymous namespace
