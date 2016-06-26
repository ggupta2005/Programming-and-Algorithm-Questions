#include<stdio.h>
#include<assert.h>

/*
 * The time complexity of finding the square root
 * of a positive number using this function is
 * O(sqrt(n)). In this function we linearly increase
 * the value of intended square root unless the 
 * value of square of square root exceeds the number.
 */
unsigned int sqrt_v1 (unsigned int num)
{
    unsigned int sqrt;

    /*
     * If the number is zero, then return zero
     */
    if (num == 0) {
        return(0);
    }

    /*
     * Start with square as 1 and increment unless
     * square of the square root exceeds the number
     * itself.
     */
    sqrt = 1;
    while ((sqrt * sqrt) <= num) {
        ++sqrt;
    }

    /*
     * If the square of the square root is greater than
     * the number, return one less than the square root.
     */
    if ((sqrt * sqrt) > num) {
        return(sqrt - 1);
    } 

    return(sqrt);
}

/*
 * The time complexity of finding the square root
 * of a positive number using this function is
 * O(log(n)). This uses binary search to find the 
 * square root of the number.
 */
unsigned int sqrt_v2 (unsigned int num)
{
    unsigned int sqrt, low, high;
    unsigned int square;

    /*
     * If the number is zero, then return zero
     */
    if (num == 0) {
        return(0);
    }

    /*
     * Initialize 'low' at one and 'high' at
     * num
     */
    low = 1;
    high = num;

    /*
     * Continue the while loop as long as low is 
     * less than or equal to high
     */
    while (low <= high) {
        /*
         * The intended square root lies at the 
         * mid point value of low and high.
         */
        sqrt = (low + high)/2;
       
        /*
         * Compute the square of the square root
         */ 
        square = sqrt * sqrt;
       
        /*
         * If the square of the square is:-
         * 1. Equal to the number, then we have found 
         *    the square root so  break from the while 
         *    loop.
         * 2. Greater than the number, then square
         *    root lies between 'low' and 'sqrt - 1'
         * 3. Less than the number, then the square
         *    root lies between 'sqrt + 1' and 'high'
         */ 
        if (square == num) {
            break;
        } else if (square > num) {
            high = sqrt - 1;
        } else {
            low = sqrt + 1;
        }
    }

    /*
     * Return the converged value of square root,
     * which is the average of 'low' and 'high'
     */
    sqrt = (low + high)/2;
 
    return(sqrt);
}

int main()
{
    /*
     * Test cases for finding the square root,
     * the first approach.
     */
    assert(0 == sqrt_v1(0));
    assert(1 == sqrt_v1(1));
    assert(2 == sqrt_v1(5));
    assert(3 == sqrt_v1(9));
    assert(3 == sqrt_v1(11.9));
    assert(32 == sqrt_v1(1025));
    assert(11 == sqrt_v1(121));

    /*
     * Test cases for finding the square root,
     * the second approach.
     */
    assert(0 == sqrt_v2(0));
    assert(1 == sqrt_v2(1));
    assert(2 == sqrt_v2(5));
    assert(3 == sqrt_v2(9));
    assert(3 == sqrt_v2(11.9));
    assert(32 == sqrt_v2(1025));
    assert(11 == sqrt_v2(121));

    return(0);
}

