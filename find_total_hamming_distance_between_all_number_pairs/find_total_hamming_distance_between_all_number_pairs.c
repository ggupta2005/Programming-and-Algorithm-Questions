/*
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different. Now your job is to find the
 * total Hamming distance between all pairs of the given numbers.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<limits.h>

int get_hamming_distance (int x, int y)
{
    int hamming_distance, xor, index;

    xor = x ^ y;

    hamming_distance = 0;
    for (index = 0; index < (sizeof(int) * CHAR_BIT); ++index) {
        if (xor & (1 << index)) {
            ++hamming_distance;
        }
    }

    return(hamming_distance);
}

int get_total_hamming_distance_for_all_number_pairs_v1 (int* array, int len)
{
    int index, inner_index, total_hamming_distance;

    if (!array || (len <= 1)) {
        return(0);
    }

    total_hamming_distance = 0;
    for (index = 0; index < (len - 1); ++index) {
        for (inner_index = index + 1; inner_index < len; ++inner_index) {

            total_hamming_distance +=
                    get_hamming_distance(array[index], array[inner_index]);
        }
    }

    return(total_hamming_distance);
}

int get_total_hamming_distance_for_all_number_pairs_v2 (int* array, int len)
{
    int index, bit_index, double_total_hamming_distance;
    int* number_of_bit_set;
    int* number_of_bit_unset;

    if (!array || (len <= 1)) {
        return(0);
    }

    number_of_bit_set = (int*)malloc(sizeof(int) * (sizeof(int) * CHAR_BIT));
    number_of_bit_unset = (int*)malloc(sizeof(int) * (sizeof(int) * CHAR_BIT));

    if (!number_of_bit_unset || !number_of_bit_set) {
        free(number_of_bit_set);
        free(number_of_bit_unset);
        return(0);
    }

    memset(number_of_bit_set, 0, sizeof(int) * (sizeof(int) * CHAR_BIT));
    memset(number_of_bit_unset, 0, sizeof(int) * (sizeof(int) * CHAR_BIT));

    for (index = 0; index < len; ++index) {

        for (bit_index = 0; bit_index < sizeof(int) * CHAR_BIT; ++bit_index) {
            if (array[index] & (1 << bit_index)) {
                ++number_of_bit_set[bit_index];
            } else {
                ++number_of_bit_unset[bit_index];
            }
        }
    }

    double_total_hamming_distance = 0;
    for (index = 0; index < len; ++index) {
        for (bit_index = 0; bit_index < sizeof(int) * CHAR_BIT; ++bit_index) {
            if (array[index] & (1 << bit_index)) {
                double_total_hamming_distance += number_of_bit_unset[bit_index];
            } else {
                double_total_hamming_distance += number_of_bit_set[bit_index];
            }
        }
    }

    free(number_of_bit_set);
    free(number_of_bit_unset);

    return(double_total_hamming_distance/2);
}

int main ()
{
    int* array0 = NULL;
    int len0 = 10;
    assert(0 == get_total_hamming_distance_for_all_number_pairs_v1(array0, len0));
    assert(0 == get_total_hamming_distance_for_all_number_pairs_v2(array0, len0));

    int array1[] = {1,2,3};
    int len1 = 1;
    assert(0 == get_total_hamming_distance_for_all_number_pairs_v1(array1, len1));
    assert(0 == get_total_hamming_distance_for_all_number_pairs_v2(array1, len1));

    int array2[] = {4,2,14};
    int len2 = sizeof(array2)/sizeof(int);
    assert(6 == get_total_hamming_distance_for_all_number_pairs_v1(array2, len2));
    assert(6 == get_total_hamming_distance_for_all_number_pairs_v2(array2, len2));

    int array3[] = {14,14,14};
    int len3 = sizeof(array3)/sizeof(int);
    assert(0 == get_total_hamming_distance_for_all_number_pairs_v1(array3, len3));
    assert(0 == get_total_hamming_distance_for_all_number_pairs_v2(array3, len3));

    return(0);
}
