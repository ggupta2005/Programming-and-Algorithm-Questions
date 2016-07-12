/*
 * This program checks if a binary tree is a full binary tree. A binary tree
 * is a full binary tree if each node in the tree has either two or zero child
 * nodes.
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

public class binary_tree_check_if_full_tree
{
    /*
     * This function returns true, if a binary tree node is a leaf
     * node and false if it is not.
     */
    public static boolean if_treenode_is_leaf (treenode root)
    {
        if (root == null) {
            return(false);
        }

        if ((root.left == null) && (root.right == null)) {
            return(true);
        }

        return(false);
    }

    /*
     * This function returns true, if a binary tree node is an internal
     * node with two children and false if does not.
     */
    public static boolean if_treenode_has_two_children (treenode root)
    {
        if (root == null) {
            return(false);
        }

        if ((root.left != null) && (root.right != null)) {
            return(true);
        }

        return(false);
    }

    /*
     * This function returns true in case a binary tree is a full tree
     * and false otherwise.
     */
    public static boolean check_if_binary_tree_is_full (treenode root)
    {
        /*
         * If the root node is null, then return true as empty
         * tree is a full binary tree.
         */
        if (root == null) {
            return(true);
        }

        /*
         * If the root node is not a leaf node and it is also not
         * an internal node with two child nodes, then return false.
         */
        if (!if_treenode_is_leaf(root) &&
            !if_treenode_has_two_children(root)) {
            return(false);
        }

        /*
         * Recursively check the left and right subtrees, if both the
         * subtrees are full binary trees themselves.
         */
        return(check_if_binary_tree_is_full(root.left) &&
               check_if_binary_tree_is_full(root.right));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: In case root is null, then the tree is full
         */
        treenode root0 = null;
        assert true == check_if_binary_tree_is_full(root0);

        /*
         * Test 1: In this case the tree has only one node.
         *         Then the tree is full
         */
        treenode root1 = null;
        root1 = new treenode(10);
        assert true == check_if_binary_tree_is_full(root1);

        /*
         * Test2: Test a basic case of root with two child nodes. This
         *        tree should be a full binary tree.
         */
        treenode root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        assert true == check_if_binary_tree_is_full(root2);

        /*
         * Test 3: Test a case when the binary tree is not a full tree.
         *         That is this tree has an internal node with one child
         *         and that is the left child for this node.
         */
        treenode root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.right = new treenode(20);
        root3.left.left = new treenode(40);
        assert false == check_if_binary_tree_is_full(root3);

        /*
         * Test 4: Test a case when the binary tree is not a full tree.
         *         That is this tree has an internal node with one child
         *         and that is the right child for this node.
         */
        treenode root4 = null;
        root4 = new treenode(10);
        root4.left = new treenode(20);
        root4.right = new treenode(20);
        root4.left.right = new treenode(40);
        assert false == check_if_binary_tree_is_full(root4);
    }
}
