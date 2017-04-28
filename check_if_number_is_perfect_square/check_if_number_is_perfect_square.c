/*
 * This program finds if a positive number is a perfect square.
 */
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<limits.h>

/*
 * This function returns 'true' if a number is a perfect square
 * and 'false' otherwise. This function uses binary search to
 * check if a number is a perfect square with 'long' data type
 * to make sure that the computed square doesn't fall out of
 * range for 'long'. The time complexity of this function is
 * O(log(n)). The space complexity of this function is O(1).
 */
bool if_number_is_perfect_square (int num)
{
    long low, high, mid, num_copy;

    /*
     * If the number is less than zero, then return 'false'
     */
    if (num < 0) {
        return(false);
    }

    /*
     * If the number is equal to zero, then return 'true'
     */
    if (num == 0) {
        return(true);
    }

    low = 1; // Set 'low' to 1
    high = num; // Set 'high' to number
    num_copy = num;

    /*
     * Continue until 'low' is not greater than 'high'
     */
    while (low <= high) {

        /*
         * Compute the 'mid' using the average of 'low'
         * and 'high'
         */
        mid = low + ((high - low) / 2);

        if ((mid * mid) == num_copy) {

            /*
             * If square of 'mid' is same as number, then
             * return 'true'
             */
            return(true);
        } else if ((mid * mid) < num_copy) {

            /*
             * If square of 'mid' is less than the number,
             * then set 'low' to one more than 'mid'
             */
            low = mid + 1;
        } else {

            /*
             * If square of 'mid' is greater than the number,
             * then set 'high' to one less than 'mid'
             */
            high = mid - 1;
        }
    }

    /*
     * If the number is not a perfect square, then return
     * 'false'
     */
    return(false);
}

int main ()
{
    /*
     * Test 0: Test with negative numbers. They should not be
     *         perfect squares.
     */
    assert(false == if_number_is_perfect_square(-1));
    assert(false == if_number_is_perfect_square(INT_MIN));

    /*
     * Test 1: Test with positive numbers which are perfect
     *         squares. They should be perfect squares.
     */
    assert(true == if_number_is_perfect_square(0));
    assert(true == if_number_is_perfect_square(1));
    assert(true == if_number_is_perfect_square(4));
    assert(true == if_number_is_perfect_square(11 * 11));
    assert(true == if_number_is_perfect_square(600 * 600));
    assert(true ==
            if_number_is_perfect_square((1 << 15) *
                                              (1 << 15)));

    /*
     * Test 2: Test with positive numbers which are not perfect
     *         squares. They should not be perfect squares.
     */
    assert(false == if_number_is_perfect_square(2));
    assert(false == if_number_is_perfect_square(INT_MAX));
    assert(false == if_number_is_perfect_square(401));

    return(0);
}
