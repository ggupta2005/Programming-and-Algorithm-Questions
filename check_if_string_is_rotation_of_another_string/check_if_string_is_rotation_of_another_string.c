/*
 * This program finds if a given string a rotation of another string.
 * For example the string "abcde" is a rotation of "eabcd", "deabc" and
 * "cdeab". For more information on this problem, please visit the link:-
 * http://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other-or-not/
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

/*
 * This function returns 'true' if the first string is a rotation of the second
 * string and 'false' otherwise. We use the following the approach to test this:-
 * 1. Construct the double string for the 'second' string. So if the second string
 *    is "eabcd", then the double string for this string is "eabcdeabcd"
 * 2. We then try to see if the first string is a sub-string of the doubled second
 *    string. If so then the two strings are rotations of each other.
 * The time complexity of this function is O(n), where 'n' is the number of characters
 * in the string. The time complexity of the function depends on the implementation
 * of string functions strcat() and strstr().
 * The space complexity of this function is O(n), since we allocate a temporary buffer
 * for the second string.
 */
bool check_if_first_str_is_rotation_of_second_str (char* first,
                                                   char* second)
{
    char* double_second;
    int first_len, second_len;

    /*
     * If either of the first or the second string is NULL of their lengths
     * are zero, then return 'false'
     */
    if (!first || !second || !strlen(first) || !strlen(second)) {
        return(false);
    }

    /*
     * If the length of the first string is not same as the second string,
     * then the two strings cannot be rotations of each other. So return
     * 'false'
     */
    if (strlen(first) != strlen(second)) {
        return(false);
    }

    first_len = strlen(first);
    second_len = strlen(second);

    /*
     * Allocate memory for the second string to construct the concatenate
     * version of the second string
     */
    double_second = (char*)malloc(2 * second_len + 1);

    /*
     * If the memory allocation fails, then return 'false'
     */
    if (!double_second) {
        return(false);
    }

    memset(double_second, 0, 2 * second_len + 1);

    /*
     * Construct the double string for the second string by concatenating the
     * second string twice in the 'double_string'
     */
    strcat(double_second, second);
    strcat(double_second, second);

    /*
     * Check if the first string is a substring of the second string. IF so,
     * then return true.
     */
    if (strstr(double_second, first)) {

        /*
         * The memory allocated for second string
         */
        free(double_second);
        return(true);
    }

    /*
     * The memory allocated for second string
     */
    free(double_second);

    /*
     * The two strings are not rotations of each other, so return false
     */
    return(false);
}

int main ()
{
    /*
     * Test 1: The two strings are rotation of each other
     */
    char* str1 = "abcde";
    char* str_rotate1 = "eabcd";
    assert(true == check_if_first_str_is_rotation_of_second_str(str1, str_rotate1));
    assert(true == check_if_first_str_is_rotation_of_second_str(str_rotate1, str1));

    /*
     * Test 2: One string is a sub-string of another but the number of characters in
     *         the two strings are not equal
     */
    char* str2 = "abcd";
    char* str_rotate2 = "eabcd";
    assert(false == check_if_first_str_is_rotation_of_second_str(str2, str_rotate2));
    assert(false == check_if_first_str_is_rotation_of_second_str(str_rotate2, str2));

    /*
     * Test 3: Both strings have the same characters and same number of characters but
     *         the strings are not rotations of each other
     */
    char* str3 = "abcd";
    char* str_rotate3 = "acbd";
    assert(false == check_if_first_str_is_rotation_of_second_str(str3, str_rotate3));
    assert(false == check_if_first_str_is_rotation_of_second_str(str_rotate3, str3));

    /*
     * Test 4: A single character string is a rotation of itself
     */
    char* str4 = "a";
    char* str_rotate4 = "a";
    assert(true == check_if_first_str_is_rotation_of_second_str(str4, str_rotate4));
    assert(true == check_if_first_str_is_rotation_of_second_str(str_rotate4, str4));

    /*
     * Test 5: One of strings is NULL
     */
    char* str5 = NULL;
    char* str_rotate5 = "a";
    assert(false == check_if_first_str_is_rotation_of_second_str(str5, str_rotate5));
    assert(false == check_if_first_str_is_rotation_of_second_str(str_rotate5, str5));

    /*
     * Test 6: One of strings has zero length
     */
    char* str6 = "";
    char* str_rotate6 = "a";
    assert(false == check_if_first_str_is_rotation_of_second_str(str6, str_rotate6));
    assert(false == check_if_first_str_is_rotation_of_second_str(str_rotate6, str6));

    return(0);
}
