/*
 * This program finds all the duplicate characters in a given string.
 * For more information on this problem, please refer to the folloiwng
 * link:- http://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>

/*
 * Maximum number of possible characters in this programming language
 */
#define MAX_NUM_CHARACTERS (1 << (sizeof(char) * CHAR_BIT))

/*
 * This function returns the duplicate characters in a given string of
 * characters in sorted order. If the string is not valid then this
 * function returns NULL. If there are no duplicate characters in the
 * string, then this function returns NULL. The time complexity of this
 * function is O(n), where 'n' is the number of characters in the string.
 * The space complexity of this function is O(1).
 */
char* find_all_duplicate_characters_in_str (char* ch)
{
    char char_stats[MAX_NUM_CHARACTERS];
    int index, len, mapped_char, num_duplicates, duplicate_index;
    char* duplicates;

    /*
     * If the character string is NULL, then return NULL
     */
    if (!ch) {
        return(NULL);
    }

    /*
     * Set all elements of the count array to be zero
     */
    memset(char_stats, 0, sizeof(char) * MAX_NUM_CHARACTERS);

    len = strlen(ch);

    /*
     * Iterate over the entire string and map the characters of the string
     * into the count array
     */
    for (index =- 0; index < len; ++index) {

        /*
         * The mapped character is the addition of the ascii value of the
         * character and the helf of the maximum number of characters in the
         * programming language set.
         */
        mapped_char = ch[index] + (MAX_NUM_CHARACTERS / 2);

        if (mapped_char >= MAX_NUM_CHARACTERS) {
            continue;
        }

        /*
         * Increment the count array for the mapped character
         */
        char_stats[mapped_char]++;
    }

    /*
     * Find the number of duplicate characters detected in the input
     * string
     */
    num_duplicates = 0;
    for (index = 0; index < MAX_NUM_CHARACTERS; ++index) {
        if (char_stats[index] > 1) {
            num_duplicates++;
        }
    }

    /*
     * Allocate the string for the duplicate characters
     */
    duplicates = (char*)malloc(sizeof(char) * (num_duplicates + 1));

    /*
     * If the memory allocation fails, then return NULL
     */
    if (!duplicates) {
        return(NULL);
    }

    /*
     * Set the duplicate character string to zero
     */
    memset(duplicates, 0, sizeof(char) * (num_duplicates + 1));

    /*
     * Make a pass of the stats array and the characters into the
     * duplicate character array
     */
    duplicate_index = 0;
    for (index = 0; index < MAX_NUM_CHARACTERS; ++index) {

        /*
         * If the character was found to be duplicate in the input
         * string then add the character into the duplicate character
         * array.
         */
        if (char_stats[index] > 1) {
            duplicates[duplicate_index] = index - (MAX_NUM_CHARACTERS / 2);
            duplicate_index++;
        }
    }

    /*
     * Return the string containing the duplicate characters
     */
    return(duplicates);
}

int main ()
{
    /*
     * Test 0: If the input string is NULL, then the duplicate character
     *         string should be NULL.
     */
    assert(NULL == find_all_duplicate_characters_in_str(NULL));

    /*
     * Test 1: If the input string does not contain any duplicate characters,
     *         then the duplicate character string should be empty.
     */
    assert(!strcmp("", find_all_duplicate_characters_in_str("abc")));

    /*
     * Test 2: Test with an input string having one duplicate character.
     *         The duplicate character string should contian this character
     *         only.
     */
    assert(!strcmp("a", find_all_duplicate_characters_in_str("aabc")));

    /*
     * Test 3: Test with an input string having all characters as duplicates.
     *         The duplicate character string should contian all the
     *         characters in sorted order.
     */
    assert(!strcmp("abc", find_all_duplicate_characters_in_str("aabccb")));

    /*
     * Test 4: Test with an input string having some characters as
     *         duplicates and some which are not duplicates. The duplicate
     *         character string should only contian the duplicate characters
     *         in sorted order.
     */
    assert(!strcmp("egks",
                find_all_duplicate_characters_in_str("geeksforgeeks")));

    return(0);
}
