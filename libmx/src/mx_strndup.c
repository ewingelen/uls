#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t str_len = mx_strlen(s1);
    if (str_len < n)
        n = str_len;

    char *string_duplicate = mx_strnew(n);

    if (string_duplicate != NULL) {
        mx_strncpy(string_duplicate, s1, n);
    }

    return string_duplicate;
}
