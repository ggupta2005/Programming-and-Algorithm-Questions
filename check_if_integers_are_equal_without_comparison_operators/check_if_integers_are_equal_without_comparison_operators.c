/*
 * This program checks if two integers are equal without
 * using any comparison operators.
 */
#include<stdio.h>
#include<assert.h>

/*
 * This function returns 'true' if the two integers are equal and
 * 'false' otherwise. This function returns xor of the two integers.
 * If the computed xor is zero, then the numbers are equal else they
 * are un-equal. The time complexity of this function is O(1).
 */
int if_equal (int a, int b)
{
    return(a ^ b);
}

int main ()
{
    /*
     * Test 0: Test if two positive numbers are equal
     */
    assert(0 == if_equal(156, 156));

    /*
     * Test 1: Test if two positive numbers are un-equal
     */
    assert(0 != if_equal(159, 156));

    /*
     * Test 2: Test if two negative numbers are equal
     */
    assert(0 == if_equal(-15, -15));

    /*
     * Test 3: Test if two negative numbers are un-equal
     */
    assert(0 != if_equal(-15, -19));

    return(0);
}
