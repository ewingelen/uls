#include "../inc/uls.h"

void mx_check_with_files(int argc, char *argv[], bool flag_l) {
    struct stat path_stat;
    bool error = false;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' && stat(argv[i], &path_stat) == -1) {
            mx_print_error("uls: ");
            mx_print_error(argv[i]);
            mx_print_error(": ");
            mx_print_error(strerror(errno));
            error = true;
        }
    }
    int count_file = mx_arr_files(argc, argv, flag_l);
    mx_arr_dir(argc, argv, count_file, error, flag_l);
}
