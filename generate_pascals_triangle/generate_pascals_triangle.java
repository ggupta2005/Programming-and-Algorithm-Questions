/*
 * This program generates first 'n' rows of Pascals's Triangle.
 */
import java.io.*;
import java.util.*;

public class generate_pascals_triangle
{
    /*
     * This function returns the 'num' rows of a Pascal's Triangle. If 'num'
     * less than or equal to zero, then this function returns NULL. The time
     * complexity of this function is O(n^2), where 'n' is the number of rows
     * in the Pascal's Triangle. The space complexity of this function is
     * O(n^2), where 'n' is the number of rows in the Pascal's Triangle.
     */
    public static List<List<Integer>> generate(int num)
    {
        List<List<Integer>> tri = new ArrayList<List<Integer>>();

        /*
         * If 'num' is less than or equal to zero, then return empty
         * list
         */
        if (num <= 0) {
            return(tri);
        }

        List<Integer> first = new ArrayList<Integer>();

        /*
         * Set the only element of the first row to one
         */
        first.add(1);
        tri.add(first);

        /*
         * Iterate through the rest of the rows and populate
         * the Pascal's Triangle
         */
        for (int i = 1; i < num; ++i) {

            ArrayList<Integer> current = new ArrayList<Integer>();
            List<Integer> previous = tri.get(i - 1);

            /*
             * Populate a given row of the triangle
             */
            for (int j = 0; j < previous.size() + 1; ++j) {
                if (j == 0) {

                    /*
                     * Copy the first element of the previous row in the
                     * zeroth element of the current row
                     */
                    current.add(previous.get(j));
                } else if (j == (previous.size())) {

                    /*
                     * Copy the last element of the previous row in the
                     * last element of the current row
                     */
                    current.add(previous.get(j - 1));
                } else {

                    /*
                     * For the rest of the elements, sum the adjacent numbers
                     * in the previous row
                     */
                    current.add(previous.get(j - 1) + previous.get(j));;
                }
            }

            /*
             * Add the current row to the Pascal's Triangle
             */
            tri.add(current);
        }

        /*
         * Return the Pascal's Triangle
         */
        return(tri);
    }

    /*
     * This function checks if the two Pascal's Triangles of 'num' rows are
     * same or not. If the two Pascal's Triangle are same, then this function
     * returns 'true' otherwise this function returns 'false'. The time
     * complexity of this function is O(n^2), where 'n' is the number of rows
     * in the Pascal's Triangle. The space complexity of this function is
     * O(n^2), where 'n' is the number of rows in the Pascal's Triangle.
     */
    public static boolean check_if_equal_pascals_triangles
                            (List<List<Integer>> exp, List<List<Integer>> act)
    {
        /*
         * If either of the Pascal's Triangle are invalid or the
         * number of rows in the Pascal's Triangles is invalid, then
         * return 'false'
         */
        if (exp == null || act == null || exp.size() != act.size()) {
            return(false);
        }

        /*
         * Compare each of the rows in the two Pascal's Triangles
         */
        for (int index = 0; index < exp.size(); ++index) {

            /*
             * If either of the rows are null, then return 'false'
             */
            if (exp.get(index) == null || act.get(index) == null ||
                exp.get(index).size() != act.get(index).size()) {
                return(false);
            }

            /*
             * If the entries in the two list rows are not same, then
             * return 'false'
             */
            for (int inner_index = 0; inner_index < exp.get(index).size();
                 ++inner_index) {
                if (exp.get(index).get(inner_index) !=
                                act.get(index).get(inner_index)) {
                    return(false);
                }
            }
        }

        /*
         * Since the two Pascal's Triangles are same, so return
         * 'true'
         */
        return(true);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: If the number of rows is not valid, then the Pascal's
         *         Triangle should be empty.
         */
        List<List<Integer>> act_pt0 = generate(0);
        List<List<Integer>> exp_pt0 = new ArrayList<List<Integer>>();
        assert(check_if_equal_pascals_triangles(act_pt0, exp_pt0));

        /*
         * Test 1: Test a Pascal's Triangle having one row.
         */
        List<List<Integer>> act_pt1 = generate(1);
        List<List<Integer>> exp_pt1 = new ArrayList<List<Integer>>();
        exp_pt1.add(new ArrayList<Integer>((Arrays.asList(1))));
        assert(check_if_equal_pascals_triangles(exp_pt1, act_pt1));

        /*
         * Test 2: Test a Pascal's Triangle having two rows.
         */
        List<List<Integer>> act_pt2 = generate(2);
        List<List<Integer>> exp_pt2 = new ArrayList<List<Integer>>();
        exp_pt2.add(new ArrayList<Integer>((Arrays.asList(1))));
        exp_pt2.add(new ArrayList<Integer>((Arrays.asList(1, 1))));
        assert(check_if_equal_pascals_triangles(exp_pt2, act_pt2));

        /*
         * Test 3: Test a Pascal's Triangle having three rows.
         */
        List<List<Integer>> act_pt3 = generate(3);
        List<List<Integer>> exp_pt3 = new ArrayList<List<Integer>>();
        exp_pt3.add(new ArrayList<Integer>((Arrays.asList(1))));
        exp_pt3.add(new ArrayList<Integer>((Arrays.asList(1, 1))));
        exp_pt3.add(new ArrayList<Integer>((Arrays.asList(1, 2, 1))));
        assert(check_if_equal_pascals_triangles(exp_pt3, act_pt3));

        /*
         * Test 4: Test a Pascal's Triangle having four rows.
         */
        List<List<Integer>> act_pt4 = generate(4);
        List<List<Integer>> exp_pt4 = new ArrayList<List<Integer>>();
        exp_pt4.add(new ArrayList<Integer>((Arrays.asList(1))));
        exp_pt4.add(new ArrayList<Integer>((Arrays.asList(1, 1))));
        exp_pt4.add(new ArrayList<Integer>((Arrays.asList(1, 2, 1))));
        exp_pt4.add(new ArrayList<Integer>((Arrays.asList(1, 3, 3, 1))));
        assert(check_if_equal_pascals_triangles(exp_pt4, act_pt4));

        /*
         * Test 5: Test a Pascal's Triangle having ten rows.
         */
        List<List<Integer>> act_pt5 = generate(10);
        List<List<Integer>> exp_pt5 = new ArrayList<List<Integer>>();
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(1))));
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(1, 1))));
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(1, 2, 1))));
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(1, 3, 3, 1))));
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(1, 4, 6, 4, 1))));
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(
                                            1, 5, 10, 10, 5, 1))));
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(
                                            1, 6, 15, 20, 15, 6, 1))));
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(
                                            1, 7, 21, 35, 35, 21, 7, 1))));
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(
                                            1, 8, 28, 56, 70, 56, 28, 8, 1))));
        exp_pt5.add(new ArrayList<Integer>((Arrays.asList(
                                      1, 9, 36, 84, 126, 126, 84, 36, 9, 1))));
        assert(check_if_equal_pascals_triangles(exp_pt5, act_pt5));
    }
}
