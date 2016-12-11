/*
 * This program finds the number in a sorted array. This program uses the
 * following approaches to find the number in a sorted array:-
 * 1. Linear Search
 * 2. Binary Search
 */
import java.io.*;
import java.util.*;

public class find_num_in_sorted_array
{
    /*
     * Illegal index
     */
    public static final int ILLEGAL = -1;

    /*
     * This function searches a number 'num' in a sorted array of length 'len'
     * and returns the index of the number in the array otherwise the function
     * returns '-1'. The function compares the number with each element of the
     * array. The time complexity of this function is O(n), where 'n' is the
     * number of elements in the array. The space complexity of this function
     * is O(1).
     */
    public static int linear_search_for_num (int[] array, int num)
    {
        int index, len;

        /*
         * If the array is invalid or its length is not
         * invalid, then return '-1' as the index.
         */
        if ((array == null) || (array.length <= 0)) {
            return(ILLEGAL);
        }

        len = array.length;

        /*
         * Iterate over the entire array.
         */
        for (index = 0; index < len; ++index) {

            /*
             * If the array element is equal to the
             * number, then return the index of the
             * array element.
             */
            if (array[index] == num) {
                return(index);
            }
        }

        /*
         * Return '-1'
         */
        return(ILLEGAL);
    }

    /*
     * This function searches a number 'num' in a sorted array of length 'len'
     * and returns the index of the number in the array otherwise the function
     * returns '-1'. The function compares the number with the middle element
     * and if the middle element is more than the search happens on the lower
     * half of the array otherwise the search happens on the higher half of the
     * array. The time complexity of this function is O(log(n)), where 'n' is
     * the number of elements in the array. The space complexity of this
     * function is O(1).
     */
    public static int binary_search_for_num (int[] array, int num)
    {
        int mid, low, high;

        /*
         * If the array is invalid or its length is not
         * invalid, then return '-1' as the index.
         */
        if ((array == null) || (array.length <= 0)) {
            return(ILLEGAL);
        }

        /*
         * Set 'low' to zero
         */
        low = 0;

        /*
         * Set high to 'array.length - 1'
         */
        high = array.length - 1;

        /*
         * Iterate until 'low' is less than or equal to 'high'
         *
         */
        while (low <= high) {

            /*
             * Compute the 'mid'
             */
            mid = (low + high)/2;

            if (array[mid] == num) {

                /*
                 * If middle element is equal to the 'num',
                 * then return 'mid'
                 */
                return(mid);
            } else if (array[mid] > num) {

                /*
                 * If middle element is greater to the 'num',
                 * then search the lower half of the array
                 */
                high = mid - 1;
            } else {

                /*
                 * If middle element is lesser to the 'num',
                 * then search the upper half of the array
                 */
                low = mid + 1;
            }
        }

        /*
         * Since the element was not found in the array,
         * then return '-1'
         */
        return(ILLEGAL);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test a number which occurs in the middle of the array.
         *         The linear search and binary search functions should
         *         return the index of the number in the array.
         */
        int[] array0 = {1,2,3,6,7,8,9,10,11};
        int num0 = 7;
        int exp_index0 = 4;
        assert(exp_index0 == linear_search_for_num(array0, num0));
        assert(exp_index0 == binary_search_for_num(array0, num0));

        /*
         * Test 1: Test a number which occurs in the end of the array.
         *         The linear search and binary search functions should
         *         return the index of the number in the array.
         */
        int[] array1 = {1,2,3,6,7,8,9,10,11};
        int num1 = 11;
        int exp_index1 = 8;
        assert(exp_index1 == linear_search_for_num(array1, num1));
        assert(exp_index1 == binary_search_for_num(array1, num1));

        /*
         * Test 2: Test a number which occurs in the beginning of the array.
         *         The linear search and binary search functions should
         *         return the index of the number in the array.
         */
        int[] array2 = {1,2,3,6,7,8,9,20,22};
        int num2 = 1;
        int exp_index2 = 0;
        assert(exp_index2 == linear_search_for_num(array2, num2));
        assert(exp_index2 == binary_search_for_num(array2, num2));

        /*
         * Test 3: Test a number which is greater than the maximum number in
         *         the array. The linear search and binary search functions
         *         should return '-1'.
         */
        int[] array3 = {1,2,3,6,7,8,9,30,33};
        int num3 = array3[array3.length - 1] + 1;
        int exp_index3 = ILLEGAL;
        assert(exp_index3 == linear_search_for_num(array3, num3));
        assert(exp_index3 == binary_search_for_num(array3, num3));

        /*
         * Test 4: Test a number which is lesser than the minimum number in
         *         the array. The linear search and binary search functions
         *         should return '-1'.
         */
        int[] array4 = {1,2,4,6,7,8,9,40,44};
        int num4 = array4[0] - 1;
        int exp_index4 = ILLEGAL;
        assert(exp_index4 == linear_search_for_num(array4, num4));
        assert(exp_index4 == binary_search_for_num(array4, num4));

        /*
         * Test 4: Test a number which does not occur in the array. The
         *         linear search and binary search functions should return
         *         '-1'.
         */
        int[] array5 = {1,3,5,6,7,8,9,50,55};
        int num5 = array5[0] + 1;
        int exp_index5 = ILLEGAL;
        assert(exp_index5 == linear_search_for_num(array5, num5));
        assert(exp_index5 == binary_search_for_num(array5, num5));
    }
}
