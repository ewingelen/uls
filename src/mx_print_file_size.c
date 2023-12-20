#include "uls.h"

void mx_print_file_size(struct stat *stat) {
    if (S_ISCHR(stat->st_mode) || S_ISBLK(stat->st_mode)) {
        if (stat->st_rdev != 0) {
            mx_printstr("0x");
        }

        char *hex = mx_nbr_to_hex(stat->st_rdev);
        mx_printstr(hex);
        mx_strdel(&hex);
    }
    else {
        mx_printlonglong(stat->st_size);
    }
}
