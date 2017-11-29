/*
 * This program sorts an array containing only zeros, ones and twos.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>

/*
 * This function sorts an array containing only zeros, ones and twos
 * in O(n) time. But this function requires two passes of the array.
 * The first pass counts the number of zeros, ones and twos in the
 * array. In the second pass, we over-write the array with zeros first,
 * then ones and finally twos.
 */
void sort_array_of_zeros_ones_and_twos_ver1 (int *array, int len)
{
    int ones = 0;
    int zeros = 0;
    int twos = 0;
    int i = 0;

    if (!array || (len <= 0)) {
        return;
    }

    /*
     * Count the number of 1s, 0s and 2s in the array
     */
    for (i = 0; i < len; ++i) {
        if (array[i] == 0) {
            zeros++;
        }

        if (array[i] == 1) {
            ones++;
        }

        if (array[i] == 2) {
            twos++;
        }
    }

    /*
     * Put 0s in the first zeros elements in the array
     */
    for (i = 0; i < zeros; ++i) {
        array[i] = 0;
    }

    /*
     * For the next ones elements put 1 in the array
     */
    for (i = 0; i < ones; ++i) {
        array[i + zeros] = 1;
    }

    /*
     * For the next twos elements put 2 in the array
     */
    for (i = 0; i < twos; ++i) {
        array[i + zeros + ones] = 2;
    }
}

/*
 * This function sorts an array containing only zeros, ones and twos
 * in O(n) time. This function uses the the dutch national flag
 * algorithm to sort the array in one pass.
 */
void sort_array_of_zeros_ones_and_twos_ver2 (int *array, int len)
{
    int low, high, mid, temp;

    if (!array || (len <= 0)) {
        return;
    }

    low = mid = 0;
    high = len - 1;

    while (mid <= high) {

        if (array[mid] == 2) {
            temp = array[mid];
            array[mid] = array[high];
            array[high] = temp;
            --high;
        } else if (array[mid] == 1) {
            ++mid;
        } else {
            temp = array[low];
            array[low] = array[mid];
            array[mid] = temp;
            ++low;
            ++mid;
        }
    }
}

int main()
{
    /*
     * Unit test cases for the first approach
     */
    int array_test_ver1_1[] = {2,2,2,2,1,1,1,1,0,0,0,0,0,0};
    int array_expect_ver1_1[] = {0,0,0,0,0,0,1,1,1,1,2,2,2,2};
    sort_array_of_zeros_ones_and_twos_ver1(
                    array_test_ver1_1,
                    sizeof(array_test_ver1_1)/sizeof(int));
    assert(memcmp(array_test_ver1_1, array_expect_ver1_1,
                  sizeof(array_test_ver1_1)) == 0);

    /*
     * Unit test cases for the second approach
     */
    int array_test_ver2_1[] = {2,2,2,2,1,1,1,1,0,0,0,0,0,0};
    int array_expect_ver2_1[] = {0,0,0,0,0,0,1,1,1,1,2,2,2,2};
    sort_array_of_zeros_ones_and_twos_ver2(
                    array_test_ver2_1,
                    sizeof(array_test_ver2_1)/sizeof(int));
    assert(memcmp(array_test_ver2_1, array_expect_ver2_1,
                  sizeof(array_test_ver2_1)) == 0);

    return(0);
}
