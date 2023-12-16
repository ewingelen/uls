#include "../inc/libmx.h"

int mx_atoi_positive(const char *str) {
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isdigit(str[i]))
            break;
        else
            result = result * 10 + (str[i] - '0');
    }

    return result;
}
