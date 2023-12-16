#include "../inc/libmx.h"

void mx_del_strmatrix(char ****matrix, int row_count) {
    if (matrix != NULL && *matrix != NULL) {
        for (int i = 0; i < row_count; i++) {
            if ((*matrix)[i] != NULL) {
                free((*matrix)[i]);
                (*matrix)[i] = NULL;
            }
        }

        free(*matrix);
        *matrix = NULL;
    }
}
