#include "../inc/uls.h"

void mx_print_owner(struct stat *stat, int count) {
    struct passwd *pw = getpwuid(stat->st_uid);

    if (pw != 0) {
        mx_printstr(pw->pw_name);
        for (int i = mx_strlen(pw->pw_name); i < count; i++)
            mx_printchar(' ');
    }
    else {
        mx_printlonglong(stat->st_uid);
        for (int i = mx_strlen(mx_itoa(stat->st_uid)); i < count; i++)
            mx_printchar(' ');
    }
}
