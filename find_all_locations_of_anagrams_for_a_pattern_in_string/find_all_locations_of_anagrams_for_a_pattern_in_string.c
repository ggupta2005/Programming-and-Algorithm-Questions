/*
 * This program finds the locations of anagrams of a pattern in a given
 * string. For example if a patterns is "ab" and the string is "tabaftyab",
 * then the location of all the anagrams of "ab" in the string is given
 * by the array [1, 2, 7].
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

#define MAX_CHARACTERS (1 << (sizeof(char) * CHAR_BIT))

void find_all_locations_of_anagrams_for_pattern_in_str (
                                        char* str,
                                        char* pattern,
                                        int** location_array,
                                        int* location_array_len)
{
    int pattern_len, str_len, mapped_char;
    int index, location_index;
    int pattern_stats[MAX_CHARACTERS];
    int str_stats[MAX_CHARACTERS];
    int* location_array_copy;

    if (!location_array || !location_array_len) {
        return;
    }

    if (!str || !pattern || !strlen(str) || !strlen(pattern) ||
        (strlen(str) < strlen(pattern))) {
        *location_array = NULL;
        *location_array_len = 0;
        return;
    }

    pattern_len = strlen(pattern);
    str_len = strlen(str);

    (*location_array) = (int*)malloc(sizeof(int) * str_len);
    location_index = 0;
    if (!(*location_array)) {
        *location_array_len = 0;
        return;
    }

    memset(pattern_stats, 0, sizeof(int) * MAX_CHARACTERS);
    for (index = 0; index < pattern_len; ++index) {
        mapped_char = pattern[index] + MAX_CHARACTERS / 2;

        if (mapped_char >= MAX_CHARACTERS) {
            continue;
        }

        pattern_stats[mapped_char]++;
    }

    memset(str_stats, 0, sizeof(int) * MAX_CHARACTERS);
    for (index = 0; index < pattern_len; ++index) {
        mapped_char = str[index] + MAX_CHARACTERS / 2;

        if (mapped_char >= MAX_CHARACTERS) {
            continue;
        }

        str_stats[mapped_char]++;
    }

    if (!memcmp(str_stats, pattern_stats,
               sizeof(int) * MAX_CHARACTERS)) {
        (*location_array)[location_index] = 0;
        ++location_index;
    }

    for (index = pattern_len; index < str_len; ++index) {

        mapped_char = str[index - pattern_len]
                                     + MAX_CHARACTERS / 2;

        if (mapped_char >= MAX_CHARACTERS) {
            continue;
        }

        str_stats[mapped_char]--;

        mapped_char = str[index] + MAX_CHARACTERS / 2;

        if (mapped_char >= MAX_CHARACTERS) {
            continue;
        }

        str_stats[mapped_char]++;

        if (!memcmp(str_stats, pattern_stats,
                    sizeof(int) * MAX_CHARACTERS)) {
            (*location_array)[location_index] =
                                 index - pattern_len + 1;
            ++location_index;
        }
    }

    if (location_index == str_len) {
        *location_array_len = str_len;
        return;
    }

    location_array_copy = *location_array;

    (*location_array) = (int*)malloc(
                            sizeof(int) * location_index);
    if (!(*location_array)) {
        free(location_array_copy);
        *location_array_len = 0;
        return;
    }

    for (index = 0; index < location_index; ++index) {
        (*location_array)[index] =
                                location_array_copy[index];
    }

    free(location_array_copy);

    *location_array_len = location_index;
}

int main ()
{
    int* act_loc_array7 = NULL;
    int act_len7 = 0;
    int exp_loc_array7[] = {0};
    int exp_len7 = sizeof(exp_loc_array7)/sizeof(int);
    find_all_locations_of_anagrams_for_pattern_in_str(
                                "a", "a", &act_loc_array7, &act_len7);
    assert((act_len7 == exp_len7) &&
           !memcmp(act_loc_array7, exp_loc_array7, sizeof(int) * act_len7));

    int* act_loc_array8 = NULL;
    int act_len8 = 0;
    int exp_loc_array8[] = {0,1,2,3,4};
    int exp_len8 = sizeof(exp_loc_array8)/sizeof(int);
    find_all_locations_of_anagrams_for_pattern_in_str(
                                "aaaaa", "a", &act_loc_array8, &act_len8);
    assert((act_len8 == exp_len8) &&
           !memcmp(act_loc_array8, exp_loc_array8, sizeof(int) * act_len8));

    int* act_loc_array9 = NULL;
    int act_len9 = 0;
    int exp_loc_array9[] = {4,5,6,7,8,9,10,11};
    int exp_len9 = sizeof(exp_loc_array9)/sizeof(int);
    find_all_locations_of_anagrams_for_pattern_in_str(
                                "abbbabcabcabca", "abc", &act_loc_array9, &act_len9);
    assert((act_len9 == exp_len9) &&
           !memcmp(act_loc_array9, exp_loc_array9, sizeof(int) * act_len9));

    int* act_loc_array10 = NULL;
    int act_len10 = 0;
    int exp_loc_array10[] = {0,4,8,12};
    int exp_len10 = sizeof(exp_loc_array10)/sizeof(int);
    find_all_locations_of_anagrams_for_pattern_in_str(
                                "abcxbacxcabxabc", "abc", &act_loc_array10, &act_len10);
    assert((act_len10 == exp_len10) &&
           !memcmp(act_loc_array10, exp_loc_array10, sizeof(int) * act_len10));

    return(0);
}
