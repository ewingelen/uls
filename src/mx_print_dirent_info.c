#include "uls.h"

void mx_print_dirent_info(struct stat *file_stat, char *path) {
    //TODO: implement correct spaces
    if (lstat(path, file_stat) == 0) {
        mx_print_dirent_type(file_stat->st_mode);
        mx_print_access_rights(file_stat);
        mx_print_xattr_or_acl(path);
        mx_printchar(' ');
        mx_print_hard_links_count(file_stat);
        mx_printchar(' ');
        mx_print_owner(file_stat);
        mx_printchar(' ');
        mx_print_group_owner(file_stat);
        mx_printchar(' ');
        mx_print_file_size(file_stat);
        mx_printchar(' ');
        mx_print_modification_time(file_stat);
        mx_printchar(' ');
        mx_print_file_name(path, file_stat);
        mx_printchar('\n');
    }
}
