#include "sample1.h"
#include "gtest/gtest.h"

TEST(FactorialTest, Negative) {
  EXPECT_EQ(1, factorial(-5));
  EXPECT_EQ(1, factorial(-10));
}

TEST(FactorialTest, Zero) {
  EXPECT_EQ(1, factorial(0));
}

TEST(FactorialTest, Positive) {
  EXPECT_EQ(1, factorial(1));
  EXPECT_EQ(2, factorial(2));
  EXPECT_EQ(120, factorial(5));
}

// 失敗するべきテスト
TEST(FactorialTest, Failure) {
  EXPECT_EQ(42, factorial(0));
}
