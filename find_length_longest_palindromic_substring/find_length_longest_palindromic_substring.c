/*
 * This program finds the length of the longest palindromic substring
 * in a string. For more information on the problem, please visit the
 * following link: http://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

/*
 * This function returns the length of the longest palindromic substring
 * in a given string. If there is no palindromic substring of length
 * greater than one, then this function returns one. If the input string
 * is not valid, then this function returns zero as the the length of the
 * longest palindromic substring. The time complexity of this function is
 * O(n^2) where 'n' is the number of number of characters in the string.
 * The space complexity of this function is O(1).
 */
int get_length_longest_palindromic_substring (char* ch)
{
    int inner_index, index, max_len, cur_len, len;

    /*
     * If the input string is NULL or its length is zero,
     * then return zero
     */
    if (!ch || !strlen(ch)) {
        return(0);
    }

    len = strlen(ch);

    /*
     * Set the maximum length of palindromic string to zero
     */
    max_len = 0;

    /*
     * Iterate over the length of the entire string
     */
    for (index = 0; index < len; ++index) {

        inner_index = index;

        /*
         * Find the length for the odd length palindromic string with the
         * central character being at 'index'.
         */
        cur_len = 1;
        for (inner_index = 1;
             ((index - inner_index) >= 0) && ((index + inner_index) < len);
             ++inner_index) {

            if (ch[index - inner_index] == ch[index + inner_index]) {

                /*
                 * If the equi-distant characters around 'index' are equal,
                 * then increment the length of current palindromic sub-string
                 * by two
                 */
                cur_len += 2;
            } else {

                /*
                 * Since the characters are not same, so break
                 */
                break;
            }
        }

        /*
         * If the length of the odd length palindromic substring is greater
         * than the current maximum length, then update the maximum length
         */
        if (cur_len > max_len) {
            max_len = cur_len;
        }

        /*
         * Find the length for the evem length palindromic string with finding
         * the matching character starting at 'index'.
         */
        cur_len = 0;
        for (inner_index = 1;
             ((index - (inner_index - 1)) >= 0)
                                        && ((index + inner_index) < len);
             ++inner_index) {

            /*
             * If the two characters are same, then increment the length of
             * current palindromic sub-string by two
             */
            if (ch[index - (inner_index - 1)] == ch[index + inner_index]) {
                cur_len += 2;
            } else {

                /*
                 * Since the characters are not same, so break
                 */
                break;
            }
        }

        /*
         * If the length of the even length palindromic substring is greater
         * than the current maximum length, then update the maximum length
         */
        if (cur_len > max_len) {
            max_len = cur_len;
        }
    }

    /*
     * Return the length of longest palindromic substring
     */
    return(max_len);
}

int main ()
{
    /*
     * Test 0: Test the case when the input string is NULL or empty.
     *         The length of longest palindromic substring should be
     *         zero.
     */
    assert(0 == get_length_longest_palindromic_substring(NULL));
    assert(0 == get_length_longest_palindromic_substring(""));

    /*
     * Test 1: Test the case when there is only one palindromic
     *         substring in the input string and its length is odd.
     */
    assert(1 == get_length_longest_palindromic_substring("a"));
    assert(3 == get_length_longest_palindromic_substring("aba"));
    assert(5 == get_length_longest_palindromic_substring("zabcbau"));

    /*
     * Test 2: Test the case when there is only one palindromic
     *         substring in the input string and its length is even.
     */
    assert(2 == get_length_longest_palindromic_substring("aa"));
    assert(4 == get_length_longest_palindromic_substring("xabbaz"));

    /*
     * Test 3: Test the case when there are many palindromic substrings
     *         within a string but the length of the longest palindromic
     *         substring is returned.
     */
    assert(10 == get_length_longest_palindromic_substring(
                                                    "abbaxbbbbbbbbbb"));
    assert(11 == get_length_longest_palindromic_substring(
                                              "abbbbbbbbbaxbbbbbbbbbb"));

    /*
     * Test 4: Test the case when there are no palindromic substrings of
     *         length greater than one.
     */
    assert(1 == get_length_longest_palindromic_substring("water"));
    assert(1 == get_length_longest_palindromic_substring("waterwater"));

    return(0);
}
