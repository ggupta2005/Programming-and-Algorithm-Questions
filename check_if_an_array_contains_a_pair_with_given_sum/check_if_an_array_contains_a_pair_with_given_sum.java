/*
 * This program checks if the an array of integers contains a pair of
 * integers with a given sum. For more information on the post, please
 * refer to the following link:-
 * http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-
 * numbers-and-another-number-x-determines-whether-or-not-there-exist-two-
 * elements-in-s-whose-sum-is-exactly-x/
 */
import java.io.*;
import java.util.*;

public class check_if_an_array_contains_a_pair_with_given_sum
{
    /*
     * This function returns 'true' if there exists a pair which when added
     * together gives the 'sum'. If no such pair exists this function returns
     * 'false'. This function takes
     * the following approach to solve the problem:-
     * 1. First sort the array using some quick sort
     * 2. Walk the sorted array from left and right to check if some pair adds
     *    to 'sum'.
     *   a. If the sum of the left and right elements is less than sum, then
     *      increment left index so that we can get more closer to sum.
     *   b. If the sum of the left and right elements is greater than sum,
     *      then decrement right index so that we can get more closer to sum.
     *   c. If the sum of the left and right elements is equal to sum, then
     *      return 'true'.
     * 3. IF the 'sum' is not found, then return 'false'.
     * The time complexity of this function is O(n * log(n)) and then walk the
     * array once.Here 'n' is the number of elements in the array.
     * The space complexity of this function is O(1).
     */
    public static boolean check_if_an_array_contains_a_pair_with_given_sum_v1 (
                                                               int []array,
                                                               int sum)
    {
        int left, right;

        /*
         * If either array in null or its length is illegal, then return
         * 'false'
         */
        if ((array == null) || (array.length == 0)) {
            return(false);
        }

        /*
         * Sort the array.
         */
        Arrays.sort(array);

        /*
         * Set 'left' at index zero and 'right' at index 'len-1'
         */
        left = 0;
        right = array.length - 1;

        /*
         * Iterate through the array until 'left' is strictly less than 'right'
         */
        while (left < right) {
            if ((array[left] + array[right]) < sum) {

                /*
                 * If the sum of the left and right elements is less
                 * than sum, then increment left
                 */
                ++left;
            } else if ((array[left] + array[right]) > sum) {

                /*
                 * If the sum of the left and right elements is greater
                 * than sum, then decrement right
                 */
                --right;
            } else {

                /*
                 * If the sum of the left and right elements is equal to
                 * sum, then return 'true'.
                 */
                return(true);
            }
        }

        /*
         * Since no such pair having 'sum' was found, so return 'false'
         */
        return(false);
    }

    /*
     * This function returns 'true' if there exists a pair which when added
     * together gives the 'sum'. If no such pair exists this function returns
     * 'false'. The appraoch uses hashing to find if some pair exists whose sum
     * matches the 'target'. The time complexity of this function is O(n) as
     * we walk the array once and map the elements in a hash table. Here 'n'
     * is the number of elements in the array. The space complexity of this
     * function is O(m), where 'm' is the size of the hash table.
     */
    public static boolean check_if_an_array_contains_a_pair_with_given_sum_v2 (
                                                               int []array,
                                                               int sum)
    {
        int index;
        Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
        Object element;

        /*
         * If either array in null or its length is illegal, then return
         * 'false'
         */
        if ((array == null) || (array.length == 0)) {
            return(false);
        }

        /*
         * Iterate through the entire array
         */
        element = null;
        for (index = 0; index < array.length; ++index) {

            /*
             * Check if there exists a node in the hash table whose
             * key matches with 'sum - array[index]'
             */
            element = ht.get(new Integer(sum - array[index]));

            if (element != null) {

                /*
                 * If there exists a node with data 'target - array[index]',
                 * then a pair with sum 'target' is found. So break.
                 */
                break;
            } else {

                /*
                 * Otherwise insert the array value in the hash table
                 */
                ht.put(new Integer(array[index]),
                                    new Integer(array[index]));
            }
        }

        if (element != null) {

            /*
             * If node is valid, then return 'true'.
             */
            return(true);
        }

        /*
         * If node is not valid, then return 'false'.
         */
        return(false);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a null array. The sum cannot be found in a
         *         null array.
         */
        int[] array0 = null;
        int sum0 = 10;
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                            array0, sum0));
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                            array0, sum0));

        /*
         * Test 1: Test with an array length which is illegal. The sum cannot
         *         be found in an array whose length is not valid.
         */
        int[] array1 = {};
        int sum1 = 10;
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                            array1, sum1));
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                            array1, sum1));

        /*
         * Test 2: Test with an legal array (positive numbers) only and length
         *         in which the desired sum is found
         */
        int[] array2 = {10, 90, 5, 15, 100, 85, 95};
        int sum2 = 185;
        assert(true == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                            array2, sum2));
        assert(true == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                            array2, sum2));

        /*
         * Test 3: Test with an legal array (positive numbers) only and length
         *         in which the desired sum is not found
         */
        int[] array3 = {10, 90, 5, 15, 100, 85, 95};
        int sum3 = 1000;
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                            array3, sum3));
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                            array3, sum3));

        /*
         * Test 4: Test with an legal array (negative numbers) only and length
         *         in which the desired sum is found
         */
        int[] array4 = {-10, -90, -5, -15, -100, -85, -95};
        int sum4 = -105;
        assert(true == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                            array4, sum4));
        assert(true == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                            array4, sum4));

        /*
         * Test 5: Test with an legal array (negative numbers) only and length
         *         in which the desired sum is not found
         */
        int[] array5 = {-10, -90, -5, -15, -100, -85, -95};
        int sum5 = -109;
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                            array5, sum5));
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                            array5, sum5));

        /*
         * Test 6: Test with an legal array (positive and negative numbers)
         *         only and length in which the desired sum is found
         */
        int[] array6 = {10, -90, 5, -15, 100, -85, -95};
        int sum6 = 10;
        assert(true == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                            array6, sum6));
        assert(true == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                            array6, sum6));

        /*
         * Test 7: Test with an legal array (positive and negative numbers)
         *         only and length in which the desired sum is not found
         */
        int[] array7 = {10, -90, 5, -15, 100, -85, -95};
        int sum7 = -1090;
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                            array7, sum7));
        assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                            array7, sum7));
    }
}
