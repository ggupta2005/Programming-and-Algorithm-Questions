/*
 * MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA,
 * BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”,
 * column 2 as “B”, column 27 as “AA”. More information on this can be found
 * on this post:-http://www.geeksforgeeks.org/find-excel-column-name-given-number/
 */
import java.io.*;
import java.util.*;

public class get_excel_column_name_from_column_number
{
    public static final int MAX_LEN = 20;

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

    /*
     * This function returns the excel column name for a given column number.
     * If the input number is not valid, then this function returns an empty
     * string.
     */
    public static String get_excel_col_name_from_excel_col_num (int num)
    {
        char[] col_name = new char[MAX_LEN];
        int len, index, char_index;
        String col_str;

        /*
         * If the input column number is less than or equal to zero,
         * then return an empty string
         */
        if (num <= 0) {
            return(new String(""));
        }

        /*
         * Iterate until 'num' is greater than zero
         */
        index = 0;
        while (num > 0) {

            /*
             * Obtain the character index using the modulus
             * operator
             */
            char_index = num % 26;

            /*
             * If the modulus operation results in zero, then
             * set character index to 26 (for character 'Z')
             */
            if (char_index == 0) {
                char_index = 26;
            }

            /*
             * Set the character in the column name
             */
            col_name[index] = (char)((int)'A' + (int)char_index - 1);
            ++index;

            /*
             * Subtract the character index from input column
             * number
             */
            num -= char_index;

            /*
             * Divide the remaining column number by 26
             */
            num /= 26;
        }

        /*
         * Since the column name characters are added in reverse order,
         * so reverse the column name
         */
        col_str = reverse_str(new String(col_name, 0, index));

        /*
         * Return the column name string
         */
        return(col_str);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with invalid column numbers. The column number
         *         should be empty.
         */
        assert("".equals(get_excel_col_name_from_excel_col_num(-52)));
        assert("".equals(get_excel_col_name_from_excel_col_num(0)));

        /*
         * Test 1: Test with column number less than or equal to 26. The
         *         column should be 'A', 'B' and so on.
         */
        assert("A".equals(get_excel_col_name_from_excel_col_num(1)));
        assert("B".equals(get_excel_col_name_from_excel_col_num(2)));
        assert("Z".equals(get_excel_col_name_from_excel_col_num(26)));

        /*
         * Test 2: Test with column number which will return column name
         *         of more than two letters.
         */
        assert("AA".equals(get_excel_col_name_from_excel_col_num(27)));
        assert("AZ".equals(get_excel_col_name_from_excel_col_num(52)));
        assert("ZZ".equals(get_excel_col_name_from_excel_col_num(702)));
    }
}
