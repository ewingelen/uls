#include "../inc/uls.h"

void mx_print_hard_links_count(struct stat *stat, int count) {
    for (int i = mx_strlen(mx_itoa(stat->st_nlink)); i < count; i++)
        mx_printchar(' ');
    mx_printint(stat->st_nlink);
}
