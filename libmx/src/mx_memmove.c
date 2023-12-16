#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *new_dst_pointer = (unsigned char *)dst;
    unsigned char *new_src_pointer = (unsigned char *)src;

    if (new_dst_pointer == new_src_pointer) {
        return dst;
    }
    else if (new_dst_pointer < new_src_pointer) {
        for (size_t i = 0; i < len; i++) {
            new_dst_pointer[i] = new_src_pointer[i];
        }
    }
    else {
        for (size_t i = len; i > 0; i--) {
            new_dst_pointer[i - 1] = new_src_pointer[i - 1];
        }
    }

    return dst;
}
