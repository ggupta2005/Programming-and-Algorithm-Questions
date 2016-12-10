/*
 * This program finds the index of first non-repeating character in a string.
 * If there are no non-repeating characters in the string, then the program
 * returns '-1'. More information on this, please visit the post:-
 * https://leetcode.com/problems/first-unique-character-in-a-string/
 */
import java.io.*;
import java.util.*;

public class find_index_of_first_non_repeating_char_in_string
{
    /*
     * Maximum number of characters availble in this programming
     * language
     */
    public static final int NUM_POSSIBLE_CHARACTERS = 1 << 16;

    /*
     * Value of illegal index in the character stats array
     */
    public static final int ILLEGAL_INDEX = -1;

    /*
     * Value of duplicate index in the character stats array
     */
    public static final int DUPLICATE_INDEX = -2;

    /*
     * This funtion returns the index of the first non-repeating character
     * in the input string. If no non-repeating character is available in
     * the string, then this function returns '-1'. The time complexity of
     * this function is O(n + C), where 'n' is the number of characters in
     * the imput string and 'C' is the constant cost of getting the minimum
     * index from the character stats array. The space complexity of this
     * function is O(1), since the size of the character array is constant
     * and doesn't depend on the size of the input string.
     */
    public static int find_index_first_non_repeating_char_in_str (String ch)
    {
        int index, len;
        int[] first_non_repeating_index = new int[NUM_POSSIBLE_CHARACTERS];
        int mapped_index;
        int min_non_repeating_index;

        /*
         * If the string is null or the length of the string in zero,
         * then return '-1' (ILLEGAL_INDEX).
         */
        if ((ch == null) || (ch.length() == 0)) {
            return(-1);
        }

        /*
         * Initialize the character stats array with 'ILLEGAL_INDEX'
         */
        for (index = 0; index < NUM_POSSIBLE_CHARACTERS; ++index) {
            first_non_repeating_index[index] = ILLEGAL_INDEX;
        }

        /*
         * Get the length of the string
         */
        len = ch.length();

        /*
         * Iterate through the character array and store the indexes
         * of the characters
         */
        for (index = 0; index < len; ++index) {

            /*
             * Map the value of the character to a valid positive
             * number
             */
            mapped_index = ch.charAt(index);

            if (first_non_repeating_index[mapped_index]
                                                == ILLEGAL_INDEX) {
                /*
                 * If the character was not mapped in the stats array
                 * previously, then map the array index of the character
                 * in the stats array
                 */
                first_non_repeating_index[mapped_index] = index;
            } else if (first_non_repeating_index[mapped_index]
                                                != DUPLICATE_INDEX) {

                /*
                 * If the character was already mapped in the stats array
                 * previously, then mark the character index as duplicate
                 * in the stats array
                 */
                first_non_repeating_index[mapped_index] = DUPLICATE_INDEX;
            }
        }

        /*
         * Set the index for first non-repeating character variable to be
         * 'ILLEGAL_INDEX' and iterate oer the character stats array
         */
        min_non_repeating_index = ILLEGAL_INDEX;
        for (index = 0; index < NUM_POSSIBLE_CHARACTERS; ++index) {

            /*
             * If the current element has a valid index value, then update
             * minimum index variable
             */
            if ((first_non_repeating_index[index] != ILLEGAL_INDEX) &&
                (first_non_repeating_index[index] != DUPLICATE_INDEX)) {
                if (min_non_repeating_index == ILLEGAL_INDEX) {

                    /*
                     * If minimum index variable is 'ILLEGAL_INDEX', then
                     * copy the index value into it
                     */
                    min_non_repeating_index =
                                    first_non_repeating_index[index];
                } else {
                    if (min_non_repeating_index >
                            first_non_repeating_index[index]) {

                        /*
                         * If the minimum index value is not 'ILLEGAL_INDEX',
                         * then update it if character stats array entry is
                         * less than minimum index value.
                         */
                        min_non_repeating_index =
                                    first_non_repeating_index[index];

                    }
                }
            }
        }

        /*
         * Return the index value for first non-repeating
         * character in the string
         */
        return(min_non_repeating_index);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with null string. The index value for first
         *         non-repeating character in the string should be
         *         'ILLEGAL_INDEX'.
         */
        assert(-1 == find_index_first_non_repeating_char_in_str(null));

        /*
         * Test 1: Test with empty string. The index value for first
         *         non-repeating character in the string should be
         *         'ILLEGAL_INDEX'.
         */
        assert(-1 == find_index_first_non_repeating_char_in_str(""));

        /*
         * Test 2: Test with string having some non-repeated characters
         *         including the first character. The index value for first
         *         non-repeating character in the string should be
         *         zero.
         */
        assert(0 == find_index_first_non_repeating_char_in_str("geekcode"));

        /*
         * Test 3: Test with string having some non-repeated characters
         *         excluding the first character. The index value for first
         *         non-repeating character in the string should be
         *         non-zero.
         */
        assert(2 ==
                find_index_first_non_repeating_char_in_str("govegeekcode"));

        /*
         * Test 4: Test with a string having only one character. The index
         *         value for first non-repeating character in the string
         *         should be zero.
         */
        assert(0 == find_index_first_non_repeating_char_in_str("a"));

        /*
         * Test 5: Test with a string having multiple same character.
         *         The index value for first non-repeating character in
         *         the string should be 'ILLEGAL_INDEX'.
         */
        assert(-1 == find_index_first_non_repeating_char_in_str("aaa"));

        /*
         * Test 6: Test with a string having multiple same characters.
         *         The index value for first non-repeating character in
         *         the string should be 'ILLEGAL_INDEX'.
         */
        assert(-1 == find_index_first_non_repeating_char_in_str("aadadaad"));
    }
}
