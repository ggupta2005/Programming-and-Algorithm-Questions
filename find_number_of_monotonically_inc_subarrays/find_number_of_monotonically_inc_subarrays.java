/*
 * This program finds the number of strictly increasing sub-arrays of
 * size more than one in a given array of numbers. For more information
 * on this, please refer to the following post:-
 * http://www.geeksforgeeks.org/count-strictly-increasing-subarrays/
 */
import java.io.*;
import java.util.*;

public class find_number_of_monotonically_inc_subarrays
{

    /*
     * This function finds the number of strictly increasing sub-arrays of
     * length greater than one. We keep a running variable (cur_len) to keep
     * track of the number of elements in an increasing sub-array. This variable
     * is reset when we encounter a number which is less than or equal to the
     * previous number. Before resetting 'cur_len' we count and store
     * the number of strictly increasing sub-arrays using the formula
     * cur_len * (cur_len-1)/2. The time complexity of this function is O(n),
     * where 'n' is the number of elements in the array. The space complexity
     * of the function is O(1).
     */
    public static int find_number_monotically_increasing_subarrays (int[] array)
    {
        int i;
        int cur_len, total;

        /*
         * If array is NULL of its length is illegal, then return 0 as there
         * are no possible sub-arrays to find here
         */
        if ((array == null) || (array.length == 0)) {
            return(0);
        }

        /*
         * Set cur_len as one, since one element is strictly increasing in
         * itself
         */
        cur_len = 1;
        total = 0;

        /*
         * Iterate from the second element until the end of array is reached
         */
        for (i = 1; i < array.length; ++i) {

            /*
             * If the current element is greater than the first element
             * then increment 'cur_len'
             */
            if (array[i-1] < array[i]) {
                ++cur_len;
            } else {

                /*
                 * If the current number is not greater than the previous
                 * number, then calculate the number of increasing sub-arrays
                 * and add them to 'total' if 'cur_len' is greater than one.
                 */
                if (cur_len > 1) {
                    total += ((cur_len) * (cur_len - 1)) / 2;
                }

                /*
                 * reset 'cur_len'
                 */
                cur_len = 1;
            }
        }

        /*
         * Add the sum for 'cur_len', if cur_len' is greater than one
         */
        if (cur_len > 1) {
            total += ((cur_len) * (cur_len - 1)) / 2;
        }

        /*
         * Return the total number of strictly increasing sub-arrays
         */
        return(total);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test on a simple array
         */
        int[] array0 = {1, 4, 3};
        assert 1 == find_number_monotically_increasing_subarrays(array0);

        /*
         * Test 1: Test on a strictly increasing array
         */
        int[] array1 = {1, 2, 3, 4};
        assert 6 == find_number_monotically_increasing_subarrays(array1);

        /*
         * Test 2: Test on a strictly decreasing array
         */
        int[] array2 = {4, 3, 2, 1};
        assert 0 == find_number_monotically_increasing_subarrays(array2);

        /*
         * Test 3: Test on a non-increasing array
         */
        int[] array3 = {1, 2, 2, 4};
        assert 2 == find_number_monotically_increasing_subarrays(array3);

        /*
         * Test 4: Test with a NULL array
         */
        int[] array4 = null;
        assert 0 == find_number_monotically_increasing_subarrays(array4);

        /*
         * Test 5: Test with an empty array
         */
        int[] array5 = {};
        assert 0 == find_number_monotically_increasing_subarrays(array5);
    }
}
