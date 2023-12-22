#include "../inc/uls.h"

void mx_print_file_size(struct stat *stat, int count) {
    if (S_ISCHR(stat->st_mode) || S_ISBLK(stat->st_mode)) {
        char *hex = mx_nbr_to_hex(stat->st_rdev);
        if (stat->st_rdev != 0) {
            for (int i = mx_strlen(hex) + mx_strlen("0x"); i < count; i++)
                mx_printchar(' ');
            mx_printstr("0x");
        }
        else {
            for (int i = mx_strlen(hex); i < count; i++)
                mx_printchar(' ');
        }
        mx_printstr(hex);
        mx_strdel(&hex);
    }
    else {
        for (int i = mx_strlen(mx_itoa(stat->st_size)); i < count; i++)
            mx_printchar(' ');
        mx_printlonglong(stat->st_size);
    }
}
