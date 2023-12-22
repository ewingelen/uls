#include "../inc/uls.h"

void mx_print_dir(char **dir, int count_dir, int count_file, bool error) {
    mx_sort(count_dir, dir);
    bool full_print = false;
    if (count_file > 0 || count_dir > 1 || error == true)
        full_print = true;
    if (full_print && count_file > 0)
        mx_printstr("\n");
    for (int i = 0; i < count_dir; i++) {
        char **files_arr = NULL;
        int count_dir_file = 0;
        if (full_print) {
            mx_printstr(dir[i]);
            mx_printstr(":");
        }
        mx_count_file(&count_dir_file, dir[i]);
        if (count_dir_file > 0 && full_print)
            mx_printstr("\n");
        files_arr = mx_read_dir(files_arr, count_dir_file, dir[i]);
        mx_print_file(files_arr, count_dir_file);
        if (i + 1 != count_dir)
            mx_printstr("\n");
        for (int i = 0; i < count_dir_file; i++)
            free(files_arr[i]);
        free(files_arr);
    }
}
