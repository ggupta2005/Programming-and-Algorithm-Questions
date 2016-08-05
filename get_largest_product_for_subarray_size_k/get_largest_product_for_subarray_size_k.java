/*
 * This program gets the largest product of a subarray of size 'k'
 * in a given array of integers. For more information on this problem
 * please refer to the following link:-
 * http://www.geeksforgeeks.org/largest-product-subarray-size-k/
 */
import java.io.*;
import java.util.*;

public class get_largest_product_for_subarray_size_k
{
    /*
     * This function returns the maximum product of a subarray of length of
     * 'k' for a given array. This function uses the following approach to
     * the maximum product for a subarray:-
     * 1. Compute the product of first 'k' array numbers, that is, compute
     *    the product from all array elements with indices [0, k-1]
     * 2. Iterate over the array from index 'k' to end of the array and
     *    compute the product of subarray using the pre-computed product of
     *    first 'k' numbers.
     * 3. If the product of the new subarray is greater than the previous
     *    maximum product, then update the product.
     * The time complexitty of this soution is O(n), where 'n' is the number
     * of elements in the array, since each element is accessed only once.
     * The space complexity of this function is O(1).
     */
    public static int get_largest_product_subarray_of_size_k (
                                                        int[] array, int k)
    {
        int product, temp_product;
        int i;

        /*
         * If array is a null pointer or its length is invalid or 'k' is less
         * than zero, then return INT_MINN from this function.
         */
        if ((array == null) || (array.length <= 0) || (k <= 0)) {
            return(Integer.MIN_VALUE);
        }

        /*
         * Find the product of first 'k' numbers from the array. Take care
         * of the corener case when 'k' is greater than length of the array.
         */
        product = 1;
        for (i = 0; ((i < k) && (i < array.length)); ++i) {
            product *= array[i];
        }

        /*
         * Find the product of other sub-arrays of size of 'k'
         */
        temp_product = product;
        for (i = k; i < array.length; ++i) {

            /*
             * The product of the sub-array from [i - k + 1, i] can be
             * computed from the already computed product of numbers from
             * [i - k, i - 1], the (i)th and and (i-k)th numbers in the
             * following way
             */
            temp_product = array[i] * (temp_product / array[i-k]);

            /*
             * If the product of the current sub-array is greater than the
             * overall product, then record this product
             */
            if (temp_product > product) {
                product = temp_product;
            }
        }

        /*
         * Return the value of the largest product
         */
        return(product);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test with null array. The largest product returned
         *         by the function should be INT_MIN.
         */
        int[] array1 = null;
        int k1 = 9;
        assert(Integer.MIN_VALUE ==
                        get_largest_product_subarray_of_size_k(
                                                            array1, k1));

        /*
         * Test 2: Test with invalid length of the subarray. The largest
         *         product returned by the function should be INT_MIN.
         */
        int[] array2 = {1, 2, 3};
        int k2 = 0;
        assert(Integer.MIN_VALUE ==
                        get_largest_product_subarray_of_size_k(
                                                            array2, k2));

        /*
         * Test 3: Test with an array, having only one element. The
         *         largest product returned by the function should be
         *         equal to the element itself.
         */
        int[] array3 = {100};
        int k3 = 1;
        assert(100 == get_largest_product_subarray_of_size_k(
                                                            array3, k3));

        /*
         * Test 4: Test with an array, having only multiple elements
         *         but with the length of the subarray being greater
         *         than the length of the array. The largest product
         *         returned by the function should be qual to the
         *         product of all elements in the array.
         */
        int[] array4 = {-100, 1, -3};
        int k4 = array4.length + 1;
        assert(300 == get_largest_product_subarray_of_size_k(
                                                            array4, k4));


        /*
         * Test 5: Test with a valid array and a value of 'k' which is
         *         less than the size of the array.
         */
        int[] array5 = {1, 5, 9, 8, 2, 4, 1, 8, 1, 2};
        int k5 = 6;
        assert(4608 == get_largest_product_subarray_of_size_k(
                                                            array5, k5));

        /*
         * Test 6: Test with another valid array and a value of 'k' which
         *         is less than the size of the array.
         */
        int[] array6 = {1, 5, 9, 8, 2, 4, 1, 8, 1, 2};
        int k6 = 4;
        assert(720 == get_largest_product_subarray_of_size_k(
                                                            array6, k6));

        /*
         * Test 7: Test with another valid array and a value of 'k' which
         *         is less than the size of the array.
         */
        int[] array7 = {2, 5, 8, 1, 1, 3};
        int k7 = 3;
        assert(80 == get_largest_product_subarray_of_size_k(
                                                           array7, k7));
    }
}
