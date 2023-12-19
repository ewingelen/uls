#include "uls.h"

//TODO: implement
void mx_print_modification_time(struct stat *stat) {
    struct stat *stat_copy = stat;
    mx_printint(stat_copy->st_size);
//    if (lstat(path, stat_copy) == 0)
//        mx_printstr(stat->st_mtimespec);

//    struct timespec mx_take_time_info(struct stat *stat, t_time time_type) {
//        if (time_type == MOD) {
//            return stat->st_mtimespec;
//        } else if (time_type == STAT) {
//            return stat->st_ctimespec;
//        } else if (time_type == ACC) {
//            return stat->st_atimespec;
//        } else if (time_type == CREATE) {
//            return stat->st_birthtimespec;
//        }
//        return stat->st_mtimespec;
//    }
}
