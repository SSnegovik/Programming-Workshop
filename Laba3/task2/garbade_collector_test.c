#include <stdio.h>
#include "garbage_collector.h"

int main() {
    ref_count_t *ref = ref_create(sizeof(int));
    if (!ref) {
        return 1;
    }

    *(int *)ref->object = 123;

    ref_inc(ref);
    ref_dec(ref);
    ref_dec(ref);

    return 0;
}