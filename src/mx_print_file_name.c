#include "uls.h"

void mx_print_file_name(char *path, struct stat *file_stat) {
    char **file_names = mx_strsplit(path, '/');
    char *file_name = file_names[mx_arr_size(file_names) - 1];
    mx_printstr(file_name);
    mx_del_strarr(&file_names);

    if ((file_stat->st_mode & S_IFMT) == S_IFLNK) {
        char buf[PATH_MAX];
        ssize_t len = readlink(path, buf, sizeof(buf) - 1);

        if (len != -1) {
            buf[len] = '\0';
            mx_printstr(" -> ");
            mx_printstr(buf);
        }
    }
}
