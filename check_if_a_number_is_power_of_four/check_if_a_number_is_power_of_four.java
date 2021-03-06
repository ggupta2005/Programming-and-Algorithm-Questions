/*
 * This program checks if a number is a power of four. For more
 * information on this problem, please visit the following link:-
 * http://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/
 */
import java.io.*;
import java.util.*;

public class check_if_a_number_is_power_of_four
{
    /*
     * This function returns 'true' if the 'num' is a power of four and
     * 'false' otherwise. The function uses bit wise operators to find is
     * a number is a power of four.
     */
    public static boolean if_num_is_power_of_four_v1 (int num)
    {
        int count_bits_set;

        /*
         * If 'num' is less than or equal to zero,
         * then return 'false'
         */
        if (num <= 0) {
            return(false);
        }

        /*
         * Check if 'num' is a power of two. If not, then return
         * 'false'
         */
        if ((num & (num -1)) != 0) {
            return(false);
        }

        /*
         * If 'num' is a power of four, then we need to check if the
         * number of ones in 'num - 1' is even.
         */
        count_bits_set = 0;

        /*
         * Deduct one from 'num'
         */
        num -= 1;

        /*
         * Loop until num is non-zero
         */
        while (num > 0) {

            /*
             * If the zeroth bit of 'num' is set, then increment the
             * number of bits counter
             */
            if ((num & 1) != 0) {
                ++count_bits_set;
            }

            /*
             * Right shift 'num' by one
             */
            num >>= 1;
        }

        /*
         * Check and return if the number of ones computed is even
         */
        return((count_bits_set%2) == 0);
    }

    /*
     * This function returns 'true' if the 'num' is a power of four and
     * 'false' otherwise. The function uses bit wise operators to find is
     * a number is a power of four.
     */
    public static boolean if_num_is_power_of_four_v2 (int num)
    {
        int count_bits_set;

        /*
         * If 'num' is less than or equal to zero,
         * then return 'false'
         */
        if (num <= 0) {
            return(false);
        }

        /*
         * Check if 'num' is a power of two. If not, then return
         * 'false'
         */
        if ((num & (num -1)) != 0) {
            return(false);
        }

        /*
         * Check if the even numbered bits are set in the number.
         * not, then return 'false'
         */
        if ((num & 0x55555555) == 0) {
            return(false);
        }

        return(true);
    }

    public  static void main (String[] args)
    {
        /*
         * Test 0: '0' is not a power of four
         */
        assert(false == if_num_is_power_of_four_v1(0));
        assert(false == if_num_is_power_of_four_v2(0));

        /*
         * Test 1: '1' is a power of four
         */
        assert(true == if_num_is_power_of_four_v1(1));
        assert(true == if_num_is_power_of_four_v2(1));

        /*
         * Test 2: '2' is not a power of four
         */
        assert(false == if_num_is_power_of_four_v1(2));
        assert(false == if_num_is_power_of_four_v2(2));

        /*
         * Test 3: '3' is not a power of four
         */
        assert(false == if_num_is_power_of_four_v1(3));
        assert(false == if_num_is_power_of_four_v2(3));

        /*
         * Test 4: '4' is a power of four
         */
        assert(true == if_num_is_power_of_four_v1(4));
        assert(true == if_num_is_power_of_four_v2(4));

        /*
         * Test 5: '16' is a power of four
         */
        assert(true == if_num_is_power_of_four_v1(16));
        assert(true == if_num_is_power_of_four_v2(16));

        /*
         * Test 6: '32' is not a power of four
         */
        assert(false == if_num_is_power_of_four_v1(32));
        assert(false == if_num_is_power_of_four_v2(32));

        /*
         * Test 7: '-1' is not a power of four
         */
        assert(false == if_num_is_power_of_four_v1(-1));
        assert(false == if_num_is_power_of_four_v2(-1));
    }
}
