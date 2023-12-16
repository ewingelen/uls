#include "../inc/libmx.h"

int mx_arr_size(char **arr) {
    if (arr == NULL || *arr == NULL)
        return -1;

    int len = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        len++;
    }

    return len;
}
