/*
 * This program reverses an integer. For example if the integer is
 * 1452, then the program should return 2541. Another example for a
 * negative number -123, then the program should return -321. If the
 * reversed integer cannot fit into the integer, then the program
 * should return 0.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<limits.h>

int get_reverse_number (int num)
{
    int num_copy;
    int rem;
    int result;
    int factor;

    num_copy = num;
    result = 0;
    factor = 10;

    while (num_copy) {
        rem = num_copy % 10;

        if (num > 0) {
            if (factor * result >= 0) {
                if ((factor * result + rem) >= 0) {
                    result = factor * result + rem;
                } else {
                    return(0);
                }
            } else {
                return(0);
            }
        } else {
            if (factor * result <= 0) {
                if ((factor * result + rem) <= 0) {
                    result = factor * result + rem;
                } else {
                    return(0);
                }
            } else {
                return(0);
            }
        }

        num_copy /= 10;
    }

    return(result);
}

int main ()
{
    assert(0 == get_reverse_number(0));
    assert(1 == get_reverse_number(1));
    assert(-1 == get_reverse_number(-1));
    assert(11 == get_reverse_number(11));
    assert(-11 == get_reverse_number(-11));
    assert(1908 == get_reverse_number(8091));
    assert(-1908 == get_reverse_number(-8091));
    assert(1 == get_reverse_number(1000));
    assert(-1 == get_reverse_number(-1000));
    assert(123321 == get_reverse_number(123321));
    assert(-123321 == get_reverse_number(-123321));
    assert(0 == get_reverse_number(1534236469));
    assert(0 == get_reverse_number(INT_MAX));
    assert(0 == get_reverse_number(INT_MIN));

    return(0);
}
