/*
 * This program finds the minimum and maximum value in a binary
 * search tree. This binary search tree can have only distinct values.
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

public class binary_search_tree_find_min_max_value
{
    treenode root;

    binary_search_tree_find_min_max_value ()
    {
        root = null;
    }

    /*
     * This function inserts an integer value in the binary search tree.
     * As per the definitions of a binary search tree the values in the
     * left subtree are strictly less than the values in the right sub-tree.
     */
    public void insert_into_binary_search_tree (int val)
    {
        treenode new_node = null;
        treenode current;
        treenode parent;

        /*
         * Allocate a new node for 'val'
         */
        new_node = new treenode(val);

        /*
         * If the allocation of memory is unsuccessful, then return from
         * this function.
         */
        if (new_node == null) {
            return;
        }

        /*
         * If the root pointer is null, then set the root pointer of the
         * binary search tree to point to the new_node and return.
         */
        if (root == null) {
            root = new_node;
            return;
        }

        /*
         * Iterate hrough the binary search tree unless, we find the
         * appropriate parent node to insert the new node.
         */
        current = root;
        parent = null;
        while (current != null) {
            parent = current;

            /*
             * The the value of the current node is greater than the
             * 'val', then move to the left sub-tree otherwise move to
             * right sub-tree.
             */
            if (current.data > val) {
                current = current.left;
            } else {
                current = current.right;
            }
        }

        /*
         * If there is a valid parent node, then insert the new_node
         * in the binary search tree.
         */
        if (parent != null) {

            /*
             * If the 'val' is less than the parent's data, then insert
             * the new_node as the left child otherwise insert the child
             * as the right child.
             */
            if (parent.data > val) {
                parent.left = new_node;
            } else {
                parent.right = new_node;
            }
        }
    }

    /*
     * This function returns the pointer reference the node which carries
     * the minimum value in the binary search tree. THe minimum value in the
     * binary search tree is the left most node in the tree.
     */
    public treenode get_minimum_val_binary_search_tree ()
    {
        treenode current;

        /*
         * If root node is null, then return null from the function.
         */
        if (root == null) {
            return(null);
        }

        /*
         * Set 'current' to the root of the tree. Iterate unless the left
         * child of 'current' is found to be null.
         */
        current = root;
        while (current.left != null) {
            current = current.left;
        }

        /*
         * Return the reference to the node carrying minimum value.
         */
        return(current);
    }

    /*
     * This function returns the pointer reference the node which carries
     * the maximum value in the binary search tree. THe maximum value in the
     * binary search tree is the right most node in the tree.
     */
    public treenode get_maximum_val_binary_search_tree ()
    {
        treenode current;

        /*
         * If root node is null, then return null from the function.
         */
        if (root == null) {
            return(null);
        }

        /*
         * Set 'current' to the root of the tree. Iterate unless the right
         * child of 'current' is found to be null.
         */
        current = root;
        while (current.right != null) {
            current = current.right;
        }

        /*
         * Return the reference to the node carrying maximum value.
         */
        return(current);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: The root node is null. The treenode returned by the minimum
         *         or maximum functions should be null.
         */
        binary_search_tree_find_min_max_value bst0 =
                                new binary_search_tree_find_min_max_value();
        assert(null == bst0.get_minimum_val_binary_search_tree());
        assert(null == bst0.get_maximum_val_binary_search_tree());

        /*
         * Test 1: The binary search tree has only one node. The get minimum
         *         or maximum functions should return this node itself
         */
        binary_search_tree_find_min_max_value bst1 =
                                new binary_search_tree_find_min_max_value();
        bst1.insert_into_binary_search_tree(10);
        assert(10 == (bst1.get_minimum_val_binary_search_tree()).data);
        assert(10 == (bst1.get_maximum_val_binary_search_tree()).data);

        /*
         * Test 2: The binary search tree has many nodes inserted one after
         *         another. The get minimum function should return the smallest
         *         value. The get maximum function should return the largest
         *         value.
         */
        binary_search_tree_find_min_max_value bst2 =
                                new binary_search_tree_find_min_max_value();

        /*
         * Intialize the minimum and maximum values to the limits allowed
         * by java.
         */
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        Random rand = new Random();

        /*
         * Generate 100 andom numbers between 0 and 99 inclusive
         */
        for (int i = 0; i < 100; ++i) {
            int num = rand.nextInt(100);

            /*
             * Add the randomly generated number in the binary search
             * tree
             */
            bst2.insert_into_binary_search_tree(num);

            /*
             * Record the maximum number generated so far
             */
            if (num > max) {
                max = num;
            }

            /*
             * Record the minimum number generated so far
             */
            if (num < min) {
                min = num;
            }
        }

        /*
         * Check if the minimum value exists is same as the minimum value
         * gotten from the binary search tree
         */
        assert(min == (bst2.get_minimum_val_binary_search_tree()).data);

        /*
         * Check if the maximum value exists is same as the maximum value
         * gotten from the binary search tree
         */
        assert(max == (bst2.get_maximum_val_binary_search_tree()).data);
    }
}
