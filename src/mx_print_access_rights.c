#include "uls.h"

void mx_print_access_rights(struct stat *stat) {
    char *read_right = "r";
    char *write_right = "w";
    char *execute_right = "x";
    char *no_rights = "-";

    mx_printstr((stat->st_mode & S_IRUSR) ? read_right : no_rights);
    mx_printstr((stat->st_mode & S_IWUSR) ? write_right : no_rights);
    mx_printstr((stat->st_mode & S_IXUSR) ? execute_right : no_rights);
    mx_printstr((stat->st_mode & S_IRGRP) ? read_right : no_rights);
    mx_printstr((stat->st_mode & S_IWGRP) ? write_right : no_rights);
    mx_printstr((stat->st_mode & S_IXGRP) ? execute_right : no_rights);
    mx_printstr((stat->st_mode & S_IROTH) ? read_right : no_rights);
    mx_printstr((stat->st_mode & S_IWOTH) ? write_right : no_rights);
    mx_printstr((stat->st_mode & S_IXOTH) ? execute_right : no_rights);
}
