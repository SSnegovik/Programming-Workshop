#include "linear_allocator.h"
#include <stdlib.h>

LinearAllocator *linear_allocator_create(size_t size) {
  LinearAllocator *allocator = malloc(sizeof(LinearAllocator));
  if (!allocator) {
    return NULL;
  }

  allocator->buffer = malloc(size);
  if (!allocator->buffer) {
    free(allocator);
    return NULL;
  }

  allocator->size = size;
  allocator->offset = 0;
  return allocator;
}

void *linear_alloc(void *allocator, size_t size) {
  LinearAllocator *la = (LinearAllocator *)allocator;

  if (la->offset + size > la->size) {
    return NULL;
  }

  void *ptr = (char *)la->buffer + la->offset;
  la->offset += size;
  return ptr;
}
void linear_reset(void *allocator) {
  LinearAllocator *la = (LinearAllocator *)allocator;
  if (la) {
    free(la->buffer);
    free(la);
  }
}