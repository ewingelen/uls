#include "uls.h"

void mx_print_dirent_info(struct stat *stat, char *d_name, mode_t st_mode) {
    //TODO: handle spaces
    mx_print_dirent_type(st_mode);
    mx_print_access_rights(stat);
    mx_print_extra_attributes();
    mx_printchar(' ');
    mx_print_hard_links_count(stat);
    mx_printchar(' ');
    mx_print_owner(stat);
    mx_printchar(' ');
    mx_print_group_owner(stat);
    mx_printchar(' ');
    mx_print_file_bytes_size(stat);
    mx_printchar(' ');
    mx_print_modification_time(stat);
    mx_printchar(' ');
    mx_printstr(d_name);
    mx_printchar('\n');
}
