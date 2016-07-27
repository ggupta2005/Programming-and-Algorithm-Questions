/*
 * This program checks if two integers are equal without
 * using any comparison operators.
 */
import java.io.*;
import java.util.*;

public class check_if_integers_are_equal_without_comparison_operators
{
    /*
     * This function returns 'true' if the two integers are equal and
     * 'false' otherwise. This function returns xor of the two integers.
     * If the computed xor is zero, then the numbers are equal else they
     * are un-equal. The time complexity of this function is O(1).
     */
    public static int if_equal (int a, int b)
    {
        return(a ^ b);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test if two positive numbers are equal
         */
        assert(0 == if_equal(156, 156));

        /*
         * Test 1: Test if two positive numbers are un-equal
         */
        assert(0 != if_equal(159, 156));

        /*
         * Test 2: Test if two negative numbers are equal
         */
        assert(0 == if_equal(-15, -15));

        /*
         * Test 3: Test if two negative numbers are un-equal
         */
        assert(0 != if_equal(-15, -19));
    }
}
