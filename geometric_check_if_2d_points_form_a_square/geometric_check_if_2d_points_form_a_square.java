/*
 * This program checks if four points on two dimensional plane represents
 * a square. For more information on this problem, please refer to the
 * following link:- http://quiz.geeksforgeeks.org/check-given-four-points-form-square/
 */
import java.io.*;
import java.util.*;

/*
 * Class definition of a two dimensiinal point
 */
class point
{
    int x, y;

    /*
     * Constructor for the point class
     */
    point (int x1, int y1)
    {
        x = x1;
        y = y1;
    }
}

public class geometric_check_if_2d_points_form_a_square
{
    /*
     * This function returns the square of the distance between two points.
     * The distance is computed using the distance formula given at the
     * following link:-
     * http://www.mathwarehouse.com/algebra/distance_formula/index.php
     */
    public static long
                get_square_of_distance_between_points (point p1, point p2)
    {
        long dist = (p1.x - p2.x) * (p1.x - p2.x) +
                    (p1.y - p2.y) * (p1.y - p2.y);

        return(dist);
    }

    /*
     * This function returns 'true' if the four points in the two dimensional
     * plane form a square and 'false' otherwise. This function uses the
     * distance property to find if the given four poits form a square of not.
     * The space and time complexity of this function is O(1).
     */
    public static boolean check_if_2d_points_form_a_square (point p1,
                                                            point p2,
                                                            point p3,
                                                            point p4)
    {
        long sqr_dist12, sqr_dist13, sqr_dist14;
        long sqr_dist1, sqr_dist2;

        /*
         * Compute the square of distance between point p1 and point p2
         */
        sqr_dist12 = get_square_of_distance_between_points(p1, p2);

        /*
         * Compute the square of distance between point p1 and point p3
         */
        sqr_dist13 = get_square_of_distance_between_points(p1, p3);

        /*
         * Compute the square of distance between point p1 and point p4
         */
        sqr_dist14 = get_square_of_distance_between_points(p1, p4);

        /*
         * If the square of distance between points p1 and p2 and points
         * p1 and p3 are same and the square of distance between points
         * p1 and p2 is two times the square of distance between points
         * p1 and p4, then find the distance between points p2 and p4
         * points p3 and p4 and compare this distance betwen points p1
         * and p2.
         */
        if ((sqr_dist12 == sqr_dist13) && ((2 * sqr_dist12) == sqr_dist14)) {
            sqr_dist1 = get_square_of_distance_between_points(p2, p4);
            sqr_dist2 = get_square_of_distance_between_points(p3, p4);

            /*
             * Return 'false' as these four points do not form a square
             */
            if ((sqr_dist1 != sqr_dist12) || (sqr_dist2 != sqr_dist12)) {
                return(false);
            }

            /*
             * Return 'true' as these four points form a square
             */
            return(true);
        }

        /*
         * If the square of distance between points p1 and p2 and points
         * p1 and p4 are same and the square of distance between points
         * p1 and p3 is two times the square of distance between points
         * p1 and p2, then find the distance between points p2 and p3
         * points p3 and p4 and compare this distance betwen points p1
         * and p2.
         */
        if ((sqr_dist12 == sqr_dist14) && ((2 * sqr_dist12) == sqr_dist13)) {
            sqr_dist1 = get_square_of_distance_between_points(p2, p3);
            sqr_dist2 = get_square_of_distance_between_points(p4, p3);

            /*
             * Return 'false' as these four points do not form a square
             */
            if ((sqr_dist1 != sqr_dist12) || (sqr_dist2 != sqr_dist12)) {
                return(false);
            }

            /*
             * Return 'true' as these four points form a square
             */
            return(true);
        }

        /*
         * If the square of distance between points p1 and p3 and points
         * p1 and p4 are same and the square of distance between points
         * p1 and p2 is two times the square of distance between points
         * p1 and p3, then find the distance between points p2 and p3
         * points p2 and p4 and compare this distance betwen points p1
         * and p3.
         */
        if ((sqr_dist13 == sqr_dist14) && ((2 * sqr_dist13) == sqr_dist12)) {
            sqr_dist1 = get_square_of_distance_between_points(p3, p2);
            sqr_dist2 = get_square_of_distance_between_points(p4, p2);

            /*
             * Return 'false' as these four points do not form a square
             */
            if ((sqr_dist1 != sqr_dist13) || (sqr_dist2 != sqr_dist13)) {
                return(false);
            }

            /*
             * Return 'true' as these four points form a square
             */
            return(true);
        }

        /*
         * Return 'false' as the four points do not form a square
         */
        return(false);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test a case when the four points form a square and
         *         the sides are parallel to the x and y axis. The
         *         function testing the condition for square should
         *         return 'true'.
         */
         point[] p1 = new point[4];
         p1[0] = new point(0, 0);
         p1[1] = new point(0, 10);
         p1[2] = new point(10, 0);
         p1[3] = new point(10, 10);
        assert(true ==
                check_if_2d_points_form_a_square(p1[0], p1[1], p1[2], p1[3]));
        assert(true ==
                check_if_2d_points_form_a_square(p1[0], p1[3], p1[2], p1[1]));
        assert(true ==
                check_if_2d_points_form_a_square(p1[0], p1[1], p1[3], p1[2]));

        /*
         * Test 2: Test a case when the four points form a rectangle and
         *         the sides are parallel to the x and y axis. The
         *         function testing the condition for square should
         *         return 'false'.
         */
         point[] p2 = new point[4];
         p2[0] = new point(0, 0);
         p2[1] = new point(0, 5);
         p2[2] = new point(10, 0);
         p2[3] = new point(10, 5);
        assert(false ==
                check_if_2d_points_form_a_square(p2[0], p2[1], p2[2], p2[3]));

        /*
         * Test 3: Test a case when the three sides satify the distance
         *         property of a square but the fourth side doesn't. The
         *         function testing the condition for square should
         *         return 'false'.
         */
         point[] p3 = new point[4];
         p3[0] = new point(0, 0);
         p3[1] = new point(3, 4);
         p3[2] = new point(4, 3);
         p3[3] = new point(7, 1);
        assert(false ==
                check_if_2d_points_form_a_square(p3[0], p3[1], p3[2], p3[3]));
        assert(false ==
                check_if_2d_points_form_a_square(p3[0], p3[3], p3[2], p3[1]));
        assert(false ==
                check_if_2d_points_form_a_square(p3[0], p3[1], p3[3], p3[2]));

        /*
         * Test 4: Test a case when the diagonal of the square is one of
         *         axis. The function testing the condition for square
         *         should return 'true'.
         */
         point[] p4 = new point[4];
         p4[0] = new point(0, 0);
         p4[1] = new point(0, 10);
         p4[2] = new point(5, 5);
         p4[3] = new point(-5, 5);
        assert(true ==
                check_if_2d_points_form_a_square(p4[0], p4[1], p4[2], p4[3]));
        assert(true ==
                check_if_2d_points_form_a_square(p4[0], p4[3], p4[2], p4[1]));
        assert(true ==
                check_if_2d_points_form_a_square(p4[0], p4[1], p4[3], p4[2]));

        /*
         * Test 5: Test a case when the four points form a rhombus. The
         *         function testing the condition for square should return
         *         'false'.
         */
         point[] p5 = new point[4];
         p5[0] = new point(0, 0);
         p5[1] = new point(0, 6);
         p5[2] = new point(-4, 3);
         p5[3] = new point(4, 3);
        assert(false ==
                check_if_2d_points_form_a_square(p5[0], p5[1], p5[2], p5[3]));
        assert(false ==
                check_if_2d_points_form_a_square(p5[0], p5[3], p5[2], p5[1]));
        assert(false ==
                check_if_2d_points_form_a_square(p5[0], p5[1], p5[3], p5[2]));
    }
}
