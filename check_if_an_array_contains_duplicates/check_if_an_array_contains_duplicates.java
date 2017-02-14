/*
 * This program checks if an array contains duplicate elements.
 */
import java.io.*;
import java.util.*;

public class check_if_an_array_contains_duplicates
{
    /*
     * This function returns 'true' if the input array contains duplicate
     * elements and 'false' otherwise. The time complexity of this function
     * is O(n * log(n)) in average case and O(n^2) in worst case since we
     * sort the array using quick sort and then walk the array once. Here
     * 'n' is the number of elements in the array. The space complexity of
     * this function is O(1).
     */
    public static boolean check_if_array_contains_duplicates_v1(int[] nums)
    {
        int index;

        /*
         * If the input array is not valid or the array doesn't have
         * any elements, then return 'false'
         */
        if ((nums == null) || (nums.length <= 0)) {
            return(false);
        }

        /*
         * Sort the array using sort function
         */
        Arrays.sort(nums);

        /*
         * Iterate through the array and check if the there are duplicate
         * elements in the array
         */
        for (index = 1; index < nums.length; ++index) {

            /*
             * If the adjacent elements in the sorted array are same, then
             * return 'true'
             */
            if (nums[index] == nums[index - 1]) {
                return(true);
            }
        }

        /*
         * Since no duplicates were detected, so return 'false'
         */
        return(false);
    }

    /*
     * This function returns 'true' if the input array contains duplicate
     * elements and 'false' otherwise. The time complexity of this function
     * is O(n), where 'n' is the number of array elements in the input array.
     * The space complexity of the this function is O(n), since we use a hash
     * table to detect the duplicates.
     */
    public static boolean check_if_array_contains_duplicates_v2 (int[] nums)
    {
        int index;
        Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
        boolean if_duplicate_found;

        /*
         * If the input array is not valid or the array doesn't have
         * any elements, then return 'false'
         */
        if ((nums == null) || (nums.length <= 0)) {
            return(false);
        }

        /*
         * Assume that the input array does not contain any duplicates
         */
        if_duplicate_found = false;

        /*
         * Iterate over the elements in the array
         */
        for (index = 0; index < nums.length; ++index) {

            /*
             * Check if the array element exists in he input array.
             */
            if (ht.get(new Integer(nums[index])) != null) {

                /*
                 * If the array element is found in the array, means that
                 * duplicate exists in the input array
                 */
                if_duplicate_found = true;
                break;
            } else {

                /*
                 * If the array element is not found in the array then add the
                 * array element into the hash table for future reference
                 */
                ht.put(new Integer(nums[index]), new Integer(nums[index]));
            }
        }

        /*
         * Walk and free the hash
         */

        /*
         * Return if the array contains duplicates
         */
        return(if_duplicate_found);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with an array of positive numbers having no duplicate
         *         elements. The function detecting the duplicates should
         *         return 'false'.
         */
        int[] array0 = {1,2,3};
        assert(false == check_if_array_contains_duplicates_v1(array0));
        assert(false == check_if_array_contains_duplicates_v2(array0));

        /*
         * Test 1: Test with an array of negative numbers having no duplicate
         *         elements. The function detecting the duplicates should
         *         return 'false'.
         */
        int[] array1 = {-1,-2,-3};
        assert(false == check_if_array_contains_duplicates_v1(array1));
        assert(false == check_if_array_contains_duplicates_v2(array1));

        /*
         * Test 2: Test with an array of positive numbers having duplicate
         *         elements. The function detecting the duplicates should
         *         return 'true'.
         */
        int[] array2 = {2,2,3,3,4,5,6};
        assert(true == check_if_array_contains_duplicates_v1(array2));
        assert(true == check_if_array_contains_duplicates_v2(array2));

        /*
         * Test 3: Test with an array of negative numbers having duplicate
         *         elements. The function detecting the duplicates should
         *         return 'true'.
         */
        int[] array3 = {-3,-3,-3,-3,-4,-5,-6};
        assert(true == check_if_array_contains_duplicates_v1(array3));
        assert(true == check_if_array_contains_duplicates_v2(array3));

        /*
         * Test 4: Test with an array of positive numbers having one duplicate
         *         element. The function detecting the duplicates should
         *         return 'true'.
         */
        int[] array4 = {2,1,3,3,4,5,6};
        assert(true == check_if_array_contains_duplicates_v1(array4));
        assert(true == check_if_array_contains_duplicates_v2(array4));

        /*
         * Test 5: Test with an array of negative numbers having one duplicate
         *         element. The function detecting the duplicates should
         *         return 'true'.
         */
        int[] array5 = {-2,-1,-3,-3,-4,-5,-6};
        assert(true == check_if_array_contains_duplicates_v1(array5));
        assert(true == check_if_array_contains_duplicates_v2(array5));
    }
}
