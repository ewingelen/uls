#include "uls.h"

void mx_print_file_bytes_size(struct stat *stat) {
    mx_printint(stat->st_size);
}
