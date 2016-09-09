/*
 * This program finds the maximum length of path from the root node to
 * a leaf node in a binary tree (Also known as the height of the binary tree).
 * Look at this post for more details on the maximum height of a binary tree:-
 * http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
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

public class binary_tree_get_max_height_from_root_to_leaf
{
    /*
     * This function returns the maximum length of a path from root node to a
     * leaf node in a binary tree. This length is defined as the number
     * of nodes in a path from root to leaf node in terms of number of nodes.
     * The time complexity of this function is O(n) where 'n' is the number of
     * nodes in the binary tree.
     */
    public static int get_max_length_root_to_leaf_binary_tree (treenode root)
    {
        int max_left_depth;
        int max_right_depth;

        /*
         * If the root element is null, then there is no depth of binary
         * tree. Return zero.
         */
        if (root == null) {
            return(0);
        }

        /*
         * Recursively find the depth of left sub-tree
         */
        max_left_depth = get_max_length_root_to_leaf_binary_tree(root.left);

        /*
         * Recursively find the depth of right sub-tree
         */
        max_right_depth = get_max_length_root_to_leaf_binary_tree(root.right);

        /*
         * If the depth of left sub-tree is higher than right sub-tree, then
         * return '1 + max_left_depth'.
         */
        if (max_left_depth > max_right_depth) {
            return(1 + max_left_depth);
        }

        /*
         * Return '1 + max_right_depth'
         */
        return(1 + max_right_depth);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: In case root is null, the maximum height should be zero
         */
        treenode root1 = null;
        assert(0 == get_max_length_root_to_leaf_binary_tree(root1));

        /*
         * Test2: Test a bsic case of root with two child nodes.
         */
        treenode root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        assert(2 == get_max_length_root_to_leaf_binary_tree(root2));

        /*
         * Test 3: Test a case when the binary tree is a complete binary
         *         tree.
         */
        treenode root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.right = new treenode(30);
        root3.left.right = new treenode(40);
        root3.left.left = new treenode(40);
        root3.right.right = new treenode(50);
        root3.right.left = new treenode(50);
        assert(3 == get_max_length_root_to_leaf_binary_tree(root3));

        /*
         * Test 4: Test a case when the tree is not a complete binary tree.
         */
        treenode root4 = null;
        root4 = new treenode(10);
        root4.left = new treenode(20);
        root4.right = new treenode(30);
        root4.left.left = new treenode(40);
        root4.left.right = new treenode(50);
        root4.right.left = new treenode(60);
        root4.right.left.right = new treenode(70);
        root4.right.left.left = new treenode(80);
        assert(4 == get_max_length_root_to_leaf_binary_tree(root4));

        /*
         * Test 5: Test a case when the binary tree is a linked list
         */
        treenode root5 = null;
        root5 = new treenode(10);
        root5.left = new treenode(20);
        root5.left.left = new treenode(40);
        root5.left.left.left = new treenode(80);
        root5.left.left.left.left = new treenode(160);
        root5.left.left.left.left.left = new treenode(160);
        assert(6 == get_max_length_root_to_leaf_binary_tree(root5));
    }
}
