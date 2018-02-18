#include "gtest/gtest.h"
#include "common.h"
#include <cmath>

TEST(BinomTest, WrongDomain) {
  // binom(n, k) は 0 <= k <= n 以外の入力を受け取るとdomain_errorを送出する
  EXPECT_ANY_THROW(binom(-1, 2)); // n < 0
  EXPECT_ANY_THROW(binom(4, -2)); // k < 0
  EXPECT_ANY_THROW(binom(-3, -2)); // n < 0 && k < 0
  EXPECT_ANY_THROW(binom(5, 6)); // n < k
}

TEST(BinomTest, Zero) {
  EXPECT_EQ(1, binom(0, 0));
}

TEST(BinomTest, Equal) {
  EXPECT_EQ(1, binom(1, 0));
  EXPECT_EQ(6, binom(4, 2));

  EXPECT_EQ(1, binom(5, 0));
  EXPECT_EQ(5, binom(5, 1));
  EXPECT_EQ(10, binom(5, 2));
  EXPECT_EQ(10, binom(5, 3));
  EXPECT_EQ(5, binom(5, 1));
  EXPECT_EQ(1, binom(5, 5));
}

TEST(BinomApproxTest, WrongDomain) {
  // binom_approx(n, k) は 0 <= k <= n 以外の入力を受け取るとdomain_errorを送出する
  EXPECT_ANY_THROW(binom(-1, 2));
  EXPECT_ANY_THROW(binom(4, -2));
  EXPECT_ANY_THROW(binom(-3, -2));
  EXPECT_ANY_THROW(binom(5, 6));
}

TEST(BinomApproxTest, Zero) {
  EXPECT_DOUBLE_EQ(1, binom(0, 0));
}

TEST(BinomApproxTest, Equal) {
  EXPECT_DOUBLE_EQ(1, binom(1, 0));
  EXPECT_DOUBLE_EQ(6, binom(4, 2));

  EXPECT_DOUBLE_EQ(1, binom(5, 0));
  EXPECT_DOUBLE_EQ(5, binom(5, 1));
  EXPECT_DOUBLE_EQ(10, binom(5, 2));
  EXPECT_DOUBLE_EQ(10, binom(5, 3));
  EXPECT_DOUBLE_EQ(5, binom(5, 1));
  EXPECT_DOUBLE_EQ(1, binom(5, 5));
}

TEST(FactorialTest, WrongDomain) {
  EXPECT_ANY_THROW(factorial(-1));
  EXPECT_ANY_THROW(factorial(-10));
}

TEST(FactorialTest, Zero) {
  EXPECT_EQ(1, factorial(0));
}

TEST(FactorialTest, Equal) {
  EXPECT_EQ(1, factorial(1));
  EXPECT_EQ(2, factorial(2));
  EXPECT_EQ(6, factorial(3));
  EXPECT_EQ(24, factorial(4));
  EXPECT_EQ(120, factorial(5));
}
