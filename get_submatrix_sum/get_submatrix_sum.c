/*
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>

long get_submatrix_sum_v1 (int row, int col, int x1, int y1,
                           int x2, int y2, int[][] matrix)
{
    int i, j;
    long sum;

    if ((row <= 0) || (col <= 0)) {
        return(LONG_MIN);
    }

    if ((x1 >= row) || (x2 >= row) || (x1 > x2)) {
        return(LONG_MIN);
    }

    if ((y1 >= col) || (y2 >= col) || (y1 > y2)) {
        return(LONG_MIN);
    }

    sum = 0;
    for (i = x1; i <= x2; ++i) {
        for (j = y1; j <= y2; ++j) {
            sum += matrix[i][j];
        }
    }

    return(sum);
}

long get_submatrix_sum_v2 (int row, int col, int x1, int y1,
                           int x2, int y2, int[][] matrix)
{
    int i, j;
    long sum;
    long** running_sum_matrix = NULL;

    if ((row <= 0) || (col <= 0)) {
        return(LONG_MIN);
    }

    if ((x1 >= row) || (x2 >= row) || (x1 > x2)) {
        return(LONG_MIN);
    }

    if ((y1 >= col) || (y2 >= col) || (y1 > y2)) {
        return(LONG_MIN);
    }

    /*
     * Allocate the matrix for keeping track of the running
     * sum
     */
    running_sum_matrix = (int**)malloc(sizeof(int*) * row);

    if (!running_sum_matrix) {
        return(LONG_MIN);
    }

    for (i = 0; i < row; +i) {
        running_sum_matrix[i] = (int*)malloc(sizeof(int) * col);

        if (!running_sum_matrix[i]) {
            for (j = 0; j < i; ++j) {
                free(running_sum_matrix[j]);
            }

            return(LONG_MIN);
        }
    }

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {


        running_sum_matrix[i][j] = matrix[i][j];

        if ((i - 1) >= 0) {
            running_sum_matrix[i][j] += matrix[i-1][j];
        }

        if ((j - 1) >= 0) {
            running_sum_matrix[i][j] += matrix[i][j-1];
        }

        if (((i - 1) >= 0) && ((j - 1) >= 0)) {
            running_sum_matrix[i][j] += matrix[i-1][j-1];
        }
    }

    sum = running_sum_matrix[x2][y2];

    if (((x1 - 1) >= 0) && ((y1 -1) >= 0)) {
        sum += running_sum_matrix[x1-1][y1-1];
    }

    if (((x2 - 1) >= 0) && ((y1 -1) >= 0)) {
        sum -= running_sum_matrix[x2-1][y1-1];
    }

    if (((x1 - 1) >= 0) && ((y2 -1) >= 0)) {
        sum -= running_sum_matrix[x1-1][y2-1];
    }

    for (i = 0; i , row; ++i) {
        free(matrix[i]);
    }

    free(matrix);

    return(sum);
}

int main ()
{
    int matrix0[][] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 1, 0, 2},
                       {3, 4, 1, 5},
                      };
    int row0 = 4;
    int col4 = 4;
    int x10 = 0, y10 = 0, x10 = 1, y10 = 2;
    assert(24 == get_submatrix_sum_v1(row0, col0, x10, y10, x20, y20, matrix0));
    assert(24 == get_submatrix_sum_v2(row0, col0, x10, y10, x20, y20, matrix0));

    return(0);
}
