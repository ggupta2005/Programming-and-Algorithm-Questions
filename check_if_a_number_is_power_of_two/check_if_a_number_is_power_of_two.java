/*
 * This program checks if a positive integer is a power of 2. For more
 * information on this, please refer to the link:-
 * http://www.geeksforgeeks.org/write-one-line-c-function-to-find-whether-a-no-is-power-of-two/
 */
import java.io.*;
import java.util.*;

public class check_if_a_number_is_power_of_two
{
    /*
     * This function returns 'true' if the 'num' is a power of two and 'false'
     * otherwise. The function uses bit wise operators to find is a number is a
     * power of two.
     */
    public static boolean if_positive_num_is_power_of_two (int num)
    {
        /*
         * If 'num' is zero, then return 'false'
         */
        if (num <= 0) {
            return(false);
        }

        /*
         * If a 'num' is a power of two, then only one bit in the number will be
         * set. So deducting one from the number will give us a number with all
         * bits set to the right of the bit set in the original number. Taking 'and'
         * of the number and one less of the number should give us zero.
         */
        return((num & (num - 1)) == 0);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: '0' is not a power of two
         */
        assert(false == if_positive_num_is_power_of_two(0));

        /*
         * Test 1: '1' is a power of two
         */
        assert(true == if_positive_num_is_power_of_two(1));

        /*
         * Test 2: '2' is a power of two
         */
        assert(true == if_positive_num_is_power_of_two(2));

        /*
         * Test 3: '3' is not a power of two
         */
        assert(false == if_positive_num_is_power_of_two(3));

        /*
         * Test 4: '1024' is a power of two
         */
        assert(true == if_positive_num_is_power_of_two(1024));

        /*
         * Test 5: '1040' is not a power of two
         */
        assert(false == if_positive_num_is_power_of_two(1040));

        /*
         * Test 6: a negative number is not a power of two
         */
        assert(false == if_positive_num_is_power_of_two(-1024));
    }
}
