#include "../inc/libmx.h"

char *mx_replace_substr(const char *str,
                        const char *sub,
                        const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) {
        return NULL;
    }

    int substr_count = mx_count_substr(str, sub);
    int new_str_length = mx_strlen(str)
                         - substr_count * mx_strlen(sub)
                         + substr_count * mx_strlen(replace);
    char *new_str = mx_strnew(new_str_length);

    if (new_str == NULL) {
        return NULL;
    }

    int new_str_index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_strncmp(&str[i], sub, mx_strlen(sub)) == 0) {
            mx_strncpy(&new_str[new_str_index], replace, mx_strlen(replace));
            new_str_index += mx_strlen(replace);
            i += mx_strlen(sub) - 1;
        }
        else {
            new_str[new_str_index] = str[i];
            new_str_index++;
        }
    }

    return new_str;
}
