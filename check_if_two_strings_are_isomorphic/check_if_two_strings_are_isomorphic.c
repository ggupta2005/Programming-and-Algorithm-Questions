/*
 * This program checks if two character strings are isomorphic.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<limits.h>

#define MAX_CHARACTERS  (1 << (sizeof(char) * CHAR_BIT))

bool isIsomorphic(char* s, char* t)
{
    int s_len, t_len, index;
    int char_map_s[MAX_CHARACTERS], char_map_t[MAX_CHARACTERS];

    if (!s && !t) {
        return(true);
    }

    if (!s || !t) {
        return(false);
    }

    s_len = strlen(s);
    t_len = strlen(t);

    if (s_len != t_len){
        return(false);
    }

    for (index = 0; index < MAX_CHARACTERS; ++index) {
        char_map_s[index] = INT_MIN;
        char_map_t[index] = INT_MIN;
    }

    for (index = 0; index < s_len; ++index) {
        if (char_map_s[s[index] + (MAX_CHARACTERS/2)] == INT_MIN) {
            char_map_s[s[index] + (MAX_CHARACTERS/2)] = t[index] + (MAX_CHARACTERS/2);
        } else if (char_map_s[s[index] + (MAX_CHARACTERS/2)] !=
                                           (t[index] + (MAX_CHARACTERS/2))) {

            return(false);
        }

        if (char_map_t[t[index] + (MAX_CHARACTERS/2)] == INT_MIN) {
            char_map_t[t[index] + (MAX_CHARACTERS/2)] = s[index] + (MAX_CHARACTERS/2);
        } else if (char_map_t[t[index] + (MAX_CHARACTERS/2)] !=
                                           (s[index] + (MAX_CHARACTERS/2))) {
            return(false);
        }
    }

    return(true);
}

int main ()
{
    assert(true == isIsomorphic("egg", "add"));
    assert(false == isIsomorphic("foo", "bar"));
    assert(false == isIsomorphic("bar", "foo"));
    assert(true == isIsomorphic("paper", "title"));

    return(0);
}
