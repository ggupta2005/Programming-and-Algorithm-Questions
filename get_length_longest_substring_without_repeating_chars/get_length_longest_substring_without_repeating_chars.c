/*
 * this program returns the length of the longest substring in a given
 * string in which there are no repeating characters. For more information
 * on this problem, please visit the following web-page:-
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define BITS_PER_BYTE 8
#define MAX_CHAR_SIZE (1 << (sizeof(char) * BITS_PER_BYTE))

int get_length_longest_substr_without_repeating_chars (char* ch)
{
    int count[MAX_CHAR_SIZE];
    int i, len, low, high, cur_low, cur_high;
    int mapped_char;

    if (!ch || !strlen(ch)) {
        return(0);
    }

    len = strlen(ch);

    memset(count, 0, sizeof(count));
    low = high = 0;
    cur_low = cur_high = 0;
    for (i = 0; i < len; ++i) {

        mapped_char = ch[i] + MAX_CHAR_SIZE/2;

        if (count[mapped_char] == 0) {

            cur_high = i;
            count[mapped_char] = 1;

            if ((cur_high - cur_low + 1) > (high - low + 1)) {
                low = cur_low;
                high = cur_high;
            }
        } else {
            cur_low = cur_high = i;
            memset(count, 0, sizeof(count));
            count[mapped_char] = 1;
        }
    }

    return(high - low + 1);
}

int main ()
{
    char* str2 = "abcabcbb";
    int exp_longest_len2 = 3;
    int act_longest_len2 =
        get_length_longest_substr_without_repeating_chars(str2);
    assert(exp_longest_len2 == act_longest_len2);

    char* str3 = "bbbbb";
    int exp_longest_len3 = 1;
    int act_longest_len3 =
        get_length_longest_substr_without_repeating_chars(str3);
    assert(exp_longest_len3 == act_longest_len3);

    char* str4 = "pwwkwe";
    int exp_longest_len4 = 3;
    int act_longest_len4 =
        get_length_longest_substr_without_repeating_chars(str4);
    assert(exp_longest_len4 == act_longest_len4);

    return(0);
}
