#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    char *string = malloc(size + 1);

    if (size < 0) {
        return NULL;
    }

    if (string != NULL) {
        for (int i = 0; i <= size; i++) {
            string[i] = '\0';
        }
    }

    return string;
}
