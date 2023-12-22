#include "../inc/uls.h"

void mx_print_modification_time(struct stat *stat) {
    char *full_time_str = ctime(&stat->st_mtime);
    char **full_time_arr = mx_strsplit(full_time_str, ' ');
    char *month = full_time_arr[1];
    char *day = full_time_arr[2];
    time_t current_time = time(NULL);
    time_t half_year_in_seconds = (365 / 2) * 24 * 60 * 60;

    mx_printstr(month);
    mx_printchar(' ');
    if (mx_strlen(day) == 1)
	mx_printchar(' ');
    mx_printstr(day);
    mx_printchar(' ');

    if (stat->st_mtime + half_year_in_seconds <= current_time
        || stat->st_mtime >= current_time + half_year_in_seconds) {
        char *year = full_time_arr[4];
        int new_line_index = mx_get_char_index(year, '\n');
        year[new_line_index] = '\0';
        mx_printchar(' ');
        mx_printstr(year);
    }
    else {
        char *time_str = full_time_arr[3];
        char **time_arr = mx_strsplit(time_str, ':');
        char *hour = time_arr[0];
        char *minute = time_arr[1];

        mx_printstr(hour);
        mx_printchar(':');
        mx_printstr(minute);
        mx_del_strarr(&time_arr);
    }

    mx_del_strarr(&full_time_arr);
}
