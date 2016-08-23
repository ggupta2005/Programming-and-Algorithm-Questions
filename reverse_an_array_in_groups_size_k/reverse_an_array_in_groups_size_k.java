/*
 * This program reverses an array in groups of a given size k. For
 * more information on this post please refer to the following link:-
 * http://www.geeksforgeeks.org/reverse-an-array-in-groups-of-given-size/
 */
import java.io.*;
import java.util.*;

public class reverse_an_array_in_groups_size_k
{
    /*
     * This function reverses a section of an array from lower index value
     * 'low' to higher index value 'high' included. If the values of 'low'
     * and 'high' are not valid, then this function siply returns without
     * performing any reverse operations. The time complexity of this
     * function is O(n), where 'n' is the number of array elements between
     * and a including 'low' nd 'high'. The space complexity of this
     * function is O(1).
     */
    public static void reverse_array_section (int[] array, int low, int high)
    {
        int temp;

        /*
         * Return from this function in case of the following conditions:-
         * 1. If the array is null
         * 2. If 'low' is less than zero
         * 3. If 'high' is less than zero
         * 4. If the value of 'low' is geater than or equal to 'high'
         */
        if ((array == null) || (low < 0) || (high < 0) || (low >= high)) {
            return;
        }

        /*
         * Iterate through unless 'low' is strictly less than 'high'
         */
        while (low < high) {

            /*
             * Swap values of the array elements indexed by 'low' and
             * 'high'
             */
            temp = array[low];
            array[low] = array[high];
            array[high] = temp;

            /*
             * Increment 'low'
             */
            ++low;

            /*
             * Decrement 'high'
             */
            --high;
        }
    }

    /*
     * This function reverses an array in groups of size 'k'. The time
     * complexity of this function is o(n), where 'n' is the number of
     * array elements in the array. The space complexity is O(1).
     */
    public static void reverse_array_in_groups_of_k (int[] array, int k)
    {
        int index, low, high, len;

        /*
         * Return from this function in case of the following
         * conditions:-
         * 1. The array pointer is null
         * 2. The length of the array is not legal
         * 3. The value of 'k' is not legal
         */
        if ((array == null) || (array.length == 0) || (k <= 0)) {
            return;
        }

        /*
         * Get the length of the array
         */
        len = array.length;

        /*
         * Set the array index to zero
         */
        index = 0;

        /*
         * Iterate until 'index' is less than the length of the
         * array
         */
        while (index < len) {

            /*
             * Set 'low' to 'index'
             */
            low = index;

            /*
             * Set 'high' to lower of the index values
             */
            high = ((low + k - 1) >= len) ? (len - 1):(low + k - 1);

            /*
             * Reverse the array elements within the section 'low'
             * to 'high'
             */
            reverse_array_section(array, low, high);

            /*
             * Increment the index by 'k'
             */
            index += k;
        }
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with null array pointer. The function to reverse
         *         the array in groups of size 'k' should return without
         *         doing anything.
         */
        int[] array0 = null;
        int k0 = 2;
        int[] expected_array0 = null;
        reverse_array_in_groups_of_k(array0, k0);
        assert(expected_array0 == array0);

        /*
         * Test 1: Test with illegal array length. The function to reverse
         *         the array in groups of size 'k' should return without
         *         doing anything.
         */
        int[] array1 = {};
        int k1 = 2;
        int expected_array1[] = {};
        reverse_array_in_groups_of_k(array1, k1);
        assert(true == Arrays.equals(expected_array1, array1));

        /*
         * Test 2: Test with illegal group size 'k'. The function to reverse
         *         the array in groups of size 'k' should return without
         *         doing anything.
         */
        int[] array2 = {2, 9, 0};
        int k2 = -2;
        int expected_array2[] = {2, 9, 0};
        reverse_array_in_groups_of_k(array2, k2);
        assert(true == Arrays.equals(expected_array2, array2));

        /*
         * Test 3: Test with legal array, length of array and value of 'k'.
         *         The length of array is a multiple of group size 'k'. The
         *         function to reverse the array in groups of size 'k'
         *         should reverse the array correctly.
         */
        int[] array3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int k3 = 3;
        int[] expected_array3 = {3, 2, 1, 6, 5, 4, 9, 8, 7};
        reverse_array_in_groups_of_k(array3, k3);
        assert(true == Arrays.equals(expected_array3, array3));

        /*
         * Test 4: Test with legal array, length of array and value of 'k'.
         *         The length of array is not a multiple of group size 'k'.
         *         The function to reverse the array in groups of size 'k'
         *         should reverse the array correctly.
         */
        int[] array4 = {1, 2, 3, 4, 5, 6, 7, 8};
        int k4 = 5;
        int[] expected_array4 = {5, 4, 3, 2, 1, 8, 7, 6};
        reverse_array_in_groups_of_k(array4, k4);
        assert(true == Arrays.equals(expected_array4, array4));

        /*
         * Test 5: Test with legal array, length of array and value of
         *         'k' bing 1. The function to reverse the array in groups
         *         of size 'k' should not reverse the array.
         */
        int[] array5 = {1, 2, 3, 4, 5, 6};
        int k5 = 1;
        int[] expected_array5 = {1, 2, 3, 4, 5, 6};
        reverse_array_in_groups_of_k(array5, k5);
        assert(true == Arrays.equals(expected_array5, array5));

        /*
         * Test 6: Test with legal array, length of array and value of 'k'.
         *         The length of array is less than the group size 'k'.
         *         The function to reverse the array in groups of size 'k'
         *         should reverse the array correctly.
         */
        int[] array6 = {1, 2, 3, 4, 5, 6, 7, 8};
        int k6 = 10;
        int[] expected_array6 = {8, 7, 6, 5, 4, 3, 2, 1};
        reverse_array_in_groups_of_k(array6, k6);
        assert(true == Arrays.equals(expected_array6, array6));
    }
}
