#include "../inc/uls.h"

int mx_arr_files(int count_present_files, char **file_present, bool flag_l) {
    struct stat path_stat;
    char **file = NULL;
    int count_file = 0;
    int j = 0;
    for (int i = 1; i < count_present_files; i++) {
        stat(file_present[i], &path_stat);
        if (file_present[i][0] != '-' &&
            stat(file_present[i], &path_stat) != -1
            && !S_ISDIR(path_stat.st_mode))
            count_file++;
    }
    if (count_file > 0) {
        file = (char **)malloc(count_file * sizeof(char *));
        for (int i = 1; i < count_present_files; i++) {
            stat(file_present[i], &path_stat);
            if (file_present[i][0] != '-' &&
                stat(file_present[i], &path_stat) != -1
                && !S_ISDIR(path_stat.st_mode)) {
                file[j] = file_present[i];
                j++;
            }
        }
        if (flag_l) {
            mx_sort(count_file, file);
            mx_handle_l_flag(file, count_file, false);
        }
        else {
            mx_print_file(file, count_file);
        }
        free(file);
    }
    return count_file;
}
