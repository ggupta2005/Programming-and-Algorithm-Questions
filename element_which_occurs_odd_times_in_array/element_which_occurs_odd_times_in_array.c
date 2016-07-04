/*
 * This program finds the element which occurs odd times in an array. All 
 * other numbers occur even times in the array
 */
#include<stdio.h>
#include<assert.h>

/*
 * This function finds the element which occurs odd times in a array based 
 * on the logic that XOR operation of an element with itself results in 
 * zero and xor of a number with zero gives us the number itself. So if we
 * XOR all the numbers in the array together, then we will get the number
 * which occurs odd number of times in the array. The time complexity of 
 * this function is O(n). 
 */
int element_odd_times (int *array, int len)
{    
    int result = 0; /* Set result to zero */
    int i;
   
    /*
     * Take the XOR of all array elements in 'result'.
     */ 
    for (i = 0; i < len; ++i) {
        result ^= array[i];
    }

    /*
     * Return the result
     */
    return result;
}

int main()
{
    /*
     * Test 1: Test with one occurrence of the odd occurring number
     */
    int array1[] = {12,3,4,4,3,1,1};
    /* 
     * only to be used with array declaration 
     * and not with pointer declaration
     */
    int len1 = sizeof(array1)/sizeof(*array1);
    assert(12 == element_odd_times(array1, len1));

    /*
     * Test 2: Test with more than one occurrence of the odd 
     *         occurring number
     */
    int array2[] = {12,12,12,3,4,4,3,1,1};
    int len2 = sizeof(array2)/sizeof(*array2);
    assert(12 == element_odd_times(array2, len2));

    /*
     * Test 3: Test with more than one occurrence of the odd 
     *         occurring number in an array of negative numbers
     */
    int array3[] = {-12,-12,-12,-3,-4,-4,-3,-1,-1};
    int len3 = sizeof(array3)/sizeof(*array3);
    assert(-12 == element_odd_times(array3, len3));

    /*
     * Test 4: Test with only one number in the array
     */
    int array4[] = {12};
    int len4 = sizeof(array4)/sizeof(*array4);
    assert(12 == element_odd_times(array4, len4));

    return 0;
}
