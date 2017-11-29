/*
 * This program checks if the Sudoku board is a valid starting board
 * position.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<string.h>


bool if_char_is_digit (char ch)
{
    if (((ch - '0') >= 0) && ((ch -'9') <= 9)) {
        return(true);
    }

    return(false);
}

int find_square_root (int num)
{
    int sqrt;

    if (num <= 0) {
        return(0);
    }

    sqrt = 1;
    while (sqrt * sqrt < num) {
        ++sqrt;
    }

    if (sqrt * sqrt > num) {
        return(0);
    }

    return(sqrt);
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
    int index_row, index_col, row_width, col_width, i, j;
    int* temp;

    if (!board || (boardRowSize <= 0) || (boardColSize <= 0) ||
        (boardColSize != boardRowSize)) {
        return(false);
    }

    for (index_row = 0; index_row < boardRowSize; ++index_row) {
        if (!board[index_row]) {
            return(false);
        }
    }

    temp = (int*)malloc(sizeof(int) * (boardRowSize + 1));

    if (!temp) {
        return(false);
    }

    /*
     * First validate all rows of the Sudoku board
     */
    for (index_row = 0; index_row < boardRowSize; ++index_row) {

        memset(temp, 0, sizeof(int) * (boardRowSize + 1));

        for (index_col = 0; index_col < boardColSize; ++index_col) {
            if (if_char_is_digit(board[index_row][index_col])) {
                if (temp[board[index_row][index_col] - '0'] != 0) {
                    free(temp);
                    return(false);
                } else {
                    temp[board[index_row][index_col] - '0'] = 1;
                }
            }
        }
    }

    /*
     * Second validate all cols of the Sudoku board
     */
    for (index_col = 0; index_col < boardColSize; ++index_col) {

        memset(temp, 0, sizeof(int) * (boardColSize + 1));

        for (index_row = 0; index_row < boardRowSize; ++index_row) {
            if (if_char_is_digit(board[index_row][index_col])) {
                if (temp[board[index_row][index_col] - '0'] != 0) {
                    free(temp);
                    return(false);
                } else {
                    temp[board[index_row][index_col] - '0'] = 1;
                }
            }
        }
    }

    /*
     * Third validate all the sub-matrix squares
     */
    row_width = find_square_root(boardRowSize);
    col_width = find_square_root(boardColSize);

    if (row_width == 0) {
        return(false);
    }

    for (i = 0; i < row_width; ++i) {
        for (j = 0; j < col_width; ++j) {
            for (index_row = i * row_width;
                 index_row < (i + 1) * row_width; ++index_row) {

                memset(temp, 0, sizeof(int) * (boardColSize + 1));

                for (index_col = j * col_width;
                     index_col < (j + 1) * col_width; ++index_col) {

                    if (if_char_is_digit(board[index_row][index_col])) {
                        if (temp[board[index_row][index_col] - '0'] != 0) {
                            free(temp);
                            return(false);
                        } else {
                            temp[board[index_row][index_col] - '0'] = 1;
                        }
                    }
                }
            }
        }
    }

    return(true);
}

int main ()
{
    char board0[9][9] = {
                          "53..7....",
                          "6..195...",
                          ".98....6.",
                          "8...6...3",
                          "4..8.3..1",
                          "7...2...6",
                          ".6....28.",
                          "...419..5",
                          "....8..79"
                        };
    int row0 = 9;
    int col0= 9;
    assert(true == isValidSudoku((char**)board0, row0, col0));

    return(0);
}
