#include "pool_allocator.h"
#include <stddef.h>

typedef void (*destructor_fn)(void *);

typedef struct {
  size_t count;
  void *object;
  destructor_fn dtor;
} des_count;

ref_count_ext_t *ref_create_ext(PoolAllocator *allocator, size_t size,
                                destructor_fn dtor);

void des_increase(des_count *des);

void des_decrease(PoolAllocator *allocator, des_count *des);
}