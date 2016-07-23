/*
 * This program allows to get the 1s-complement and 2s-complement
 * for a binary numbered string. More information on this can be
 * found on the following link:-
 * http://www.geeksforgeeks.org/1s-2s-complement-binary-number/
 */
import java.io.*;
import java.util.*;

public class get_1s_2s_complement_of_binary_num_str
{
    /*
     * This function checks if the given number string has only
     * binary Stringacter symbols '0' and '1'. If the string comprises
     * of any other Stringacters, then this function returns 'false'
     * otherwise this function returns 'true'. The time complexity of
     * this function is O(n), where 'n' is the number of Stringacters
     * in the number string.
     */
    public static boolean check_if_string_is_binary (String bin_num)
    {
        int len, i;

        /*
         * If the number string is null or has zero length,
         * then return 'false'.
         */
        if ((bin_num == null) || (bin_num.length() == 0)) {
            return(false);
        }

        i = 0;
        while (i < bin_num.length()) {

            /*
             * If the Stringacter symbol is not one of '0' or '1', then
             * return 'false' from this function
             */
            if ((bin_num.charAt(i) != '0') && (bin_num.charAt(i) != '1')) {
                return(false);
            }

            ++i;
        }

        /*
         * Return 'true' in case this is binary string
         */
        return(true);
    }

    /*
     * This function returns a 1s complement string for the binary
     * number string. The time complexity of this function is O(n),
     * where 'n' is the number of Stringacters in the number string.
     */
    public static String get_1s_complement_for_binary_number_str (String bin_num)
    {
        int len, i;
        char[] ones_complement;

        /*
         * If the number string is null or has zero length,
         * then return null
         */
        if ((bin_num == null) || (bin_num.length() == 0)) {
            return(null);
        }

        /*
         * If the number string doesn't contain binary symbols,
         * then return null
         */
        if (!check_if_string_is_binary(bin_num)) {
            return(null);
        }

        len = bin_num.length();

        /*
         * Allocate buffer space for ones complement string
         */
        ones_complement = new char[len];

        /*
         * If the allocated string is null, then return null
         * from this function
         */
        if (ones_complement == null) {
            return(null);
        }

        /*
         * Walk the binary string backwards and compute the ones
         * complement
         */
        for (i = len-1; i >= 0; --i) {
            /*
             * If the Stringacter is '0' in the binary string,
             * then add '1' in the ones complement string otherwise
             * add '0'
             */
            if (bin_num.charAt(i) == '0') {
                ones_complement[i] = '1';
            } else {
                ones_complement[i] = '0';
            }
        }

        /*
         * Return the ones complement string
         */
        return(new String(ones_complement));
    }

    /*
     * This function returns a 2s complement string for the binary
     * number string. The time complexity of this function is O(n),
     * where 'n' is the number of Stringacters in the number string.
     */
    public static String get_2s_complement_for_binary_number_str (String bin_num)
    {
        int len, i;
        char[] twos_complement;
        String ones_complement;
        char carry;
        int bit1, bit2;

        /*
         * If the number string is null or has zero length,
         * then return null
         */
        if ((bin_num == null) || (bin_num.length() == 0)) {
            return(null);
        }

        /*
         * If the number string doesn't contain binary symbols,
         * then return null
         */
        if (!check_if_string_is_binary(bin_num)) {
            return(null);
        }

        /*
         * Get the ones complement for binary number string
         */
        ones_complement = get_1s_complement_for_binary_number_str(bin_num);

        /*
         * If getting the ones complement fails, then return null from
         * the function
         */
        if (ones_complement == null) {
            return(null);
        }

        len = bin_num.length();

        /*
         * Allocate buffer space for twos complement string
         */
        twos_complement = new char[len];

        /*
         * If the allocated string is null, then return null
         * from this function
         */
        if (twos_complement == null) {
            return(null);
        }

        /*
         * Walk the binary string backwards and compute the twos
         * complement. The carry is set to one because we need to
         * add one to ones complement
         */
        carry = '1';
        for (i = len - 1; i >= 0; --i) {

            /*
             * Take the xor of carry and ones complement string
             * and store in twos complement string
             */
            bit1 = (ones_complement.charAt(i) == '0') ? 0 : 1;
            bit2 = (carry == '0') ? 0 : 1;

            if ((bit1 ^ bit2) == 1) {
                twos_complement[i] = '1';
            } else {
                twos_complement[i] = '0';
            }

            /*
             * Set the 'carry' as and operation of ones complement
             * and carry
             */
            if ((bit1 & bit2) == 1) {
                carry = '1';
            } else {
                carry = '0';
            }
        }

        /*
         * Return the twos complement string
         */
        return(new String(twos_complement));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test a 1s and 2s complement for a positive number
         *         binary string
         */
        String bin_num0 = "0101";
        String exp_1s_com0 = "1010";
        String exp_2s_com0 = "1011";
        String act_1s_com0 = get_1s_complement_for_binary_number_str(bin_num0);
        String act_2s_com0 = get_2s_complement_for_binary_number_str(bin_num0);
        assert exp_1s_com0.equals(act_1s_com0);
        assert exp_2s_com0.equals(act_2s_com0);

        /*
         * Test 1: Test a 1s and 2s complement for another positive number
         *         binary string
         */
        String bin_num1 = "00111111";
        String exp_1s_com1 = "11000000";
        String exp_2s_com1 = "11000001";
        String act_1s_com1 = get_1s_complement_for_binary_number_str(bin_num1);
        String act_2s_com1 = get_2s_complement_for_binary_number_str(bin_num1);
        assert exp_1s_com1.equals(act_1s_com1);
        assert exp_2s_com1.equals(act_2s_com1);

        /*
         * Test 2: Test a 1s and 2s complement for a non-binary number
         *         string
         */
        String bin_num2 = "21111111";
        String exp_1s_com2 = null;
        String exp_2s_com2 = null;
        String act_1s_com2 = get_1s_complement_for_binary_number_str(bin_num2);
        String act_2s_com2 = get_2s_complement_for_binary_number_str(bin_num2);
        assert exp_1s_com2 == act_1s_com2;
        assert exp_2s_com2 == act_2s_com2;

        /*
         * Test 3: Test a 1s and 2s complement for null binary number
         *         string
         */
        String bin_num3 = null;
        String exp_1s_com3 = null;
        String exp_2s_com3 = null;
        String act_1s_com3 = get_1s_complement_for_binary_number_str(bin_num3);
        String act_2s_com3 = get_2s_complement_for_binary_number_str(bin_num3);
        assert exp_1s_com3 == act_1s_com3;
        assert exp_2s_com3 == act_2s_com3;

        /*
         * Test 4: Test a 1s and 2s complement for an empty binary number
         *         string
         */
        String bin_num4 = "";
        String exp_1s_com4 = null;
        String exp_2s_com4 = null;
        String act_1s_com4 = get_1s_complement_for_binary_number_str(bin_num4);
        String act_2s_com4 = get_2s_complement_for_binary_number_str(bin_num4);
        assert exp_1s_com4 == act_1s_com4;
        assert exp_2s_com4 == act_2s_com4;
    }
}
