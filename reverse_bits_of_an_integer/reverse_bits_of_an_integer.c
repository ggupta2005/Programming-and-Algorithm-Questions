/*
 * This program reverses the bits of an integer. For example if the number
 * is '0x0000ff11', then after reversing the bits in the number we would get
 * '0x88ff0000'.
 */
#include<stdio.h>
#include<assert.h>
#include<limits.h>

/*
 * This function reverses the bits in the input number and returns the
 * number with the reversed bits. This function iterates over all the
 * bits in the number so its time complexity is O(log(n)). The space
 * complexity of this function is O(1).
 */
int reverse_bits_v1 (int num)
{
    int num_reverse;
    int index;
    int len_in_bits = sizeof(num) * CHAR_BIT;

    /*
     * Iterate over all the bits in the input number
     */
    num_reverse = 0;
    for (index = 0; index < len_in_bits; ++index) {

        /*
         * If the bit at 'index' position is set in the input
         * number, then set the bit at position 'len_in_bits -
         * index - 1' in the reversed number
         */
        if (num & (1 << index)) {
            num_reverse |= (1 << (len_in_bits - index - 1));
        }
    }

    /*
     * Return the number with bits reversed
     */
    return(num_reverse);
}

/*
 * This function reverses the bits in the input number and returns the
 * number with the reversed bits. This function reverses the bytes, then
 * neighboring nibbles, then the neighboring group of two bits and finally
 * the neighboring bits using the bitwise operators. The time and space
 * complexities of this function is hence O(1).
 */
int reverse_bits_v2 (int num)
{
    int num_copy = num;

    /*
     * Reverse bytes in the number. We take the bitwise AND with the
     * mask after the right shift operator since right shift operator
     * is known to supplement ones in case signed bit is set.
     */
    num_copy = (((num_copy & 0xff000000) >> 24) & 0x000000ff) |
               (((num_copy & 0x00ff0000) >> 8) & 0x0000ff00) |
               (((num_copy & 0x0000ff00) << 8) & 0x00ff0000) |
               (((num_copy & 0x000000ff) << 24) & 0xff000000);

    /*
     * Swap nibbles in the number
     */
    num_copy = (((num_copy & 0xf0f0f0f0) >> 4) & 0x0f0f0f0f) |
               (((num_copy & 0x0f0f0f0f) << 4) & 0xf0f0f0f0);

    /*
     * Swap half of the nibbles in the number
     */
    num_copy = (((num_copy & 0xcccccccc) >> 2) & 0x33333333) |
               (((num_copy & 0x33333333) << 2) & 0xcccccccc);

    /*
     * Swap the even and odd bits
     */
    num_copy = (((num_copy & 0xaaaaaaaa) >> 1) & 0x55555555) |
               (((num_copy & 0x55555555) << 1) & 0xaaaaaaaa);

    /*
     * Return the number with bits reversed
     */
    return(num_copy);
}

int main ()
{
    /*
     * Test 0: Test with zero. The bit reversed number will be zero.
     */
    assert(0x00000000 == reverse_bits_v1(0x00000000));
    assert(0x00000000 == reverse_bits_v2(0x00000000));

    /*
     * Test 1: Test with a number in which alternating bits starting
     *         from bit zero are set. The bit reversed number should
     *         also have alternating bits set from the first bit.
     */
    assert(0xaaaaaaaa == reverse_bits_v1(0x55555555));
    assert(0xaaaaaaaa == reverse_bits_v2(0x55555555));

    /*
     * Test 2: Test with a few other combination of bits set in
     *         numbers to check if the bit reversing function works.
     */
    assert(0xf33f0000 == reverse_bits_v1(0x0000fccf));
    assert(0xf33f0000 == reverse_bits_v2(0x0000fccf));
    assert(0x88ff0000 == reverse_bits_v1(0x0000ff11));
    assert(0x88ff0000 == reverse_bits_v2(0x0000ff11));

    return(0);
}
