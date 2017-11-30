/*
 * This program adds two numbers without using any
 * airthmaetic operators.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>

int add_two_numbs_without_using_airthmetic_ops (int a, int b)
{
    int index;
    int result, carry;
    int a_bit_index;
    int b_bit_index;

    result = 0;
    for (index = 0; index < sizeof(int); ++index) {

        a_bit_index = a & (1 << index);

        b_bit_index = b & (1 << index);

        carry = b_bit_index & a_bit_index;

    }

}
