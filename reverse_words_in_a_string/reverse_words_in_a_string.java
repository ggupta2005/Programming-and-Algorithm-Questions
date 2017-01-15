/*
 * This program reverses the string word by word. A word is defined as a
 * sequence of non-space characters. The input string does not contain
 * leading or trailing spaces and the words are always separated by a
 * single space.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Could you do it in-place without allocating extra space?
 */
import java.io.*;
import java.util.*;

public class reverse_words_in_a_string
{
    /*
     * This function reverses the order of characters in an input string
     * from index position 'low' to index position 'high'. The time
     * complexity of this function is O(n), where 'n' is the number of
     * characters between 'low' and 'high'. The space complexity of this
     * function is O(1).
     */
    public static void reverse_section (char[] s, int low, int high)
    {
        /*
         * If the input string is invalid or the indexed positions
         * 'low' and 'high' are not valid, then return.
         */
        if ((s == null) || (low < 0) || (high < 0) || (high <= low)) {
            return;
        }

        /*
         * Iterate until 'low' is less than 'high'
         */
        while (low < high) {

            /*
             * Swap the characters using xor operator
             */
            s[low] ^= s[high];
            s[high] ^= s[low];
            s[low] ^= s[high];

            /*
             * Increment the low index
             */
            ++low;

            /*
             * Decrement the high index
             */
            --high;
        }
    }

    /*
     * This function reverses an input string word by word. The time
     * complexity of this function is O(n), where 'n' is the number of
     * characters between 'low' and 'high'. The space complexity of this
     * function is O(1).
     */
    public static String reverse_words_in_string (String s)
    {
        int high, low, len, index;
        char[] ch;

        /*
         * If input string is invalid, then return null
         */
        if (s == null) {
            return(null);
        }

        /*
         * If the string is empty, then return empty string
         */
        if (s.length() == 0) {
            return(new String(""));
        }

        /*
         * Store the length of the string
         */
        len = s.length();

        /*
         * Convert the string to character array
         */
        ch = s.toCharArray();

        /*
         * Reverse the entire string
         */
        reverse_section(ch, 0, len - 1);

        /*
         * Set both index 'low' and 'high' to zero
         */
        low = 0;
        high = 0;
        do {

            /*
             * Find the end index of a word
             */
            while ((high < len) && (ch[high] != ' ')) {
                ++high;
            }

            if (high <= len) {

                /*
                 * Reverse the current word spanning from
                 * 'low' to 'high - 1'
                 */
                reverse_section(ch, low, high - 1);
            }

            /*
             * Move to the beginning of the next word
             */
            low = high;
            while ((low < len) && (ch[low] == ' ')) {
                ++low;
            }

            /*
             * Set both index 'low' and 'high' to starting
             * of the next word
             */
            high = low;

        } while (low < len); /* Continue until there is a
                                valid word in the string */

        return(new String(ch));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a null string. The string after calling
         *         the function for reversing words in the string should
         *         be null.
         */
        assert(null == reverse_words_in_string(null));

        /*
         * Test 1: Test with an empty string. The string after calling
         *         the function for reversing words in the string should
         *         be empty.
         */
        assert("".equals(reverse_words_in_string("")));

        /*
         * Test 2: Test with a string containing many words. The string
         *         after calling the function for reversing words in the
         *         string should have the words reversed.
         */
        assert("blue is sky the".equals(reverse_words_in_string(
                                                    "the sky is blue")));

        /*
         * Test 3: Test with a string containing only one word. The string
         *         after calling the function for reversing words in the
         *         string should be unchanged.
         */
        assert("character".equals(reverse_words_in_string(
                                                    "character")));

        /*
         * Test 4: Test with a string containing only one letter. The string
         *         after calling the function for reversing words in the
         *         string should be unchanged.
         */
        assert("a".equals(reverse_words_in_string("a")));
    }
}
