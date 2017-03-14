/*
 * This program returns the third largest number is an unsorted array of
 * numbers. If the third largest number doesn't exist, then the program
 * returns the largest number in the array.
 */
import java.io.*;
import java.util.*;

public class find_third_largest_in_an_unsorted_array
{
    /*
     * This function returns the third largest number in an unsorted array
     * of numbers. If the third largest number doesn't exist in the array,
     * then this function returns the largest number in the array. The time
     * complexity of this function is O(n), where 'n' is the number of
     * elements in the array.
     */
    public static int get_third_largest_in_array (int[] array)
    {
        int largest, second_largest, third_largest;
        int index, len;
        boolean if_second_largest_found, if_third_largest_found;

        /*
         * If the array is not valid or the length of the
         * array is not valid, then return minimum integer
         * value
         */
        if ((array == null) || (array.length <= 0)) {
            return(Integer.MIN_VALUE);
        }

        len = array.length;

        /*
         * Set the largest element in the array as the first
         * element in the array
         */
        largest = array[0];
        if_second_largest_found = false;
        if_third_largest_found = false;
        second_largest = Integer.MIN_VALUE;
        third_largest = Integer.MIN_VALUE;

        /*
         * Iterate from the second element in the array till its end
         */
        for (index = 1; index < len; ++index) {
            if (array[index] > largest) {

                /*
                 * If the current element is greater than the largest
                 * element, then do the following if possible:-
                 * 1. Assign the current third largest element to
                 *    current second largest.
                 * 2. Assign the current second largest element to
                 *    current largest.
                 * 3. Assign the current array element to the largest
                 *    element.
                 */
                if (!if_second_largest_found) {
                    second_largest = largest;
                    if_second_largest_found = true;
                } else if (!if_third_largest_found) {
                    third_largest = second_largest;
                    second_largest = largest;
                    if_third_largest_found = true;
                } else {
                    third_largest = second_largest;
                    second_largest = largest;
                }

                largest = array[index];
            } else if (array[index] < largest) {

                /*
                 * If the current element is lesser than the largest
                 * element, then update the second largest element
                 * if the current array element is greater than the
                 * second largest element. Also update the third
                 * largest element if the current array element is
                 * greater than the second largest element
                 */
                if (!if_second_largest_found) {
                    second_largest = array[index];
                    if_second_largest_found = true;
                } else if (array[index] > second_largest) {
                    third_largest = second_largest;
                    second_largest = array[index];
                    if (!if_third_largest_found) {
                        if_third_largest_found = true;
                    }
                } else if (array[index] < second_largest) {

                    /*
                     * If the current element is lesser than the
                     * second largest element, then update the
                     * third largest element if needed.
                     */
                    if (!if_third_largest_found) {
                        third_largest = array[index];
                        if_third_largest_found = true;
                    } else if (array[index] > third_largest) {
                        third_largest = array[index];
                    }
                }
            }
        }

        /*
         * If the third largest element is found in the array, than
         * return third largest otherwise return the largest array
         * element.
         */
        return(if_third_largest_found ? third_largest : largest);
    }

    public static void main (String[] args)
    {

        /*
         * Test 0: Test with an empty array. The third largest
         *         array element should be minimum integer value.
         */
        int[] array0 = null;
        assert(Integer.MIN_VALUE ==
                    get_third_largest_in_array(array0));

        /*
         * Test 1: Test with an array having illegal length. The third
         *         largest array element should be minimum integer value.
         */
        int array1[] = {};
        assert(Integer.MIN_VALUE ==
                    get_third_largest_in_array(array1));

        /*
         * Test 2: Test with an array having only one element.
         *         The function should return that element as
         *         largest element in the array.
         */
        int array2[] = {1};
        assert(1 == get_third_largest_in_array(array2));

        /*
         * Test 3: Test with an array having many elements but one distinct
         *         value. The function should return that value as the
         *         largest element.
         */
        int array3[] = {1,1,1,1,1};
        assert(1 == get_third_largest_in_array(array3));

        /*
         * Test 4: Test with an array having two distinct values.
         *         The function should return that value as the largest
         *         element.
         */
        int array4[] = {1,1,1,1,2};
        assert(2 == get_third_largest_in_array(array4));

        /*
         * Test 5: Test with an array having three distinct values.
         *         The function should return the third largest
         *         element among the three distinct values.
         */
        int array5[] = {1,1,1,1,2,3};
        assert(1 == get_third_largest_in_array(array5));

        /*
         * Test 6: Test with an array having four distinct values.
         *         The function should return the third largest
         *         element among the four distinct values.
         */
        int array6[] = {1,1,1,4,1,2,3};
        assert(2 == get_third_largest_in_array(array6));

    }
}
