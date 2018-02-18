#include <iostream>
#include "sample1.h"

// 注: nが負のときは1になる
int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}
