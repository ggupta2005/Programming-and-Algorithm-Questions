/*
 * This program generates the power set for the numbers given in an
 * array of numbers. For more information on the problem, please visit
 * the following link:-
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

struct array_ptr_with_length {
    int* array;
    int len;
};

int get_num_bits_set (unsigned long num)
{
    int bits_set, bit_index, one = 1;

    bits_set = 0;
    for (bit_index = 0;
         bit_index < (sizeof(unsigned long) * CHAR_BIT);
         ++bit_index) {

        if (num & (one << bit_index)) {
            ++bits_set;
        }
    }

    return(bits_set);
}

struct array_ptr_with_length* generate_power_set_for_array
                                          (int* array, int len,
                                           unsigned long* power_set_size)
{
    struct array_ptr_with_length* power_set;
    unsigned long index, inner_index, one = 1;
    int num_bits_set, array_index, set_index;

    if (!power_set_size) {
        return(NULL);
    }

    if (!array || (len <= 0) || (len > sizeof(unsigned long) * CHAR_BIT)) {
        *power_set_size = 0;
        return(NULL);
    }

    *power_set_size = 1 << len;

    power_set = (struct array_ptr_with_length*)malloc(
                    sizeof(struct array_ptr_with_length) * (*power_set_size));

    if (!power_set) {
        return(NULL);
    }

    memset(power_set, 0,
            sizeof(struct array_ptr_with_length) * (*power_set_size));

    for (index = 0; index < *power_set_size; ++index) {

        num_bits_set = get_num_bits_set(index);

        if (num_bits_set == 0) {
            continue;
        }

        power_set[index].len = num_bits_set;
        power_set[index].array = (int*)malloc(sizeof(int) * num_bits_set);

        if (!power_set[index].array) {
            for (inner_index = 0; inner_index < index; ++inner_index) {
                free(power_set[inner_index].array);
            }

            free(power_set);
            *power_set_size = 0;
            return(NULL);
        }

        set_index = 0;
        for (array_index = 0; array_index < len; ++array_index) {
            if (index & (one << array_index)) {
                power_set[index].array[set_index] = array[array_index];
                ++set_index;
            }
        }
    }

    return(power_set);
}

bool compare_if_power_sets_are_equal (
                struct array_ptr_with_length* power_set1,
                unsigned long power_set_size1,
                struct array_ptr_with_length* power_set2,
                unsigned long power_set_size2)
{
    unsigned long index1, index2;
    bool if_set_match_found, if_match_found = false;
    int array_index1, array_index2;

    if (!power_set1 || !power_set2 ||
        (power_set_size1 != power_set_size2)) {
        return(false);
    }

    for (index1 = 0; index1 < power_set_size1; ++index1) {

        if_set_match_found = false;
        for (index2 = 0; index2 < power_set_size2; ++index2) {
            if (power_set1[index1].len == power_set2[index2].len) {
                if ((power_set1[index1].array == NULL) &&
                    (power_set2[index2].array == NULL)) {

                    if_set_match_found = true;
                    break;

                } else if ((power_set1[index1].array != NULL) &&
                           (power_set2[index2].array != NULL)) {

                    for (array_index1 = 0;
                         array_index1 < power_set1[index1].len;
                         ++array_index1) {

                        if_match_found = false;
                        for (array_index2 = 0;
                             array_index2 < power_set2[index2].len;
                             ++array_index2) {

                            if (power_set2[index2].array[array_index2] ==
                                power_set1[index1].array[array_index1]) {
                                if_match_found = true;
                                break;
                            }
                        }

                        if (!if_match_found) {
                            break;
                        }
                    }

                    if (if_match_found) {
                        if_set_match_found = true;
                        break;
                    }
                }
            }
        }

        if (!if_set_match_found) {
            break;
        }
    }

    return(if_set_match_found);
}

int main ()
{
    /*
     *
     */
    struct array_ptr_with_length* exp_power_set0 = NULL;
    unsigned long exp_power_set_len0 = 0;
    struct array_ptr_with_length* act_power_set0;
    unsigned long act_power_set_len0;
    int* array0 = NULL;
    int len0 = 10;
    act_power_set0 = generate_power_set_for_array(
                                            array0, len0,
                                            &act_power_set_len0);
    assert((exp_power_set0 == act_power_set0) &&
            (exp_power_set_len0 == act_power_set_len0));

    struct array_ptr_with_length* exp_power_set1 = NULL;
    unsigned long exp_power_set_len1 = 0;
    struct array_ptr_with_length* act_power_set1;
    unsigned long act_power_set_len1;
    int array1[] = {0,1,2};
    int len1 = -11;
    act_power_set1 = generate_power_set_for_array(
                                            array1, len1,
                                            &act_power_set_len1);
    assert((exp_power_set1 == act_power_set1) &&
            (exp_power_set_len1 == act_power_set_len1));

    struct array_ptr_with_length* exp_power_set2 = NULL;
    unsigned long exp_power_set_len2 = 0;
    struct array_ptr_with_length* act_power_set2;
    unsigned long act_power_set_len2;
    int array2[] = {0,2,2};
    int len2 = sizeof(unsigned long) * CHAR_BIT + 1;
    act_power_set2 = generate_power_set_for_array(
                                            array2, len2,
                                            &act_power_set_len2);
    assert((exp_power_set2 == act_power_set2) &&
            (exp_power_set_len2 == act_power_set_len2));

    struct array_ptr_with_length* exp_power_set3 = NULL;
    unsigned long exp_power_set_len3 = 0;
    struct array_ptr_with_length* act_power_set3;
    unsigned long act_power_set_len3;
    int* array3 = NULL;
    int len3 = 0;
    act_power_set3 = generate_power_set_for_array(
                                            array3, len3,
                                            &act_power_set_len3);
    assert((exp_power_set3 == act_power_set3) &&
            (exp_power_set_len3 == act_power_set_len3));

    int array4[] = {1};
    int len4 = sizeof(array4)/sizeof(int);
    unsigned long exp_power_set_len4 = (unsigned long)1 << len4;
    struct array_ptr_with_length* exp_power_set4 = NULL;
    exp_power_set4 =
      (struct array_ptr_with_length*)malloc(
            sizeof(struct array_ptr_with_length) * exp_power_set_len4);
    exp_power_set4[0].len = 0;
    exp_power_set4[0].array = NULL;
    exp_power_set4[1].len = 1;
    exp_power_set4[1].array = array4;
    struct array_ptr_with_length* act_power_set4;
    unsigned long act_power_set_len4;
    act_power_set4 = generate_power_set_for_array(
                                            array4, len4,
                                            &act_power_set_len4);
    assert(
        compare_if_power_sets_are_equal(
                exp_power_set4, exp_power_set_len4,
                act_power_set4, act_power_set_len4));

    return(0);
}
