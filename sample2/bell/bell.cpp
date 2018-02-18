#include <vector>
#include <utility>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "common.h"
#include "bell.h"

int bell_triangle(int n) {
  if (n < 0) {
    throw std::domain_error("Invalid input: bell_triangle(n) is defined for n >= 0");
  }

  if (n == 0) {
    return 1;
  }

  std::vector<int> prev_row(n);
  std::vector<int> curr_row(n);
  prev_row[0] = 1;
  curr_row[0] = 1;

  for (int row_id = 2; row_id <= n; ++row_id) {
    curr_row[0] = prev_row[row_id - 2];
    for (int j = 1; j < row_id; ++j) {
      curr_row[j] = curr_row[j - 1] + prev_row[j - 1];
    }
    if (row_id < n) {
      curr_row.swap(prev_row);
    }
  }

  return curr_row[n - 1];
}

int bell_recursive(int n) {
  if (n < 0) {
    throw std::domain_error("Invalid input: bell_recursive(n) is defined for n >= 0");
  }

  if (n == 0) {
    return 1;
  }

  std::vector<int> memo(n + 1, -1);
  return _bell_recursive(n, memo);
}

// auxiliary function for bell_recursive
int _bell_recursive(int n, std::vector<int>& memo) {
  if (n == 0) {
    return 1;
  }

  int out = 0;
  for(int i = 0; i <= n - 1; ++i) {
    int b_i;
    if (memo[i] == -1) {
      b_i = _bell_recursive(i, memo);
      memo[i] = b_i;
    } else {
      b_i = memo[i];
    }
    out += binom(n - 1, i) * b_i;
  }

  return out;
}

/*
// テスト失敗例
double bell_dobinski(int n, int trunc) {
  if (n < 0) {
    throw std::domain_error("Invalid input: bell_dobinski(n, trunc) is defined for n >= 0");
  }
  if (trunc < 1) {
    throw std::domain_error("Invalid input: bell_dobinski(n, trunc) is defined for trunc >= 1");
  }

  double out = 0;
  for (int i = 0; i <= trunc; ++i) {
    out += std::pow((double)i, n) / factorial(i); // ここでオーバーフローする
  }
  return out / math_e;
}
*/

double bell_dobinski(int n, int trunc) {
  if (n < 0) {
    throw std::domain_error("Invalid input: bell_dobinski(n, trunc) is defined for n >= 0");
  }
  if (trunc < 1) {
    throw std::domain_error("Invalid input: bell_dobinski(n, trunc) is defined for trunc >= 1");
  }

  if (n == 0) {
    return 1.0;
  }

  double out = 0;
  for (int i = 1; i <= trunc; ++i) {
    out += std::exp(n * std::log(i) - std::lgamma(i + 1));
  }
  return out / math_e;
}
