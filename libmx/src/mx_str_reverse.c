#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    if (s == NULL) {
        return;
    }

    int string_length = mx_strlen(s);

    for (int i = 0; i < string_length / 2; i++) {
        char temp = s[i];
        s[i] = s[string_length - i - 1];
        s[string_length - i - 1] = temp;
    }
}
