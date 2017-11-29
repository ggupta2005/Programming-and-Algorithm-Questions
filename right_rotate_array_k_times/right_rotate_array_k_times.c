/*
 * This program right rotates an array 'k' times.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void right_rotate_array_k_times_v1 (int* array, int len, int k)
{
    int index, j, prev, temp;

    if (!array || (len <= 0) || (k <= 0)) {
        return;
    }

    k = k % len;

    if (!k) {
        return;
    }

    j = 0;
    while (j < k) {
        prev = array[len - 1];
        for (index = 0; index < len; ++index) {
            temp = array[index];
            array[index] = prev;
            prev = temp;
        }

        ++j;
    }
}

void right_rotate_array_k_times_v2 (int* array, int len, int k)
{
    int index, index_k, j, prev, temp;
    int* copy;

    if (!array || (len <= 0) || (k <= 0)) {
        return;
    }

    k = k % len;

    if (!k) {
        return;
    }

    copy = (int*)malloc(sizeof(int) * len);

    if (!copy) {
        return;
    }

    for (index = 0; index < len; ++index) {
        index_k = index + k;

        if (index_k >= len) {
            index_k -= len;
        }

        copy[index_k] = array[index];
    }

    for (index = 0; index < len; ++index) {
        array[index] = copy[index];
    }

    free(copy);
}

void right_rotate_array_k_times_v3 (int* array, int len, int k)
{
    int index, index_k, j, prev, temp;
    int* copy;

    if (!array || (len <= 0) || (k <= 0)) {
        return;
    }

    k = k % len;

    if (!k) {
        return;
    }

    if ((len % k) != 0) {

        j = 0;
        index = 0;
        prev = array[index];
        while (j < len) {
            index_k = index + k;

            if (index_k >= len) {
                index_k -= len;
            }

            temp = array[index_k];
            array[index_k] = prev;
            prev = temp;

            index = index_k;
            ++j;
        }

    } else {

        for (j = 0; j < k; ++j) {

            index = j;
            prev = array[index];

            do {
                index_k = index + k;

                if (index_k >= len) {
                    index_k -= len;
                }

                temp = array[index_k];
                array[index_k] = prev;
                prev = temp;

                index = index_k;

            } while (index != j);
        }
    }
}

void reverse_array_section (int* array, int low, int high)
{
    int temp;

    if (!array || (low < 0) || (high < 0) || (low > high)) {
        return;
    }

    while (low <= high) {
        temp = array[low];
        array[low] = array[high];
        array[high] = temp;

        ++low;
        --high;
    }
}

void right_rotate_array_k_times_v4 (int* array, int len, int k)
{
    int index, index_k, j, prev, temp;
    int* copy;

    if (!array || (len <= 0) || (k <= 0)) {
        return;
    }

    k = k % len;

    if (!k) {
        return;
    }

    reverse_array_section(array, 0, len - 1);
    reverse_array_section(array, 0, k - 1);
    reverse_array_section(array, k, len - 1);
}

int main ()
{
    int array0[] = {1,2,3,4,5,6,7,8};
    int len0 = sizeof(array0)/sizeof(int);
    int k0 = 3;
    int expected0[] = {6,7,8,1,2,3,4,5};
    right_rotate_array_k_times_v4(array0, len0, k0);
    assert(0 == memcmp(array0, expected0, sizeof(array0)));

    return(0);
}
