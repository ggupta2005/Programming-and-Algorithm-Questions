/*
 * This program finds the maximum possible profit that can be obtained by
 * cutting a rod into smaller pieces. The selling price of the smaller
 * pieces is given in an array. The index of the array provides the length
 * of the pieces in which the rod can be cut into. For more information on
 * the problem, please refer to the following link:-
 * http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

int find_max_profit_by_cutting_a_rod_v1 (int* array, int array_len,
                                         int rod_length)
{
    int max_profit, temp_profit, len;

    if (!array || (array_len <= 0) || (rod_length <= 0)) {
        return(0);
    }

    max_profit = 0;
    for (len = 1; len < array_len; ++len) {
        if ((rod_length - len) >= 0) {
            temp_profit = array[len] +
                find_max_profit_by_cutting_a_rod_v1(array, array_len,
                                                    rod_length - len);

            if (temp_profit > max_profit) {
                max_profit = temp_profit;
            }
        }
    }

    return(max_profit);
}

int find_max_profit_by_cutting_a_rod_v2 (int* array, int array_len,
                                         int rod_length)
{
    int* max_profit;
    int temp_profit, max_piece_profit, len, piece_len;

    if (!array || (array_len <= 0) || (rod_length <= 0)) {
        return(0);
    }

    max_profit = (int*)malloc(sizeof(int) * (rod_length + 1));

    memset(max_profit, 0, sizeof(int) * (rod_length + 1));

    for (len = 1; len <= rod_length; ++len) {

        max_piece_profit = 0;
        for (piece_len = 1; piece_len < array_len; ++piece_len) {

            if ((len - piece_len) >= 0) {
                temp_profit =
                    array[piece_len] + max_profit[len - piece_len];
            }

            if (temp_profit > max_piece_profit) {
                max_piece_profit = temp_profit;
            }
        }

        max_profit[len] = max_piece_profit;
    }

    max_piece_profit = max_profit[rod_length];

    free(max_profit);

    return(max_piece_profit);
}

int main ()
{
    int array2[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int len2 = sizeof(array2)/sizeof(int);
    int rod_length2 = 8;
    int max_profit2 = 22;
    assert(max_profit2 == find_max_profit_by_cutting_a_rod_v1(array2, len2, rod_length2));
    assert(max_profit2 == find_max_profit_by_cutting_a_rod_v2(array2, len2, rod_length2));

    int array3[] = {0, 3, 5, 8, 9, 10, 17, 17, 20};
    int len3 = sizeof(array3)/sizeof(int);
    int rod_length3 = 8;
    int max_profit3 = 24;
    assert(max_profit3 == find_max_profit_by_cutting_a_rod_v1(array3, len3, rod_length3));
    assert(max_profit3 == find_max_profit_by_cutting_a_rod_v2(array3, len3, rod_length3));

    return(0);
}
