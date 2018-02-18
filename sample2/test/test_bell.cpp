#include <vector>
#include <stdexcept>
#include "gtest/gtest.h"
#include "bell.h"

class BellComparisonTest: public ::testing::Test {
protected:
  constexpr static int n_max_ = 10;
  std::vector<int> bell_triangle_precompute_;

  // 開始時処理
  virtual void SetUp() {
    bell_triangle_precompute_.reserve(n_max_ + 1);

    for (int i = 0; i <= n_max_; ++i) {
      bell_triangle_precompute_.push_back(bell_triangle(i));
    }
  }

  // 終了時処理 (今回は不要)
  //virtual boid TearDown() {}

};

TEST(BellTriangleTest, WrongDomain) {
  // n < 0 だと定義域エラー
  EXPECT_ANY_THROW(bell_triangle(-1));
  EXPECT_ANY_THROW(bell_triangle(-5));
}

TEST(BellTriangleTest, WrongDomainExplicit) {
  // n < 0 だと定義域エラー
  EXPECT_THROW(bell_triangle(-1), std::domain_error);
  EXPECT_THROW(bell_triangle(-5), std::domain_error);
}

TEST(BellTriangleTest, Zero) {
  EXPECT_EQ(1, bell_triangle(0));
}

TEST(BellTriangleTest, Equal) {
  EXPECT_EQ(1, bell_triangle(1));
  EXPECT_EQ(2, bell_triangle(2));
  EXPECT_EQ(5, bell_triangle(3));
  EXPECT_EQ(15, bell_triangle(4));
  EXPECT_EQ(52, bell_triangle(5));
  EXPECT_EQ(203, bell_triangle(6));
  EXPECT_EQ(877, bell_triangle(7));
  EXPECT_EQ(4140, bell_triangle(8));
  EXPECT_EQ(21147, bell_triangle(9));
}

TEST(BellRecursiveTest, WrongDomain) {
  EXPECT_ANY_THROW(bell_recursive(-1));
  EXPECT_ANY_THROW(bell_recursive(-5));
}

TEST(BellRecursiveTest, Zero) {
  EXPECT_EQ(1, bell_recursive(0));
}

TEST_F(BellComparisonTest, Recursive) {
  for (int i = 0; i <= n_max_; ++i) {
    EXPECT_EQ(bell_triangle_precompute_[i], bell_recursive(i));
  }
}

TEST(BellDobinskiTest, WrongDomain) {
  int trunc = 50;
  EXPECT_ANY_THROW(bell_dobinski(-1, trunc));
  EXPECT_ANY_THROW(bell_dobinski(-5, trunc));
  EXPECT_ANY_THROW(bell_dobinski(5, 0));
  EXPECT_ANY_THROW(bell_dobinski(5, -1));
}

TEST(BellDobinskiTest, Zero) {
  int trunc = 50;
  EXPECT_DOUBLE_EQ(1, bell_dobinski(0, trunc));
}

TEST_F(BellComparisonTest, Dobinski) {
  int trunc = 50;
  for (int i = 0; i <= n_max_; ++i) {
    EXPECT_DOUBLE_EQ((double) bell_triangle_precompute_[i],
                      bell_dobinski(i, trunc));
  }
}

TEST_F(BellComparisonTest, DobinskiWithTol) {
  int trunc = 50;
  double tol = 1e-6;
  for (int i = 0; i <= n_max_; ++i) {
    EXPECT_NEAR((double) bell_triangle_precompute_[i],
                bell_dobinski(i, trunc), tol);
  }
}
