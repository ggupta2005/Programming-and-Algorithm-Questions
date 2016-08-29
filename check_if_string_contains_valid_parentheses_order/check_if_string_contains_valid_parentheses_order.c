/*
 * This program checks if a string contains a valid parentheses order. For
 * more informaton on this problem, please refer to the following link:-
 * https://leetcode.com/problems/valid-parentheses/
 */
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

/*
 * This function returns 'true' if the order of parantheses in a given
 * string is valid and 'false' otherwise. The time complexity of this
 * function is O(n), where 'n' is the number of characters in the
 * string. The space complexity of this funcion is O(n), where 'n'
 * is the number of characters in the string. We are using a stack as
 * the store for the parantheses.
 */
bool check_if_str_contains_valid_parentheses_order (char* str)
{
    int i, len;
    char* stack;
    int top;

    /*
     * If the input string is not valid or its length is zero,
     * then this string doesn't have a valid parantheses
     * combination. Return 'false'
     */
    if (!str || !strlen(str)) {
        return(false);
    }

    len = strlen(str);

    /*
     * Allocate the memory for the stack whose size is the same the
     * length of the string
     */
    stack = (char*)malloc(sizeof(char) * len);

    /*
     * If the allocation for the stack fails, then return 'false'
     */
    if (!stack) {
        return(false);
    }

    /*
     * Initialize the stack and the top of the stack
     */
    memset(stack, 0, sizeof(char) * len);
    top = -1;

    /*
     * Iterate until we reach the end of the string
     */
    for (i = 0; i < len; ++i) {

        /*
         * If the string any of the characters '(', '{' and '[', then push
         * the character on the stack
         */
        if ((str[i] == '(') || (str[i] == '{') || (str[i] == '[')) {

            /*
             * If the 'top' of the stack is valid, then push the character
             * on the top of the stack.
             */
            if (top < (len-1)) {
                ++top;
                stack[top] = str[i];
            } else {

                /*
                 * Since the top of stack is same the number of the
                 * characters in the string, so an overflow condition
                 * has occurred. Free the stack and return 'false'.
                 */
                free(stack);
                return(false);
            }
        }

        /*
         * If the string any of the characters ')', '}' and ']', then pop
         * the top character from the stack and match the corresponding
         * parantheses characters
         */
        if ((str[i] == ')') || (str[i] == '}') || (str[i] == ']')) {

            switch (str[i]) {

                case ')':

                    /*
                     * If top is valid and the top character in the stack
                     * matches with the string character parantheses, then
                     * pop the top character of the stack
                     */
                    if ((top > -1) && (stack[top] == '(')) {
                        --top;
                    } else {

                        /*
                         * If the stack is empty or the top character of
                         * the stack does not match with the string
                         * character parantheses, then free the stack and
                         * return 'false'
                         */
                        free(stack);
                        return(false);
                    }
                    break;

                case '}':

                    /*
                     * If top is valid and the top character in the stack
                     * matches with the string character parantheses, then
                     * pop the top character of the stack
                     */
                    if ((top > -1) && (stack[top] == '{')) {
                        --top;
                    } else {

                        /*
                         * If the stack is empty or the top character of
                         * the stack does not match with the string
                         * character parantheses, then free the stack and
                         * return 'false'
                         */
                        free(stack);
                        return(false);
                    }
                    break;

                case ']':

                    /*
                     * If top is valid and the top character in the stack
                     * matches with the string character parantheses, then
                     * pop the top character of the stack
                     */
                    if ((top > -1) && (stack[top] == '[')) {
                        --top;
                    } else {

                        /*
                         * If the stack is empty or the top character of
                         * the stack does not match with the string
                         * character parantheses, then free the stack and
                         * return 'false'
                         */
                        free(stack);
                        return(false);
                    }
                    break;

                default:
                    break;
            }
        }
    }

    /*
     * Since the end of the string has been reached, then free the stack
     * array and check if the top of stack is valid. Return if the top of
     * stack is valid.
     */
    free(stack);
    return(top == -1);
}

int main ()
{
    /*
     * Test 0: Test with a  NULL string. This should not be an valid
     *         parantheses string.
     */
    assert(false == check_if_str_contains_valid_parentheses_order(NULL));

    /*
     * Test 1: Test with an empty string. This should not be an valid
     *         parantheses string.
     */
    assert(false == check_if_str_contains_valid_parentheses_order(""));

    /*
     * Test 2: Test with a valid paratheses string having only '(' and ')'.
     *         This should be a valid parantheses string.
     */
    assert(true == check_if_str_contains_valid_parentheses_order("()"));

    /*
     * Test 3: Test with a valid paratheses string having '(', ')', '{',
     *         '}', '[' and ']'. This should be a valid parantheses
     *         string.
     */
    assert(true ==
            check_if_str_contains_valid_parentheses_order("(){}[]"));

    /*
     * Test 4: Test with an invalid paratheses string having '(', ')',
     *         '{', '}', '[' and ']'. This should be an invalid
     *         parantheses string.
     */
    assert(false ==
            check_if_str_contains_valid_parentheses_order("(]"));

    /*
     * Test 5: Test with an invalid paratheses string having '(', ')',
     *         '{', '}', '[' and ']'. This should be an invalid
     *         parantheses string.
     */
    assert(false ==
            check_if_str_contains_valid_parentheses_order("([)]"));

    /*
     * Test 6: Test with an invalid paratheses string having only
     *         '(', '{' and'['. This should be an invalid
     *         parantheses string.
     */
    assert(false ==
     check_if_str_contains_valid_parentheses_order("([(((({[[[(("));

    /*
     * Test 7: Test with an invalid paratheses string having only
     *         ')', '}' and']'. This should be an invalid
     *         parantheses string.
     */
    assert(false ==
     check_if_str_contains_valid_parentheses_order("}}}}}})))))))"));

    return(0);
}
