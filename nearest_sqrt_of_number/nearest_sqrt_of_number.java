import java.io.*;

public class nearest_sqrt_of_number
{
    /*
     * Constant to capture the return value in case
     * user attempts to find the square root of a 
     * negative number.
     */
    public static final long ILLEGAL = -1;

    /*
     * The time complexity of finding the square root
     * of a positive number using this function is
     * O(sqrt(n)). In this function we linearly increase
     * the value of intended square root unless the 
     * value of square of square root exceeds the number.
     * If a negative value is passed to this function, then
     * this function will return 'ILLEGAL' value.
     */
    public static long sqrt_v1 (long num)
    {
        long sqrt;
        
        /*
         * If num is less than zero, then return an
         * illegal value
         */
        if (num < 0) {
            return(ILLEGAL);
        }

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
     * square root of the number. If a negative value is 
     * passed to this function, then this function will 
     * return 'ILLEGAL' value.
     */
    public static long sqrt_v2 (long num)
    {
        long sqrt, low, high;
        long square;

        /*
         * If num is less than zero, then return an
         * illegal value
         */
        if (num < 0) {
            return(ILLEGAL);
        }

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

    public static void main(String[] args) 
    {
        /*
         * Test cases for finding the square root,
         * the first approach.
         */
        assert(0 == sqrt_v1(0));
        assert(ILLEGAL == sqrt_v1(-1));
        assert(ILLEGAL == sqrt_v1(-32));
        assert(1 == sqrt_v1(1));
        assert(2 == sqrt_v1(5));
        assert(3 == sqrt_v1(9));
        assert(3 == sqrt_v1(11));
        assert(32 == sqrt_v1(1025));
        assert(11 == sqrt_v1(121));

        /*
         * Test cases for finding the square root,
         * the second approach.
         */
        assert(0 == sqrt_v2(0));
        assert(ILLEGAL == sqrt_v1(-1));
        assert(ILLEGAL == sqrt_v1(-32));
        assert(1 == sqrt_v2(1));
        assert(2 == sqrt_v2(5));
        assert(3 == sqrt_v2(9));
        assert(3 == sqrt_v2(11));
        assert(32 == sqrt_v2(1025));
        assert(11 == sqrt_v2(121));
    }
}
