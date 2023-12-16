#include "../inc/libmx.h"

int **mx_dup_int_matrix(int **src, int rows, int columns) {
    int **matrix = malloc(sizeof(int *) * rows);

    for (int i = 0; i < rows; i++)
        matrix[i] = malloc(sizeof(int) * columns);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = src[i][j];

    return matrix;
}
