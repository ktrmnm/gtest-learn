#ifndef BELL_H_
#define BELL_H_

#include <vector>
#include <cmath>

int bell_triangle(int n);
int bell_recursive(int n);
int _bell_recursive(int n, std::vector<int>& memo);
double bell_dobinski(int n, int trunc = 20);

const static double math_e = std::exp(1);

#endif
