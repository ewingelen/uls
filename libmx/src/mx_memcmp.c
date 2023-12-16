#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *new_s1_pointer = (unsigned char *)s1;
    unsigned char *new_s2_pointer = (unsigned char *)s2;

    for (size_t i = 0; i < n; i++) {
        if (*new_s1_pointer != *new_s2_pointer) {
            return *new_s1_pointer - *new_s2_pointer;
        }
        new_s1_pointer++;
        new_s2_pointer++;
    }

    return 0;
}
