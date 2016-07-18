/*
 * This program finds the nth fibonacci number using dynmic programming
 * memoization technique.
 */
import java.io.*;
import java.util.*;

public class nth_fibonacci_number
{
    public static final long ILLEGAL = -1;
    public static final int MAX_NTH_FIBOACCI_NUMBER = 50;

    /*
     * This function computes the nth fibonacci number using the dynamic programming
     * approach of memoization. We compute the nth fibonacci number using bottom up
     * approach by computing and storing the smaller fibonacci numbers and using the
     * stored fibonacci numbers to compute the larger fibonacci numbers. If there is
     * some error encountered in computing the fibonacci numbers, then some error value
     * is returned from this function.
     * The time complexity is O(num).
     * The space complexity is O(num).
     */
    public static  long find_nth_fibo_using_dynamic_programming_memoization
                                                                (int num)
    {
        /*
         * Array to store the fibonacci  number up until MAX_NTH_FIBOACCI_NUMBER
         */
        long[] fibo_array= new long[MAX_NTH_FIBOACCI_NUMBER + 1];
        int i;

        /*
         * If 'num' is greater than MAX_NTH_FIBOACCI_NUMBER, then return error from
         * this function.
         */
        if (num > MAX_NTH_FIBOACCI_NUMBER) {
            return(ILLEGAL);
        }

        /*
         * Address the base case of num being 0
         */
        if (num == 0) {
            return(0);
        }

        /*
         * Address the base case of num being 1
         */
        if (num == 1) {
            return(1);
        }

        /*
         * Set the first two elelments of the array stroing the fibonacci numbers
         */
        fibo_array[0] = 0;
        fibo_array[1] = 1;

        /*
         * Iterate from 2 until 'num' to compute all fibonacci numbers until the
         * 'num'th fibonacci number.
         */
        for (i = 2; i <= num; ++i) {
            fibo_array[i] = fibo_array[i-2] + fibo_array[i-1];
        }

        /*
         * Return the 'num' fibonacci number
         */
        return(fibo_array[num]);
    }

    /*
     * This function computes the nth fibonacci number using the dynamic programming
     * approach but without any memoization. We compute the nth fibonacci number by computing
     * the running sum in the last two required fibonacci numbers which are required to
     * compute the current fibonacci number. If there is some error encountered in computing
     * the fibonacci numbers, then some error value is returned from this function.
     * The time complexity is O(num).
     * The space complexity is O(1).
     */
    public static long find_nth_fibo_using_dynamic_programming (int num)
    {
        long  a, b, c;
        int i;

        /*
         * If 'num' is greater than MAX_NTH_FIBOACCI_NUMBER, then return error from
         * this function.
         */
        if (num > MAX_NTH_FIBOACCI_NUMBER) {
            return(ILLEGAL);
        }

        /*
         * Address the base case of num being 0
         */
        if (num == 0) {
            return(0);
        }

        /*
         * Address the base case of num being 1
         */
        if (num == 1) {
            return(1);
        }

        /*
         * Set the first two elelments of the array stroing the fibonacci numbers
         */
        a = 0;
        b = 1;
        c = a + b;

        /*
         * Iterate from 2 until 'num' to compute the 'num'th fibonacci number.
         */
        for (i = 2; i <= num; ++i) {
            c = a + b;
            a = b;
            b = c;
        }

        /*
         * Return the 'num' fibonacci number
         */
        return(c);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test with number as 0
         */
        int num1 = 0;
        long exp_fib_num1 = 0;
        long actual_fib_num1;
        actual_fib_num1 = find_nth_fibo_using_dynamic_programming_memoization(num1);
        assert actual_fib_num1 == exp_fib_num1;
        actual_fib_num1 = find_nth_fibo_using_dynamic_programming(num1);
        assert actual_fib_num1 == exp_fib_num1;

        /*
         * Test 2: Test with number as 1
         */
        int num2 = 1;
        long exp_fib_num2 = 1;
        long actual_fib_num2;
        actual_fib_num2 = find_nth_fibo_using_dynamic_programming_memoization(num2);
        assert actual_fib_num2 == exp_fib_num2;
        actual_fib_num2 = find_nth_fibo_using_dynamic_programming(num2);
        assert actual_fib_num2 == exp_fib_num2;

        /*
         * Test 3: Test with number as 2
         */
        int num3 = 2;
        long exp_fib_num3 = 1;
        long actual_fib_num3;
        actual_fib_num3 = find_nth_fibo_using_dynamic_programming_memoization(num3);
        assert actual_fib_num3 == exp_fib_num3;
        actual_fib_num3 = find_nth_fibo_using_dynamic_programming(num3);
        assert actual_fib_num3 == exp_fib_num3;

        /*
         * Test 4: Test with number as 7
         */
        int num4 = 7;
        long exp_fib_num4 = 13;
        long actual_fib_num4;
        actual_fib_num4 = find_nth_fibo_using_dynamic_programming_memoization(num4);
        assert actual_fib_num4 == exp_fib_num4;
        actual_fib_num4 = find_nth_fibo_using_dynamic_programming(num4);
        assert actual_fib_num4 == exp_fib_num4;

        /*
         * Test 5: Test with number as 10
         */
        int num5 = 10;
        long exp_fib_num5 = 55;
        long actual_fib_num5;
        actual_fib_num5 = find_nth_fibo_using_dynamic_programming_memoization(num5);
        assert actual_fib_num5 == exp_fib_num5;
        actual_fib_num5 = find_nth_fibo_using_dynamic_programming(num5);
        assert actual_fib_num5 == exp_fib_num5;

        /*
         * Test 6: Test with number as 50
         */
        int num6 = 50;
        long exp_fib_num6 = 12586269025L;
        long actual_fib_num6;
        actual_fib_num6 = find_nth_fibo_using_dynamic_programming_memoization(num6);
        assert actual_fib_num6 == exp_fib_num6;
        actual_fib_num6 = find_nth_fibo_using_dynamic_programming(num6);
        assert actual_fib_num6 == exp_fib_num6;

        /*
         * Test 7: Test with number as 100, which beyond the maximum number that
         *         can be computed by these functions.
         */
        int num7 = 100;
        long exp_fib_num7 = -1;
        long actual_fib_num7;
        actual_fib_num7 = find_nth_fibo_using_dynamic_programming_memoization(num7);
        assert actual_fib_num7 == exp_fib_num7;
        actual_fib_num7 = find_nth_fibo_using_dynamic_programming(num7);
        assert actual_fib_num7 == exp_fib_num7;

    }
}
