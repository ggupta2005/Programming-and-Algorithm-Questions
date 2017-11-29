/*
 * This porgram finds the bitwise xor of all positive numbers from one
 * till a given number. For more information on this problem, please
 * refer to the following link:-
 * http://www.geeksforgeeks.org/calculate-xor-1-n/
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>

#define ILLEGAL              -1
#define BITS_PER_BYTE         4

int find_bitwise_xor_positive_nums_v1 (int num)
{
    int index, bit_xor;

    if (num <= 0) {
        return(ILLEGAL);
    }

    bit_xor = 0;
    for (index = 1; index <= num; ++index) {
        bit_xor ^= index;
    }

    return(bit_xor);
}

int find_bitwise_xor_positive_nums_v2 (int num)
{
    int index, bit_xor, power_two, rem, div;

    if (num <= 0) {
        return(ILLEGAL);
    }

    bit_xor = 0;
    for (index = 0; index < BITS_PER_BYTE * sizeof(int); ++index) {

        if (index > 0) {

            power_two = 1 << (index + 1);

            rem = num % power_two;

            if ((rem % 2) != 0) {
                bit_xor |= (1 << index);
            }

        } else {
            div =

        }
    }
}

int main ()
{
    assert(-1 == find_bitwise_xor_positive_nums_v1(-100));
    assert(-1 == find_bitwise_xor_positive_nums_v1(0));
    assert(7 == find_bitwise_xor_positive_nums_v1(6));
    assert(0 == find_bitwise_xor_positive_nums_v1(7));

    return(0);
}
