/*
 * This program checks if a given number is sparse or not. A number is
 * sparse if no consecutive bits in the number are set. For more
 * information on the problem, please refer to the following link:-
 * http://www.geeksforgeeks.org/check-if-a-given-number-is-sparse-or-not/
 */
import java.io.*;
import java.util.*;

public class check_if_binary_representation_of_number_is_sparse
{
    /*
     * This function returns 'true' if no two consecutive bits in the input
     * number are set and 'false' otherwise. The time complexity of this
     * function is O(log(n)) as we iterate through all the bits in the
     * number. The space complexity of this function is O(1).
     */
    public static boolean if_num_is_sparse_v1 (int num)
    {
        int index;

        /*
         * Iterate through all the bits in the number and check if the
         * any of consecutive bits in the number are set. The size of
         * integer in java is 32 bits.
         */
        for (index = 0; index < (32 -1); ++index) {

            /*
             * Bitwise AND operation of the number and '3 << n'
             * should be equal to '3 << n' if there are consecutive
             * bits set in the number. Return 'false' if the below
             * condition is 'true'.
             */
            if ((num & (3 << index)) == (3 << index)) {
                return(false);
            }
        }

        /*
         * Return 'true' since the number is sparse.
         */
        return(true);
    }

    /*
     * This function returns 'true' if no two consecutive bits in the input
     * number are set and 'false' otherwise. The time complexity of this
     * function is O(1). The space complexity of this function is O(1).
     */
    public static boolean if_num_is_sparse_v2 (int num)
    {
        /*
         * If bitwise AND operation of the number and the left
         * shifted version of the number is zero, then the number
         * doesn't have any consecutive bits set.
         */
        return((num & (num << 1)) == 0);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with zero. Zero should be sparse.
         */
        assert(true == if_num_is_sparse_v1(0x00000000));
        assert(true == if_num_is_sparse_v2(0x00000000));

        /*
         * Test 1: Test with only one bit set in number. This number
         *         should be sparse.
         */
        assert(true == if_num_is_sparse_v1(0x00000001));
        assert(true == if_num_is_sparse_v2(0x00000001));

        assert(true == if_num_is_sparse_v1(0x80000000));
        assert(true == if_num_is_sparse_v2(0x80000000));

        /*
         * Test 2: Test with numbers having alternate bits set in them.
         *         These numbers should be sparse.
         */
        assert(true == if_num_is_sparse_v1(0x55555555));
        assert(true == if_num_is_sparse_v2(0x55555555));

        assert(true == if_num_is_sparse_v1(0xaaaaaaaa));
        assert(true == if_num_is_sparse_v2(0xaaaaaaaa));

        /*
         * Test 3: Test with numbers which have four, three or two
         *         consecutive bits set in a nibble. These numbers
         *         should not be sparse. Also test cases when the
         *         nibble in which bits are set is at the beginning,
         *         end and middle of the number.
         */
        assert(false == if_num_is_sparse_v1(0x000f0000));
        assert(false == if_num_is_sparse_v2(0x000f0000));

        assert(false == if_num_is_sparse_v1(0x0000000f));
        assert(false == if_num_is_sparse_v2(0x0000000f));

        assert(false == if_num_is_sparse_v1(0xf0000000));
        assert(false == if_num_is_sparse_v2(0xf0000000));

        assert(false == if_num_is_sparse_v1(0x00070000));
        assert(false == if_num_is_sparse_v2(0x00070000));

        assert(false == if_num_is_sparse_v1(0x00000007));
        assert(false == if_num_is_sparse_v2(0x00000007));

        assert(false == if_num_is_sparse_v1(0x70000000));
        assert(false == if_num_is_sparse_v2(0x70000000));

        assert(false == if_num_is_sparse_v1(0x00030000));
        assert(false == if_num_is_sparse_v2(0x00030000));

        assert(false == if_num_is_sparse_v1(0x00000003));
        assert(false == if_num_is_sparse_v2(0x00000003));

        assert(false == if_num_is_sparse_v1(0x30000000));
        assert(false == if_num_is_sparse_v2(0x30000000));

        /*
         * Test 4: Test with numbers which have consecutive bits set
         *         across two consecutive nibbles in the number. These
         *         number should not be sparse.
         */
        assert(false == if_num_is_sparse_v1(0x18181818));
        assert(false == if_num_is_sparse_v2(0x18181818));

        assert(false == if_num_is_sparse_v1(0x81818181));
        assert(false == if_num_is_sparse_v2(0x81818181));
    }
}
