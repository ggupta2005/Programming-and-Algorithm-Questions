/*
 * This program finds the longest common suffix string for an array or list
 * of strings.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<limits.h>

/*
 * This function reverses a character string. The time complexity of
 * this function is O(n) and the space complexity of this function
 * is O(1).
 */
void reverse_str (char* ch)
{
    int left, right;

    /*
     * If the character array is NULL or its length is zero,
     * then return from this function.
     */
    if (!ch || !strlen(ch)) {
        return;
    }

    /*
     * Set left to zero
     */
    left = 0;

    /*
     * Set right to the last charater in the string
     */
    right = strlen(ch) - 1;

    /*
     * Iterate until left index is less than right index
     */
    while (left < right) {

        /*
         * If left indexed character is not same as the
         * right indexed character, then swap the characters
         * using the xor operator.
         */
        if (ch[left] != ch[right]) {

            ch[left] ^= ch[right];
            ch[right] ^= ch[left];
            ch[left] ^= ch[right];
        }

        /*
         * Increment the left index
         */
        ++left;

        /*
         * Decrement the right index
         */
        --right;
    }
}

/*
 * This function returns the longest common suffix string for the list of
 * string. If this is no common suffix string, then this function returns
 * NULL. The time complexity of this function is O(m * n), where 'm' is the
 * number of strings and 'n' is the maximum length of the string in this
 * list of strings. The space complexity of this function is O(p + m),
 * where 'p' is the length of the shortest length of the string in this
 * list of strings and 'm' is the number of strings.
 */
char* longestCommonSuffix(char** strs, int len)
{
    int index;
    int min_len, common_suffix_index;
    char* common_suffix = NULL;
    int* str_len_array = NULL;

    /*
     * If the array of string is empty or its length is
     * invalid, then return NULL as the longest common
     * suffix
     */
    if (!strs || (len <= 0)) {
        return(NULL);
    }

    str_len_array = (int*)malloc(sizeof(int) * len);
    if (!str_len_array) {
        return(NULL);
    }

    /*
     * Cache the length of each string in the array of strings
     */
    for (index = 0; index < len; ++index) {

        if (!strs[index]) {
            str_len_array[index] = 0;
        } else {
            str_len_array[index] = strlen(strs[index]);
        }
    }

    /*
     * Find the minimum length of a string among the list
     * of strings
     */
    min_len = INT_MAX;
    for (index = 0; index < len; ++index) {

        if (min_len > str_len_array[index]) {
            min_len = str_len_array[index];
        }
    }

    /*
     * If the minimum length of the string is found to be zero,
     * then return NULL
     */
    if (min_len == 0) {
        return(NULL);
    }

    /*
     * Allocate a string which can store 'min_len' characters
     */
    common_suffix = (char*)malloc(sizeof(char) * (min_len + 1));

    /*
     * If the memory alloation fails, then return NULL
     */
    if (!common_suffix) {
        free(str_len_array);
        return(NULL);
    }

    /*
     * Set the allocated memory to zero
     */
    memset(common_suffix, 0, sizeof(char) * (min_len + 1));

    /*
     * Iterate over the number of characters in the smallest
     * string among the list of strings
     */
    for (common_suffix_index = 0; common_suffix_index < min_len;
         ++common_suffix_index) {

        /*
         * Iterate over all the strings to check if the character
         * at index position 'common_suffix_index' is same in all
         * the strings
         */
        for (index = 1; index < len; ++index) {

            if (strs[index - 1][
                     str_len_array[index - 1] - common_suffix_index] !=
                strs[index][
                     str_len_array[index] - common_suffix_index]) {
                    break;
            }
        }

        if (index < len) {

            /*
             * If the character at at index position is not same in all
             * the strings, then we have found the longest common suffix.
             * Break from the loop.
             */
            break;
        } else {

            /*
             * Otherwise set the common character in the longest common
             * suffix string
             */
            common_suffix[common_suffix_index] =
                        strs[0][str_len_array[0] - common_suffix_index - 1];
        }
    }

    if (!common_suffix_index) {

        /*
         * If there were no common suffix characers found in the string
         * then free the allocated string and return NULL
         */
        free(common_suffix);
        free(str_len_array);
        return(NULL);
    }

    /*
     * Reverse the suffix string
     */
    reverse_str(common_suffix);

    /*
     * Return the longest common suffix string
     */
    return(common_suffix);
}

int main ()
{
    /*
     * Test 0: Test when the list of strings is empty. The longest
     *         common suffix string should be NULL.
     */
    char* list0[] = {};
    int len0 = sizeof(list0)/sizeof(char*);
    assert(NULL == longestCommonSuffix(list0, len0));

    /*
     * Test 1: Test the case when there is only one string in the
     *         list of strings. The longest common suffix string should
     *         be the only string itself.
     */
    char* list1[] = {"abc"};
    int len1 = sizeof(list1)/sizeof(char*);
    assert(strcmp("abc", longestCommonSuffix(list1, len1)) == 0);

    /*
     * Test 2: Test the case when there are multiple string and there
     *         exists a longest common suffix string. The longest common
     *         suffix string returned should be non-NULL.
     */
    char* list2[] = {"cab", "cdab", "efab", "dcab"};
    int len2 = sizeof(list2)/sizeof(char*);
    assert(strcmp("ab", longestCommonSuffix(list2, len2)) == 0);

    /*
     * Test 3: Test the case when there are multiple string and there
     *         doesn't exist a longest common suffix string. The longest
     *         common suffix string returned should be NULL.
     */
    char* list3[] = {"bc", "bcd", "abef", "abdc"};
    int len3 = sizeof(list3)/sizeof(char*);
    assert(NULL == longestCommonSuffix(list3, len3));

    return(0);
}
