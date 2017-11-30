/*
 * This program adds two binary numbers represented as strings.
 * More information can be found at the following link:-
 * http://www.geeksforgeeks.org/add-two-bit-strings/
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char* add_two_binary_numbers_represented_as_string (char* bin_num1,
                                                    char* bin_num2)
{
    char* result;
    int len1, len2, result_len, index1, index2, result_index;
    char carry, rem;

    if (!bin_num1 && !bin_num2) {
        return(NULL);
    }

    if (!strlen(bin_num1) && !strlen(bin_num2)) {
        return(NULL);
    }

    if (!bin_num2 || !strlen(bin_num2)) {
        len1 = strlen(bin_num1);
        len2 = 0;
    } else if (!bin_num1 || !strlen(bin_num1)) {
        len2 = strlen(bin_num2);
        len1 = 0;
    } else {
        len1 = strlen(bin_num1);
        len2 = strlen(bin_num2);
    }

    result_len = (len1 > len2) ? (len1 + 1) : (len2 + 1);
    result = (char*)malloc(sizeof(char) * (result_len + 1));

    printf("result_len = %d\n", result_len);

    if (!result) {
        return(NULL);
    }

    memset(result, 0, sizeof(char) * (result_len + 1));

    index1 = len1 - 1;
    index2 = len2 - 1;
    result_index = result_len;
    carry = '0';
    rem = '0';
    while ((index1 >= 0) && (index2 >= 0)) {
        rem = '0' + ((bin_num1[index1] - '0') +
                     (bin_num2[index2] - '0') +
                     (carry - '0')) % 2;

        carry = '0' + ((bin_num1[index1] - '0') +
                       (bin_num2[index2] - '0') +
                       (carry - '0')) / 2;

        result[result_index] = rem;
        --result_index;
        --index1;
        --index2;
    }

    while (index1 >= 0) {
        rem = '0' + ((bin_num1[index1] - '0') +
                     (carry - '0')) % 2;

        carry = '0' + ((bin_num1[index1] - '0') +
                       (carry - '0')) / 2;

        result[result_index] = rem;
        --result_index;
        --index1;
    }

    while (index2 >= 0) {
        rem = '0' + ((bin_num2[index2] - '0') +
                     (carry - '0')) % 2;

        carry = '0' + ((bin_num2[index2] - '0') +
                       (carry - '0')) / 2;

        result[result_index] = rem;
        --result_index;
        --index2;
    }

    result[result_index] = carry;

    if (result[0] == '0') {
        for (result_index = 1; result_index <= result_len; ++result_index) {
            result[result_index - 1] = result[result_index];
        }
    }

    return(result);
}

int main ()
{
    /*
     * Test 0:
     */
    char* num1 = "10010000";
    char* num2 = "10010000";
    //char* num2 = NULL;
    char* exp_num1 = "10011001";
    char* actual_num1 = add_two_binary_numbers_represented_as_string(num1, num2);
    printf("expected = %s\n", exp_num1);
    printf("actual = %s\n", actual_num1);
    assert(0 == strcmp(exp_num1, actual_num1));

    return(0);
}
