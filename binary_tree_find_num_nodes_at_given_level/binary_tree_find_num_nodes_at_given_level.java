/*
 * This program finds the number of nodes at a given level in a
 * binary tree. If there are not as many levels in the binary tree
 * then the function returns zero.
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

public class binary_tree_find_num_nodes_at_given_level
{
    /*
     * This function returns the number of nodes at a given level in the
     * binary tree. If there are not as many levels in the binary tree or
     * the level is not valid, then this function returns zero. The time
     * complexity of this function is O(n), where 'n' is the number of
     * nodes in the binary tree. The space complexity of this function is
     * O(n).
     */
    public static int
        get_number_of_node_at_level_k (treenode root, int level)
    {
        /*
         * If the root of the binary tree is not valid or the number
         * of the level is not valid, then return zero.
         */
        if ((root == null) || (level <= 0)) {
            return(0);
        }

        /*
         * If the value of the level is one, then retrun one
         */
        if (level == 1) {
            return(1);
        }

        /*
         * Recursively, find the number of nodes at the given level
         * in the right and the left subtrees.
         */
        return(get_number_of_node_at_level_k(root.left, level - 1) +
               get_number_of_node_at_level_k(root.right, level - 1));
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: In case root is null, the number of nodes at any level
         *         in the tree should be zero.
         */
        treenode root1 = null;
        assert(0 == get_number_of_node_at_level_k(root1, -1));
        assert(0 == get_number_of_node_at_level_k(root1, 0));
        assert(0 == get_number_of_node_at_level_k(root1, 1));

        /*
         * Test 2: Test a basic case of root with two child nodes. Test the
         *         number of nodes at all valid and invalid levels in the
         *         binary tree.
         */
        treenode root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        assert(0 == get_number_of_node_at_level_k(root2, 0));
        assert(1 == get_number_of_node_at_level_k(root2, 1));
        assert(2 == get_number_of_node_at_level_k(root2, 2));
        assert(0 == get_number_of_node_at_level_k(root2, 3));

        /*
         * Test 3: Test a basic case of binary tree having three levels. Test
         *         the number of nodes at all valid and invalid levels in the
         *         binary tree.
         */
        treenode root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.right = new treenode(30);
        root3.left.right = new treenode(40);
        root3.right.right = new treenode(50);
        assert(0 == get_number_of_node_at_level_k(root3, 0));
        assert(1 == get_number_of_node_at_level_k(root3, 1));
        assert(2 == get_number_of_node_at_level_k(root3, 2));
        assert(2 == get_number_of_node_at_level_k(root3, 3));
        assert(0 == get_number_of_node_at_level_k(root3, 4));

        /*
         * Test 4: Test a basic case of binary tree having many levels. Test
         *         the number of nodes at all valid and invalid levels in the
         *         binary tree.
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
        assert(0 == get_number_of_node_at_level_k(root4, 0));
        assert(1 == get_number_of_node_at_level_k(root4, 1));
        assert(2 == get_number_of_node_at_level_k(root4, 2));
        assert(3 == get_number_of_node_at_level_k(root4, 3));
        assert(2 == get_number_of_node_at_level_k(root4, 4));
        assert(0 == get_number_of_node_at_level_k(root4, 5));
    }
}
