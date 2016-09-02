/*
 * This program finds the maximum sum for some sub-array in a given array
 * of integers. For more information on this problem, please refer to the
 * following link:- https://leetcode.com/problems/maximum-subarray/
 */
import java.io.*;
import java.util.*;

public class find_maximum_sum_for_subarray
{

    /*
     * This function finds the maximum sum for some subarray in the given
     * array of integers. This function computes the sum for all possible
     * subarrays and keeps track of the maximum sum seen. The time
     * complexity of this function is O(n ^ 3), where 'n is the number of
     * elements in the array. The space complexity of this function O(1).
     */
    public static int find_maximum_sum_for_subarray_v1 (int[] array)
    {
        int i, j, k, max_sum, temp_sum;

        /*
         * If the array is null of its length is not valid, then
         * return smallest possible integer value
         */
        if ((array == null) || (array.length <= 0)) {
            return(Integer.MIN_VALUE);
        }

        /*
         * Set maximum sum to INT_MIN
         */
        max_sum = Integer.MIN_VALUE;

        /*
         * Iterate over all array elements
         */
        for (i = 0; i < array.length; ++i) {

            /*
             * Iterate over all elements on the right of the
             * current element to compute the sum over all
             * possible sub-arrays starting at the current
             * element.
             */
            for (j = i; j < array.length; ++j) {

                /*
                 * Compute the sum of all the elements in the
                 * subarray
                 */
                temp_sum = 0;
                for (k = i; k <= j; ++k) {
                    temp_sum += array[k];
                }

                /*
                 * If the sum of the current sub-array is greater
                 * than the maximum sum, then update the maximum
                 * sum
                 */
                if (temp_sum > max_sum) {
                    max_sum = temp_sum;
                }
            }
        }

        /*
         * Return the maximum sub-array sum
         */
        return(max_sum);
    }

    /*
     * This function finds the maximum sum for some subarray in the given
     * array of integers. This function re-uses the maximum sub-array sum
     * computed over previous element and uses that sum to find the maximum
     * sub-array sum including the current element. The time complexity
     * of this function is O(n), where 'n' is the number of elements in
     * the array. The space complexity of this function O(n), since we keep
     * an additional array of 'n' elements to keep track of previous subarray
     * sums.
     */
    public static int find_maximum_sum_for_subarray_v2 (int[] array)
    {
        int index, max_sum;
        int[] sum;

        /*
         * If the array is null of its length is not valid, then
         * return smallest possible integer value
         */
        if ((array == null) || (array.length <= 0)) {
            return(Integer.MIN_VALUE);
        }

        /*
         * Allocate a temporary array to keep track of previous subarray
         * sums
         */
        sum = new int[array.length];

        /*
         * If the array allocation fails, then return smallest possible
         * integer value
         */
        if (sum == null) {
            return(Integer.MIN_VALUE);
        }

        /*
         * Set the first element of sum to be equal to the first element
         * in array
         */
        sum[0] = array[0];

        /*
         * Iterate over all array elements from the first element in the
         * array
         */
        for (index = 1; index < array.length; ++index) {

            /*
             * If the sum of the previous subarray sum and the current element
             * is greater than the current element, then store this sum in the
             * 'sum' array. Other wise store the value in the array in the 'sum'
             * array
             */
            if (sum[index - 1] + array[index] > array[index]) {
                sum[index] = sum[index - 1] + array[index];
            } else {
                sum[index] = array[index];
            }
        }

        /*
         * Compute the maximum sum in the 'sum' array
         */
        max_sum = sum[0];
        for (index = 1; index < array.length; ++index) {
            if (max_sum < sum[index]) {
                max_sum = sum[index];
            }
        }

        /*
         * Return the maximum sub-array sum
         */
        return(max_sum);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0:  Test with a mix of positive and negative number. The
         *          functions computing the maximum sub-array sum should
         *          return the expected value.
         */
        int[] array0 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int exp_sum0 = 6;
        assert(exp_sum0 == find_maximum_sum_for_subarray_v1(array0));
        assert(exp_sum0 == find_maximum_sum_for_subarray_v2(array0));

        /*
         * Test 1:  Test with a all positive numbers. The functions
         *          computing the maximum sub-array sum should return the
         *          sum of the array.
         */
        int[] array1 = {2, 1, 3, 4, 5};
        int exp_sum1 = 15;
        assert(exp_sum1 == find_maximum_sum_for_subarray_v1(array1));
        assert(exp_sum1 == find_maximum_sum_for_subarray_v2(array1));

        /*
         * Test 2:  Test with a all negative numbers. The functions
         *          computing the maximum sub-array sum should return the
         *          maximum negative number from the array.
         */
        int[] array2 = {-5, -4, -3, -2, -1};
        int exp_sum2 = -1;
        assert(exp_sum2 == find_maximum_sum_for_subarray_v1(array2));
        assert(exp_sum2 == find_maximum_sum_for_subarray_v2(array2));

        /*
         * Test 3:  Test with a single positive number. The functions
         *          computing the maximum sub-array sum should return the
         *          single element from the array.
         */
        int[] array3 = {25};
        int exp_sum3 = 25;
        assert(exp_sum3 == find_maximum_sum_for_subarray_v1(array3));
        assert(exp_sum3 == find_maximum_sum_for_subarray_v2(array3));

        /*
         * Test 4:  Test with a single negative number. The functions
         *          computing the maximum sub-array sum should return the
         *          single element from the array.
         */
        int[] array4 = {-25};
        int exp_sum4 = -25;
        assert(exp_sum4 == find_maximum_sum_for_subarray_v1(array4));
        assert(exp_sum4 == find_maximum_sum_for_subarray_v2(array4));

        /*
         * Test 5:  Test without a single number in the array. The functions
         *          computing the maximum sub-array sum should return the
         *          smallest possible integer number.
         */
        int[] array5 = {};
        int exp_sum5 = Integer.MIN_VALUE;
        assert(exp_sum5 == find_maximum_sum_for_subarray_v1(array5));
        assert(exp_sum5 == find_maximum_sum_for_subarray_v2(array5));

        /*
         * Test 6:  Test with an array pointing to null. The functions
         *          computing the maximum sub-array sum should return the
         *          smallest possible integer number.
         */
        int[] array6 = null;
        int exp_sum6 = Integer.MIN_VALUE;
        assert(exp_sum6 == find_maximum_sum_for_subarray_v1(array6));
        assert(exp_sum6 == find_maximum_sum_for_subarray_v2(array6));
    }
}
