/*
 * This program finds if an array has only consecutive integer
 * elements without duplicates.For more details on the problem,
 * please refer to the post:-
 * http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/
 */

import java.io.*;
import java.util.*;

public class find_if_array_has_consecuitve_numbers
{
    /*
     * This function finds if an array contains non-duplicate consecutive
     * array elements. This uses the following algorithm to find the
     * consecutive array elements:-
     * 1. Find the minimum array element in the array
     * 2. Prepare a temporary buffer to keep track of consecuitve
     *    elements relative to the minimum element.
     * 3. Walk the array again to map the array elements relative to
     *    to the minimum number.
     * 4. Walk the temporary array to check if all numbers relative to
     *    minimum number are present
     * The time complexity of this algorithm is O(n).
     * The space complexity of this algorithm is O(n).
     */
    public static boolean find_if_array_has_consecutive_nums (int[] array)
    {
        int i, min;
        boolean[] consecutive;
        boolean if_consecutive = true;

        /*
         * If array is not legal or the length of the array is less
         * than or equal to zero, then return false
         */
        if ((array == null) || (array.length == 0)) {
            return(false);
        }

        /*
         * Find the minimum array element
         */
        min = array[0];
        for (i = 1; i < array.length; ++i) {
            if (min > array[i]) {
                min = array[i];
            }
        }

        /*
         * Allocate a temporary array for consecutive numbers
         */
        consecutive = new boolean[array.length];

        /*
         * If the array allocation fails, then return false.
         */
        if (consecutive == null) {
            return(false);
        }

        /*
         * Set all the element of consecutive to be 'false'
         */
        for (i = 0; i < consecutive.length; ++i) {
            consecutive[i] = false;
        }

        /*
         * Walk the array again to map the array elements relative to
         * to the minimum number
         */
        for (i = 0; i < array.length; ++i) {
            if ((array[i] - min) < array.length) {
                consecutive[array[i] - min] = true;
            }
        }

        /*
         * Check if all consecutive integers are present
         */
        for (i = 0; i < consecutive.length; ++i) {
            if_consecutive &= consecutive[i];
        }

        /*
         * Return the final result that all consecutive integers are
         * present
         */
        return(if_consecutive);
    }

    public static void main(String[] args)
    {

        /*
         * Test 0: The array consists of consecutive array integers
         */
        int[] array0 = {83, 78, 80, 81, 79, 82};
        assert true == find_if_array_has_consecutive_nums(array0);

        /*
         * Test 1: The array consists of non-consecutive array integers
         */
        int[] array1 = {34, 23, 52, 12, 3};
        assert false == find_if_array_has_consecutive_nums(array1);

        /*
         * Test 2: The array consists of consecutive array integers but
         *         also duplicates
         */
        int[] array2 = {7, 6, 5, 5, 3, 4};
        assert false == find_if_array_has_consecutive_nums(array2);

        /*
         * Test 3: The array is null
         */
        int[] array3 = null;
        assert false == find_if_array_has_consecutive_nums(array3);

        /*
         * Test 4: The length of array is negative
         */
        int[] array4 = {};
        assert false == find_if_array_has_consecutive_nums(array4);

        /*
         * Test 5: The array consists of only one element so it should be
         *         consecutive by default
         */
        int[] array5 = {3};
        assert true == find_if_array_has_consecutive_nums(array5);

    }
}
