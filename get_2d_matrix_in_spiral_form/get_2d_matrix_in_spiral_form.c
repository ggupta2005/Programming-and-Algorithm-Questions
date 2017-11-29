/*
 * This program gets the spiral form a two dimensional matrix. The spiral
 * form of the matrix is generated using the clockwise traversal of the
 * matrix. For example, if the matrix is
 * [[1, 2, 3]
 *  [4, 5, 6]
 *  [7, 8, 9]],
 * then the spiral form of the metrix is [1, 2, 3, 6, 9, 8, 7, 4, 5]. For
 * more information on the problem, visit the following webpage:-
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

enum direction {
    forward,
    backward,
    downward,
    upward
};


int* get_2d_matrix_in_spiral_form (int row, int col, int matrix[][col])
{
    int* array = NULL;
    int num_elements, x_lower, x_higher, y_lower, y_higher, i, j;
    enum direction direction;

    if ((row <= 0) || (col <= 0)) {
        return(NULL);
    }

    array = (int*)malloc(sizeof(int) * (row * col));

    if (!array) {
        return(NULL);
    }

    memset(array, 0, sizeof(int) * (row * col));

    x_lower = 0;
    x_higher = row - 1;
    y_lower = 0;
    y_higher = col - 1;
    direction = forward;

    num_elements = 0;
    j = 0;
    while (num_elements < (row * col)) {

        switch (direction) {
            case forward:
                for (i = y_lower; i <= y_higher; ++i) {
                    array[j] = matrix[x_lower][i];
                    ++j;
                }

                ++x_lower;
                direction = downward;
                num_elements += y_higher - y_lower + 1;
                break;

            case backward:
                for (i = y_higher; i >= y_lower; --i) {
                    array[j] = matrix[x_higher][i];
                    ++j;
                }

                --x_higher;
                direction = upward;
                num_elements += y_higher - y_lower + 1;
                break;

            case downward:
                for (i = x_lower; i <= x_higher; ++i) {
                    array[j] = matrix[i][y_higher];
                    ++j;
                }

                --y_higher;
                direction = backward;
                num_elements += x_higher - x_lower + 1;
                break;

            case upward:
                for (i = x_higher; i >= x_lower; --i) {
                    array[j] = matrix[i][y_lower];
                    ++j;
                }

                ++y_lower;
                direction = forward;
                num_elements += x_higher - x_lower + 1;
                break;

            default:
                break;
        }

    }

    return(array);
}

int main ()
{
    int matrix0[][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int expected0[] = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    int* actual0 = get_2d_matrix_in_spiral_form(3, 3, matrix0);
    assert(0 == memcmp(expected0, actual0, sizeof(expected0)));

    int matrix1[][3] = {{ 1,  2,  3},
                        { 4,  5,  6},
                        { 7,  8,  9},
                        {10, 11, 12},
                        {13, 14, 15}};
    int expected1[] = {1, 2, 3, 6, 9, 12, 15, 14, 13, 10, 7, 4, 5, 8, 11};
    int* actual1 = get_2d_matrix_in_spiral_form(5, 3, matrix1);
    assert(0 == memcmp(expected1, actual1, sizeof(expected1)));

    return(0);
}
