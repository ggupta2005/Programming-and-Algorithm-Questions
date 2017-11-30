/*
 * This programs finds the maximum zeros between two ones in the binary
 * representation of an integer. For example for the number "1030", the
 * binary representation is "10000000110" and the amximum number of zeros
 * between two ones is 7.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<limits.h>

int find_maximum_0s_between_two_1s_in_binary_representation (int num)
{
    int max, index, one_index, num_ones;
    bool found_first_one;

    if (num == 0) {
        return(-1);
    }

    max = 0;
    num_ones = 0;
    found_first_one = false;
    for (index = 0; index < sizeof(int) * CHAR_BIT; ++index) {

        if (num & (1 << index)) {

            num_ones++;

            if (!found_first_one) {
                found_first_one = true;
            } else {
                if ((index - one_index - 1) > max) {
                    max = index - one_index - 1;
                }
            }

            one_index = index;
        }
    }

    if (num_ones == 1) {
        return(-1);
    }

    return(max);
}

int main ()
{
    assert(-1 == find_maximum_0s_between_two_1s_in_binary_representation(0));
    assert(-1 == find_maximum_0s_between_two_1s_in_binary_representation(1));
    assert(-1 == find_maximum_0s_between_two_1s_in_binary_representation(2));

    assert(0 == find_maximum_0s_between_two_1s_in_binary_representation(3));
    assert(0 == find_maximum_0s_between_two_1s_in_binary_representation(0x0000ffff));
    assert(0 == find_maximum_0s_between_two_1s_in_binary_representation(0xffff0000));
    assert(0 == find_maximum_0s_between_two_1s_in_binary_representation(0xffffffff));

    assert(2 == find_maximum_0s_between_two_1s_in_binary_representation(9));
    assert(7 == find_maximum_0s_between_two_1s_in_binary_representation(1030));
    assert(1 == find_maximum_0s_between_two_1s_in_binary_representation(47));
    assert(3 == find_maximum_0s_between_two_1s_in_binary_representation(549));

    assert(1 == find_maximum_0s_between_two_1s_in_binary_representation(0xaaaaaaaa));
    assert(1 == find_maximum_0s_between_two_1s_in_binary_representation(0x55555555));
    assert(30 == find_maximum_0s_between_two_1s_in_binary_representation(0x80000001));

    return(0);
}
