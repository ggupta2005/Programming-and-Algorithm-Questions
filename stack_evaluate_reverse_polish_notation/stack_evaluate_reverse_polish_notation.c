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
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

/*
 * Maximum size of the stack which is implemented as an array
 */
#define MAX_STACK_SIZE 10000

/*
 * This function returns the integer value gotten from the
 * evaluation of the reverse polish notation. The time and space
 * complexity of this function is O(n), where 'n' is the number of
 * symbols in the expression.
 */
int evalRPN(char** tokens, int tokensSize)
{
    int stack[MAX_STACK_SIZE];
    int top, index, a, b;

    /*
     * If the list of tokens is not valid, then return zero
     */
    if (!tokens || (tokensSize <= 0)) {
        return(0);
    }

    /*
     * Set top of the stack to '-1'.
     */
    top = -1;

    /*
     * Iterate over all the tokens in the expression
     */
    for (index = 0; index < tokensSize; ++index) {

        /*
         * If the current token is an operator, then pop the
         * top two operands from the stack and evaluate the
         * corresponding expression and push the value of the
         * evaluation into the stack. Otherwise push the integer
         * value of the operand into the stack.
         */
        if (!strcmp("+", tokens[index])) {

            /*
             * If the stack doesn't have two operands, then
             * return zero.
             */
            if (top < 1) {
                return(0);
            }

            b = stack[top];
            --top;

            a = stack[top];
            --top;

            ++top;
            stack[top] = a + b;

        } else if (!strcmp("*", tokens[index])) {

            /*
             * If the stack doesn't have two operands, then
             * return zero.
             */
            if (top < 1) {
                return(0);
            }

            b = stack[top];
            --top;

            a = stack[top];
            --top;

            ++top;
            stack[top] = a * b;

        } else if (!strcmp("/", tokens[index])) {

            /*
             * If the stack doesn't have two operands, then
             * return zero.
             */
            if (top < 1) {
                return(0);
            }

            b = stack[top];
            --top;

            a = stack[top];
            --top;

            ++top;
            stack[top] = a / b;
        } else if (!strcmp("-", tokens[index])) {

            /*
             * If the stack doesn't have two operands, then
             * return zero.
             */
            if (top < 1) {
                return(0);
            }

            b = stack[top];
            --top;

            a = stack[top];
            --top;

            ++top;
            stack[top] = a - b;
        } else {
            ++top;
            stack[top] = atoi(tokens[index]);
        }
    }

    /*
     * If there are more than one operand on the stack,
     * then return zero.
     */
    if (top > 0) {
        return(0);
    }

    /*
     * Return the value on the top of stack.
     */
    return(stack[top]);
}

int main ()
{
    /*
     * Test 0: Evaluate given reverse polish notation
     *         expression.
     */
    char* rpn0[] = {"2", "1", "+", "3", "*"};
    int len0 = sizeof(rpn0)/sizeof(char*);
    assert(9 == evalRPN(rpn0, len0));

    /*
     * Test 1: Evaluate given reverse polish notation
     *         expression.
     */
    char* rpn1[] = {"4", "13", "5", "/", "+"};
    int len1 = sizeof(rpn1)/sizeof(char*);
    assert(6 == evalRPN(rpn1, len1));

    return(0);
}
