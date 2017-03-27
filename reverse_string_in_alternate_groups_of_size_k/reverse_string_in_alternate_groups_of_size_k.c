/*
 * Given a string and an integer k, you need to reverse the first k
 * characters for every 2k characters counting from the start of the
 * string. If there are less than k characters left, reverse all of them.
 * If there are less than 2k but greater than or equal to k characters,
 * then reverse the first k characters and left the other as original.
 *
 * Example:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

/*
 * This function reverses the order of characters in an input string
 * from index position 'low' to index position 'high'. The time
 * complexity of this function is O(n), where 'n' is the number of
 * characters between 'low' and 'high'. The space complexity of this
 * function is O(1).
 */
void reverse_section (char* s, int low, int high)
{
    /*
     * If the input string is invalid or the indexed positions
     * 'low' and 'high' are not valid, then return.
     */
    if (!s || (low < 0) || (high < 0) || (high <= low)) {
        return;
    }

    /*
     * Iterate until 'low' is less than 'high'
     */
    while (low < high) {

        /*
         * Swap the characters using xor operator
         */
        if (s[low] != s[high]) {
            s[low] ^= s[high];
            s[high] ^= s[low];
            s[low] ^= s[high];
        }

        /*
         * Increment the low index
         */
        ++low;

        /*
         * Decrement the high index
         */
        --high;
    }
}

/*
 * This fuction reverses alternate sections of 'k' characters in
 * the input string. The time complexity of this function is O(n),
 * where 'n' is the number of characters in the input string. The
 * space complexity of this function is O(1).
 */
char* reverse_str_in_alternate_groups_of_size_k (char* s, int k)
{
    char* result = NULL;
    int i, len, chunk, low, high;

    /*
     * If the input string is not valid, then return NULL
     */
    if (!s) {
        return(NULL);
    }

    len = strlen(s);

    /*
     * If the length of the string is zero, then return
     * an empty string
     */
    if (!len) {
        result = (char*)malloc(sizeof(char));
        memset(result, 0, sizeof(char));
        return(result);
    }

    /*
     * Allocate memory for the reversed string in alternate chunks
     * of 'k' characters and copy the original string into the
     * alloated string.
     */
    result = (char*)malloc(sizeof(char) * (len + 1));
    memset(result, 0, sizeof(char) * (len + 1));
    strncpy(result, s, len);

    /*
     * If the input chuck is not valid, then return the copy of the
     * input string.
     */
    if (k <= 0) {
        return(result);
    }

    chunk = 0;
    i = 0;

    /*
     * Iterate through the length of the string
     */
    while (i < len) {

        /*
         * If this is an even numbered chunk, then reverse this
         * chunk
         */
        if (chunk % 2 == 0) {

            /*
             * Compute the lower index of the section
             */
            low = i;

            /*
             * Compute the upper index of the section
             */
            high = ((i + k - 1) > (len - 1) ? (len -1) : (i + k - 1));

            /*
             * Reverse the section between the upper and lower
             * index values
             */
            reverse_section(result, low, high);
        }

        i += k;

        /*
         * Increment the chuck number
         */
        ++chunk;
    }

    /*
     * Return the reversed string
     */
    return(result);
}

int main ()
{
    /*
     * Test 0: Test with a NULL string. The string in which
     *         every alternate characters are reversed should
     *         be NULL.
     */
    assert(NULL == reverse_str_in_alternate_groups_of_size_k(NULL, 3));
    assert(NULL == reverse_str_in_alternate_groups_of_size_k(NULL, 0));

    /*
     * Test 1: Test with an empty string. The string in which
     *         every alternate characters are reversed should
     *         be empty.
     */
    assert(!strcmp("",
                   reverse_str_in_alternate_groups_of_size_k("", 3)));
    assert(!strcmp("",
                   reverse_str_in_alternate_groups_of_size_k("", 0)));

    /*
     * Test 2: Test with a valid string but an invalid value of 'k'.
     *         The string in which every alternate characters are reversed
     *         should be same as the input string.
     */
    assert(!strcmp("abcdefgh",
             reverse_str_in_alternate_groups_of_size_k("abcdefgh", 0)));
    assert(!strcmp("abcdefgh",
             reverse_str_in_alternate_groups_of_size_k("abcdefgh", -3)));

    /*
     * Test 3: Test with a valid string and a valid value of 'k'. The
     *         output string should the one in which every alternate
     *         characters are reversed in the input string.
     */
    assert(!strcmp("bacdfegh",
             reverse_str_in_alternate_groups_of_size_k("abcdefgh", 2)));
    assert(!strcmp("cbadefhg",
             reverse_str_in_alternate_groups_of_size_k("abcdefgh", 3)));

    /*
     * Test 4: Test with a valid string and a valid value of 'k' which is
     *         greater than the length of the input string. The output
     *         string should be the reverse of the input string.
     */
    assert(!strcmp("hgfedcba",
             reverse_str_in_alternate_groups_of_size_k(
                                 "abcdefgh", strlen("abcdefgh") + 1)));

    /*
     * Test 5: Test with a valid string and a valid value of 'k' which is
     *         one. The output string should be same as the input string.
     */
    assert(!strcmp("abcdefgh",
             reverse_str_in_alternate_groups_of_size_k("abcdefgh", 1)));

    return(0);
}
