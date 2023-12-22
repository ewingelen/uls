#include "../inc/uls.h"

void mx_count_file(int *count_file, char *path) {
    int count = 0;
    DIR *dir_current = opendir(path);
    struct dirent *entry = NULL;
    while ((entry = readdir(dir_current)) != NULL) {
        if (entry->d_name[0] != '.')
            count++;
    }
    *count_file = count;
    closedir(dir_current);
}
