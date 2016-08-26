/*
 * This program checks if an integer is a palindrome. For example the number
 * 123321 is an integer which is a palindrome. The integer 123312 is not a
 * palindrome. We assume that negative numbers can also be palindromes.
 * For more information on this problem, refer to the following post:-
 * https://leetcode.com/problems/palindrome-number/
 *
 * Additional references:-
 * - For reference on the sign of the sign of the remainder operator refer
 *   to the following link :-
 *   http://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
 */
import java.io.*;
import java.util.*;

public class check_if_an_integer_is_palindrome
{
    /*
     * This function returns the number of digits in a given integer. The
     * time complexity of this function is O(d), where 'd' is the number of
     * digits in the number. The space complexity of this function is O(1).
     */
    public static int number_of_digits_in_integer (int num)
    {
        int digits = 0;

        /*
         * Iterate until the number is non-zero
         */
        while (num != 0) {

            /*
             * Increment the number of digits in the number
             */
            ++digits;

            /*
             * Divide the number by ten
             */
            num /= 10;
        }

        /*
         * Return the number of digits
         */
        return(digits);
    }

    /*
     * THis function returns the power of ten to the input 'exponent'. This
     * function first computes the sub-powers of ten and uses the computed
     * sub-powers to return the actual power of ten. The time complexity of
     * this function is O(log(exponent)), where 'exponent' is the intended
     * power of ten. The space complexity of this function is O(log(exponent))
     * since there be O(log(exponent)) function calls on the stack.
     */
    public static int power_of_ten (int exponent)
    {
        int power;

        /*
         * If exponent is less than zero, then return zero.
         */
        if (exponent < 0) {
            return(0);
        }

        /*
         * If exponent is zero, then return one. This is the base
         * case.
         */
        if (exponent == 0) {
            return(1);
        }

        /*
         * If exponent is one, then return ten. This is the base
         * case.
         */
        if (exponent == 1) {
            return(10);
        }

        /*
         * If the exponent is greater than one, then first compute
         * the sub-power by calling the function recursively for
         * half of exponent. Then use the computed sub-power to
         * return the actual power
         */
        if ((exponent % 2) == 0) {
            power = power_of_ten(exponent/2);
            power *= power;
        } else {
            power = power_of_ten(exponent/2);
            power *= 10 * power;
        }

        return(power);
    }

    /*
     * This function returns 'true' if the integer number is palindrome and
     * 'false' if the number is not palindrome. The time complexity of this
     * of this function is O(d), where 'd' is the number of digits in the
     * number. The space complexity of this function is O(1).
     */
    public static boolean check_if_integer_is_palindrome (int num)
    {
        int msb, lsb;
        int digits, power_msb, power_lsb;

        /*
         * Find the number of digits in the number
         */
        digits = number_of_digits_in_integer(num);

        /*
         * Compute the power of ten that is required to get
         * the most significant digit in the number.
         */
        power_msb = power_of_ten(digits - 1);

        /*
         * Compute the power of ten that is required to get
         * the least significant digit in the number.
         */
        power_lsb = power_of_ten(1);

        /*
         * Iterate until the number is zero
         */
        while (num != 0) {

            /*
             * Get the most significant digit in the number
             */
            msb = num / power_msb;

            /*
             * Get the least significant digit in the number
             */
            lsb = num % power_lsb;

            /*
             * If the most significant digit is not equal to
             * the least significant digit, then return 'false'
             */
            if (msb != lsb) {
                return(false);
            }

            /*
             * Remove the current most significant digit from the
             * number
             */
            num %= power_msb;

            /*
             * Remove the current least significant digit from the
             * number
             */
            num /= power_lsb;

            /*
             * Since two digits are shaved-off from the number, divide
             * the power of ten, which is used to obtain the most
             * significant digit, by one hundred
             */
            power_msb /= (10*10);
        }

        /*
         * Return true, since the number is palindrome
         */
        return(true);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test positive single digit numbers. These should be
         *         palindromes
         */
        assert(true == check_if_integer_is_palindrome(0));
        assert(true == check_if_integer_is_palindrome(1));
        assert(true == check_if_integer_is_palindrome(9));

        /*
         * Test 1: Test positive double digit palindrome numbers. These
         *         should be palindromes
         */
        assert(true == check_if_integer_is_palindrome(11));

        /*
         * Test 2: Test positive double digit non-palindrome numbers.
         *         These should not be palindromes
         */
        assert(false == check_if_integer_is_palindrome(12));

        /*
         * Test 3: Test positive multi-digit palindrome numbers. These
         *         should be palindroms
         */
        assert(true == check_if_integer_is_palindrome(121));
        assert(true == check_if_integer_is_palindrome(13231));
        assert(true == check_if_integer_is_palindrome(13299231));

        /*
         * Test 4: Test positive multi-digit non-palindrome numbers.
         *         These should not be palindromes
         */
        assert(false == check_if_integer_is_palindrome(132992310));

        /*
         * Test 5: Test negative single digit numbers. These should be
         *         palindromes
         */
        assert(true == check_if_integer_is_palindrome(-1));
        assert(true == check_if_integer_is_palindrome(-9));

        /*
         * Test 6: Test negative double digit palindrome numbers. These
         *         should be palindromes
         */
        assert(true == check_if_integer_is_palindrome(-11));

        /*
         * Test 7: Test negative double digit non-palindrome numbers.
         *         These should not be palindromes
         */
        assert(false == check_if_integer_is_palindrome(-12));

        /*
         * Test 8: Test negative multi-digit palindrome numbers. These
         *         should be palindroms
         */
        assert(true == check_if_integer_is_palindrome(-121));
        assert(true == check_if_integer_is_palindrome(-13231));
        assert(true == check_if_integer_is_palindrome(-13299231));

        /*
         * Test 9: Test negative multi-digit non-palindrome numbers.
         *         These should not be palindromes
         */
        assert(false == check_if_integer_is_palindrome(-132992310));
    }
}
