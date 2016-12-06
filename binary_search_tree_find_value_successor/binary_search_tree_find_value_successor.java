/*
 * This program finds the inorder successor of a value in the binary search
 * tree. If the value doesn't exist in the binary search tree or if the value
 * is the maximum value in the binary search tree, then the successor returned
 * is null. For more information on this problem, please visit the following
 * link:- http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
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

public class binary_search_tree_find_value_successor
{
    treenode root;

    binary_search_tree_find_value_successor ()
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
    public static treenode get_minimum_val_binary_search_tree (treenode root)
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
     * This function returns the address reference to the binary search tree
     * node which contains the number equal to 'value'. If no such value
     * exists in the binary search tree, then this function returns null.
     */
    public treenode find_node_for_value_binary_search_tree (int value)
    {
        treenode current;

        /*
         * If the root node of the binary search tree in null,
         * then return null from this function.
         */
        if (root == null) {
            return(null);
        }

        /*
         * Set 'current' to the root node
         */
        current = root;

        /*
         * Iterate in the binary search tree, until 'current' is
         * null
         */
        while (current != null) {

            if (current.data == value) {

                /*
                 * If the 'value' is found in the current node, then
                 * dis-continue the loop
                 */
                break;
            } else if (value < current.data) {

                /*
                 * If the 'value' is less than the data in the
                 * current node, then move to the left sub-tree
                 */
                current = current.left;
            } else {

                /*
                 * If the 'value' is more than the data in the
                 * current node, then move to the right sub-tree
                 */
                current = current.right;
            }
        }

        /*
         * Return the address reference of the node containing
         * 'value'
         */
        return(current);
    }

    /*
     * This function returns the address reference of the binary search tree
     * node which is the successor to the node containing the data which is
     * equal to the 'value'. If the 'value' does not exist in the binary
     * search tree or the successor is not valid, then this function returns
     * null.
     */
    treenode get_successor_binary_search_tree (int value)
    {
        treenode value_node = null;
        treenode current = null;
        treenode successor_node = null;

        /*
         * If the root of the binary search tree is null, then return
         * null from this function.
         */
        if (root == null) {
            return(null);
        }

        /*
         * Find the address reference to the binary search tree node
         * containing 'value'.
         */
        value_node = find_node_for_value_binary_search_tree(value);

        /*
         * If the reference to the binary search tree node containing
         * 'value' is null, then return null from this function.
         */
        if (value_node == null) {
            return(null);
        }

        /*
         * If the right child of the binary search tree node containing
         * 'value' is not null, then find the minimum value of in the
         * right sub-tree as this minimum value is the successor of
         * 'value'
         */
        if (value_node.right != null) {
            successor_node =
                get_minimum_val_binary_search_tree(value_node.right);
        } else {

            /*
             * Otherwise, if the right subtree of the binary search
             * tree node containing 'value' is null, then find the
             * successor from the top of the tree.
             */
            successor_node = null;
            current = root;
            while (current != null) {

                if (value < current.data) {

                    /*
                     * If 'value' is less than the current node, then
                     * record the successor and move to the left subtree
                     */
                    successor_node = current;
                    current = current.left;
                } else if (value > current.data) {

                    /*
                     * If 'value' is more than the current node, move to
                     * the right subtree
                     */
                    current = current.right;
                } else {

                    /*
                     * If 'value' is equal to the current node, then break
                     * from this loop
                     */
                    break;
                }
            }
        }

        /*
         * Return the reference to the successor node
         */
        return(successor_node);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: The root node is null. The successor treenode returned by
         *         the function should be null.
         */
        binary_search_tree_find_value_successor root0 =
                                new binary_search_tree_find_value_successor();
        assert(null == root0.get_successor_binary_search_tree(10));

        /*
         * Test 1: The binary search tree has only one node. The successor
         *         of the root node should be null.
         */
        binary_search_tree_find_value_successor root1 =
                                new binary_search_tree_find_value_successor();
        root1.insert_into_binary_search_tree(10);
        assert(null == root1.get_successor_binary_search_tree(10));

        /*
         * Test 2: The binary search tree has more than one node. The
         *         successor of the following cases should be following:-
         *         1. The successor of the maximum value in the BST should
         *            be null.
         *         2. The successor of the minimum value in the BST should
         *            not be null.
         *         3. The successor of a value having a valid right child
         *            shouldn't be null
         *         4. The successor of a non-maximum value not having a
         *            valid right child shouldn't be null.
         */
        binary_search_tree_find_value_successor root2 =
                                new binary_search_tree_find_value_successor();
        treenode successor_node2 = null;
        root2.insert_into_binary_search_tree(100);
        root2.insert_into_binary_search_tree(50);
        root2.insert_into_binary_search_tree(40);
        root2.insert_into_binary_search_tree(70);
        root2.insert_into_binary_search_tree(80);
        root2.insert_into_binary_search_tree(20);
        root2.insert_into_binary_search_tree(10);
        root2.insert_into_binary_search_tree(150);
        root2.insert_into_binary_search_tree(130);
        root2.insert_into_binary_search_tree(170);
        root2.insert_into_binary_search_tree(180);
        root2.insert_into_binary_search_tree(110);
        root2.insert_into_binary_search_tree(140);
        successor_node2 = root2.get_successor_binary_search_tree(180);
        assert(null == successor_node2);
        successor_node2 = root2.get_successor_binary_search_tree(10);
        assert((null != successor_node2) && (20 == successor_node2.data));
        successor_node2 = root2.get_successor_binary_search_tree(100);
        assert((null != successor_node2) && (110 == successor_node2.data));
        successor_node2 = root2.get_successor_binary_search_tree(40);
        assert((null != successor_node2) && (50 == successor_node2.data));

        /*
         * Test 3: The binary search tree has more than one node. The
         *         successor of a value which does not exist in the binary
         *         search tree should be null.
         */
        binary_search_tree_find_value_successor root3 =
                                new binary_search_tree_find_value_successor();
        root3.insert_into_binary_search_tree(100);
        root3.insert_into_binary_search_tree(50);
        root3.insert_into_binary_search_tree(40);
        root3.insert_into_binary_search_tree(70);
        assert(null == root3.get_successor_binary_search_tree(10));
    }
}
