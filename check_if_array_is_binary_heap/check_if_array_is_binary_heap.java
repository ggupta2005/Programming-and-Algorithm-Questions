/*
 * This program checks if an array represents a max heap. More
 * information on this can be found on the following link:-
 * http://www.geeksforgeeks.org/how-to-check-if-a-given-array-represents-a-binary-heap/
 */
import java.io.*;
import java.util.*;

public class check_if_array_is_binary_heap
{
    /*
     * This function returns 'true' if the array satisfies the max-heap property
     * and 'false' otherwise. This function finds the left child and right child
     * for a particular array entry (using heap property of child nodes) and
     * compare the array entry with the left and the right children. If the array
     * entry is greater than both left and right children, then the array entry
     * satisfies the heap property. The time complexity of this function is O(n)
     * where 'n' is the number of array elements and for each array entry, we
     * perform at most two comparison operations. The space complexity of this
     * function is O(1).
     */
    public static boolean if_array_satifies_binary_heap_property (int[] array)
    {
        int index, left_child_index, right_child_index, heap_size;

        /*
         * If the array in NULL or the heap size is invalid, then this array
         * cannot be a heap. Return from 'false' from this function
         */
        if ((array == null) || (array.length <= 0)) {
            return(false);
        }

        /*
         * Get the size of the heap
         */
        heap_size = array.length;

        /*
         * Iterate over the array to find if each element of the array satisfies
         * the max-heap property
         */
        for (index = 0; index < heap_size; index++) {

            /*
             * Compute left child index
             */
            left_child_index = 2 * index + 1;

            /*
             * Compute right child index
             */
            right_child_index = 2 * index + 2;

            /*
             * If the left child index is less than the heap size,
             * then check if the left child is lesser than the
             * parent to satisfy the max heap property
             */
            if (left_child_index < heap_size) {

                /*
                 * If the left child is greater than the parent, then
                 * return 'false'
                 */
                if (array[left_child_index] > array[index]) {
                    return(false);
                }
            }

            /*
             * If the right child index is less than the heap size,
             * then check if the right child is lesser than the
             * parent to satisfy the max heap property
             */
            if (right_child_index < heap_size) {

                /*
                 * If the right child is greater than the parent, then
                 * return 'false'
                 */
                if (array[right_child_index] > array[index]) {
                    return(false);
                }
            }
        }

        /*
         * The array satisfies the max heap property, so return 'true'
         */
        return(true);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a NULL array. This should not be a max-heap
         */
        int[] array0 = null;
        assert(false == if_array_satifies_binary_heap_property(array0));

        /*
         * Test 1: An array having only one element is a max-heap by default
         */
        int[] array1 = {1};
        assert(true == if_array_satifies_binary_heap_property(array1));

        /*
         * Test 2: test an array having max-heap property
         */
        int[] array2 = {11, 9, 10, 7, 8, 5, 4, 3, 2, 1, 0};
        assert(true == if_array_satifies_binary_heap_property(array2));

        /*
         * Test 3: test an array not having max-heap property. The right child
         *         does not satify the max-heap property
         */
        int[] array3 = {11, 9, 10, 7, 8, 5, 4, 3, 13, 1, 0};
        assert(false == if_array_satifies_binary_heap_property(array3));

        /*
         * Test 4: test an array not having max-heap property. The left child
         *         does not satify the max-heap property
         */
        int[] array4 = {11, 9, 10, 7, 8, 5, 4, 14, 2, 1, 0};
        assert(false == if_array_satifies_binary_heap_property(array4));

        /*
         * Test 5: Test with an empty array. This should not be a max-heap
         */
        int[] array5 = {};
        assert(false == if_array_satifies_binary_heap_property(array5));
    }
}
