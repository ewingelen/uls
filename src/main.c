#include "../inc/uls.h"

int main(int argc, char *argv[]) {
    int count_file = 0;
    char **files_arr_start = NULL;
    bool files = false;
    bool long_print = false;
    for (int i = 1; i < argc; i++) {
        if (mx_strcmp(argv[i], "-l") == 0)
            long_print = true;
        if (argv[i][0] != '-')
            files = true;
    }
    if (long_print == false && files == true) {
        mx_check_with_files(argc, argv, long_print);
    }
    if (long_print == false && files == false) {
        mx_count_file(&count_file, ".");
        files_arr_start = mx_read_dir(files_arr_start, count_file, ".");
        mx_print_file(files_arr_start, count_file);
    }
    if (long_print == true && files == false) {
        mx_count_file(&count_file, ".");
        files_arr_start = mx_read_dir(files_arr_start, count_file, ".");
        mx_sort(count_file, files_arr_start);
        mx_handle_l_flag(files_arr_start, count_file, true);
    }
    if (long_print == true && files == true) {
        mx_check_with_files(argc, argv, long_print);
    }
    for (int i = 0; i < count_file; i++)
        free(files_arr_start[i]);
    free(files_arr_start);
}
