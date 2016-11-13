/*
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string. If the last
 * word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space
 *       characters only.
 *
 * For example,
 * Given s = "Hello World", return 5.
 */
import java.io.*;
import java.util.*;

public class find_the_length_of_last_word_in_a_string
{
    /*
     * This function finds the length of the last word in a string. The
     * word in a collection of all charaters except the space character.
     * The time complexity of this function is O(n), where 'n' is the
     * number of characters in the input string. The space complexity of
     * this function is O(1).
     */
    public static int find_length_last_word_in_str (String s)
    {
        int len;
        int index;
        int last_word_len;

        /*
         * If string is NULL or the length of string is zero,
         * then return zero as the length of the last word.
         */
        if ((s == null) || (s.length() == 0)) {
            return(0);
        }

        /*
         * Get the length of the input string
         */
        len = s.length();

        /*
         * Set 'index' to the last character in the string
         */
        index = len - 1;

        /*
         * Set the length of the last word in the string to
         * zero
         */
        last_word_len = 0;

        /*
         * Iterate until we reach the beginning of the string
         * and bypass all space characters in the string
         */
        while ((index >= 0) && (s.charAt(index) == ' ')) {
            --index;
        }

        /*
         * If we reached a non-space character in the string,
         * iterate until we reach the beginning of the string or
         * encounter a space character
         */
        while((index >= 0) && (s.charAt(index) != ' ')) {
            --index;

            /*
             * Increment the last word length counter
             */
            ++last_word_len;
        }

        /*
         * Return the length of the last word in the string
         */
        return(last_word_len);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a NULL string. The length of the
         *         last word in string should be zero.
         */
        assert(0 == find_length_last_word_in_str(null));

        /*
         * Test 1: Test with an empty string. The length of the
         *         last word in string should be zero.
         */
        assert(0 == find_length_last_word_in_str(""));

        /*
         * Test 2: Test with a string having only white-spaces.
         *         The length of the last word in string should
         *         be zero.
         */
        assert(0 == find_length_last_word_in_str("        "));

        /*
         * Test 3: Test with a string having no white-spaces and
         *         one word. The length of the last word in string
         *         should be equal to length of the string.
         */
        assert("havingblast".length() ==
                    find_length_last_word_in_str("havingblast"));

        /*
         * Test 4: Test with a string having white-spaces in beginning
         *         and one word in the strig. The length of the last word
         *         in string should be equal to length of the last word
         *         in the string.
         */
        assert("havingblast".length() ==
                    find_length_last_word_in_str("    havingblast"));

        /*
         * Test 5: Test with a string having white-spaces in the end
         *         and one word in the strig. The length of the last word
         *         in string should be equal to length of the last word
         *         in the string.
         */
        assert("havingblast".length() ==
                    find_length_last_word_in_str("havingblast   "));

        /*
         * Test 6: Test with a string having white-spaces and
         *         multiple words. The length of the last word in
         *         string should be equal to length of the string.
         */
        assert("blast".length() ==
                find_length_last_word_in_str(
                                "   everyone having a   blast  "));
    }
}
