#include "../inc/libmx.h"

void mx_del_strarr_without_content(char ***arr) {
    if (arr != NULL && *arr != NULL) {
        free(*arr);
        *arr = NULL;
    }
}
