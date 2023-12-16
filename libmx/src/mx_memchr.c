#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *new_pointer = (unsigned char *)s;

    for (size_t i = 0; i < n; i++) {
        if (new_pointer[i] == (unsigned char)c) {
            return new_pointer + i;
        }
    }

    return NULL;
}
