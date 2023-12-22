#include "../inc/uls.h"

void mx_print_dirent_info(struct stat *file_stat,
                          char *path,
                          int *arr_num_space,
                          bool args_without_print) {
    if (lstat(path, file_stat) == 0) {
        mx_print_dirent_type(file_stat->st_mode);
        mx_print_access_rights(file_stat);
        mx_print_xattr_or_acl(path);
        mx_printchar(' ');
        mx_print_hard_links_count(file_stat, arr_num_space[0]);
        mx_printchar(' ');
        mx_print_owner(file_stat, arr_num_space[1]);
        mx_printchar(' ');
        mx_printchar(' ');
        mx_print_group_owner(file_stat, arr_num_space[2]);
        mx_printchar(' ');
        mx_printchar(' ');
        mx_print_file_size(file_stat, arr_num_space[3]);
        mx_printchar(' ');
        mx_print_modification_time(file_stat);
        mx_printchar(' ');
        mx_print_file_name(path, file_stat, args_without_print);
        mx_printchar('\n');
    }
}
