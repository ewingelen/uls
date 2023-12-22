#include "../inc/uls.h"

char **mx_get_d_names_alphabetically(char *path, int *dirent_count) {
    char **names = NULL;
    struct dirent *entry;
    DIR *dir = opendir(path);

    while ((entry = readdir(dir)) != NULL) {
        if (mx_get_char_index(entry->d_name, '.') != 0) {
            names = mx_realloc(names, sizeof(char *) * (*dirent_count + 1));
            names[*dirent_count] = mx_strdup(entry->d_name);
            (*dirent_count)++;
        }
    }

    names = mx_realloc(names, sizeof(char *) * (*dirent_count + 1));
    names[*dirent_count] = NULL;
    closedir(dir);
    mx_bubble_sort(names, *dirent_count);
    return names;
}
