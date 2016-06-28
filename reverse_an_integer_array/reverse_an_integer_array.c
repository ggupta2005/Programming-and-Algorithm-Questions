/*
 * The following program reverses an array
 */

#include<stdio.h>
#include<string.h>
#include<assert.h>

/*
 * This function reverses an integer array in linear time (O(n)).
 */
void reverse (int* array, int num)
{
    int left;
    int right;
    int temp;

    /*
     * If the array pointer is NULL, then return from the function
     */
    if (!array) {
        return;
    }

    /*
     * If the number of array elements is less than zero, then return
     * from the function
     */
    if (num < 0) {
        return;
    }

    left = 0;
    right = num -1;

    /*
     * Iterate while 'left' is less than 'right'
     */
    while (left < right) {

        /*
         * Swap the array elements using a temporary variable.
         */
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        /*
         * Increment the 'left' and decrement the 'right'
         * counter.
         */
        ++left;
        --right;
    }
}

int main()
{
    /*
     * Test case: 1
     */
    int array_test_1[] = {};
    int array_expect_1[] = {};
    reverse(array_test_1, sizeof(array_test_1)/sizeof(int));
    assert(memcmp(array_test_1, array_expect_1,
                  sizeof(array_test_1)) == 0);

    /*
     * Test case: 2
     */
    int array_test_2[] = {1,4,5};
    int array_expect_2[] = {5,4,1};
    reverse(array_test_2, sizeof(array_test_2)/sizeof(int));
    assert(memcmp(array_test_2, array_expect_2,
                  sizeof(array_test_2)) == 0);

    /*
     * Test case: 3
     */
    int array_test_3[] = {1,4,5,9,2,4};
    int array_expect_3[] = {4,2,9,5,4,1};
    reverse(array_test_3, sizeof(array_test_3)/sizeof(int));
    assert(memcmp(array_test_3, array_expect_3,
                  sizeof(array_test_3)) == 0);

    /*
     * Test case: 4
     */
    int* array_test_4 = NULL;
    int* array_expect_4 = NULL;
    reverse(array_test_4, sizeof(array_test_4)/sizeof(int));
    assert(memcmp(array_test_4, array_expect_4,
                  0) == 0);

    /*
     * Test case: 5
     */
    int array_test_5[] = {1,4,5,9,2,4};
    int array_expect_5[] = {1,4,5,9,2,4};
    reverse(array_test_5, -6);
    assert(memcmp(array_test_5, array_expect_5,
                  sizeof(array_test_5)) == 0);

    /*
     * Test case: 6
     */
    int array_test_6[] = {1,4,5,9,2,4};
    int array_expect_6[] = {1,4,5,9,2,4};
    reverse(array_test_6, 0);
    assert(memcmp(array_test_6, array_expect_6,
                  sizeof(array_test_6)) == 0);

    return 0;
}
