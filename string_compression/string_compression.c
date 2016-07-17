/*
 * This program compresses the string in the following manner:-
 * string "aaabbbbcccaaa" -> "a3b4c3a3"
 * string "abcdeeeeeeeee" -> "a1b1c1d1e9"
 * If the compresses string's length is greater than the original
 * string, then the program returns the string itself.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

/*
 * This function returns the number of digits in a number
 * which is greater than or equal to zero. If the number is
 * less than zero, this function returns zero.
 */
int count_digits (int num)
{
    int count = 0;

    if (num < 0) {
        return(0);
    }

    /*
     * While number is not zero, continue counting the
     * the digits
     */
    while (num) {
        num = num/10;
        ++count;
    }

    return(count);
}

/*
 * This function converts an integer number which is greater than
 * or equal to zero to a string. If the number is less than zero,
 * then this function returns NULL. The caller of this function
 * is responsible to free the memory allocated by this function.
 */
char* ntoa (int num)
{
    char* ch;
    int digits, rem;
    int i;

    /*
     * If the number is less than, return NULL
     */
    if (num < 0) {
        return(NULL);
    }

    /*
     * Count the number of digits in the number
     */
    digits = count_digits(num);

    /*
     * If the number of digits in the number are zero, then return
     * NULL.
     */
    if (digits == 0) {
        return(NULL);
    }

    /*
     * Allocate a character array to store the string converted
     * number.
     */
    ch = (char*)malloc(sizeof(char) * (digits + 1));

    /*
     * If the allocation fails, then return NULL
     */
    if (!ch) {
        return(NULL);
    }

    memset(ch, 0, sizeof(char) * (digits + 1));

    /*
     * Iterate until the number is zero and add the character
     * digits into the array
     */
    i = digits - 1;
    while (i >= 0) {

        rem = num % 10;
        num /= 10;

        ch[i] = '0' + rem;
        --i;
    }

    /*
     * Return the string version of the number.
     */
    return(ch);
}

/*
 * This function compresses a given character string and returns the
 * compressed string. The time complexity of this function is O(n),
 * where 'n' is the number of characters in the character string.
 */
char* string_compression (char* ch)
{
    char* result = NULL, len;
    int i, count, j, k;
    char* count_to_str;

    /*
     * If the character string is NULL or its length is zero, then
     * Return NULL
     */
    if (!ch || !strlen(ch)) {
        return(NULL);
    }

    len = strlen(ch);

    /*
     * The length of the compressed string can be twice as long the
     * input string. So allocate a separate memory for the compressed
     * string
     */
    result = (char*)malloc(sizeof(char) * (2 * len + 1));

    /*
     * If the string allocation fail, then return NULL.
     */
    if (!result) {
        return(NULL);
    }

    memset(result, 0, sizeof(char) * (2 * len + 1));

    /*
     * Iterate through the string and do the following:-
     * Compare the current character with the next character
     * If both are same, then increment the 'count'. Otherwise
     * add the current character into the buffer and convert the
     * 'count' into a string and add the numbered string into the
     * buffer.
     */
    i = 0;
    count = 1;
    j = 0;
    while (i < (len - 1)) {
        if (ch[i] == ch[i+1]) {
            /*
             * Since the current character and the next character are
             * same, so increment 'count'.
             */
            ++count;
        } else {
            /*
             * Add the current character into the return buffer
             */
            result[j] = ch[i];
            ++j;

            /*
             * Convert the 'count' into string
             */
            count_to_str = ntoa(count);

            /*
             * Add the numbered string to the return buffer.
             */
            if (count_to_str) {
                k = 0;
                while (count_to_str[k]) {
                    result[j] = count_to_str[k];
                    ++j; ++k;
                }

                /*
                 * Free the numbered string
                 */
                free(count_to_str);
            }

            /*
             * Reset count to maintain loop invariance
             */
            count = 1;
        }

        /*
         * Increment the index into the character string
         */
        ++i;
    }

    /*
     * Since we iterated through the second last character in the
     * string, add the last character and its count to the return
     * buffer.
     */
    result[j] = ch[i];
    ++j;

    count_to_str = ntoa(count);

    if (count_to_str) {
        k = 0;
        while (count_to_str[k]) {
            result[j] = count_to_str[k];
            ++j; ++k;
        }
        free(count_to_str);
    }

    /*
     * If the length of the input string is less than the return
     * string, then return the pointer to the input string.
     */
    if (strlen(ch) <= strlen(result)) {
        free(result);
        return(ch);
    }

    /*
     * Return the compressed string
     */
    return(result);
}

int main ()
{
    /*
     * Test 1: Test a string which can be compressed
     */
    char* str1 = "aaaabbbcccd";
    char* expected_str1 = "a4b3c3d1";
    char* actual_str1 = string_compression(str1);
    assert(0 == strcmp(expected_str1, actual_str1));

    /*
     * Test 2: Test a string which has only one character
     */
    char* str2 = "aaaaaaaaaa";
    char* expected_str2 = "a10";
    char* actual_str2 = string_compression(str2);
    assert(0 == strcmp(expected_str2, actual_str2));

    /*
     * Test 3: Test a string for which compression will give
     *         string larger than the original string
     */
    char* str3 = "abcde";
    char* expected_str3 = "abcde";
    char* actual_str3 = string_compression(str3);
    assert(0 == strcmp(expected_str3, actual_str3));

    /*
     * Test 4: Test a string which is NULL
     */
    char* str4 = NULL;
    char* expected_str4 = NULL;
    char* actual_str4 = string_compression(str4);
    assert(expected_str4 == actual_str4);

    /*
     * Test 5: Test a string which has only one character
     */
    char* str5 = "a";
    char* expected_str5 = "a";
    char* actual_str5 = string_compression(str5);
    assert(0 == strcmp(expected_str5, actual_str5));

    /*
     * Test 6: Test a string whose length is zero
     */
    char* str6 = "";
    char* expected_str6 = NULL;
    char* actual_str6 = string_compression(str6);
    assert(expected_str6 == actual_str6);

    /*
     * Test 7: Test a case in which all characters have same
     *         number of contigous characters
     */
    char* str7 = "aaaa....,,,,yyyy////$$$$))))";
    char* expected_str7 = "a4.4,4y4/4$4)4";
    char* actual_str7 = string_compression(str7);
    assert(0 == strcmp(expected_str7, actual_str7));

    return(0);
}
