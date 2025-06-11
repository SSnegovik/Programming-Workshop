#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "quadratic.h"

#define DEFAULT_EPSILON 1e-7

bool is_values_equal(long double a, long double b, long double eps) {
  return fabs(a - b) < eps;
}

void test_zero_coefficient_a() {
  long double *result = find_roots(0, 1, 1, DEFAULT_EPSILON);
  assert(result == NULL);
}

void test_coefficient_1_0_m1() {
  long double *result = find_roots(1, 0, -1, DEFAULT_EPSILON);
  long double correct_answer[2] = {-1.0, 1.0};
  assert(is_values_equal(result[0], correct_answer[0], DEFAULT_EPSILON) &&
         is_values_equal(correct_answer[1], result[1], DEFAULT_EPSILON));
}

void test_coefficient_1_0_0() {
  long double *result = find_roots(1, 0, 0, DEFAULT_EPSILON);
  long double correct_answer[1] = {0};
  assert(is_values_equal(result[0], correct_answer[0], DEFAULT_EPSILON));
}

void test_coefficient_1_0_1() {
  long double *result = find_roots(1, 0, 1, DEFAULT_EPSILON);
  assert(result == NULL);
}

void test_coefficient_1_0_m1em7() {
  long double local_epsilon = 1e-4;
  long double *result = find_roots(1, 0, -1e-7, local_epsilon);
  long double correct_answer[2] = {-3E-4, 3E-4};
  assert(is_values_equal(result[0], correct_answer[0], local_epsilon) &&
         is_values_equal(correct_answer[1], result[1], local_epsilon));
}

void test_coefficient_1_m1e10_m1() {
  long double local_epsilon = 1e-11;
  long double *result = find_roots(1, -1E+10, -1, local_epsilon);
  long double correct_answer[2] = {-1E-10, 1E+10};
  assert(is_values_equal(result[0], correct_answer[0], local_epsilon) &&
         is_values_equal(correct_answer[1], result[1], local_epsilon));
}

void test_coefficient_1_0_m1em8() {
  long double local_epsilon = 1e-7;
  long double *result = find_roots(1, 0, -1E-8, local_epsilon);
  long double correct_answer[2] = {-1E-4, 1E-4};
  assert(is_values_equal(result[0], correct_answer[0], local_epsilon) &&
         is_values_equal(correct_answer[1], result[1], local_epsilon));
}

int main() {
  test_zero_coefficient_a();
  test_coefficient_1_0_m1();
  test_coefficient_1_0_0();
  test_coefficient_1_0_1();
  test_coefficient_1_0_m1em7();
  test_coefficient_1_m1e10_m1();
  test_coefficient_1_0_m1em8();
  return 0;
}
