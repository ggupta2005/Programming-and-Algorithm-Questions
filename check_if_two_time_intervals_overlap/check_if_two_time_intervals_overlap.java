/*
 * This program checks if two time intervals of the form [s1, e1] and
 * [s2, e2] ovrlap. for example the time intervals [10, 20] and [15, 30]
 * overlap but the time time intervals [10, 20] and [25, 30] do not
 * overlap.
 */
import java.io.*;
import java.util.*;

public class check_if_two_time_intervals_overlap
{
    /*
     * This function checks if the two time intervals [s1, e1] and [s2, e2]
     * are overlapping. If the two time intervals overlap, then this function
     * return 'true' otherwise it returns 'false'. If the time intervals are
     * themselves incorrect, then this function returns 'false'.
     */
    public static boolean
        check_if_time_intervals_overlap_v1 (int s1, int e1, int s2, int e2)
    {
        /*
         * If either of the time intervals is incorrect, that is the
         * start time is greater than the end time, then return 'false'
         */
        if ((s1 > e1) || (s2 > e2)) {
            return(false);
        }

        /*
         * If the start time of the first interval lies between the
         * start time and the end time of the second interval, then
         * time intervals overlap. Return 'true' in this case.
         */
        if ((s2 >= s1) && (s2 <= e1)) {
            return(true);
        }

        /*
         * If the end time of the first interval lies between the
         * start time and the end time of the second interval, then
         * time intervals overlap. Return 'true' in this case.
         */
        if ((e2 >= s1) && (e2 <= e1)) {
            return(true);
        }

        /*
         * If the start time of the second interval lies between the
         * start time and the end time of the first interval, then
         * time intervals overlap. Return 'true' in this case.
         */
        if ((s1 >= s2) && (s1 <= e2)) {
            return(true);
        }

        /*
         * If the end time of the second interval lies between the
         * start time and the end time of the first interval, then
         * time intervals overlap. Return 'true' in this case.
         */
        if ((e1 >= s2) && (e1 <= e2)) {
            return(true);
        }

        /*
         * Since the tme intervals do not overlap, so return
         * 'false'
         */
        return(false);
    }

    /*
     * This function checks if the two time intervals [s1, e1] and [s2, e2]
     * are overlapping. If the two time intervals overlap, then this function
     * return 'true' otherwise it returns 'false'. If the time intervals are
     * themselves incorrect, then this function returns 'false'.
     */
    public static boolean
        check_if_time_intervals_overlap_v2 (int s1, int e1, int s2, int e2)
    {
        /*
         * If either of the time intervals is incorrect, that is the
         * start time is greater than the end time, then return 'false'
         */
        if ((s1 > e1) || (s2 > e2)) {
            return(false);
        }

        /*
         * If the end time of the second interval is lesser than the
         * start time of the interval or if the end time of the first
         * interval is lesser than the start time of the second interval,
         * then the two time intervals do not overlap. So return 'false'.
         */
        if ((e2 < s1) || (e1 < s2)) {
            return(false);
        }

        /*
         * In all other cases the time intervals will overlap. So return
         * 'true'.
         */
        return(true);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test when the time intervals overlap, that is the end
         *         time of one time interval lies within the other time
         *         interval. The functions should return 'true'.
         */
        int s11 = 10, e11 = 20, s21 = 15, e21 = 40;
        assert(true == check_if_time_intervals_overlap_v1(s11, e11, s21, e21));
        assert(true == check_if_time_intervals_overlap_v1(s21, e21, s11, e11));
        assert(true == check_if_time_intervals_overlap_v2(s11, e11, s21, e21));
        assert(true == check_if_time_intervals_overlap_v2(s21, e21, s11, e11));

        /*
         * Test 2: Test when the time intervals do not overlap at all. The
         *         functions should return 'false'.
         */
        int s12 = 10, e12 = 20, s22 = 25, e22 = 40;
        assert(false ==
                    check_if_time_intervals_overlap_v1(s12, e12, s22, e22));
        assert(false ==
                    check_if_time_intervals_overlap_v1(s22, e22, s12, e12));
        assert(false ==
                    check_if_time_intervals_overlap_v2(s12, e12, s22, e22));
        assert(false ==
                    check_if_time_intervals_overlap_v2(s22, e22, s12, e12));

        /*
         * Test 3: Test when the start time of one interval is equal to the
         *         end time of the second interval so the time intervals
         *         overlap at exactly one point. The functions should return
         *         'true'.
         */
        int s13 = 10, e13 = 20, s23 = 20, e23 = 40;
        assert(true == check_if_time_intervals_overlap_v1(s13, e13, s23, e23));
        assert(true == check_if_time_intervals_overlap_v1(s23, e23, s13, e13));
        assert(true == check_if_time_intervals_overlap_v2(s13, e13, s23, e23));
        assert(true == check_if_time_intervals_overlap_v2(s23, e23, s13, e13));

        /*
         * Test 4: Test when the first start time, first end time, second
         *         start time and second end time are all equal. The functions
         *         should return 'true'.
         */
        int s14 = 10, e14 = 10, s24 = 10, e24 = 10;
        assert(true == check_if_time_intervals_overlap_v1(s14, e14, s24, e24));
        assert(true == check_if_time_intervals_overlap_v1(s24, e24, s14, e14));
        assert(true == check_if_time_intervals_overlap_v2(s14, e14, s24, e24));
        assert(true == check_if_time_intervals_overlap_v2(s24, e24, s14, e14));

        /*
         * Test 5: Test the case when one time interval covers the entire of
         *         the second time interval. The functions should return
         *         'true'.
         */
        int s15 = 10, e15 = 100, s25 = 50, e25 = 90;
        assert(true == check_if_time_intervals_overlap_v1(s15, e15, s25, e25));
        assert(true == check_if_time_intervals_overlap_v1(s25, e25, s15, e15));
        assert(true == check_if_time_intervals_overlap_v2(s15, e15, s25, e25));
        assert(true == check_if_time_intervals_overlap_v2(s25, e25, s15, e15));
    }
}
