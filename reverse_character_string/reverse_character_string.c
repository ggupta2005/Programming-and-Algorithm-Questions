/*
 * This porgram reverses a character string. For example if the input
 * string is "armed", then the reversed string should be "demra".
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>

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

int main ()
{
    /*
     * Test 0: Test with the NULL string. The test string should
     *         remain NULL.
     */
    char* ch0 = NULL;
    char* exp0 = NULL;
    reverse_str(ch0);
    assert(ch0 == exp0);

    /*
     * Test 1: Test with an empty string. The test string should
     *         remain empty.
     */
    char ch1[] = "";
    char exp1[] = "";
    reverse_str(ch1);
    assert(strcmp(ch1, exp1) == 0);

    /*
     * Test 2: Test with a string having only one character. The test
     *         string should remain unchanged.
     */
    char ch2[] = "a";
    char exp2[] = "a";
    reverse_str(ch2);
    assert(strcmp(ch2, exp2) == 0);

    /*
     * Test 3: Test with a string having only one character type of
     *         character. The test string should remain unchanged.
     */
    char ch3[] = "aaa";
    char exp3[] = "aaa";
    reverse_str(ch3);
    assert(strcmp(ch3, exp3) == 0);

    /*
     * Test 4: Test with a string having different alphabetical characters.
     *         This string should get reversed.
     */
    char ch4[] = "armed";
    char exp4[] = "demra";
    reverse_str(ch4);
    assert(strcmp(ch4, exp4) == 0);

    /*
     * Test 5: Test with a string having different alphabetical characters
     *         and spaces. This string should get reversed.
     */
    char ch5[] = "armed forces";
    char exp5[] = "secrof demra";
    reverse_str(ch5);
    assert(strcmp(ch5, exp5) == 0);

    /*
     * Test 6: Test with a string having different special characters and
     *         digits. This string should get reversed.
     */
    char ch6[] = "@%^894!%";
    char exp6[] = "%!498^%@";
    reverse_str(ch6);
    assert(strcmp(ch6, exp6) == 0);

    /*
     * Test 7: Test with a string which is a palindrome. The string should
     *         not get reversed.
     */
    char ch7[] = "radar";
    char exp7[] = "radar";
    reverse_str(ch7);
    assert(strcmp(ch7, exp7) == 0);

    return(0);
}
