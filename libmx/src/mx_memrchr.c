#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *new_pointer = (unsigned char *)s;

    for (size_t i = n; i > 0; i--) {
        if (new_pointer[i - 1] == (unsigned char)c) {
            return new_pointer + i - 1;
        }
    }

    return NULL;
}
