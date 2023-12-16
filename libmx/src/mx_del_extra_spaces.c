#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL)
        return NULL;

    int new_string_length = 0;
    char *trimmed_string = mx_strtrim(str);

    if (trimmed_string == NULL)
        return NULL;
    else if (mx_strlen(trimmed_string) == 0)
        return trimmed_string;

    for (int i = 0; trimmed_string[i] != '\0'; i++) {
        if (mx_isprint(trimmed_string[i]) == 0)
            trimmed_string[i] = ' ';

        if (trimmed_string[i] != ' ' || trimmed_string[i - 1] != ' ')
            new_string_length++;
    }

    char *new_string = mx_strnew(new_string_length);

    if (new_string == NULL) {
        mx_strdel(&trimmed_string);
        return NULL;
    }

    int add_index = 0;

    for (int i = 0; trimmed_string[i] != '\0'; i++) {
        if (mx_isprint(trimmed_string[i]) == 0)
            trimmed_string[i] = ' ';

        if (trimmed_string[i] != ' ' || trimmed_string[i - 1] != ' ') {
            new_string[add_index] = trimmed_string[i];
            add_index++;
        }
    }

    new_string[add_index] = '\0';
    mx_strdel(&trimmed_string);
    return new_string;
}
