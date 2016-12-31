/*
 * This program checks if some permutation of a string can be a palindrome.
 * For example:- permutation of "aac', "aca" is a palindrome but any
 * permutation of "abc" cannot be a palindrome.
 */
import java.io.*;
import java.util.*;

public class check_if_string_permutation_is_palindrome
{
    public static final int NUM_POSSIBLE_CHARACTERS = 1 << 16;

    /*
     * This function returns 'true' if some permutation of a string can be
     * palindrome and 'false' otherwise. The time complexity of this function
     * O(n), where 'n' is the number of characters in the string and the
     * space complexity of the function is O(1).
     */
    public static boolean check_if_str_permutation_is_palindrome
                                                            (String ch)
    {
        int len, index;
        int[] stat = new int[NUM_POSSIBLE_CHARACTERS];
        int mapped_char;
        int number_of_odd_numbered_chars;

        /*
         * If the character string is null, then return 'false'
         */
        if (ch == null) {
            return(false);
        }

        /*
         * If the character string is empty, then return 'true'
         */
        if (ch.length() == 0) {
            return(true);
        }

        len = ch.length();

        /*
         * Map all the characters of 'ch' into 'stat' and
         * increment the mapped character array entry
         */
        for (index = 0; index < len; ++index) {
            mapped_char = (int)ch.charAt(index);
            stat[mapped_char]++;
        }

        /*
         * Find the number of characters which occur odd number of times
         * in the character stats array
         */
        number_of_odd_numbered_chars = 0;
        for (index = 0; index < NUM_POSSIBLE_CHARACTERS; ++index) {
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

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a null string. The permutation of this
         *         string cannot be a palindrome.
         */
        String ch0 = null;
        assert(false == check_if_str_permutation_is_palindrome(ch0));

        /*
         * Test 1: Test with an empty string. The permutation of this
         *         string should be a palindrome.
         */
        String ch1 = "";
        assert(true == check_if_str_permutation_is_palindrome(ch1));

        /*
         * Test 2: Test with a string having odd number of characters with
         *         only one character occurring odd number of times. The
         *         permutation of this string should be a palindrome.
         */
        String ch2 = "aabbc";
        assert(true == check_if_str_permutation_is_palindrome(ch2));

        /*
         * Test 3: Test with a string having odd number of characters with
         *         more than one character occurring odd number of times.
         *         The permutation of this string should not be a palindrome.
         */
        String ch3 = "aabac";
        assert(false == check_if_str_permutation_is_palindrome(ch3));

        /*
         * Test 4: Test with a string having even number of characters with
         *         all characters in the string occurring even number of
         *         times. The permutation of this string should be a
         *         palindrome.
         */
        String ch4 = "aabbccddeffe";
        assert(true == check_if_str_permutation_is_palindrome(ch4));

        /*
         * Test 5: Test with a string having even number of characters with
         *         some characters in the string occurring odd number of
         *         times. The permutation of this string should not be a
         *         palindrome.
         */
        String ch5 = "aabbccddefge";
        assert(false == check_if_str_permutation_is_palindrome(ch5));
    }
}
