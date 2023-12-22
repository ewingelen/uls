#include "../inc/uls.h"

void mx_sort(int size, char *arr[size]) {
    bool sort = true;
    while (sort) {
        sort = false;
        for (int i = 1; i < size; i++) {
            if (mx_strcmp(arr[i], arr[i - 1]) < 0) {
                char *tmp;
                tmp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = tmp;
                sort = true;
            }
        }
    }
}
