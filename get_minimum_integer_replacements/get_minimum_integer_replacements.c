/*
 * The problem definition for the following program is as follow:-
 * Given a positive integer n and you can do operations as follow:
 *  - If n is even, replace n with n/2.
 *  - If n is odd, you can replace n with either n + 1 or n - 1.
 * What is the minimum number of replacements needed for n to become 1?
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<limits.h>

#define BITS_PER_BYTE 8

int get_num_bits_set (int num)
{
    int total = 0;
    int index;

    for (index = 0; index < (sizeof(int) * BITS_PER_BYTE);
         ++index) {
        if (num & (1 << index)) {
            ++total;
        }
    }

    return(total);
}

int get_min_integer_replacements (int num)
{
    int total = 0;

    if (num <= 0) {
        return(-1);
    }

    while (num != 1) {
        if ((num % 2) == 0) {
            num /= 2;
        } else {
            if (num == INT_MAX) {
                --num;
            } else if (get_num_bits_set(num + 1)
                            < get_num_bits_set(num - 1)) {
                ++num;
            } else {
                --num;
            }
        }

        ++total;
    }

    printf("%d\n", total);
    return(total);
}

int main ()
{
    assert(-1 == get_min_integer_replacements(-2));
    assert(-1 == get_min_integer_replacements(0));
    assert(0 == get_min_integer_replacements(1));
    assert(1 == get_min_integer_replacements(2));
    assert(2 == get_min_integer_replacements(3));
    assert(2 == get_min_integer_replacements(4));
    assert(3 == get_min_integer_replacements(5));
    assert(32 == get_min_integer_replacements(100000000));
    assert(33 == get_min_integer_replacements(INT_MAX));

    return(0);
}
