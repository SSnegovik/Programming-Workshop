#include "integral.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double parabola(double x) { return pow(x, 2); }

void test_integral_1() {
  double res = integral(1, 2, 1000, parabola);
  double correct_answer = 2.333333;
  assert(fabs(res - correct_answer) <= correct_answer * 1e-6);
}

void test_integral_2() {
  double res = integral(16, 47, 1000, parabola);
  double correct_answer = 33242.333333;
  assert(fabs(res - correct_answer) <= correct_answer * 1e-6);
}

int main() {
  test_integral_1();
  test_integral_2();
  return 0;
}
