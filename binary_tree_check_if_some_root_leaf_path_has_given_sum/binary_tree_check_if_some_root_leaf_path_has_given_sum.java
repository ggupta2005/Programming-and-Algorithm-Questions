/*
 * This program checks if a binary tree has a path from root to leaf
 * which has a given sum. More information on this problem can be found
 * on the following link:-
 * http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
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

public class binary_tree_check_if_some_root_leaf_path_has_given_sum
{
    /*
     * This function returns 'true' if there is some root to leaf path in
     * binary tree which has sum of all nodes from root to leaf nodes as
     * 'sum'. If there is no such path exists, then this function returns
     * 'false'. The time complexity of this function is O(n), where 'n' is
     * the number of nodes in the binary tree. The space complexity of this
     * function is O(n).
     */
    public static boolean check_if_some_root_leaf_path_has_given_sum (
                                                        treenode root,
                                                        int sum)
    {
        /*
         * If the root node is NULL, then return 'false'
         */
        if (root == null) {
            return(false);
        }

        /*
         * If the node is a leaf node and the value in the node is same
         * as the 'sum', then return 'true' otherwise return 'false'
         */
        if ((root.left == null) && (root.right == null)) {
            return(sum == root.data);
        }

        /*
         * Recursively check the left and right sub-trees to check if the
         * sub-tress have a path to the leaf nodes which have path sum as
         * 'sum - root.data'.
         */
        return(check_if_some_root_leaf_path_has_given_sum(
                                            root.left, sum - root.data) ||
               check_if_some_root_leaf_path_has_given_sum(
                                            root.right, sum - root.data));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: In case root is NULL, then the tree does not have a
         *         path from root to leaf which has a path sum
         */
        treenode root0 = null;
        int sum0 = 0;
        assert(false ==
                check_if_some_root_leaf_path_has_given_sum(root0, sum0));

        /*
         * Test 1: In case root is NULL, and sum is non-zero then the tree
         *         does not have a path from root to leaf which has a path
         *         sum
         */
        treenode root1 = null;
        int sum1 = 10;
        assert(false ==
                check_if_some_root_leaf_path_has_given_sum(root1, sum1));

        /*
         * Test 2: In case root is not null, and sum is same as the value in
         *         root node, then the tree has a path from root to leaf which
         *         has a path sum
         */
        treenode root2 = null;
        root2 = new treenode(10);
        int sum2 = 10;
        assert(true ==
                check_if_some_root_leaf_path_has_given_sum(root2, sum2));

        /*
         * Test 3: In case root is not null, and sum is not same as the
         *         value in root node, then the tree does not have a path
         *         from root to leaf which has a path sum
         */
        treenode root3 = null;
        root3 = new treenode(10);
        int sum3 = 30;
        assert(false ==
                check_if_some_root_leaf_path_has_given_sum(root3, sum3));

        /*
         * Test 4: In case root is a big tree, and there is a path from
         *         root to leaf which has a path sum
         */
        treenode root4 = null;
        root4 = new treenode(10);
        root4.right = new treenode(30);
        root4.left = new treenode(40);
        root4.right.left = new treenode(60);
        root4.right.right = new treenode(-100);
        root4.left.right = new treenode(70);
        root4.right.right.right = new treenode(80);
        root4.right.right.left = new treenode(90);
        int sum4 = 20;
        assert(true ==
                check_if_some_root_leaf_path_has_given_sum(root4, sum4));

        /*
         * Test 5: In case root is a big tree, and there is no  path from
         *         root to leaf which has a path and sum
         */
        treenode root5 = null;
        root5 = new treenode(10);
        root5.right = new treenode(30);
        root5.left = new treenode(40);
        root5.right.left = new treenode(60);
        root5.right.right = new treenode(-100);
        root5.left.right = new treenode(70);
        root5.right.right.right = new treenode(80);
        root5.right.right.left = new treenode(90);
        int sum5 = -120;
        assert(false ==
                check_if_some_root_leaf_path_has_given_sum(root5, sum5));
    }
}
