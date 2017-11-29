/*
 * This program finds the maximum possible sum without choosing consecutive
 * elements in an array. For example for the array {10, 12, 5}, the maximum
 * possible sum without choosing any consecutve elements is 15 (10 + 5) while
 * for the array {12, 100, 70} the maximum possible sum without choosing any
 * consecutve elements is 100.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int get_max_sum_without_consecutive_elements_v1 (
                                    int* array, int low, int high)
{
    int index, max, temp_max;

    if (!array || (low < 0) || (high < 0) || (low > high)) {
        return(0);
    }

    if (low == high) {
        return(array[low]);
    }

    max = get_max_sum_without_consecutive_elements_v1(array, low, high - 1);

    if ((high - 2) >= 0) {
        for (index = high - 2; index >= 0; --index) {
            temp_max = array[high] +
                get_max_sum_without_consecutive_elements_v1(array, low, index);

            if (temp_max > max) {
                max = temp_max;
            }
        }
    } else {
        temp_max = array[high];

        if (temp_max > max) {
            max = temp_max;
        }
    }

    return(max);
}

int get_max_sum_without_consecutive_elements_v2 (
                                    int* array, int low, int high)
{
    int index, inner_index, max, temp_max;
    int* max_array;


    if (!array || (low < 0) || (high < 0) || (low > high)) {
        return(0);
    }

    if (low == high) {
        return(array[low]);
    }

    max_array = (int*)malloc(sizeof(int) * (high - low + 1));

    if (!max_array) {
        return(0);
    }

    memset(max_array, 0, sizeof(int) * (high - low + 1));

    max_array[0] = array[0];
    for (index = 1; index <= high; ++index) {

        max = max_array[index - 1];

        if ((index - 2) >= 0) {
            for (inner_index = index - 2; inner_index >= 0;
                 --inner_index) {

                temp_max = array[index] +
                             max_array[inner_index];

                if (temp_max > max) {
                    max = temp_max;
                }
            }
        } else {

            temp_max = array[index];

            if (temp_max > max) {
                max = temp_max;
            }
        }

        max_array[index] = max;
    }

    max = max_array[high];

    free(max_array);

    return(max);
}

int main ()
{
    int array0[] = {10, 12, 5};
    int low0 = 0;
    int high0 = sizeof(array0)/sizeof(int) - 1;
    int max_sum0 = 15;
    assert(max_sum0 ==
           get_max_sum_without_consecutive_elements_v1(array0, low0, high0));
    assert(max_sum0 ==
           get_max_sum_without_consecutive_elements_v2(array0, low0, high0));

    int array1[] = {12, 100, 70};
    int low1 = 0;
    int high1 = sizeof(array1)/sizeof(int) - 1;
    int max_sum1 = 100;
    assert(max_sum1 ==
           get_max_sum_without_consecutive_elements_v1(array1, low1, high1));
    assert(max_sum1 ==
           get_max_sum_without_consecutive_elements_v2(array1, low1, high1));

    return(0);
}
