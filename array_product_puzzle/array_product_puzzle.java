/*
 * This program solves the problem of finding the product array for an
 * array of integers. An element of product array at index 'index' is
 * defined as the product of all the array elements except the element
 * at index 'index'. The condition in this puzzle that we are not allowed
 * to use the division operator and we need to find the product array in
 * O(n) time. For more on this puzzle, refer to the link:-
 * http://www.geeksforgeeks.org/a-product-array-puzzle/
 */
import java.io.*;
import java.util.*;

public class array_product_puzzle
{
    /*
     * This function constructs and returns the product array from the
     * given array using the following steps:-
     * 1. It constructs the array containing the running product of all
     *    elements from left to right
     * 2. It constructs the array containing the running product of all
     *    elements from righ to left
     * 3. It constructs the product array for an index 'index' by taking by
     *    following formula:-
     *    product_array[index] = left_array[index] * right_array[index]
     * Time complexity of this function is O(n)
     * Space complexity of this function is O(n)
     */
    public static int[] get_product_array (int[] array)
    {
        int i;
        int[] left_product;
        int[] right_product;
        int[] array_product;

        /*
         * If the array or its length are not valid, then return null
         * from this function.
         */
        if ((array == null) || (array.length <= 0)) {
            return(null);
        }

        /*
         * Allocate memory for left running product, right running
         * product and the product array.
         */
        left_product = new int[array.length];
        right_product = new int[array.length];
        array_product = new int[array.length];

        /*
         * If either of the arrays were not allocated successfully,
         * then free all allocated arrays and return null from the
         * function.
         */
        if ((left_product == null) || (right_product == null) ||
            (array_product == null)) {
            return(null);
        }

        /*
         * Initialize each element of the three arrays to be one.
         */
        for (i = 0; i < array.length; ++i) {
            left_product[i] = 1;
            right_product[i] = 1;
            array_product[i] = 1;
        }

        /*
         * Get the running product of all elements from left of the
         * array
         */
        for (i = 1; i < array.length; ++i) {
            left_product[i] = left_product[i-1] * array[i-1];
        }

        /*
         * Get the running product of all elements from right of the
         * array
         */
        for (i = array.length -2; i >= 0; --i) {
            right_product[i] = right_product[i+1] * array[i+1];
        }

        /*
         * The product array is given by the product of corresponding
         * left and the right product arrays
         */
        for (i = 0; i < array.length; ++i) {
            array_product[i] = left_product[i] * right_product[i];
        }

        /*
         * Return the product array
         */
        return(array_product);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a valid array
         */
        int[] array0 = {10, 3, 5, 6, 2};
        int[] expected_array0 = {180, 600, 360, 300, 900};
        int[] actual_array0 = get_product_array(array0);
        assert true == Arrays.equals(expected_array0, actual_array0);

        /*
         * Test 1: Test with a valid array having two elements. The product
         * would contain elements which are inter-changed.
         */
        int[] array1 = {10, 3};
        int[] expected_array1 = {3, 10};
        int[] actual_array1 = get_product_array(array1);
        assert true == Arrays.equals(expected_array1, actual_array1);

        /*
         * Test 2: Test with a valid array having one element. The product
         *         array should contain only one element and that should be one.
         */
        int[] array2 = {10};
        int[] expected_array2 = {1};
        int[] actual_array2 = get_product_array(array2);
        assert true == Arrays.equals(expected_array2, actual_array2);

        /*
         * Test 3: Test with a null array. The product array would be null.
         */
        int[] array3 = null;
        int[] actual_array3 = get_product_array(array3);
        assert actual_array3 == null;

        /*
         * Test 4: Test with an empty array. The product array would be null.
         */
        int[] array4 = {};
        int[] actual_array4 = get_product_array(array4);
        assert actual_array4 == null;
    }
}

