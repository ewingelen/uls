#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int swap_count = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int compare_result = mx_strcmp(arr[j], arr[j + 1]);

            if (compare_result > 0) {
                char *temp = arr[j];

                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_count++;
            }
        }
    }

    return swap_count;
}
