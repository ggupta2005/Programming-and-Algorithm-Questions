/*
 * This program finds the inorder predecessor of a value in the binary search
 * tree. If the value doesn't exist in the binary search tree or if the value
 * is the maximum value in the binary search tree, then the predecessor
 * returned is null. For more information on this problem, please visit the
 * following link:-
 * http://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
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

public class binary_search_tree_find_value_predecessor
{
    treenode root;

    binary_search_tree_find_value_predecessor ()
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
     * the maximum value in the binary search tree. THe maximum value in the
     * binary search tree is the right most node in the tree.
     */
    public static treenode get_maximum_val_binary_search_tree (treenode root)
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
     * node which is the predecessor to the node containing the data which is
     * equal to the 'value'. If the 'value' does not exist in the binary
     * search tree or the predecessor is not valid, then this function returns
     * null.
     */
    public treenode get_predecessor_binary_search_tree (int value)
    {
        treenode value_node = null;
        treenode current = null;
        treenode predecessor_node = null;

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
         * If the left child of the binary search tree node containing
         * 'value' is not null, then find the maximum value of in the
         * left sub-tree as this maximum value is the predecessor of
         * 'value'
         */
        if (value_node.left != null) {
            predecessor_node =
                get_maximum_val_binary_search_tree(value_node.left);
        } else {

            /*
             * Otherwise, if the left subtree of the binary search
             * tree node containing 'value' is null, then find the
             * predecessor from the top of the tree.
             */
            predecessor_node = null;
            current = root;
            while (current != null) {
                if (value < current.data) {

                    /*
                     * If 'value' is less than the current node, move to
                     * the right subtree
                     */
                    current = current.left;
                } else if (value > current.data) {

                    /*
                     * If 'value' is more than the current node, then
                     * record the predecessor and move to the left subtree
                     */
                    predecessor_node = current;
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
         * Return the reference to the predecessor node
         */
        return(predecessor_node);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: The root node is null. The predecessor treenode returned by
         *         the function should be null.
         */
        binary_search_tree_find_value_predecessor root0 = new
                                  binary_search_tree_find_value_predecessor();
        assert(null == root0.get_predecessor_binary_search_tree(10));

        /*
         * Test 1: The binary search tree has only one node. The predecessor
         *         of the root node should be null.
         */
        binary_search_tree_find_value_predecessor root1 = new
                                  binary_search_tree_find_value_predecessor();
        root1.insert_into_binary_search_tree(10);
        assert(null == root1.get_predecessor_binary_search_tree(10));

        /*
         * Test 2: The binary search tree has more than one node. The
         *         predecessor of the following cases should be following:-
         *         1. The predecessor of the maximum value in the BST should
         *            not be null.
         *         2. The predecessor of the minimum value in the BST should
         *            be null.
         *         3. The predecessor of a value having a valid left child
         *            shouldn't be null
         *         4. The predecessor of a non-maximum value not having a
         *            valid left child shouldn't be null.
         */
        binary_search_tree_find_value_predecessor root2 = new
                                  binary_search_tree_find_value_predecessor();
        treenode predecessor_node2 = null;
        root2.insert_into_binary_search_tree(100);
        root2.insert_into_binary_search_tree(70);
        root2.insert_into_binary_search_tree(40);
        root2.insert_into_binary_search_tree(90);
        root2.insert_into_binary_search_tree(50);
        root2.insert_into_binary_search_tree(60);
        root2.insert_into_binary_search_tree(170);
        root2.insert_into_binary_search_tree(140);
        root2.insert_into_binary_search_tree(190);
        root2.insert_into_binary_search_tree(150);
        root2.insert_into_binary_search_tree(160);
        predecessor_node2 =
                root2.get_predecessor_binary_search_tree(190);
        assert((null != predecessor_node2) && (170 == predecessor_node2.data));
        predecessor_node2 =
                root2.get_predecessor_binary_search_tree(40);
        assert(null == predecessor_node2);
        predecessor_node2 =
                root2.get_predecessor_binary_search_tree(100);
        assert((null != predecessor_node2) && (90 == predecessor_node2.data));
        predecessor_node2 =
                root2.get_predecessor_binary_search_tree(50);
        assert((null != predecessor_node2) && (40 == predecessor_node2.data));

        /*
         * Test 3: The binary search tree has more than one node. The
         *         predecessor of a value which does not exist in the binary
         *         search tree should be null.
         */
        binary_search_tree_find_value_predecessor root3 = new
                                  binary_search_tree_find_value_predecessor();
        root3.insert_into_binary_search_tree(100);
        root3.insert_into_binary_search_tree(50);
        root3.insert_into_binary_search_tree(40);
        root3.insert_into_binary_search_tree(70);
        assert(null == root3.get_predecessor_binary_search_tree(10));
    }
}
