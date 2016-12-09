/*
 * This program finds the binamial cofficient C(n,r) mod 104,395,303, where
 * 'n' is a positive number greater than zero and 'r' is greater than or
 * equal to zero. For more information on this problem, please refer to the
 * following link:- http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
 * Define the large prime number
 */
#define LARGE_PRIME 104395303

/*
 * This function returns the binomial cofficient C(n,r) mod 104395303. If
 * the values of 'n' and 'r' are not valid, then this function returns 0.
 * This function uses memoization technique of dynamic programming for
 * getting the binomial cofficient. The time complexity of this function
 * is O(n*r). The space complexity of this function is O(n * r).
 */
int get_binomial_cofficient (int n, int r)
{
    int** matrix;
    int i, j, binomial_coff;

    /*
     * If the following holds true, then return zero:-
     * 1. If 'n' is less than or equal to zero
     * 2. If 'r' is less than zero
     * 3. If 'n' is less than 'r'
     */
    if ((n <= 0) || (r < 0) || (n < r)) {
        return(0);
    }

    /*
     * Allocate a matrix of 'n + 1' rows and 'r + 1' columns
     */
    matrix = (int**)malloc(sizeof(int*) * (n + 1));

    /*
     * If matrix allocation fails, then return zero.
     */
    if (!matrix) {
        return(0);
    }

    /*
     * Allocate rows of length 'r + 1'
     */
    for (i = 0; i <= n; ++i) {
        matrix[i] = (int*)malloc(sizeof(int) * (r + 1));

        /*
         * If the allocation of a row fails, then free the
         * previously allocated rows and return zero
         */
        if (!matrix[i]) {
            for (j = 0; j < i; ++j) {
                free(matrix[j]);
            }

            free(matrix);

            return(0);
        }
    }

    /*
     * Set the initial values in the matrix. C(i, 0) is one
     * so set the first column of the matrix to one.
     */
    for (i = 1; i <= n; ++i) {
        matrix[i][0] = 1;
    }

    /*
     * C(i, i) is one so set all diagonal elements to one
     */
    for (i = 1; i <= r; ++i) {
        matrix[i][i] = 1;
    }

    /*
     * Iterate over all the matrix elements and set the
     * binomial cofficient values
     */
    for (i = 2; i <= n; ++i) {
        for (j = 1; ((j <= r) && (j <= i)); ++j) {

            /*
             * We needn't recompute C(i, i) again, as we computed
             * this earlier
             */
            if (j == i) {
                continue;
            }

            /*
             * The binomial cofficient for C(i, j) is computed by
             * the following recurrence relationship:-
             * C(i , j) = C(i - 1, j - 1) + C(i - 1, j)
             *
             * The modulus operator for addition of two numbers is
             * spread in the following manner:-
             * (a + b) % m = (a % m + b % m) % m
             */
            matrix[i][j] = ((matrix[i - 1][j - 1] % LARGE_PRIME) +
                            (matrix[i - 1][j] % LARGE_PRIME)) %
                            LARGE_PRIME;
        }
    }

    /*
     * Pick the last matrix entry for getting the value
     * C(n, r)
     */
    binomial_coff = matrix[n][r];

    /*
     * Free the allocated memory for the matrix
     */
    for (i = 0; i <= n; ++i) {
        free(matrix[i]);
    }

    free(matrix);

    /*
     * Return the value of the binomial cofficient
     */
    return(binomial_coff);
}

int main ()
{
    /*
     * Test 0: Test the negative test cases for the values of
     *         'n' and 'r'. The return value from the function
     *         computing the binomial cofficient should be zero.
     */
    assert(0 == get_binomial_cofficient(0, 0));
    assert(0 == get_binomial_cofficient(-10, 0));
    assert(0 == get_binomial_cofficient(20, -10));
    assert(0 == get_binomial_cofficient(20, 100));

    /*
     * Test 1: Test the case of C(n, 0). The return value from
     *         the function computing the binomial cofficient
     *         should be one.
     */
    assert(1 == get_binomial_cofficient(1, 0));
    assert(1 == get_binomial_cofficient(2, 0));
    assert(1 == get_binomial_cofficient(3, 0));
    assert(1 == get_binomial_cofficient(100, 0));

    /*
     * Test 2: Test the case of C(n, n). The return value from
     *         the function computing the binomial cofficient
     *         should be one.
     */
    assert(1 == get_binomial_cofficient(1, 1));
    assert(1 == get_binomial_cofficient(2, 2));
    assert(1 == get_binomial_cofficient(3, 3));
    assert(1 == get_binomial_cofficient(100, 100));

    /*
     * Test 3: Test the case of C(n, 1). The return value from
     *         the function computing the binomial cofficient
     *         should be 'n'.
     */
    assert(1 == get_binomial_cofficient(1, 1));
    assert(2 == get_binomial_cofficient(2, 1));
    assert(3 == get_binomial_cofficient(3, 1));
    assert(100 == get_binomial_cofficient(100, 1));

    /*
     * Test 4: Test the case of C(n, n-1). The return value from
     *         the function computing the binomial cofficient
     *         should be 'n'.
     */
    assert(1 == get_binomial_cofficient(1, 1 - 1));
    assert(2 == get_binomial_cofficient(2, 2 - 1));
    assert(3 == get_binomial_cofficient(3, 3 - 1));
    assert(100 == get_binomial_cofficient(100, 100 - 1));

    /*
     * Test 5: Test all the values of C(n, 0), C(n, 1), C(n, 2)..
     *         C(n, n) for a given 'n'.
     */
    assert(1 == get_binomial_cofficient(6, 0));
    assert(6 == get_binomial_cofficient(6, 1));
    assert(15 == get_binomial_cofficient(6, 2));
    assert(20 == get_binomial_cofficient(6, 3));
    assert(15 == get_binomial_cofficient(6, 4));
    assert(6 == get_binomial_cofficient(6, 5));
    assert(1 == get_binomial_cofficient(6, 6));

    return(0);
}
