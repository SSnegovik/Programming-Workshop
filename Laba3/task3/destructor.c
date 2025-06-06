#include "destructor.h"
#include <stdlib.h>
#include <string.h>

des_count *des_create(PoolAllocator *allocator, size_t size,
                      destructor_fn dtor) {
  des_count *des = (des_count *)pool_alloc(allocator, sizeof(des_count));
  if (!des)
    return NULL;

  des->object = pool_alloc(allocator, size);
  if (!des->object) {
    pool_free(allocator, des);
    return NULL;
  }

  des->count = 1;
  des->dtor = dtor;
  return des;
}

void des_increase(des_count *des) {
  if (des) {
    des->count++;
  }
}

void des_decrease(PoolAllocator *allocator, des_count *des) {
  if (!des)
    return;

  des->count--;
  if (des->count == 0) {
    if (des->dtor) {
      des->dtor(des->object);
    }
    pool_free(allocator, des->object);
    pool_free(allocator, des);
  }
}