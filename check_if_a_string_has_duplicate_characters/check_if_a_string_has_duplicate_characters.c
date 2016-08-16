/*
 * This program checks if a string has duplicate characters.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

/*
 * Maximum number of characters possible in 'char' in
 * C-programming language
 */
#define NUM_POSSIBLE_CHARACTERS    (1 << (sizeof(char) * 8))

/*
 * This function partitions the array around a 'pivot' element
 * and returns the index of the pivot element. This functionu
 * uses the element at index 'high' as the pivot.
 */
int partition (char* ch, int low, int high)
{
    char temp, pivot;
    int i, pindex;

    /*
     * Set 'pivot' as the element at index 'high' in the array
     */
    pivot = ch[high];

    pindex = low;
    for (i = low; i < high; ++i) {

        /*
         * If the array elemnt is less than pivot element
         * then move the element to the left of the pivot
         */
        if (pivot > ch[i]) {
            temp = ch[i];
            ch[i] = ch[pindex];
            ch[pindex] = temp;
            ++pindex;
        }
    }

    /*
     * At this point all elements less than 'pivot' are present to
     * the left of 'pindex'. So swap and move the element at 'high'
     * to index 'pindex'
     */
    temp = ch[high];
    ch[high] = ch[pindex];
    ch[pindex] = temp;

    /*
     * Return the partition index to the quick sort routine
     */
    return(pindex);
}

/*
 * This function sorts a character array from indicies 'low' to
 * 'high' in ascending order using quick sort.
 */
void quicksort (char* ch, int low, int high)
{
    int partition_index;

    /*
     * If array is NULL or 'low' or 'high' are less than zero, then
     * there is no need to sory the array. So return.
     */
    if (!ch || (low < 0) || (high < 0)) {
        return;
    }

    /*
     * If 'low' is less than 'high', partition the array using
     * and recursively sory the parts around the partition index
     * using quick sort
     */
    if (low < high) {
        int partition_index = partition(ch, low, high);
        quicksort(ch, low, partition_index - 1);
        quicksort(ch, partition_index + 1, high);
    }
}

/*
 * This function checks if a characte string has duplicate characters. If the
 * character string has duplicate characters, then this function returns 'true'
 * otherwise this function returns false'. This function uses the following
 * approach to find if there are duplicate characters in a string:-
 * 1. Sort the string using quick sort.
 * 2. Compare the consecutive characters in the character array to find
 *    if they are equal. In case they are equal return 'true'.
 * 3. If we reach towards the end of the function, then return 'false' as
 *    here are no duplicate characters in the string.
 * The time complexity of this function is O(n*log(n)), where 'n' is the
 * number of characters in either string. The time complexity of the
 * function depends on the time taken by quick sort which could be O(n^2)
 * in worst case.
 * The space complexity of this function is O(1).
 */
bool check_if_a_str_has_duplicate_chars_v1 (char* ch)
{
    int len, i, j;

    /*
     * If the string is NULL or its length is zero, then return
     * 'false'
     */
    if (!ch || !strlen(ch)) {
        return(false);
    }

    len = strlen(ch);

    /*
     * Sort the characters of the string using quicksort
     */
    quicksort(ch, 0, len -1);

    /*
     * Iterate through the character array to find if any of the
     * consecutive characters are same. IF so, then return 'true'.
     */
    for (i = 0; i < (len - 1); ++i) {

        /*
         * If the consecutive characters are same, then return 'true'
         */
        if (ch[i] == ch[i+1]) {
            return(true);
        }
    }

    /*
     * Return 'false' if no duplicate characters are found
     */
    return(false);
}

/*
 * This function checks if a characte string has duplicate characters. If the
 * character string has duplicate characters, then this function returns 'true'
 * otherwise this function returns false'. This function uses the following
 * approach to find if there are duplicate characters in a string:-
 * 1. Iterate over the length of the string to see if there exists another
 *    another character which same as the character under test. If so,
 *    then return 'true'.
 * The time complexity of this function is O(n^2), where 'n' is the
 * number of characters in either string.
 * The space complexity of this function is O(1).
 */
bool check_if_a_str_has_duplicate_chars_v2 (char* ch)
{
    int len, i, j;

    /*
     * If the string is NULL or its length is zero, then return
     * 'false'
     */
    if (!ch || !strlen(ch)) {
        return(false);
    }

    len = strlen(ch);

    /*
     * For a given character in the array, check if there are any characters
     * on the right which are same as the current character.
     */
    for (i = 0; i < (len - 1); ++i) {
        for (j = i + 1; j < len; ++j) {

            /*
             * If the ith character is same as the jth character, then
             * return true, as a duplicate character exists
             */
            if (ch[i] == ch[j]) {
                return(true);
            }
        }
    }

    /*
     * Return 'false' if no duplicate characters are found
     */
    return(false);
}

/*
 * This function checks if a characte string has duplicate characters. If the
 * character string has duplicate characters, then this function returns 'true'
 * otherwise this function returns false'. This function uses the following
 * approach to find if there are duplicate characters in a string:-
 * 1. Define a count array to record the if a particular character has been
 *    found in the character array previously. Initialize this array to 0.
 * 2. Iterate over the character and map the characters into the cout array
 * 3. If the mapped character in the count array is zero, then increment the
 *    array entry by one otherwise we this mapped entry in the count array
 *    is a duplicate character. Return 'true', from this function.
 * 4. If we reach towards the end of the function, then return 'false' as
 *    here are no duplicate characters in the string.
 * The time complexity of this function is O(n), where 'n' is the
 * number of characters in either string sinze we iterate through the
 * character array once.
 * The space complexity of this function is O(m) where 'm' is the number
 * of characters suported by the programming language.
 */
bool check_if_a_str_has_duplicate_chars_v3 (char* ch)
{
    int len, i;
    int count[NUM_POSSIBLE_CHARACTERS];
    int mapped_char;

    /*
     * If the string is NULL or its length is zero, then return
     * 'false'
     */
    if (!ch || !strlen(ch)) {
        return(false);
    }

    len = strlen(ch);

    /*
     * Set all elements of the count array to be zero
     */
    memset(count, 0, sizeof(int) * NUM_POSSIBLE_CHARACTERS);

    /*
     * Iterate over the entire array and map the characters of the string
     * into the count array
     */
    for (i = 0; i < len; ++i) {

        /*
         * The mapped character is the addition of the ascii value of the
         * character and the helf of the maximum number of characters in the
         * programming language set.
         */
        mapped_char = ch[i] + NUM_POSSIBLE_CHARACTERS / 2;

        /*
         * If the value of the count array in the mapped character slot is
         * non-zero, then we have found a duplicate character. Return 'true'
         */
        if (count[mapped_char]) {
            return(true);
        } else {

            /*
             * Increment the count array for the mapped character
             */
            count[mapped_char]++;
        }
    }

    /*
     * Return 'false' if no duplicate characters are found
     */
    return(false);
}

int main ()
{
    /*
     * Test 0: Test with a NULL string. This should not be character array
     *         having duplicate characters
     */
    char* str0 = NULL;
    assert(false == check_if_a_str_has_duplicate_chars_v1(str0));
    assert(false == check_if_a_str_has_duplicate_chars_v2(str0));
    assert(false == check_if_a_str_has_duplicate_chars_v3(str0));

    /*
     * Test 1: Test with an empty string. This should not be character
     *         array having duplicate characters
     */
    char str1[] = "";
    assert(false == check_if_a_str_has_duplicate_chars_v1(str1));
    assert(false == check_if_a_str_has_duplicate_chars_v2(str1));
    assert(false == check_if_a_str_has_duplicate_chars_v3(str1));

    /*
     * Test 2: Test with a string having duplicate characters. This should
     *         not be character array having duplicate characters
     */
    char str2[] = "geeks";
    assert(true == check_if_a_str_has_duplicate_chars_v1(str2));
    assert(true == check_if_a_str_has_duplicate_chars_v2(str2));
    assert(true == check_if_a_str_has_duplicate_chars_v3(str2));

    /*
     * Test 3: Test with a string having no duplicate characters. This
     *         should not be character array having duplicate characters
     */
    char str3[] = "water";
    assert(false == check_if_a_str_has_duplicate_chars_v1(str3));
    assert(false == check_if_a_str_has_duplicate_chars_v2(str3));
    assert(false == check_if_a_str_has_duplicate_chars_v3(str3));

    /*
     * Test 4: Test with a string having a single character. This
     *         should not be character array having duplicate characters
     */
    char str4[] = "w";
    assert(false == check_if_a_str_has_duplicate_chars_v1(str4));
    assert(false == check_if_a_str_has_duplicate_chars_v2(str4));
    assert(false == check_if_a_str_has_duplicate_chars_v3(str4));

    return(0);
}
