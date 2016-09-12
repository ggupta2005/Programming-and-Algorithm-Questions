/*
 * This program checks if a binary tree is balanced. A binary tree is
 * balanced if the difference in maximum heights of the sub-trees is
 * not more than one and the left and right sub-trees are themselves
 * height balanced. For more information on balanced binary trees,
 * please refer to the following link:-
 * http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
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

public class binary_tree_check_if_balanced_tree
{
    /*
     * This function recursively checks if a binary tree is height balanced
     * and returns 'true' if the binary tree is height balanced and 'false'
     * otherwise. A binary tree is balanced if the difference in maximum
     * heights of the sub-trees is not more than one and the left and right
     * sub-trees are themselves height balanced. This function implements the
     * following algorithm to check if a binary tree is balanced or not:-
     * 1. First check if each of the subtrees are height balanced and also
     *    get the maximum height from subtree root to its leaves. If one of
     *    the subtrees is not height balanced, then this function returns
     *    'false'.
     * 2. If the subtrees are themselves height balanced, then check the
     *    height difference between the maximum heights in the left and the
     *    right subtrees. If the difference in height is more than one, then
     *    return 'false'.
     * 3. Return 'true' since the tree is found to be height balanced.
     * The time complexity of this function is O(n), where 'n' is the number
     * of nodes in the binary tree. The space complexity is o(n), since we are
     * making one recursive call per node in the tree.
     */
    public static boolean check_if_binary_tree_is_height_balanced_recursive
                                                            (treenode root,
                                                             int[] max_height)
    {
        int[] left_depth = new int[1];
        int[] right_depth = new int[1];

        /*
         * If the current tree node is null, then set the 'max_height' as
         * zero and return 'true'.
         */
        if (root == null) {
            max_height[0] = 0;
            return(true);
        }

        /*
         * If the current tree node is a leaf, then set the 'max_height' as
         * one and return 'true'.
         */
        if ((root.left == null) && (root.right == null)) {
            max_height[0] = 1;
            return(true);
        }

        /*
         * Recursively check if the left subtree is height balanced and also
         * get the maximum depth of the subtree. If the subtree is not
         * height balanced, then return 'false'.
         */
        if (!check_if_binary_tree_is_height_balanced_recursive(
                                               root.left, left_depth)) {
            return(false);
        }

        /*
         * Recursively check if the right subtree is height balanced and also
         * get the maximum depth of the subtree. If the subtree is not
         * height balanced, then return 'false'.
         */
        if (!check_if_binary_tree_is_height_balanced_recursive(
                                               root.right, right_depth)) {
            return(false);
        }

        /*
         * If the difference between the left and right subtree is more than
         * one, then return 'false'
         */
        if ((left_depth[0] - right_depth[0]) > 1) {
            max_height[0] = left_depth[0] + 1;
            return(false);
        } else if ((right_depth[0] - left_depth[0]) > 1) {
            max_height[0] = right_depth[0] + 1;
            return(false);
        }

        /*
         * Set 'max_height' as the maximum depth of the tree
         */
        if (left_depth[0] > right_depth[0]) {
            max_height[0] = left_depth[0] + 1;
        } else {
            max_height[0] = right_depth[0] + 1;
        }

        /*
         * Return 'true' as the tree is found to be height balanced
         */
        return(true);
    }

    /*
     * This function calls a recursive function to find if the binary tree
     * is height balanced.
     */
    public static boolean check_if_binary_tree_is_height_balanced
                                                            (treenode root)
    {
        int[] max_height = new int[1];

        return(check_if_binary_tree_is_height_balanced_recursive(
                                                    root, max_height));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: In case root is null, then the tree is height balanced.
         */
        treenode root0 = null;
        assert(true == check_if_binary_tree_is_height_balanced(root0));

        /*
         * Test 1: In this case the tree has only one node.
         *         So the tree is height balanced.
         */
        treenode root1 = null;
        root1 = new treenode(10);
        assert(true == check_if_binary_tree_is_height_balanced(root1));

        /*
         * Test 2: Test a basic case of root with two child nodes. This
         *         tree should be a height balanced  binary tree.
         */
        treenode root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        assert(true == check_if_binary_tree_is_height_balanced(root2));

        /*
         * Test 3: Test a case when the binary tree has the height
         *         difference of one with left subtree having a larger
         *         height. Then this tree should be a height balanced binary
         *         tree.
         */
        treenode root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.right = new treenode(40);
        root3.left.left = new treenode(50);
        assert(true == check_if_binary_tree_is_height_balanced(root3));

        /*
         * Test 4: Test a case when the binary tree has the height
         *         difference of one with right subtree having a larger
         *         height. Then this tree should be a height balanced binary
         *         tree.
         */
        treenode root4 = null;
        root4 = new treenode(10);
        root4.left = new treenode(20);
        root4.right = new treenode(40);
        root4.right.left = new treenode(50);
        assert(true == check_if_binary_tree_is_height_balanced(root4));

        /*
         * Test 5: Test a case when the binary tree has the height
         *         difference of two with left subtree having a larger
         *         height. Then this tree should not be a height balanced
         *         binary tree.
         */
        treenode root5 = null;
        root5 = new treenode(10);
        root5.left = new treenode(20);
        root5.right = new treenode(40);
        root5.left.left = new treenode(50);
        root5.left.left.right = new treenode(60);
        assert(false == check_if_binary_tree_is_height_balanced(root5));

        /*
         * Test 6: Test a case when the binary tree has the height
         *         difference of two with right subtree having a larger
         *         height. Then this tree should not be a height balanced
         *         binary tree.
         */
        treenode root6 = null;
        root6 = new treenode(10);
        root6.left = new treenode(20);
        root6.right = new treenode(40);
        root6.right.left = new treenode(50);
        root6.right.left.right = new treenode(60);
        assert(false == check_if_binary_tree_is_height_balanced(root6));
    }
}
