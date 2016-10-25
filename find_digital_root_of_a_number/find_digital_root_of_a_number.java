/*
 * This program finds the digital root of a non-negative number. The digital
 * root of a number is calculated by repeatedly adding all its digits until
 * the result has only one digit. For example, num = 38, the process is like:
 * 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, we return 2. For more
 * information on digital root, please refer to the following link:-
 * https://en.wikipedia.org/wiki/Digital_root
 */
import java.io.*;
import java.util.*;

public class find_digital_root_of_a_number
{
    /*
     * This function iteratively finds the digital root of a positive number.
     * If the number is either zero or negative, zero is returned as the
     * digital root of the number. If the number is positive, then we find
     * the sum of the digits of the number until the number has a single
     * digit left. We return this single digit as the digital root of the
     * number. The time complexity of this function is O(n), where 'n' is the
     * number of digits in the number. The space complexity of this function is
     * O(1).
     */
    public static int get_digital_root_v1 (int num)
    {
        int temp;

        /*
         * If the number is less than or equal to zero, then return
         * zero as the digital root of the number.
         */
        if (num <= 0) {
            return(0);
        }

        /*
         * Iterate until the number has a single digit.
         */
        while ((num / 10) != 0) {

            /*
             * Store the sum of all the digits of the number
             * in 'temp'
             */
            temp = 0;
            while (num != 0) {
                temp += num % 10;
                num /= 10;
            }

            /*
             * Assign 'temp' to 'num'
             */
            num = temp;
        }

        /*
         * Return the single digit in the number
         */
        return(num);
    }

    /*
     * This function finds the digital root of a positive number. If the
     * number is either zero or negative, zero is returned as the digital
     * root of the number. If the number is positive, then we find the
     * digital using the airthmetic with number nine. The time and space
     * complexity of this function is O(1).
     */
    public static int get_digital_root_v2 (int num)
    {
        /*
         * If the number is less than or equal to zero, then return
         * zero as the digital root of the number.
         */
        if (num <= 0) {
            return(0);
        }

        /*
         * If the number is divisible by nine, then the digital root
         * of the number is nine otherwise digital root is the remainder
         * of division by nine (See the above link).
         */
        if ((num % 9) == 0) {
            return(9);
        } else {
            return(num % 9);
        }
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: The digital root of a negative number should be zero
         */
        assert(0 == get_digital_root_v1(-1));
        assert(0 == get_digital_root_v2(-1));

        /*
         * Test 1: The digital root of zero should be zero
         */
        assert(0 == get_digital_root_v1(0));
        assert(0 == get_digital_root_v2(0));

        /*
         * Test 2: The digital root of single digit umber should be the
         *         same single digit number
         */
        assert(1 == get_digital_root_v1(1));
        assert(1 == get_digital_root_v2(1));
        assert(9 == get_digital_root_v1(9));
        assert(9 == get_digital_root_v2(9));

        /*
         * Test 3: Test the digital root of multiple digit numbers which
         *         are not multiples of nine.
         */
        assert((25 % 9) == get_digital_root_v1(25));
        assert((25 % 9) == get_digital_root_v2(25));

        /*
         * Test 4: Test the digital root of multiple digit numbers which
         *         are multiples of nine.
         */
        assert(9 == get_digital_root_v1(81));
        assert(9 == get_digital_root_v2(81));
    }
}
