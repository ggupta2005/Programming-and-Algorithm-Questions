/*
 * This program checks if some permutation of a string can be a palindrome.
 * For example:- permutation of "aac', "aca" is a palindrome but any
 * permutation of "abc" cannot be a palindrome.
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

/*
 * Maximum number characters possible in C programming language
 */
#define MAX_NUM_CHARS       1 << (sizeof(char) * CHAR_BIT)

/*
 * This function returns 'true' if some permutation of a string can be
 * palindrome and 'false' otherwise. The time complexity of this function
 * O(n), where 'n' is the number of characters in the string and the
 * space complexity of the function is O(1).
 */
bool check_if_str_permutation_is_palindrome (char* ch)
{
    int len, index;
    int stat[MAX_NUM_CHARS];
    int mapped_char;
    int number_of_odd_numbered_chars;

    /*
     * If the character string is NULL, then return 'false'
     */
    if (!ch) {
        return(false);
    }

    /*
     * If the character string is empty, then return 'true'
     */
    if (!strlen(ch)) {
        return(true);
    }

    /*
     * Clear the character stats array
     */
    memset(stat, 0, sizeof(stat));

    len = strlen(ch);

    /*
     * Map all the characters of 'ch' into 'stat' and
     * increment the mapped character array entry
     */
    for (index = 0; index < len; ++index) {
        mapped_char = ch[index] + (MAX_NUM_CHARS / 2);

        if (mapped_char >= MAX_NUM_CHARS) {
            return(false);
        }

        stat[mapped_char]++;
    }

    /*
     * Find the number of characters which occur odd number of times
     * in the character stats array
     */
    number_of_odd_numbered_chars = 0;
    for (index = 0; index < MAX_NUM_CHARS; ++index) {
        if ((stat[index] % 2) == 1) {
            number_of_odd_numbered_chars++;
        }
    }

    if ((len % 2) == 0) {

        /*
         * If the length of the string is even, then there should
         * not be any character which occurs odd number of times
         * in the string if the permutation of the string has to
         * be palindrome. If so, then return 'false'.
         */
        if (number_of_odd_numbered_chars > 0) {
            return(false);
        }
    } else {

        /*
         * If the length of the string is odd, then there should
         * be at most one character which occurs odd number of times
         * in the string if the permutation of the string has to
         * be palindrome. If so, then return 'false'.
         */
        if (number_of_odd_numbered_chars > 1) {
            return(false);
        }
    }

    /*
     * Return 'true' since the premutation of this string can be
     * a palindrome.
     */
    return(true);
}

int main ()
{
    /*
     * Test 0: Test with a NULL string. The permutation of this
     *         string cannot be a palindrome.
     */
    char* ch0 = NULL;
    assert(false == check_if_str_permutation_is_palindrome(ch0));

    /*
     * Test 1: Test with an empty string. The permutation of this
     *         string should be a palindrome.
     */
    char* ch1 = "";
    assert(true == check_if_str_permutation_is_palindrome(ch1));

    /*
     * Test 2: Test with a string having odd number of characters with
     *         only one character occurring odd number of times. The
     *         permutation of this string should be a palindrome.
     */
    char* ch2 = "aabbc";
    assert(true == check_if_str_permutation_is_palindrome(ch2));

    /*
     * Test 3: Test with a string having odd number of characters with
     *         more than one character occurring odd number of times.
     *         The permutation of this string should not be a palindrome.
     */
    char* ch3 = "aabac";
    assert(false == check_if_str_permutation_is_palindrome(ch3));

    /*
     * Test 4: Test with a string having even number of characters with
     *         all characters in the string occurring even number of
     *         times. The permutation of this string should be a
     *         palindrome.
     */
    char* ch4 = "aabbccddeffe";
    assert(true == check_if_str_permutation_is_palindrome(ch4));

    /*
     * Test 5: Test with a string having even number of characters with
     *         some characters in the string occurring odd number of
     *         times. The permutation of this string should not be a
     *         palindrome.
     */
    char* ch5 = "aabbccddefge";
    assert(false == check_if_str_permutation_is_palindrome(ch5));

    return(0);
}
