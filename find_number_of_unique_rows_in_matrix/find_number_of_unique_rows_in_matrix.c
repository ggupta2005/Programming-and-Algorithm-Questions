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
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*
 * This function returns the number of unique rows in a binary valued matrix.
 * The time complexity of this function is O(m * m * n), where 'm' is the
 * number of rows in the matrix and 'n' is the number of cols in the matrix.
 * The space complexity of this function is O(m).
 */
int get_num_unique_rows_in_matrix_v1 (int rows, int cols, int matrix[][cols])
{
    int row, col, inner_row, num_unique;
    int* unique_id;

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
    unique_id = (int*)malloc(sizeof(int) * rows);

    if (!unique_id) {
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
     * Free the temporary allocated buffer
     */
    free(unique_id);

    /*
     * Return the number of unique rows found in the matrix.
     */
    return(num_unique);
}

/*
 * Number of sysmbols in the binary matrix
 */
#define MAX_BOOLEAN_VALUES 2

/*
 * Structure of the trie for storing the binary trie
 */
struct trienode {
    struct trienode* links[MAX_BOOLEAN_VALUES];
};

/*
 * This function returns the pointer reference for the newly allocated
 * trie node and set the data members of the trie node to default values.
 * If the memory allocation fails, then this function returns NULL.
 */
struct trienode* make_trienode ()
{
    struct trienode* new_node;
    int index;

    /*
     * Allocate a new trie node
     */
    new_node = (struct trienode*)malloc(sizeof(struct trienode));

    /*
     * If the memory allocation fails, then return NULL
     */
    if (!new_node) {
        return(NULL);
    }

    /*
     * Assign default values to the trie node data members
     */
    for (index = 0; index < MAX_BOOLEAN_VALUES; ++index) {
        new_node->links[index] = NULL;
    }

    /*
     * Return the pointer reference for the allocated node
     */
    return(new_node);
}

/*
 * This function intializes the root node of the trie.
 */
void init_trie_root (struct trienode** root)
{
    /*
     * If the reference to the trie root is NULL, then
     * return
     */
    if (!root) {
        return;
    }

    /*
     * Allocate a new node for this root reference
     */
    *root = make_trienode();
}

/*
 * This function inserts a binary valued matrix rowc in the trie data
 * structure. If the matrix row is not valid, then this function does
 * not add the matrix row in the trie. The time complexity of this
 * function is O(n), where 'n' is the number of entriesin the matrix
 * row. The space complexity of this string is O(1).
 */
void insert_boolean_row_in_trie (struct trienode* root,
                                 int* row, int len)
{
    struct trienode* current;
    int index;

    /*
     * If the root of the trie is not valid or the matrix row
     * is not valid, then return from the function
     */
    if (!root || !row || (len <= 0)) {
        return;
    }

    /*
     * Check if each entry of the matrix is zero or one. If not,
     * simply return from this function
     */
    for (index = 0; index < len; ++index) {
        if ((row[index] != 0) && (row[index] != 1)) {
            return;
        }
    }

    /*
     * Start at the root of the digital trie and add the
     * matrix row in the trie
     */
    current = root;
    for (index = 0; index < len; ++index) {

        if (!(current->links[row[index]])) {
            current->links[row[index]] = make_trienode();
        }

        current = current->links[row[index]];
    }
}

/*
 * This function returns 'true' if the given matrix row is found in the
 * trie and 'false' otherwise. The time complexity of this function
 * is O(n), where 'n' is the number of entries in the matrix row.
 * The space complexity of this string is O(1).
 */
bool search_if_boolean_row_exists_in_trie (struct trienode* root,
                                           int* row, int len)
{
    struct trienode* current;
    int index;

    /*
     * If the root of trie is NULL or if the matrix row is NULL or
     * empty, then return 'false'
     */
    if (!root || !row || (len <= 0)) {
        return(false);
    }

    /*
     * Check if each entry of the matrix is zero or one. If not,
     * simply return 'false' from this function
     */
    for (index = 0; index < len; ++index) {
        if ((row[index] != 0) && (row[index] != 1)) {
            return(false);
        }
    }

    /*
     * Start at the root of the tree and search down in the trie
     * for the matrix row
     */
    current = root;
    for (index = 0; index < len; ++index) {

        /*
         * If the child node is NULL, then the current
         * entry does not exist in the trie, so return
         * 'false'
         */
        if (!(current->links[row[index]])) {
            return(false);
        }

        /*
         * Move to the child node
         */
        current = current->links[row[index]];
    }

    /*
     * Return 'true' since the matrix row is found in the trie
     */
    return(true);
}

/*
 * This function walks and frees a trie rooted at 'root' recursively.
 */
void walk_and_free_trie (struct trienode** root)
{
    int index;

    if (!root) {
        return;
    }

    /*
     * If de-reference to the root node is valid, then recursively
     * walk the child nodes and free them. Once done freeing the child
     * nodes, free the root node.
     */
    if (*root) {

        for (index = 0; index < MAX_BOOLEAN_VALUES; ++index) {
            walk_and_free_trie(&((*root)->links[index]));
        }

        free(*root);
    }
}

/*
 * This function returns the number of unique rows in a binary valued matrix.
 * The time complexity of this function is O(m * n), where 'm' is the
 * number of rows in the matrix and 'n' is the number of cols in the matrix.
 * The space complexity of this function is approximately O(m * n) since we
 * are using s trie to drive the algorithm.
 */
int get_num_unique_rows_in_matrix_v2 (int rows, int cols, int matrix[][cols])
{
    int row, num_unique;
    struct trienode* root = NULL;

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
    init_trie_root(&root);

    /*
     * If the allocation of the trie node fails, then return zero.
     */
    if (!root) {
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
        if (!search_if_boolean_row_exists_in_trie(
                                    root, matrix[row], cols)) {
            ++num_unique;
            insert_boolean_row_in_trie(root, matrix[row], cols);
        }
    }

    /*
     * Walk and free the trie
     */
    walk_and_free_trie(&root);

    /*
     * Return the number of unique rows in the matrix
     */
    return(num_unique);
}

int main ()
{
    /*
     * Test 0: Test the case, when some rows in the matrix are unque and
     *         some are not unique.
     */
    int matrix0[][5] =
                        {
                            {0, 1, 0, 0, 1},
                            {1, 0, 1, 1, 0},
                            {0, 1, 0, 0, 1},
                            {1, 1, 1, 0, 0},
                            {0, 1, 0, 0, 1},
                            {1, 1, 1, 0, 0},
                            {0, 1, 0, 0, 1}
                        };
    int cols0 = sizeof(matrix0[0])/sizeof(int);
    int rows0 = sizeof(matrix0)/sizeof(matrix0[0]);
    assert(3 == get_num_unique_rows_in_matrix_v1(rows0, cols0, matrix0));
    assert(3 == get_num_unique_rows_in_matrix_v2(rows0, cols0, matrix0));

    /*
     * Test 1: Test the case, when only one of the rows in the matrix is
     *         unique.
     */
    int matrix1[][7] =
                        {
                            {1, 1, 0, 0, 1, 0, 0},
                            {1, 1, 0, 0, 1, 0, 0},
                            {1, 1, 0, 0, 1, 0, 0},
                            {1, 1, 0, 0, 1, 0, 0},
                            {1, 1, 0, 0, 1, 0, 0},
                            {1, 1, 0, 0, 1, 0, 0},
                            {1, 1, 0, 0, 1, 0, 0}
                        };
    int cols1 = sizeof(matrix1[0])/sizeof(int);
    int rows1 = sizeof(matrix1)/sizeof(matrix1[0]);
    assert(1 == get_num_unique_rows_in_matrix_v1(rows1, cols1, matrix1));
    assert(1 == get_num_unique_rows_in_matrix_v2(rows1, cols1, matrix1));

    /*
     * Test 2: Test the case, when only all the rows in the matrix are
     *         unique.
     */
    int matrix2[][5] =
                        {
                            {0, 1, 0, 0, 1},
                            {1, 0, 0, 1, 0},
                            {0, 0, 0, 0, 1},
                            {1, 1, 1, 0, 0}
                        };
    int cols2 = sizeof(matrix2[0])/sizeof(int);
    int rows2 = sizeof(matrix2)/sizeof(matrix2[0]);
    assert(rows2 == get_num_unique_rows_in_matrix_v1(rows2, cols2, matrix2));
    assert(rows2 == get_num_unique_rows_in_matrix_v2(rows2, cols2, matrix2));

    /*
     * Test 3: Test the case, when there is only one row in the matrix.
     */
    int matrix3[][10] =
                        {
                            {0, 1, 0, 0, 1, 0, 0, 0, 1, 0}
                        };
    int cols3 = sizeof(matrix3[0])/sizeof(int);
    int rows3 = sizeof(matrix3)/sizeof(matrix3[0]);
    assert(rows3 == get_num_unique_rows_in_matrix_v1(rows3, cols3, matrix3));
    assert(rows3 == get_num_unique_rows_in_matrix_v2(rows3, cols3, matrix3));

    /*
     * Test 4: Test the case, when there is only one column in the matrix.
     */
    int matrix4[][1] =
                        {
                            {0},
                            {1},
                            {0},
                            {0},
                            {1}
                        };
    int cols4 = sizeof(matrix4[0])/sizeof(int);
    int rows4 = sizeof(matrix4)/sizeof(matrix4[0]);
    assert(2 == get_num_unique_rows_in_matrix_v1(rows4, cols4, matrix4));
    assert(2 == get_num_unique_rows_in_matrix_v2(rows4, cols4, matrix4));

    return(0);
}
