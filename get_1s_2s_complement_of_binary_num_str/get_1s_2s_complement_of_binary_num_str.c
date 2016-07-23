/*
 * This program allows to get the 1s-complement and 2s-complement
 * for a binary numbered string. More information on this can be
 * found on the following link:-
 * http://www.geeksforgeeks.org/1s-2s-complement-binary-number/
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

/*
 * This function checks if the given number string has only
 * binary character symbols '0' and '1'. If the string comprises
 * of any other characters, then this function returns 'false'
 * otherwise this function returns 'true'. The time complexity of
 * this function is O(n), where 'n' is the number of characters
 * in the number string.
 */
bool check_if_string_is_binary (char* bin_num)
{
    int len, i;

    /*
     * If the number string is NULL or has zero length,
     * then return 'false'.
     */
    if (!bin_num || !strlen(bin_num)) {
        return(false);
    }

    i = 0;
    while (bin_num[i]) {

        /*
         * If the character symbol is not one of '0' or '1', then
         * return 'false' from this function
         */
        if ((bin_num[i] != '0') && (bin_num[i] != '1')) {
            return(false);
        }

        ++i;
    }

    /*
     * Return 'true' in case this is binary string
     */
    return(true);
}

/*
 * This function returns a 1s complement string for the binary
 * number string. The time complexity of this function is O(n),
 * where 'n' is the number of characters in the number string.
 */
char* get_1s_complement_for_binary_number_str (char* bin_num)
{
    int len, i;
    char* ones_complement;

    /*
     * If the number string is NULL or has zero length,
     * then return NULL
     */
    if (!bin_num || !strlen(bin_num)) {
        return(NULL);
    }

    /*
     * If the number string doesn't contain binary symbols,
     * then return NULL
     */
    if (!check_if_string_is_binary(bin_num)) {
        return(NULL);
    }

    len = strlen(bin_num);

    /*
     * Allocate buffer space for ones complement string
     */
    ones_complement = (char*)malloc(sizeof(char) * (len + 1));

    /*
     * If the allocated string is NULL, then return NULL
     * from this function
     */
    if (!ones_complement) {
        return(NULL);
    }

    memset(ones_complement, 0, sizeof(char) * (len + 1));

    /*
     * Walk the binary string backwards and compute the ones
     * complement
     */
    for (i = len-1; i >= 0; --i) {
        /*
         * If the character is '0' in the binary string,
         * then add '1' in the ones complement string otherwise
         * add '0'
         */
        if (bin_num[i] == '0') {
            ones_complement[i] = '1';
        } else {
            ones_complement[i] = '0';
        }
    }

    /*
     * Return the ones complement string
     */
    return(ones_complement);
}

/*
 * This function returns a 2s complement string for the binary
 * number string. The time complexity of this function is O(n),
 * where 'n' is the number of characters in the number string.
 */
char* get_2s_complement_for_binary_number_str (char* bin_num)
{
    int len, i;
    char* twos_complement;
    char* ones_complement;
    char carry;

    /*
     * If the number string is NULL or has zero length,
     * then return NULL
     */
    if (!bin_num || !strlen(bin_num)) {
        return(NULL);
    }

    /*
     * If the number string doesn't contain binary symbols,
     * then return NULL
     */
    if (!check_if_string_is_binary(bin_num)) {
        return(NULL);
    }

    /*
     * Get the ones complement for binary number string
     */
    ones_complement = get_1s_complement_for_binary_number_str(bin_num);

    /*
     * If getting the ones complement fails, then return NULL from
     * the function
     */
    if (!ones_complement) {
        return(NULL);
    }

    len = strlen(bin_num);

    /*
     * Allocate buffer space for twos complement string
     */
    twos_complement = (char*)malloc(sizeof(char) * (len + 1));

    /*
     * If the allocated string is NULL, then return NULL
     * from this function
     */
    if (!twos_complement) {

        /*
         * Free the ones complement string before returning from this
         * this function
         */
        free(ones_complement);
        return(NULL);
    }

    memset(twos_complement, 0, sizeof(char) * (len + 1));

    /*
     * Walk the binary string backwards and compute the twos
     * complement. The carry is set to one because we need to
     * add one to ones complement
     */
    carry = '1';
    for (i = len - 1; i >= 0; --i) {

        /*
         * Take the xor of carry and ones complement string
         * and store in twos complement string
         */
        twos_complement[i] = '0'+ ((ones_complement[i] - '0') ^
                                   (carry - '0'));

        /*
         * Set the 'carry' as and operation of ones complement
         * and carry
         */
        carry = '0' + ((ones_complement[i] - '0') & (carry - '0'));
    }

    /*
     * Free ones complement string
     */
    free(ones_complement);

    /*
     * Return the twos complement string
     */
    return(twos_complement);
}

int main ()
{
    /*
     * Test 0: Test a 1s and 2s complement for a positive number
     *         binary string
     */
    char* bin_num0 = "0101";
    char* exp_1s_com0 = "1010";
    char* exp_2s_com0 = "1011";
    char* act_1s_com0 = get_1s_complement_for_binary_number_str(bin_num0);
    char* act_2s_com0 = get_2s_complement_for_binary_number_str(bin_num0);
    assert(0 == strcmp(exp_1s_com0, act_1s_com0));
    assert(0 == strcmp(exp_2s_com0, act_2s_com0));

    /*
     * Test 1: Test a 1s and 2s complement for another positive number
     *         binary string
     */
    char* bin_num1 = "00111111";
    char* exp_1s_com1 = "11000000";
    char* exp_2s_com1 = "11000001";
    char* act_1s_com1 = get_1s_complement_for_binary_number_str(bin_num1);
    char* act_2s_com1 = get_2s_complement_for_binary_number_str(bin_num1);
    assert(0 == strcmp(exp_1s_com1, act_1s_com1));
    assert(0 == strcmp(exp_2s_com1, act_2s_com1));

    /*
     * Test 2: Test a 1s and 2s complement for a non-binary number
     *         string
     */
    char* bin_num2 = "21111111";
    char* exp_1s_com2 = NULL;
    char* exp_2s_com2 = NULL;
    char* act_1s_com2 = get_1s_complement_for_binary_number_str(bin_num2);
    char* act_2s_com2 = get_2s_complement_for_binary_number_str(bin_num2);
    assert(exp_1s_com2 == act_1s_com2);
    assert(exp_2s_com2 == act_2s_com2);

    /*
     * Test 3: Test a 1s and 2s complement for NULL binary number
     *         string
     */
    char* bin_num3 = NULL;
    char* exp_1s_com3 = NULL;
    char* exp_2s_com3 = NULL;
    char* act_1s_com3 = get_1s_complement_for_binary_number_str(bin_num3);
    char* act_2s_com3 = get_2s_complement_for_binary_number_str(bin_num3);
    assert(exp_1s_com3 == act_1s_com3);
    assert(exp_2s_com3 == act_2s_com3);

    /*
     * Test 4: Test a 1s and 2s complement for an empty binary number
     *         string
     */
    char* bin_num4 = "";
    char* exp_1s_com4 = NULL;
    char* exp_2s_com4 = NULL;
    char* act_1s_com4 = get_1s_complement_for_binary_number_str(bin_num4);
    char* act_2s_com4 = get_2s_complement_for_binary_number_str(bin_num4);
    assert(exp_1s_com4 == act_1s_com4);
    assert(exp_2s_com4 == act_2s_com4);

    return(0);
}
