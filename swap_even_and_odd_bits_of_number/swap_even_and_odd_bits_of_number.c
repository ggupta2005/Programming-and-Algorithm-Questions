/*
 * This program swaps the even and odd bits of a number. Fo more
 * on this problem, please refer to the following link:-
 * http://www.geeksforgeeks.org/swap-all-odd-and-even-bits/
 */
#include<stdio.h>
#include<assert.h>

/*
 * The mask for getting all the even positioned bits in the number.
 * The even positioned bits start from 0 index.
 * 0x55 55 55 55 = 0x0101 0101 0101 0101 0101 0101 0101 0101
 */
#define EVEN_BIT_MASK         0x55555555

/*
 * The mask for getting all the odd positioned bits in the number.
 * The odd positioned bits start from 1 index.
 * 0xaa aa aa aa = 0x1010 1010 1010 1010 1010 1010 1010 1010
 */
#define ODD_BIT_MASK          0xaaaaaaaa

/*
 * This function returns the number after swapping the even and odd
 * positioned bits in the number.
 */
unsigned int get_num_afterswapping_even_odd_bits (unsigned int num)
{
    /*
     * Get all the odd set bits in the number using bitwise and
     * operation of the number and ODD_BIT_MASK.
     */
    unsigned int odd_bits_set = num & ODD_BIT_MASK;

    /*
     * Get all the even set bits in the number using bitwise and
     * operation of the number and EVEN_BIT_MASK.
     */
    unsigned int even_bits_set = num & EVEN_BIT_MASK;

    /*
     * Right shift by one bit all the odd positioned set bits.
     */
    odd_bits_set >>= 1;

    /*
     * Left shift by one bit all the even positioned set bits.
     */
    even_bits_set <<= 1;

    /*
     * Return the bitwise OR of the right shifted odd set bits
     * and left shifted even set bits.
     */
    return(odd_bits_set | even_bits_set);
}

int main ()
{
    /*
     * Test 0: Test with zero. The odd-even bit swapped number will
     *         be zero.
     */
    assert(0x00000000 ==
                get_num_afterswapping_even_odd_bits(0x00000000));

    /*
     * Test 1: Test with one. The odd-even bit swapped number will
     *         be two.
     */
    assert(0x00000002 ==
                get_num_afterswapping_even_odd_bits(0x00000001));

    /*
     * Test 2: Test with two. The odd-even bit swapped number will
     *         be one.
     */
    assert(0x00000001 ==
                get_num_afterswapping_even_odd_bits(0x00000002));

    /*
     * Test 3: Test with 0x55555555. The odd-even bit swapped number
     *         will be 0xaaaaaaaa.
     */
    assert(0x55555555 ==
                get_num_afterswapping_even_odd_bits(0xaaaaaaaa));

    /*
     * Test 4: Test with number 23 (0x00000017). The odd-even bit
     *         swapped number will be 43 (0x0000002b)
     */
    assert(43 == get_num_afterswapping_even_odd_bits(23));

    return(0);
}
