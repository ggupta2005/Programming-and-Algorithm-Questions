/*
 * This program finds the maximum occurring character in a string. For more
 * information on this, visit the post:-
 * http://www.geeksforgeeks.org/return-maximum-occurring-character-in-the-input-string/
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<limits.h>

/*
 * Maximum number of characters possible in this programming
 * language
 */
#define NUM_CHARS_POSSIBLE       (1 << (sizeof(char) * CHAR_BIT))

/*
 * This function returns the maximum occuring character in a character
 * string. If more than one character occurs for the maximum time in the
 * input string, then this function returns the character which has the
 * least ascii value. The time complexity of this function is O(n) where
 * 'n' is the number of characters in the input string and the space
 * complexity of this function is O(1).
 */
char maximum_occurring_char_in_string (char* ch)
{
    unsigned char result;
    int max_count, count, i, j, len;
    int char_stats[NUM_CHARS_POSSIBLE];
    unsigned char mapped_char;

    /*
     * If the character string is NULL or the string is empty, then
     * return zero.
     */
    if (!ch || !strlen(ch)) {
        return(0);
    }

    len = strlen(ch);

    /*
     * Set the character stats array to zero
     */
    memset(char_stats, 0, (NUM_CHARS_POSSIBLE) * sizeof(int));

    /*
     * Map all the characters of the string to the
     * character stats array.
     */
    for (i = 0; i < len; ++i) {
        mapped_char = ch[i] + (NUM_CHARS_POSSIBLE/2);
        char_stats[mapped_char]++;
    }

    /*
     * Find the character maximum occuring character in the
     * character stats array.
     */
    max_count = char_stats[0];
    result = 0;
    for (i = 1; i < NUM_CHARS_POSSIBLE; ++i) {

        if (char_stats[i] > max_count) {

            /*
             * If the frequency of the character in the stats
             * array is greater than the current maximum, then
             * update max count and record the ascii value of
             * character.
             */
            max_count = char_stats[i];
            result = i;
        } else if (char_stats[i] == max_count) {

            /*
             * If the frequency of the character in the stats
             * array is same than the current maximum, then
             * record the ascii value of character if the ascii
             * value is smaller than the current ascii value.
             */
            if (result > i) {
                result = i;
            }
        }
    }

    return(result - (NUM_CHARS_POSSIBLE/2));
}

int main()
{
    /*
     * Test 1: Find the maximum occurring character from a
     *         alphabetical string.
     */
    char* str1 = "geeksforgeeks.org";
    char expected_char1 = 'e';
    char actual_char1;
    actual_char1 = maximum_occurring_char_in_string(str1);
    assert(expected_char1 == actual_char1);

    /*
     * Test 2: Find the maximum occurring character from a
     *         string containing both positive and negative
     *         ascii values
     */
    char str2[] = {-124, -124, 89, 65, -110, 0};
    char expected_char2 = -124;
    char actual_char2;
    actual_char2 = maximum_occurring_char_in_string(str2);
    assert(expected_char2 == actual_char2);

    /*
     * Test 3: Test with a string having multiple characters
     *         which are maximum occuring. The maximum occuring
     *         character should be the one with the smallest
     *         ascii value.
     */
    char* str3 = "rreeffggtthhuuuaaa";
    char expected_char3 = 'a';
    char actual_char3;
    actual_char3 = maximum_occurring_char_in_string(str3);
    assert(expected_char3 == actual_char3);

    /*
     * Test 4: Test with a NULL string. The ascii value of the
     *         maximum occuring character in a NULL string should
     *         be zero.
     */
    char* str4 = NULL;
    char expected_char4 = 0;
    char actual_char4;
    actual_char4 = maximum_occurring_char_in_string(str4);
    assert(expected_char4 == actual_char4);

    /*
     * Test 5: Test with an empty string. The ascii value of the
     *         maximum occuring character in an empty string should
     *         be zero.
     */
    char* str5 = "";
    char expected_char5 = 0;
    char actual_char5;
    actual_char5 = maximum_occurring_char_in_string(str5);
    assert(expected_char5 == actual_char5);

    return(0);
}
