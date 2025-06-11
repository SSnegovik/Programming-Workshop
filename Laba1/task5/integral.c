#include "integral.h"

#include <math.h>
#include <stdio.h>

double integral(double a, double b, int n, double (*f)(double)) {
  double h = (b - a) / n;
  double sum = 0.5 * (f(a) + f(b));

  for (int i = 1; i < n; i++) {
    double x = a + i * h;
    sum += f(x);
  }

  return sum * h;
}
