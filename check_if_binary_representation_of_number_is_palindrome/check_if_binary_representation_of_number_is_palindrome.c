/*
 * Check if the binary representation of an integer is palindrome.
 * For example the binary representation of the integer '0xFE00007F;,
 * is a palindrome while the binary representation of the number '16000'
 * is not a palindrome.
 */
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

#define BITS_PER_BYTE 8

/*
 * This function returns 'true' if the binary reprsentation of a
 * number is a palindrome and 'false' otherwise. The time complexity
 * of this function is O(log(n)) and the space complexity of this
 * function is O(1).
 */
bool if_binary_representation_num_is_palindrome (int num)
{
    int left, right;
    int left_val, right_val;
    int bit_size = sizeof(num) * BITS_PER_BYTE; /* calculate the number
                                                   bits in the number */


    /*
     * Set 'left' to the most significant bit in the number
     */
    left = bit_size - 1;
    /*
     * Set 'right' to the least significant bit in the number
     */
    right = 0;

    /*
     * Iterate until the 'left' index is less than 'right' index
     */
    while (left > right) {

        /*
         * Get the left indexed bit
         */
        left_val = num & (1 << left);

        /*
         * Get the right indexed bit
         */
        right_val = num & (1 << right);

        /*
         * If there is a mismatch between the values of left indexed bit
         * and right indexed bit, then return 'false'.
         */
        if ((left_val != 0) && (right_val == 0)) {
            return(false);
        } else if ((left_val == 0) && (right_val != 0)) {
            return(false);

        }

        /*
         * Decrement the left index
         */
        --left;

        /*
         * Increment the right index
         */
        ++right;
    }

    /*
     * Return 'true' in case the binary representatio of the number
     * is palindrome.
     */
    return(true);
}

int main ()
{
    /*
     * Test 0: Zero's binary representation is palindromic.
     */
    assert(true == if_binary_representation_num_is_palindrome(0));

    /*
     * Test 1: One's binary representation is not palindromic.
     */
    assert(false == if_binary_representation_num_is_palindrome(1));

    /*
     * Test 2: Test few cases when the binary representation of the number
     *         is palindromic.
     */
    assert(true == if_binary_representation_num_is_palindrome(0xffffffff));
    assert(true == if_binary_representation_num_is_palindrome(0xe0e00707));
    assert(true == if_binary_representation_num_is_palindrome(0x80800101));
    assert(true == if_binary_representation_num_is_palindrome(0x10100808));

    /*
     * Test 3: Test few cases when the binary representation of the number
     *         is not palindromic.
     */
    assert(false == if_binary_representation_num_is_palindrome(0x0000ffff));
    assert(false == if_binary_representation_num_is_palindrome(0x70700707));

    return(0);
}
