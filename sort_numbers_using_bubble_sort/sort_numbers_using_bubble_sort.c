/*
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

//srand(time(NULL));

void bubble_sort (int* array, int len)
{
    int i, j, temp;

    if (!array || (len <= 0)) {
        return;
    }

    for (i = 0; i < (len - 1); ++i) {
        for (j = 0; j < (len - 1 - i) ; ++j) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

bool check_if_not_sorted (int* array, int len)
{
    int i, j, temp;

    if (!array || (len <= 0)) {
        return(false);
    }

    for (i = 0; i < (len - 1); ++i) {
        if (array[i+1] < array[i]) {
           return(false);
        }
    }

    return(true);
}

int main ()
{
    int array0[] = {5,6,7,8,1,2,3,4};
    int len0 = sizeof(array0)/sizeof(int);
    bubble_sort(array0, len0);
    assert(check_if_not_sorted(array0, len0));

    int array1[100];
    int len1 = sizeof(array1)/sizeof(int);
    bubble_sort(array1, len1);
    assert(check_if_not_sorted(array1, len1));

    return(0);
}
