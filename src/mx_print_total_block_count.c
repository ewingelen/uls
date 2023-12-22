#include "../inc/uls.h"

void mx_print_total_block_count(char **path, int count_file) {
    blkcnt_t total_blocks = 0;
    struct stat file_stat;

    for (int i = 0; i < count_file; i++) {
        if (stat(path[i], &file_stat) == 0)
            total_blocks += file_stat.st_blocks;
    }

    mx_printstr("total ");
    mx_printlonglong(total_blocks);
    mx_printstr("\n");
}
