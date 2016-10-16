/*
 * This program finds the sum of all left leaves in a binary tree.
 * For more information on the problem, please refer to the following
 * link:- http://www.geeksforgeeks.org/find-sum-left-leaves-given-binary-tree/
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

public class binary_tree_find_sum_of_left_leaves
{
    /*
     * This function returns 'true' if the left and right subtrees of the
     * nodes are empty and 'false' otherwise.
     */
    public static boolean is_leaf (treenode root)
    {
        /*
         * If the node itself is null, then the return 'false'
         */
        if (root == null) {
            return(false);
        }

        /*
         * If the left and right subtrees of the node are null, then
         * return 'true'
         */
        if ((root.left == null) && (root.right == null)) {
            return(true);
        }

        /*
         * In all other cases, the node is not a leaf node, so return
         * 'false'
         */
        return(false);
    }

    /*
     * This function returns the sum of all the leaf nodes in the binary
     * tree which are the left child of their parent node.
     */
    public static int find_sum_of_left_leaves (treenode root)
    {
        int sum = 0;

        /*
         * If the root of the binary tree is null, then return zero
         */
        if (root == null) {
            return(0);
        }

        /*
         * If the left subtree is not empty and the left subtree is a
         * leaf node, then return the sum of the left child and the find
         * sum of all left leaves in the right subtree.
         */
        if ((root.left != null) && is_leaf(root.left)) {
            return(root.left.data +
                      find_sum_of_left_leaves(root.right));
        }

        /*
         * Otherwiae return the sum of left leaves in left and right
         * subtrees.
         */
        return(find_sum_of_left_leaves(root.left)
                    + find_sum_of_left_leaves(root.right));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with root being null. The sum of left leaves
         *         should be zero.
         */
        treenode root0 = null;
        assert(0 == find_sum_of_left_leaves(root0));

        /*
         * Test 1: Test with root being the only node. The sum of left
         *         leaves should be zero as there are no left leaves.
         */
        treenode root1 = null;
        root1 = new treenode(10);
        assert(0 == find_sum_of_left_leaves(root1));

        /*
         * Test 2: Test with the root having one left and one right
         *         child. The sum of left leaves should be equal to the
         *         value in the left child.
         */
        treenode root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        assert(20 == find_sum_of_left_leaves(root2));

        /*
         * Test 3: Test with left leaves being present in both left and
         *         right subtrees.
         */
        treenode root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.left.left = new treenode(30);
        root3.right = new treenode(40);
        root3.right.left = new treenode(50);
        assert(80 == find_sum_of_left_leaves(root3));

        /*
         * Test 4: Test with a case when there are no left leaves in the
         *         binary tree. The sum of left leaves in this case should
         *         zero.
         */
        treenode root4 = null;
        root4 = new treenode(10);
        root4.left = new treenode(20);
        root4.left.right = new treenode(30);
        root4.right = new treenode(40);
        root4.right.right = new treenode(50);
        assert(0 == find_sum_of_left_leaves(root4));
    }
}
