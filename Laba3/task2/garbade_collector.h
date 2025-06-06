#include <stddef.h>

typedef struct {
  size_t count;
  void *object;
} ref_count_t;

ref_count_t *ref_create(size_t size);
void ref_inc(ref_count_t *ref);
void ref_dec(ref_count_t *ref);