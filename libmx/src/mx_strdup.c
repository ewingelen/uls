#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    int string_length = mx_strlen(s1);
    char *string_duplicate = mx_strnew(string_length);

    if (string_duplicate != NULL) {
        mx_strcpy(string_duplicate, s1);
    }

    return string_duplicate;
}
