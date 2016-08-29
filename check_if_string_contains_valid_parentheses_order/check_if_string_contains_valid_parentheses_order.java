/*
 * This program checks if a string contains a valid parentheses order. For
 * more informaton on this problem, please refer to the following link:-
 * https://leetcode.com/problems/valid-parentheses/
 */
import java.io.*;
import java.util.*;

public class check_if_string_contains_valid_parentheses_order
{
    /*
     * This function returns 'true' if the order of parantheses in a given
     * string is valid and 'false' otherwise. The time complexity of this
     * function is O(n), where 'n' is the number of characters in the
     * str.charAt(i)ng. The space complexity of this funcion is O(n), where 'n'
     * is the number of characters in the str.charAt(i)ng. We are using a stack as
     * the store for the parantheses.
     */
    public static boolean check_if_str_contains_valid_parentheses_order
                                                                (String str)
    {
        int i, len;
        char[] stack;
        int top;

        /*
         * If the input string is not valid or its length is zero,
         * then this string doesn't have a valid parantheses
         * combination. Return 'false'
         */
        if ((str == null) || (str.length() == 0)) {
            return(false);
        }

        len = str.length();

        /*
         * Allocate the memory for the stack whose size is the same the
         * length of the string
         */
        stack = new char[len];

        /*
         * If the allocation for the stack fails, then return 'false'
         */
        if (stack == null) {
            return(false);
        }

        /*
         * Initialize the top of the stack
         */
        top = -1;

        /*
         * Iterate until we reach the end of the string
         */
        for (i = 0; i < len; ++i) {

            /*
             * If the string any of the characters '(', '{' and '[', then push
             * the character on the stack
             */
            if ((str.charAt(i) == '(') || (str.charAt(i) == '{') ||
                (str.charAt(i) == '[')) {

                /*
                 * If the 'top' of the stack is valid, then push the character
                 * on the top of the stack.
                 */
                if (top < (len-1)) {
                    ++top;
                    stack[top] = str.charAt(i);
                } else {

                    /*
                     * Since the top of stack is same the number of the
                     * characters in the string, so an overflow condition
                     * has occurred. Return 'false'.
                     */
                    return(false);
                }
            }

            /*
             * If the string any of the characters ')', '}' and ']', then pop
             * the top character from the stack and match the corresponding
             * parantheses characters
             */
            if ((str.charAt(i) == ')') || (str.charAt(i) == '}') ||
                (str.charAt(i) == ']')) {

                switch (str.charAt(i)) {

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
                             * character parantheses, then return 'false'
                             */
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
                             * character parantheses, then return 'false'
                             */
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
                             * character parantheses, then return 'false'
                             */
                            return(false);
                        }
                        break;

                    default:
                        break;
                }
            }
        }

        /*
         * Since the end of the string has been reached, theni check if
         * the top of stack is valid. Return if the top of stack is valid.
         */
        return(top == -1);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a  null string. This should not be an valid
         *         parantheses string.
         */
        assert(false == check_if_str_contains_valid_parentheses_order(null));

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
    }
}
