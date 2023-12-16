#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, size_t n) {
    while (n > 0) {
        if (*s1 == '\0' && *s2 == '\0') {
            return 0;
        }

        if (*s1 != *s2) {
            return *s1 - *s2;
        }

        s1++;
        s2++;
        n--;
    }

    return 0;
}
