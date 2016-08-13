/*
 * This program checks if a string of characters is palindrome or not.
 */
import java.io.*;
import java.util.*;

public class check_if_string_is_palindrome
{
    /*
     * This function returns 'true' if a string is a palindrome and 'false'
     * otherwise.
     */
    public static boolean check_if_str_is_palindrome (String ch)
    {
        int left, right;

        /*
         * If the string pointer is null or the length of string is
         * zero, then this is not a palindromic string. Return 'false'
         * from this function.
         */
        if ((ch == null) || (ch.length() == 0)) {
            return(false);
        }

        /*
         * Set left index to zero
         */
        left = 0;

        /*
         * Set right index to point to the last valid index in the
         * string
         */
        right = ch.length() - 1;

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
            if (ch.charAt(left) != ch.charAt(right)) {
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

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a null string. This string should
         *         not be a palindrome.
         */
        String str0 = null;
        assert(false == check_if_str_is_palindrome(str0));

        /*
         * Test 1: Test with a string of zero length. This string
         *         should not be a palindrome.
         */
        String str1 = "";
        assert(false == check_if_str_is_palindrome(str1));

        /*
         * Test 2: Test with a palindromic string having odd length. This
         *         string should be a palindrome.
         */
        String str2 = "madam";
        assert(true == check_if_str_is_palindrome(str2));

        /*
         * Test 3: Test with a palindromic string having even length. This
         *         string should be a palindrome.
         */
        String str3 = "abba";
        assert(true == check_if_str_is_palindrome(str3));

        /*
         * Test 4: Test with a non-palindromic string having odd length.
         *         This string should not be a palindrome.
         */
        String str4 = "madum";
        assert(false == check_if_str_is_palindrome(str4));

        /*
         * Test 5: Test with a non-palindromic string having even length.
         *         This string should not be a palindrome.
         */
        String str5 = "abca";
        assert(false == check_if_str_is_palindrome(str5));
    }
}
