/*
 * This program unsets the kth bit in a given number. For more
 * information on this, please refer to the following post:-
 * http://www.geeksforgeeks.org/how-to-turn-off-a-particular-bit-in-a-number/
 */
#include<stdio.h>
#include<assert.h>

#define BITS_PER_BYTE    8   /* Number of bits per byte */
#define ILLEGAL         ~0   /* Illegal value case unsetting of
                                a bit fails for some reason */

/*
 * This function un-sets the kth bit in a number. The value of 'k'
 * is interpreted as zero based index. So if 'k' is zero, then the
 * first bit in the input number will be set to zero. If the value
 * of 'k' is not legal, then this function returns maximum possible
 * integer value.
 */
unsigned int unset_the_kth_bit_in_a_number (unsigned int num, int k)
{
    /*
     * If 'k' is less than or its value is greater than or equal to
     * the maximum number of bits in the input number, then return
     * ILLEGAL.
     */
    if ((k < 0) || (k >= (BITS_PER_BYTE * sizeof(num)))) {
        return(~0);
    }

    /*
     * Generate the bit mask for the un-setting the kth bit in
     * the number
     */
    unsigned int kth_bit_unset_mask = ~(1 << k);

    /*
     * Return the bitwise and operation of the input number and
     * the bit mask
     */
    return(num & kth_bit_unset_mask);
}

int main ()
{
    /*
     * Test 0: Test with value zero and k equal to one. There is
     *         no bit to un-set in zero, so return value will be
     *         zero
     */
    assert(0 == unset_the_kth_bit_in_a_number(0, 1));

    /*
     * Test 1: Test with value zero and k equal to maximum number
     *         of bits in the integer. There is no bit to un-set in
     *         the number, so return value will be ILLEGAL
     */
    assert(ILLEGAL == unset_the_kth_bit_in_a_number(0, 32));

    /*
     * Test 2: Test with value zero and k equal to less than zero
     *         There is no bit to un-set in the number, so return
     *         value will be ILLEGAL
     */
    assert(ILLEGAL == unset_the_kth_bit_in_a_number(0, -1));

    /*
     * Test 3: Test un-setting the 0th bit in number
     */
    assert(14 == unset_the_kth_bit_in_a_number(15, 0));

    /*
     * Test 4: Test un-setting the 1st bit in number
     */
    assert(13 == unset_the_kth_bit_in_a_number(15, 1));

    /*
     * Test 5: Test un-setting the bit which is not set in the
     *         number. The return value should be same as the
     *         number itself.
     */
    assert(15 == unset_the_kth_bit_in_a_number(15, 10));

    return(0);
}
