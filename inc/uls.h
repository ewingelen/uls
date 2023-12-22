#ifndef ULS
#define ULS

#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <grp.h>
#include <sys/acl.h>
#include <string.h>
#include <errno.h>
#include "../libmx/inc/libmx.h"

bool mx_check_is_directory(char *path);

char **mx_get_d_names_alphabetically(char *path, int *dirent_count);

void mx_handle_l_flag(char **path, int count_file, bool args_without_print);

void mx_print_access_rights(struct stat *stat);

void mx_print_dirent_info(struct stat *file_stat,
                          char *path,
                          int *arr_num_space,
                          bool args_without_print);

void mx_print_dirent_type(mode_t mode);

void mx_print_dirents_info(char *path);

void mx_print_xattr_or_acl(char *path);

void mx_print_file_size(struct stat *stat, int count);

void mx_print_file_name(char *path,
                        struct stat *file_stat,
                        bool args_without_print);

void mx_print_group_owner(struct stat *stat, int count);

void mx_print_hard_links_count(struct stat *stat, int count);

void mx_print_modification_time(struct stat *stat);

void mx_print_owner(struct stat *stat, int count);

void mx_print_total_block_count_if_directory(char *path);

void mx_handle_l_with_dir(char **path, int count_dir, int count_file);

void mx_space_need(char **path, int count_file, int *arr_num_space);

void mx_print_total_block_count(char **path, int count_file);

void mx_sort(int size, char *arr[size]);

void mx_count_file(int *count_file, char *path);

char **mx_read_dir(char **file_arr, int count_file, char *path);

void mx_print_file(char **file_arr, int count_file);

void mx_print_dir(char **dir, int count_dir, int count_file, bool error);

void mx_check_with_files(int argc, char *argv[], bool flag_l);

int mx_arr_files(int count_present_files, char **file_present, bool flag_l);

void mx_arr_dir(int count_present_files,
                char **file_present,
                int count_file,
                bool error,
                bool flag_l);

void mx_handle_l_with_dir(char **path, int count_dir, int count_file);

void mx_space_need(char **path, int count_file, int *arr_num_space);

void mx_print_total_block_count(char **path, int count_file);

#endif //ULS
