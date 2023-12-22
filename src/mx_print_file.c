#include "../inc/uls.h"

void mx_print_file(char **file_arr, int count_file) {
    int i;
    mx_sort(count_file, file_arr);
    if (isatty(1)) {
        for (i = 0; i + 1 < count_file; i++) {
            mx_printstr(file_arr[i]);
            mx_printstr("  ");
        }
        if (count_file > 0) {
            mx_printstr(file_arr[i]);
        }
        mx_printchar('\n');
    }
    else {
        for (i = 0; i < count_file; i++) {
            mx_printstr(file_arr[i]);
            mx_printchar('\n');
        }
    }
}
