/*
 * This program finds the missing number from an array of numbers of size
 * 'n' in which all numbers are within the range 0 to 'n'.
 */
#include<stdio.h>
#include<assert.h>

#define ILLEGAL -1

/*
 * This function finds the missing number from an array of numbers of
 * size 'n' in which all numbers are within the range 0 to 'n'. If the
 * array is not valid, then this function will return '-1'. This
 * function adds all the numbers in [0, 'n'] and then subtracts the sum
 * of all the elements in the array. The time complexity of this function
 * is O(n), where 'n' is the number of array elements. The space
 * complexity of this function is O(1). This function does two paases
 * over all elements in range [0, 'n'].
 */
int find_missing_number_among_0_to_n_v1 (int* array, int len)
{
    int sum, i;

    /*
     * If array is NULL or the length of the array is
     * not valid, then return '-1'.
     */
    if (!array || (len <= 0)) {
        return(ILLEGAL);
    }

    sum = 0;

    /*
     * First add all numbers from 0 to 'len'
     */
    for (i = 0; i <= len; ++i) {
        sum += i;
    }

    /*
     * From the 'sum' subtract the sum of all the
     * array elements
     */
    for (i = 0; i < len; ++i) {
        sum -= array[i];
    }

    /*
     * Return the missing number
     */
    return(sum);
}

/*
 * This function finds the missing number from an array of numbers of
 * size 'n' in which all numbers are within the range 0 to 'n'. If the
 * array is not valid, then this function will return '-1'. This
 * function adds all the numbers in [0, 'n'] and simultaneously subtracts
 * the sum of all the elements in the array. The time complexity of this
 * function is O(n), where 'n' is the number of array elements. The space
 * complexity of this function is O(1). This function does one paases over
 * all elements in range [0, 'n'].
 */
int find_missing_number_among_0_to_n_v2 (int* array, int len)
{
    int sum, i;

    /*
     * If array is NULL or the length of the array is
     * not valid, then return '-1'.
     */
    if (!array || (len <= 0)) {
        return(ILLEGAL);
    }

    sum = 0;

    /*
     * Add all numbers from 0 to 'len' and also subtract
     * the array elements from this 'sum'.
     */
    for (i = 0; i <= len; ++i) {
        sum += i;

        /*
         * If index is less than 'len', then subtract
         * from the sum
         */
        if (i < len) {
            sum -= array[i];
        }
    }

    /*
     * Return the missing number
     */
    return(sum);
}

/*
 * This function finds the missing number from an array of numbers of
 * size 'n' in which all numbers are within the range 0 to 'n'. If the
 * array is not valid, then this function will return '-1'. This
 * function adds all the numbers in [0, 'n'] and simultaneously subtracts
 * the sum of all the elements in the array. The time complexity of this
 * function is O(n), where 'n' is the number of array elements. The space
 * complexity of this function is O(1). This function does one paases over
 * all elements in range [0, 'n'].
 */
int find_missing_number_among_0_to_n_v3 (int* array, int len)
{
    int sum, i;

    /*
     * If array is NULL or the length of the array is
     * not valid, then return '-1'.
     */
    if (!array || (len <= 0)) {
        return(ILLEGAL);
    }

    sum = 0;

    /*
     * Add all numbers from 0 to 'len - 1' and also subtract
     * the array elements from this 'sum'.
     */
    for (i = 0; i < len; ++i) {
        sum += i;
        sum -= array[i];
    }

    /*
     * Add 'len' to the sum
     */
    sum += len;

    /*
     * Return the missing number
     */
    return(sum);
}

/*
 * This function finds the missing number from an array of numbers of
 * size 'n' in which all numbers are within the range 0 to 'n'. If the
 * array is not valid, then this function will return '-1'. This function
 * xors all the numbers in [0, 'n'] and simultaneously xors the elements
 * in the array from the xor of all elements from [0, 'n']. The time
 * complexity of this function is O(n), where 'n' is the number of array
 * elements. The space complexity of this function is O(1). This function
 * does one paases over all elements in range [0, 'n'].
 */
int find_missing_number_among_0_to_n_v4 (int* array, int len)
{
    int sum, i;

    /*
     * If array is NULL or the length of the array is
     * not valid, then return '-1'.
     */
    if (!array || (len <= 0)) {
        return(ILLEGAL);
    }

    sum = 0;

    /*
     * bitwise XOR all numbers from 0 to 'len - 1' and also
     * xor the array elements from this running xor.
     */
    for (i = 0; i < len; ++i) {
        sum ^= i;
        sum ^= array[i];
    }

    /*
     * Bitwise XOR 'len' to the sum
     */
    sum ^= len;

    /*
     * Return the missing number
     */
    return(sum);
}

int main ()
{
    /*
     * Test 0: Test with NULL array and legal length. The missing
     *         element returned should be ILLEGAL.
     */
    int* array0 = NULL;
    int len0 = 10;
    assert(ILLEGAL == find_missing_number_among_0_to_n_v1(array0, len0));
    assert(ILLEGAL == find_missing_number_among_0_to_n_v2(array0, len0));
    assert(ILLEGAL == find_missing_number_among_0_to_n_v3(array0, len0));
    assert(ILLEGAL == find_missing_number_among_0_to_n_v4(array0, len0));

    /*
     * Test 1: Test with valid array but illegal length. The missing
     *         element returned should be ILLEGAL.
     */
    int array1[] = {0, 1, 3};
    int len1 = -10;
    assert(ILLEGAL == find_missing_number_among_0_to_n_v1(array1, len1));
    assert(ILLEGAL == find_missing_number_among_0_to_n_v2(array1, len1));
    assert(ILLEGAL == find_missing_number_among_0_to_n_v3(array1, len1));
    assert(ILLEGAL == find_missing_number_among_0_to_n_v4(array1, len1));

    /*
     * Test 2: Find a missing number from the array which is neither
     *         zero nor the maximum number.
     */
    int array2[] = {0,1,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int len2 = sizeof(array2)/sizeof(int);
    assert(2 == find_missing_number_among_0_to_n_v1(array2, len2));
    assert(2 == find_missing_number_among_0_to_n_v2(array2, len2));
    assert(2 == find_missing_number_among_0_to_n_v3(array2, len2));
    assert(2 == find_missing_number_among_0_to_n_v4(array2, len2));

    /*
     * Test 3: Find a missing number from the array and the missing
     *         number should be zero.
     */
    int array3[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int len3 = sizeof(array3)/sizeof(int);
    assert(0 == find_missing_number_among_0_to_n_v1(array3, len3));
    assert(0 == find_missing_number_among_0_to_n_v2(array3, len3));
    assert(0 == find_missing_number_among_0_to_n_v3(array3, len3));
    assert(0 == find_missing_number_among_0_to_n_v4(array3, len3));

    /*
     * Test 4: Find a missing number from the array and the missing
     *         number should be he maximum number.
     */
    int array4[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int len4 = sizeof(array4)/sizeof(int);
    assert(len4 == find_missing_number_among_0_to_n_v1(array4, len4));
    assert(len4 == find_missing_number_among_0_to_n_v2(array4, len4));
    assert(len4 == find_missing_number_among_0_to_n_v3(array4, len4));
    assert(len4 == find_missing_number_among_0_to_n_v4(array4, len4));

    return(0);
}
