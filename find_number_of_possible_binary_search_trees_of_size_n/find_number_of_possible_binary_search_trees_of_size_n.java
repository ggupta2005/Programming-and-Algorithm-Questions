/*
 * This program finds the number of binary search trees possible of size
 * 'n'. For example if 'n' is one, then there is only one possible binary
 * search tree. If 'n' is two, then number of possible binary search trees
 * is two. For more information on this problem, please visit the following
 * link:- http://www.geeksforgeeks.org/g-fact-18/
 */
import java.io.*;
import java.util.*;

public class find_number_of_possible_binary_search_trees_of_size_n
{
    /*
     * This function returns the number of possible binary search trees
     * possible having keys in the range 1 to 'n'. The function picks one
     * of the values (i) from [1, 'n'] as the root and finds the number
     * of possible number of left subtrees for [1, 'i - 1]'] and the number
     * of right subtrees for the set [i + 1, n] recursively and muliiplies
     * or adds the number of subtrees computed. Since this a recursive
     * function so a lot of values are reoomputed again and again. So the
     * time and space complexity of this function is O(2^n), where 'n' is
     * the size of the binary search tree.
     */
    public static int find_num_possible_binary_search_trees_size_n_v1 (int n)
    {
        int num_left_tree, num_right_tree, total;
        int root;

        /*
         * Base case: If 'n' is less than or equal to zero, then return
         *            zero
         */
        if (n <= 0) {
            return(0);
        }

        /*
         * Base case: If 'n' is equal to one, then return one
         */
        if (n == 1) {
            return(1);
        }

        /*
         * Initialize the total number of valid binary search trees to zero
         */
        total = 0;

        /*
         * Iterate over all possible values for the root of the binary search
         * tree
         */
        for (root =1; root <= n; ++root) {

            /*
             * Find the number of possible left binary search trees
             */
            num_left_tree =
                find_num_possible_binary_search_trees_size_n_v1(root - 1);

            /*
             * Find the number of possible right binary search trees
             */
            num_right_tree =
                find_num_possible_binary_search_trees_size_n_v1(n - root);

            if ((num_left_tree > 0) && (num_right_tree > 0)) {

                /*
                 * If the number of left subtrees and right subtrees are
                 * greater than zero, then multiply them and add to 'total'
                 */
                total += num_left_tree * num_right_tree;
            } else if (num_left_tree > 0) {

                /*
                 * Otherwise, ff the number of left subtrees greater
                 * than zero, then add them to 'total'
                 */
                total += num_left_tree;
            } else if (num_right_tree > 0) {

                /*
                 * Otherwise, ff the number of right subtrees greater
                 * than zero, then add them to 'total'
                 */
                total += num_right_tree;
            }
        }

        /*
         * Return the total number of possible binary search trees of size
         * 'n'
         */
        return(total);
    }

    /*
     * This function returns the number of possible binary search trees
     * possible having keys in the range 1 to 'n'. The function uses a
     * temporary array and stores the maximum number of binary search trees
     * possible of a given size. It picks one of the values (i) from [1, 'n']
     * as the root and finds the number of possible number of left subtrees
     * for [1, 'i - 1]'] and the number of right subtrees for the set
     * [i + 1, n] and muliiplies or adds the number of subtrees computed.
     * Since we compute and store the result in the temporary array, we are
     * able to reuse this result for a later computation. Hence the time
     * complexity of this function is O(n^2), where 'n' is the size of the
     * binary search tree. The space complexity of this function O(n).
     */
    public static int find_num_possible_binary_search_trees_size_n_v2 (int n)
    {
        int num_left_tree, num_right_tree, total;
        int root, iter;
        int[] array = null;

        /*
         * Base case: If 'n' is less than or equal to zero, then return
         *            zero
         */
        if (n <= 0) {
            return(0);
        }

        /*
         * Base case: If 'n' is equal to one, then return one
         */
        if (n == 1) {
            return(1);
        }

        /*
         * Allocate an array of 'n+1' elements to book keep the number
         * of valid subtress of a given size
         */
        array = new int[n+1];

        /*
         * If the array allocation fails, then return zero
         */
        if (array == null) {
            return(0);
        }

        /*
         * Set the zeroth and first the elements of the array to the
         * base case values
         */
        array[0] = 0;
        array[1] = 1;

        /*
         * Iterate from two until 'n'
         */
        for (root = 2; root <= n; ++root) {

            /*
             * Compute the maximum number of binary search trees possible
             * of size 'root' for different sizes of left subtree and right
             * subtrees.
             */
            total = 0;
            for (iter = 1; iter <= root; ++iter) {

                /*
                 * Find the number of possible left binary search trees
                 */
                num_left_tree = array[iter - 1];

                /*
                 * Find the number of possible right binary search trees
                 */
                num_right_tree = array[root - iter];

                if ((num_left_tree > 0) && (num_right_tree > 0)) {

                    /*
                     * If the number of left subtrees and right subtrees
                     * are greater than zero, then multiply them and add
                     * to 'total'
                     */
                    total += num_left_tree * num_right_tree;
                } else if (num_left_tree > 0) {

                    /*
                     * Otherwise, ff the number of left subtrees greater
                     * than zero, then add them to 'total'
                     */
                    total += num_left_tree;
                } else if (num_right_tree > 0) {

                    /*
                     * Otherwise, ff the number of right subtrees greater
                     * than zero, then add them to 'total'
                     */
                    total += num_right_tree;
                }
            }

            array[root] = total;
        }


        /*
         * Cache the total number of possible binary search trees of size 'n'
         */
        total = array[n];

        /*
         * Return the total number of possible binary search trees of size
         * 'n'
         */
        return(total);
    }


    public static void main (String[] args)
    {
        /*
         * Test 0: Test with a negative value of 'n'
         */
        assert(0 == find_num_possible_binary_search_trees_size_n_v1(-10));
        assert(0 == find_num_possible_binary_search_trees_size_n_v2(-10));

        /*
         * Test 1: Test with a zero value of 'n'
         */
        assert(0 == find_num_possible_binary_search_trees_size_n_v1(0));
        assert(0 == find_num_possible_binary_search_trees_size_n_v2(0));

        /*
         * Test 2: Test with value of 'n' being one
         */
        assert(1 == find_num_possible_binary_search_trees_size_n_v1(1));
        assert(1 == find_num_possible_binary_search_trees_size_n_v2(1));

        /*
         * Test 3: Test with value of 'n' being two
         */
        assert(2 == find_num_possible_binary_search_trees_size_n_v1(2));
        assert(2 == find_num_possible_binary_search_trees_size_n_v2(2));

        /*
         * Test 4: Test with value of 'n' being three
         */
        assert(5 == find_num_possible_binary_search_trees_size_n_v1(3));
        assert(5 == find_num_possible_binary_search_trees_size_n_v2(3));

        /*
         * Test 5: Test with value of 'n' being four
         */
        assert(14 == find_num_possible_binary_search_trees_size_n_v1(4));
        assert(14 == find_num_possible_binary_search_trees_size_n_v2(4));

        /*
         * Test 6: Test with value of 'n' being five
         */
        assert(42 == find_num_possible_binary_search_trees_size_n_v1(5));
        assert(42 == find_num_possible_binary_search_trees_size_n_v2(5));
    }
}
