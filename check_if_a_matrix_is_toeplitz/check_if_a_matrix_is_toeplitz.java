/*
 * Check if a two dimensional matrix is toeplitz. A matrix is called toeplitz
 * if all the elements on the diagonal of the matrix are equal. More on the
 * toeplitz matrix can be found at the link:-
 * https://en.wikipedia.org/wiki/Toeplitz_matrix
 */
import java.io.*;
import java.util.*;

public class check_if_a_matrix_is_toeplitz
{

    /*
     * This function checks if a two dimensional matrix is toeplitz, If the
     * matrix is toeplitz, then this function returns 'true' otherwise this
     * function returns 'false'. This function tests each downward going
     * diagonal in the matrix for equality. The time complexity of this
     * function is O(M * N), where 'M' is the number of rows and 'N' is the
     * number of columns in the matrix. The space complexity of this function
     * is O(1);
     */
    public static boolean check_if_two_dimensional_matrix_is_toeplitz (
                                                          int[][] matrix)
    {
        int i, j, k, first_num;
        int row, col;
        boolean if_diagonal_equal;

        /*
         * If the matrix is null, then retrun 'false'
         */
        if (matrix == null) {
            return(false);
        }

        row = matrix.length;
        col = matrix[0].length;

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

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with an empty matrix
         */
        int[][] matrix0 = null;
        assert(false == check_if_two_dimensional_matrix_is_toeplitz(
                                                                matrix0));

        /*
         * Test 1: Test with a matrix having one row and one column.
         *         This should be a toeplitz matrix by default.
         */
        int[][] matrix1 = {{1}};
        assert(true == check_if_two_dimensional_matrix_is_toeplitz(
                                                                matrix1));

        /*
         * Test 2: Test with a matrix having two rows and two columns
         *         with diagonal elements being equal. This should be a
         *         toeplitz matrix.
         */
        int[][] matrix2 = {{2, 1},
                           {3, 2}};
        assert(true == check_if_two_dimensional_matrix_is_toeplitz(
                                                                matrix2));

        /*
         * Test 3: Test with a matrix having two rows and two columns
         *         with diagonal elements being un-equal. This should
         *         not be a toeplitz matrix by default.
         */
        int[][] matrix3 = {{4, 1},
                           {3, 3}};
        assert(false == check_if_two_dimensional_matrix_is_toeplitz(
                                                                matrix3));

        /*
         * Test 4: Test with a matrix having number of rows not equal to
         *         and number of columns with diagonal elements being equal.
         *         The number of rows is greater than the number of columns.
         *         This should be a toeplitz matrix.
         */
        int[][] matrix4 = {{0, 1, 3},
                           {3, 0, 1},
                           {4, 3, 0},
                           {5, 4, 3},
                           {6, 5, 4}};
        assert(true == check_if_two_dimensional_matrix_is_toeplitz(
                                                                matrix4));

        /*
         * Test 5: Test with a matrix having number of rows not equal to
         *         and number of columns with diagonal elements being equal.
         *         The number of rows is lesser than the number of columns.
         *         This should be a toeplitz matrix.
         */
        int[][] matrix5 = {{0, 1, 3, 9, 8, 7}};
        assert(true == check_if_two_dimensional_matrix_is_toeplitz(
                                                                matrix5));

        /*
         * Test 6: Test with a matrix having number of rows not equal to
         *         and number of columns with diagonal elements being equal.
         *         The inequality in a diagonal ocurrs in the top half of the
         *         matrix. This should not be a toeplitz matrix.
         */
        int[][] matrix6 = {{0, 1, 3},
                           {3, 0, 1},
                           {4, 3, 7},
                           {5, 4, 3},
                           {6, 5, 4}};
        assert(false == check_if_two_dimensional_matrix_is_toeplitz(
                                                                matrix6));

        /*
         * Test 7: Test with a matrix having number of rows not equal to
         *         and number of columns with diagonal elements being equal.
         *         The inequality in a diagonal ocurrs in the bottom half of the
         *         matrix. This should not be a toeplitz matrix.
         */
        int[][] matrix7 = {{0, 1, 3},
                           {3, 0, 1},
                           {4, 3, 0},
                           {5, 4, 3},
                           {6, 5, 9}};
        assert(false == check_if_two_dimensional_matrix_is_toeplitz(
                                                                matrix7));
    }
}
