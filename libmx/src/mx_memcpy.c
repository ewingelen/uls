#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *new_dst_pointer = (unsigned char *)dst;
    unsigned char *new_src_pointer = (unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        new_dst_pointer[i] = new_src_pointer[i];
    }

    return dst;
}
