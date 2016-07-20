/*
 * This program multiplies a number by seven using bitwise operators.
 * Bitwise operators are more efficient to use than the airthmetic
 * operators. More on this can be found on the website:-
 * http://www.geeksforgeeks.org/efficient-way-to-multiply-with-7/
 */
#include<stdio.h>
#include<assert.h>

/*
 * This function multiplies a number by seven using the following
 * operations:-
 * 1. By right-shifting the number by 3 bits we multiply the number
 *    by 8.
 * 2. If we now subtract the num from the right shifted number, then
 *    we will get the result.
 */
unsigned long multiply_by_seven (unsigned long num)
{
    unsigned long eight_multiply = num << 3;

    unsigned long seven_multiply = eight_multiply - num;

    return(seven_multiply);
}

int main ()
{
    /*
     * Test 0: Multiply 0 by 7
     */
    assert(0 == multiply_by_seven(0));

    /*
     * Test 1: Multiply 1 by 7
     */
    assert(7 == multiply_by_seven(1));

    /*
     * Test 2: Multiply 10 by 7
     */
    assert(70 == multiply_by_seven(10));

    /*
     * Test 3: Multiply 49 by 7
     */
    assert(343 == multiply_by_seven(49));

    return(0);
}
