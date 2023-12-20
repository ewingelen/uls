#include "uls.h"

void mx_print_dirents_info(char *path) {
    struct stat file_stat;

    if (mx_check_is_directory(path)) {
        int dirent_count = 0;
        char *dir_path_with_slash = mx_strcat(path, "/");
        char **d_names = mx_get_d_names_alphabetically(
                dir_path_with_slash,
                &dirent_count
        );

        for (int i = 0; i < dirent_count; i++) {
            char *file_path = mx_strcat(dir_path_with_slash, d_names[i]);

            mx_print_dirent_info(&file_stat, file_path);
            mx_strdel(&file_path);
        }

        mx_strdel(&dir_path_with_slash);
        mx_del_strarr(&d_names);
    }
    else {
        mx_print_dirent_info(&file_stat, path);
    }
}
