/*
 * This program finds the hamming distance between two integers, that is
 * the number of bit positions in which the two numbers differ in their
 * binary representation. For more information on hamming distance,
 * please visit the following link:- https://en.wikipedia.org/wiki/Hamming_distance
 */
import java.io.*;
import java.util.*;

public class find_hamming_distance_between_two_numbers
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
            if ((num & 1) != 0) {

                /*
                 * Increment 'count' in case the bit is set in the 'num'
                 */
                ++count;
            }

            /*
             * Left shift the number by '1'
             */
            num = num >>> 1;
        }

        /*
         * Return the total bits set in the number
         */
        return(count);
    }

    /*
     * This function returns the number hamming distance between number 'a'
     * into number 'b'. We first take of the bitwise xor of 'a'and 'b' and
     * then we compute the number of bits set in the number obtained from
     * the xor operation. The time complexity of this function is O(log(num)),
     * since a number can be represented in 'log(num)' bits.
     */
    public static int find_hamming_distance_between_two_nums (int a, int b)
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
         * Test 0: Test with both numbers being same. The hamming distance
         *         should be zero.
         */
        int a0 = 110;
        int b0 = 110;
        assert(0 == find_hamming_distance_between_two_nums(a0, b0));

        /*
         * Test 1: Test with both numbers being zero. The hamming distance
         *         should be zero.
         */
        int a1 = 0;
        int b1 = 0;
        assert(0 == find_hamming_distance_between_two_nums(a1, b1));

        /*
         * Test 2: Test with both numbers being different. The hamming
         *         distance should be non-zero.
         */
        int a2 = 9;
        int b2 = 4;
        assert(3 == find_hamming_distance_between_two_nums(a2, b2));

        /*
         * Test 3: Test with both numbers being different with bits being
         *         set be mutually exclusive. The hamming distance should be
         *         non-zero.
         */
        int a3 = 0xffff0000;
        int b3 = 0x0000ffff;
        assert(32 == find_hamming_distance_between_two_nums(a3, b3));
    }
}
