/*
 * This program evaluates reverse polish notation using a stack.
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish
 * Notation. Valid operators are +, -, *, /. Each operand may be an
 * integer or another expression.
 *
 * Some examples:
 *
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */
import java.io.*;
import java.util.*;

public class stack_evaluate_reverse_polish_notation
{
    /*
     * This function return 'true' if the 'op' string is an operator
     * among '+', '-', '*' or '/' and 'false' otherwise.
     */
    public static boolean if_operator (String op)
    {
        if (op == null) {
            return(false);
        }

        if (op.equals("+") || op.equals("-") ||
            op.equals("*") || op.equals("/")) {
            return(true);
        }

        return(false);
    }

    /*
     * This function returns the integer value gotten from the
     * evaluation of the reverse polish notation. The time and space
     * complexity of this function is O(n), where 'n' is the number of
     * symbols in the expression.
     */
    public static int evalRPN(String[] tokens) {

        Stack<Integer> stack = new Stack<Integer>();

        /*
         * If the list of tokens is not valid, then return zero
         */
        if (tokens == null || (tokens.length == 0)) {
            return(0);
        }

        /*
         * Iterate over all the tokens in the expression
         */
        for (int i = 0; i < tokens.length; ++i) {

            /*
             * If the current token is an operator, then pop the
             * top two operands from the stack and evaluate the
             * corresponding expression and push the value of the
             * evaluation into the stack. Otherwise push the integer
             * value of the operand into the stack.
             */
            if (if_operator(tokens[i])) {

                /*
                 * If the stack doesn't have two operands, then
                 * return zero.
                 */
                if (stack.size() < 2) {
                    return(0);
                }

                int b = stack.pop();
                int a = stack.pop();

                if (tokens[i].equals("+")) {
                    stack.push(a + b);
                } else if (tokens[i].equals("*")) {
                    stack.push(a * b);
                } else if (tokens[i].equals("/")) {
                    stack.push(a / b);
                } else if (tokens[i].equals("-")) {
                    stack.push(a - b);
                }
            } else {
                stack.push(Integer.parseInt(tokens[i]));
            }
        }

        /*
         * If there are more than one operand on the stack,
         * then return zero.
         */
        if (stack.size() > 1) {
            return(0);
        }

        /*
         * Return the value on the top of stack.
         */
        return(stack.pop());
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Evaluate given reverse polish notation
         *         expression.
         */
        String[] rpn0 = {"2", "1", "+", "3", "*"};
        assert(9 == evalRPN(rpn0));

        /*
         * Test 1: Evaluate given reverse polish notation
         *         expression.
         */
        String[] rpn1 = {"4", "13", "5", "/", "+"};
        assert(6 == evalRPN(rpn1));
    }
}
