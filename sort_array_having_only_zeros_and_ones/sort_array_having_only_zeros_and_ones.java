/*
 * Sort an array comprising of only 1 and 0 as numbers
 */

import java.io.*;
import java.util.*;

public class sort_array_having_only_zeros_and_ones
{
    /*
     * This function sorts an array containing only zeros and ones
     * in O(n) time. But this function requires two passes of the
     * array. The first pass counts the number of zero and one in
     * the array. In the second pass, we over-write the array with
     * zeros first and then ones.
     */
    public static void sort_array_of_zeros_and_ones_ver1 (int[] array)
    {
        int ones = 0;
        int zeros = 0;
        int i = 0;

        if (array == null) {
            return;
        }

        /*
         * Count the number of 1s and 0s in the array
         */
        for (i = 0; i < array.length; ++i) {
            if (array[i] == 0) {
                zeros++;
            }

            if (array[i] == 1) {
                ones++;
            }
        }

        /*
         * put 0s in the first zeros elements in the array
         */
        for (i = 0; i < zeros; ++i) {
            array[i] = 0;
        }

        /*
         * For the next ones elements put 1 in the array
         */
        for (i = 0; i < ones; ++i) {
            array[i + zeros] = 1;
        }
    }

    /*
     * This function sorts an array containing only zeros and ones.
     * Since ones need to be pushed to the end of the array and zeros
     * need to pushed to the front of the array, we maintain two indicies
     * left and right which keep track of the zeros and ones in the array
     * respectively. This requires only one pass of the array and array
     * is sorted in O(n) time.
     */
    public static void sort_array_of_zeros_and_ones_ver2 (int[] array)
    {
        int left;
        int right;
        int temp;

        if (array == null) {
            return;
        }

        left = 0;
        right = array.length - 1;

        /*
         * Iterate through the array until left is greater
         * than or equal to right.
         */
        while (left < right) {

            /*
             * If the element to the left is 1 and the element
             * to the right in one, then swap the array element
             * value and increment 'left' index and decrement
             * 'right' index.
             */
            if ((array[left] == 1) && (array[right] == 0)) {
                temp = array[left];
                array[left] = array[right];
                array[right] = temp;

                ++left;
                --right;
            } else {

                /*
                 * If the left element is 0, then increment left
                 */
                if (array[left] == 0) {
                    ++left;
                }

                /*
                 * If the right element is 1, then decrement right
                 */
                if(array[right] == 1) {
                    --right;
                }
            }
        }
    }

    public static void main (String[] args)
    {
        /*
         * Unit test cases for the first approach
         */
        int[] array_test_ver1_1 = {1,1,1,1,0,0,0,0,0,0};
        int[] array_expect_ver1_1 = {0,0,0,0,0,0,1,1,1,1};
        sort_array_of_zeros_and_ones_ver1(array_test_ver1_1);
        assert true ==
               Arrays.equals(array_test_ver1_1, array_expect_ver1_1);

        int[] array_test_ver1_2 = {1,0,0,1,0,0,0,0,0,0};
        int[] array_expect_ver1_2 = {0,0,0,0,0,0,0,0,1,1};
        sort_array_of_zeros_and_ones_ver1(array_test_ver1_2);
        assert true ==
               Arrays.equals(array_test_ver1_2, array_expect_ver1_2);

        int[] array_test_ver1_3 = {0,0,0,0,0,0,0,0,0,0};
        int[] array_expect_ver1_3 = {0,0,0,0,0,0,0,0,0,0};
        sort_array_of_zeros_and_ones_ver1(array_test_ver1_3);
        assert true ==
               Arrays.equals(array_test_ver1_3, array_expect_ver1_3);

        int[] array_test_ver1_4 = {1,1,1,1,1,1,1,1,1,1};
        int[] array_expect_ver1_4 = {1,1,1,1,1,1,1,1,1,1};
        sort_array_of_zeros_and_ones_ver1(array_test_ver1_4);
        assert true ==
               Arrays.equals(array_test_ver1_4, array_expect_ver1_4);

        /*
         * Unit test cases for the second approach
         */
        int[] array_test_ver2_1 = {1,1,1,1,0,0,0,0,0,0};
        int[] array_expect_ver2_1 = {0,0,0,0,0,0,1,1,1,1};
        sort_array_of_zeros_and_ones_ver2(array_test_ver2_1);
        assert true ==
               Arrays.equals(array_test_ver2_1, array_expect_ver2_1);

        int[] array_test_ver2_2 = {1,0,0,1,0,0,0,0,0,0};
        int[] array_expect_ver2_2 = {0,0,0,0,0,0,0,0,1,1};
        sort_array_of_zeros_and_ones_ver2(array_test_ver2_2);
        assert true ==
               Arrays.equals(array_test_ver2_2, array_expect_ver2_2);

        int[] array_test_ver2_3 = {0,0,0,0,0,0,0,0,0,0};
        int[] array_expect_ver2_3 = {0,0,0,0,0,0,0,0,0,0};
        sort_array_of_zeros_and_ones_ver2(array_test_ver2_3);
        assert true ==
               Arrays.equals(array_test_ver2_3, array_expect_ver2_3);

        int[] array_test_ver2_4 = {1,1,1,1,1,1,1,1,1,1};
        int[] array_expect_ver2_4 = {1,1,1,1,1,1,1,1,1,1};
        sort_array_of_zeros_and_ones_ver2(array_test_ver2_4);
        assert true ==
               Arrays.equals(array_test_ver2_4, array_expect_ver2_4);
    }
}
