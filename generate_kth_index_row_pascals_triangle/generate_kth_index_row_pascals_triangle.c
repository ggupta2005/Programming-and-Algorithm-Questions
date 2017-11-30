/*
 * This program generates the kth index row of a Pascal's Triangle.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

/*
 * This function generates the kth index row for the Pascal's Triangle and
 * sets the number of elements in the kth row in the reference variable
 * 'num_elements'. If the input 'row_index' is not valid, then this
 * function returns NULL. The time complexity of this function is O(n^2),
 * where 'n' is the number of rows in the Pascal's Triangle. The space
 * complexity of this function is O(n), where 'n' is the number of rows
 * in the Pascal's Triangle.
 */
int* get_kth_index_row_pascals_triangle (int row_index, int* num_elements)
{
    int* kth_index_row;
    int* kth_index_row_copy;
    int index, inner_index;

    /*
     * If the reference to the number of elements in the kth row is
     * not valid, then return NULL
     */
    if (!num_elements) {
        return(NULL);
    }

    /*
     * If the row index is not valid, then return NULL
     */
    if (row_index < 0) {
        *num_elements = 0;
        return(NULL);
    }

    kth_index_row = (int*)malloc(sizeof(int) * (row_index + 1));
    kth_index_row_copy = (int*)malloc(sizeof(int) * (row_index + 1));

    if (!kth_index_row || !kth_index_row_copy) {
        free(kth_index_row_copy);
        free(kth_index_row);
        *num_elements = 0;
        return(NULL);
    }

    *num_elements = (row_index + 1);

    kth_index_row[0] = 1;
    for (index = 1; index <= row_index; ++index) {
        for (inner_index = 0; inner_index < (index + 1); ++inner_index) {
            if (inner_index == 0) {
                kth_index_row_copy[inner_index] = kth_index_row[inner_index];
            } else if (inner_index == index) {
                kth_index_row_copy[inner_index] = kth_index_row[inner_index - 1];
            } else {
                kth_index_row_copy[inner_index] = kth_index_row[inner_index - 1]
                                                        + kth_index_row[inner_index];
            }
        }

        memcpy(kth_index_row, kth_index_row_copy, (index + 1) * sizeof(int));
    }

    free(kth_index_row_copy);

    return(kth_index_row);
}

int main ()
{
    int act_len0;
    int* act0;
    int* exp0 = NULL;
    act0 = get_kth_index_row_pascals_triangle(-1, &act_len0);
    assert((act0 == exp0) && (act_len0 == 0));

    int act_len1;
    int* act1;
    int exp1[] = {1};
    act1 = get_kth_index_row_pascals_triangle(0, &act_len1);
    assert((act_len1 == 1) && !memcmp(act1, exp1, sizeof(int) * act_len1));

    int act_len2;
    int* act2;
    int exp2[] = {1, 1};
    act2 = get_kth_index_row_pascals_triangle(1, &act_len2);
    assert((act_len2 == 2) && !memcmp(act2, exp2, sizeof(int) * act_len2));

    int act_len3;
    int* act3;
    int exp3[] = {1, 2, 1};
    act3 = get_kth_index_row_pascals_triangle(2, &act_len3);
    assert((act_len3 == 3) && !memcmp(act3, exp3, sizeof(int) * act_len3));

    int act_len4;
    int* act4;
    int exp4[] = {1, 3, 3, 1};
    act4 = get_kth_index_row_pascals_triangle(3, &act_len4);
    assert((act_len4 == 4) && !memcmp(act4, exp4, sizeof(int) * act_len4));

    return(0);
}
