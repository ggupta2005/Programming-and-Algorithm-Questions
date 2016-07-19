/*
 * This program checks if a binary tree is a perfect binary tree or not.
 * More on perfect binary tree can be found in the link:-
 * http://quiz.geeksforgeeks.org/binary-tree-set-3-types-of-binary-tree/
 */
import java.io.*;
import java.util.*;

/*
 * The class definition of a binary tree node
 */
class treenode
{
    int data;
    treenode left;
    treenode right;

    public treenode(int val)
    {
        data = val;
        left = null;
        right = null;
    }
}

public class binary_tree_check_if_perfect_tree
{
    /*
     * This function recursively computes the number of nodes in the
     * binary tree. We should pass the root of the binary tree to find
     * number of nodes in that binary tree. The time complexity of this
     * function is O(n), where 'n' is the number of nodes in the binary
     * tree.
     */
    public static int count_nodes (treenode root)
    {
        /*
         * If the root node is null, then there are no nodes in the
         * binary tree. So return zero.
         */
        if (root == null) {
            return(0);
        }

        /*
         * Recursively find the number of nodes in the left and right
         * subtrees and return the sum of nodes in the left, right subtrees
         * and the node itself.
         */
        return(1 + count_nodes(root.left) + count_nodes(root.right));
    }

    /*
     * This function finds the maximum height of the binary tree using
     * recursion. The time complexity of this function function is O(n),
     * where 'n' is the number of nodes in the binary
     */
    public static int height (treenode root)
    {
        if (root == null) {
            return(0);
        }

        int l_depth = 1 + height(root.left);
        int r_depth = 1 + height(root.right);

        if (l_depth > r_depth) {
            return(l_depth);
        }

        return(r_depth);
    }

    /*
     * This function computes the power of 'base' to 'exponent' efficiently.
     * The time complexity of this function is O(log(exponent)). This is a
     * recursive function.
     */
    public static int power (int base, int exponent)
    {
        /*
         * Base case. If exponent is zero, then return one
         */
        if (exponent == 0) {
            return(1);
        }

        /*
         * Base case. If exponent is one, then return base itself
         */
        if (exponent == 1) {
            return(base);
        }

        /*
         * Calculate the number base^(exponent/2) by recursively calling
         * calling this function
         */
        int product = power(base, exponent/2);

        /*
         * Incase of even value of 'exponent', return the complete
         * product once we have the base^(exponent/2)
         */
        if ((exponent%2) == 0) {
            return(product * product);
        }

        /*
         * Incase of odd value of 'exponent', return the complete
         * product once we have the base^(exponent/2)
         */
        return(base * product * product);
    }

    /*
     * This function checks if a binary tree is a perfect binary tree.
     * A tree is a perfect binary tree if it has (2^h - 1) nodes, where
     * h is the height of the tree. This function returns 'true' if the
     * binary tree is perfect and false otherwise. The overall time complexity
     * of this function is O(n), where 'n' is the number of nodes in the
     * binary tree.
     */
    public static boolean if_binary_tree_full_and_complete (treenode root)
    {
        /*
         * An empty tree is always a perfect binary tree, so
         * return 'true'.
         */
        if (root == null) {
            return(true);
        }

        /*
         * Compute the height of the binary tree
         */
        int max_height = height(root);

        /*
         * Compute the number of nodes in the binary tree
         */
        int node_count = count_nodes(root);

        /*
         * Find the number of nodes in the perfect binary tree having
         * height 'max_height'
         */
        int expected_node_count = power(2, max_height) - 1;

        /*
         * Check if the number of nodes in the binary is same as the
         * number of nodes that should be in a perfect  binary tree
         * having the same height
         */
        return(expected_node_count == node_count);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test the case when the binary tree is empty
         */
        treenode root0 = null;
        assert true == if_binary_tree_full_and_complete(root0);

        /*
         * Test 1: Test the case when the binary tree has one node
         */
        treenode root1 = new treenode(10);
        assert true == if_binary_tree_full_and_complete(root1);

        /*
         * Test 2: Test the case when the binary tree is a perfect
         *         tree having 15 nodes
         */
        treenode root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);

        root2.left.right = new treenode(40);
        root2.left.left = new treenode(50);
        root2.right.left = new treenode(60);
        root2.right.right = new treenode(70);

        root2.left.left.left = new treenode(80);
        root2.left.left.right = new treenode(90);
        root2.left.right.left = new treenode(80);
        root2.left.right.right = new treenode(90);
        root2.right.left.left = new treenode(80);
        root2.right.left.right = new treenode(90);
        root2.right.right.left = new treenode(80);
        root2.right.right.right = new treenode(90);
        assert true == if_binary_tree_full_and_complete(root2);

        /*
         * Test 3:  Test a case when a tree is not a complete binary tree
         */
        treenode root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.right = new treenode(30);

        root3.left.right = new treenode(40);
        root3.left.left = new treenode(50);
        root3.right.left = new treenode(60);
        root3.right.right = new treenode(70);

        root3.left.left.left = new treenode(80);
        assert false == if_binary_tree_full_and_complete(root3);
    }
}
