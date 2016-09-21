/*
 * This program finds the number of bits set for a number.
 * For more information on this problem, please visit the following
 * link:- http://www.geeksforgeeks.org/count-set-bits-in-an-integer/
 */
import java.io.*;
import java.util.*;

public class find_num_bits_set_in_a_signed_number
{
    /*
     * This function returns the number of bits set in a given  integer.
     * The time complexity of this function is O(log(n)), where
     * 'n' is the number passed to this function. The space complexity of
     * this function is O(1).
     */
    public static int find_num_bits_set (int num)
    {
        int total = 0;

        /*
         * Iterate until 'num' becomes zero
         */
        while (num != 0) {

            /*
             * Test if the zeroth bit in the number is set.
             * If so, increment the number of bits set counter.
             */
            if ((num & 1) == 1) {
                ++total;
            }

            /*
             * Right shift the number by one. We should use the '>>>'
             * operator so that only '0' is appended from the left side.
             * For more information, please refer to the following link:-
             * http://www.geeksforgeeks.org/bitwise-shift-operators-in-java/
             */
            num = num >>> 1;
        }

        /*
         * Return the total number of bits set in the number
         */
        return(total);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: The numbers of bits set in zero should be zero
         */
        assert(0 == find_num_bits_set(0));

        /*
         * Test 1: The numbers of bits set in one should be one
         */
        assert(1 == find_num_bits_set(1));

        /*
         * Test 2: Test the number of bits set when the number is
         *         represented in hexadecimal format
         */
        assert(16 == find_num_bits_set(0x0000ffff));

        /*
         * Test 3: Test the number of bits set when all the bits in
         *         the number are set
         */
        assert(32 == find_num_bits_set(0xffffffff));

        /*
         * Test 4: Test the number of bits set when all the even
         *         positioned bits in the number are set
         */
        assert(16 == find_num_bits_set(0x55555555));

        /*
         * Test 5: Test the number of bits set when all the odd
         *         positioned bits in the number are set
         */
        assert(16 == find_num_bits_set(0xaaaaaaaa));
    }
}
