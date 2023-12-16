#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL)
        return NULL;

    int start_trim_end = 0;
    int end_trim_start = mx_strlen(str);

    while (str[start_trim_end] == ' '
           || mx_isprint(str[start_trim_end]) == 0)
        start_trim_end++;

    while (str[end_trim_start - 1] == ' '
           || mx_isprint(str[end_trim_start - 1]) == 0)
        end_trim_start--;

    int new_string_length = end_trim_start - start_trim_end;
    if (new_string_length <= 0) {
        return mx_strnew(0);
    }

    char *new_string = mx_strnew(end_trim_start - start_trim_end);
    if (new_string == NULL)
        return NULL;

    int index = 0;
    for (int i = start_trim_end; i < end_trim_start; i++) {
        new_string[index] = str[i];
        index++;
    }

    new_string[index] = '\0';
    return new_string;
}
