/*
 * This program finds the number of zeros in an array that contains only
 * zeros and ones. The array is such that all the ones occur before all
 * the zeros in the array
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */

#include<stdio.h>
#include<string.h>
#include<assert.h>

/*
 * This funcion finds the number of zeros in linear time that is O(n).
 * It starts from the end of the array and counts the number of zeros
 * until it encounters a one in the array.
 */
int find_number_of_zeros_in_array_of_ones_and_zeros_v1 (int* array,
                                                        int len)
{
    int i, num;

    /*
     * If the array pointer is NULL or if the lenght o array
     * is less than zero, then return 0.
     */
    if (!array || (len <= 0)) {
        return(0);
    }

    /*
     * Count number of zeros from back of the array. And
     * count until you encounter a one in the array.
     */
    num = 0;
    for (i = len-1; ((i >= 0) && (array[i] != 1)); --i) {
        if (array[i] == 0)
            ++num;
    }

    return(num);
}

/*
 * This function finds the number of zeros in O(log(n)). Since in the array
 * zeros lies after ones, so we check the middle element in the array and do
 * the following:-
 * 1. If the middle element is a zero, then we check the element to the left
 *    and if the left element is one then we have found the number of zeros
 *    in the array.
 */
int find_number_of_zeros_in_array_of_ones_and_zeros_v2 (int* array,
                                                        int len)
{
    int i, num, low, high, mid;

    /*
     * If the array pointer is NULL or if the lenght o array
     * is less than zero, then return 0.
     */
    if (!array || (len <= 0)) {
        return(0);
    }

    num = 0;
    low = 0;
    high = len - 1;
    while (low <= high) {

        mid = (low + high)/2;

        if (array[mid] == 1) {
            if (mid == (len - 1)) {
                return(0);
            } else {
                if (array[mid + 1] == 1) {
                    low = mid + 1;
                } else {
                    return(len - mid - 1);
                }
            }
        } else {
            if (mid == 0) {
                return(len);
            } else {
                if (array[mid - 1] == 0) {
                    high = mid - 1;
                } else {
                    return(len - mid);
                }
            }
        }
    }

    mid = (low + high)/2;

    return(len - mid);
}

int main()
{
    int array11[] = {1,1,1,1,1,0,0,0,0,0};
    assert(5 == find_number_of_zeros_in_array_of_ones_and_zeros_v1(
                                                        array11, 10));

    int array12[] = {0,0,0,0,0,0,0,0,0,0};
    assert(10 == find_number_of_zeros_in_array_of_ones_and_zeros_v1(
                                                        array12, 10));


    int array13[] = {1,1,1,1,1,1,1,1,1,1};
    assert(0 == find_number_of_zeros_in_array_of_ones_and_zeros_v1(
                                                        array13, 10));


    int array14[] = {1,0,0,0,0,0,0,0,0,0};
    assert(9 == find_number_of_zeros_in_array_of_ones_and_zeros_v1(
                                                        array14, 10));


    int array15[] = {1,1,1,1,1,1,1,1,1,0};
    assert(1 == find_number_of_zeros_in_array_of_ones_and_zeros_v1(
                                                        array15, 10));


    int array21[] = {1,1,1,1,1,0,0,0,0,0};
    assert(5 == find_number_of_zeros_in_array_of_ones_and_zeros_v2(
                                                        array21, 10));

    int array22[] = {0,0,0,0,0,0,0,0,0,0};
    assert(10 == find_number_of_zeros_in_array_of_ones_and_zeros_v2(
                                                        array22, 10));


    int array23[] = {1,1,1,1,1,1,1,1,1,1};
    assert(0 == find_number_of_zeros_in_array_of_ones_and_zeros_v2(
                                                        array23, 10));


    int array24[] = {1,0,0,0,0,0,0,0,0,0};
    assert(9 == find_number_of_zeros_in_array_of_ones_and_zeros_v2(
                                                        array24, 10));


    int array25[] = {1,1,1,1,1,1,1,1,1,0};
    assert(1 == find_number_of_zeros_in_array_of_ones_and_zeros_v2(
                                                        array25, 10));

    return(0);
}



