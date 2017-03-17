
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

public class binary_search_tree_check_if_value_exists
{
    treenode root;

    binary_search_tree_check_if_value_exists ()
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
     * This function returns the reference of a node which contains the
     * data as 'val' in a binary search tree. If the 'val' does not
     * exists in the binary search tree, then this function returns
     * null. The time complxity of this function is O(log(n)) is best
     * average case and O(n) in worst case, where 'n' is the number of
     * nodes in the binary search tree.
     */
    treenode search_value_in_binary_search_tree (int val)
    {
        treenode current;

        /*
         * If the root is null, then return null
         */
        if (root == null) {
            return(null);
        }

        /*
         * Attempt to find 'val' in the tree while iterating
         * from root to leaf node in the binary search tree
         */
        current = root;
        while ((current != null) && (current.data != val)) {

            if (current.data > val) {

                /*
                 * If the data value in the current node is
                 * greater than 'val', then move to the left
                 * subtree.
                 */
                current = current.left;
            } else {
                /*
                 * If the data value in the current node is
                 * lesser than 'val', then move to the right
                 * subtree.
                 */
                current = current.right;
            }
        }

        /*
         * Return the reference of the node containing the
         * 'val'
         */
        return(current);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test to search for a value in an empty BST. The
         *         reference returned for the value should be null.
         */
        binary_search_tree_check_if_value_exists obj0 =
                    new binary_search_tree_check_if_value_exists();
        treenode value0 = null;
        value0 = obj0.search_value_in_binary_search_tree(10);
        assert(null == value0);

        /*
         * Test 1: Test to search for a value in a BST having one node.
         *         Following should be the test results for different
         *         cases:-
         *         1. If the value doesn't exist in the BST, then the
         *            reference returned for the value should be null.
         *         2. If the value exists in the BST, then the
         *            reference returned for the value should not be
         *            null.
         */
        binary_search_tree_check_if_value_exists obj1 =
                    new binary_search_tree_check_if_value_exists();
        treenode value1 = null;
        obj1.insert_into_binary_search_tree(10);
        value1 = obj1.search_value_in_binary_search_tree(obj1.root.data);
        assert((null != value1) && (value1.data == obj1.root.data));;
        value1 = obj1.search_value_in_binary_search_tree(obj1.root.data - 1);
        assert(null == value1);
        value1 = obj1.search_value_in_binary_search_tree(obj1.root.data + 1);
        assert(null == value1);

        /*
         * Test 2: Test to search for a value in a BST having many nodes.
         *         Following should be the test results for different
         *         cases:-
         *         1. If the value doesn't exist in the BST, then the
         *            reference returned for the value should be null.
         *         2. If the value exists in the BST, then the
         *            reference returned for the value should not be
         *            null.
         */
        binary_search_tree_check_if_value_exists obj2 =
                    new binary_search_tree_check_if_value_exists();
        treenode value2 = null;
        obj2.insert_into_binary_search_tree(100);
        obj2.insert_into_binary_search_tree(70);
        obj2.insert_into_binary_search_tree(40);
        obj2.insert_into_binary_search_tree(90);
        obj2.insert_into_binary_search_tree(50);
        obj2.insert_into_binary_search_tree(60);
        obj2.insert_into_binary_search_tree(170);
        obj2.insert_into_binary_search_tree(140);
        obj2.insert_into_binary_search_tree(190);
        obj2.insert_into_binary_search_tree(150);
        obj2.insert_into_binary_search_tree(160);
        value2 = obj2.search_value_in_binary_search_tree(100);
        assert((null != value2) && (100 == value2.data));
        value2 = obj2.search_value_in_binary_search_tree(160);
        assert((null != value2) && (160 == value2.data));
        value2 = obj2.search_value_in_binary_search_tree(40);
        assert((null != value2) && (40 == value2.data));
        value2 = obj2.search_value_in_binary_search_tree(45);
        assert(null == value2);
        value2 = obj2.search_value_in_binary_search_tree(85);
        assert(null == value2);
    }
}
