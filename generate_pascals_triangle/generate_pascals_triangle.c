/*
 * This program generates first 'n' rows of Pascals's Triangle.
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

/*
 * This function returns the 'num' rows of a Pascal's Triangle. If 'num'
 * less than or equal to zero, then this function returns NULL. The time
 * complexity of this function is O(n^2), where 'n' is the number of rows
 * in the Pascal's Triangle. The space complexity of this function is
 * O(n^2), where 'n' is the number of rows in the Pascal's Triangle.
 */
int** get_pascals_triangle (int num)
{
    int index, inner_index;
    int** pascals_triangle;

    /*
     * If 'num' is less than or equal to zero, then return NULL
     */
    if (num <= 0) {
        return(NULL);
    }

    /*
     * Allocate 'num' rows for Pascal's Triangle
     */
    pascals_triangle = (int**)malloc(sizeof(int*) * num);

    /*
     * If memory allocation fails, then return NULL
     */
    if (!pascals_triangle) {
        return(NULL);
    }

    /*
     * Allocate memory for each of the rows for the Pascal's Triangle
     */
    for (index = 0; index < num; ++index) {

        /*
         * Allocate memory according to the number of entries in a row
         * in the triangle
         */
        pascals_triangle[index] =
                (int*)malloc(sizeof(int) * (index + 1));

        /*
         * If the memory allocation fails, then free all the previously
         * allocated memory and return NULL
         */
        if (!pascals_triangle[index]) {

            /*
             * Free the previously allocated rows
             */
            for (inner_index = 0; inner_index < index; ++inner_index) {
                free(pascals_triangle[inner_index]);
            }

            /*
             * Free the allocated row pointers
             */
            free(pascals_triangle);
            return(NULL);
        }
    }

    /*
     * Set the only element of the first row to one
     */
    pascals_triangle[0][0] = 1;

    /*
     * Iterate through the rest of the rows and populate
     * the Pascal's Triangle
     */
    for (index = 1; index < num; ++index) {

        /*
         * Populate a given row of the triangle
         */
        for (inner_index = 0; inner_index < (index + 1);
             ++inner_index) {

            if (inner_index == 0) {

                /*
                 * Copy the first element of the previous row in the
                 * zeroth element of the current row
                 */
                pascals_triangle[index][0] = pascals_triangle[index - 1][0];
            } else if (inner_index == index) {

                /*
                 * Copy the last element of the previous row in the
                 * last element of the current row
                 */
                pascals_triangle[index][inner_index] =
                                pascals_triangle[index - 1][inner_index - 1];
            } else {

                /*
                 * For the rest of the elements, sum the adjacent numbers
                 * in the previous row
                 */
                pascals_triangle[index][inner_index] =
                                pascals_triangle[index - 1][inner_index - 1] +
                                pascals_triangle[index - 1][inner_index] ;
            }
        }
    }

    /*
     * Return the Pascal's Triangle
     */
    return(pascals_triangle);
}

/*
 * This function checks if the two Pascal's Triangles of 'num' rows are
 * same or not. If the two Pascal's Triangle are same, then this function
 * returns 'true' otherwise this function returns 'false'. The time
 * complexity of this function is O(n^2), where 'n' is the number of rows
 * in the Pascal's Triangle. The space complexity of this function is
 * O(n^2), where 'n' is the number of rows in the Pascal's Triangle.
 */
bool check_if_equal_pascals_triangles (int num, int exp[][num], int** act)
{
    int index;

    /*
     * If either of the Pascal's Triangle are invalid or the
     * number of rows in the Pascal's Triangles is invalid, then
     * return 'false'
     */
    if (!exp || !act || (num <= 0)) {
        return(false);
    }

    /*
     * Compare each of the rows in the two Pascal's Triangles
     */
    for (index = 0; index < num; ++index) {

        /*
         * If either of the rows are NULL, then return 'false'
         */
        if (!exp[index] || !act[index]) {
            return(false);
        }

        /*
         * If the entries in the two array rows are not same, then
         * return 'false'
         */
        if (memcmp(exp[index], act[index], sizeof(int) * (index + 1))) {
            return(false);
        }
    }

    /*
     * Since the two Pascal's Triangles are same, so return
     * 'true'
     */
    return(true);
}

int main ()
{
    /*
     * Test 0: If the number of rows is not valid, then the Pascal's
     *         Triangle should be NULL.
     */
    int** act_pt0 = get_pascals_triangle(0);
    int** exp_pt0 = NULL;
    assert(act_pt0 == exp_pt0);

    /*
     * Test 1: Test a Pascal's Triangle having one row.
     */
    int** act_pt1 = get_pascals_triangle(1);
    int exp_pt1[][1] = {
                    {1}
                  };
    assert(check_if_equal_pascals_triangles(1, exp_pt1, act_pt1));

    /*
     * Test 2: Test a Pascal's Triangle having two rows.
     */
    int** act_pt2 = get_pascals_triangle(2);
    int exp_pt2[][2] = {
                    {1},
                    {1, 1}
                  };
    assert(check_if_equal_pascals_triangles(2, exp_pt2, act_pt2));

    /*
     * Test 3: Test a Pascal's Triangle having three rows.
     */
    int** act_pt3 = get_pascals_triangle(3);
    int exp_pt3[][3] = {
                    {1},
                    {1, 1},
                    {1, 2, 1}
                  };
    assert(check_if_equal_pascals_triangles(3, exp_pt3, act_pt3));

    /*
     * Test 4: Test a Pascal's Triangle having four rows.
     */
    int** act_pt4 = get_pascals_triangle(4);
    int exp_pt4[][4] = {
                    {1},
                    {1, 1},
                    {1, 2, 1},
                    {1, 3, 3, 1}
                  };
    assert(check_if_equal_pascals_triangles(4, exp_pt4, act_pt4));

    /*
     * Test 5: Test a Pascal's Triangle having ten rows.
     */
    int** act_pt5 = get_pascals_triangle(10);
    int exp_pt5[][10] = {
                    {1},
                    {1, 1},
                    {1, 2, 1},
                    {1, 3, 3, 1},
                    {1, 4 ,6, 4, 1},
                    {1, 5, 10, 10, 5, 1},
                    {1, 6, 15, 20, 15, 6, 1},
                    {1, 7, 21, 35, 35, 21, 7, 1},
                    {1, 8, 28, 56, 70, 56, 28, 8, 1},
                    {1, 9, 36, 84, 126, 126, 84, 36, 9, 1}
                  };
    assert(check_if_equal_pascals_triangles(10, exp_pt5, act_pt5));

    return(0);
}
