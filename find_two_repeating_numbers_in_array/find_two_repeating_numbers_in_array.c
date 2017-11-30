/*
 * You are given an array of n+2 elements. All elements of the array
 * are in range 1 to n. And all elements occur once except two numbers
 * which occur twice. Find the two repeating numbers. For example,
 * array = {4, 2, 4, 5, 2, 3, 1} and n = 5. The above array has n + 2 = 7
 * elements with all elements occurring once except 2 and 4 which occur twice.
 * So the output should be 4 2. For more information on this problem, please
 * refer to the following link:-
 * http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>

void find_two_repeating_numbers_in_array (int* array, int len, int num,
                                          int *num1, int *num2)
{
    int sum_array, diff, sum_len;
    int index, left, right;

    if (!array || (len <= 0) || (num <= 0) || !num1 || !num2) {
        return;
    }

    if ((len - num) != 2) {
        return;
    }

    sum_array = 0;
    for (index = 0; index < len; ++index) {
        sum_array += array[index];
    }

    sum_len = 0;
    for (index = 1; index <= num; ++index) {
        sum_len += index;
    }

    diff = sum_array - sum_len;

    left = 1;
    right = num;
    while (left < right) {
        if ((left + right) == diff) {
            *num1 = left;
            *num2 = right;
            break;
        } else if ((left + right) < diff) {
            ++left;
        } else {
            --right;
        }
    }
}

int main ()
{
    int array0[] = {4, 2, 4, 5, 2, 3, 1};
    int len0 = sizeof(array0)/sizeof(int);
    int num0 = 5;
    int exp_num01 = 2, exp_num02 = 4;
    int act_num01, act_num02;
    find_two_repeating_numbers_in_array(array0, len0, num0,
                                        &act_num01, &act_num02);
    printf("num1 = %d, num2 = %d\n", act_num01, act_num02);
    assert((exp_num01 == act_num01) && (exp_num02 == act_num02));

    int array1[] = {2, 1, 2, 1};
    int len1 = sizeof(array1)/sizeof(int);
    int num1 = 2;
    int exp_num11 = 1, exp_num12 = 2;
    int act_num11, act_num12;
    find_two_repeating_numbers_in_array(array1, len1, num1,
                                        &act_num11, &act_num12);
    assert((exp_num11 == act_num11) && (exp_num12 == act_num12));

    return(0);
}
