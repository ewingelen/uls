#include "../inc/libmx.h"

void *mx_memmem(const void *big,
                size_t big_len,
                const void *little,
                size_t little_len) {
    if (big == NULL
        || little == NULL
        || little_len == 0 ||
        big_len < little_len) {
        return NULL;
    }

    const unsigned char *new_big_pointer = (const unsigned char *)big;
    const unsigned char *new_little_pointer = (const unsigned char *)little;

    for (size_t i = 0; i <= big_len - little_len; i++) {
        if (mx_memcmp(new_big_pointer + i,
                      new_little_pointer,
                      little_len) == 0) {
            return (void *)(new_big_pointer + i);
        }
    }

    return NULL;
}
