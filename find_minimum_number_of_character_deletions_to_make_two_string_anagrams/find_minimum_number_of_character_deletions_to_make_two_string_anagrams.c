/*
 * This program finds the minimum of number of character deletions in order
 * to make two strings anagrams of each other. For example if the strings are
 * "bcadeh" and "hea", then the number of characters to be removed from
 * "bcadeh" are three ('b', 'c' and 'd') so that the two strings can become
 * anagrams each other. The characters could be removed from either of the
 * strings. For more information on this:-
 * http://www.geeksforgeeks.org/remove-minimum-number-characters-two-strings-become-anagram/
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>

#define BITS_PER_BYTE        8
#define MAX_CHARACTERS       (sizeof(char) << BITS_PER_BYTE)

/*
 * This function determines the number of characters to be deleted either
 * 'str1' or 'str2' in order to make the two strings anagrams of each
 * other. The time complexity of this function is O(m + n), where 'm' and
 * 'n' is the number of characters in the two strings. The space complexity
 * of this function is O(1) since we use character arrayes for statistics
 * which do not depend on the size of the input strings.
 */
int find_minimum_num_char_del_make_two_str_anagrams (
                                            char* str1, char* str2)
{
    int stats1[MAX_CHARACTERS], stats2[MAX_CHARACTERS];
    int index, len1, len2;
    int mapped_char, total_deletions;

    /*
     * If both strings are NULL, then return zero as no characters
     * need to be deleted from either of the strings
     */
    if (!str1 && !str2) {
        return(0);
    }

    /*
     * If the first string is NULL, then all characters of the second
     * string need to be deleted so return the length of the second
     * string
     */
    if (!str1) {
        return(strlen(str2));
    }

    /*
     * If the second string is NULL, then all characters of the first
     * string need to be deleted so return the length of the first
     * string
     */
    if (!str2) {
        return(strlen(str1));
    }

    /*
     * If both strings are empty, then return zero as no characters
     * need to be deleted from either of the strings
     */
    if (!strlen(str1) && !strlen(str2)) {
        return(0);
    }

    /*
     * If the first string is empty, then all characters of the second
     * string need to be deleted so return the length of the second
     * string
     */
    if (!strlen(str1)) {
        return(strlen(str2));
    }

    /*
     * If the second string is empty, then all characters of the first
     * string need to be deleted so return the length of the first
     * string
     */
    if (!strlen(str2)) {
        return(strlen(str1));
    }

    /*
     * Store the lengths of the two strings
     */
    len1 = strlen(str1);
    len2 = strlen(str2);

    /*
     * Clear the stats array for both the strings
     */
    memset(stats1, 0, MAX_CHARACTERS * sizeof(char));
    memset(stats2, 0, MAX_CHARACTERS * sizeof(char));

    /*
     * Map each character of the first string into the stats array
     * and increment the stats if needed
     */
    for (index = 0; index < len1; ++index) {
        mapped_char = str1[index] + MAX_CHARACTERS/2;
        stats1[mapped_char]++;
    }

    /*
     * Map each character of the second string into the stats array
     * and increment the stats if needed
     */
    for (index = 0; index < len2; ++index) {
        mapped_char = str2[index] + MAX_CHARACTERS/2;
        stats2[mapped_char]++;
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

int main ()
{
    /*
     * Test 0: Test with both strings as NULL. The total number of
     *         deletions to make strings anagrams should be zero.
     */
    char* first_str0 = NULL;
    char* second_str0 = NULL;
    assert(0 ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str0, second_str0));

    /*
     * Test 1: Test with first string as NULL and second string
     *         as non-NULL. The total number of deletions to make
     *         strings anagrams should be the number characters in
     *         second string.
     */
    char* first_str1 = NULL;
    char* second_str1 = "aab";
    assert(strlen(second_str1) ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str1, second_str1));

    /*
     * Test 2: Test with second string as NULL and first string
     *         as non-NULL. The total number of deletions to make
     *         strings anagrams should be the number characters in
     *         first string.
     */
    char* first_str2 = "aab";
    char* second_str2 = NULL;
    assert(strlen(first_str2) ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str2, second_str2));

    /*
     * Test 3: Test with both strings as empty. The total number of
     *         deletions to make strings anagrams should be zero.
     */
    char* first_str3 = "";
    char* second_str3 = "";
    assert(0 ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str3, second_str3));

    /*
     * Test 4: Test with second string as empty and first string
     *         as non-empty. The total number of deletions to make
     *         strings anagrams should be the number characters in
     *         first string.
     */
    char* first_str4 = "ytru";
    char* second_str4 = "";
    assert(strlen(first_str4) ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str4, second_str4));

    /*
     * Test 5: Test with first string as empty and second string
     *         as non-empty. The total number of deletions to make
     *         strings anagrams should be the number characters in
     *         second string.
     */
    char* first_str5 = "";
    char* second_str5 = "ytur";
    assert(strlen(second_str5) ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str5, second_str5));

    /*
     * Test 6: Test a case when both strings are anagrams of each
     *         other. The total number of deletions to make strings
     *         anagrams should be zero.
     */
    char* first_str6 = "abdce";
    char* second_str6 = "edcba";
    assert(0 ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str6, second_str6));

    /*
     * Test 7: Test a case when both strings have some common characters
     *         and some uncommon characters. The total number of deletions
     *         to make strings anagrams should be non-zero.
     */
    char* first_str7 = "abdceiou";
    char* second_str7 = "edcbbaa";
    assert(5 ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str7, second_str7));

    /*
     * Test 8: Test a case when all characters of one string are contained
     *         in the second string. The total number of deletions to make
     *         strings anagrams should be the difference between the
     *         lengths of the two strings.
     */
    char* first_str8 = "abdceiou";
    char* second_str8 = "edcba";
    assert(strlen(first_str8) - strlen(second_str8) ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str8, second_str8));
    assert(strlen(first_str8) - strlen(second_str8) ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            second_str8, first_str8));

    /*
     * Test 9: Test a case when both strings have no common characters.
     *         The total number of deletions to make strings anagrams
     *         should be sum of the lengths of the two strings.
     */
    char* first_str9 = "tmnlp";
    char* second_str9 = "edcba";
    assert(strlen(second_str9) + strlen(first_str9) ==
            find_minimum_num_char_del_make_two_str_anagrams(
                                            first_str9, second_str9));
    return(0);
}
