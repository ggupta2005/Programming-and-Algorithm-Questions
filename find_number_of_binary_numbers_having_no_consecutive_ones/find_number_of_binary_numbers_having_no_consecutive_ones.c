/*
 * This program finds the number of binary strings of length 'n'
 * such that these binary strings do not have consecutive ones. For
 * example if 'n'is 2, then there are three binary strings which do
 * not have consecutive ones in them "00", "01" and "11". For more
 * information on this problem, please refer to the following link:-
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

int get_num_binary_strings_no_consecutive_ones_v1 (
                                           int len,
                                           bool if_previous_bit_is_one)
{
    if (len <= 0) {
        return(0);
    }

    if (len == 1) {
        if (if_previous_bit_is_one) {
            return(1);
        } else {
            return(2);
        }
    }

    if (if_previous_bit_is_one) {
        return(get_num_binary_strings_no_consecutive_ones_v1(len - 1, false));
    }

    return(get_num_binary_strings_no_consecutive_ones_v1(len - 1, true) +
           get_num_binary_strings_no_consecutive_ones_v1(len - 1, false));
}

int get_num_binary_strings_no_consecutive_ones_v2 (int len)
{
    int* bin_str_with_prev_one;
    int* bin_str_without_prev_one;
    int index;

    if (len <= 0) {
        return(0);
    }

    bin_str_with_prev_one = (int*)malloc(sizeof(int) * (len + 1));
    bin_str_without_prev_one = (int*)malloc(sizeof(int) * (len + 1));

    if (!bin_str_with_prev_one || !bin_str_without_prev_one) {
        return(0);
    }

    memset(bin_str_with_prev_one, 0, sizeof(int) *(len + 1));
    memset(bin_str_without_prev_one, 0, sizeof(int) *(len + 1));

    bin_str_with_prev_one[1] = 1;
    bin_str_without_prev_one[1] = 2;

    for (index = 2; index <= len; ++index) {

    }


    if (len == 1) {
        if (if_previous_bit_is_one) {
            return(1);
        } else {
            return(2);
        }
    }
}

int main ()
{
    assert(2 == get_num_binary_strings_no_consecutive_ones_v1(1, false));
    assert(3 == get_num_binary_strings_no_consecutive_ones_v1(2, false));
    assert(5 == get_num_binary_strings_no_consecutive_ones_v1(3, false));
    assert(8 == get_num_binary_strings_no_consecutive_ones_v1(4, false));

    return(0);
}
