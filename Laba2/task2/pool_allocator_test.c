#include "pool_allocator.h"
#include <assert.h>
#include <stdio.h>

int main() {
  PoolAllocator *allocator = pool_allocator_create(64, 25);
  assert(allocator != NULL);

  void *blocks[10];

  for (int i = 0; i < 25; ++i) {
    blocks[i] = pool_alloc(allocator);
    assert(blocks[i] != NULL);
  }

  assert(pool_alloc(allocator) == NULL);

  pool_free(allocator, blocks[12]);
  pool_free(allocator, blocks[13]);

  assert(pool_alloc(allocator) != NULL);
  assert(pool_alloc(allocator) != NULL);
  assert(pool_alloc(allocator) == NULL);

  pool_allocator_destroy(allocator);

  return 0;
}
