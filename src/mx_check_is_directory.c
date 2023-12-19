#include "uls.h"

bool mx_check_is_directory(char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}
