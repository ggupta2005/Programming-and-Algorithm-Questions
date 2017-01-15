/*
 * This program reverses the string word by word. A word is defined as a
 * sequence of non-space characters. The input string does not contain
 * leading or trailing spaces and the words are always separated by a
 * single space.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Could you do it in-place without allocating extra space?
 */
#include<stdio.h>
#include<assert.h>
#include<string.h>

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
        s[low] ^= s[high];
        s[high] ^= s[low];
        s[low] ^= s[high];

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
 * This function reverses an input string word by word. The time
 * complexity of this function is O(n), where 'n' is the number of
 * characters between 'low' and 'high'. The space complexity of this
 * function is O(1).
 */
void reverse_words_in_string (char *s)
{
    int high, low, len, index;

    /*
     * If input string is invalid or if the string is
     * empty, then return
     */
    if (!s || !strlen(s)) {
        return;
    }

    len = strlen(s);

    /*
     * Reverse the entire string
     */
    reverse_section(s, 0, len - 1);

    /*
     * Set both index 'low' and 'high' to zero
     */
    low = 0;
    high = 0;
    do {

        /*
         * Find the end index of a word
         */
        while ((high < len) && (s[high] != ' ')) {
            ++high;
        }

        if (high <= len) {

            /*
             * Reverse the current word spanning from
             * 'low' to 'high - 1'
             */
            reverse_section(s, low, high - 1);
        }

        /*
         * Move to the beginning of the next word
         */
        low = high;
        while ((low < len) && (s[low] == ' ')) {
            ++low;
        }

        /*
         * Set both index 'low' and 'high' to starting
         * of the next word
         */
        high = low;

    } while (low < len); /* Continue until there is a
                            valid word in the string */
}

int main ()
{
    /*
     * Test 0: Test with a NULL string. The string after calling
     *         the function for reversing words in the string should
     *         be NULL.
     */
    char* act_ch0 = NULL;
    char* exp_ch0 = NULL;
    reverse_words_in_string(act_ch0);
    assert(act_ch0 == exp_ch0);

    /*
     * Test 1: Test with an empty string. The string after calling
     *         the function for reversing words in the string should
     *         be empty.
     */
    char act_ch1[] = "";
    char exp_ch1[] = "";
    reverse_words_in_string(act_ch1);
    assert(!strcmp(act_ch1, exp_ch1));

    /*
     * Test 2: Test with a string containing many words. The string
     *         after calling the function for reversing words in the
     *         string should have the words reversed.
     */
    char act_ch2[] = "the sky is blue";
    char exp_ch2[] = "blue is sky the";
    reverse_words_in_string(act_ch2);
    assert(!strcmp(act_ch2, exp_ch2));

    /*
     * Test 3: Test with a string containing only one word. The string
     *         after calling the function for reversing words in the
     *         string should be unchanged.
     */
    char act_ch3[] = "character";
    char exp_ch3[] = "character";
    reverse_words_in_string(act_ch3);
    assert(!strcmp(act_ch3, exp_ch3));

    /*
     * Test 4: Test with a string containing only one letter. The string
     *         after calling the function for reversing words in the
     *         string should be unchanged.
     */
    char act_ch4[] = "a";
    char exp_ch4[] = "a";
    reverse_words_in_string(act_ch4);
    assert(!strcmp(act_ch4, exp_ch4));

    return(0);
}
