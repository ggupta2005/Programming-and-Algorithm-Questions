/*
 * This program moves all the zeros to the end of the array without
 * changing the relative order of other elements in the array. For
 * example, if the array is {0, 9, 1, 2, 3, 0}, then after moving all
 * the zeros to the end the array will look like {9, 1, 2. 3. 0. 0}.
 * For more information on the problem, please refer to the following
 * link:- http://www.geeksforgeeks.org/move-zeroes-end-array/
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<string.h>

void move_all_zeros_to_end_without_changing_order (int* array, int len)
{
    int zero_index, non_zero_index;
    int temp;

    if (!array || (len <= 0)) {
        return;
    }

    zero_index = 0;
    non_zero_index = 0;
    while ((zero_index < len) && (non_zero_index < len)) {

        while ((zero_index < len) && array[zero_index]) {
            ++zero_index;
        }

        while ((non_zero_index < len) && !array[non_zero_index]) {
            ++non_zero_index;
        }

        if ((zero_index < len) && (non_zero_index < len)) {
            if (non_zero_index > zero_index) {
                temp = array[zero_index];
                array[zero_index] = array[non_zero_index];
                array[non_zero_index] = temp;
            } else {
                ++non_zero_index;
            }
        }
    }
}

int main ()
{
    int array0[] = {0, 9, 1, 2, 3, 0};
    int len0 = sizeof(array0)/sizeof(int);
    int exp_array0[] = {9, 1, 2, 3, 0, 0};
    move_all_zeros_to_end_without_changing_order(array0, len0);
    assert(0 == memcmp(array0, exp_array0, sizeof(array0)));

    int array1[] = {8, 9, 1, 2, 3, 9};
    int len1 = sizeof(array1)/sizeof(int);
    int exp_array1[] = {8, 9, 1, 2, 3, 9};
    move_all_zeros_to_end_without_changing_order(array1, len1);
    assert(0 == memcmp(array1, exp_array1, sizeof(array1)));

    int array2[] = {0, 0, 0, 0, 0, 0};
    int len2 = sizeof(array2)/sizeof(int);
    int exp_array2[] = {0, 0, 0, 0, 0, 0};
    move_all_zeros_to_end_without_changing_order(array2, len2);
    assert(0 == memcmp(array2, exp_array2, sizeof(array2)));

    int array3[] = {8, 9, 1, 2, 3, 0, 1, 2, 3};
    int len3 = sizeof(array3)/sizeof(int);
    int exp_array3[] = {8, 9, 1, 2, 3, 1, 2, 3, 0};
    move_all_zeros_to_end_without_changing_order(array3, len3);
    assert(0 == memcmp(array3, exp_array3, sizeof(array3)));

    int array4[] = {8, 9, 1, 2, 3, 1, 2, 3, 0};
    int len4 = sizeof(array4)/sizeof(int);
    int exp_array4[] = {8, 9, 1, 2, 3, 1, 2, 3, 0};
    move_all_zeros_to_end_without_changing_order(array4, len4);
    assert(0 == memcmp(array4, exp_array4, sizeof(array4)));

    int array5[] = {0, 0, 8, 9, 1, 2, 3, 1, 2, 3};
    int len5 = sizeof(array5)/sizeof(int);
    int exp_array5[] = {8, 9, 1, 2, 3, 1, 2, 3, 0, 0};
    move_all_zeros_to_end_without_changing_order(array5, len5);
    assert(0 == memcmp(array5, exp_array5, sizeof(array5)));

    return(0);
}
