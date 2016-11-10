/*
 * This porgram reverses a character string. For example if the input
 * string is "armed", then the reversed string should be "demra".
 */
import java.io.*;
import java.util.*;

public class reverse_character_string
{
    /*
     * This function reverses a character string. The time complexity of
     * this function is O(n) and the space complexity of this function
     * is O(1).
     */
    public static String reverse_str (String ch)
    {
        int left, right;
        char[] array;

        /*
         * If the character array is null then return null
         */
        if (ch == null) {
            return(null);
        }

        /*
         * If the length of string is zero, then return
         * empty string from this function.
         */
        if (ch.length() == 0) {
            return(new String(""));
        }

        /*
         * Convert string into character array
         */
        array = ch.toCharArray();

        /*
         * Set left to zero
         */
        left = 0;

        /*
         * Set right to the last charater in the string
         */
        right = array.length - 1;

        /*
         * Iterate until left index is less than right index
         */
        while (left < right) {

            /*
             * If left indexed character is not same as the
             * right indexed character, then swap the characters
             * using the xor operator.
             */
            if (array[left] != array[right]) {

                array[left] ^= array[right];
                array[right] ^= array[left];
                array[left] ^= array[right];
            }

            /*
             * Increment the left index
             */
            ++left;

            /*
             * Decrement the right index
             */
            --right;
        }

        return(new String(array));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with the null string. The return string should
         *         be null.
         */
        String ch0 = null;
        String exp0 = null;
        assert(exp0 == reverse_str(ch0));

        /*
         * Test 1: Test with an empty string. The return string should
         *         be empty.
         */
        String ch1 = "";
        String exp1 = "";
        assert(exp1.equals(reverse_str(ch1)));

        /*
         * Test 2: Test with a string having only one character. The
         *         return string should be same as test string.
         */
        String ch2 = "a";
        String exp2 = "a";
        assert(exp2.equals(reverse_str(ch2)));

        /*
         * Test 3: Test with a string having only one character type of
         *         character. The return string should have the same
         *         character.
         */
        String ch3 = "aaa";
        String exp3 = "aaa";
        assert(exp3.equals(reverse_str(ch3)));

        /*
         * Test 4: Test with a string having different alphabetical
         *         characters. This string should get reversed.
         */
        String ch4 = "armed";
        String exp4 = "demra";
        assert(exp4.equals(reverse_str(ch4)));

        /*
         * Test 5: Test with a string having different alphabetical
         *         characters and spaces. This string should get reversed.
         */
        String ch5 = "armed forces";
        String exp5 = "secrof demra";
        assert(exp5.equals(reverse_str(ch5)));

        /*
         * Test 6: Test with a string having different special characters and
         *         digits. This string should get reversed.
         */
        String ch6 = "@%^894!%";
        String exp6 = "%!498^%@";
        assert(exp6.equals(reverse_str(ch6)));

        /*
         * Test 7: Test with a string which is a palindrome. The return
         *         string should be same as the test string.
         */
        String ch7 = "radar";
        String exp7 = "radar";
        assert(exp7.equals(reverse_str(ch7)));
    }

}
