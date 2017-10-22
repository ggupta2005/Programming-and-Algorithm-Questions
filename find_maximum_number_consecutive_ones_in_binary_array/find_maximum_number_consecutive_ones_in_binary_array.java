/*
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 *
 * Example 1:
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 *              1s.
 * The maximum number of consecutive 1s is 3.
 */
import java.io.*;
import java.util.*;

public class find_maximum_number_consecutive_ones_in_binary_array
{
    /*
     * This function returns the maximum number of consecutive ones in a binary
     * array. The time complexity of this function is O(n), where 'n' is the
     * number of elements in the array. The space complexity of the function is
     * O(1).
     */
    public static int find_max_consecutive_ones (int[] nums)
    {
        int index, max_cons_ones, temp_cons_ones;
        boolean if_inside_ones;

        /*
         * If the binary array is not valid or the number of elements
         * in the array is not valid, then return zero.
         */
        if (nums == null || (nums.length <= 0)) {
            return(0);
        }

        max_cons_ones = 0;
        temp_cons_ones = 0;
        if_inside_ones = false;

        /*
         * Iterate through the entire array
         */
        for (index = 0; index < nums.length; ++index) {


            if (nums[index] == 1) {

                /*
                 * If the current entry in the array is one, then
                 * count increment the current number of consecutive
                 * ones.
                 */
                if (!if_inside_ones) {
                    if_inside_ones = true;
                }
                ++temp_cons_ones;
            } else {
                /*
                 * If the current entry in the array is zero, then
                 * maximum number of consecutive ones.
                 */
                if (if_inside_ones) {
                    if (temp_cons_ones > max_cons_ones) {
                        max_cons_ones = temp_cons_ones;
                    }

                    temp_cons_ones = 0;
                    if_inside_ones = false;
                }
            }
        }

        if (temp_cons_ones > max_cons_ones) {
            max_cons_ones = temp_cons_ones;
        }

        return(max_cons_ones);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: The input array has all zeros. So there are no
         *         consecutive ones in the array.
         */
        int[] array0 = {0,0,0,0,0};
        assert(0 == find_max_consecutive_ones(array0));

        /*
         * Test 1: The input array has all ones. So the maximum number
         *         of consecutive ones in the array should be equal to
         *         the length of the array.
         */
        int[] array1 = {1,1,1,1,1};
        assert(array1.length == find_max_consecutive_ones(array1));

        /*
         * Test 2: The input array has mix of zeros and ones.
         */
        int[] array2 = {1,1,0,1,1,1};
        assert(3 == find_max_consecutive_ones(array2));

        /*
         * Test 3: The input array has alternating zeros and ones.
         *         The maximum consecutive number of ones in the
         *         array should be one.
         */
        int[] array3 = {1,0,1,0,1,0,1};
        assert(1 == find_max_consecutive_ones(array3));
    }
}
