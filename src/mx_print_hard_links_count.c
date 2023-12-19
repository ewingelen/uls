#include "uls.h"

void mx_print_hard_links_count(struct stat *stat) {
    mx_printint(stat->st_nlink);
}
