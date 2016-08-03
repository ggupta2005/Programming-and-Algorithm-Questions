/*
 * Check if a two dimensional matrix is toeplitz. A matrix is called toeplitz
 * if all the elements on the diagonal of the matrix are equal. More on the
 * toeplitz matrix can be found at the link:-
 * https://en.wikipedia.org/wiki/Toeplitz_matrix
 */
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

/*
 * This function checks if a two dimensional matrix is toeplitz, If the
 * matrix is toeplitz, then this function returns 'true' otherwise this
 * function returns 'false'. This function tests each downward going
 * diagonal in the matrix for equality. The time complexity of this
 * function is O(M * N), where 'M' is the number of rows and 'N' is the
 * number of columns in the matrix. The space complexity of this function
 * is O(1);
 */
bool check_if_two_dimensional_matrix_is_toeplitz (int row, int col,
                                                  int matrix[][col])
{
    int i, j, k, first_num;
    bool if_diagonal_equal;

    /*
     * If the row number and column number of the matrix are not
     * legal, then return false from this function.
     */
    if ((row <= 0) || (col <= 0)) {
        return(false);
    }

    /*
     * Let us assume that the matrix is toeplitz
     */
    if_diagonal_equal = true;

    /*
     * Iterate over all the downwards going diagonals from the top edge
     * to find if the diagonals contain equal elements
     */
    for (k = col - 1; k >= 0; --k) {

        /*
         * Get the first element of the top edge downward going diagonal
         */
        first_num = matrix[0][k];

        /*
         * Iterate over all the other elements in this diagonal to
         * check if all other elements are equal to the first element
         * in the diagonal.
         */
        if_diagonal_equal = true;
        for (i = 1, j = k + 1; ((i < row) && (j < col)); ++i, ++j) {

            /*
             * If a particular lement in the diagonal is not equal to
             * the first element, then break
             */
            if (matrix[i][j] != first_num) {
                if_diagonal_equal = false;
                break;
            }
        }

        /*
         * If this diagonal did not have equal elements, then break
         * from this loop
         */
        if (!if_diagonal_equal) {
            break;
        }
    }

    /*
     * If upper half of the matrix is not found to be toeplitz, then return
     * 'false'
     */
    if (!if_diagonal_equal) {
        return(false);
    }

    /*
     * Iterate over all the downwards going diagonals from the left edge
     * to find if the diagonals contain equal elements
     */
    for (k = 1; k < row; ++k) {

        /*
         * Get the first element of the left edge downward going diagonal
         */
        first_num = matrix[k][0];

        /*
         * Iterate over all the other elements in this diagonal to
         * check if all other elements are equal to the first element
         * in the diagonal.
         */
        if_diagonal_equal = true;
        for (i = k + 1, j = 1; ((i < row) && (j < col)); ++i, ++j) {

            /*
             * If a particular lement in the diagonal is not equal to
             * the first element, then break
             */
            if (matrix[i][j] != first_num) {
                if_diagonal_equal = false;
                break;
            }
        }

        /*
         * If this diagonal did not have equal elements, then break
         * from this loop
         */
        if (!if_diagonal_equal) {
            break;
        }
    }

    /*
     * Return the result if the matrix is toeplitz or not
     */
    return(if_diagonal_equal);
}

int main ()
{
    /*
     * Test 0: Test with a dummy matrix with illegal values of rows and
     *         sent to the function
     */
    int matrix0[1][2] = {{1, 1}};
    int row0 = 0;
    int col0 = -1;
    assert(false == check_if_two_dimensional_matrix_is_toeplitz(
                                                row0, col0, matrix0));

    /*
     * Test 1: Test with a matrix having one row and one column.
     *         This should be a toeplitz matrix by default.
     */
    int matrix1[1][1] = {{1}};
    int row1 = 1;
    int col1 = 1;
    assert(true == check_if_two_dimensional_matrix_is_toeplitz(
                                                row1, col1, matrix1));

    /*
     * Test 2: Test with a matrix having two rows and two columns
     *         with diagonal elements being equal. This should be a
     *         toeplitz matrix.
     */
    int matrix2[2][2] = {{2, 1},
                         {3, 2}};
    int row2 = 2;
    int col2 = 2;
    assert(true == check_if_two_dimensional_matrix_is_toeplitz(
                                                row2, col2, matrix2));

    /*
     * Test 3: Test with a matrix having two rows and two columns
     *         with diagonal elements being un-equal. This should
     *         not be a toeplitz matrix by default.
     */
    int matrix3[2][2] = {{4, 1},
                         {3, 3}};
    int row3 = 2;
    int col3 = 2;
    assert(false == check_if_two_dimensional_matrix_is_toeplitz(
                                                row3, col3, matrix3));

    /*
     * Test 4: Test with a matrix having number of rows not equal to
     *         and number of columns with diagonal elements being equal.
     *         The number of rows is greater than the number of columns.
     *         This should be a toeplitz matrix.
     */
    int matrix4[5][3] = {{0, 1, 3},
                         {3, 0, 1},
                         {4, 3, 0},
                         {5, 4, 3},
                         {6, 5, 4}};
    int row4 = 5;
    int col4 = 3;
    assert(true == check_if_two_dimensional_matrix_is_toeplitz(
                                                row4, col4, matrix4));

    /*
     * Test 5: Test with a matrix having number of rows not equal to
     *         and number of columns with diagonal elements being equal.
     *         The number of rows is lesser than the number of columns.
     *         This should be a toeplitz matrix.
     */
    int matrix5[1][6] = {{0, 1, 3, 9, 8, 7}};
    int row5 = 1;
    int col5 = 6;
    assert(true == check_if_two_dimensional_matrix_is_toeplitz(
                                                row5, col5, matrix5));

    /*
     * Test 6: Test with a matrix having number of rows not equal to
     *         and number of columns with diagonal elements being equal.
     *         The inequality in a diagonal ocurrs in the top half of the
     *         matrix. This should not be a toeplitz matrix.
     */
    int matrix6[5][3] = {{0, 1, 3},
                         {3, 0, 1},
                         {4, 3, 7},
                         {5, 4, 3},
                         {6, 5, 4}};
    int row6 = 5;
    int col6 = 3;
    assert(false == check_if_two_dimensional_matrix_is_toeplitz(
                                                row6, col6, matrix6));

    /*
     * Test 7: Test with a matrix having number of rows not equal to
     *         and number of columns with diagonal elements being equal.
     *         The inequality in a diagonal ocurrs in the bottom half of the
     *         matrix. This should not be a toeplitz matrix.
     */
    int matrix7[5][3] = {{0, 1, 3},
                         {3, 0, 1},
                         {4, 3, 0},
                         {5, 4, 3},
                         {6, 5, 9}};
    int row7 = 5;
    int col7 = 3;
    assert(false == check_if_two_dimensional_matrix_is_toeplitz(
                                                row7, col7, matrix7));

    return(0);
}
