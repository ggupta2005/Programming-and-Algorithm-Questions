/*
 * Given a picture consisting of black and white pixels, find the number
 * of black lonely pixels. The picture is represented by a 2D char array
 * consisting of 'B' and 'W', which means black and white pixels respectively.
 *
 * A black lonely pixel is character 'B' that located at a specific position
 * where the same row and same column don't have any other black pixels.
 *
 * Example:
 * Input:
 * [['W', 'W', 'B'],
 *  ['W', 'B', 'W'],
 *  ['B', 'W', 'W']]
 *
 * Output: 3
 * Explanation: All the three 'B's are black lonely pixels.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int findLonelyPixel(char** picture, int pictureRowSize, int pictureColSize)
{
    int row, col;
    int *row_vector, *col_vector;
    int num_lonely_black_pixels;

    if (!picture || (pictureRowSize <= 0) || (pictureColSize <= 0)) {
        return(0);
    }

    for (row = 0; row < pictureRowSize; ++row) {
        if (!picture[row]) {
            return(0);
        }
    }

    row_vector = (int*)malloc(sizeof(int) * pictureRowSize);
    col_vector = (int*)malloc(sizeof(int) * pictureColSize);

    if (!row_vector || !col_vector) {
        free(row_vector);
        free(col_vector);
        return(0);
    }

    memset(row_vector, 0, sizeof(int) * pictureRowSize);
    memset(col_vector, 0, sizeof(int) * pictureColSize);

    for (row = 0; row < pictureRowSize; ++row) {
        for (col = 0; col < pictureColSize; ++col) {
            if (picture[row][col] == 'B') {
                ++row_vector[row];
                ++col_vector[col];
            }
        }
    }

    num_lonely_black_pixels = 0;
    for (row = 0; row < pictureRowSize; ++row) {
        for (col = 0; col < pictureColSize; ++col) {
            if (picture[row][col] == 'B') {
                if ((row_vector[row] == 1) && (col_vector[col] == 1)) {
                    ++num_lonely_black_pixels;
                }
            }
        }
    }

    free(row_vector);
    free(col_vector);
    return(num_lonely_black_pixels);
}

int main ()
{

    return(0);
}
