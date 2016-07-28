/*
 * This program checks if the an array of integers contains a pair of
 * integers with a given sum. For more information on the post, please
 * refer to the following link:-
 * http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-
 * numbers-and-another-number-x-determines-whether-or-not-there-exist-two-
 * elements-in-s-whose-sum-is-exactly-x/
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

/*
 * This function partitions the array around a 'pivot' element and returns the
 * index of the pivot element. This function uses the element at index 'high'
 * as the pivot.
 */
int partition (int* array, int low, int high)
{
    int temp, pindex, i, pivot;

    /*
     * Set 'pivot' as the element at index 'high' in the array
     */
    pivot = array[high];

    pindex = low;
    for (i = low; i < high; ++i) {

        /*
         * If the array elemnt is less than pivot element
         * then move the element to the left of the pivot
         */
        if (array[i] < pivot) {
            temp = array[i];
            array[i] = array[pindex];
            array[pindex] = temp;
            ++pindex;
        }
    }

    /*
     * At this point all elements less than 'pivot' are present to
     * the left of 'pindex'. So swap and move the element at 'high'
     * to index 'pindex'
     */
    temp = array[high];
    array[high] = array[pindex];
    array[pindex] = temp;

    /*
     * Return the partition index to the quick sort routine
     */
    return(pindex);
}

/*
 * This function sorts an integer array from indicies 'low' to 'high' in
 * ascending order using quick sort. The tme complexity of this function
 * is O(n*log(n)) is best case and O(n^2) in worst case. Here 'n' is the
 * number of array elements.
 */
void quicksort (int* array, int low, int high)
{
    int partition_index;

    /*
     * If array is NULL or 'low' or 'high' are less than zero, then
     * there is no need to sory the array. So return.
     */
    if (!array || (low < 0) || (high < 0)) {
        return;
    }

    /*
     * If 'low' is less than 'high', partition the array using and recursively
     * sort the parts around the partition index using quick sort
     */
    if (low < high) {
        partition_index = partition(array, low, high);
        quicksort(array, low, partition_index - 1);
        quicksort(array, partition_index + 1, high);
    }
}

/*
 * This function returns 'true' if there exists a pair which when added together gives
 * the 'sum'. If no such pair exists this function returns 'false'. This function takes
 * the following approach to solve the problem:-
 * 1. First sort the array using some quick sort
 * 2. Walk the sorted array from left and right to check if some pair adds to 'sum'.
 *   a. If the sum of the left and right elements is less than sum, then increment left
 *      index so that we can get more closer to sum.
 *   b. If the sum of the left and right elements is greater than sum, then decrement right
 *      index so that we can get more closer to sum.
 *   c. If the sum of the left and right elements is equal to sum, then return 'true'.
 * 3. IF the 'sum' is not found, then return 'false'.
 * The time complexity of this function is O(n * log(n)) in average case and O(n^2) in worst
 * case since we sort the array using quick sort and then walk the array once. Here 'n' is
 * the number of elements in the array.
 * The space complexity of this function is O(1).
 */
bool check_if_an_array_contains_a_pair_with_given_sum_v1 (int *array, int len,
                                                          int sum)
{
    int left, right;

    /*
     * If either array in NULL or its length is illegal, then return 'false' as
     * we cannot do anagram computation
     */
    if (!array || (len < 0)) {
        return(false);
    }

    /*
     * Sort the array using quick sort
     */
    quicksort(array, 0, len -1);

    /*
     * Set 'left' at index zero and 'right' at index 'len-1'
     */
    left = 0;
    right = len - 1;

    /*
     * Iterate through the array until 'left' is strictly less than 'right'
     */
    while (left < right) {
        if ((array[left] + array[right]) < sum) {

            /*
             * If the sum of the left and right elements is less
             * than sum, then increment left
             */
            ++left;
        } else if ((array[left] + array[right]) > sum) {

            /*
             * If the sum of the left and right elements is greater
             * than sum, then decrement right
             */
            --right;
        } else {

            /*
             * If the sum of the left and right elements is equal to
             * sum, then return 'true'.
             */
            return(true);
        }
    }

    /*
     * Since no such pair having 'sum' was found, so return 'false'
     */
    return(false);
}

int main ()
{
    /*
     * Test 0: Test with a NULL array. The sum cannot be found in a
     *         NULL array.
     */
    int* array0 = NULL;
    int len0 = 10;
    int sum0 = 10;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array0, len0, sum0));

    /*
     * Test 1: Test with an array length which is illegal. The sum cannot
     *         be found in an array whose length is not valid.
     */
    int array1[] = {10, 90, 5, 15};
    int len1 = -10;
    int sum1 = 10;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array1, len1, sum1));

    /*
     * Test 2: Test with an legal array (positive numbers) only and length
     *         in which the desired sum is found
     */
    int array2[] = {10, 90, 5, 15, 100, 85, 95};
    int len2 = sizeof(array2)/sizeof(int);;
    int sum2 = 185;
    assert(true == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array2, len2, sum2));

    /*
     * Test 3: Test with an legal array (positive numbers) only and length
     *         in which the desired sum is not found
     */
    int array3[] = {10, 90, 5, 15, 100, 85, 95};
    int len3 = sizeof(array3)/sizeof(int);;
    int sum3 = 1000;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array3, len3, sum3));

    /*
     * Test 4: Test with an legal array (negative numbers) only and length
     *         in which the desired sum is found
     */
    int array4[] = {-10, -90, -5, -15, -100, -85, -95};
    int len4 = sizeof(array4)/sizeof(int);;
    int sum4 = -105;
    assert(true == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array4, len4, sum4));

    /*
     * Test 5: Test with an legal array (negative numbers) only and length
     *         in which the desired sum is not found
     */
    int array5[] = {-10, -90, -5, -15, -100, -85, -95};
    int len5 = sizeof(array5)/sizeof(int);;
    int sum5 = -109;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array5, len5, sum5));

    /*
     * Test 6: Test with an legal array (positive and negative numbers) only and
     *         length in which the desired sum is found
     */
    int array6[] = {10, -90, 5, -15, 100, -85, -95};
    int len6 = sizeof(array6)/sizeof(int);;
    int sum6 = 10;
    assert(true == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array6, len6, sum6));

    /*
     * Test 7: Test with an legal array (positive and negative numbers) only
     *         and length in which the desired sum is not found
     */
    int array7[] = {10, -90, 5, -15, 100, -85, -95};
    int len7 = sizeof(array7)/sizeof(int);;
    int sum7 = -1090;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array7, len7, sum7));

    return(0);
}
