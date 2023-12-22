#include "../inc/uls.h"

char **mx_read_dir(char **file_arr, int count_file, char *path) {
    struct dirent *entry = NULL;
    DIR *dir_current = opendir(path);
    file_arr = (char **)malloc(count_file * sizeof(char *));
    int i = 0;
    while ((entry = readdir(dir_current)) != NULL) {
        if (entry->d_name[0] != '.') {
            file_arr[i] = mx_strdup(entry->d_name);
            i++;
        }
    }
    closedir(dir_current);
    return file_arr;
}
