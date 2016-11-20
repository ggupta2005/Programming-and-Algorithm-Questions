/*
 * This program finds the minimum of number of character deletions in order
 * to make two strings anagrams of each other. For example if the strings are
 * "bcadeh" and "hea", then the number of characters to be removed from
 * "bcadeh" are three ('b', 'c' and 'd') so that the two strings can become
 * anagrams each other. The characters could be removed from either of the
 * strings. For more information on this:-
 * http://www.geeksforgeeks.org/remove-minimum-number-characters-two-strings-become-anagram/
 */
import java.io.*;
import java.util.*;

public class
    find_minimum_number_of_character_deletions_to_make_two_string_anagrams
{
    public static final int MAX_CHARACTERS = 1 << 16;

    /*
     * This function determines the number of characters to be deleted either
     * 'str1' or 'str2' in order to make the two strings anagrams of each
     * other. The time complexity of this function is O(m + n), where 'm' and
     * 'n' is the number of characters in the two strings. The space complexity
     * of this function is O(1) since we use character arrayes for statistics
     * which do not depend on the size of the input strings.
     */
    public static int find_minimum_num_char_del_make_two_str_anagrams (
                                                String str1, String str2)
    {
        int[] stats1 = new int [MAX_CHARACTERS];
        int[] stats2 = new int [MAX_CHARACTERS];
        int index, len1, len2;
        int mapped_char, total_deletions;

        /*
         * If both strings are null, then return zero as no characters
         * need to be deleted from either of the strings
         */
        if ((str1 == null) && (str2 == null)) {
            return(0);
        }

        /*
         * If the first string is null, then all characters of the second
         * string need to be deleted so return the length of the second
         * string
         */
        if (str1 == null) {
            return(str2.length());
        }

        /*
         * If the second string is null, then all characters of the first
         * string need to be deleted so return the length of the first
         * string
         */
        if (str2 == null) {
            return(str1.length());
        }

        /*
         * If both strings are empty, then return zero as no characters
         * need to be deleted from either of the strings
         */
        if ((str1.length() == 0) && (str2.length() == 0)) {
            return(0);
        }

        /*
         * If the first string is empty, then all characters of the second
         * string need to be deleted so return the length of the second
         * string
         */
        if (str1.length() == 0) {
            return(str2.length());
        }

        /*
         * If the second string is empty, then all characters of the first
         * string need to be deleted so return the length of the first
         * string
         */
        if (str2.length() == 0) {
            return(str1.length());
        }

        /*
         * Store the lengths of the two strings
         */
        len1 = str1.length();
        len2 = str2.length();

        /*
         * Map each character of the first string into the stats array
         * and increment the stats if needed
         */
        for (index = 0; index < len1; ++index) {
            mapped_char = str1.charAt(index);
            stats1[(int)mapped_char]++;
        }

        /*
         * Map each character of the second string into the stats array
         * and increment the stats if needed
         */
        for (index = 0; index < len2; ++index) {
            mapped_char = str2.charAt(index);
            stats2[(int)mapped_char]++;
        }

        /*
         * Set the total number of deletions to zero
         */
        total_deletions = 0;

        /*
         * For each character find the difference in the number of
         * such a character in the first string and the second string
         * and add to the total number of deletions
         */
        for (index = 0; index < MAX_CHARACTERS; ++index) {
            total_deletions += (stats1[index] - stats2[index]) > 0 ?
                                stats1[index] - stats2[index] :
                                stats2[index] - stats1[index];
        }

        /*
         * Return the total number of deletions found
         */
        return(total_deletions);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with both strings as null. The total number of
         *         deletions to make strings anagrams should be zero.
         */
        String first_str0 = null;
        String second_str0 = null;
        assert(0 ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str0, second_str0));

        /*
         * Test 1: Test with first string as null and second string
         *         as non-null. The total number of deletions to make
         *         strings anagrams should be the number characters in
         *         second string.
         */
        String first_str1 = null;
        String second_str1 = "aab";
        assert(second_str1.length() ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str1, second_str1));

        /*
         * Test 2: Test with second string as null and first string
         *         as non-null. The total number of deletions to make
         *         strings anagrams should be the number characters in
         *         first string.
         */
        String first_str2 = "aab";
        String second_str2 = null;
        assert(first_str2.length() ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str2, second_str2));

        /*
         * Test 3: Test with both strings as empty. The total number of
         *         deletions to make strings anagrams should be zero.
         */
        String first_str3 = "";
        String second_str3 = "";
        assert(0 ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str3, second_str3));

        /*
         * Test 4: Test with second string as empty and first string
         *         as non-empty. The total number of deletions to make
         *         strings anagrams should be the number characters in
         *         first string.
         */
        String first_str4 = "ytru";
        String second_str4 = "";
        assert(first_str4.length() ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str4, second_str4));

        /*
         * Test 5: Test with first string as empty and second string
         *         as non-empty. The total number of deletions to make
         *         strings anagrams should be the number characters in
         *         second string.
         */
        String first_str5 = "";
        String second_str5 = "ytur";
        assert(second_str5.length() ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str5, second_str5));

        /*
         * Test 6: Test a case when both strings are anagrams of each
         *         other. The total number of deletions to make strings
         *         anagrams should be zero.
         */
        String first_str6 = "abdce";
        String second_str6 = "edcba";
        assert(0 ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str6, second_str6));

        /*
         * Test 7: Test a case when both strings have some common characters
         *         and some uncommon characters. The total number of deletions
         *         to make strings anagrams should be non-zero.
         */
        String first_str7 = "abdceiou";
        String second_str7 = "edcbbaa";
        assert(5 ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str7, second_str7));

        /*
         * Test 8: Test a case when all characters of one string are contained
         *         in the second string. The total number of deletions to make
         *         strings anagrams should be the difference between the
         *         lengths of the two strings.
         */
        String first_str8 = "abdceiou";
        String second_str8 = "edcba";
        assert(first_str8.length() - second_str8.length() ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str8, second_str8));
        assert(first_str8.length() - second_str8.length() ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                second_str8, first_str8));

        /*
         * Test 9: Test a case when both strings have no common characters.
         *         The total number of deletions to make strings anagrams
         *         should be sum of the lengths of the two strings.
         */
        String first_str9 = "tmnlp";
        String second_str9 = "edcba";
        assert(second_str9.length() + first_str9.length() ==
                find_minimum_num_char_del_make_two_str_anagrams(
                                                first_str9, second_str9));
    }
}
