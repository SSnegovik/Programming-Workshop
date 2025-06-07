#include <stddef.h>

typedef struct {
  void *buffer;
  size_t size;
  size_t offset;
} LinearAllocator;

LinearAllocator *linear_allocator_create(size_t size);
void *linear_alloc(void *allocator, size_t size);
void linear_reset(void *allocator);