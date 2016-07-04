/*
 * This program finds ithe number of nodes in a binary tree.
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

public class binary_tree_count_number_of_nodes
{
    /*
     * This function recursively computes the number of nodes in a binary tree.
     */
    public static int find_number_of_nodes_binary_tree (treenode root)
    {
        /*
         * If the root node is null, then return zero.
         */
        if (root == null) {
            return(0);
        }

        /*
         * Otherwise return the sum of the following:-
         * 1. '1' for the node itself.
         * 2. number of nodes in the left sub-tree
         * 3. number of nodes in the right sub-tree
         */
        return(1 + find_number_of_nodes_binary_tree(root.left)
               + find_number_of_nodes_binary_tree(root.right));
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: In case root is null, the number of nodes in the
         * tree should be zero.
         */
        treenode root1 = null;
        assert 0 == find_number_of_nodes_binary_tree(root1);

        /*
         * Test2: Test a bsic case of root with two child nodes.
         */
        treenode root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        assert 3 == find_number_of_nodes_binary_tree(root2);

        /*
         * Test 3: Test a case when the binary tree is a complete binary
         *         tree.
         */
        treenode root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.right = new treenode(30);
        root3.left.right = new treenode(40);
        root3.right.right = new treenode(50);
        assert 5 == find_number_of_nodes_binary_tree(root3);

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
        assert 8 == find_number_of_nodes_binary_tree(root4);
    }
}
