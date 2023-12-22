#include "../inc/uls.h"

void mx_arr_dir(int count_present_files,
                char **file_present,
                int count_file,
                bool error,
                bool flag_l) {
    char **dir = NULL;
    int count_dir = 0;
    struct stat path_stat;
    int j = 0;
    for (int i = 1; i < count_present_files; i++) {
        stat(file_present[i], &path_stat);
        if (file_present[i][0] != '-' &&
            stat(file_present[i], &path_stat) != -1
            && S_ISDIR(path_stat.st_mode))
            count_dir++;
    }
    if (count_dir > 0) {
        dir = (char **)malloc(count_dir * sizeof(char *));
        for (int i = 1; i < count_present_files; i++) {
            stat(file_present[i], &path_stat);
            if (file_present[i][0] != '-' &&
                stat(file_present[i], &path_stat) != -1
                && S_ISDIR(path_stat.st_mode)) {
                dir[j] = file_present[i];
                j++;
            }
        }
        if (flag_l) {
            mx_sort(count_dir, dir);
            mx_handle_l_with_dir(dir, count_dir, count_file);
        }
        else {
            mx_print_dir(dir, count_dir, count_file, error);
        }
        free(dir);
    }
}
