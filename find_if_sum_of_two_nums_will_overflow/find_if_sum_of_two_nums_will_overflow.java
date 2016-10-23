/*
 * This program finds if the sum of two integers will result in
 * overflow. For more information on this program, please refer to
 * the following link:-
 * http://www.geeksforgeeks.org/check-for-integer-overflow/
 */
import java.io.*;
import java.util.*;

public class find_if_sum_of_two_nums_will_overflow
{

    /*
     * This function returns 'true' in case the sum of two integers
     * will overflow the maximum or minimum allowed values for integers
     * and 'false' otherwise.
     */
    public static boolean if_sum_of_two_nums_will_overflow (int a, int b)
    {
        if ((a > 0) && (b > 0)) {

            /*
             * If both numbers are greater than zero, then check
             * if one of the numbers is greater than difference of
             * Integer.MAX_VALUE and the other number. If that is the
             * case, then return 'true'.
             */
            if (a > (Integer.MAX_VALUE - b)) {
                return(true);
            }
        }

        if ((a < 0) && (b < 0)) {

            /*
             * If both numbers are lesser than zero, then check
             * if one of the numbers is lesser than difference of
             * 'Intege.MIN_VALUE' and the other number. If that is the
             * case, then return 'true'.
             */
            if (a < (Integer.MIN_VALUE - b)) {
                return(true);
            }
        }

        /*
         * In all other zases, return 'false' because the sum of
         * 'a' and 'b' will not overflow the INT_MIN and INT_MAX.
         */
        return(false);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with largest positive value, so that overflow can
         *         occur.
         */
        assert(true == if_sum_of_two_nums_will_overflow(Integer.MAX_VALUE, 1));

        /*
         * Test 1: Test with largest positive value, so that overflow
         *         cannot occur.
         */
        assert(false == if_sum_of_two_nums_will_overflow(Integer.MAX_VALUE, -1));

        /*
         * Test 2: Test with largest positive value, so that overflow
         *         cannot occur.
         */
        assert(false == if_sum_of_two_nums_will_overflow(Integer.MAX_VALUE, 0));

        /*
         * Test 3: Test with largest negative value, so that overflow can
         *         occur.
         */
        assert(true == if_sum_of_two_nums_will_overflow(Integer.MIN_VALUE, -1));

        /*
         * Test 4: Test with largest negative value, so that overflow cannot
         *         occur.
         */
        assert(false == if_sum_of_two_nums_will_overflow(Integer.MIN_VALUE, +1));

        /*
         * Test 5: Test with largest negative value, so that overflow cannot
         *         occur.
         */
        assert(false == if_sum_of_two_nums_will_overflow(Integer.MIN_VALUE, 0));
    }
}
