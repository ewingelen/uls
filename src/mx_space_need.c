#include "../inc/uls.h"

void mx_space_need(char **path, int count_file, int *arr_num_space) {
    struct stat file_stat;
    for (int i = 0; i < count_file; i++) {
        stat(path[i], &file_stat);
        struct passwd *pw = getpwuid(file_stat.st_uid);
        struct group *gr = getgrgid(file_stat.st_gid);
        if (arr_num_space[0] < mx_strlen(mx_itoa(file_stat.st_nlink)))
            arr_num_space[0] = mx_strlen(mx_itoa(file_stat.st_nlink));

        if (pw != 0) {
            if (arr_num_space[1] < mx_strlen(pw->pw_name))
                arr_num_space[1] = mx_strlen(pw->pw_name);
        }
        else {
            if (arr_num_space[1] < mx_strlen(mx_itoa(file_stat.st_uid)))
                arr_num_space[1] = mx_strlen(mx_itoa(file_stat.st_uid));
        }

        if (gr != 0) {
            if (arr_num_space[2] < mx_strlen(gr->gr_name))
                arr_num_space[2] = mx_strlen(gr->gr_name);
        }
        else {
            if (arr_num_space[2] < mx_strlen(mx_itoa(file_stat.st_gid)))
                arr_num_space[2] = mx_strlen(mx_itoa(file_stat.st_gid));
        }

        if (S_ISCHR(file_stat.st_mode) || S_ISBLK(file_stat.st_mode)) {
            char *hex = mx_nbr_to_hex(file_stat.st_rdev);
            if (file_stat.st_rdev != 0) {
                if (arr_num_space[3] < mx_strlen("0x") + mx_strlen(hex))
                    arr_num_space[3] = mx_strlen("0x") + mx_strlen(hex);
            }
            if (arr_num_space[3] < mx_strlen(hex))
                arr_num_space[3] = mx_strlen(hex);
            mx_strdel(&hex);
        }
        else {
            if (arr_num_space[3] < mx_strlen(mx_itoa(file_stat.st_size)))
                arr_num_space[3] = mx_strlen(mx_itoa(file_stat.st_size));
        }

    }
}
