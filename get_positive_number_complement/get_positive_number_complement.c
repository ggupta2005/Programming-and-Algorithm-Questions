/*
 * Given a positive integer, output its complement number. The complement
 * strategy is to flip the bits of its binary representation.
 *
 * Note:
 * The given integer is guaranteed to fit within the range of a 32-bit signed
 * integer. You could assume no leading zero bit in the integer’s binary
 * representation.
 *
 * Example 1:
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 *              and its complement is 010. So you need to output 2.
 *
 * Example 2:
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits),
 *              and its complement is 0. So you need to output 0.
 */
#include<stdio.h>
#include<assert.h>
#include<limits.h>

/*
 * This function returns the bit mask of a positive integer. If the number
 * is non-positive, then this function returns 0. The time complexity of
 * this function is O(log(n)) and the space complexity of this function is
 * O(1).
 */
int get_mask (int num)
{
    int mask, index;

    /*
     * If the number is less than or equal to zero, then return 0.
     */
    if (num <= 0) {
        return(0);
    }

    mask = 0;
    index = 0;

    /*
     * Iterate until, 'num' is non-zero
     */
    while (num) {

        /*
         * Set the bit in the mask
         */
        mask |= (1 << index);
        ++index;

        /*
         * Right shift the number
         */
        num >>= 1;
    }

    /*
     * Return the mask
     */
    return(mask);
}

/*
 * This function finds the 1s complement of a positive number. The time
 * complexity of this function is O(log(n)) and the space complexity of
 * the function is O(1).
 */
int find_complement(int num)
{
    /*
     * If the number is less than or equal to zero, then
     * return 0.
     */
    if (num <= 0) {
        return(0);
    }

    /*
     * Get the mask in O(log(n)) time.
     */
    int mask = get_mask(num);

    /*
     * Return the xor of the mask and the number which will
     * give the 1s complement.
     */
    return(num ^ mask);
}

int main ()
{
    /*
     * Test 0: The complement of one is zero.
     */
    assert(0 == find_complement(1));

    /*
     * Test 1: The complement of five is two.
     */
    assert(2 == find_complement(5));

    /*
     * Test 2: The complement of maximum positive number is zero.
     */
    assert(0 == find_complement(0x7fffffff));

    /*
     * Test 3: The complement of zero or negative number is zero.
     */
    assert(0 == find_complement(0));
    assert(0 == find_complement(-10));

    return(0);
}
