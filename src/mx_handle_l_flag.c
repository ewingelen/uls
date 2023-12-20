#include "uls.h"

void mx_handle_l_flag(char *path) {
    mx_print_total_block_count_if_directory(path);
    mx_print_dirents_info(path);
}
