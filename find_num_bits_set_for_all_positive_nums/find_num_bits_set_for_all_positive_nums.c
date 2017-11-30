/*
 * This program finds the number of bits set on all positive
 * numbers till a given positive number. More information on
 * this can be found at the following link:-
 * http://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>

#define BITS_PER_BYTE 8

unsigned long count_num_bits_set_for_all_positive_numbers_v1
                                                (unsigned long num)
{
    unsigned long total_bits_set, index, bit_index;
    unsigned long bits_set_in_num;

    total_bits_set = 0;
    for (index = 0; index <= num; ++index) {

        bits_set_in_num = 0;
        for (bit_index = 0; bit_index < (sizeof(num) * BITS_PER_BYTE);
             bit_index++) {

            if (index & (1 << bit_index)) {
                bits_set_in_num++;
            }
        }

        total_bits_set += bits_set_in_num;
    }

    return(total_bits_set);
}

unsigned long count_num_bits_set_for_all_positive_numbers_v2
                                                (unsigned long num)
{
    unsigned long total_bits_set, index, bit_index;
    unsigned long bits_set_in_num;

    total_bits_set = 0;


    return(total_bits_set);
}

