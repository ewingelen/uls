#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int first_string_length = mx_strlen(s1);
    int second_string_length = mx_strlen(s2);
    int total_strings_length = first_string_length + second_string_length;
    char *result = mx_strnew(total_strings_length);

    if (result == NULL) {
        return NULL;
    }

    int i;

    for (i = 0; i < first_string_length; i++) {
        result[i] = s1[i];
    }

    for (int j = 0; j < second_string_length; j++) {
        result[i + j] = s2[j];
    }

    result[i + second_string_length] = '\0';

    return result;
}
