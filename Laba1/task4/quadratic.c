#include "quadratic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long double *find_roots(long double a, long double b, long double c,
                        long double eps) {
  if (fabs(a) < eps) {
    return NULL;
  }

  long double d = b * b - 4 * a * c;

  if (d < -eps) {
    return NULL;
  }

  if (fabs(d) < eps) {
    long double *result = (long double *)malloc(sizeof(long double));
    result[0] = -b / (2 * a);
    return result;
  } else {
    long double *result = (long double *)malloc(2 * sizeof(long double));
    long double sqrt_d = sqrt(d);

    long double x = -0.5 * (b + (b > 0 ? sqrt_d : -sqrt_d));
    result[0] = x / a;
    result[1] = c / x;

    if (fabsl(result[0] - result[1]) > eps && result[0] > result[1]) {
      long double temp = result[0];
      result[0] = result[1];
      result[1] = temp;
    }

    return result;
  }
}
