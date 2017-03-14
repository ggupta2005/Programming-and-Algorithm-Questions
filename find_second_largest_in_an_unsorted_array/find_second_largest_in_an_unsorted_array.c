/*
 * This program returns the second largest number is an unsorted array of
 * numbers. If the second largest number doesn't exist, then the program
 * returns the largest number in the array.
 */
#include<stdio.h>
#include<assert.h>
#include<limits.h>
#include<stdbool.h>

/*
 * This function returns the second largest number in an unsorted array
 * of numbers. If the second largest number doesn't exist in the array,
 * then this function returns the largest number in the array. The time
 * complexity of this function is O(n), where 'n' is the number of
 * elements in the array.
 */
int get_second_largest_in_array (int* array, int len)
{
    int largest, second_largest;
    int index;
    bool if_second_largest_found;

    /*
     * If the array is not valid or the length of the
     * array is not valid, then return INT_MIN
     */
    if (!array || (len <= 0)) {
        return(INT_MIN);
    }

    /*
     * Set the largest element in the array as the first
     * element in the array
     */
    largest = array[0];
    if_second_largest_found = false;

    /*
     * Iterate from the second element in the array till its end
     */
    for (index = 1; index < len; ++index) {
        if (array[index] > largest) {

            /*
             * If the current element is greater than the largest
             * element, then do the following:-
             * 1. Assign the current largest element to current
             *    second largest.
             * 2. Assign the current array element to the largest
             *    element.
             */
            second_largest = largest;
            largest = array[index];
            if (!if_second_largest_found) {
               if_second_largest_found = true;
            }
        } else if (array[index] < largest) {

            /*
             * If the current element is lesser than the largest
             * element, then update the second largest element
             * if the current array element is greater than the
             * second largest element.
             */
            if (!if_second_largest_found) {
                second_largest = array[index];
                if_second_largest_found = true;
            } else if (array[index] > second_largest) {
                second_largest = array[index];
            }
        }
    }

    /*
     * If the second largest element is found in the array, than
     * return second largest otherwise return the largest array
     * element.
     */
    return(if_second_largest_found ? second_largest : largest);
}

int main ()
{
    /*
     * Test 0: Test with an empty array. The second largest
     *         array element should be INT_MIN.
     */
    int* array0 = NULL;
    int len0 = 10;
    assert(INT_MIN == get_second_largest_in_array(array0, len0));

    /*
     * Test 1: Test with an array having illegal length. The second
     *         largest array element should be INT_MIN.
     */
    int array1[] = {1,2,3,4,5};
    int len1 = -10;
    assert(INT_MIN == get_second_largest_in_array(array1, len1));

    /*
     * Test 2: Test with an array having only one element.
     *         The function should return that element as
     *         largest element in the array.
     */
    int array2[] = {1};
    int len2 = sizeof(array2)/sizeof(int);
    assert(1 == get_second_largest_in_array(array2, len2));

    /*
     * Test 3: Test with an array having one distinct values.
     *         The function should return that value as the largest
     *         element.
     */
    int array3[] = {1,1,1,1,1};
    int len3 = sizeof(array3)/sizeof(int);
    assert(1 == get_second_largest_in_array(array3, len3));

    /*
     * Test 4: Test with an array having four distinct values.
     *         The function should return the second largest
     *         element among the four distinct values.
     */
    int array4[] = {1,1,4,1,1,2,3};
    int len4 = sizeof(array4)/sizeof(int);
    assert(3 == get_second_largest_in_array(array4, len4));

    return(0);
}
