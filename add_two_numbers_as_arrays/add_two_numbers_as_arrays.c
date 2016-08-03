/*
 * This program adds two numbers represented as integer arrays. The
 * elements of these integer arrays can only be numbers from 0-9 and
 * the leading digit of the array will be non-zero. For example, if
 * the two integer arrays are {4,5,6} and {2,3,4}, then the sum of the
 * integer array will be {6,9,0}. Another example, if the two integer
 * arrays are {1,2,3} and {9,9,9}, then the summ array will be
 * {1.1,2,2}
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<string.h>

/*
 * This function takes two integer number arrays and their lengths and
 * populates the 'sum' array with the sum of the two number arrays. It
 * also populates the 'sum_len' with the number of digits in the sum
 * array. The time complexity of this function is O(n), where 'n' is
 * number of digits in the number arrays.
 */
void add_two_integer_arrays (int* num1, int len1, int* num2, int len2,
                             int** sum, int* sum_len)
{
    int i, j, k;
    int carry;
    int* new_sum;

    /*
     * In case of error conditions, set the default values of the
     * sum array and its length and return
     */
    if ((!num1 && !num2) || ((len1 <= 0) && (len2 <= 0))
        || !sum || !sum_len) {

        if (sum) {
            *sum = NULL;
        }

        if (sum_len) {
            *sum_len = 0;
        }

        return;
    }

    /*
     * We set the length of the sum array as one greater than the
     * maximum legal length to take care of the carry over scenario
     */
    if (num1 && num2) {

        /*
         * If both number arrays are legal, then set the length of
         * the sum array as higher length of the two number arrays.
         */
        *sum_len = (len1 > len2) ? (len1 + 1):(len2 + 1);
    } else if (num1) {

        /*
         * If only the first number array is legal, then set the length
         * of the sum array as the length of the first array
         */
        *sum_len = len1 + 1;
    } else {

        /*
         * If only the second number array is legal, then set the length
         * of the sum array as the length of the second array
         */
        *sum_len = len2 + 1;
    }

    /*
     * Allocate the sum array
     */
    *sum = (int*)malloc(sizeof(int) * (*sum_len));

    if (!(*sum)) {

        /*
         * If the allocation of sum array failes, then set the length of
         * sum array to zero and return
         */
        *sum_len = 0;
        return;
    }

    /*
     * Clear the sum array
     */
    memset(*sum, 0, sizeof(int) * (*sum_len));

    /*
     * Set the appropriate value of the index into the first array.
     */
    if (num1) {

        /*
         * We set the index into the first array as the last index in
         * first array because the LSB is the last element in the first
         * array
         */
        i = len1 - 1;
    } else {

        /*
         * If the first array is not legal, then set the index to -1
         */
        i = -1;
    }

    /*
     * Set the appropriate value of the index into the second array.
     */
    if (num2) {

        /*
         * We set the index into the second array as the last index in
         * second array because the LSB is the last element in the second
         * array
         */
        j = len2 - 1;
    } else {

        /*
         * If the second array is not legal, then set the index to -1
         */
        j = -1;
    }

    /*
     * Set the index into the sum array at the LSB
     */
    k = (*sum_len) - 1;

    /*
     * Set the value of carry to zero
     */
    carry = 0;

    /*
     * Iterate through the number arrays until the indexes are legal
     */
    while ((i >= 0) && (j >= 0)) {

        /*
         * Set the sum and the carry variables
         */
        (*sum)[k] = (num1[i] + num2[j] + carry) % 10;
        carry = (num1[i] + num2[j] + carry) / 10;

        /*
         * Decrement the indexes
         */
        --i;
        --j;
        --k;
    }

    /*
     * Iterate though the first array until the index into the
     * first array is legal
     */
    while (i >= 0) {
        (*sum)[k] = (num1[i] + carry) % 10;
        carry = (num1[i] + carry) / 10;

        --i;
        --k;
    }

    /*
     * Iterate though the second array until the index into the
     * second array is legal
     */
    while (j >= 0) {
        (*sum)[k] = (num2[j] + carry) % 10;
        carry = (num2[j] + carry) / 10;

        --j;
        --k;
    }

    if (carry > 0) {

        /*
         * If carry is greater than zero, then set the MSB in sum array
         * as carry
         */
        *sum[0] = carry;
    } else {

        /*
         * In this case, the sum can fit into the length of the larger
         * number array, so allocate an integer array with the length of
         * the larger length and copy the elements from the sum array into
         * the new sum array
         */
        *sum_len = *sum_len - 1;
        new_sum = (int*)malloc(sizeof(int) * (*sum_len));

        if (!new_sum) {

            /*
             * If the memory allocation fails then free sum array and set
             * its length to zero
             */
            free(*sum);
            *sum_len = 0;
            return;
        } else {

            /*
             * Copy the old sum array into the new sum array
             */
            for (i = 1; i < ((*sum_len) + 1); ++i) {
                new_sum[i - 1] = (*sum)[i];
            }

            /*
             * Free the old sum array
             */
            free(*sum);

            /*
             * Point the sum array to new sum array
             */
            *sum = new_sum;
        }
    }
}

/*
 * This function prints an integer array on the console element by
 * element.
 */
void print_array (int* array, int len, char* array_name)
{
    int i;

    /*
     * If 'array' or 'array_name' pointers are NULL or the length
     * of the integer array is illegal, then return from the function
     */
    if (!array || (len <= 0) || !array_name) {
        return;
    }

    printf("Printing array %s\n", array_name);

    /*
     * Iterate through the array and print one element at a time
     */
    i = 0;
    while (i < len) {
        printf("%d ", array[i]);
        ++i;
    }

    printf("\n");
}

int main ()
{
    /*
     * Test 0: Test with NULL number arrays. The sum array should be
     *         NULL and its length should be 0 after calling the function
     *         to add the number arrays.
     */
    int* first0 = NULL;
    int first_len0 = 10;
    int* second0 = NULL;
    int second_len0 = 10;
    int* expected_sum0 = NULL;
    int expected_len0 = 0;
    int* actual_sum0 = NULL;
    int actual_len0 = 0;
    add_two_integer_arrays(first0, first_len0, second0, second_len0,
                           &actual_sum0, &actual_len0);

    assert(actual_sum0 == expected_sum0);
    assert(expected_len0 == actual_len0);

    /*
     * Test 1: Test with number arrays having illegal lengths. The sum array
     *         should be NULL and its length should be 0 after calling the
     *         function to add the number arrays.
     */
    int first1[] = {1};
    int first_len1 = 0;
    int* second1 = {0};
    int second_len1 = -10;
    int* expected_sum1 = NULL;
    int expected_len1 = 0;
    int* actual_sum1 = NULL;
    int actual_len1 = 0;
    add_two_integer_arrays(first1, first_len1, second1, second_len1,
                           &actual_sum1, &actual_len1);

    assert(actual_sum1 == expected_sum1);
    assert(expected_len1 == actual_len1);

    /*
     * Test 2: Test with number arrays having zero lengths. The sum array
     *         should be NULL and its length should be 0 after calling the
     *         function to add the number arrays.
     */
    int first2[] = {};
    int first_len2 = sizeof(first2)/sizeof(int);
    int second2[] = {};
    int second_len2 = sizeof(second2)/sizeof(int);
    int* expected_sum2 = NULL;
    int expected_len2 = 0;
    int* actual_sum2 = NULL;
    int actual_len2 = 0;
    add_two_integer_arrays(first2, first_len2, second2, second_len2,
                           &actual_sum2, &actual_len2);

    assert(actual_sum2 == expected_sum2);
    assert(expected_len2 == actual_len2);

    /*
     * Test 3: Test with the second number array having zero length. The
     *         sum array should be same as the first number array which has
     *         non-zero length after the call to function to add the number
     *         arrays.
     */
    int first3[] = {1,2,3};
    int first_len3 = sizeof(first3)/sizeof(int);
    int second3[] = {};
    int second_len3 = sizeof(second3)/sizeof(int);
    int expected_sum3[] = {1,2,3};
    int expected_len3 = sizeof(expected_sum3)/sizeof(int);
    int* actual_sum3 = NULL;
    int actual_len3 = 0;
    add_two_integer_arrays(first3, first_len3, second3, second_len3,
                           &actual_sum3, &actual_len3);

    assert(0 == memcmp(actual_sum3, expected_sum3,
                       expected_len3 * sizeof(int)));
    assert(expected_len3 == actual_len3);

    /*
     * Test 4: Test with the second number array being NULL. The sum array
     *         should be same as the first number array which has non-zero
     *         length after the call to function to add the number arrays.
     */
    int first4[] = {1,2,3};
    int first_len4 = sizeof(first4)/sizeof(int);
    int* second4 = NULL;
    int second_len4 = 10;
    int expected_sum4[] = {1,2,3};
    int expected_len4 = sizeof(expected_sum4)/sizeof(int);
    int* actual_sum4 = NULL;
    int actual_len4 = 0;
    add_two_integer_arrays(first4, first_len4, second4, second_len4,
                           &actual_sum4, &actual_len4);

    assert(0 == memcmp(actual_sum4, expected_sum4,
                       expected_len4 * sizeof(int)));
    assert(expected_len4 == actual_len4);

    /*
     * Test 5: Test with the first number array having zero length. The
     *         sum array should be same as the second number array which has
     *         non-zero length after the call to function to add the number
     *         arrays.
     */
    int first5[] = {};
    int first_len5 = sizeof(first5)/sizeof(int);
    int second5[] = {1,2,3};
    int second_len5 = sizeof(second5)/sizeof(int);
    int expected_sum5[] = {1,2,3};
    int expected_len5 = sizeof(expected_sum5)/sizeof(int);
    int* actual_sum5 = NULL;
    int actual_len5 = 0;
    add_two_integer_arrays(first5, first_len5, second5, second_len5,
                           &actual_sum5, &actual_len5);

    assert(0 == memcmp(actual_sum5, expected_sum5,
                       expected_len5 * sizeof(int)));
    assert(expected_len5 == actual_len5);

    /*
     * Test 6: Test with the first number array being NULL. The sum array
     *         should be same as the second number array which has non-zero
     *         length after the call to function to add the number arrays.
     */
    int* first6 = NULL;
    int first_len6 = 10;
    int second6[] = {1,2,3};
    int second_len6 = sizeof(second6)/sizeof(int);
    int expected_sum6[] = {1,2,3};
    int expected_len6 = sizeof(expected_sum6)/sizeof(int);
    int* actual_sum6 = NULL;
    int actual_len6 = 0;
    add_two_integer_arrays(first6, first_len6, second6, second_len6,
                           &actual_sum6, &actual_len6);

    assert(0 == memcmp(actual_sum6, expected_sum6,
                       expected_len6 * sizeof(int)));
    assert(expected_len6 == actual_len6);

    /*
     * Test 7: Both the number arrays first and second are legal number
     *         arrays. The sum of the number arrays does not result in
     *         additional MSB digit.
     */
    int first7[] = {1,9,9};
    int first_len7 = sizeof(first7)/sizeof(int);
    int second7[] = {1,2,3};
    int second_len7 = sizeof(second7)/sizeof(int);
    int expected_sum7[] = {3,2,2};
    int expected_len7 = sizeof(expected_sum7)/sizeof(int);
    int* actual_sum7 = NULL;
    int actual_len7 = 0;
    add_two_integer_arrays(first7, first_len7, second7, second_len7,
                           &actual_sum7, &actual_len7);

    assert(0 == memcmp(actual_sum7, expected_sum7,
                       sizeof(int) * expected_len7));
    assert(expected_len7 == actual_len7);

    /*
     * Test 8: Both the number arrays first and second are legal number
     *         arrays. The sum of the number arrays does result
     *         in additional MSB digit.
     */
    int first8[] = {9,9,9};
    int first_len8 = sizeof(first8)/sizeof(int);
    int second8[] = {1,2,3};
    int second_len8 = sizeof(second8)/sizeof(int);
    int expected_sum8[] = {1,1,2,2};
    int expected_len8 = sizeof(expected_sum8)/sizeof(int);
    int* actual_sum8 = NULL;
    int actual_len8 = 0;
    add_two_integer_arrays(first8, first_len8, second8, second_len8,
                           &actual_sum8, &actual_len8);

    assert(0 == memcmp(actual_sum8, expected_sum8,
                       sizeof(int) * expected_len8));
    assert(expected_len8 == actual_len8);

    /*
     * Test 9: Both the number arrays first and second are legal number
     *         arrays. The number arrays have different lengths. The
     *         length of first array is greater than second array
     */
    int first9[] = {9,9,9};
    int first_len9 = sizeof(first9)/sizeof(int);
    int second9[] = {3};
    int second_len9 = sizeof(second9)/sizeof(int);
    int expected_sum9[] = {1,0,0,2};
    int expected_len9 = sizeof(expected_sum9)/sizeof(int);
    int* actual_sum9 = NULL;
    int actual_len9 = 0;
    add_two_integer_arrays(first9, first_len9, second9, second_len9,
                           &actual_sum9, &actual_len9);

    assert(0 == memcmp(actual_sum9, expected_sum9,
                       sizeof(int) * expected_len9));
    assert(expected_len9 == actual_len9);

    /*
     * Test 10: Both the number arrays first and second are legal number
     *          arrays. The number arrays have different lengths. The
     *          length of first array is greater than second array
     */
    int first10[] = {3};
    int first_len10 = sizeof(first10)/sizeof(int);
    int second10[] = {9,9,9};
    int second_len10 = sizeof(second10)/sizeof(int);
    int expected_sum10[] = {1,0,0,2};
    int expected_len10 = sizeof(expected_sum10)/sizeof(int);
    int* actual_sum10 = NULL;
    int actual_len10 = 0;
    add_two_integer_arrays(first10, first_len10, second10, second_len10,
                           &actual_sum10, &actual_len10);

    assert(0 == memcmp(actual_sum10, expected_sum10,
                       sizeof(int) * expected_len10));
    assert(expected_len10 == actual_len10);

    return(0);
}
