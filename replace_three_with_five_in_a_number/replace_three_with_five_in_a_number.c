/*
 * This program replaces the digit three with digit five in a number. For
 * example if a number is 134 then the output should be 154. You should not
 * convert the integer number string and then replace the digit three with
 * digit five.
 */
#include<stdio.h>
#include<assert.h>
#include<limits.h>

#define THREE 3
#define FIVE 5

/*
 * This function replaces all '3' digits with digit '5' in a given number.
 * However, there could be cases when the replacing '3' with '5' can lead
 * to overflow for positive numbers and underflow for negative numbers. So
 * in such cases this function returns the number passed into the function
 * itself. The time complexity of this function is O(d), where 'd' is the
 * number of digits in the number. The space complexity of this function is
 * O(1).
 */
int replace_three_with_five (int num)
{
    int result = 0; /* Set result to be zero */
    int factor = 1; /* Set factor to be one */
    int rem;
    int num_copy;

    /*
     * Create a copy of the number
     */
    num_copy = num;

    /*
     * Iterate until the copy of the number is non-zero
     */
    while (num_copy) {

        /*
         * Get the digit in units place in the number
         */
        rem = num_copy % 10;

        if (rem == THREE) {
            /*
             * If the remainder is positive three, then set the
             * remainder to five
             */
            rem = FIVE;
        } else if (rem * -1 == THREE) {
            /*
             * If the remainder is negative three, then set the
             * remainder to negative five
             */
            rem = -1 * FIVE;
        }

        /*
         * Form the result using the remainder
         */
        if (num > 0) {

            if (factor * rem >= 0) {

                /*
                 * If the product of factor and remainder does not
                 * overflow integer max limit, then add into the result
                 */
                if (result + factor * rem >= 0) {
                    result += factor* rem;
                } else {

                    /*
                     * If the result overflows, then return the number
                     * itself
                     */
                    return(num);
                }
            } else {

                /*
                 * If the product of factor and remainder overflows
                 * integer max limit, then return the number itself
                 */
                return(num);
            }
        } else {
            if (factor * rem <= 0) {

                /*
                 * If the product of factor and remainder does not
                 * underflow integer min limit, then add into the result
                 */
                if (result + factor * rem <= 0) {
                    result += factor* rem;
                } else {

                    /*
                     * If the result underflows, then return the number
                     * itself
                     */
                    return(num);
                }
            } else {

                /*
                 * If the product of factor and remainder underflows
                 * integer min limit, then return the number itself
                 */
                return(num);
            }
        }

        /*
         * Divide the copy of the number by ten
         */
        num_copy /= 10;

        /*
         * Multiply the factor by ten
         */
        factor *= 10;
    }

    return(result);
}

int main ()
{
    /*
     * Test 0: Test with zero. Result should be zero
     */
    assert(0 == replace_three_with_five(0));

    /*
     * Test 1: Test with a positive number having a digit three.
     *         Result should be a number having digits three
     *         replaced by five
     */
    assert(154 == replace_three_with_five(134));

    /*
     * Test 2: Test with a negative number having a digit three.
     *         Result should be a number having digits three
     *         replaced by five
     */
    assert(-154 == replace_three_with_five(-134));

    /*
     * Test 3: Test with a positive number having all digits as three.
     *         Result should be a number having digits three
     *         replaced by five
     */
    assert(5555 == replace_three_with_five(3333));

    /*
     * Test 4: Test with a negative number having all digits as three.
     *         Result should be a number having digits three
     *         replaced by five
     */
    assert(-5555 == replace_three_with_five(-3333));

    /*
     * Test 5: Test with a positive number having no three digits. The
     *         result should be number itself
     */
    assert(1111 == replace_three_with_five(1111));

    /*
     * Test 6: Test with a negative number having no three digits. The
     *         result should be number itself
     */
    assert(-1111 == replace_three_with_five(-1111));

    /*
     * Test 7: Test with the maximum positive number 2147483647. The
     *         result should be maximum positive number itself
     */
    assert(INT_MAX == replace_three_with_five(INT_MAX));

    /*
     * Test 8: Test with the minimum negative number -2147483648. The
     *         result should be minimum negative number itself
     */
    assert(INT_MIN == replace_three_with_five(INT_MIN));

    return(0);
}
