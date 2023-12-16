#include "../inc/libmx.h"

void mx_print_error(const char *s) {
    int string_length = mx_strlen(s);

    write(STDERR_FILENO, s, string_length);
}
