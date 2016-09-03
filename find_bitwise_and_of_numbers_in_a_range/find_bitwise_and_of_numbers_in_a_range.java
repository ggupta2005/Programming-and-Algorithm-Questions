/*
 * This program computes the bitwise AND of all positive numbers within
 * a given range. For more information on this problem, please refer to
 * the following link:-
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/
 */
import java.io.*;
import java.util.*;

public class find_bitwise_and_of_numbers_in_a_range
{
    public static final int ILLEGAL = ~0;
    public static final int SIZEOF_INT_IN_BITS = 32;

    /*
     * This function calculates and returns the bitwise AND operations of all
     * numbers in a range from 'low' to 'high'. This function takes one number
     * at a time and takes the bitwise AND with the running result. The time
     * complexity of this function is O(n), where 'n' is the total number of
     * numbers from 'low' to 'high'. The sapce complexity of this function is
     * O(1).
     */
    public static int find_bitwise_and_numbers_in_range_v1 (
                                                        int low, int high)
    {
        int all_and, num;

        /*
         * If 'low' or 'high' are not positive numbers and if
         * low is greater than high, then return ILLEGAL from
         * this function.
         */
        if ((low < 0) || (high < 0) || (low > high)) {
            return(ILLEGAL);
        }

        /*
         * Set the cumulative result to 'low'
         */
        all_and = low;

        /*
         * Iterate from all number from 'low' to 'high' to capture the running
         * AND of all the number in this range.
         */
        for (num = low + 1; num <= high; ++num) {
            all_and &= num;
        }

        /*
         * Return the cumulative result
         */
        return(all_and);
    }

    /*
     * This function calculates and returns the bitwise AND operations of all
     * numbers in the range from 'low' to 'high'. This function examines each
     * bit position to compute the bitwise AND operation of all numbers from
     * 'low' to 'high'. The time complexity of this function is O(b),
     * where 'b' is the number of bits in the integer. The space complexity
     * of this function is O(1).
     */
    public static int find_bitwise_and_numbers_in_range_v2 (
                                                        int low, int high)
    {
        int all_and, bit, diff, power_two, low_bit, high_bit;

        /*
         * If 'low' or 'high' are not positive numbers and if
         * low is greater than high, then return ILLEGAL from
         * this function.
         */
        if ((low < 0) || (high < 0) || (low > high)) {
            return(ILLEGAL);
        }

        /*
         * Compute the number of integers between low and high inclusive
         */
        diff = high - low + 1;

        /*
         * Set the cumulative AND operation result to zero
         */
        all_and = 0;

        /*
         * Iterate over all the bis in the integer
         */
        for (bit = 0; bit < (SIZEOF_INT_IN_BITS - 1); ++bit) {

            /*
             * Compute the power of two using left shift operator
             */
            power_two = 1 << bit;

            /*
             * If the power of two is greater than or equal to the
             * number of integers between 'low' and 'high', then set
             * the bit in the cumulative result to be the bitwise AND
             * of this bit.
             */
            if (power_two >= diff) {
                low_bit = low & (1 << bit);
                high_bit = high & (1 << bit);
                all_and |= low_bit & high_bit;
            } else {

                /*
                 * Otherwise, unset the current bit in the cumulative
                 * result
                 */
                all_and &= ~(1 << bit);
            }
        }

        /*
         * Return the cumulative result
         */
        return(all_and);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with negative values of the range. The result should
         *         not be legal.
         */
        int and0 = ILLEGAL;
        assert(and0 == find_bitwise_and_numbers_in_range_v1(-9, 10));
        assert(and0 == find_bitwise_and_numbers_in_range_v2(-9, 10));
        assert(and0 == find_bitwise_and_numbers_in_range_v1(9, -10));
        assert(and0 == find_bitwise_and_numbers_in_range_v2(9, -10));
        assert(and0 == find_bitwise_and_numbers_in_range_v1(-10, -9));
        assert(and0 == find_bitwise_and_numbers_in_range_v2(-10, -9));

        /*
         * Test 1: Test with positive values of the range. But the lower
         *         value of the range is greater than the higher value of
         *         the range. The result should not be legal.
         */
        int and1 = ILLEGAL;
        assert(and1 == find_bitwise_and_numbers_in_range_v1(10, 9));
        assert(and1 == find_bitwise_and_numbers_in_range_v2(10, 9));

        /*
         * Test 2: Test with positive values of the range. The lower
         *         value of the range is same as the higher value of
         *         the range. The result should be range itself.
         */
        int and2 = 10;
        assert(and2 == find_bitwise_and_numbers_in_range_v1(10, 10));
        assert(and2 == find_bitwise_and_numbers_in_range_v2(10, 10));

        /*
         * Test 3: Test with lower value as zero and higher value as
         *         some non-zero value. The result should be zero.
         */
        int and3 = 0;
        assert(and3 == find_bitwise_and_numbers_in_range_v1(0, 10));
        assert(and3 == find_bitwise_and_numbers_in_range_v2(0, 10));

        /*
         * Test 4: Test with lower value as some non-zero and higher
         *         value as some non-zero value. The result should be
         *         non-zero.
         */
        int and4 = 240;
        assert(and4 == find_bitwise_and_numbers_in_range_v1(246, 249));
        assert(and4 == find_bitwise_and_numbers_in_range_v2(246, 249));

        /*
         * Test 5: Test with lower value as zero and higher value as the
         *         maximum possible integer value. The result should be
         *         zero. Test only vrsion 2 since version will take a long
         *         time to complete. :)
         */
        int and5 = 0;
        assert(and5 == find_bitwise_and_numbers_in_range_v2(
                                                    0, Integer.MAX_VALUE));
    }
}
