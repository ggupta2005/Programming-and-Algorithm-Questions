/*
 * This program solves the problem of finding the product array for an
 * array of integers. An element of product array at index 'index' is
 * defined as the product of all the array elements except the element
 * at index 'index'. The condition in this puzzle that we are not allowed
 * to use the division operator and we need to find the product array in
 * O(n) time. For more on this puzzle, refer to the link:-
 * http://www.geeksforgeeks.org/a-product-array-puzzle/
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

/*
 * This function constructs and returns the product array from the
 * given array using the following steps:-
 * 1. It constructs the array containing the running product of all
 *    elements from left to right
 * 2. It constructs the array containing the running product of all
 *    elements from righ to left
 * 3. It constructs the product array for an index 'index' by taking by
 *    following formula:-
 *    product_array[index] = left_array[index] * right_array[index]
 * Time complexity of this function is O(n)
 * Space complexity of this function is O(n)
 */
int* get_product_array (int* array, int len)
{
    int i;
    int* left_product;
    int* right_product;
    int* array_product;

    /*
     * If the array or its length are not valid, then return NULL
     * from this function.
     */
    if (!array || (len <= 0)) {
        return(NULL);
    }

    /*
     * Allocate memory for left running product, right running
     * product and the product array.
     */
    left_product = (int*)malloc(sizeof(int) * len);
    right_product = (int*)malloc(sizeof(int) * len);
    array_product = (int*)malloc(sizeof(int) * len);

    /*
     * If either of the arrays were not allocated successfully,
     * then free all allocated arrays and return NULL from the
     * function.
     */
    if (!left_product || !right_product || !array_product) {
        free(left_product);
        free(right_product);
        free(array_product);
        return(NULL);
    }

    /*
     * Initialize each element of the three arrays to be one.
     */
    for (i = 0; i < len; ++i) {
        left_product[i] = 1;
        right_product[i] = 1;
        array_product[i] = 1;
    }

    /*
     * Get the running product of all elements from left of the
     * array
     */
    for (i = 1; i < len; ++i) {
        left_product[i] = left_product[i-1] * array[i-1];
    }

    /*
     * Get the running product of all elements from right of the
     * array
     */
    for (i = len -2; i >= 0; --i) {
        right_product[i] = right_product[i+1] * array[i+1];
    }

    /*
     * The product array is given by the product of corresponding
     * left and the right product arrays
     */
    for (i = 0; i < len; ++i) {
        array_product[i] = left_product[i] * right_product[i];
    }

    /*
     * Free both the left and right product arrays
     */
    free(left_product);
    free(right_product);

    /*
     * Return the product array
     */
    return(array_product);
}

int main ()
{
    /*
     * Test 0: Test with a valid array
     */
    int array0[] = {10, 3, 5, 6, 2};
    int expected_array0[] = {180, 600, 360, 300, 900};
    int len0 = sizeof(array0)/sizeof(int);
    int* actual_array0 = get_product_array(array0, len0);
    assert(0 == memcmp(expected_array0, actual_array0, len0 * sizeof(int)));

    /*
     * Test 1: Test with a valid array having two elements. The product
     * would contain elements which are inter-changed.
     */
    int array1[] = {10, 3};
    int expected_array1[] = {3, 10};
    int len1 = sizeof(array1)/sizeof(int);
    int* actual_array1 = get_product_array(array1, len1);
    assert(0 == memcmp(expected_array1, actual_array1, len1 * sizeof(int)));

    /*
     * Test 2: Test with a valid array having one element. The product
     *         array should contain only one element and that should be one.
     */
    int array2[] = {10};
    int expected_array2[] = {1};
    int len2 = sizeof(array2)/sizeof(int);
    int* actual_array2 = get_product_array(array2, len2);
    assert(0 == memcmp(expected_array2, actual_array2, len2 * sizeof(int)));

    /*
     * Test 3: Test with a NULL array
     */
    int* array3 = NULL;
    int* expected_array3 = NULL;
    int len3 = 10;
    int* actual_array3 = get_product_array(array3, len3);
    assert(expected_array3 == actual_array3);

    /*
     * Test 4: Test with a illegal length of array
     */
    int array4[] = {10, 20};
    int* expected_array4 = NULL;
    int len4 = -10;
    int* actual_array4 = get_product_array(array4, len4);
    assert(expected_array4 == actual_array4);

    return(0);
}
