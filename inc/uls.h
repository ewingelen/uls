#ifndef ULS
#define ULS

#include <dirent.h>
#include <sys/stat.h>
//#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include "libmx.h"

bool mx_check_is_directory(char *path);

char **mx_get_d_names_alphabetically(char *path, int *dirent_count);

void mx_handle_l_flag(char *path);

void mx_print_access_rights(struct stat *stat);

void mx_print_dirent_info(struct stat *stat, char *d_name, mode_t st_mode);

void mx_print_dirent_type(mode_t mode);

void mx_print_dirents_info(char *path);

void mx_print_extra_attributes();

void mx_print_file_bytes_size(struct stat *stat);

void mx_print_group_owner(struct stat *stat);

void mx_print_hard_links_count(struct stat *stat);

void mx_print_modification_time(struct stat *stat);

void mx_print_owner(struct stat *stat);

void mx_print_total_block_count_if_directory(char *path);

#endif //ULS
