#include "uls.h"

void mx_handle_l_flag(char *path) {
    char *dir_path_with_slash = mx_strcat(path, "/");

    mx_print_total_block_count_if_directory(dir_path_with_slash);
    mx_print_dirents_info(dir_path_with_slash);

    mx_strdel(&dir_path_with_slash);
}
