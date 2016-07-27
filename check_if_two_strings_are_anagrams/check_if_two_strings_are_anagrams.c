/*
 * This program tests if two strings are anagrams of each other.
 * Two strings are called anagrams, if all characters in the first
 * string can be used to form the permutation of the second string.
 * For example, "fghtyy" is an anagram of "yyhgtf" but "fghtyy" is
 * not an anagram of "yygghy"
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

/*
 * Maximum number of characters possible in 'char' in
 * C-programming language
 */
#define NUM_POSSIBLE_CHARACTERS    (1 << (sizeof(char) * 8))

/*
 * This function partitions the array around a 'pivot' element
 * and returns the index of the pivot element. This functionu
 * uses the element at index 'high' as the pivot.
 */
int partition (char* array, int low, int high)
{
    char pivot, temp;
    int pindex, i;

    /*
     * Set 'pivot' as the element at index 'high' in the array
     */
    pivot = array[high];

    pindex = low;
    for (i = low; i < high; ++i) {

        /*
         * If the array elemnt is less than pivot element
         * then move the element to the left of the pivot
         */
        if (array[i] < pivot) {
            temp = array[i];
            array[i] = array[pindex];
            array[pindex] = temp;
            ++pindex;
        }
    }

    /*
     * At this point all elements less than 'pivot' are present to
     * the left of 'pindex'. So swap and move the element at 'high'
     * to index 'pindex'
     */
    temp = array[high];
    array[high] = array[pindex];
    array[pindex] = temp;

    /*
     * Return the partition index to the quick sort routine
     */
    return(pindex);
}

/*
 * This function sorts a character array from indicies 'low' to
 * 'high' in ascending order using quick sort.
 */
void quicksort (char* array, int low, int high)
{
    int partition_index;

    /*
     * If array is NULL or 'low' or 'high' are less than zero, then
     * there is no need to sory the array. So return.
     */
    if (!array || (low < 0) || (high < 0)) {
        return;
    }

    /*
     * If 'low' is less than 'high', partition the array using
     * and recursively sory the parts around the partition index
     * using quick sort
     */
    if (low < high) {
        partition_index = partition(array, low, high);
        quicksort(array, low, partition_index - 1);
        quicksort(array, partition_index + 1, high);
    }
}

/*
 * This function returns 'true' if the two strings are anagrams of
 * each of other and 'false' otherwise. This function uses the following
 * approach to test whether two strings are anagrams of each other:-
 * 1. Sort the strings using quick sort.
 * 2. Compare the strings character by character to find if any
 *    characters mis-match. If there is a mis-match then return
 *    'false' other wise return 'true'.
 * The time complexity of this function is O(n*log(n)), where 'n'
 * is the number of characters in either string. The time complexity
 * of the function depends on the time taken by quick sort which could
 * be O(n^2) in worst case.
 * The space complexity of this function is O(1).
 */
bool if_two_strings_are_anagrams_v1 (char* str1, char* str2)
{
    int len1, len2, i, j;

    /*
     * If either string in NULL, then return 'false' as
     * we cannot do anagram computation
     */
    if (!str1 || !str2) {
        return(false);
    }

    len1 = strlen(str1);
    len2 = strlen(str2);

    /*
     * If th strings are of un-equal lengths, then the strings
     * are not anagrams of each other. Return 'false'.
     */
    if (len1 != len2) {
        return(false);
    }

    /*
     * Sort both the strings using quick-sort
     */
    quicksort(str1, 0, len1 - 1);
    quicksort(str2, 0, len2 - 1);

    /*
     * Walk both the sorted strings and match each character
     * in string one with corresponding character in string two.
     * Return 'false' if there is a mis-match.
     */
    for (i = 0; i < len1; ++i) {
        if (str1[i] != str2[i]) {
            return(false);
        }
    }

    /*
     * Return 'true' as no mis-match in the sorted strings was
     * detected.
     */
    return(true);
}

/*
 * This function returns 'true' if the two strings are anagrams of
 * each of other and 'false' otherwise. This function uses the following
 * approach to test whether two strings are anagrams of each other:-
 * 1. Map all the characters of string one into a character statistics
 *    array. This array has size that is equal to the number of possible
 *    characters in this programming language. If more than one character
 *    occurs in the same string, then increment the mapped character
 *    statistics
 * 2. Map all the characters of string two into another character
 *    statistics array.
 * 3. Compare the two character statistics array. They should be equal
 *    element to element if the strings are anagrams of each other.
 * The time complexity of this function is O(n), where 'n' is the number
 * of characters in either string.
 * The space complexity of the function depends on the number of characters
 * in the character set supported by this programming language as we use
 * two character statistics arrays to record the character stats.
 */
bool if_two_strings_are_anagrams_v2 (char* str1, char* str2)
{
    int len1, len2, i, j;
    int char_stats1[NUM_POSSIBLE_CHARACTERS];
    int char_stats2[NUM_POSSIBLE_CHARACTERS];
    unsigned char mapped_char;

    /*
     * If either string in NULL, then return 'false' as
     * we cannot do anagram computation
     */
    if (!str1 || !str2) {
        return(false);
    }

    len1 = strlen(str1);
    len2 = strlen(str2);

    /*
     * If th strings are of un-equal lengths, then the strings
     * are not anagrams of each other. Return 'false'.
     */
    if (len1 != len2) {
        return(false);
    }

    memset(char_stats1, 0, sizeof(char_stats1));
    memset(char_stats2, 0, sizeof(char_stats2));

    /*
     * Map all the characters of 'str1' into 'char_stats1' and
     * all characters of 'str2' into 'char_stats2'
     */
    for (i = 0; i < len1; ++i) {
        mapped_char = str1[i] + NUM_POSSIBLE_CHARACTERS/2;
        char_stats1[mapped_char]++;

        mapped_char = str2[i] + NUM_POSSIBLE_CHARACTERS/2;
        char_stats2[mapped_char]++;
    }

    /*
     * Walk both the character stats array and match each value
     * in stats one with corresponding value in stats two.
     * Return 'false' if there is a mis-match.
     */
    for (i = 0; i < NUM_POSSIBLE_CHARACTERS; ++i) {
        if (char_stats1[i] != char_stats2[i]) {
            return(false);
        }
    }

    /*
     * Return 'true' as no mis-match in the char stats was
     * detected.
     */
    return(true);
}

/*
 * This function returns 'true' if the two strings are anagrams of
 * each of other and 'false' otherwise. This function uses the following
 * approach to test whether two strings are anagrams of each other:-
 * 1. Map all the characters of string one into a character statistics
 *    array. This array has size that is equal to the number of possible
 *    characters in this programming language. If more than one character
 *    occurs in the same string, then increment the mapped character
 *    statistics
 * 2. Map all the characters of string two into the same character
 *    statistics array. But this time decrement the count in the mapped
 *    array element.
 * 3. Compare the character statistics array elements to zero. If any
 *    element of the mapped character array is non-zero, then the two
 *    strings are not anagrams of each other.
 * The time complexity of this function is O(n), where 'n' is the number
 * of characters in either string.
 * The space complexity of the function depends on the number of characters
 * in the character set supported by this programming language as we use
 * one character statistics array to record the character stats (both at the
 * time of increment and decrement).
 */
bool if_two_strings_are_anagrams_v3 (char* str1, char* str2)
{
    int len1, len2, i, j;
    int char_stats[NUM_POSSIBLE_CHARACTERS];
    unsigned char mapped_char;

    /*
     * If either string in NULL, then return 'false' as
     * we cannot do anagram computation
     */
    if (!str1 || !str2) {
        return(false);
    }

    len1 = strlen(str1);
    len2 = strlen(str2);

    /*
     * If th strings are of un-equal lengths, then the strings
     * are not anagrams of each other. Return 'false'.
     */
    if (len1 != len2) {
        return(false);
    }

    memset(char_stats, 0, sizeof(char_stats));

    /*
     * Map all the characters of 'str1' into 'char_stats' and
     * increment the mapped character array entry
     */
    for (i = 0; i < len1; ++i) {
        mapped_char = str1[i] + NUM_POSSIBLE_CHARACTERS/2;
        char_stats[mapped_char]++;
    }

    /*
     * Map all the characters of 'str2' into 'char_stats' and
     * decrement the mapped character array entry
     */
    for (i = 0; i < len1; ++i) {
        mapped_char = str2[i] + NUM_POSSIBLE_CHARACTERS/2;
        char_stats[mapped_char]--;
    }

    /*
     * Check if any of the array entries for stats is non-zero.
     * If so, then return 'false'
     */
    for (i = 0; i < NUM_POSSIBLE_CHARACTERS; ++i) {
        if (char_stats[i] != 0) {
            return(false);
        }
    }

    /*
     * Return 'true' as the strings as anagrams
     */
    return(true);
}

int main ()
{
    /*
     * Test 0: If either of the strings are NULL, then the strings
     *         are not anagram of each other.
     */
    char* first0 = NULL;
    char* second0 = NULL;
    assert(false == if_two_strings_are_anagrams_v1(first0, second0));
    assert(false == if_two_strings_are_anagrams_v2(first0, second0));
    assert(false == if_two_strings_are_anagrams_v3(first0, second0));

    /*
     * Test 1: If both the strings are of length zero, then the strings
     *         are anagram of each other.
     */
    char first1[] = "";
    char second1[] = "";
    assert(true == if_two_strings_are_anagrams_v1(first1, second1));
    assert(true == if_two_strings_are_anagrams_v2(first1, second1));
    assert(true == if_two_strings_are_anagrams_v3(first1, second1));

    /*
     * Test 2: If both the strings are of unequal length, then the strings
     *         are not anagram of each other.
     */
    char first2[] = "ats";
    char second2[] = "cats";
    assert(false == if_two_strings_are_anagrams_v1(first2, second2));
    assert(false == if_two_strings_are_anagrams_v2(first2, second2));
    assert(false == if_two_strings_are_anagrams_v3(first2, second2));

    /*
     * Test 3: If both the strings are of equal length and have the same
     *         set of characters, then the strings are anagram of each other.
     */
    char first3[] = "dats";
    char second3[] = "adts";
    assert(true == if_two_strings_are_anagrams_v1(first3, second3));
    assert(true == if_two_strings_are_anagrams_v2(first3, second3));
    assert(true == if_two_strings_are_anagrams_v3(first3, second3));

    /*
     * Test 4: If both the strings are of equal length but have different
     *         set of characters, then the strings are not anagram of each
     *         other.
     */
    char first4[] = "cats";
    char second4[] = "yats";
    assert(false == if_two_strings_are_anagrams_v1(first4, second4));
    assert(false == if_two_strings_are_anagrams_v2(first4, second4));
    assert(false == if_two_strings_are_anagrams_v3(first4, second4));

    /*
     * Test 5: If both the strings are of equal length and have the same
     *         set of characters multiple times, then the strings are anagram
     *         of each other.
     */
    char first5[] = "ddattttss";
    char second5[] = "ssttttadd";
    assert(true == if_two_strings_are_anagrams_v1(first5, second5));
    assert(true == if_two_strings_are_anagrams_v2(first5, second5));
    assert(true == if_two_strings_are_anagrams_v3(first5, second5));

    return(0);
}
