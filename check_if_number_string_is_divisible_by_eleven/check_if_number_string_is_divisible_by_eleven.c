/*
 * This program checks if a number string is divisible by eleven. For
 * more information on the problem, please refer to the following link:-
 * http://www.geeksforgeeks.org/check-large-number-divisible-11-not/
 */
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#include<stdbool.h>

/*
 * This function returns 'true' if the number string is divisible by
 * eleven and 'false' otherwise. The time complexity of this function
 * is O(n), where 'n' is the number of digits in the number string. The
 * space complexity of this function is O(1).
 */
bool if_num_str_is_divisible_by_eleven (char* str)
{
    int index, sum_even, sum_odd;

    /*
     * If the number string is not valid or its length is
     * zero, then return 'false'
     */
    if (!str || !strlen(str)) {
        return(false);
    }

    /*
     * If any of the characters in the number string are not
     * digits, then return 'false'
     */
    index = 0;
    while (str[index] != '\0') {
        if (!isdigit(str[index])) {
            return(false);
        }

        ++index;
    }

    index = 0;
    sum_even = 0;
    sum_odd = 0;

    /*
     * Iterate over the length of the entire number string
     * and sum separately the digits in even indexes and odd
     * indexes.
     */
    while (str[index] != '\0') {
        if ((index % 2) == 0) {
            sum_even += str[index] - '0';
        } else {
            sum_odd += str[index] - '0';
        }

        ++index;
    }

    /*
     * Check if the difference between the sum of even index
     * digits and the sum of the odd index digits is divisible
     * by eleven
     */
    return(((sum_even - sum_odd) % 11) == 0);
}

int main ()
{
    /*
     * Test 0: Test with all combinations of the input number
     *         string being illegal. The number string should
     *         not be divisible by eleven.
     */
    assert(!if_num_str_is_divisible_by_eleven(NULL));
    assert(!if_num_str_is_divisible_by_eleven(""));
    assert(!if_num_str_is_divisible_by_eleven("fdgb12345"));

    /*
     * Test 1: Test with some combinations of the input number
     *         string which are divisible by eleven. The number
     *         string should be divisible by eleven.
     */
    assert(if_num_str_is_divisible_by_eleven("0"));
    assert(if_num_str_is_divisible_by_eleven("11"));
    assert(if_num_str_is_divisible_by_eleven("1331"));
    assert(if_num_str_is_divisible_by_eleven("76945"));
    assert(if_num_str_is_divisible_by_eleven("1234567589333892"));

    /*
     * Test 2: Test with some combinations of the input number
     *         string which are not divisible by eleven. The number
     *         string should not be divisible by eleven.
     */
    assert(!if_num_str_is_divisible_by_eleven("1"));
    assert(!if_num_str_is_divisible_by_eleven("120"));
    assert(!if_num_str_is_divisible_by_eleven("363588395960667043875487"));

    return(0);
}
