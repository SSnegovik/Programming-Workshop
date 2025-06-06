#include "garbage_collector.h"

int main() {
  ref_count_t *ref = ref_create(sizeof(int));
  if (!ref)
    return 1;

  *(int *)ref->object = 123;

  if (*(int *)ref->object != 123)
    return 2;

  if (ref->count != 1)
    return 3;

  ref_inc(ref);
  if (ref->count != 2)
    return 4;

  ref_dec(ref);
  if (ref->count != 1)
    return 5;

  ref_dec(ref);

  return 0;
}