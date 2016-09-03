/*
 * This program finds the number of unique paths in a matrix from the top
 * left corner to bottom right corner. We are only allowed to move downwards
 * and towards right side. For more information on the problem, please visit
 * http://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

/*
 * This function finds the number of unique paths from top left corner of
 * a matrix to the bottem right corner of a matrix having 'row' rows and
 * 'col columns. The program uses bottom up approach in dynamic programming
 * to compute the number of paths to a given cell in the matrix. The time
 * complexiy of this function is O(row * col) because we visit each cell
 * in the matrix. The space complexity of this function is O(row * col)
 * since we use a temporary matrix to store the number of unique paths
 * in a given cell.
 */
int find_number_of_unique_paths_in_matrix (int row, int col)
{
    int** matrix;
    int i, j, max_paths;

    /*
     * If the values of 'row' and 'col' are not valid, then return
     * zero
     */
    if ((row <= 0) || (col <= 0)) {
        return(0);
    }

    /*
     * Allocate the rows of the matrix
     */
    matrix =(int**)malloc(sizeof(int*) * row);

    /*
     * If the matrix allocation fails then return zero
     */
    if (!matrix) {
        return(0);
    }

    /*
     * For each matrix pointer, allocate an array of length 'col'
     */
    for (i = 0; i < row; ++i) {

        matrix[i] = (int*)malloc(sizeof(int) * col);


        /*
         * If the memory alocation fails, then release all the memory
         * that was allocated and return zero
         */
        if (!matrix[i]) {
            for (j = 0; j < i; ++j) {
                free(matrix[j]);
            }

            return(0);
        }

        /*
         * Clearthe contents of the row
         */
        memset(matrix[i], 0, sizeof(int) * col);
    }

    /*
     * The left corner cell can be reached in one unique path
     */
    matrix[0][0] = 1;

    /*
     * Iterate over all the cells in the matrix
     */
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {

            /*
             * If the upper cell is valid, then add the number of
             * ways to reach the upper cell to the current cell
             */
            if ((i - 1) >= 0) {
                matrix[i][j] += matrix[i-1][j];
            }

            /*
             * If the previous row cell is valid, then add the number
             * of ways to reach the previous row cell to the current
             * cell
             */
            if ((j - 1) >= 0) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
    }

    /*
     * Store the number of unique paths to reach to the bottom
     * right corner cell
     */
    max_paths = matrix[row - 1][col - 1];

    /*
     * Walk and free the matrix
     */
    for (j = 0; j < row; ++j) {
        free(matrix[j]);
    }

    /*
     * Return the maximum number of paths
     */
    return(max_paths);
}

int main ()
{
    /*
     * Test 0: Test with illegal value of rows and columns. The number
     *         of unique paths should be zero
     */
    assert(0 == find_number_of_unique_paths_in_matrix(0, 0));
    assert(0 == find_number_of_unique_paths_in_matrix(1, -1));
    assert(0 == find_number_of_unique_paths_in_matrix(-1, 1));

    /*
     * Test 1: Test with one row and one column. The number of unique
     *         paths should be one
     */
    assert(1 == find_number_of_unique_paths_in_matrix(1, 1));

    /*
     * Test 2: Test with equal values of rows and columns. The number of
     *         unique paths should be some non-zero value
     */
    assert(2 == find_number_of_unique_paths_in_matrix(2, 2));
    assert(6 == find_number_of_unique_paths_in_matrix(3, 3));

    /*
     * Test 3: Test with un-equal values of rows & columns. The number of
     *         unique paths should be some non-zero value
     */
    assert(3 == find_number_of_unique_paths_in_matrix(3, 2));

    /*
     * Test 4: Test with many rows and one columns. The number of
     *         unique paths should be one
     */
    assert(1 == find_number_of_unique_paths_in_matrix(3, 1));

    /*
     * Test 5: Test with one row and many columns. The number of
     *         unique paths should be one
     */
    assert(1 == find_number_of_unique_paths_in_matrix(1, 3));

    return(0);
}
