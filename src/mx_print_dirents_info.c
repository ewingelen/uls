#include "uls.h"

void mx_print_dirents_info(char *path) {
    struct stat file_stat;

    if (mx_check_is_directory(path)) {
        int dirent_count = 0;
        char **d_names = mx_get_d_names_alphabetically(path, &dirent_count);

        for (int i = 0; i < dirent_count; i++) {
            char *file_path = mx_strcat(path, d_names[i]);

            if (stat(file_path, &file_stat) == 0)
                mx_print_dirent_info(
                        &file_stat,
                        d_names[i],
                        file_stat.st_mode
                );

            mx_strdel(&file_path);
        }

        mx_del_strarr(&d_names);
    }
    else {
        //TODO: check this and file name
//        char **paths = mx_strsplit(path, '/');
//        char *file_name = paths[mx_arr_size(paths) - 1];
//
//        if (stat(file_name, &file_stat) == 0)
//            mx_print_dirent_info(&file_stat, file_name, file_stat.st_mode);
//        mx_del_strarr_without_content(&paths);
//        mx_strdel(&file_name);
    }
}
