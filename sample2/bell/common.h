#ifndef COMMON_H_
#define COMMON_H_

#include <vector>
#include <stdexcept>

int binom(int n, int k) {
  if (n < 0 || k < 0 || n < k) {
    throw std::domain_error("Invalid input: binom(n, k) is defined for 0 <= k <= n");
  }
  int k_ = std::min(k, n - k);

  std::vector<int> c(k_ + 1); // row of the Pascal triangle
  c[0] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = std::min(i, k_); j > 0; --j) {
      c[j] = c[j] + c[j - 1];
    }
  }
  return c[k_];
}

double binom_approx(int n, int k) {
  if (n < 0 || k < 0 || n < k) {
    throw std::domain_error("Invalid input: binom(n, k) is defined for 0 <= k <= n");
  }
  int k_ = std::min(k, n - k);

  double c = 1;
  for (int i = 1; i <= k_ + 1; ++i) {
    c *= static_cast<double>(n + 1 - i) / i;
  }
  return c;
}

int factorial(int n) {
  if (n < 0) {
    throw std::domain_error("Invalid input: factorial(n) is defined for n >= 0");
  }
  int out = 1;
  for (int i = 1; i <= n; ++i) {
    out *= i;
  }
  return out;
}

#endif
