#include "../inc/libmx.h"

void mx_del_intmatrix(int ***matrix, int rows) {
    if (matrix != NULL && *matrix != NULL) {
        for (int i = 0; i < rows; i++) {
            free((*matrix)[i]);
            (*matrix)[i] = NULL;
        }

        free(*matrix);
        *matrix = NULL;
    }
}
