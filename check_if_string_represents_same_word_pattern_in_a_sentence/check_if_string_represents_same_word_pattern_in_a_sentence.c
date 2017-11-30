/*
 * Given a 'pattern' and a string 'str', find if 'str' follows he same pattern.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

#define BITS_PER_BYTE      8
#define MAX_CHARACTERS     (1 << (sizeof(char) * BITS_PER_BYTE))

bool check_if_str_represents_same_word_pattern_in_sentence (
                                                char* str, char* pattern)
{
    int num_words, len, index, mapped_char;
    char* words[MAX_CHARACTERS];
    char* temp;

    if (!pattern || !str) {
        return(false);
    }

    if (!strlen(pattern) || !strlen(str)) {
        return(false);
    }

    memset(words, 0, sizeof(words));

    num_words = 0;
    len = strlen(pattern);
    for (index = 0; index < len; ++index) {
        mapped_char = pattern[index] + MAX_CHARACTERS/2;

        if (index == 0) {
            temp = strtok(str, " ");
        } else {
            temp = strtok(NULL, " ");
        }

        if (!temp) {
            return(false);
        }

        if (words[mapped_char]) {
            if (strcmp(words[mapped_char], temp)) {
                return(false);
            }
        } else {
            words[mapped_char] = temp;
        }
    }

    temp = strtok(NULL, " ");

    if (temp) {
        return(false);
    }

    return(true);
}

int main ()
{
    char pattern0[] = "abba";
    char str0[] = "dog cat cat dog";
    assert(true ==
            check_if_str_represents_same_word_pattern_in_sentence(
                                                     str0, pattern0));

    char pattern1[] = "abba";
    char str1[] = "dog cat cat fish";
    assert(false ==
            check_if_str_represents_same_word_pattern_in_sentence(
                                                     str1, pattern1));

    char pattern2[] = "aaaa";
    char str2[] = "dog cat cat dog";
    assert(false ==
            check_if_str_represents_same_word_pattern_in_sentence(
                                                     str2, pattern2));

    char pattern3[] = "abba";
    char str3[] = "dog dog dog dog";
    assert(false ==
            check_if_str_represents_same_word_pattern_in_sentence(
                                                     str3, pattern3));

    char pattern4[] = "aba";
    char str4[] = "dog cat dog cat";
    assert(false ==
            check_if_str_represents_same_word_pattern_in_sentence(
                                                     str4, pattern4));

    char pattern5[] = "aba";
    char str5[] = "dog cat";
    assert(false ==
            check_if_str_represents_same_word_pattern_in_sentence(
                                                     str5, pattern5));
    return(0);
}
