/*
 * Given a string and an integer k, you need to reverse the first k
 * characters for every 2k characters counting from the start of the
 * string. If there are less than k characters left, reverse all of them.
 * If there are less than 2k but greater than or equal to k characters,
 * then reverse the first k characters and left the other as original.
 *
 * Example:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 */
import java.io.*;
import java.util.*;

public class reverse_string_in_alternate_groups_of_size_k
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
     * This fuction reverses alternate sections of 'k' characters in
     * the input string. The time complexity of this function is O(n),
     * where 'n' is the number of characters in the input string. The
     * space complexity of this function is O(1).
     */
    public static String
            reverse_str_in_alternate_groups_of_size_k (String s, int k)
    {
        String result = null;
        int i, len, chunk, low, high;
        char[] ch;

        /*
         * If the input string is not valid, then return null
         */
        if (s == null) {
            return(null);
        }

        len = s.length();

        /*
         * If the length of the string is zero, then return
         * an empty string
         */
        if (len == 0) {
            result = new String("");
            return(result);
        }

        /*
         * If the input chuck is not valid, then return the copy of the
         * input string.
         */
        if (k <= 0) {
            result = new String(s);
            return(result);
        }

        /*
         * Convert the input string to character array
         */
        ch = s.toCharArray();

        chunk = 0;
        i = 0;

        /*
         * Iterate through the length of the string
         */
        while (i < len) {

            /*
             * If this is an even numbered chunk, then reverse this
             * chunk
             */
            if (chunk % 2 == 0) {

                /*
                 * Compute the lower index of the section
                 */
                low = i;

                /*
                 * Compute the upper index of the section
                 */
                high = ((i + k - 1) > (len - 1) ? (len -1) : (i + k - 1));

                /*
                 * Reverse the section between the upper and lower
                 * index values
                 */
                reverse_section(ch, low, high);
            }

            i += k;

            /*
             * Increment the chuck number
             */
            ++chunk;
        }

        /*
         * Return the reversed string
         */
        result = new String(ch);
        return(result);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a null string. The string in which
         *         every alternate characters are reversed should
         *         be null.
         */
        assert(null == reverse_str_in_alternate_groups_of_size_k(null, 3));
        assert(null == reverse_str_in_alternate_groups_of_size_k(null, 0));

        /*
         * Test 1: Test with an empty string. The string in which
         *         every alternate characters are reversed should
         *         be empty.
         */
        assert("".equals(
                       reverse_str_in_alternate_groups_of_size_k("", 3)));
        assert("".equals(
                       reverse_str_in_alternate_groups_of_size_k("", 0)));

        /*
         * Test 2: Test with a valid string but an invalid value of 'k'.
         *         The string in which every alternate characters are reversed
         *         should be same as the input string.
         */
        assert("abcdefgh".equals(
                 reverse_str_in_alternate_groups_of_size_k("abcdefgh", 0)));
        assert("abcdefgh".equals(
                 reverse_str_in_alternate_groups_of_size_k("abcdefgh", -3)));

        /*
         * Test 3: Test with a valid string and a valid value of 'k'. The
         *         output string should the one in which every alternate
         *         characters are reversed in the input string.
         */
        assert("bacdfegh".equals(
                 reverse_str_in_alternate_groups_of_size_k("abcdefgh", 2)));
        assert("cbadefhg".equals(
                 reverse_str_in_alternate_groups_of_size_k("abcdefgh", 3)));

        /*
         * Test 4: Test with a valid string and a valid value of 'k' which is
         *         greater than the length of the input string. The output
         *         string should be the reverse of the input string.
         */
        assert("hgfedcba".equals(
                 reverse_str_in_alternate_groups_of_size_k(
                                     "abcdefgh", "abcdefgh".length() + 1)));

        /*
         * Test 5: Test with a valid string and a valid value of 'k' which is
         *         one. The output string should be same as the input string.
         */
        assert("abcdefgh".equals(
                 reverse_str_in_alternate_groups_of_size_k("abcdefgh", 1)));
    }
}
