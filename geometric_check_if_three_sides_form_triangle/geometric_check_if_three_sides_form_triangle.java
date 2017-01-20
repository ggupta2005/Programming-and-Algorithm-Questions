/*
 * This program checks if three integer sides form a valid triangle.
 */
import java.io.*;
import java.util.*;

public class geometric_check_if_three_sides_form_triangle
{
    /*
     * This function returns 'true' if the three sides form a valid triangle
     * and 'false' otherwise.
     */
    public static boolean if_sides_form_valid_triangle (int a, int b, int c)
    {
        /*
         * If either sides of the triangle are less than or equal to
         * zero, then return 'false'.
         */
        if ((a <= 0) || (b <= 0) || (c <= 0)) {
            return(false);
        }

        /*
         * If any of the sides is greater or equal to the sum of the
         * other tow sides, then return 'false'.
         */
        if ((a >= (b + c)) || (b >= (a + c)) || (c >= (a + b))) {
            return(false);
        }

        /*
         * Return 'true' since the sides form a valid triangle
         */
        return(true);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with value of sides less than or equal to zero.
         *         Such a set of sides should not form a valid triangle.
         */
        assert(!if_sides_form_valid_triangle(0, 4, 5));
        assert(!if_sides_form_valid_triangle(-1, 4, 5));
        assert(!if_sides_form_valid_triangle(4, 0, 5));
        assert(!if_sides_form_valid_triangle(4, -1, 5));
        assert(!if_sides_form_valid_triangle(4, 5, 0));
        assert(!if_sides_form_valid_triangle(4, 5, -1));

        /*
         * Test 1: Test with value of sides where one of the sides is
         *         greater than the sum of other two sides. Such a set of
         *         sides should not form a valid triangle.
         */
        assert(!if_sides_form_valid_triangle(4, 10, 5));
        assert(!if_sides_form_valid_triangle(10, 4, 5));
        assert(!if_sides_form_valid_triangle(4, 5, 10));

        /*
         * Test 2: Test with value of sides where one of the sides is
         *         is equal to the sum of other two sides. Such a set of
         *         sides should not form a valid triangle.
         */
        assert(!if_sides_form_valid_triangle(4, 9, 5));
        assert(!if_sides_form_valid_triangle(9, 4, 5));
        assert(!if_sides_form_valid_triangle(4, 5, 9));

        /*
         * Test 3: Test with value of sides where the value of sides is
         *         greater than zero and the sum of any two sides is
         *         greater than the third side. Such a set of sides
         *         should form a valid triangle.
         */
        assert(if_sides_form_valid_triangle(4, 7, 5));
        assert(if_sides_form_valid_triangle(7, 4, 5));
        assert(if_sides_form_valid_triangle(4, 5, 7));
    }
}
