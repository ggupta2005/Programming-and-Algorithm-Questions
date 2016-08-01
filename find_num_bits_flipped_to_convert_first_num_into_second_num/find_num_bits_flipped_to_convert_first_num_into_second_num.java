/*
 * This program finds the number of bits that need to be flipped to convert a
 * given number into another number. For more information on this problem, please
 * refer to the post:-
 * http://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/
 */
import java.io.*;
import java.util.*;

public class find_num_bits_flipped_to_convert_first_num_into_second_num
{
    /*
     * This function returns the number of bits set in a given number.
     * This function tests if a bit is set using the bitwise operation.
     * If the bitwise AND operation results in zero, then bit in 'num' is
     * not set else it is set. The time complexity of this function is
     * O(log(num)), since a number can be represented in 'log(num)'
     * bits.
     */
    public static int find_num_bits_set_in_num (int num)
    {
        int i;
        int count = 0;

        /*
         * Iterate until 'num' is zero and test if a given bit
         * is set in the number
         */
        while (num != 0) {

            /*
             * Test if the 'ith' bit in the number is set
             */
            if ((num & (1 << 0)) != 0) {

                /*
                 * Increment 'count' in case the bit is set in the 'num'
                 */
                ++count;
            }

            /*
             * Left shift the number by '1'
             */
            num = num >> 1;
        }

        /*
         * Return the total bits set in the number
         */
        return(count);
    }

    /*
     * This function returns the number of bits that need to flipped to
     * convert number 'a' into number 'b'. The get the number of bits that
     * need to be flipped, we first take of the bitwise xor of 'a'and 'b'
     * and then we compute the number of bits set in the number obtained from
     * the xor operation.
     */
    public static int
        find_num_bits_flipped_to_convert_first_num_into_second_num (int a,
                                                                    int b)
    {
        /*
         * Obtain the bitwise xor of 'a' and 'b'
         */
        int xor_a_b = a ^ b;

        /*
         * Return the number of bits set in the result of bitwise xor
         * operation of 'a' and 'b'
         */
        return(find_num_bits_set_in_num(xor_a_b));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with both numbers being same. The number of bits that
         *         need to be flipped should be zero.
         */
        int a0 = 110;
        int b0 = 110;
        assert(0 ==
          find_num_bits_flipped_to_convert_first_num_into_second_num(a0, b0));

        /*
         * Test 1: Test with both numbers being zero. The number of bits that
         *         need to be flipped should be zero.
         */
        int a1 = 0;
        int b1 = 0;
        assert(0 ==
          find_num_bits_flipped_to_convert_first_num_into_second_num(a1, b1));

        /*
         * Test 2: Test with both numbers being different. The number of bits
         *         that need to be flipped should be non-zero.
         */
        int a2 = 9;
        int b2 = 4;
        assert(3 ==
          find_num_bits_flipped_to_convert_first_num_into_second_num(a2, b2));
    }

}
