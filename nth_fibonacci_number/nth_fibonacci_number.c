/*
 * This program finds the nth fibonacci number using dynmic programming
 * memoization technique.
 */
#include<stdio.h>
#include<assert.h>

/*
 * In case there occurs an error in computing the nth fibonacci number, this
 * is the error value that is returned by the computing functions
 */
#define ILLEGAL                -1

/*
 * Maximum index of the fibonacci number that can be computed by this program
 */
#define MAX_NTH_FIBOACCI_NUMBER 50

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
unsigned long find_nth_fibo_using_dynamic_programming_memoization
                                                    (unsigned long num)
{
    /*
     * Array to store the fibonacci  number up until MAX_NTH_FIBOACCI_NUMBER
     */
    unsigned long fibo_array[MAX_NTH_FIBOACCI_NUMBER + 1];
    unsigned long i;

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
unsigned long find_nth_fibo_using_dynamic_programming (unsigned long num)
{
    unsigned long i, a, b, c;

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

int main ()
{
    /*
     * Test 1: Test with number as 0
     */
    unsigned long num1 = 0;
    unsigned long exp_fib_num1 = 0;
    unsigned long actual_fib_num1;
    actual_fib_num1 = find_nth_fibo_using_dynamic_programming_memoization(num1);
    assert(actual_fib_num1 == exp_fib_num1);
    actual_fib_num1 = find_nth_fibo_using_dynamic_programming(num1);
    assert(actual_fib_num1 == exp_fib_num1);

    /*
     * Test 2: Test with number as 1
     */
    unsigned long num2 = 1;
    unsigned long exp_fib_num2 = 1;
    unsigned long actual_fib_num2;
    actual_fib_num2 = find_nth_fibo_using_dynamic_programming_memoization(num2);
    assert(actual_fib_num2 == exp_fib_num2);
    actual_fib_num2 = find_nth_fibo_using_dynamic_programming(num2);
    assert(actual_fib_num2 == exp_fib_num2);

    /*
     * Test 3: Test with number as 2
     */
    unsigned long num3 = 2;
    unsigned long exp_fib_num3 = 1;
    unsigned long actual_fib_num3;
    actual_fib_num3 = find_nth_fibo_using_dynamic_programming_memoization(num3);
    assert(actual_fib_num3 == exp_fib_num3);
    actual_fib_num3 = find_nth_fibo_using_dynamic_programming(num3);
    assert(actual_fib_num3 == exp_fib_num3);

    /*
     * Test 4: Test with number as 7
     */
    unsigned long num4 = 7;
    unsigned long exp_fib_num4 = 13;
    unsigned long actual_fib_num4;
    actual_fib_num4 = find_nth_fibo_using_dynamic_programming_memoization(num4);
    assert(actual_fib_num4 == exp_fib_num4);
    actual_fib_num4 = find_nth_fibo_using_dynamic_programming(num4);
    assert(actual_fib_num4 == exp_fib_num4);

    /*
     * Test 5: Test with number as 10
     */
    unsigned long num5 = 10;
    unsigned long exp_fib_num5 = 55;
    unsigned long actual_fib_num5;
    actual_fib_num5 = find_nth_fibo_using_dynamic_programming_memoization(num5);
    assert(actual_fib_num5 == exp_fib_num5);
    actual_fib_num5 = find_nth_fibo_using_dynamic_programming(num5);
    assert(actual_fib_num5 == exp_fib_num5);

    /*
     * Test 6: Test with number as 50
     */
    unsigned long num6 = 50;
    unsigned long exp_fib_num6 = 12586269025;
    unsigned long actual_fib_num6;
    actual_fib_num6 = find_nth_fibo_using_dynamic_programming_memoization(num6);
    assert(actual_fib_num6 == exp_fib_num6);
    actual_fib_num6 = find_nth_fibo_using_dynamic_programming(num6);
    assert(actual_fib_num6 == exp_fib_num6);

    /*
     * Test 7: Test with number as 100, which beyond the maximum number that
     *         can be computed by these functions.
     */
    unsigned long num7 = 100;
    unsigned long exp_fib_num7 = -1;
    unsigned long actual_fib_num7;
    actual_fib_num7 = find_nth_fibo_using_dynamic_programming_memoization(num7);
    assert(actual_fib_num7 == exp_fib_num7);
    actual_fib_num7 = find_nth_fibo_using_dynamic_programming(num7);
    assert(actual_fib_num7 == exp_fib_num7);

    return(0);
}
