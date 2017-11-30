/*
 * This program checks if 'n' queens can be placed on a chess board of
 * nXn dimensions.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

bool if_queen_is_safe (char** matrix, int n, int row, int col)
{
    int i, j;

    if (!matrix || (n <= 0) || (row < 0) || (row >= n) ||
        (col < 0) || (col >= n)) {
        return(false);
    }

    /*
     * check if there is queen is present in the horizontal
     * line
     */
    for (i = 0; i < n; ++i) {
        if (i != col) {
            if (matrix[row][i] == '1') {
                return(false);
            }
        }
    }

    /*
     * check if there is queen is present in the vertical
     * line
     */
    for (i = 0; i < n; ++i) {
        if (i != row) {
            if (matrix[i][col] == '1') {
                return(false);
            }
        }
    }

    return(true);
}

bool if_n_queens_be_placed (char** matrix, int n, int row)
{
    int i, j;

    if (!matrix || (n <= 0) || (row < 0) || (row > n)) {
        return(false);
    }

    if (row == n) {
        return(true);
    }

    for (i = 0; i < n; ++i) {
        if (if_queen_is_safe(matrix, n, row, i)) {
            matrix[row][i] = '1';

            if (!if_n_queens_be_placed(matrix, n, row + 1)) {
                matrix[row][i] = '0';
            } else {
                return(true);
            }
        }
    }

    return(false);
}

bool check_if_n_queens_be_placed_on_n_board (int n)
{
    char** matrix;
    int i, j;
    bool if_placed;

    if (n <= 0) {
        return(false);
    }

    matrix = (char**)malloc(sizeof(char*) * n);

    if (!matrix) {
        return(false);
    }

    for (i = 0; i < n; ++i) {
        matrix[i] = (char*)malloc(sizeof(char) * n);

        if (!matrix[i]) {
            for (j = 0; j < i; ++j) {
                free(matrix[j]);
                return(false);
            }
        }

        for (j = 0; j < n; ++j) {
            matrix[i][j] = '0';
        }
    }

    if_placed = if_n_queens_be_placed(matrix, n, 0);

    printf("n = %d\n", n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    return(if_placed);
}

int main ()
{
    assert(!check_if_n_queens_be_placed_on_n_board(0));
    assert(check_if_n_queens_be_placed_on_n_board(1));
    assert(check_if_n_queens_be_placed_on_n_board(2));
    assert(check_if_n_queens_be_placed_on_n_board(3));
    assert(check_if_n_queens_be_placed_on_n_board(4));

    return(0);
}
