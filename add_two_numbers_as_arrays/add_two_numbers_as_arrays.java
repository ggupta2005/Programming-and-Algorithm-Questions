/*
 * This program adds two numbers represented as integer arrays. The
 * elements of these integer arrays can only be numbers from 0-9 and
 * the leading digit of the array will be non-zero. For example, if
 * the two integer arrays are {4,5,6} and {2,3,4}, then the sum of the
 * integer array will be {6,9,0}. Another example, if the two integer
 * arrays are {1,2,3} and {9,9,9}, then the summ array will be
 * {1.1,2,2}
 */
import java.io.*;
import java.util.*;

public class add_two_numbers_as_arrays
{
    /*
     * This function takes two integer number arrays and returns the
     * 'sum' array with the sum of the two number arrays. The time
     * complexity of this function is O(n), where 'n' is number of
     * digits in the number arrays.
     */
    public static int[] add_two_integer_arrays (int[] num1, int[] num2)
    {
        int i, j, k;
        int carry;
        int[] sum = null;
        int[] new_sum = null;
        int sum_len;

        /*
         * When both number arrays are null, then return null
         */
        if ((num1 == null) && (num2 == null)) {
            return(sum);
        }

        /*
         * When both number arrays are of length zero, then return null
         */
        if ((num1 != null && num2 != null) &&
            ((num1.length <= 0) && (num2.length <= 0))) {
            return(sum);
        }

        /*
         * We set the length of the sum array as one greater than the
         * maximum legal length to take care of the carry over scenario
         */
        if ((num1 != null) && (num2 != null)) {

            /*
             * If both number arrays are legal, then set the length of
             * the sum array as higher length of the two number arrays.
             */
            sum_len = (num1.length > num2.length) ?
                                    (num1.length + 1):(num2.length + 1);
        } else if (num1 != null) {

            /*
             * If only the first number array is legal, then set the length
             * of the sum array as the length of the first array
             */
            sum_len = num1.length + 1;
        } else {

            /*
             * If only the second number array is legal, then set the length
             * of the sum array as the length of the second array
             */
            sum_len = num2.length + 1;
        }

        /*
         * Allocate the sum array
         */
        sum = new int[sum_len];

        if (sum == null) {

            /*
             * If the allocation of sum array failes, then return null
             */
            return(sum);
        }

        /*
         * Set the appropriate value of the index into the first array.
         */
        if (num1 != null) {

            /*
             * We set the index into the first array as the last index in
             * first array because the LSB is the last element in the first
             * array
             */
            i = num1.length - 1;
        } else {

            /*
             * If the first array is not legal, then set the index to -1
             */
            i = -1;
        }

        /*
         * Set the appropriate value of the index into the second array.
         */
        if (num2 != null) {

            /*
             * We set the index into the second array as the last index in
             * second array because the LSB is the last element in the second
             * array
             */
            j = num2.length - 1;
        } else {

            /*
             * If the second array is not legal, then set the index to -1
             */
            j = -1;
        }

        /*
         * Set the index into the sum array at the LSB
         */
        k = sum_len - 1;

        /*
         * Set the value of carry to zero
         */
        carry = 0;

        /*
         * Iterate through the number arrays until the indexes are legal
         */
        while ((i >= 0) && (j >= 0)) {

            /*
             * Set the sum and the carry variables
             */
            sum[k] = (num1[i] + num2[j] + carry) % 10;
            carry = (num1[i] + num2[j] + carry) / 10;

            /*
             * Decrement the indexes
             */
            --i;
            --j;
            --k;
        }

        /*
         * Iterate though the first array until the index into the
         * first array is legal
         */
        while (i >= 0) {
            sum[k] = (num1[i] + carry) % 10;
            carry = (num1[i] + carry) / 10;

            --i;
            --k;
        }

        /*
         * Iterate though the second array until the index into the
         * second array is legal
         */
        while (j >= 0) {
            sum[k] = (num2[j] + carry) % 10;
            carry = (num2[j] + carry) / 10;

            --j;
            --k;
        }

        if (carry > 0) {

            /*
             * If carry is greater than zero, then set the MSB in sum array
             * as carry
             */
            sum[0] = carry;
        } else {

            /*
             * In this case, the sum can fit into the length of the larger
             * number array, so allocate an integer array with the length of
             * the larger length and copy the elements from the sum array into
             * the new sum array
             */
            sum_len = sum_len - 1;
            new_sum = new int[sum_len];

            if (new_sum == null) {

                /*
                 * If the memory allocation fails then return null
                 */
                return(null);
            } else {

                /*
                 * Copy the old sum array into the new sum array
                 */
                for (i = 1; i < (sum_len + 1); ++i) {
                    new_sum[i - 1] = sum[i];
                }

                /*
                 * Point the sum array to new sum array
                 */
                sum = new_sum;
            }
        }

        return(sum);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test with null number arrays. The sum array should be
         *         null after calling the function to add the number arrays.
         */
        int[] first1 = null;
        int[] second1 = null;
        int[] expected_sum1 = null;
        int[] actual_sum1 = add_two_integer_arrays(first1, second1);
        assert(actual_sum1 == expected_sum1);

        /*
         * Test 2: Test with number arrays having zero lengths. The sum array
         *         should be null and its length should be 0 after calling the
         *         function to add the number arrays.
         */
        int[] first2 = {};
        int[] second2 = {};
        int[] expected_sum2 = null;
        int[] actual_sum2 = add_two_integer_arrays(first2, second2);
        assert(actual_sum2 == expected_sum2);

        /*
         * Test 3: Test with the second number array having zero length. The
         *         sum array should be same as the first number array which has
         *         non-zero length after the call to function to add the number
         *         arrays.
         */
        int[] first3 = {1,2,3};
        int[] second3 = {};
        int[] expected_sum3 = {1,2,3};
        int[] actual_sum3 = add_two_integer_arrays(first3, second3);
        assert(Arrays.equals(actual_sum3, expected_sum3));

        /*
         * Test 4: Test with the second number array being null. The sum array
         *         should be same as the first number array which has non-zero
         *         length after the call to function to add the number arrays.
         */
        int[] first4 = {1,2,3};
        int[] second4 = null;
        int[] expected_sum4 = {1,2,3};
        int[] actual_sum4 = add_two_integer_arrays(first4, second4);
        assert(Arrays.equals(actual_sum4, expected_sum4));

        /*
         * Test 5: Test with the first number array having zero length. The
         *         sum array should be same as the second number array which has
         *         non-zero length after the call to function to add the number
         *         arrays.
         */
        int[] first5 = {};
        int[] second5 = {1,2,3};
        int[] expected_sum5 = {1,2,3};
        int[] actual_sum5 = add_two_integer_arrays(first5, second5);
        assert(Arrays.equals(actual_sum5, expected_sum5));

        /*
         * Test 6: Test with the first number array being null. The sum array
         *         should be same as the second number array which has non-zero
         *         length after the call to function to add the number arrays.
         */
        int[] first6 = null;
        int[] second6 = {1,2,3};
        int[] expected_sum6 = {1,2,3};
        int[] actual_sum6 = add_two_integer_arrays(first6, second6);
        assert(Arrays.equals(actual_sum6, expected_sum6));

        /*
         * Test 7: Both the number arrays first and second are legal number
         *         arrays. The sum of the number arrays does not result in
         *         additional MSB digit.
         */
        int[] first7 = {1,9,9};
        int[] second7 = {1,2,3};
        int[] expected_sum7 = {3,2,2};
        int[] actual_sum7 = add_two_integer_arrays(first7, second7);
        assert(Arrays.equals(actual_sum7, expected_sum7));

        /*
         * Test 8: Both the number arrays first and second are legal number
         *         arrays. The sum of the number arrays does result in
         *         additional MSB digit.
         */
        int[] first8 = {9,9,9};
        int[] second8 = {1,2,3};
        int[] expected_sum8 = {1,1,2,2};
        int[] actual_sum8 = add_two_integer_arrays(first8, second8);
        assert(Arrays.equals(actual_sum8, expected_sum8));

        /*
         * Test 9: Both the number arrays first and second are legal number
         *         arrays. The number arrays have different lengths. The
         *         length of first array is greater than second array
         */
        int[] first9 = {9,9,9};
        int[] second9 = {3};
        int[] expected_sum9 = {1,0,0,2};
        int[] actual_sum9 = add_two_integer_arrays(first9, second9);
        assert(Arrays.equals(actual_sum9, expected_sum9));

        /*
         * Test 10: Both the number arrays first and second are legal number
         *          arrays. The number arrays have different lengths. The
         *          length of first array is greater than second array
         */
        int[] first10 = {3};
        int[] second10 = {9,9,9};
        int[] expected_sum10 = {1,0,0,2};
        int[] actual_sum10 = add_two_integer_arrays(first10, second10);
        assert(Arrays.equals(actual_sum10, expected_sum10));
    }
}
