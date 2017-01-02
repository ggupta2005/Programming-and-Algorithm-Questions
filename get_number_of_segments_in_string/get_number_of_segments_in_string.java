/*
 * Count the number of segments in a string, where a segment is defined
 * to be a contiguous sequence of non-space characters. Please note that
 * the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 */
import java.io.*;
import java.util.*;

public class get_number_of_segments_in_string
{
    /*
     * This function returns the number of segments in a string which are
     * separated by spaces. If the input string is not valid or the string
     * is empty or if the string contains only spaces, then this function
     * returns zero. The time complexity of this function is O(n), where
     * 'n' is the number of characters in the string. The space complexity
     * of this function is O(1).
     */
    public static int count_segments_in_str (String s)
    {
        int num_segments, index, len;
        boolean if_inside_word;

        /*
         * If the input string is null or it is empty, then return
         * zero.
         */
        if ((s == null) || (s.length() == 0)) {
            return(0);
        }

        /*
         * Get the length of the input string
         */
        len = s.length();

        num_segments = 0;
        if_inside_word = false;

        /*
         * Iterate through the entire string
         */
        for (index = 0; index < len; ++index) {

            if (s.charAt(index) == ' ') {

                /*
                 * If this is a space character, then we are not
                 * inside a word. So set the boolean flag to
                 * 'false'.
                 */
                if_inside_word = false;
            } else {

                /*
                 * If this is a non-space character, then we are
                 * inside a word
                 */
                if (!if_inside_word) {

                    /*
                     * If we enter a word segment for the first
                     * time, then set the boolean flag to 'true'
                     * and increment the number of segments.
                     */
                    if_inside_word = true;
                    ++num_segments;
                }
            }
        }

        /*
         * Return the number of segments in the string
         */
        return(num_segments);
    }

    public static void main(String[] args)
    {
        /*
         * Test 0:  Test with string which are null, empty or having only
         *          white spaces. The number of word segments in such
         *          strings should be zero.
         */
        assert(0 == count_segments_in_str(null));
        assert(0 == count_segments_in_str(""));
        assert(0 == count_segments_in_str("         "));

        /*
         * Test 1: Test with a string having no space characters. The
         *         The number of word segments in this string should be
         *         one.
         */
        assert(1 == count_segments_in_str("abbaa"));

        /*
         * Test 2: Test with the word strings having spaces in the beginning
         *         & end and the same word string having no spaces in the
         *         beginning and end. The number of word segments in all three
         *         strings should be the same.
         */
        assert(5 == count_segments_in_str("Hello, my name is John"));
        assert(5 == count_segments_in_str("     Hello, my name is John"));
        assert(5 == count_segments_in_str("Hello, my name is John     "));

        /*
         * Test 3: Test with a string having word segements of width one.
         */
        assert(10 == count_segments_in_str("a a a a a a a a a a"));
    }
}
