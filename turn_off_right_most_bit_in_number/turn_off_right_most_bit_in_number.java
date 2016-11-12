/*
 * This program turns off the right most bit in a given integer. For
 * more information on this problem, please refer to the following
 * link:- http://www.geeksforgeeks.org/turn-off-the-rightmost-set-bit/
 */
import java.io.*;
import java.util.*;

public class turn_off_right_most_bit_in_number
{
    /*
     * This function turns off the right most bit in an integer. The time
     * complexity of this function is O(1) and the space complexity of this
     * function is O(1).
     */
    public static int turn_off_right_most_bit_num (int num)
    {
        /*
         * Bitwise AND operation of 'num' and 'num - 1' will un-set the
         * rightmost bit in the number
         */
        return(num & (num - 1));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with zero. The return value should be zero after
         *         turning off the right most bit in the number.
         */
        assert(0x00000000 == turn_off_right_most_bit_num(0x00000000));

        /*
         * Test 1: Test with one. The return value should be zero after
         *         turning off the right most bit in the number.
         */
        assert(0x00000000 == turn_off_right_most_bit_num(0x00000000));

        /*
         * Test 2: Test with two. The return value should be zero after
         *         turning off the right most bit in the number.
         */
        assert(0x00000000 == turn_off_right_most_bit_num(0x00000002));

        /*
         * Test 3: Test with three. The return value should be two after
         *         turning off the right most bit in the number.
         */
        assert(0x00000002 == turn_off_right_most_bit_num(0x00000003));

        /*
         * Test 4: Test with four. The return value should be zero after
         *         turning off the right most bit in the number.
         */
        assert(0x00000000 == turn_off_right_most_bit_num(0x00000004));

        /*
         * Test 5: Test with maximum positive integer value. The return value
         *         have the right most bit turned off.
         */
        assert(0x7ffffffe == turn_off_right_most_bit_num(0x7fffffff));

        /*
         * Test 6: Test with 0x40000000 integer value. The return value
         *         should be zero.
         */
        assert(0x00000000 == turn_off_right_most_bit_num(0x40000000));

        /*
         * Test 7: Test with minimum negative integer value. The return value
         *         should be zero.
         */
        assert(0x00000000 == turn_off_right_most_bit_num(0x80000000));

        /*
         * Test 8: Test with 0xffffffff integer value. The return value
         *         should be 0xfffffffe. the bit in the zeroth position
         *         should be un-set.
         */
        assert(0xfffffffe == turn_off_right_most_bit_num(0xffffffff));
    }
}
