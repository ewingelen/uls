#include "../inc/libmx.h"

bool mx_str_only_digit(const char *str) {
    for (int i = 0; i < mx_strlen(str); i++) {
        char current_symbol = str[i];

        if (!mx_isdigit(current_symbol)) {
            return false;
        }
    }

    return true;
}
