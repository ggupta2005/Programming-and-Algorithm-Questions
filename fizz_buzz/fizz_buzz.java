/*
 * Write a program that outputs the string representation of numbers
 * from 1 to n.
 *
 * But for multiples of three it should output “Fizz” instead of the
 * number and for the multiples of five output “Buzz”. For numbers which
 * are multiples of both three and five output “FizzBuzz”.
 */
import java.io.*;
import java.util.*;

public class fizz_buzz
{
    public static final int THREE = 3;
    public static final int FIVE = 5;
    public static final String FIZZ = "Fizz";
    public static final String BUZZ = "Buzz";

    /*
     * This function returns an array of strings which contains the numbers
     * as is or the multiples of three or five are replaced by "fizz" or
     * "Buzz". The numbers which are multiples of both 3 and 5 are replaced
     * by "FizzBuzz". If the input number is less than or equal to zero,
     * then this function returns NULL.
     */
    public static String[] get_fizz_buzz (int n)
    {
        String[] array;
        int index, inner_index;

        /*
         * If 'n' is less than or equal to zero, then return NULL
         */
        if (n <= 0) {
            return(null);
        }

        /*
         * Allocate an array of strings
         */
        array = new String[n];

        /*
         * If the array allocation fails, then return NULL
         */
        if (array == null) {
            return(null);
        }

        /*
         * Iterate from one to 'n' and fill the required value in the
         * character array.
         */
        for (index = 1; index <= n; ++index) {

            /*
             * 1. If 'index' is a multiple of both 3 and 5, then fill
             *    "FizzBuzz" in character array.
             * 2. If 'index' is a multiple of both 3, then fill
             *    "Fizz" in character array.
             * 3. If 'index' is a multiple of both 5, then fill
             *    "Buzz" in character array.
             * 4. If 'index' is not a multiple of both 3 and 5, then fill
             *    number string in character array.
             */
            if ((index % (THREE * FIVE)) == 0) {
                array[index - 1] = new String(FIZZ + BUZZ);
            } else if ((index % THREE) == 0) {
                array[index - 1] = new String(FIZZ);
            } else if ((index % FIVE) == 0) {
                array[index - 1] = new String(BUZZ);
            } else {
                array[index - 1] = new String(Integer.toString(index));
            }
        }

        /*
         * Return the character array
         */
        return(array);
    }
    /*
     * This function checks if all the string array entries in the
     * two arrays are equal. This functionreturns 'true' if the entries
     * are equal and false otherwise.
     */
    public static boolean if_array_of_string_is_equal (String[]array1,
                                                       String[] array2)
    {
        int i;

        /*
         * If lengths of the two string arrays is not legal or they
         * are not equal, then return 'false'.
         */
        if ((array1.length <= 0) || (array2.length <= 0) ||
            (array1.length != array2.length)) {
            return(false);
        }

        /*
         * Iterate over all the array entries
         */
        for (i = 0; i < array1.length; ++i) {

            /*
             * If the two strings are not equal, then return 'false'
             */
            if (array1[i].equals(array2[i]) == false) {
                return(false);
            }
        }

        /*
         * Since both character array entries are equal, so return 'true'
         */
        return(true);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test with 'n' as 15.
         */
        String[] actual_array1 = get_fizz_buzz(15);
        String[] expected_array1 =
                        {
                            "1",
                            "2",
                            "Fizz",
                            "4",
                            "Buzz",
                            "Fizz",
                            "7",
                            "8",
                            "Fizz",
                            "Buzz",
                            "11",
                            "Fizz",
                            "13",
                            "14",
                            "FizzBuzz"
                        };
        assert(true == if_array_of_string_is_equal(actual_array1,
                                                   expected_array1));

        /*
         * Test 2: Test with 'n' as 0.
         */
        int n2 = 0;
        String[] actual_array2 = get_fizz_buzz(n2);
        String[]  expected_array2 = null;
        assert(actual_array2 == expected_array2);

        /*
         * Test 3: Test with 'n' as less than zero.
         */
        int n3 = -10;
        String[] actual_array3 = get_fizz_buzz(n3);
        String[] expected_array3 = null;
        assert(actual_array3 == expected_array3);
    }
}
