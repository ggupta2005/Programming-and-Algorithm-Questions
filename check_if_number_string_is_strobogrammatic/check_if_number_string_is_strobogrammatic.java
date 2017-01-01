/*
 * This program checks if a number string is strobogrammatic i.e. the numbers
 * in the string look the same when rotated by 180 degrees upside down.
 * For example, the numbers "69", "88", and "818" are all strobogrammatic.
 */
import java.io.*;
import java.util.*;

public class check_if_number_string_is_strobogrammatic
{
    /*
     * This function returns 'true' if the character 'a' when inverted
     * is same as 'b' and 'false' otherwise. This can only return 'true'
     * for the digits '1', '0', '8', '6', '9'. The time and space complexity
     * of this function is O(1).
     */
    public static boolean if_chars_are_same_when_inverted (char a, char b)
    {
        /*
         * Check when character 'a' is inverted if it is equal to
         * 'b'
         */
        switch (a) {
            case '8':

                /*
                 * If 'b' is '8' return 'true'
                 */
                if (b == '8') {
                    return(true);
                }

                break;

            case '0':

                /*
                 * If 'b' is '0' return 'true'
                 */
                if (b == '0') {
                    return(true);
                }

                break;

            case '1':

                /*
                 * If 'b' is '1' return 'true'
                 */
                if (b == '1') {
                    return(true);
                }

                break;

            case '6':

                /*
                 * If 'b' is '9' return 'true'
                 */
                if (b == '9') {
                    return(true);
                }

                break;

            case '9':

                /*
                 * If 'b' is '6' return 'true'
                 */
                if (b == '6') {
                    return(true);
                }

                break;

            /*
             * If 'a' is neither of '0', '1', '8', '9' or '6',
             * then break
             */
            default:
                break;
        }

        /*
         * Inverting of character 'a' does not result in 'b',
         * so return 'false'
         */
        return(false);
    }

    /*
     * This function returns 'true' if the character string of digits is
     * strobogrammatic otherwise this function returns 'false'. The time
     * complexity of this function is O(n), where 'n' is the number of
     * character digits in the string. The space complexity of this
     * function is O(1).
     */
    public static boolean if_num_str_is_strobogrammatic (String ch)
    {
        int i, len, left, right;

        /*
         * If the character string is null or if the string is
         * empty, then return 'false'.
         */
        if ((ch == null) || (ch.length() == 0)) {
            return(false);
        }

        len = ch.length();

        /*
         * If any character in the string is not digit, then return
         * 'false'
         */
        for (i = 0; i < len; ++i) {
            if (!Character.isDigit(ch.charAt(i))) {
                return(false);
            }
        }

        /*
         * If the length of the string is odd, then check the
         * middle character of the string
         */
        if ((len % 2) != 0) {
            if ((ch.charAt(len/2) == '6') || (ch.charAt(len/2) == '9')) {

                /*
                 * If the middle character is '6' or '9', then the
                 * digit string cannot be strobogrammatic. So return
                 * 'false'.
                 */
                return(false);
            } else if ((ch.charAt(len/2) == '2') ||
                       (ch.charAt(len/2) == '3') ||
                       (ch.charAt(len/2) == '4') ||
                       (ch.charAt(len/2) == '5') ||
                       (ch.charAt(len/2) == '7')) {

                /*
                 * If the middle character is '2', '3', '4', '5' or '7',
                 * then the digit string cannot be strobogrammatic. So
                 * return 'false'.
                 */
                return(false);
            }
        }

        /*
         * Compare characters from the front of the string and the
         * end of the string to see if inverting the character in the front
         * of the string results in the character from the end in the string.
         */
        left = 0;
        right = len - 1;
        while (left < right) {

            /*
             * If the left and the right indexed character do not form a
             * strobogrammatic pair, then return 'false'
             */
            if (!if_chars_are_same_when_inverted(ch.charAt(left),
                                                 ch.charAt(right))) {
                return(false);
            }

            ++left;
            --right;
        }

        /*
         * The digit string is strobogrammatic, so return 'true'
         */
        return(true);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test using a null or empty string. The digit string
         *         should not be strobogrammatic.
         */
        assert(false == if_num_str_is_strobogrammatic(null));
        assert(false == if_num_str_is_strobogrammatic(""));

        /*
         * Test 1: Test using a string containing non-digit characters.
         *         The digit string should not be strobogrammatic.
         */
        assert(false == if_num_str_is_strobogrammatic("ab10"));

        /*
         * Test 2: Test using a strings which are strobogrammatic. The
         *         digit string should be found strobogrammatic.
         */
        assert(true == if_num_str_is_strobogrammatic("0"));
        assert(true == if_num_str_is_strobogrammatic("69"));
        assert(true == if_num_str_is_strobogrammatic("88"));
        assert(true == if_num_str_is_strobogrammatic("818"));

        /*
         * Test 3: Test using a strings which are not strobogrammatic but
         *         contain '1', '0', '8', '6', '9'. The digit string should
         *         not be found strobogrammatic.
         */
        assert(false == if_num_str_is_strobogrammatic("81968"));
        assert(false == if_num_str_is_strobogrammatic("81918"));

        /*
         * Test 4: Test using a strings which are not strobogrammatic but
         *         contain all of the digits. The digit string should
         *         not be found strobogrammatic.
         */
        assert(false == if_num_str_is_strobogrammatic("156"));
        assert(false == if_num_str_is_strobogrammatic("2347"));

        /*
         * Test 5: Test using single digits strings. The following digit
         *         strings should be strobogrammatic.
         *         '0' -----> strobogrammatic
         *         '1' -----> strobogrammatic
         *         '2' -----> non-strobogrammatic
         *         '3' -----> non-strobogrammatic
         *         '4' -----> non-strobogrammatic
         *         '5' -----> non-strobogrammatic
         *         '6' -----> non-strobogrammatic
         *         '7' -----> non-strobogrammatic
         *         '8' -----> strobogrammatic
         *         '9' -----> non-strobogrammatic
         */
        assert(true == if_num_str_is_strobogrammatic("0"));
        assert(true == if_num_str_is_strobogrammatic("1"));
        assert(false == if_num_str_is_strobogrammatic("2"));
        assert(false == if_num_str_is_strobogrammatic("3"));
        assert(false == if_num_str_is_strobogrammatic("4"));
        assert(false == if_num_str_is_strobogrammatic("5"));
        assert(false == if_num_str_is_strobogrammatic("6"));
        assert(false == if_num_str_is_strobogrammatic("7"));
        assert(true == if_num_str_is_strobogrammatic("8"));
        assert(false == if_num_str_is_strobogrammatic("9"));
    }
}
