import java.io.*;
import java.util.*;

public class reverse_an_integer_array
{
    /*
     * This function reverses an integer array in linear time (O(n)).
     */
    public static void reverse (int[] array)
    {
        int left;
        int right;
        int temp;

        /*
         * If the array pointer is NULL, then return from the function
         */
        if (array == null) {
            return;
        }

        left = 0;
        right = array.length - 1;

        /*
         * Iterate while 'left' is less than 'right'
         */
        while (left < right) {

            /*
             * Swap the array elements using a temporary variable.
             */
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;

            /*
             * Increment the 'left' and decrement the 'right'
             * counter.
             */
            ++left;
            --right;
        }
    }

    public static void main(String[] args)
    {
        /*
         * Test case: 1
         */
        int[] array_test_1 = {};
        int[] array_expect_1 = {};
        reverse(array_test_1);
        assert true == Arrays.equals(array_test_1, array_expect_1);

        /*
         * Test case: 2
         */
        int[] array_test_2 = {1,4,5};
        int[] array_expect_2 = {5,4,1};
        reverse(array_test_2);
        assert true == Arrays.equals(array_test_2, array_expect_2);

        /*
         * Test case: 3
         */
        int[] array_test_3 = {1,4,5,9,2,4};
        int[] array_expect_3 = {4,2,9,5,4,1};
        reverse(array_test_3);
        assert true == Arrays.equals(array_test_3, array_expect_3);

        /*
         * Test case: 4
         */
        int[] array_test_4 = null;
        int[] array_expect_4 = null;
        reverse(array_test_4);
        assert true == Arrays.equals(array_test_4, array_expect_4);
    }
}
