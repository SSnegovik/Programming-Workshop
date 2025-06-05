#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int *array;
  int top;
} Stack;

void init_stack(Stack *stack, int size);

int is_empty(Stack *stack);

int is_full(Stack *stack);

void push(Stack *stack, int value);

int pop(Stack *stack);