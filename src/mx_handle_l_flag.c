#include "../inc/uls.h"

void mx_handle_l_flag(char **path, int count_file, bool args_without_print) {
    struct stat file_stat;
    int arr_num_space[4] = {-1, -1, -1, -1};
    mx_space_need(path, count_file, arr_num_space);
    if (args_without_print)
        mx_print_total_block_count(path, count_file);
    for (int i = 0; i < count_file; i++) {
        mx_print_dirent_info(
                &file_stat,
                path[i],
                arr_num_space,
                args_without_print
        );
    }
}
