/*
 * This program finds total number of positive numbers containing 'n' digits
 * which do not have a given digit.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<limits.h>

int get_num_digits (int num)
{
    int num_digits;

    num_digits = 0;
    while (num) {
        ++num_digits;

        num /= 10;
    }

    return(num_digits);
}

int power (int a, int pow)
{
    int product;

    if (pow < 0) {
        return(-1);
    }

    if (pow == 0) {
        return(1);
    }

    if (pow == 1) {
        return(a);
    }

    product = power(a, pow / 2);

    if (pow % 2 == 1) {
        return(product * product * a);
    }

    return(product * product);
}

int find_total_num_containing_n_digits_not_having_a_given_digit (
                                                            int n_digits,
                                                            int digit)
{
    int total_num;

    if ((n_digits <= 0) || (n_digits >= get_num_digits(INT_MAX))) {
        return(-1);
    }

    if ((digit < 0) || (digit > 9)) {
        return(-1);
    }

    total_num = 1;

    if (digit != 0) {
        total_num *= (10 - 1 - 1) * power(10 - 1, n_digits - 1);
    } else {
        total_num *= (10 - 1) * power(10 - 1, n_digits - 1);
    }

    printf("num = %d\n", total_num);
    return(total_num);
}

int main ()
{
    assert(9 == find_total_num_containing_n_digits_not_having_a_given_digit(1, 0));
    assert(8 == find_total_num_containing_n_digits_not_having_a_given_digit(1, 1));
    assert(8 == find_total_num_containing_n_digits_not_having_a_given_digit(1, 2));
    assert(8 == find_total_num_containing_n_digits_not_having_a_given_digit(1, 3));

    assert(81 == find_total_num_containing_n_digits_not_having_a_given_digit(2, 0));
    assert(72 == find_total_num_containing_n_digits_not_having_a_given_digit(2, 1));
    assert(72 == find_total_num_containing_n_digits_not_having_a_given_digit(2, 2));
    assert(72 == find_total_num_containing_n_digits_not_having_a_given_digit(2, 3));

    assert(729 == find_total_num_containing_n_digits_not_having_a_given_digit(3, 0));
    assert(648 == find_total_num_containing_n_digits_not_having_a_given_digit(3, 1));
    assert(648 == find_total_num_containing_n_digits_not_having_a_given_digit(3, 2));
    assert(648 == find_total_num_containing_n_digits_not_having_a_given_digit(3, 3));

    return(0);
}
