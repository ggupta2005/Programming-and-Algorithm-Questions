/*
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include<ctype.h>

bool if_alphabet_same (char a, char b)
{
    int a_index;
    int b_index;

    if ((a >= 'a') && (a <= 'z')) {
        a_index = a - 'a';
    } else if ((a >= 'A') && (a <= 'Z')) {
        a_index = a - 'A';
    } else {
        return(false);
    }

    if ((b >= 'a') && (b <= 'z')) {
        b_index = b - 'a';
    } else if ((b >= 'A') && (b <= 'Z')) {
        b_index = b - 'A';
    } else {
        return(false);
    }

    return(a_index == b_index);
}

bool if_digit_same (char a, char b)
{
    int a_index;
    int b_index;

    if ((a >= '0') && (a <= '9')) {
        a_index = a - '0';
    } else {
        return(false);
    }

    if ((b >= '0') && (b <= '9')) {
        b_index = b - '0';
    } else {
        return(false);
    }

    return(a_index == b_index);
}

bool find_if_string_is_valid_palindrome (char* ch)
{
    int left, len, right;

    if (!ch) {
        return(false);
    }

    if (!strlen(ch)) {
        return(true);
    }

    left = 0;
    right = strlen(ch) - 1;

    while (left < right) {
        if (!isalpha(ch[left]) && !isdigit(ch[left])) {
            ++left;
            continue;
        }

        if (!isalpha(ch[right]) && !isdigit(ch[right])) {
            --right;
            continue;
        }

        if (!if_alphabet_same(ch[left], ch[right]) &&
            !if_digit_same(ch[left], ch[right])) {
            return(false);
        }

        ++left;
        --right;
    }

    return(true);
}

int main ()
{
    char* ch0 = "A man, a plan, a canal: Panama";
    assert(true == find_if_string_is_valid_palindrome(ch0));

    char* ch1 = "race a car";
    assert(false == find_if_string_is_valid_palindrome(ch1));

    char* ch2 = "7888887";
    assert(true == find_if_string_is_valid_palindrome(ch2));

    char* ch3 = "0P";
    assert(false == find_if_string_is_valid_palindrome(ch3));

    return(0);
}

