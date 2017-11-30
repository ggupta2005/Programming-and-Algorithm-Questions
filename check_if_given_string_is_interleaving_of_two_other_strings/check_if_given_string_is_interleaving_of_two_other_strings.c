/*
 * This program checks if a given string C is an interleaving of two other
 * strings (A, B). C is said to be interleaving A and B, if it contains
 * all characters of A and B and order of all characters in individual
 * strings is preserved. For more information on this problem, please refer
 * to the following link:-
 * http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings/
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

bool check_if_given_str_is_interleaving_of_two_other_strs
                                        (char* A, char* B, char* C)
{
    int len_c, len_a, len_b;
    int index_a, index_b, index_c;

    if (!A) {
        len_a = 0;
    } else {
        len_a = strlen(A);
    }

    if (!B) {
        len_b = 0;
    } else {
        len_b = strlen(B);
    }

    if (!C) {
        len_c = 0;
    } else {
        len_c = strlen(C);
    }

    index_a = 0;
    index_b = 0;
    index_c = 0;

    while ((index_a < len_a) && (index_b < len_b)
           && (index_c < len_c)) {

        if (A[index_a] == C[index_c]) {
            ++index_a;
            ++index_c;
        } else if (B[index_b] == C[index_c]) {
            ++index_b;
            ++index_c;
        } else {
            return(false);
        }
    }

    while ((index_a < len_a) && (index_c < len_c)) {
        if (A[index_a] == C[index_c]) {
            ++index_a;
            ++index_c;
        } else {
            return(false);
        }
    }

    while ((index_b < len_b) && (index_c < len_c)) {
        if (B[index_b] == C[index_c]) {
            ++index_b;
            ++index_c;
        } else {
            return(false);
        }
    }

    if ((index_a < len_a) || (index_b < len_b) ||
        (index_c < len_c)) {
        return(false);
    }

    return(true);
}

int main ()
{
    char* A0 = NULL;
    char* B0 = NULL;
    char* C0 = NULL;
    assert(true ==
            check_if_given_str_is_interleaving_of_two_other_strs(A0, B0, C0));

    char* A1 = "AABC";
    char* B1 = NULL;
    char* C1 = "AABC";
    assert(true ==
            check_if_given_str_is_interleaving_of_two_other_strs(A1, B1, C1));
    assert(true ==
            check_if_given_str_is_interleaving_of_two_other_strs(B1, A1, C1));

    char* A2 = "AABC";
    char* B2 = NULL;
    char* C2 = "BCAA";
    assert(false ==
            check_if_given_str_is_interleaving_of_two_other_strs(A2, B2, C2));
    assert(false ==
            check_if_given_str_is_interleaving_of_two_other_strs(B2, A2, C2));

    char* A3 = "AABC";
    char* B3 = NULL;
    char* C3 = "AAB";
    assert(false ==
            check_if_given_str_is_interleaving_of_two_other_strs(A3, B3, C3));
    assert(false ==
            check_if_given_str_is_interleaving_of_two_other_strs(B3, A3, C3));

    char* A4 = "AAB";
    char* B4 = NULL;
    char* C4 = "AABC";
    assert(false ==
            check_if_given_str_is_interleaving_of_two_other_strs(A4, B4, C4));
    assert(false ==
            check_if_given_str_is_interleaving_of_two_other_strs(B4, A4, C4));

    char* A5 = "AAB";
    char* B5 = "BBCD";
    char* C5 = "ABABCDB";
    assert(true ==
            check_if_given_str_is_interleaving_of_two_other_strs(A5, B5, C5));
    assert(true ==
            check_if_given_str_is_interleaving_of_two_other_strs(B5, A5, C5));

    char* A6 = "AAB";
    char* B6 = "BBCD";
    char* C6 = "AABBBCD";
    assert(true ==
            check_if_given_str_is_interleaving_of_two_other_strs(A6, B6, C6));
    assert(true ==
            check_if_given_str_is_interleaving_of_two_other_strs(B6, A6, C6));

    return(0);
}
