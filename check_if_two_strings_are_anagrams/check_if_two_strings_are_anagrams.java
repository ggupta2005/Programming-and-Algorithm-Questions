/*
 * This program tests if two strings are anagrams of each other.
 * Two strings are called anagrams, if all characters in the first
 * string can be used to form the permutation of the second string.
 * For example, "fghtyy" is an anagram of "yyhgtf" but "fghtyy" is
 * not an anagram of "yygghy"
 */
import java.io.*;
import java.util.*;

public class check_if_two_strings_are_anagrams
{
    public static final int NUM_POSSIBLE_CHARACTERS = 1 << 16;

    /*
     * This function returns 'true' if the two strings are anagrams of
     * each of other and 'false' otherwise. This function uses the following
     * approach to test whether two strings are anagrams of each other:-
     * 1. Sort the strings using sorting routine provided by java.
     * 2. Compare the strings character by character to find if any
     *    characters mis-match. If there is a mis-match then return
     *    'false' other wise return 'true'.
     * The time complexity of this function is O(n*log(n)), where 'n'
     * is the number of characters in either string. The time complexity
     * of the function depends on the time taken by sort routine provided by
     * by java.
     * The space complexity of this function is O(n), where 'n' is the number
     * characters in either string.
     */
    public static boolean if_two_strings_are_anagrams_v1 (String str1, String str2)
    {
        int i, j;
        char[] array1;
        char[] array2;

        /*
         * If either string in null, then return 'false' as
         * we cannot do anagram computation
         */
        if ((str1 == null) || (str2 == null)) {
            return(false);
        }

        /*
         * If th strings are of un-equal lengths, then the strings
         * are not anagrams of each other. Return 'false'.
         */
        if (str1.length() != str2.length()) {
            return(false);
        }

        /*
         * Convert the string to character arrays
         */
        array1 = str1.toCharArray();
        array2 = str2.toCharArray();

        /*
         * Sort both the strings using quick-sort
         */
        Arrays.sort(array1);
        Arrays.sort(array2);

        /*
         * Walk both the sorted strings and match each character
         * in string one with corresponding character in string two.
         * Return 'false' if there is a mis-match.
         */
        for (i = 0; i < array1.length; ++i) {
            if (array1[i] != array2[i]) {
                return(false);
            }
        }

        /*
         * Return 'true' as no mis-match in the sorted strings was
         * detected.
         */
        return(true);
    }

    /*
     * This function returns 'true' if the two strings are anagrams of
     * each of other and 'false' otherwise. This function uses the following
     * approach to test whether two strings are anagrams of each other:-
     * 1. Map all the characters of string one into a character statistics
     *    array. This array has size that is equal to the number of possible
     *    characters in this programming language. If more than one character
     *    occurs in the same string, then increment the mapped character
     *    statistics
     * 2. Map all the characters of string two into another character
     *    statistics array.
     * 3. Compare the two character statistics array. They should be equal
     *    element to element if the strings are anagrams of each other.
     * The time complexity of this function is O(n), where 'n' is the number
     * of characters in either string.
     * The space complexity of the function depends on the number of characters
     * in the character set supported by this programming language as we use
     * two character statistics arrays to record the character stats.
     */
    public static boolean if_two_strings_are_anagrams_v2 (String str1, String str2)
    {
        int i, j;
        int[] char_stats1 = new int[NUM_POSSIBLE_CHARACTERS];
        int[] char_stats2 = new int[NUM_POSSIBLE_CHARACTERS];
        char mapped_char;

        /*
         * If either string in NULL, then return 'false' as
         * we cannot do anagram computation
         */
        if ((str1 == null) || (str2 == null)) {
            return(false);
        }

        /*
         * If th strings are of un-equal lengths, then the strings
         * are not anagrams of each other. Return 'false'.
         */
        if (str1.length() != str2.length()) {
            return(false);
        }

        /*
         * Map all the characters of 'str1' into 'char_stats1' and
         * all characters of 'str2' into 'char_stats2'
         */
        for (i = 0; i < str1.length(); ++i) {
            mapped_char = str1.charAt(i);
            char_stats1[(int)mapped_char]++;

            mapped_char = str2.charAt(i);
            char_stats2[(int)mapped_char]++;
        }

        /*
         * Walk both the character stats array and match each value
         * in stats one with corresponding value in stats two.
         * Return 'false' if there is a mis-match.
         */
        for (i = 0; i < NUM_POSSIBLE_CHARACTERS; ++i) {
            if (char_stats1[i] != char_stats2[i]) {
                return(false);
            }
        }

        /*
         * Return 'true' as no mis-match in the char stats was
         * detected.
         */
        return(true);
    }

    /*
     * This function returns 'true' if the two strings are anagrams of
     * each of other and 'false' otherwise. This function uses the following
     * approach to test whether two strings are anagrams of each other:-
     * 1. Map all the characters of string one into a character statistics
     *    array. This array has size that is equal to the number of possible
     *    characters in this programming language. If more than one character
     *    occurs in the same string, then increment the mapped character
     *    statistics
     * 2. Map all the characters of string two into the same character
     *    statistics array. But this time decrement the count in the mapped
     *    array element.
     * 3. Compare the character statistics array elements to zero. If any
     *    element of the mapped character array is non-zero, then the two
     *    strings are not anagrams of each other.
     * The time complexity of this function is O(n), where 'n' is the number
     * of characters in either string.
     * The space complexity of the function depends on the number of characters
     * in the character set supported by this programming language as we use
     * one character statistics array to record the character stats (both at the
     * time of increment and decrement).
     */
    public static boolean if_two_strings_are_anagrams_v3 (String str1, String str2)
    {
        int i, j;
        int[] char_stats = new int[NUM_POSSIBLE_CHARACTERS];
        char mapped_char;

        /*
         * If either string in NULL, then return 'false' as
         * we cannot do anagram computation
         */
        if ((str1 == null) || (str2 == null)) {
            return(false);
        }

        /*
         * If th strings are of un-equal lengths, then the strings
         * are not anagrams of each other. Return 'false'.
         */
        if (str1.length() != str2.length()) {
            return(false);
        }

        /*
         * Map all the characters of 'str1' into 'char_stats' and
         * increment the mapped character array entry
         */
        for (i = 0; i < str1.length(); ++i) {
            mapped_char = str1.charAt(i);
            char_stats[(int)mapped_char]++;
        }

        /*
         * Map all the characters of 'str2' into 'char_stats' and
         * decrement the mapped character array entry
         */
        for (i = 0; i < str2.length(); ++i) {
            mapped_char = str2.charAt(i);
            char_stats[(int)mapped_char]--;
        }

        /*
         * Check if any of the array entries for stats is non-zero.
         * If so, then return 'false'
         */
        for (i = 0; i < NUM_POSSIBLE_CHARACTERS; ++i) {
            if (char_stats[i] != 0) {
                return(false);
            }
        }

        /*
         * Return 'true' as the strings as anagrams
         */
        return(true);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: If either of the strings are null, then the strings
         *         are not anagram of each other.
         */
        String first0 = null;
        String second0 = null;
        assert(false == if_two_strings_are_anagrams_v1(first0, second0));
        assert(false == if_two_strings_are_anagrams_v2(first0, second0));
        assert(false == if_two_strings_are_anagrams_v3(first0, second0));

        /*
         * Test 1: If both the strings are of length zero, then the strings
         *         are anagram of each other.
         */
        String first1 = "";
        String second1 = "";
        assert(true == if_two_strings_are_anagrams_v1(first1, second1));
        assert(true == if_two_strings_are_anagrams_v2(first1, second1));
        assert(true == if_two_strings_are_anagrams_v3(first1, second1));

        /*
         * Test 2: If both the strings are of unequal length, then the strings
         *         are not anagram of each other.
         */
        String first2 = "ats";
        String second2 = "cats";
        assert(false == if_two_strings_are_anagrams_v1(first2, second2));
        assert(false == if_two_strings_are_anagrams_v2(first2, second2));
        assert(false == if_two_strings_are_anagrams_v3(first2, second2));

        /*
         * Test 3: If both the strings are of equal length and have the same
         *         set of characters, then the strings are anagram of each other.
         */
        String first3 = "dats";
        String second3 = "adts";
        assert(true == if_two_strings_are_anagrams_v1(first3, second3));
        assert(true == if_two_strings_are_anagrams_v2(first3, second3));
        assert(true == if_two_strings_are_anagrams_v3(first3, second3));

        /*
         * Test 4: If both the strings are of equal length but have different
         *         set of characters, then the strings are not anagram of each
         *         other.
         */
        String first4 = "cats";
        String second4 = "yats";
        assert(false == if_two_strings_are_anagrams_v1(first4, second4));
        assert(false == if_two_strings_are_anagrams_v2(first4, second4));
        assert(false == if_two_strings_are_anagrams_v3(first4, second4));

        /*
         * Test 5: If both the strings are of equal length and have the same
         *         set of characters multiple times, then the strings are anagram
         *         of each other.
         */
        String first5 = "ddattttss";
        String second5 = "ssttttadd";
        assert(true == if_two_strings_are_anagrams_v1(first5, second5));
        assert(true == if_two_strings_are_anagrams_v2(first5, second5));
        assert(true == if_two_strings_are_anagrams_v3(first5, second5));
    }
}
