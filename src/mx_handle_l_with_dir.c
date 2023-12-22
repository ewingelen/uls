#include "../inc/uls.h"

void mx_handle_l_with_dir(char **path, int count_dir, int count_file) {
    for (int i = 0; i < count_dir; i++) {
        if (i != 0 || count_file > 0)
            mx_printchar('\n');
        if (count_dir > 1) {
            mx_printstr(path[i]);
            mx_printstr(":\n");
        }
        mx_print_total_block_count_if_directory(path[i]);
        mx_print_dirents_info(path[i]);
    }
}
