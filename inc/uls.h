#ifndef ULS
#define ULS

//#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <grp.h>
#include <sys/acl.h>
#include "libmx.h"

bool mx_check_is_directory(char *path);

char **mx_get_d_names_alphabetically(char *path, int *dirent_count);

void mx_handle_l_flag(char *path);

void mx_print_access_rights(struct stat *stat);

void mx_print_dirent_info(struct stat *file_stat, char *path);

void mx_print_dirent_type(mode_t mode);

void mx_print_dirents_info(char *path);

void mx_print_xattr_or_acl(char *path);

void mx_print_file_size(struct stat *stat);

void mx_print_file_name(char *path, struct stat *file_stat);

void mx_print_group_owner(struct stat *stat);

void mx_print_hard_links_count(struct stat *stat);

void mx_print_modification_time(struct stat *stat);

void mx_print_owner(struct stat *stat);

void mx_print_total_block_count_if_directory(char *path);

#endif //ULS
