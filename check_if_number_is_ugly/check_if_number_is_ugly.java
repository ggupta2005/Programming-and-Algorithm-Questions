/*
 * Check if a positive number is an ugly number which means that this positive
 * number will have only 2, 3 and 5 as its prime factors. For more information
 * on this problem, please visit the following link:-
 *
 */
import java.io.*;
import java.util.*;

public class check_if_number_is_ugly
{
    /*
     * This function returns true if a positive number has only 2,3, and 5
     * as prime factors and false otherwise. The time complexity of this
     * function is O(log(2)n + log(3)n + log(5)n). The space complexity of
     * this function is O(1).
     */
    public static boolean check_if_number_is_ugly (int num)
    {
        /*
         * If the number is less than or equal to zero,
         * then return 'false'
         */
        if (num <= 0) {
            return(false);
        }

        /*
         * Continue dividing the number by two until the
         * number is no longer divisible by two.
         */
        while ((num % 2) == 0) {
            num /= 2;
        }

        /*
         * Continue dividing the number by three until the
         * number is no longer divisible by three.
         */
        while ((num % 3) == 0) {
            num /= 3;
        }

        /*
         * Continue dividing the number by five until the
         * number is no longer divisible by five.
         */
        while ((num % 5) == 0) {
            num /= 5;
        }

        /*
         * Check if the number does to one, after all the
         * divisions by two, three and five.
         */
        return(num == 1);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with negative numbers and zero. These numbers
         *         should not be ugly numbers.
         */
        assert(false == check_if_number_is_ugly(-100));
        assert(false == check_if_number_is_ugly(0));

        /*
         * Test 1: Test with positive numbers having two, three and
         *         five as the only prime factors.
         */
        assert(true == check_if_number_is_ugly(1));
        assert(true == check_if_number_is_ugly(2));
        assert(true == check_if_number_is_ugly(3));
        assert(true == check_if_number_is_ugly(5));
        assert(true == check_if_number_is_ugly(6));
        assert(true == check_if_number_is_ugly(10));
        assert(true == check_if_number_is_ugly(1 << 8));
        assert(true == check_if_number_is_ugly(1 << 16));
        assert(true == check_if_number_is_ugly(1 << 24));

        /*
         * Test 2: Test with positive numbers having two, three and
         *         five as not the only prime factors.
         */
        assert(false == check_if_number_is_ugly(7));
        assert(false == check_if_number_is_ugly(17));
        assert(false == check_if_number_is_ugly(140));
        assert(false == check_if_number_is_ugly(260));
    }
}
