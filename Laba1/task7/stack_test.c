#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_initStack() {
  Stack stack;
  init_stack(&stack, 50);
  assert(stack.top == -1);
}

void test_push() {
  Stack stack;
  init_stack(&stack, 10);

  push(&stack, 20);
  assert(stack.top == 0);
  assert(stack.array[stack.top] == 20);

  push(&stack, 40);
  assert(stack.top == 1);
  assert(stack.array[stack.top] == 40);

  push(&stack, 60);
  assert(stack.top == 2);
  assert(stack.array[stack.top] == 60);
}

void test_pop() {
  Stack stack;
  init_stack(&stack, 10);

  push(&stack, 20);
  push(&stack, 40);
  push(&stack, 60);

  int value;

  assert(pop(&stack) == 60);
  assert(value == 60);
  assert(stack.top == 1);

  assert(pop(&stack) == 40);
  assert(value == 40);
  assert(stack.top == 0);

  assert(pop(&stack) == 20);
  assert(value == 20);
  assert(stack.top == -1);
}

void test_push_after_pop() {
  Stack stack;
  init_stack(&stack, 10);

  push(&stack, 20);
  push(&stack, 40);

  int temp;
  pop(&stack, &temp);

  push(&stack, 80);
  assert(stack.top == 1);
  assert(stack.array[stack.top] == 80);

  push(&stack, 100);
  assert(stack.top == 2);
  assert(stack.array[stack.top] == 100);

  push(&stack, 120);
  assert(stack.top == 3);
  assert(stack.array[stack.top] == 120);
}

int main() {
  test_initStack();
  test_push();
  test_pop();
  test_push_after_pop();
  return 0;
}
