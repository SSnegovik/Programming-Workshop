#include "destructor.h"

int main() {
  PoolAllocator allocator;
  pool_allocator_init(&allocator, 1024, 16);

  des_count *des = des_create(&allocator, 100, NULL);
  if (!des) {
    return 1;
  }

  des_increase(ref);
  des_decrease(&allocator, des);
  des_decrease(&allocator, des);

  pool_allocator_destroy(&allocator);

  return 0;
}