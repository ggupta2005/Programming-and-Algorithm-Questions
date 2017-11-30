/*
 * This program compares the two number strings numerically.
 * For example, the number string "98765" is numerically lesser
 * than "12346789".
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

#define FIRST_IS_LARGER     1
#define SECOND_IS_LARGER   -1
#define BOTH_ARE_EQUAL      0

int cmp_two_number_strings_numerically (char* num1,
                                        char* num2)
{
    int index2, len1, len2, index1;
    bool if_first_valid, if_second_valid;

    if (!num1 && !num2) {
        return(BOTH_ARE_EQUAL);
    }

    if (num1 && !num2) {
        return(FIRST_IS_LARGER);
    }

    if (!num1 && num2) {
        return(SECOND_IS_LARGER);
    }

    if(!strlen(num1) && !strlen(num2)) {
        return(BOTH_ARE_EQUAL);
    }

    len1 = strlen(num1);
    len2 = strlen(num2);

    if_first_valid = true;
    for (index1 = 0; index1 < len1; ++index1) {
        if (!isdigit(num1[index1])) {
            if_first_valid = false;
            break;
        }
    }

    if_second_valid = true;
    for (index2 = 0; index2 < len2; ++index2) {
        if (!isdigit(num2[index2])) {
            if_second_valid = false;
            break;
        }
    }

    if (!if_first_valid && !if_second_valid) {
        return(BOTH_ARE_EQUAL);
    }

    if (if_first_valid && !if_second_valid) {
        return(FIRST_IS_LARGER);
    }

    if (!if_first_valid && if_second_valid) {
        return(SECOND_IS_LARGER);
    }

    index1 = 0;
    while (index1 < len1) {
        if (num1[index1] != '0') {
            break;
        }

        ++index1;
    }

    index2 = 0;
    while (index2 < len2) {
        if (num2[index2] != '0') {
            break;
        }

        ++index2;
    }

    if ((index1 == len1) && (index2 == len2)) {
        return(BOTH_ARE_EQUAL);
    }

    if ((index1 < len1) && (index2 == len2)) {
        return(FIRST_IS_LARGER);
    }

    if ((index1 == len1) && (index2 < len2)) {
        return(SECOND_IS_LARGER);
    }

    while ((index1 < len1) && (index2 < len2)) {

        if (num1[index1] > num2[index2]) {
            return(FIRST_IS_LARGER);
        } else if (num1[index1] < num2[index2]) {
            return(SECOND_IS_LARGER);
        }

        ++index1;
        ++index2;
    }

    if ((index1 < len1) && (index2 == len2)) {
        return(FIRST_IS_LARGER);
    }

    if ((index1 == len1) && (index2 < len2)) {
        return(SECOND_IS_LARGER);
    }

    return(BOTH_ARE_EQUAL);
}

int main ()
{
    assert(BOTH_ARE_EQUAL ==
            cmp_two_number_strings_numerically(NULL, NULL));
    assert(FIRST_IS_LARGER ==
            cmp_two_number_strings_numerically("123", NULL));
    assert(SECOND_IS_LARGER ==
            cmp_two_number_strings_numerically(NULL, "123"));

    assert(BOTH_ARE_EQUAL ==
            cmp_two_number_strings_numerically("", ""));

    assert(BOTH_ARE_EQUAL ==
            cmp_two_number_strings_numerically("jhfkjh1211217",
                                               "1hfsdkjfhsd23"));
    assert(FIRST_IS_LARGER ==
            cmp_two_number_strings_numerically("1234567890",
                                               "1hfsdkjfhsd23"));
    assert(SECOND_IS_LARGER ==
            cmp_two_number_strings_numerically("1hfsdkjfhsd23",
                                               "1234567890"));

    assert(BOTH_ARE_EQUAL ==
            cmp_two_number_strings_numerically("0000000",
                                               "0000"));
    assert(FIRST_IS_LARGER ==
            cmp_two_number_strings_numerically("00000001",
                                               "0000"));
    assert(SECOND_IS_LARGER ==
            cmp_two_number_strings_numerically("0000000",
                                               "0001"));
    assert(BOTH_ARE_EQUAL ==
            cmp_two_number_strings_numerically("00000001",
                                               "0001"));

    assert(BOTH_ARE_EQUAL ==
            cmp_two_number_strings_numerically("0000000123000",
                                               "00123000"));
    assert(FIRST_IS_LARGER ==
            cmp_two_number_strings_numerically("0000000124000",
                                               "00123000"));
    assert(SECOND_IS_LARGER ==
            cmp_two_number_strings_numerically("0000000123000",
                                               "00124000"));


    assert(BOTH_ARE_EQUAL ==
            cmp_two_number_strings_numerically("1239",
                                               "1239"));
    assert(FIRST_IS_LARGER ==
            cmp_two_number_strings_numerically("1243",
                                               "124"));
    assert(SECOND_IS_LARGER ==
            cmp_two_number_strings_numerically("123",
                                               "1234"));

    return(0);
}
