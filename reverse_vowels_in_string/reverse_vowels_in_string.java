/*
 * This function reverses the vowels in a string of characters, For example,
 * if the string is "hello", then the reversed string will be "holle"
 */
import java.io.*;
import java.util.*;

public class reverse_vowels_in_string
{
    /*
     * This function returns 'true' if a character is a vowel otherwise
     * this function returns 'false'.
     */
    public static boolean if_char_is_vowel (char ch)
    {
        /*
         * If a character is a lower case vowel, then return 'true'
         */
        if ((ch == 'a') || (ch == 'e') || (ch == 'i') ||
            (ch == 'o') || (ch == 'u')) {
            return(true);
        }

        /*
         * If a character is a upper case vowel, then return 'true'
         */
        if ((ch == 'A') || (ch == 'E') || (ch == 'I') ||
            (ch == 'O') || (ch == 'U')) {
            return(true);
        }

        /*
         * Since the character is not a lower case vowel or upper
         * case character, then return 'false'
         */
        return(false);
    }

    /*
     * This function reverses the vowels in a string. The characters other
     * than a vowel are left unchanged. The time complexity of this function
     * is O(n) and the space complexity of this function is O(1).
     */
    public static String reverse_vowels_in_str (String ch)
    {
        int left, right;
        char[] array;

        /*
         * If the character array is null then return null
         */
        if (ch == null) {
            return(null);
        }

        /*
         * If the length of string is zero, then return
         * empty string from this function.
         */
        if (ch.length() == 0) {
            return(new String(""));
        }

        /*
         * Convert string into character array
         */
        array = ch.toCharArray();

        /*
         * Set left to zero
         */
        left = 0;

        /*
         * Set right to the last charater in the string
         */
        right = array.length - 1;

        /*
         * Iterate until left index is less than right index
         */
        while (left < right) {

            /*
             * If the left indexed character is not a vowel,
             * then we do not reverse the position of this
             * character. So move to the next character.
             */
            if (!if_char_is_vowel(array[left])) {

                /*
                 * Increment the left index
                 */
                ++left;
                continue;
            }

            /*
             * If the right indexed character is not a vowel,
             * then we do not reverse the position of this
             * character. So move to the next character.
             */
            if (!if_char_is_vowel(array[right])) {

                /*
                 * Decrement the right index
                 */
                --right;
                continue;
            }

            /*
             * If left indexed character is not same as the
             * right indexed character, then swap the characters
             * using the xor operator.
             */
            if (array[left] != array[right]) {

                array[left] ^= array[right];
                array[right] ^= array[left];
                array[left] ^= array[right];
            }

            /*
             * Increment the left index
             */
            ++left;

            /*
             * Decrement the right index
             */
            --right;
        }

        return(new String(array));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with the NULL string. The test string should
         *         remain NULL.
         */
        String ch0 = null;
        String exp0 = null;
        assert(exp0 == reverse_vowels_in_str(ch0));

        /*
         * Test 1: Test with an empty string. The test string should
         *         remain empty.
         */
        String ch1 = "";
        String exp1 = "";
        assert(exp1.equals(reverse_vowels_in_str(ch1)));

        /*
         * Test 2: Test with a string having two same vowels. The test
         *         string should remain same.
         */
        String ch2 = "ee";
        String exp2 = "ee";
        assert(exp2.equals(reverse_vowels_in_str(ch2)));

        /*
         * Test 3: Test with a string having one vowel. The test
         *         string should remain same.
         */
        String ch3 = "I";
        String exp3 = "I";
        assert(exp3.equals(reverse_vowels_in_str(ch3)));

        /*
         * Test 4: Test with a string having mix of vowels and other
         *         characters. The order of vowels should get reversed.
         */
        String ch4 = "hello";
        String exp4 = "holle";
        assert(exp4.equals(reverse_vowels_in_str(ch4)));

        /*
         * Test 5: Test with a string having mix of upper case and
         *         lower case vowels and other characters. The order
         *         of vowels should get reversed.
         */
        String ch5 = "hEllo You";
        String exp5 = "hullo YoE";
        assert(exp5.equals(reverse_vowels_in_str(ch5)));

        /*
         * Test 6: Test with a string having no vowels. The string
         *         should remain the same.
         */
        String ch6 = "ykljhtf";
        String exp6 = "ykljhtf";
        assert(exp6.equals(reverse_vowels_in_str(ch6)));

        /*
         * Test 7: Test with a string having one vowel. The string
         *         should remain the same.
         */
        String ch7 = "yklojhtf";
        String exp7 = "yklojhtf";
        assert(exp7.equals(reverse_vowels_in_str(ch7)));

        /*
         * Test 8: Test with a string having only vowels. The string
         *         should be reversed.
         */
        String ch8 = "EiouaIO";
        String exp8 = "OIauoiE";
        assert(exp8.equals(reverse_vowels_in_str(ch8)));
    }
}
