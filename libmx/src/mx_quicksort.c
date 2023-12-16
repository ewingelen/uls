#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int swap_count = 0;
    int i;
    int j;
    int pivot;
    char *temp;

    if (arr == NULL)
        return -1;

    if (left < right) {
        pivot = (left + right) / 2;
        i = left;
        j = right;

        while (i <= j) {
            while (mx_strlen(arr[i]) < mx_strlen(arr[pivot])) {
                i++;
            }
            while (mx_strlen(arr[j]) > mx_strlen(arr[pivot])) {
                j--;
            }

            if (i <= j) {
                bool same_str_len = mx_strlen(arr[i]) == mx_strlen(arr[j]);
                if (i != j && !same_str_len) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    swap_count++;
                }
                i++;
                j--;
            }
        }

        swap_count += mx_quicksort(arr, left, j);
        swap_count += mx_quicksort(arr, i, right);
    }

    return swap_count;
}
