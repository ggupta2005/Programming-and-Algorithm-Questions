/*
 * This program computes n modulo d without division(/) and modulo(%)
 * operators, where d is a power of 2 number. For more information on
 * this problem, please refer to the following link:-
 * http://www.geeksforgeeks.org/compute-modulus-division-by-a-power-of-2-number/
 */
import java.io.*;
import java.util.*;

public class find_modolus_division_by_power_of_two_without_standard_operators
{
    /*
     * This function returns 'true' if the 'num' is a power of two and 'false'
     * otherwise. The function uses bit wise operators to find is a number is a
     * power of two.
     */
    public static boolean if_power_of_two (int a)
    {
        /*
         * If 'num' is zero, then return 'false'
         */
        if (a <= 0) {
            return(false);
        }

        /*
         * If a 'num' is a power of two, then only one bit in the number will
         * be set. So deducting one from the number will give us a number
         * with all bits set to the right of the bit set in the original
         * number. Taking 'and' of the number and one less of the number
         * should give us zero.
         */
        return((a & (a - 1)) == 0);
    }

    /*
     * This function returns the remainder when a 'num' is divided by a
     * 'divisor' and the divisor is a power of two. This function doesn't
     * use the modulo or division opoerators.
     */
    public static int get_modulo_of_power_two (int num, int divisor)
    {
        /*
         * If divisor is not a power of two, then return minimum integer
         * value.
         */
        if (!if_power_of_two(divisor)) {
            return(Integer.MIN_VALUE);
        }

        /*
         * If the number is less than zero, then return minimum integer
         * value
         */
        if (num < 0) {
            return(Integer.MIN_VALUE);
        }

        /*
         * Return bitwise 'and' of the number and one less of the divisor.
         */
        return(num & (divisor - 1));
    }

    public static void main (String[] args)
    {
        int num0 = 6, div0 = 4;
        assert((num0 % div0) == get_modulo_of_power_two(num0, div0));

        int num1 = 6, div1 = 1;
        assert((num1 % div1) == get_modulo_of_power_two(num1, div1));

        int num2 = 6, div2 = 0;
        assert(Integer.MIN_VALUE == get_modulo_of_power_two(num2, div2));

        int num3 = 6, div3 = -128;
        assert(Integer.MIN_VALUE == get_modulo_of_power_two(num3, div3));
    }
}
