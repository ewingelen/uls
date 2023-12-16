#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    else if (s1 != NULL && s2 == NULL) {
        return mx_strdup(s1);
    }
    else if (s1 == NULL && s2 != NULL) {
        return mx_strdup(s2);
    }

    int first_str_length = mx_strlen(s1);
    int second_str_length = mx_strlen(s2);
    char *new_str = mx_strnew(first_str_length + second_str_length);

    if (new_str == NULL) {
        return NULL;
    }

    mx_strcpy(new_str, s1);
    char *result = mx_strcat(new_str, s2);
    mx_strdel(&new_str);
    return result;
}
