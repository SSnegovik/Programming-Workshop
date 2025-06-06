#include "garbage_collector.h"
#include "pool_allocator.h"
#include <stdio.h>

ref_count_t *ref_create(size_t size) {
    ref_count_t *ref = (ref_count_t *)pool_alloc(sizeof(ref_count_t));
    if (!ref) return NULL;

    ref->object = pool_alloc(size);
    if (!ref->object) {
        pool_free(ref);
        return NULL;
    }

    ref->count = 1;
    return ref;
}

void ref_inc(ref_count_t *ref) {
    if (ref) {
        ref->count++;
    }
}

void ref_dec(ref_count_t *ref) {
    if (!ref) return;

    if (ref->count == 0) {
               return;
    }

    ref->count--;

    if (ref->count == 0) {
        pool_free(ref->object);
        pool_free(ref);
    }
}