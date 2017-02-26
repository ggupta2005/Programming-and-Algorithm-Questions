/*
 * This program checks if a number is a power of eight.
 */
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

/*
 * This function returns 'true' if the 'num' is a power of eight and
 * 'false' otherwise. The function uses bit wise operators to find is
 * a number is a power of eight.
 */
bool if_num_is_power_of_eight_v1 (int num)
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
     * If 'num' is a power of eight, then we need to check if the
     * number of ones in 'num - 1' is divisible by three.
     */
    count_bits_set = 0;

    /*
     * Deduct one from 'num'
     */
    num -= 1;

    /*
     * Loop until num is non-zero
     */
    while (num > 0) {

        /*
         * If the zeroth bit of 'num' is set, then increment the
         * number of bits counter
         */
        if ((num & 1) != 0) {
            ++count_bits_set;
        }

        /*
         * Right shift 'num' by one
         */
        num >>= 1;
    }

    /*
     * Check and return if the number of ones computed is divisible by
     * three
     */
    return((count_bits_set%3) == 0);
}

/*
 * This function returns 'true' if the 'num' is a power of eight and
 * 'false' otherwise. The function uses bit wise operators to find is
 * a number is a power of eight.
 */
bool if_num_is_power_of_eight_v2 (int num)
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
     * Check if after decrementing the number it is divisible by seven.
     * not, then return 'false'
     */
    if (((num - 1) % 7) != 0) {
        return(false);
    }

    return(true);
}

int main ()
{
    /*
     * Test 0: '0' is not a power of eight
     */
    assert(false == if_num_is_power_of_eight_v1(0));
    assert(false == if_num_is_power_of_eight_v2(0));

    /*
     * Test 1: '1' is a power of eight
     */
    assert(true == if_num_is_power_of_eight_v1(1));
    assert(true == if_num_is_power_of_eight_v2(1));

    /*
     * Test 2: '2' is not a power of eight
     */
    assert(false == if_num_is_power_of_eight_v1(2));
    assert(false == if_num_is_power_of_eight_v2(2));

    /*
     * Test 3: '3' is not a power of eight
     */
    assert(false == if_num_is_power_of_eight_v1(3));
    assert(false == if_num_is_power_of_eight_v2(3));

    /*
     * Test 4: '4' is not a power of eight
     */
    assert(false == if_num_is_power_of_eight_v1(4));
    assert(false == if_num_is_power_of_eight_v2(4));

    /*
     * Test 5: '8' is a power of eight
     */
    assert(true == if_num_is_power_of_eight_v1(8));
    assert(true == if_num_is_power_of_eight_v2(8));

    /*
     * Test 6: '32' is not a power of eight
     */
    assert(false == if_num_is_power_of_eight_v1(32));
    assert(false == if_num_is_power_of_eight_v2(32));

    /*
     * Test 7: '64' is a power of eight
     */
    assert(true == if_num_is_power_of_eight_v1(64));
    assert(true == if_num_is_power_of_eight_v2(64));

    /*
     * Test 8: '512' is a power of eight
     */
    assert(true == if_num_is_power_of_eight_v1(512));
    assert(true == if_num_is_power_of_eight_v2(512));

    /*
     * Test 9: '4096' is a power of eight
     */
    assert(true == if_num_is_power_of_eight_v1(4096));
    assert(true == if_num_is_power_of_eight_v2(4096));

    /*
     * Test 10: '-1' is not a power of eight
     */
    assert(false == if_num_is_power_of_eight_v1(-1));
    assert(false == if_num_is_power_of_eight_v2(-1));

    return(0);
}
