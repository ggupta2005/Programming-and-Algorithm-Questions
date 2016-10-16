/*
 * This program checks if a number is even or odd.
 */
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

/*
 * This function uses the modulo operator to check if a
 * number is even. The time and space complexity of this
 * function is O(1).
 */
bool check_if_num_is_even_v1 (int num)
{
    /*
     * If the remainder when number is divided by two is zero,
     * then return 'true'.
     */
    if ((num % 2) == 0) {
        return(true);
    }

    /*
     * In case of odd numbers return 'false'
     */
    return(false);
}

/*
 * This function uses the bitwise operators to check if a
 * number is even. The time and space complexity of this
 * function is O(1).
 */
bool check_if_num_is_even_v2 (int num)
{
    /*
     * If the zeroth bit in the number is not set, then
     * number is even. So return 'true'.
     */
    if ((num & 1) == 0) {
        return(true);
    }

    /*
     * In case of odd numbers return 'false'
     */
    return(false);
}

int main ()
{
    /*
     * Test 0:  Test with a positive even number. The functions
     *          to test even number should return 'true'.
     */
    assert(true == check_if_num_is_even_v1(2));
    assert(true == check_if_num_is_even_v2(2));

    /*
     * Test 1:  Test with a positive odd number. The functions
     *          to test even number should return 'false'.
     */
    assert(false == check_if_num_is_even_v1(9));
    assert(false == check_if_num_is_even_v2(9));

    /*
     * Test 2:  Test with a negative even number. The functions
     *          to test even number should return 'true'.
     */
    assert(true == check_if_num_is_even_v1(-2));
    assert(true == check_if_num_is_even_v2(-2));

    /*
     * Test 3:  Test with a negative odd number. The functions
     *          to test even number should return 'false'.
     */
    assert(false == check_if_num_is_even_v1(-9));
    assert(false == check_if_num_is_even_v2(-9));

    /*
     * Test 4:  Test with zero. The functions to test even
     *          number should return 'true'.
     */
    assert(true == check_if_num_is_even_v1(0));
    assert(true == check_if_num_is_even_v2(0));

    return(0);
}
