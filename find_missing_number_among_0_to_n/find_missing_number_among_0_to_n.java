/*
 * This program finds the missing number from an array of numbers of size
 * 'n' in which all numbers are within the range 0 to 'n'.
 */
import java.io.*;
import java.util.*;

public class find_missing_number_among_0_to_n
{
    public static final int ILLEGAL = -1;

    /*
     * This function finds the missing number from an array of numbers of
     * size 'n' in which all numbers are within the range 0 to 'n'. If the
     * array is not valid, then this function will return '-1'. This
     * function adds all the numbers in [0, 'n'] and then subtracts the sum
     * of all the elements in the array. The time complexity of this function
     * is O(n), where 'n' is the number of array elements. The space
     * complexity of this function is O(1). This function does two paases
     * over all elements in range [0, 'n'].
     */
    public static int find_missing_number_among_0_to_n_v1 (int[] array)
    {
        int sum, i;
        int len;

        /*
         * If array is null or the length of the array is
         * not valid, then return '-1'.
         */
        if (array == null) {
            return(ILLEGAL);
        }

        sum = 0;
        len = array.length;

        /*
         * First add all numbers from 0 to 'len'
         */
        for (i = 0; i <= len; ++i) {
            sum += i;
        }

        /*
         * From the 'sum' subtract the sum of all the
         * array elements
         */
        for (i = 0; i < len; ++i) {
            sum -= array[i];
        }

        /*
         * Return the missing number
         */
        return(sum);
    }

    /*
     * This function finds the missing number from an array of numbers of
     * size 'n' in which all numbers are within the range 0 to 'n'. If the
     * array is not valid, then this function will return '-1'. This
     * function adds all the numbers in [0, 'n'] and simultaneously subtracts
     * the sum of all the elements in the array. The time complexity of this
     * function is O(n), where 'n' is the number of array elements. The space
     * complexity of this function is O(1). This function does one paases over
     * all elements in range [0, 'n'].
     */
    public static int find_missing_number_among_0_to_n_v2 (int[] array)
    {
        int sum, i, len;

        /*
         * If array is null or the length of the array is
         * not valid, then return '-1'.
         */
        if (array == null) {
            return(ILLEGAL);
        }

        sum = 0;
        len = array.length;

        /*
         * Add all numbers from 0 to 'len' and also subtract
         * the array elements from this 'sum'.
         */
        for (i = 0; i <= len; ++i) {
            sum += i;

            /*
             * If index is less than 'len', then subtract
             * from the sum
             */
            if (i < len) {
                sum -= array[i];
            }
        }

        /*
         * Return the missing number
         */
        return(sum);
    }

    /*
     * This function finds the missing number from an array of numbers of
     * size 'n' in which all numbers are within the range 0 to 'n'. If the
     * array is not valid, then this function will return '-1'. This
     * function adds all the numbers in [0, 'n'] and simultaneously subtracts
     * the sum of all the elements in the array. The time complexity of this
     * function is O(n), where 'n' is the number of array elements. The space
     * complexity of this function is O(1). This function does one paases over
     * all elements in range [0, 'n'].
     */
    public static int find_missing_number_among_0_to_n_v3 (int[] array)
    {
        int sum, i, len;

        /*
         * If array is null or the length of the array is
         * not valid, then return '-1'.
         */
        if (array == null) {
            return(ILLEGAL);
        }

        sum = 0;
        len = array.length;

        /*
         * Add all numbers from 0 to 'len - 1' and also subtract
         * the array elements from this 'sum'.
         */
        for (i = 0; i < len; ++i) {
            sum += i;
            sum -= array[i];
        }

        /*
         * Add 'len' to the sum
         */
        sum += len;

        /*
         * Return the missing number
         */
        return(sum);
    }

    /*
     * This function finds the missing number from an array of numbers of
     * size 'n' in which all numbers are within the range 0 to 'n'. If the
     * array is not valid, then this function will return '-1'. This function
     * xors all the numbers in [0, 'n'] and simultaneously xors the elements
     * in the array from the xor of all elements from [0, 'n']. The time
     * complexity of this function is O(n), where 'n' is the number of array
     * elements. The space complexity of this function is O(1). This function
     * does one paases over all elements in range [0, 'n'].
     */
    public static int find_missing_number_among_0_to_n_v4 (int[] array)
    {
        int sum, i, len;

        /*
         * If array is null or the length of the array is
         * not valid, then return '-1'.
         */
        if (array == null) {
            return(ILLEGAL);
        }

        sum = 0;
        len = array.length;

        /*
         * bitwise XOR all numbers from 0 to 'len - 1' and also
         * xor the array elements from this running xor.
         */
        for (i = 0; i < len; ++i) {
            sum ^= i;
            sum ^= array[i];
        }

        /*
         * Bitwise XOR 'len' to the sum
         */
        sum ^= len;

        /*
         * Return the missing number
         */
        return(sum);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test with null array and legal length. The missing
         *         element returned should be ILLEGAL.
         */
        int[] array1 = null;
        assert(ILLEGAL == find_missing_number_among_0_to_n_v1(array1));
        assert(ILLEGAL == find_missing_number_among_0_to_n_v2(array1));
        assert(ILLEGAL == find_missing_number_among_0_to_n_v3(array1));
        assert(ILLEGAL == find_missing_number_among_0_to_n_v4(array1));

        /*
         * Test 2: Find a missing number from the array which is neither
         *         zero nor the maximum number.
         */
        int array2[] = {0,1,3,4,5,6,7,8,9,10,11,12,13,14,15};
        assert(2 == find_missing_number_among_0_to_n_v1(array2));
        assert(2 == find_missing_number_among_0_to_n_v2(array2));
        assert(2 == find_missing_number_among_0_to_n_v3(array2));
        assert(2 == find_missing_number_among_0_to_n_v4(array2));

        /*
         * Test 3: Find a missing number from the array and the missing
         *         number should be zero.
         */
        int array3[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        assert(0 == find_missing_number_among_0_to_n_v1(array3));
        assert(0 == find_missing_number_among_0_to_n_v2(array3));
        assert(0 == find_missing_number_among_0_to_n_v3(array3));
        assert(0 == find_missing_number_among_0_to_n_v4(array3));

        /*
         * Test 4: Find a missing number from the array and the missing
         *         number should be he maximum number.
         */
        int array4[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
        assert(array4.length == find_missing_number_among_0_to_n_v1(array4));
        assert(array4.length == find_missing_number_among_0_to_n_v2(array4));
        assert(array4.length == find_missing_number_among_0_to_n_v3(array4));
        assert(array4.length == find_missing_number_among_0_to_n_v4(array4));
    }
}
