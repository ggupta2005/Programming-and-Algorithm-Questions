/*
 * MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA,
 * BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”,
 * column 2 as “B”, column 27 as “AA”. More information on this can be found
 * on this post:-http://www.geeksforgeeks.org/find-excel-column-name-given-number/
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define MAX_LEN 20

/*
 * This function reverses a character string. The time complexity of
 * this function is O(n) and the space complexity of this function
 * is O(1).
 */
void reverse_str (char* ch)
{
    int left, right;

    /*
     * If the character array is NULL or its length is zero,
     * then return from this function.
     */
    if (!ch || !strlen(ch)) {
        return;
    }

    /*
     * Set left to zero
     */
    left = 0;

    /*
     * Set right to the last charater in the string
     */
    right = strlen(ch) - 1;

    /*
     * Iterate until left index is less than right index
     */
    while (left < right) {

        /*
         * If left indexed character is not same as the
         * right indexed character, then swap the characters
         * using the xor operator.
         */
        if (ch[left] != ch[right]) {

            ch[left] ^= ch[right];
            ch[right] ^= ch[left];
            ch[left] ^= ch[right];
        }

        /*
         * Increment the left index
         */
        ++left;

        /*
         * Decrement the right index
         */
        --right;
    }
}

/*
 * This function returns the excel column name for a given column number.
 * If the input number is not valid, then this function returns an empty
 * string.
 */
char* get_excel_col_name_from_excel_col_num (int num)
{
    char* col_name = NULL;
    int len, index, char_index;

    /*
     * Allocate character array to store the excel column name
     */
    col_name = (char*)malloc(sizeof(char) * MAX_LEN);

    /*
     * If the memory allocaion fails, then this function returns
     * NULL
     */
    if (!col_name) {
        return(NULL);
    }

    /*
     * Clear the allocated memory
     */
    memset(col_name, 0, sizeof(char) * MAX_LEN);

    /*
     * If the input column number is less than or equal to zero,
     * then return an empty string
     */
    if (num <= 0) {
        return(col_name);
    }

    /*
     * Iterate until 'num' is greater than zero
     */
    index = 0;
    while (num > 0) {

        /*
         * Obtain the character index using the modulus
         * operator
         */
        char_index = num % 26;

        /*
         * If the modulus operation results in zero, then
         * set character index to 26 (for character 'Z')
         */
        if (char_index == 0) {
            char_index = 26;
        }

        /*
         * Set the character in the column name
         */
        col_name[index] = 'A' + char_index - 1;
        ++index;

        /*
         * Subtract the character index from input column
         * number
         */
        num -= char_index;

        /*
         * Divide the remaining column number by 26
         */
        num /= 26;
    }

    /*
     * Since the column name characters are added in reverse order,
     * so reverse the column name
     */
    reverse_str(col_name);

    /*
     * Return the column name
     */
    return(col_name);
}

int main ()
{
    /*
     * Test 0: Test with invalid column numbers. The column number
     *         should be empty.
     */
    assert(!strcmp("",get_excel_col_name_from_excel_col_num(-52)));
    assert(!strcmp("",get_excel_col_name_from_excel_col_num(0)));

    /*
     * Test 1: Test with column number less than or equal to 26. The
     *         column should be 'A', 'B' and so on.
     */
    assert(!strcmp("A",get_excel_col_name_from_excel_col_num(1)));
    assert(!strcmp("B",get_excel_col_name_from_excel_col_num(2)));
    assert(!strcmp("Z",get_excel_col_name_from_excel_col_num(26)));

    /*
     * Test 2: Test with column number which will return column name
     *         of more than two letters.
     */
    assert(!strcmp("AA",get_excel_col_name_from_excel_col_num(27)));
    assert(!strcmp("AZ",get_excel_col_name_from_excel_col_num(52)));
    assert(!strcmp("ZZ",get_excel_col_name_from_excel_col_num(702)));

    return(0);
}
