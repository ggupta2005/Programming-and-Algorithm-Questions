/*
 * This function reverses the vowels in a string of characters, For example,
 * if the string is "hello", then the reversed string will be "holle"
 */
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

/*
 * This function returns 'true' if a character is a vowel otherwise 
 * this function returns 'false'.
 */
bool if_char_is_vowel (char ch) 
{
    /*
     * If a character is a lower case vowel, then return 'true'
     */
    if ((ch == 'a') || (ch == 'e') || (ch == 'i') ||
        (ch == 'o') || (ch == 'u')) {
        return(true);
    }

    /*
     * If a character is a upper case vowel, then return 'true'
     */
    if ((ch == 'A') || (ch == 'E') || (ch == 'I') ||
        (ch == 'O') || (ch == 'U')) {
        return(true);
    }
    
    /*
     * Since the character is not a lower case vowel or upper 
     * case character, then return 'false'
     */
    return(false);
}

/*
 * This function reverses the vowels in a string. The characters other 
 * than a vowel are left unchanged. The time complexity of this function
 * is O(n) and the space complexity of this function is O(1). 
 */
void reverse_vowels_in_str (char* ch)
{
    int left, right;

    /*
     * If the character string is NULL or its length is zero,
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
         * If the left indexed character is not a vowel,
         * then we do not reverse the position of this
         * character. So move to the next character.
         */
        if (!if_char_is_vowel(ch[left])) {

            /*
             * Increment the left index
             */
            ++left;
            continue;
        }
    
        /*
         * If the right indexed character is not a vowel,
         * then we do not reverse the position of this
         * character. So move to the next character.
         */
        if (!if_char_is_vowel(ch[right])) {

            /*
             * Decrement the right index
             */
            --right;
            continue;
        }

        /*
         * If left indexed vowel is not same as the
         * right indexed vowel, then swap the characters
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
    reverse_vowels_in_str(ch0); 
    assert(ch0 == exp0);

    /*
     * Test 1: Test with an empty string. The test string should
     *         remain empty.
     */
    char ch1[] = "";
    char exp1[] = "";
    reverse_vowels_in_str(ch1); 
    assert(strcmp(ch1, exp1) == 0);

    /*
     * Test 2: Test with a string having two same vowels. The test
     *         string should remain same. 
     */
    char ch2[] = "ee";
    char exp2[] = "ee";
    reverse_vowels_in_str(ch2); 
    assert(strcmp(ch2, exp2) == 0);

    /*
     * Test 3: Test with a string having one vowel. The test
     *         string should remain same. 
     */
    char ch3[] = "I";
    char exp3[] = "I";
    reverse_vowels_in_str(ch3); 
    assert(strcmp(ch3, exp3) == 0);
    
    /*
     * Test 4: Test with a string having mix of vowels and other
     *         characters. The order of vowels should get reversed.
     */
    char ch4[] = "hello";
    char exp4[] = "holle";
    reverse_vowels_in_str(ch4); 
    assert(strcmp(ch4, exp4) == 0);

    /*
     * Test 5: Test with a string having mix of upper case and 
     *         lower case vowels and other characters. The order 
     *         of vowels should get reversed.
     */
    char ch5[] = "hEllo You";
    char exp5[] = "hullo YoE";
    reverse_vowels_in_str(ch5); 
    assert(strcmp(ch5, exp5) == 0);

    /*
     * Test 6: Test with a string having no vowels. The string
     *         should remain the same.
     */
    char ch6[] = "ykljhtf";
    char exp6[] = "ykljhtf";
    reverse_vowels_in_str(ch6); 
    assert(strcmp(ch6, exp6) == 0);

    /*
     * Test 7: Test with a string having one vowel. The string
     *         should remain the same.
     */
    char ch7[] = "yklojhtf";
    char exp7[] = "yklojhtf";
    reverse_vowels_in_str(ch7); 
    assert(strcmp(ch7, exp7) == 0);

    /*
     * Test 8: Test with a string having only vowels. The string
     *         should be reversed.
     */
    char ch8[] = "EiouaIO";
    char exp8[] = "OIauoiE";
    reverse_vowels_in_str(ch8); 
    assert(strcmp(ch8, exp8) == 0);

    return(0);
}
