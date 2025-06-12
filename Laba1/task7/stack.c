#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void init_stack(Stack *stack, int size) {
  stack->size = size;
  stack->array = (int *)malloc(size * sizeof(int));
  stack->top = -1;
}

int is_empty(Stack *stack) { return stack->top == -1; }

int is_full(Stack *stack) { return stack->top == stack->size - 1; }

int push(Stack *stack, int value) {
  if (is_full(stack)) {
    return -1;
  } else {
    stack->array[++stack->top] = value;
    return 0;
  }
}

int pop(Stack *stack, int *out_value) {
  if (is_empty(stack)) {
    return -1;
  } else {
    *out_value = stack->array[stack->top--];
    return 0;
  }
}
