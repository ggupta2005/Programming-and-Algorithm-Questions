/*
 * This program finds the maximum sum for a root to leaf path. For more
 * infomation on this problem, please refer to the following link:-
 * http://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/
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

public class binary_tree_find_maximum_root_to_leaf_sum_path
{
    /*
     * This fnction returns the maximum path sum from root of the binary
     * tree to any of its leaf. The time complexity of this function is
     * O(n), where 'n' is the number of nodes in the binary tree. The
     * space complexity of this function is O(n) since this function
     * uses recursion.
     */
    public static int
            find_maximum_root_to_leaf_path_sum (treenode root)
    {
        int left_sum = 0, right_sum = 0;
        boolean if_left_subtree, if_right_subtree;

        /*
         * If the root of the tree in null, then return zero
         */
        if (root == null) {
            return(0);
        }

        if_left_subtree = false;
        if (root.left != null) {

            /*
             * Find the maximum path sum from root to some leaf in the
             * left leaf.
             */
            left_sum = root.data +
                        find_maximum_root_to_leaf_path_sum(root.left);
            if_left_subtree = true;
        }

        if_right_subtree = false;
        if (root.right != null) {

            /*
             * Find the maximum path sum from root to some leaf in the
             * right leaf.
             */
            right_sum = root.data +
                         find_maximum_root_to_leaf_path_sum(root.right);
            if_right_subtree = true;
        }

        if (if_left_subtree && if_right_subtree) {

            /*
             * If the root node has non-empty left and right subtrees,
             * then return the maximum path sum among the left and right
             * subtrees.
             */
            return(left_sum > right_sum ? left_sum : right_sum);
        } else if (if_left_subtree) {

            /*
             * If right subtree is null, then return the left subtree
             * maximum path sum.
             */
            return(left_sum);
        } else if (if_right_subtree) {

            /*
             * If left subtree is null, then return the right subtree
             * maximum path sum.
             */
            return(right_sum);
        }

        /*
         * Otherwise return the data value in the leaf node.
         */
        return(root.data);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with root being null. The maximum path sum from
         *         root to leaf should be zero.
         */
        treenode root0 = null;
        assert(0 == find_maximum_root_to_leaf_path_sum(root0));

        /*
         * Test 1: Test with root being the only node. The maximum path sum
         *         from root to leaf should be value in root node.
         */
        treenode root1 = null;
        root1 = new treenode(10);
        assert(10 == find_maximum_root_to_leaf_path_sum(root1));

        /*
         * Test 2: Test with the root having one left and one right
         *         child. The maximum path sum from root to leaf should
         *         be maximum sum of value in root node and value in either
         *         left or right leaf node.
         */
        treenode root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        assert((root2.data +
                ((root2.left.data > root2.right.data) ?
                       (root2.left.data) : (root2.right.data))) ==
                find_maximum_root_to_leaf_path_sum(root2));

        /*
         * Test 3: Test with many leaves being present in both left and
         *         right subtrees. All nodes of binary tree contain positive
         *         values. The function should return the maximum path sum
         *         from root to leaf.
         */
        treenode root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.left.left = new treenode(30);
        root3.right = new treenode(40);
        root3.right.left = new treenode(50);
        assert(100 == find_maximum_root_to_leaf_path_sum(root3));

        /*
         * Test 4: Test with many leaves being present in both left and
         *         right subtrees. All nodes of binary tree contain negative
         *         values. The function should return the maximum path sum
         *         from root to leaf.
         */
        treenode root4 = null;
        root4 = new treenode(-10);
        root4.left = new treenode(-20);
        root4.left.left = new treenode(-30);
        root4.right = new treenode(-40);
        root4.right.left = new treenode(-50);
        assert(-60 == find_maximum_root_to_leaf_path_sum(root4));
    }
}
