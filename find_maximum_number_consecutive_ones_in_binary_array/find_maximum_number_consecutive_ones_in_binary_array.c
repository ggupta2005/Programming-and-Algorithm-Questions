/*
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 *
 * Example 1:
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 *              1s.
 * The maximum number of consecutive 1s is 3.
 */
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

/*
 * This function returns the maximum number of consecutive ones in a binary
 * array. The time complexity of this function is O(n), where 'n' is the
 * number of elements in the array. The space complexity of the function is
 * O(1).
 */
int find_max_consecutive_ones (int* nums, int numsSize)
{
    int index, max_cons_ones, temp_cons_ones;
    bool if_inside_ones;

    /*
     * If the binary array is not valid or the number of elements
     * in the array is not valid, then return zero.
     */
    if (!nums || (numsSize <= 0)) {
        return(0);
    }

    max_cons_ones = 0;
    temp_cons_ones = 0;
    if_inside_ones = false;

    /*
     * Iterate through the entire array
     */
    for (index = 0; index < numsSize; ++index) {


        if (nums[index] == 1) {

            /*
             * If the current entry in the array is one, then
             * count increment the current number of consecutive
             * ones.
             */
            if (!if_inside_ones) {
                if_inside_ones = true;
            }
            ++temp_cons_ones;
        } else {
            /*
             * If the current entry in the array is zero, then
             * maximum number of consecutive ones.
             */
            if (if_inside_ones) {
                if (temp_cons_ones > max_cons_ones) {
                    max_cons_ones = temp_cons_ones;
                }

                temp_cons_ones = 0;
                if_inside_ones = false;
            }
        }
    }

    if (temp_cons_ones > max_cons_ones) {
        max_cons_ones = temp_cons_ones;
    }

    return(max_cons_ones);
}

int main ()
{
    /*
     * Test 0: The input array has all zeros. So there are no
     *         consecutive ones in the array.
     */
    int array0[] = {0,0,0,0,0};
    int len0 = sizeof(array0)/sizeof(int);
    assert(0 == find_max_consecutive_ones(array0, len0));

    /*
     * Test 1: The input array has all ones. So the maximum number
     *         of consecutive ones in the array should be equal to
     *         the length of the array.
     */
    int array1[] = {1,1,1,1,1};
    int len1 = sizeof(array1)/sizeof(int);
    assert(len1 == find_max_consecutive_ones(array1, len1));

    /*
     * Test 2: The input array has mix of zeros and ones.
     */
    int array2[] = {1,1,0,1,1,1};
    int len2 = sizeof(array2)/sizeof(int);
    assert(3 == find_max_consecutive_ones(array2, len2));

    /*
     * Test 3: The input array has alternating zeros and ones.
     *         The maximum consecutive number of ones in the
     *         array should be one.
     */
    int array3[] = {1,0,1,0,1,0,1};
    int len3 = sizeof(array3)/sizeof(int);
    assert(1 == find_max_consecutive_ones(array3, len3));

    return(0);
}
