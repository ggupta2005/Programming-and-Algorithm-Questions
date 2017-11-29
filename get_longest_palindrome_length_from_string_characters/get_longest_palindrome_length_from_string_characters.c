/*
 * This program returns the length of the longest possible palindrome
 * from the characters of a string.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define BITS_PER_BYTE          8
#define MAX_NUM_POSSIBLE_CHARS (1 << (sizeof(char) * BITS_PER_BYTE))

int get_longest_palindrome_length_from_str_chars (char* ch)
{
    int len, index;
    int char_stats[MAX_NUM_POSSIBLE_CHARS];
    int mapped_char;
    int sum_count_char, max_odd_count_char;

    if (!ch || !strlen(ch)) {
        return(0);
    }

    len = strlen(ch);

    memset(char_stats, 0, sizeof(char_stats));

    for (index = 0; index < len; ++index) {
        mapped_char = ch[index] + MAX_NUM_POSSIBLE_CHARS/2;

        if (mapped_char >= MAX_NUM_POSSIBLE_CHARS) {
            continue;
        }

        char_stats[mapped_char]++;
    }

    sum_count_char = 0;
    max_odd_count_char = 0;
    for (index = 0; index < MAX_NUM_POSSIBLE_CHARS; ++index) {

        if (char_stats[index] > 0) {

            if ((char_stats[index] % 2) == 0) {
                sum_count_char += char_stats[index];
            } else {

                if (max_odd_count_char > 0) {
                    if (max_odd_count_char < char_stats[index]) {

                        sum_count_char--;

                        max_odd_count_char = char_stats[index];

                        sum_count_char += max_odd_count_char;
                    } else {
                        sum_count_char += char_stats[index] - 1;
                    }
                } else {
                    max_odd_count_char = char_stats[index];

                    sum_count_char += max_odd_count_char;
                }
            }
        }
    }

    return(sum_count_char);
}

int main ()
{
    char* ch0 = "abccccdd";
    int exp_max_palindrome_len0 = 7;
    assert(exp_max_palindrome_len0 ==
                get_longest_palindrome_length_from_str_chars(ch0));

    char* ch1 = "ad";
    int exp_max_palindrome_len1 = 1;
    assert(exp_max_palindrome_len1 ==
                get_longest_palindrome_length_from_str_chars(ch1));

    char* ch2 = "aa";
    int exp_max_palindrome_len2 = 2;
    assert(exp_max_palindrome_len2 ==
                get_longest_palindrome_length_from_str_chars(ch2));

    char* ch3 = "aA";
    int exp_max_palindrome_len3 = 1;
    assert(exp_max_palindrome_len3 ==
                get_longest_palindrome_length_from_str_chars(ch3));

    char* ch4 = "aabbcccc";
    int exp_max_palindrome_len4 = strlen(ch4);
    assert(exp_max_palindrome_len4 ==
                get_longest_palindrome_length_from_str_chars(ch4));

    char* ch5 = "aaabbbccccc";
    int exp_max_palindrome_len5 = 9;
    assert(exp_max_palindrome_len5 ==
                get_longest_palindrome_length_from_str_chars(ch5));

    return(0);
}
