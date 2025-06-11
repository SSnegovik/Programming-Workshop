#include "linear_allocator.h"
#include <assert.h>
#include <stdlib.h>

int main() {
  LinearAllocator *allocator = linear_allocator_create(256);
  assert(allocator != NULL);
  assert(allocator->buffer != NULL);
  assert(allocator->size == 256);
  assert(allocator->offset == 0);

  void *ptr1 = linear_alloc(allocator, 128);
  assert(ptr1 != NULL);
  assert(allocator->offset == 128);

  void *ptr2 = linear_alloc(allocator, 128);
  assert(ptr2 != NULL);
  assert(allocator->offset == 256);

  void *ptr3 = linear_alloc(allocator, 256);
  assert(ptr3 == NULL);

  linear_reset(allocator);

  return 0;
}
