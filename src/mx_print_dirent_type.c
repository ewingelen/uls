#include "uls.h"

void mx_print_dirent_type(mode_t mode) {
    switch (mode & S_IFMT) {
        case S_IFDIR:
            mx_printchar('d');
            break;
        case S_IFBLK:
            mx_printchar('b');
            break;
        case S_IFCHR:
            mx_printchar('c');
            break;
        case S_IFIFO:
            mx_printchar('p');
            break;
        case S_IFLNK:
            mx_printchar('l');
            break;
        case S_IFSOCK:
            mx_printchar('s');
            break;
        default:
            mx_printchar('-');
    }
}
