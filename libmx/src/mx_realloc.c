#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL || size == 0) {
        if (size == 0) {
            free(ptr);
        }
        return malloc(size);
    }

    size_t cur_size = malloc_size(ptr);
    if (size <= cur_size) {
        return ptr;
    }

    void *new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }

    size_t copy_size = (size < cur_size) ? size : cur_size;
    mx_memcpy(new_ptr, ptr, copy_size);
    free(ptr);

    return new_ptr;
}
