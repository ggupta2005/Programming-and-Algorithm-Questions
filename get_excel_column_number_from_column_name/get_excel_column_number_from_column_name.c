/*
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 *
 *   A -> 1
 *   B -> 2
 *   C -> 3
 *   ...
 *   Z -> 26
 *   AA -> 27
 *   AB -> 28
 */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>

/*
 * This function returns the one based position of a lower case character.
 * If the input character is not a lower case character, then this function
 * returns zero.
 */
int lowercase_position (char ch)
{
    if ((ch >= 'a') && (ch <= 'z')) {

        /*
         * If the input character is lower case, then return its one
         * based index w.r.t to 'a'.
         */
        return(ch - 'a' + 1);
    }

    return(0);
}

/*
 * This function returns the one based position of a upper case character.
 * If the input character is not a upper case character, then this function
 * returns zero.
 */
int uppercase_position (char ch)
{
    if ((ch >= 'A') && (ch <= 'Z')) {

        /*
         * If the input character is lower case, then return its one
         * based index w.r.t to 'A'.
         */
        return(ch - 'A' + 1);
    }

    return(0);
}

/*
 * This function returns the column number corresponding to the excel
 * column name. If the input string is not valid or it doesn't have
 * alphabetical characters, then this function returns zero. The time
 * complexity of this function is O(n), where 'n' is the number of
 * characters in the column name. The space complexity of this function
 * is O(1).
 */
int get_excel_col_number_from_col_name(char* s)
{
    int col_num;
    int len, index;

    /*
     * If the input string is NULL or empty, then return zero
     */
    if (!s || !strlen(s)) {
        return(0);
    }

    len = strlen(s);

    /*
     * Check if any of the characters in the input string are not
     * alphabetical. If so, return zero.
     */
    for (index = 0; index < len; ++index) {
        if (!isalpha(s[index])) {
            return(0);
        }
    }

    /*
     * Iterate over the column name string and compute the column
     * name for the column name.
     */
    col_num = 0;
    for (index = 0; index < len; ++index) {

        /*
         * Multiply the previous value of column name by 26 and add
         * the one based index position of the current character. Use
         * both upper case and lower case one based index functions as
         * the column name can be a combination of upper or lower case
         * alphabets.
         */
        col_num = col_num * 26 + lowercase_position(s[index])
                               + uppercase_position(s[index]);
    }

    /*
     * Return the computed column number
     */
    return(col_num);
}

int main ()
{
    /*
     * Test 0: Test with NULL column name string or empty string.
     *         The column number should be zero.
     */
    assert(0 == get_excel_col_number_from_col_name(NULL));
    assert(0 == get_excel_col_number_from_col_name(""));

    /*
     * Test 1: Test with non-alphabetical characters in the column
     *         name string. The column number should be zero.
     */
    assert(0 == get_excel_col_number_from_col_name("654Z@"));

    /*
     * Test 2: Test with one alphabetical character in the column name
     *         string. The column number should be equal to the one
     *         based index position of the letter. Test with both upper
     *         and lower case letters.
     */
    assert(1 == get_excel_col_number_from_col_name("A"));
    assert(1 == get_excel_col_number_from_col_name("a"));
    assert(2 == get_excel_col_number_from_col_name("B"));
    assert(2 == get_excel_col_number_from_col_name("b"));
    assert(26 == get_excel_col_number_from_col_name("z"));
    assert(26 == get_excel_col_number_from_col_name("Z"));

    /*
     * Test 3: Test with more than one letter in the column name. Also
     *         test with combination of upper case and lower case
     *         characters.
     */
    assert(27 == get_excel_col_number_from_col_name("AA"));
    assert(27 == get_excel_col_number_from_col_name("Aa"));
    assert(28 == get_excel_col_number_from_col_name("Ab"));
    assert(28 == get_excel_col_number_from_col_name("ab"));
    assert(52 == get_excel_col_number_from_col_name("Az"));
    assert(52 == get_excel_col_number_from_col_name("AZ"));
    assert(702 == get_excel_col_number_from_col_name("ZZ"));
    assert(702 == get_excel_col_number_from_col_name("zz"));

    return(0);
}

