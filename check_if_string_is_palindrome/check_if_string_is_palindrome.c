/*
 * This program checks if a string of characters is palindrome or not.
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

/*
 * This function returns 'true' if a string is a palindrome and 'false'
 * otherwise.
 */
bool check_if_str_is_palindrome (char* ch)
{
    int len, left, right;

    /*
     * If the string pointer is NULL or the length of string is
     * zero, then this is not a palindromic string. Return 'false'
     * from this function.
     */
    if (!ch || !strlen(ch)) {
        return(false);
    }

    /*
     * Get the length of the string
     */
    len = strlen(ch);

    /*
     * Set left index to zero
     */
    left = 0;

    /*
     * Set right index to point to the last valid index in the
     * string
     */
    right = len - 1;

    /*
     * Iterate until left index is strictly less than the right
     * index
     */
    while (left < right) {

        /*
         * If the character at the left index is not equal to
         * character at right index, then this string is not a
         * palindrome. Return 'false'.
         */
        if (ch[left] != ch[right]) {
            return(false);
        }

        /*
         * Increment left index
         */
        ++left;

        /*
         * Decrement right index
         */
        --right;
    }

    /*
     * Return 'true' as the string is palindrome
     */
    return(true);
}

int main ()
{
    /*
     * Test 0: Test with a NULL string. This string should
     *         not be a palindrome.
     */
    char* str0 = NULL;
    assert(false == check_if_str_is_palindrome(str0));

    /*
     * Test 1: Test with a string of zero length. This string
     *         should not be a palindrome.
     */
    char* str1 = "";
    assert(false == check_if_str_is_palindrome(str1));

    /*
     * Test 2: Test with a palindromic string having odd length. This
     *         string should be a palindrome.
     */
    char* str2 = "madam";
    assert(true == check_if_str_is_palindrome(str2));

    /*
     * Test 3: Test with a palindromic string having even length. This
     *         string should be a palindrome.
     */
    char* str3 = "abba";
    assert(true == check_if_str_is_palindrome(str3));

    /*
     * Test 4: Test with a non-palindromic string having odd length.
     *         This string should not be a palindrome.
     */
    char* str4 = "madum";
    assert(false == check_if_str_is_palindrome(str4));

    /*
     * Test 5: Test with a non-palindromic string having even length.
     *         This string should not be a palindrome.
     */
    char* str5 = "abca";
    assert(false == check_if_str_is_palindrome(str5));

    return(0);
}
