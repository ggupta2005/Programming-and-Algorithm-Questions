/*
 * This program finds the minimum number from the digits of a given positive
 * number with no zeros of the given number put to the beginning of the number.
 * For example, if the given number is 90874322, then the minimum number formed
 * from these digits is 20234789. For more information on this post, please
 * refer to the following link:-
 * http://www.geeksforgeeks.org/smallest-number-rearranging-digits-given-number/
 */
import java.io.*;
import java.util.*;

public class find_minimum_number_formed_from_digits_of_given_number
{
    public static final int ILLEGAL = -1;
    public static final int MAX_DIGITS = 10;

    /*
     * This function returns the minimum possible number from the digits of
     * a given positive number with no zeros of the given number put to the
     * beginning of the number. If the number is less than zero, then this
     * function returns '-1'. The time complexity of this function is O(n),
     * where 'n' is the number of digits in the number. The space complxity
     * of this function is O(1).
     */
    public static int find_minimum_num_formed_from_digits_of_given_num
                                                                  (int num)
    {
        int[] digit_stats = new int[MAX_DIGITS];
        int rem, num_copy, result, index, inner_index, zero_index;
        boolean if_first_digit_added;

        /*
         * If the number is less than zero, then return '-1'
         */
        if (num < 0) {
            return(ILLEGAL);
        }

        /*
         * Make a copy of the number
         */
        num_copy = num;

        /*
         * Iterate until the copy of the number becomes zero
         */
        while (num_copy != 0) {

            /*
             * Find the remainder of the number
             */
            rem = num_copy % 10;

            /*
             * Increment the digit stats
             */
            digit_stats[rem]++;

            /*
             * Divide the number copy by ten
             */
            num_copy /= 10;
        }

        /*
         * Set result as zero
         */
        result = 0;

        /*
         * Maintain a variable to keep track if the first non-zero
         * digit has been added to the result
         */
        if_first_digit_added = false;

        /*
         * Iterate over all non-zero digits starting from the digit one.
         */
        for (index = 1; index < MAX_DIGITS; ++index) {

            /*
             * Add as many digits to the result as there in the original
             * number.
             */
            for (inner_index = 0; inner_index < digit_stats[index];
                 ++inner_index) {

                /*
                 * Multiply by ten and add index to the result
                 */
                result = result * 10 + index;

                /*
                 * If the first digit is already added to the number
                 * then add all zeros into the number
                 */
                if (!if_first_digit_added) {
                    if_first_digit_added = true;

                    /*
                     * Add all zeros in the original number into the
                     * result number
                     */
                    for (zero_index = 0; zero_index < digit_stats[0];
                         ++zero_index) {

                        /*
                         * Multiply the result number by ten
                         */
                        result *= 10;
                    }
                }
            }
        }

        /*
         * Return the result number
         */
        return(result);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test the case when the number is less than zero. The
         *         minimum number should be '-1'.
         */
        assert(ILLEGAL ==
                find_minimum_num_formed_from_digits_of_given_num(-100));

        /*
         * Test 1: Test the case when the number is zero. The minimum
         *         number should be zero.
         */
        assert(0 ==
                find_minimum_num_formed_from_digits_of_given_num(0));

        /*
         * Test 2: Test the case when the number is a single digit number.
         *         The minimum number should be the single digit number.
         */
        assert(1 ==
                find_minimum_num_formed_from_digits_of_given_num(1));
        assert(2 ==
                find_minimum_num_formed_from_digits_of_given_num(2));

        /*
         * Test 3: Test the case when the number has more than one digits.
         */
        assert(10 ==
                find_minimum_num_formed_from_digits_of_given_num(10));

        /*
         * Test 4: Test the case when the number is has a mix of non-zero
         *         digits and zero digit.
         */
        assert(20234789 ==
                find_minimum_num_formed_from_digits_of_given_num(90874322));

        /*
         * Test 5: Test the case when the number is has a mix of non-zero
         *         digits and all non-zero digits are in ascending order.
         */
        assert(123456789 ==
                find_minimum_num_formed_from_digits_of_given_num(123456789));

        /*
         * Test 6: Test the case when the number is has a mix of non-zero
         *         digits and all non-zero digits are in descending order.
         */
        assert(123456789 ==
                find_minimum_num_formed_from_digits_of_given_num(987654321));

        /*
         * Test 7: Test the case when the number is has a mix of non-zero
         *         digits zero digits. All zero digits come after the first
         *         minimum non-zero digit.
         */
        assert(1000005 ==
                find_minimum_num_formed_from_digits_of_given_num(5000100));

        /*
         * Test 8: Test the case when there are multiple non-zero same digits.
         */
        assert(1111122222 ==
                find_minimum_num_formed_from_digits_of_given_num(1212121212));
    }
}
