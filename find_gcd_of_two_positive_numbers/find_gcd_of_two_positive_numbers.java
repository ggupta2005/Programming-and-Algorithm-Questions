/*
 * This program finds the Greatest Common Divisor (GCD) of two
 * positive numbers.
 */
import java.io.*;
import java.util.*;

public class find_gcd_of_two_positive_numbers
{
    /*
     * This function returns the Greatest Common Divisor (GCD) of two
     * positive numbers using the Basic Euclidean Algorithm. The time
     * complexity of this algorithm is O(log(min(a,b))).
     */
    public static int gcd (int a, int b)
    {
        /*
         * If both numbers are zero, then return zero.
         */
        if ((a == 0) && (b == 0)) {
            return(0);
        }

        /*
         * If one of the numbers is zero, then return
         * the other number.
         */
        if (a == 0) {
            return(b);
        }

        if (b == 0) {
            return(a);
        }

        if (a > b) {

            /*
             * If 'a' is greater than 'b', then return the
             * gcd of 'a modulo b' and 'b'.
             */
            return(gcd(a%b, b));
        }

        /*
         * If 'b' is greater than or equal to 'a', then return
         * the gcd of 'a' and 'b modulo a'.
         */
        return(gcd(a, b%a));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with both numbers being zero. The GCD
         *         should be zero.
         */
        assert(0 == gcd(0, 0));

        /*
         * Test 1: Test with one of the numbers being zero and
         *         other being non-zero. The GCD should be the
         *         non-zero number.
         */
        assert(2 == gcd(2, 0));
        assert(2 == gcd(0, 2));

        /*
         * Test 2: Test with both numbers being same. The GCD should
         *         be the number itself.
         */
        assert(2 == gcd(2, 2));

        /*
         * Test 3: Test with one of the numbers being one and
         *         other being greater than one. The GCD should
         *         be one.
         */
        assert(1 == gcd(1, 23));
        assert(1 == gcd(23, 1));

        /*
         * test 4: Test with prime numbers. The GCD should be
         *         one.
         */
        assert(1 == gcd(7, 5));
        assert(1 == gcd(33, 751));

        /*
         * Test 5: Test with numbers where one number is multiple
         *         of the other number. The GCD should be the
         *         smaller of the two numbers.
         */
        assert(10 == gcd(70, 10));
        assert(10 == gcd(10, 70));

        /*
         * Test 6: Test with numbers having GCD greater than one.
         */
        assert(10 == gcd(70, 90));
        assert(10 == gcd(90, 70));
    }
}
