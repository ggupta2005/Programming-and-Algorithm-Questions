/*
 * This program checks if two binary trees are identical. Two binary trees
 * are said to identical if they are structurally same and if the nodes have
 * the same value. For more iformation on this problem, please refer to the
 * following link:-
 * http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
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

public class binary_tree_check_if_two_binary_tree_are_identical
{
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
         * Test 0: The two tree root nodes are null. The binary trees
         *         should be identical.
         */
        treenode root10 = null;
        treenode root20 = null;
        assert(true == check_if_two_binary_tree_are_dentical(
                                                    root10, root20));

        /*
         * Test 1: The one of tree root node is not null while other
         *         is  null. The binary trees should not be identical.
         */
        treenode root11 = null;
        treenode root21 = null;
        root11 = new treenode(10);
        assert(false == check_if_two_binary_tree_are_dentical(
                                                    root11, root21));

        /*
         * Test 2: The one of tree root node is not null while other
         *         is  null. The binary trees should not be identical.
         */
        treenode root12 = null;
        treenode root22 = null;
        root22 = new treenode(10);
        assert(false == check_if_two_binary_tree_are_dentical(
                                                    root12, root22));

        /*
         * Test 3: Both the binary tree root nodes are non-null and
         *         contain only one element with same value. The
         *         binary trees should be identical.
         */
        treenode root13 = null;
        treenode root23 = null;
        root13 = new treenode(10);
        root23 = new treenode(10);
        assert(true == check_if_two_binary_tree_are_dentical(
                                                    root13, root23));

        /*
         * Test 4: Both the binary tree root nodes are non-null and
         *         contain only one element with different values. The
         *         binary trees should not be identical.
         */
        treenode root14 = null;
        treenode root24 = null;
        root14 = new treenode(10);
        root24 = new treenode(20);
        assert(false == check_if_two_binary_tree_are_dentical(
                                                    root14, root24));

        /*
         * Test 5: Test with two binary trees having many nodes. The
         *         trees are structurally same and have the same value
         *         in the nodes. The two binary trees should be same.
         */
        treenode root15 = null;
        treenode root25 = null;
        root15 = new treenode(20);
        root15.left = new treenode(40);
        root15.right = new treenode(60);
        root15.left.right = new treenode(80);
        root15.left.left = new treenode(100);
        root15.right.left = new treenode(120);
        root15.right.left.left = new treenode(140);
        root15.right.left.right = new treenode(160);
        root25 = new treenode(20);
        root25.left = new treenode(40);
        root25.right = new treenode(60);
        root25.left.right = new treenode(80);
        root25.left.left = new treenode(100);
        root25.right.left = new treenode(120);
        root25.right.left.left = new treenode(140);
        root25.right.left.right = new treenode(160);
        assert(true == check_if_two_binary_tree_are_dentical(
                                                    root15, root25));

        /*
         * Test 6: Test with two binary trees having many nodes. The
         *         trees are structurally same and but have different
         *         value in the nodes. The two binary trees should be
         *         different.
         */
        treenode root16 = null;
        treenode root26 = null;
        root16 = new treenode(20);
        root16.left = new treenode(40);
        root16.right = new treenode(60);
        root16.left.right = new treenode(80);
        root16.left.left = new treenode(100);
        root16.right.left = new treenode(120);
        root16.right.left.left = new treenode(140);
        root16.right.left.right = new treenode(160);
        root26 = new treenode(20);
        root26.left = new treenode(40);
        root26.right = new treenode(60);
        root26.left.right = new treenode(80);
        root26.left.left = new treenode(110);
        root26.right.left = new treenode(130);
        root26.right.left.left = new treenode(140);
        root26.right.left.right = new treenode(160);
        assert(false == check_if_two_binary_tree_are_dentical(
                                                    root16, root26));

        /*
         * Test 7: Test with two binary trees having many nodes. The
         *         trees are structurally different  The two binary
         *         trees should be different.
         */
        treenode root17 = null;
        treenode root27 = null;
        root17 = new treenode(20);
        root17.left = new treenode(40);
        root17.right = new treenode(70);
        root17.left.right = new treenode(80);
        root17.left.left = new treenode(100);
        root17.right.left = new treenode(120);
        root27 = new treenode(20);
        root27.left = new treenode(40);
        root27.right = new treenode(70);
        root27.left.right = new treenode(80);
        root27.left.left = new treenode(100);
        root27.right.left = new treenode(120);
        root27.right.left.left = new treenode(140);
        root27.right.left.right = new treenode(160);
        assert(false == check_if_two_binary_tree_are_dentical(
                                                    root17, root27));
    }
}
