/*
 * This program fins the number of trailing zeros in the factorial of a
 * positive number. For example:- there is one trailing zero in 5! (5! = 20).
 * There are four trailing zeros in 20! (20! = 2432902008176640000). For more
 * information on the problem, please refer to the following link:-
 * http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>

/*
 * This function returns the number of times five divides a number
 * without leaving any remainder.
 */
int num_five_divisors (int num)
{
    int count;

    /*
     * If number is less than or equal to zero, return zero
     */
    if (num <= 0) {
        return(0);
    }

    count = 0;

    /*
     * Iterate until the division by five gives remainder as
     * zero.
     */
    while ((num % 5) == 0) {

        /*
         * Increment the number of times fives divides the
         * number without leaving a remainder
         */
        ++count;

        /*
         * Divide the number by five
         */
        num /= 5;
    }

    /*
     * Return 'count'
     */
    return(count);
}

/*
 * This function returns the number of trailing zeros in the
 * factorial of a number. The number of trailing zeros depend
 * on the number of five divisors in the factortial of the number.
 * This function attempts to find the number of five divisors in
 * the factorial of the number. The time complexity of this function
 * is O(n) and the space complexity of this function is O(1).
 */
int get_num_trailing_zeros_in_factorial_v1 (int num)
{
    int num_trailing_zeros, index;

    /*
     * If the number is less than zero, then return zero
     */
    if (num <= 0) {
        return(0);
    }

    num_trailing_zeros = 0;
    index = 1;

    /*
     * Iterate over all the numbers less or equal to
     * num and find the total number of five divisors
     * in all the numbers
     */
    while (index <= num) {
        num_trailing_zeros += num_five_divisors(index);
        ++index;
    }

    /*
     * Return the number of fiv divisors in the factorial
     * of the number.
     */
    return(num_trailing_zeros);
}

/*
 * This function returns the number of trailing zeros in the
 * factorial of a number. The number of trailing zeros depend
 * on the number of five divisors in the factortial of the number.
 * This function attempts to find the number of five divisors in
 * the factorial of the number. However, in this function we only
 * inspect the multiples of five for the number of five divisors in
 * the factorial of the number. The time complexity of this function
 * is O(n/5) and the space complexity of this function is O(1).
 */
int get_num_trailing_zeros_in_factorial_v2 (int num)
{
    int num_trailing_zeros, multiple_five_index;

    /*
     * If the number is less than zero, then return zero
     */
    if (num <= 0) {
        return(0);
    }

    num_trailing_zeros = 0;
    multiple_five_index = 5;

    /*
     * Iterate over all the numbers less or equal to
     * num in increments of five and find the total
     * number of five divisors in all the numbers
     */
    while (multiple_five_index <= num) {

        num_trailing_zeros +=
            num_five_divisors(multiple_five_index);

        /*
         * Go to the next multiple of five
         */
        multiple_five_index += 5;
    }

    /*
     * Return the number of fiv divisors in the factorial
     * of the number.
     */
    return(num_trailing_zeros);
}

int get_num_trailing_zeros_in_factorial_v3 (int num)
{
    int num_trailing_zeros, multiple_five_index;

    if (num <= 0) {
        return(0);
    }

    num_trailing_zeros = 0;
    multiple_five_index = 5;

    while (multiple_five_index <= num) {

        num_trailing_zeros += (num / multiple_five_index);

        multiple_five_index *= 5;
    }

    return(num_trailing_zeros);
}

int main ()
{
    assert(0 == get_num_trailing_zeros_in_factorial_v1(-1));
    assert(0 == get_num_trailing_zeros_in_factorial_v2(-1));
    assert(0 == get_num_trailing_zeros_in_factorial_v3(-1));

    assert(0 == get_num_trailing_zeros_in_factorial_v1(0));
    assert(0 == get_num_trailing_zeros_in_factorial_v2(0));
    assert(0 == get_num_trailing_zeros_in_factorial_v3(0));

    assert(0 == get_num_trailing_zeros_in_factorial_v1(1));
    assert(0 == get_num_trailing_zeros_in_factorial_v2(1));
    assert(0 == get_num_trailing_zeros_in_factorial_v3(1));

    assert(0 == get_num_trailing_zeros_in_factorial_v1(2));
    assert(0 == get_num_trailing_zeros_in_factorial_v2(2));
    assert(0 == get_num_trailing_zeros_in_factorial_v3(2));

    assert(0 == get_num_trailing_zeros_in_factorial_v1(3));
    assert(0 == get_num_trailing_zeros_in_factorial_v2(3));
    assert(0 == get_num_trailing_zeros_in_factorial_v3(3));

    assert(0 == get_num_trailing_zeros_in_factorial_v1(4));
    assert(0 == get_num_trailing_zeros_in_factorial_v2(4));
    assert(0 == get_num_trailing_zeros_in_factorial_v3(4));

    assert(1 == get_num_trailing_zeros_in_factorial_v1(5));
    assert(1 == get_num_trailing_zeros_in_factorial_v2(5));
    assert(1 == get_num_trailing_zeros_in_factorial_v3(5));

    assert(4 == get_num_trailing_zeros_in_factorial_v1(20));
    assert(4 == get_num_trailing_zeros_in_factorial_v2(20));
    assert(4 == get_num_trailing_zeros_in_factorial_v3(20));

    assert(6 == get_num_trailing_zeros_in_factorial_v1(25));
    assert(6 == get_num_trailing_zeros_in_factorial_v2(25));
    assert(6 == get_num_trailing_zeros_in_factorial_v3(25));

    assert(24 == get_num_trailing_zeros_in_factorial_v1(100));
    assert(24 == get_num_trailing_zeros_in_factorial_v2(100));
    assert(24 == get_num_trailing_zeros_in_factorial_v3(100));

    return(0);
}
