/*
 * This program finds the element which occurs odd times in an array. All 
 * other numbers occur even times in the array
 */

import java.io.*;
import java.util.*;

public class element_which_occurs_odd_times_in_array
{
    /*
     * This function finds the element which occurs odd times in a array based 
     * on the logic that XOR operation of an element with itself results in 
     * zero and xor of a number with zero gives us the number itself. So if we
     * XOR all the numbers in the array together, then we will get the number
     * which occurs odd number of times in the array. The time complexity of 
     * this function is O(n). 
     */
    public static int element_odd_times (int []array)
    {    
        int result = 0; /* Set result to zero */
        int i;
       
        /*
         * Take the XOR of all array elements in 'result'.
         */ 
        for (i = 0; i < array.length; ++i) {
            result ^= array[i];
        }

        /*
         * Return the result
         */
        return result;
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test with one occurrence of the odd occurring 
         *         number
         */
        int[] array1 = {12,3,4,4,3,1,1};
        assert 12 == element_odd_times(array1);

        /*
         * Test 2: Test with more than one occurrence of the odd 
         *         occurring number
         */
        int[] array2 = {12,12,12,3,4,4,3,1,1};
        assert 12 == element_odd_times(array2);

        /*
         * Test 3: Test with more than one occurrence of the odd 
         *         occurring number in an array of negative numbers
         */
        int[] array3 = {-12,-12,-12,-3,-4,-4,-3,-1,-1};
        assert -12 == element_odd_times(array3);

        /*
         * Test 4: Test with only one number in the array
         */
        int[] array4 = {12};
        assert 12 == element_odd_times(array4);
    }
}
