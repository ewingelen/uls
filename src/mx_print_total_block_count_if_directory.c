#include "uls.h"

void mx_print_total_block_count_if_directory(char *path) {
    if (!mx_check_is_directory(path))
        return;

    blkcnt_t total_blocks = 0;
    struct stat file_stat;
    int dirent_count = 0;
    char **d_names = mx_get_d_names_alphabetically(path, &dirent_count);

    for (int i = 0; i < dirent_count; i++) {
        char *file_path = mx_strcat(path, d_names[i]);

        if (stat(file_path, &file_stat) == 0)
            total_blocks += file_stat.st_blocks;

        mx_strdel(&file_path);
    }

    mx_del_strarr(&d_names);
    mx_printstr("total: ");
    mx_printint(total_blocks);
    mx_printstr("\n");
}
