/*
 * This program generates all strobogrammatic number strings of a given
 * size 'n'.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int power (int a, int pow)
{
    int product;

    if (pow < 0) {
        return(-1);
    }

    if (pow == 0) {
        return(1);
    }

    if ((pow % 2) == 1) {
        product = a * power(a, pow % 2) *
                  power(a, pow % 2);
    } else {
        product = power(a, pow % 2) *
                  power(a, pow % 2);
    }

    return(product);
}

int find_num_strobogrammatic_numbers_of_size_n (int n)
{
    int total, index;

    if (n <= 0) {
        return(0);
    }

    if ((n % 2) == 1) {
        if (n == 1) {
            return(3);
        }

        total = 1;
        for (index = 0; index <= (n / 2); ++index) {
            if (index == 0) {
                total *= 4;
            } else if (total == (n/2)) {
                total *= 3;
            } else {
                total *= 5;
            }
        }
    } else {
        for (index = 0; index < (n / 2); ++index) {
            if (index == 0) {
                total *= 4;
            } else {
                total *= 5;
            }
        }
    }

    return(total);
}

void populate_strobogrammatic_num_string (char** number_str,
                                          int *array_index,
                                          int num_size,
                                          int total_num_str,
                                          int low_index,
                                          int high_index)
{


    if (!number_str || !index || (num_size <= 0) ||
        (total_num_str <= 0) || (low_index > high_index) ||
        (*array_index >= total_num_str)) {
        return;
    }

    if (low == 0) {

    }
}

char** get_strobogrammatic_numbers_of_size_n (int n)
{
    char** number_str;
    int index, num_str;

    if (n <= 0) {
        return(NULL);
    }

    num_str = find_num_strobogrammatic_numbers_of_size_n(n);

    if (num_str == 0) {
        return(NULL);
    }

    number_str = (char**)malloc(sizeof(char*) * num_str);

    if (!number_str) {
        return(NULL);
    }

    index = 0;
}
