/*
 * This program swaps two the values in two variables without using a temporary
 * variable. For more information on this program, visit the post:
 * http://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/
 */
#include<stdio.h>
#include<assert.h>

/*
 * This function performs the value swap for two integers pointed to
 * by pointers. This function doesn't use a temporary variable to
 * perform the swap. This function uses the bitwise operator XOR to
 * perform the value swap. The time complexity of this function is
 * O(1).
 */
void swap_values_without_temporary_variable (int* a, int* b)
{
    /*
     * If either of 'a' or 'b' is NULL, then we cannot perform the
     * the swap operation. So return.
     */
    if (!a || !b) {
        return;
    }

    /*
     * If 'a' and 'b' point to the same memory location then the
     * result of the operation below will lead to zeroing of the
     * memory location. So return.
     */
    if (a == b) {
        return;
    }

    /*
     * If the value pointed to by 'a' and 'b' is same, then there is
     * no need to perform the swap. So return.
     */
    if (*a == *b) {
        return;
    }

    /*
     * Perform the value swap without using a temporary variable and
     * by using the XOR operation.
     */
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main ()
{
    /*
     * Test 0: Swap two positive numbers without using temporary variable.
     */
    int a0 = 20;
    int b0 = 10;
    int exp_a0 = 10;
    int exp_b0 = 20;
    swap_values_without_temporary_variable(&a0, &b0);
    assert((a0 == exp_a0) && (b0 == exp_b0));

    /*
     * Test 1: Swap two negative numbers without using temporary variable.
     */
    int a1 = -21;
    int b1 = -11;
    int exp_a1 = -11;
    int exp_b1 = -21;
    swap_values_without_temporary_variable(&a1, &b1);
    assert((a1 == exp_a1) && (b1 == exp_b1));

    /*
     * Test 2: Swap one negative number and a positive number without using
     *         temporary variable.
     */
    int a2 = 22;
    int b2 = -22;
    int exp_a2 = -22;
    int exp_b2 = 22;
    swap_values_without_temporary_variable(&a2, &b2);
    assert((a2 == exp_a2) && (b2 == exp_b2));

    /*
     * Test 3: Swap one positive number and a zero number without using
     *         temporary variable.
     */
    int a3 = 0;
    int b3 = 33;
    int exp_a3 = 33;
    int exp_b3 = 0;
    swap_values_without_temporary_variable(&a3, &b3);
    assert((a3 == exp_a3) && (b3 == exp_b3));

    /*
     * Test 4: Swap one negative number and a zero number without using
     *         temporary variable.
     */
    int a4 = 0;
    int b4 = -44;
    int exp_a4 = -44;
    int exp_b4 = 0;
    swap_values_without_temporary_variable(&a4, &b4);
    assert((a4 == exp_a4) && (b4 == exp_b4));

    /*
     * Test 5: Swap values of two variables having the same positive
     *         value without using temporary variable.
     */
    int a5 = 55;
    int b5 = 55;
    int exp_a5 = 55;
    int exp_b5 = 55;
    swap_values_without_temporary_variable(&a5, &b5);
    assert((a5 == exp_a5) && (b5 == exp_b5));

    /*
     * Test 6: Swap values of two variables having the same negative
     *         value without using temporary variable.
     */
    int a6 = -66;
    int b6 = -66;
    int exp_a6 = -66;
    int exp_b6 = -66;
    swap_values_without_temporary_variable(&a6, &b6);
    assert((a6 == exp_a6) && (b6 == exp_b6));

    /*
     * Test 7: Swap values in case the reference of the same variable
     *         is passed to the function. The variable should retain its
     *         value.
     */
    int a7 = -77;
    int exp_a7 = -77;
    swap_values_without_temporary_variable(&a7, &a7);
    assert(a7 == exp_a7);

    /*
     * Test 8: Swap values in case when the reference to the second variable
     *         in NULL. The variable should retain its value.
     */
    int a8 = -88;
    int exp_a8 = -88;
    swap_values_without_temporary_variable(&a8, NULL);
    assert(a8 == exp_a8);

    /*
     * Test 9: Swap values in case when the reference to the first variable
     *         in NULL. The variable should retain its value.
     */
    int a9 = -99;
    int exp_a9 = -99;
    swap_values_without_temporary_variable(NULL, &a9);
    assert(a9 == exp_a9);

    return(0);
}
