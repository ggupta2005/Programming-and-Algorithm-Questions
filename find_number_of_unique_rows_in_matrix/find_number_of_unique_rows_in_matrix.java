/*
 * This program finds the number of unique rows in a binary matrix. Consider
 * the example below:-
 *
 * Input:
 *   {0, 1, 0, 0, 1}
 *   {1, 0, 1, 1, 0}
 *   {0, 1, 0, 0, 1}
 *   {1, 1, 1, 0, 0}
 *
 * Output:
 *   3
 *   The three unique rows are below:-
 *      0 1 0 0 1
 *      1 0 1 1 0
 *      1 1 1 0 0
 */
import java.io.*;
import java.util.*;

class trienode
{
    /*
     * Constant for the number of boolean values
     */
    public static final int MAX_BOOLEAN_VALUES = 2;

    /*
     * Array of references storing references to the
     * child nodes in the trie
     */
    trienode[] links;

    /*
     * Constructor for trie node class
     */
    trienode ()
    {
        /*
         * Allocate the number of links in the trie for all the
         * boolean valuess
         */
        links = new trienode[MAX_BOOLEAN_VALUES];

        for (int index = 0; index < MAX_BOOLEAN_VALUES; ++index) {
            links[index] = null;
        }
    }
}

class trie
{
    trienode root;

    trie ()
    {
        root = new trienode();
    }

    /*
     * This function inserts a binary valued matrix rowc in the trie data
     * structure. If the matrix row is not valid, then this function does
     * not add the matrix row in the trie. The time complexity of this
     * function is O(n), where 'n' is the number of entriesin the matrix
     * row. The space complexity of this string is O(1).
     */
    void insert_boolean_row_in_trie (int[] row)
    {
        trienode current;
        int index;

        /*
         * If the root of the trie is not valid or the matrix row
         * is not valid, then return from the function
         */
        if (root == null || row == null || (row.length <= 0)) {
            return;
        }

        /*
         * Check if each entry of the matrix is zero or one. If not,
         * simply return from this function
         */
        for (index = 0; index < row.length; ++index) {
            if ((row[index] != 0) && (row[index] != 1)) {
                return;
            }
        }

        /*
         * Start at the root of the digital trie and add the
         * matrix row in the trie
         */
        current = root;
        for (index = 0; index < row.length; ++index) {

            if ((current.links[row[index]]) == null) {
                current.links[row[index]] = new trienode();
            }

            current = current.links[row[index]];
        }
    }

    /*
     * This function returns 'true' if the given matrix row is found in the
     * trie and 'false' otherwise. The time complexity of this function
     * is O(n), where 'n' is the number of entries in the matrix row.
     * The space complexity of this string is O(1).
     */
    boolean search_if_boolean_row_exists_in_trie (int[] row)
    {
        trienode current;
        int index;

        /*
         * If the root of trie is null or if the matrix row is null or
         * empty, then return 'false'
         */
        if (root == null || row == null || (row.length <= 0)) {
            return(false);
        }

        /*
         * Check if each entry of the matrix is zero or one. If not,
         * simply return 'false' from this function
         */
        for (index = 0; index < row.length; ++index) {
            if ((row[index] != 0) && (row[index] != 1)) {
                return(false);
            }
        }

        /*
         * Start at the root of the tree and search down in the trie
         * for the matrix row
         */
        current = root;
        for (index = 0; index < row.length; ++index) {

            /*
             * If the child node is null, then the current
             * entry does not exist in the trie, so return
             * 'false'
             */
            if ((current.links[row[index]]) == null) {
                return(false);
            }

            /*
             * Move to the child node
             */
            current = current.links[row[index]];
        }

        /*
         * Return 'true' since the matrix row is found in the trie
         */
        return(true);
    }
}

public class find_number_of_unique_rows_in_matrix
{
    /*
     * This function returns the number of unique rows in a binary valued
     * matrix. The time complexity of this function is O(m * m * n), where 'm'
     * is the number of rows in the matrix and 'n' is the number of cols in
     * the matrix. The space complexity of this function is O(m).
     */
    public static int get_num_unique_rows_in_matrix_v1 (int[][] matrix)
    {
        int row, col, inner_row, num_unique;
        int[] unique_id;
        int rows, cols;

        /*
         * If the input matrix is not valid, then return zero
         */
        if (matrix == null) {
            return(0);
        }

        /*
         * Read rows and columns of the matrix
         */
        rows = matrix.length;
        cols = matrix[0].length;

        /*
         * If the number of rows and columns in the matrix are not valid,
         * then return zero.
         */
        if ((rows <= 0) && (cols <= 0)) {
            return(0);
        }

        /*
         * Allocate temporary buffer of size equal to the number of rows
         * in the matrix.
         */
        unique_id = new int[rows];

        if (unique_id == null) {
            return(0);
        }

        /*
         * Assign an illegal value to all entries of the temporary buffer
         */
        for (row = 0; row < rows; ++row) {
            unique_id[row] = -1;
        }

        /*
         * Assign a unique number to each of the unique rows in the matrix
         */
        num_unique = 0;

        /*
         * Iterate over all the rows in the matrix
         */
        for (row = 0; row < rows; ++row) {

            /*
             * If the current row is found to unique, then find all other
             * rows which are same as this row.
             */
            if (unique_id[row] == -1) {

                /*
                 * Mark this row with a new unique identifier
                 */
                unique_id[row] = num_unique;

                /*
                 * Iterate over other rows to find other rows which are same
                 * as this row.
                 */
                for (inner_row = row + 1; inner_row < rows; ++inner_row) {

                    for (col = 0; col < cols; ++col) {
                        if (matrix[row][col] != matrix[inner_row][col]) {
                            break;
                        }
                    }

                    /*
                     * If this row is same as the current row, then mark this
                     * row with the unique identifier of the current row.
                     */
                    if (col == cols) {
                        unique_id[inner_row] = num_unique;
                    }
                }

                /*
                 * Increment the unique identifier.
                 */
                ++num_unique;
            }
        }

        /*
         * Return the number of unique rows found in the matrix.
         */
        return(num_unique);
    }

    /*
     * This function returns the number of unique rows in a binary valued matrix.
     * The time complexity of this function is O(m * n), where 'm' is the
     * number of rows in the matrix and 'n' is the number of cols in the matrix.
     * The space complexity of this function is approximately O(m * n) since we
     * are using s trie to drive the algorithm.
     */
    public static int get_num_unique_rows_in_matrix_v2 (int[][] matrix)
    {
        int row, num_unique;
        trie t = null;
        int rows, cols;

        /*
         * If the input matrix is not valid, then return zero
         */
        if (matrix == null) {
            return(0);
        }

        /*
         * Read rows and columns of the matrix
         */
        rows = matrix.length;
        cols = matrix[0].length;

        /*
         * If the number of rows and columns in the matrix are not valid,
         * then return zero.
         */
        if ((rows <= 0) && (cols <= 0)) {
            return(0);
        }

        /*
         * Intialize the root of the trie node.
         */
        t = new trie();

        /*
         * If the allocation of the trie fails, then return zero.
         */
        if (t == null) {
            return(0);
        }

        /*
         * Keep track of the number of unique matrix rows
         */
        num_unique = 0;

        /*
         * Iterate over all the rows in the binary matrix
         */
        for (row = 0; row < rows; ++row) {

            /*
             * If the given row does not exist in the trie, then add the
             * row in the trie and increment the counter for number of unique
             * rows in the matrix.
             */
            if (!t.search_if_boolean_row_exists_in_trie(matrix[row])) {
                ++num_unique;
                t.insert_boolean_row_in_trie(matrix[row]);
            }
        }

        /*
         * Return the number of unique rows in the matrix
         */
        return(num_unique);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test the case, when some rows in the matrix are unque and
         *         some are not unique.
         */
        int[][] matrix0 =
                            {
                                {0, 1, 0, 0, 1},
                                {1, 0, 1, 1, 0},
                                {0, 1, 0, 0, 1},
                                {1, 1, 1, 0, 0},
                                {0, 1, 0, 0, 1},
                                {1, 1, 1, 0, 0},
                                {0, 1, 0, 0, 1}
                            };
        assert(3 == get_num_unique_rows_in_matrix_v1(matrix0));
        assert(3 == get_num_unique_rows_in_matrix_v2(matrix0));

        /*
         * Test 1: Test the case, when only one of the rows in the matrix is
         *         unique.
         */
        int[][] matrix1 =
                            {
                                {1, 1, 0, 0, 1, 0, 0},
                                {1, 1, 0, 0, 1, 0, 0},
                                {1, 1, 0, 0, 1, 0, 0},
                                {1, 1, 0, 0, 1, 0, 0},
                                {1, 1, 0, 0, 1, 0, 0},
                                {1, 1, 0, 0, 1, 0, 0},
                                {1, 1, 0, 0, 1, 0, 0}
                            };
        assert(1 == get_num_unique_rows_in_matrix_v1(matrix1));
        assert(1 == get_num_unique_rows_in_matrix_v2(matrix1));

        /*
         * Test 2: Test the case, when only all the rows in the matrix are
         *         unique.
         */
        int[][] matrix2 =
                            {
                                {0, 1, 0, 0, 1},
                                {1, 0, 0, 1, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 1, 0, 0}
                            };
        assert(matrix2.length == get_num_unique_rows_in_matrix_v1(matrix2));
        assert(matrix2.length == get_num_unique_rows_in_matrix_v2(matrix2));

        /*
         * Test 3: Test the case, when there is only one row in the matrix.
         */
        int[][] matrix3=
                            {
                                {0, 1, 0, 0, 1, 0, 0, 0, 1, 0}
                            };
        assert(matrix3.length == get_num_unique_rows_in_matrix_v1(matrix3));
        assert(matrix3.length == get_num_unique_rows_in_matrix_v2(matrix3));

        /*
         * Test 4: Test the case, when there is only one column in the matrix.
         */
        int[][] matrix4 =
                            {
                                {0},
                                {1},
                                {0},
                                {0},
                                {1}
                            };
        assert(2 == get_num_unique_rows_in_matrix_v1(matrix4));
        assert(2 == get_num_unique_rows_in_matrix_v2(matrix4));
    }
}
