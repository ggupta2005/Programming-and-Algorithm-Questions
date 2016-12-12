/*
 * This program finds the longest common prefix string for an array or list
 * of strings. For more iformation on the problem, please refer to the
 * following link:- http://www.geeksforgeeks.org/longest-common-prefix-set-1-word-by-word-matching/
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<limits.h>

/*
 * This function returns the longest common prefix string for the list of
 * string. If this is no common prefix string, then this function returns
 * NULL. The time complexity of this function is O(m * n), where 'm' is the
 * number of string and 'n' is the maximum length of the string in this
 * list of strings. The space complexity of this function is O(p), where
 * 'p' is the length of the shortest length of the string in this list of
 * strings.
 */
char* longestCommonPrefix(char** strs, int len)
{
    int index;
    int min_len, common_prefix_index;
    char* common_prefix = NULL;

    /*
     * If the array of string is empty or its length is
     * invalid, then return NULL as the longest common
     * prefix
     */
    if (!strs || (len <= 0)) {
        return(NULL);
    }

    /*
     * Find the minimum length of a string among the list
     * of strings
     */
    min_len = INT_MAX;
    for (index = 0; index < len; ++index) {
        if (!strs[index]) {
            min_len = 0;
        } else {
            if (min_len > strlen(strs[index])) {
                min_len = strlen(strs[index]);
            }
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
    common_prefix = (char*)malloc(sizeof(char) * (min_len + 1));

    /*
     * If the memory alloation fails, then return NULL
     */
    if (!common_prefix) {
        return(NULL);
    }

    /*
     * Set the allocated memory to zero
     */
    memset(common_prefix, 0, sizeof(char) * (min_len + 1));

    /*
     * Iterate over the number of characters in the smallest
     * string among the list of strings
     */
    for (common_prefix_index = 0; common_prefix_index < min_len;
         ++common_prefix_index) {

        /*
         * Iterate over all the strings to check if the character
         * at index position 'common_prefix_index' is same in all
         * the strings
         */
        for (index = 1; index < len; ++index) {

            if (strs[index - 1][common_prefix_index] !=
                strs[index][common_prefix_index]) {
                    break;
            }
        }

        if (index < len) {

            /*
             * If the character at at index position is not same in all
             * the strings, then we have found the longest common prefix.
             * Break from the loop.
             */
            break;
        } else {

            /*
             * Otherwise set the common character in the longest common
             * prefix string
             */
            common_prefix[common_prefix_index] =
                        strs[0][common_prefix_index];
        }
    }

    if (!common_prefix_index) {

        /*
         * If there were no common prefix characers found in the string
         * then free the allocated string and return NULL
         */
        free(common_prefix);
        return(NULL);
    }

    /*
     * Return the longest common prefix string
     */
    return(common_prefix);
}

int main ()
{
    /*
     * Test 0: Test when the list of strings is empty. The longest
     *         common prefix string should be NULL.
     */
    char* list0[] = {};
    int len0 = sizeof(list0)/sizeof(char*);
    assert(NULL == longestCommonPrefix(list0, len0));

    /*
     * Test 1: Test the case when there is only one string in the
     *         list of strings. The longest common prefix string should
     *         be the only string itself.
     */
    char* list1[] = {"abc"};
    int len1 = sizeof(list1)/sizeof(char*);
    assert(strcmp("abc", longestCommonPrefix(list1, len1)) == 0);

    /*
     * Test 2: Test the case when there are multiple string and there
     *         exists a longest common prefix string. The longest common
     *         prefix string returned should be non-NULL.
     */
    char* list2[] = {"abc", "abcd", "abef", "abdc"};
    int len2 = sizeof(list2)/sizeof(char*);
    assert(strcmp("ab", longestCommonPrefix(list2, len2)) == 0);

    /*
     * Test 3: Test the case when there are multiple string and there
     *         doesn't exist a longest common prefix string. The longest
     *         common prefix string returned should be NULL.
     */
    char* list3[] = {"bc", "bcd", "abef", "abdc"};
    int len3 = sizeof(list3)/sizeof(char*);
    assert(NULL == longestCommonPrefix(list3, len3));

    /*
     * Test 4: Test the case when there are multiple string all the strings
     *         are same. The longest common prefix string returned should
     *         be non-NULL and equal to one of the strings.
     */
    char* list4[] = {"abcd", "abcd", "abcd", "abcd", "abcd", "abcd"};
    int len4 = sizeof(list4)/sizeof(char*);
    assert(strcmp(list4[0], longestCommonPrefix(list4, len4)) == 0);

    /*
     * Test 5: Test the case when there are multiple string and there
     *         exist a NULL string among these list of strings. The
     *         longest common prefix string returned should be NULL.
     */
    char* list5[] = {"bc", NULL, "abef", "abdc"};
    int len5 = sizeof(list5)/sizeof(char*);
    assert(NULL == longestCommonPrefix(list5, len5));

    /*
     * Test 6: Test the case when there are multiple string and there
     *         exist an empty string among these list of strings. The
     *         longest common prefix string returned should be NULL.
     */
    char* list6[] = {"bc", "", "abef", "abdc"};
    int len6 = sizeof(list6)/sizeof(char*);
    assert(NULL == longestCommonPrefix(list6, len6));

    return(0);
}
