#include "../inc/uls.h"

void mx_print_dirents_info(char *path) {
    struct stat file_stat;
    int dirent_count = 0;
    char *dir_path_with_slash = mx_strcat(path, "/");
    char **d_names = mx_get_d_names_alphabetically(
            dir_path_with_slash,
            &dirent_count
    );
    char **file_path = (char **)malloc((dirent_count + 1) * sizeof(char *));
    for (int i = 0; i < dirent_count; i++)
        file_path[i] = mx_strcat(dir_path_with_slash, d_names[i]);
    file_path[dirent_count] = NULL;

    int arr_num_space[4] = {-1, -1, -1, -1};
    mx_space_need(file_path, dirent_count, arr_num_space);
    for (int i = 0; i < dirent_count; i++)
        mx_print_dirent_info(&file_stat, file_path[i], arr_num_space, true);

    mx_strdel(&dir_path_with_slash);
    mx_del_strarr(&d_names);
    mx_del_strarr(&file_path);
}
