/*
 * Given a non-negative integer n, count all numbers with unique
 * digits, x, where 0 ≤ x < 10n.
 * Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the
 *                          range of 0 ≤ x < 100, excluding [11,22,33,44,55,
 *                                                           66,77,88,99])
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>

int number_of_n_digits_with_unique_digits (int n)
{
    int total = 1, index, start = 9;

    if (n <= 0) {
        return(1);
    }

    start = 9;
    for (index = 1; index <= n; ++index) {
        if (index <= 2) {
            total *= start;
        } else {
            total *= (start - index + 2);
        }
    }

    return(total);
}

int countNumbersWithUniqueDigits(int n) {

    int total = 0, index;

    for (index = 0; index <= n; ++index) {
        total += number_of_n_digits_with_unique_digits(index);
    }

    return(total);
}

int main ()
{
    assert(1 == countNumbersWithUniqueDigits(0));
    assert(10 == countNumbersWithUniqueDigits(1));
    assert(91 == countNumbersWithUniqueDigits(2));

    return(0);
}
