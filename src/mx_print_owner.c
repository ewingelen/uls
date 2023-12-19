#include "uls.h"

void mx_print_owner(struct stat *stat) {
    struct passwd *pw = getpwuid(stat->st_uid);

    if (pw != 0)
        mx_printstr(pw->pw_name);
}
