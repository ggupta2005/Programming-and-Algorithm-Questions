/*
 * This program inverts the left and right subtrees of a binary tree that
 * is the right child of the root becomes its left child and the left child
 * of the root becomes its right child.
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

public class binary_tree_invert_tree
{
    /*
     * This function recursively inverts the left and right subtrees, that
     * is the left child of the root node becomes the right child and the
     * right child of the root child becomes its left child. The time
     * complexity of this function is O(n), where 'n' is the number of nodes
     * in the binary tree. The space complexity of this function is O(n),
     * since this a recursive function.
     */
    public static void invert_tree (treenode root)
    {
        treenode temp;

        /*
         * If the root node is null, then we do not need to perform
         * any inversions. So return from this function.
         */
        if (root == null) {
            return;
        }

        /*
         * Swap the left and the right child nodes
         */
        temp = root.left;
        root.left = root.right;
        root.right = temp;

        /*
         * Recursively invert the left and right subtrees
         */
        invert_tree(root.left);
        invert_tree(root.right);
    }

    /*
     * This function returns 'true' if the two binary trees are identical and
     * 'false' otherwise. Two binary trees are said to identical if they are
     * structurally same and if the nodes have the same value. The time
     * complexity of this function is O(n), where 'n' is the number of nodes
     * in the binary tree. The space complexity of this function is O(n),
     * since this a recursive function.
     */
    public static boolean check_if_two_binary_tree_are_dentical (
                                                        treenode root1,
                                                        treenode root2)
    {
        /*
         * If both root1 and root2 are null, then binary tress are
         * identical. Return 'true'.
         */
        if ((root1 == null) && (root2 == null)) {
            return(true);
        }

        /*
         * If either one of root1 and root2 are not null, then binary
         * tress are not identical. Return 'false'.
         */
        if ((root1 == null) || (root2 == null)) {
            return(false);
        }

        /*
         * Check the following to find if the two binary trees
         * identical:-
         * 1. The data value in the root nodes are equal.
         * 2. The left subtree is identical
         * 3. The right subtree is identical
         */
        return((root1.data == root2.data) &&
               check_if_two_binary_tree_are_dentical(
                                    root1.left, root2.left) &&
               check_if_two_binary_tree_are_dentical(
                                    root1.right, root2.right));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Invert an empty binary tree. The binary tree should
         *         empty even after inversion.
         */
        treenode root0 = null;
        treenode exp_root0 = null;
        invert_tree(root0);
        assert(true == check_if_two_binary_tree_are_dentical(
                                                root0, exp_root0));

        /*
         * Test 1: Invert a binary tree having one node only. The binary
         *         tree should have the same node even after inversion.
         */
        treenode root1 = null;
        treenode exp_root1 = null;
        root1 = new treenode(10);
        exp_root1 = new treenode(10);
        invert_tree(root1);
        assert(true == check_if_two_binary_tree_are_dentical(
                                                root1, exp_root1));

        /*
         * Test 2: Invert a binary tree having one left child node and one
         *         right child node. The binary tree should have the left
         *         and right child nodes inter-changed after inversion.
         */
        treenode root2 = null;
        treenode exp_root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        exp_root2 = new treenode(10);
        exp_root2.left = new treenode(30);
        exp_root2.right = new treenode(20);
        invert_tree(root2);
        assert(true == check_if_two_binary_tree_are_dentical(
                                                root2, exp_root2));

        /*
         * Test 3: Invert a binary tree having empty left or right subtrees.
         *         The binary tree should have the left and right child nodes
         *         inter-changed after inversion.
         */
        treenode root3 = null;
        treenode exp_root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.left.left = new treenode(40);
        root3.right = new treenode(30);
        root3.right.right = new treenode(50);
        exp_root3 = new treenode(10);
        exp_root3.left = new treenode(30);
        exp_root3.left.left = new treenode(50);
        exp_root3.right = new treenode(20);
        exp_root3.right.right = new treenode(40);
        invert_tree(root3);
        assert(true == check_if_two_binary_tree_are_dentical(
                                            root3, exp_root3));
    }
}
