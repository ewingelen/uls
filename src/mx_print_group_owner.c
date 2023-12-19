#include "uls.h"

void mx_print_group_owner(struct stat *stat) {
    struct group *gr = getgrgid(stat->st_gid);

    if (gr != 0)
        mx_printstr(gr->gr_name);
}
