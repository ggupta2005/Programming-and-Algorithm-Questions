/*
 * This program checks if a number is a power of four. For more
 * information on this problem, please visit the following link:-
 * http://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/
 */
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

/*
 * This function returns 'true' if the 'num' is a power of four and
 * 'false' otherwise. The function uses bit wise operators to find is
 * a number is a power of four.
 */
bool if_num_is_power_of_four (int num)
{
    int count_bits_set;

    /*
     * If 'num' is less than or equal to zero,
     * then return 'false'
     */
    if (num <= 0) {
        return(false);
    }

    /*
     * Check if 'num' is a power of two. If not, then return
     * 'false'
     */
    if ((num & (num -1)) != 0) {
        return(false);
    }

    /*
     * If 'num' is a power of four, then we need to check if the
     * number of ones in 'num - 1' is even.
     */
    count_bits_set = 0;

    /*
     * Deduct one from 'num'
     */
    num -= 1;

    /*
     * Loop until num is non-zero
     */
    while (num) {

        /*
         * If the zeroth bit of 'num' is set, then increment the
         * number of bits counter
         */
        if (num & 1) {
            ++count_bits_set;
        }

        /*
         * Right shift 'num' by one
         */
        num >>= 1;
    }

    /*
     * Check and return if the number of ones computed is even
     */
    return((count_bits_set%2) == 0);
}

int main ()
{
    /*
     * Test 0: '0' is not a power of four
     */
    assert(false == if_num_is_power_of_four(0));

    /*
     * Test 1: '1' is a power of four
     */
    assert(true == if_num_is_power_of_four(1));

    /*
     * Test 2: '2' is not a power of four
     */
    assert(false == if_num_is_power_of_four(2));

    /*
     * Test 3: '3' is not a power of four
     */
    assert(false == if_num_is_power_of_four(3));

    /*
     * Test 4: '4' is a power of four
     */
    assert(true == if_num_is_power_of_four(4));

    /*
     * Test 5: '16' is a power of four
     */
    assert(true == if_num_is_power_of_four(16));

    /*
     * Test 6: '32' is not a power of four
     */
    assert(false == if_num_is_power_of_four(32));

    /*
     * Test 7: '-1' is not a power of four
     */
    assert(false == if_num_is_power_of_four(-1));

    return(0);
}
