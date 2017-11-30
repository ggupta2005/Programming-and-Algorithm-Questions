/*
 * This program adds one to a number represented as an array.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int index, num_nines, carry;
    int* result_array;

    if (!digits || !returnSize || (digitsSize <= 0)) {
        return(NULL);
    }

    for (index = 0; index < digitsSize; ++index) {
        if ((digits[index] < 0) || (digits[index] > 9)) {
            *returnSize = 0;
            return(NULL);
        }
    }

    num_nines = 0;
    for (index = 0; index < digitsSize; ++index) {
        if (digits[index] == 9) {
            num_nines++;
        }
    }

    if (num_nines == digitsSize) {
        result_array = (int*)malloc(sizeof(int) * (digitsSize + 1));
        *returnSize = digitsSize + 1;
    } else {
        result_array = (int*)malloc(sizeof(int) * digitsSize);
        *returnSize = digitsSize;
    }

    if (!result_array) {
        *returnSize = 0;
        return(NULL);
    }

    if (num_nines == digitsSize) {
        result_array[0] = 1;

        for (index = 1; index <= digitsSize; ++index) {
            result_array[index] = 0;
        }
    } else {

        carry = 1;
        for (index = digitsSize - 1; index >= 0; --index) {
            result_array[index] = (digits[index] + carry) % 10;
            carry = (digits[index] + carry) / 10;
        }
    }

    return(result_array);
}

int main ()
{
    int array0[] = {9,9,9,9,9};
    int len0 = sizeof(array0)/sizeof(int);
    int act_len0;
    int* act_array0 = plusOne(array0, len0, &act_len0);
    int exp_len0 = len0 + 1;
    int exp_array0[] = {1,0,0,0,0,0};
    assert(!memcmp(exp_array0, act_array0, exp_len0 * sizeof(int)
            && (act_len0 == exp_len0)));

    int array1[] = {9,9,8,9,9};
    int len1 = sizeof(array1)/sizeof(int);
    int act_len1;
    int* act_array1 = plusOne(array1, len1, &act_len1);
    int exp_len1 = len1;
    int exp_array1[] = {9,9,9,0,0};
    assert(!memcmp(exp_array1, act_array1, exp_len1 * sizeof(int)
            && (act_len1 == exp_len1)));

    int array2[] = {2,2,8,9,8};
    int len2 = sizeof(array2)/sizeof(int);
    int act_len2;
    int* act_array2 = plusOne(array2, len2, &act_len2);
    int exp_len2 = len2;
    int exp_array2[] = {2,2,8,9,9};
    assert(!memcmp(exp_array2, act_array2, exp_len2 * sizeof(int)
            && (act_len2 == exp_len2)));

    return(0);
}
