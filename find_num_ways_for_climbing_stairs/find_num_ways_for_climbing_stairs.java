/*
 * This program finds the number of ways to reach the nth stair while  climbing
 * stairs in steps of either one and two. For more information on the problem,
 * please refer to the following post:-
 * http://www.geeksforgeeks.org/count-ways-reach-nth-stair/
 */
import java.io.*;
import java.util.*;

public class find_num_ways_for_climbing_stairs
{
    /*
     * This function finds the number of ways in which a person can climb
     * the nth stair starting from zeroth step in steps of one or two steps
     * at a given time. The function uses the dynamic programming technique
     * of memoization to find the solution. We use an array to keep track of
     * the sub-colutions and use the sub-solution to find the number of ways
     * in which the nth stair can be climbed. The time complexity of this
     * function is O(n), where 'n' is the number of stairs to climb. The space
     * complexity of this function is O(n), where 'n' is the number of
     * stairs to climb.
     */
    public static int find_num_ways_for_climbing_stairs_v1 (int num)
    {
        int[] stair_result;
        int i, final_result;

        /*
         * If the number of stairs is zero or less than zero, then return
         * zero from the function
         */
        if (num <= 0) {
            return(0);
        }

        /*
         * Allocate a temporary buffer to keep track of the sub-problems
         */
        stair_result = new int[num + 1];

        /*
         * If the memory allocation fails, then return zero
         */
        if (stair_result == null) {
            return(0);
        }

        /*
         * To climb the first stair, we have only one way
         */
        if (num >= 1) {
            stair_result[1] = 1;
        }

        /*
         * To climb the second stair, we have two ways:-
         * 1. Climb the two stairs one stair at a time
         * 2. Climb both stairs in one go
         */
        if (num >= 2) {
            stair_result[2] = 2;
        }

        /*
         * Iterate from the third stair until the 'num' stair is
         * processed
         */
        for (i = 3; i <= num; ++i) {

            /*
             * The ith stair can be climbed using the following
             * recurrence
             */
            stair_result[i] = stair_result[i-1] + stair_result[i-2];
        }

        /*
         * Cache the number of ways to climb the 'num' stair
         */
        final_result = stair_result[num];

        /*
         * Return the cache result
         */
        return(final_result);
    }

    /*
     * This function finds the number of ways in which a person can climb
     * the nth stair starting from zeroth step in steps of one or two steps
     * at a given time. The function uses the dynamic programming technique
     * of memoization to find the solution. But we do not allocate an array
     * to keep track of all the sub-problems. We only cache the number of
     * ways to climb the last two steps. The time complexity of this
     * function is O(n), where 'n' is the number of stairs to climb.
     * The space complexity of this function is O(1).
     */
    public static int find_num_ways_for_climbing_stairs_v2 (int num)
    {
        int i, final_result;
        int stair_one_prev, stair_two_prev, stair_current;

        /*
         * If the number of stairs is zero or less than zero, then return
         * zero from the function
         */
        if (num <= 0) {
            return(0);
        }

        /*
         * To climb the first stair, we have only one way
         */
        if (num == 1) {
            return(1);
        }

        /*
         * To climb the second stair, we have two ways:-
         * 1. Climb the two stairs one stair at a time
         * 2. Climb both stairs in one go
         */
        if (num == 2) {
            return(2);
        }

        stair_two_prev = 1;
        stair_one_prev = 2;
        stair_current = 0;

        /*
         * Iterate from the third stair until the 'num' stair is
         * processed
         */
        for (i = 3; i <= num; ++i) {

            /*
             * The ith stair can be climbed using the the number of ways
             * to climb the previous step and the second to previous
             * step
             */
            stair_current = stair_one_prev + stair_two_prev;

            /*
             * Set the value of second to previous step to the value of
             * the previous step
             */
            stair_two_prev = stair_one_prev;

            /*
             * Set the value of the previous step to be the value of the
             * ith step
             */
            stair_one_prev = stair_current;
        }

        /*
         * Return the number of ways to climb the 'num' stair
         */
        return(stair_current);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with illegal values of nth stair. The number
         *         of ways to climb should be zero.
         */
        assert(0 == find_num_ways_for_climbing_stairs_v1(-100));
        assert(0 == find_num_ways_for_climbing_stairs_v2(-100));
        assert(0 == find_num_ways_for_climbing_stairs_v1(0));
        assert(0 == find_num_ways_for_climbing_stairs_v2(0));

        /*
         * Test 1: Test with one stair to climb. The number
         *         of ways to climb should be one.
         */
        assert(1 == find_num_ways_for_climbing_stairs_v1(1));
        assert(1 == find_num_ways_for_climbing_stairs_v2(1));

        /*
         * Test 2: Test with two stairs to climb. The number
         *         of ways to climb should be two.
         */
        assert(2 == find_num_ways_for_climbing_stairs_v1(2));
        assert(2 == find_num_ways_for_climbing_stairs_v2(2));

        /*
         * Test 3: Test with three stairs to climb. The number
         *         of ways to climb should be three.
         */
        assert(3 == find_num_ways_for_climbing_stairs_v1(3));
        assert(3 == find_num_ways_for_climbing_stairs_v1(3));

        /*
         * Test 4: Test with four stairs to climb. The number
         *         of ways to climb should be five.
         */
        assert(5 == find_num_ways_for_climbing_stairs_v2(4));
        assert(5 == find_num_ways_for_climbing_stairs_v2(4));
    }
}
