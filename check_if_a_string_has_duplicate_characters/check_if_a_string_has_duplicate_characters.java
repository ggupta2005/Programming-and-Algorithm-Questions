/*
 * This program checks if a string has duplicate characters.
 */
import java.io.*;
import java.util.*;

public class check_if_a_string_has_duplicate_characters
{
    public static final int NUM_POSSIBLE_CHARACTERS = 1 << 16;

    /*
     * This function checks if a characte string has duplicate characters. If the
     * character string has duplicate characters, then this function returns 'true'
     * otherwise this function returns false'. This function uses the following
     * approach to find if there are duplicate characters in a string:-
     * 1. Sort the string
     * 2. Compare the consecutive characters in the character array to find
     *    if they are equal. In case they are equal return 'true'.
     * 3. If we reach towards the end of the function, then return 'false' as
     *    here are no duplicate characters in the string.
     * The time complexity of this function is O(n*log(n)), where 'n' is the
     * number of characters in either string. The time complexity of the
     * function depends on the time taken by sorting which could be O(n^2)
     * in worst case.
     * The space complexity of this function is O(n) since we convert string
     * into character array.
     */
    public static boolean check_if_a_str_has_duplicate_chars_v1 (String ch)
    {
        int len, i, j;
        char[] array;

        /*
         * If the string is null or its length is zero, then return
         * 'false'
         */
        if ((ch == null) || (ch.length() == 0)) {
            return(false);
        }

        /*
         * Sort the characters of the string
         */
        array = ch.toCharArray();
        Arrays.sort(array);

        len = array.length;

        /*
         * Iterate through the character array to find if any of the
         * consecutive characters are same. IF so, then return 'true'.
         */
        for (i = 0; i < (len - 1); ++i) {

            /*
             * If the consecutive characters are same, then return 'true'
             */
            if (array[i] == array[i+1]) {
                return(true);
            }
        }

        /*
         * Return 'false' if no duplicate characters are found
         */
        return(false);
    }

    /*
     * This function checks if a characte string has duplicate characters. If the
     * character string has duplicate characters, then this function returns 'true'
     * otherwise this function returns false'. This function uses the following
     * approach to find if there are duplicate characters in a string:-
     * 1. Iterate over the length of the string to see if there exists another
     *    another character which same as the character under test. If so,
     *    then return 'true'.
     * The time complexity of this function is O(n^2), where 'n' is the
     * number of characters in either string.
     * The space complexity of this function is O(1).
     */
    public static boolean check_if_a_str_has_duplicate_chars_v2 (String ch)
    {
        int len, i, j;

        /*
         * If the string is null or its length is zero, then return
         * 'false'
         */
        if ((ch == null) || (ch.length() == 0)) {
            return(false);
        }

        len = ch.length();

        /*
         * For a given character in the array, check if there are any characters
         * on the right which are same as the current character.
         */
        for (i = 0; i < (len - 1); ++i) {
            for (j = i + 1; j < len; ++j) {

                /*
                 * If the ith character is same as the jth character, then
                 * return true, as a duplicate character exists
                 */
                if (ch.charAt(i) == ch.charAt(j)) {
                    return(true);
                }
            }
        }

        /*
         * Return 'false' if no duplicate characters are found
         */
        return(false);
    }

    /*
     * This function checks if a characte string has duplicate characters. If the
     * character string has duplicate characters, then this function returns 'true'
     * otherwise this function returns false'. This function uses the following
     * approach to find if there are duplicate characters in a string:-
     * 1. Define a count array to record the if a particular character has been
     *    found in the character array previously. Initialize this array to 0.
     * 2. Iterate over the character and map the characters into the cout array
     * 3. If the mapped character in the count array is zero, then increment the
     *    array entry by one otherwise we this mapped entry in the count array
     *    is a duplicate character. Return 'true', from this function.
     * 4. If we reach towards the end of the function, then return 'false' as
     *    here are no duplicate characters in the string.
     * The time complexity of this function is O(n), where 'n' is the
     * number of characters in either string sinze we iterate through the
     * character array once.
     * The space complexity of this function is O(m) where 'm' is the number
     * of characters suported by the programming language.
     */
    public static boolean check_if_a_str_has_duplicate_chars_v3 (String ch)
    {
        int len, i;
        int[] count;
        char mapped_char;

        /*
         * If the string is null or its length is zero, then return
         * 'false'
         */
        if ((ch == null) || (ch.length() == 0)) {
            return(false);
        }

        len = ch.length();

        /*
         * Allocate the count array
         */
        count = new int[NUM_POSSIBLE_CHARACTERS];

        /*
         * If the count array allocatio fails, the return 'false'
         */
        if (count == null) {
            return(false);
        }

        /*
         * Iterate over the entire array and map the characters of the string
         * into the count array
         */
        for (i = 0; i < len; ++i) {

            mapped_char = ch.charAt(i);

            /*
             * If the value of the count array in the mapped character slot is
             * non-zero, then we have found a duplicate character. Return 'true'
             */
            if (count[(int)mapped_char] == 1) {
                return(true);
            } else {

                /*
                 * Increment the count array for the mapped character
                 */
                count[(int)mapped_char]++;
            }
        }

        /*
         * Return 'false' if no duplicate characters are found
         */
        return(false);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a null string. This should not be character array
         *         having duplicate characters
         */
        String str0 = null;
        assert(false == check_if_a_str_has_duplicate_chars_v1(str0));
        assert(false == check_if_a_str_has_duplicate_chars_v2(str0));
        assert(false == check_if_a_str_has_duplicate_chars_v3(str0));

        /*
         * Test 1: Test with an empty string. This should not be character
         *         array having duplicate characters
         */
        String str1 = "";
        assert(false == check_if_a_str_has_duplicate_chars_v1(str1));
        assert(false == check_if_a_str_has_duplicate_chars_v2(str1));
        assert(false == check_if_a_str_has_duplicate_chars_v3(str1));

        /*
         * Test 2: Test with a string having duplicate characters. This should
         *         not be character array having duplicate characters
         */
        String str2 = "geeks";
        assert(true == check_if_a_str_has_duplicate_chars_v1(str2));
        assert(true == check_if_a_str_has_duplicate_chars_v2(str2));
        assert(true == check_if_a_str_has_duplicate_chars_v3(str2));

        /*
         * Test 3: Test with a string having no duplicate characters. This
         *         should not be character array having duplicate characters
         */
        String str3 = "water";
        assert(false == check_if_a_str_has_duplicate_chars_v1(str3));
        assert(false == check_if_a_str_has_duplicate_chars_v2(str3));
        assert(false == check_if_a_str_has_duplicate_chars_v3(str3));

        /*
         * Test 4: Test with a string having a single character. This
         *         should not be character array having duplicate characters
         */
        String str4 = "w";
        assert(false == check_if_a_str_has_duplicate_chars_v1(str4));
        assert(false == check_if_a_str_has_duplicate_chars_v2(str4));
        assert(false == check_if_a_str_has_duplicate_chars_v3(str4));
    }
}
