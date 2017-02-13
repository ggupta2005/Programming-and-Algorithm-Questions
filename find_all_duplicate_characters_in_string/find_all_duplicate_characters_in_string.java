/*
 * This program finds all the duplicate characters in a given string.
 * For more information on this problem, please refer to the folloiwng
 * link:- http://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
 */
import java.io.*;
import java.util.*;

public class find_all_duplicate_characters_in_string
{
    /*
     * Maximum number of possible characters in this programming language
     */
    public static final int NUM_POSSIBLE_CHARACTERS = 1 << 16;

    /*
     * This function returns the duplicate characters in a given string of
     * characters in sorted order. If the string is not valid then this
     * function returns null. If there are no duplicate characters in the
     * string, then this function returns null. The time complexity of this
     * function is O(n), where 'n' is the number of characters in the string.
     * The space complexity of this function is O(1).
     */
    public static String find_all_duplicate_characters_in_str (String ch)
    {
        char[] char_stats = new char[NUM_POSSIBLE_CHARACTERS];
        int index, len, num_duplicates, duplicate_index;
        char mapped_char;
        char[] duplicates;

        /*
         * If the character string is null, then return null
         */
        if (ch == null) {
            return(null);
        }

        len = ch.length();

        /*
         * Iterate over the entire string and map the characters of the string
         * into the count array
         */
        for (index =- 0; index < len; ++index) {

            mapped_char = ch.charAt(index);

            if (mapped_char >= NUM_POSSIBLE_CHARACTERS) {
                continue;
            }

            /*
             * Increment the count array for the mapped character
             */
            char_stats[(int)mapped_char]++;
        }

        /*
         * Find the number of duplicate characters detected in the input
         * string
         */
        num_duplicates = 0;
        for (index = 0; index < NUM_POSSIBLE_CHARACTERS; ++index) {
            if (char_stats[index] > 1) {
                num_duplicates++;
            }
        }

        /*
         * Allocate the string for the duplicate characters
         */
        duplicates = new char[num_duplicates];

        /*
         * If the memory allocation fails, then return null
         */
        if (duplicates == null) {
            return(null);
        }

        /*
         * Make a pass of the stats array and the characters into the
         * duplicate character array
         */
        duplicate_index = 0;
        for (index = 0; index < NUM_POSSIBLE_CHARACTERS; ++index) {

            /*
             * If the character was found to be duplicate in the input
             * string then add the character into the duplicate character
             * array.
             */
            if (char_stats[index] > 1) {
                duplicates[duplicate_index] = (char)index;
                duplicate_index++;
            }
        }

        /*
         * Return the string containing the duplicate characters
         */
        return(new String(duplicates));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: If the input string is null, then the duplicate character
         *         string should be null.
         */
        assert(null == find_all_duplicate_characters_in_str(null));

        /*
         * Test 1: If the input string does not contain any duplicate
         *         characters, then the duplicate character string should be
         *         empty.
         */
        assert("".equals(find_all_duplicate_characters_in_str("abc")));

        /*
         * Test 2: Test with an input string having one duplicate character.
         *         The duplicate character string should contian this character
         *         only.
         */
        assert("a".equals(find_all_duplicate_characters_in_str("aabc")));

        /*
         * Test 3: Test with an input string having all characters as
         *         duplicates. The duplicate character string should contian
         *         all the characters in sorted order.
         */
        assert("abc".equals(find_all_duplicate_characters_in_str("aabccb")));

        /*
         * Test 4: Test with an input string having some characters as
         *         duplicates and some which are not duplicates. The duplicate
         *         character string should only contian the duplicate
         *         characters in sorted order.
         */
        assert("egks".equals(
                    find_all_duplicate_characters_in_str("geeksforgeeks")));
    }
}
