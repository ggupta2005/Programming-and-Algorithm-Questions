/*
 * This program finds whether a binary tree is a degenerate binary tree. A binary tree
 * is a degenerate binary tree if each node in the tree has exactly one child node. For
 * more on degenerate trees look at the link:-
 * https://webdocs.cs.ualberta.ca/~holte/T26/pb-with-bst.html
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

public class binary_tree_check_if_degenerate_tree
{
    /*
     * This function checks if the binary tree is de-generated. If the binary
     * tree is de-generated then this function returns false else this function
     * returns true. To check if a binary tree is de-generated, we check if the
     * binary tree more than one child nodes. If the binary tree has more than
     * one child nodes, then the binary tree is not degenerated.
     */
    public static boolean check_if_binary_tree_is_degenerate (treenode root)
    {
        /*
         * If the root node is null, then the binary tree is de-genrated.
         * Return 'true'.
         */
        if (root == null) {
            return(true);
        }

        /*
         * If the root node has both right and left sub-tress, then the
         * binary tree is not de-genrated. Return 'false'.
         */
        if ((root.left != null) && (root.right != null)) {
            return(false);
        }

        /*
         * If the root node is a part of de-generated binary tree, then
         * make sure both left and right sub-trees are de-generated binary
         * trees.
         */
        return(check_if_binary_tree_is_degenerate(root.left)
               && check_if_binary_tree_is_degenerate(root.right));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: In case root is null, then the tree is degenerated
         */
        treenode root0 = null;
        assert true == check_if_binary_tree_is_degenerate(root0);

        /*
         * Test 1: In this case the tree has only one node.
         *         Then the tree is degenerated
         */
        treenode root1 = null;
        root1 = new treenode(10);
        assert true == check_if_binary_tree_is_degenerate(root1);

        /*
         * Test2: Test a basic case of root with two child nodes. This
         *        tree should not be a degenerated binary tree.
         */
        treenode root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        assert false == check_if_binary_tree_is_degenerate(root2);

        /*
         * Test 3: Test a case when the binary tree is a linear linked list .
         *         That is this tree is degenrated towards the left subtree.
         */
        treenode root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.left.left = new treenode(40);
        root3.left.left.left = new treenode(40);
        assert true == check_if_binary_tree_is_degenerate(root3);

        /*
         * Test 4: Test a case when the binary tree is a linear linked list .
         *         That is this tree is degenrated towards the right subtree.
         */
        treenode root4 = null;
        root4 = new treenode(10);
        root4.right = new treenode(30);
        root4.right.right = new treenode(60);
        root4.right.right.right = new treenode(70);
        root4.right.right.right.right = new treenode(80);
        assert true == check_if_binary_tree_is_degenerate(root4);

        /*
         * Test 5: Test a case when the binary tree is a linear linked list .
         *         That is this tree is degenrated either towards the right or
         *         left subtrees.
         */
        treenode root5 = null;
        root5 = new treenode(10);
        root5.right = new treenode(30);
        root5.right.right = new treenode(60);
        root5.right.right.left = new treenode(70);
        root5.right.right.left.left = new treenode(80);
        root5.right.right.left.left.right = new treenode(80);
        assert true == check_if_binary_tree_is_degenerate(root5);
    }
}
