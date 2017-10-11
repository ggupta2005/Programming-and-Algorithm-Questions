/*
 * This program checks if an integer has an alternate bit pattern. For
 * example, integers 10 (1010) and 5 (0101) have alternate bits set in
 * them. For more information on this problem, please refer to the
 * following link:- http://www.geeksforgeeks.org/check-if-a-number-has-bits-in-alternate-pattern/
 */
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

/*
 * This function returns 'true' if the binary representation of a positive
 * number has alternating bit pattern of zero and one. It returns 'false'
 * otherwise.
 */
bool if_num_has_alternate_bits_set (int n)
{
    bool if_one_expected;

    /*
     * If the input number is less than or equal to zero, then
     * return 'false'.
     */
    if (n <= 0) {
        return(false);
    }

    if (n % 2 == 0) {
        if_one_expected = false;
    } else {
        if_one_expected = true;
    }

    /*
     * Iterate until the number is greater than zero.
     */
    while (n > 0) {

        if (if_one_expected) {

            /*
             * If the LSB is expected to be one but is
             * zero, then return 'false'.
             */
            if ((n & 1) == 0) {
                return(false);
            }

            if_one_expected = false;
        } else {

            /*
             * If the LSB is expected to be zero but is
             * one, then return 'false'.
             */
            if ((n & 1) != 0) {
                return(false);
            }

            if_one_expected = true;
        }

        n >>= 1;
    }

    return(true);
}

int main ()
{
    /*
     * Test 0: Test with some numbers which do not have alternating
     *         bit pattern.
     */
    assert(false == if_num_has_alternate_bits_set(0));
    assert(false == if_num_has_alternate_bits_set(7));
    assert(false == if_num_has_alternate_bits_set(11));

    /*
     * Test 1: Test with some numbers which have alternating bit
     *         pattern.
     */
    assert(true == if_num_has_alternate_bits_set(1));
    assert(true == if_num_has_alternate_bits_set(5));
    assert(true == if_num_has_alternate_bits_set(10));
    assert(true == if_num_has_alternate_bits_set(0x55555555));

    return(0);
}
