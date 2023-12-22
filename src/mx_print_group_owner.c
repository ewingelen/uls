#include "../inc/uls.h"

void mx_print_group_owner(struct stat *stat, int count) {
    struct group *gr = getgrgid(stat->st_gid);

    if (gr != 0) {
        mx_printstr(gr->gr_name);
        for (int i = mx_strlen(gr->gr_name); i < count; i++)
            mx_printchar(' ');
    }
    else {
        mx_printlonglong(stat->st_gid);
        for (int i = mx_strlen(mx_itoa(stat->st_gid)); i < count; i++)
            mx_printchar(' ');
    }
}
