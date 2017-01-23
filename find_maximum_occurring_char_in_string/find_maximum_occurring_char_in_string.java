/*
 * This program finds the maximum occurring character in a string. For more
 * information on this, visit the post:-
 * http://www.geeksforgeeks.org/return-maximum-occurring-character-in-the-input-string/
 */
import java.io.*;
import java.util.*;

public class find_maximum_occurring_char_in_string
{
    /*
     * Maximum number of characters possible in this programming
     * language
     */
    public static final int NUM_POSSIBLE_CHARACTERS = 1 << 16;

    /*
     * This function returns the maximum occuring character in a character
     * string. If more than one character occurs for the maximum time in the
     * input string, then this function returns the character which has the
     * least ascii value. The time complexity of this function is O(n) where
     * 'n' is the number of characters in the input string and the space
     * complexity of this function is O(1).
     */
    public static char maximum_occurring_char_in_string (String ch)
    {
        char result;
        int max_count, count, i, j, len;
        int[] char_stats = new int[NUM_POSSIBLE_CHARACTERS];
        char mapped_char;

        /*
         * If the character string is null or the string is empty, then
         * return zero.
         */
        if ((ch== null) || (ch.length() == 0)) {
            return(0);
        }

        len = ch.length();

        /*
         * Map all the characters of the string to the
         * character stats array.
         */
        for (i = 0; i < len; ++i) {
            mapped_char = ch.charAt(i);
            char_stats[(int)mapped_char]++;
        }

        /*
         * Find the character maximum occuring character in the
         * character stats array.
         */
        max_count = char_stats[0];
        result = 0;
        for (i = 1; i < NUM_POSSIBLE_CHARACTERS; ++i) {

            if (char_stats[i] > max_count) {

                /*
                 * If the frequency of the character in the stats
                 * array is greater than the current maximum, then
                 * update max count and record the ascii value of
                 * character.
                 */
                max_count = char_stats[i];
                result = (char)i;
            } else if (char_stats[i] == max_count) {

                /*
                 * If the frequency of the character in the stats
                 * array is same than the current maximum, then
                 * record the ascii value of character if the ascii
                 * value is smaller than the current ascii value.
                 */
                if ((int)result > i) {
                    result = (char)i;
                }
            }
        }

        return(result);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Find the maximum occurring character from a
         *         alphabetical string.
         */
        String str1 = "geeksforgeeks.org";
        char expected_char1 = 'e';
        char actual_char1;
        actual_char1 = maximum_occurring_char_in_string(str1);
        assert(expected_char1 == actual_char1);

        /*
         * Test 2: Test with a string having multiple characters
         *         which are maximum occuring. The maximum occuring
         *         character should be the one with the smallest
         *         ascii value.
         */
        String str2 = "rreeffggtthhuuuaaa";
        char expected_char2 = 'a';
        char actual_char2;
        actual_char2 = maximum_occurring_char_in_string(str2);
        assert(expected_char2 == actual_char2);

        /*
         * Test 3: Test with a null string. The ascii value of the
         *         maximum occuring character in a null string should
         *         be zero.
         */
        String str3 = null;
        char expected_char3 = 0;
        char actual_char3;
        actual_char3 = maximum_occurring_char_in_string(str3);
        assert(expected_char3 == actual_char3);

        /*
         * Test 4: Test with an empty string. The ascii value of the
         *         maximum occuring character in an empty string should
         *         be zero.
         */
        String str4 = "";
        char expected_char4 = 0;
        char actual_char4;
        actual_char4 = maximum_occurring_char_in_string(str4);
        assert(expected_char4 == actual_char4);
    }
}
