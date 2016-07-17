/*
 * This program compresses the string in the following manner:-
 * string "aaabbbbcccaaa" -> "a3b4c3a3"
 * string "abcdeeeeeeeee" -> "a1b1c1d1e9"
 * If the compresses string's length is greater than the original
 * string, then the program returns the string itself.
 */
import java.io.*;
import java.util.*;

public class string_compression
{

    /*
     * This function compresses a given character string and returns the
     * compressed string. The time complexity of this function is O(n),
     * where 'n' is the number of characters in the character string.
     */
    public static String string_compression (String input)
    {
        char[] result;
        char[] ch;
        int i, count, j, k, len;
        char[] count_to_str;
        String result_string;

        /*
         * If the character string is null or its length is zero, then
         * Return null
         */
        if ((input == null) || (input.length() == 0)) {
            return(null);
        }

        /*
         * Get the character array for the input string
         */
        ch = input.toCharArray();

        /*
         * Get the length of the character array
         */
        len = ch.length;

        /*
         * The length of the compressed string can be twice as long the
         * input string. So allocate a separate memory for the compressed
         * string
         */
        result = new char[2 * len + 1];

        /*
         * If the string allocation fail, then return null.
         */
        if (result == null) {
            return(null);
        }

        /*
         * Iterate through the string and do the following:-
         * Compare the current character with the next character
         * If both are same, then increment the 'count'. Otherwise
         * add the current character into the buffer and convert the
         * 'count' into a string and add the numbered string into the
         * buffer.
         */
        i = 0;
        count = 1;
        j = 0;
        while (i < (len - 1)) {
            if (ch[i] == ch[i+1]) {
                /*
                 * Since the current character and the next character are
                 * same, so increment 'count'.
                 */
                ++count;
            } else {
                /*
                 * Add the current character into the return buffer
                 */
                result[j] = ch[i];
                ++j;

                /*
                 * Convert the 'count' into string
                 */
                count_to_str = String.valueOf(count).toCharArray();

                /*
                 * Add the numbered string to the return buffer.
                 */
                if (count_to_str != null) {
                    k = 0;
                    while (k < count_to_str.length) {
                        result[j] = count_to_str[k];
                        ++j; ++k;
                    }
                }

                /*
                 * Reset count to maintain loop invariance
                 */
                count = 1;
            }

            /*
             * Increment the index into the character string
             */
            ++i;
        }

        /*
         * Since we iterated through the second last character in the
         * string, add the last character and its count to the return
         * buffer.
         */
        result[j] = ch[i];
        ++j;

        count_to_str = String.valueOf(count).toCharArray();

        if (count_to_str != null) {
            k = 0;
            while (k < count_to_str.length) {
                result[j] = count_to_str[k];
                ++j; ++k;
            }
        }

        /*
         * Construct a string from characters within 0 to j
         */
        result_string = new String(result, 0, j);

        /*
         * If the length of the input string is less than the return
         * string, then return the pointer to the input string.
         */
        if (input.length() <= result_string.length()) {
            return(input);
        }

        /*
         * Return the compressed string
         */
        return(String.valueOf(result_string));
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test a string which can be compressed
         */
        String str1 = "aaaabbbcccd";
        String expected_str1 = "a4b3c3d1";
        String actual_str1 = string_compression(str1);
        assert true == expected_str1.equals(actual_str1);

        /*
         * Test 2: Test a string which has only one character
         */
        String str2 = "aaaaaaaaaa";
        String expected_str2 = "a10";
        String actual_str2 = string_compression(str2);
        assert true == expected_str2.equals(actual_str2);

        /*
         * Test 3: Test a string for which compression will give
         *         string larger than the original string
         */
        String str3 = "abcde";
        String expected_str3 = "abcde";
        String actual_str3 = string_compression(str3);
        assert true == expected_str3.equals(actual_str3);

        /*
         * Test 4: Test a string which is null
         */
        String str4 = null;
        String expected_str4 = null;
        String actual_str4 = string_compression(str4);
        assert expected_str4 == actual_str4;

        /*
         * Test 5: Test a string which has only one character
         */
        String str5 = "a";
        String expected_str5 = "a";
        String actual_str5 = string_compression(str5);
        assert true == expected_str5.equals(actual_str5);

        /*
         * Test 6: Test a string whose length is zero
         */
        String str6 = "";
        String expected_str6 = null;
        String actual_str6 = string_compression(str6);
        assert expected_str6 == actual_str6;

        /*
         * Test 7: Test a case in which all characters have same
         *         number of contigous characters
         */
        String str7 = "aaaa....,,,,yyyy////$$$$))))";
        String expected_str7 = "a4.4,4y4/4$4)4";
        String actual_str7 = string_compression(str7);
        assert true == expected_str7.equals(actual_str7);
    }
}
