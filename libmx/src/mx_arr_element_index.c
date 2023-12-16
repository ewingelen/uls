#include "../inc/libmx.h"

int mx_arr_element_index(char **arr, const char *element) {
    int arr_size = mx_arr_size(arr);

    if (arr_size == -1)
        return -1;

    for (int i = 0; arr[i] != NULL; i++) {
        if (mx_strcmp(arr[i], element) == 0) {
            return i;
        }
    }

    return -1;
}
