/*
 * This program finds the binary search tree node which has the
 * the closest data value to a given input value.
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

public class binary_search_tree_find_closest_node_to_a_given_value
{
    treenode root;

    binary_search_tree_find_closest_node_to_a_given_value ()
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
     * This functon finds the the binary search tree node whose data value
     * is the closest to a given value. If the root node of the binary search
     * tree is null, then this function returns null. the time complexity of
     * this function is O(log(n)) in best and average case, where 'n' is the
     * number of nodes in the binary search tree. The worst case time
     * complexity of this function is O(n).
     */
    treenode get_closest_node_to_a_given_value (int value)
    {
        treenode current;
        treenode closest;
        int min;

        /*
         * If root node is null, then return null from the function
         */
        if (root == null) {
            return(null);
        }

        min = Integer.MAX_VALUE; /* Set minimum value difference to
                                    maximum integer value */
        current = root; /* Set the current pointer to root of the tree */
        closest = null;  /* Set the closest value node to null */
        while (current != null) {

            /*
             * If the difference between the current node value and the
             * 'value' is less than the minimum difference, then update
             * the minimum value difference and the closest node pointer
             */
            if (min > Math.abs(current.data - value)) {
                closest = current;
                min = Math.abs(current.data - value);
            }

            /*
             * If 'value' is lesser than the current node data value,
             * then move to the left subtree otherwise move to the
             * right subtree.
             */
            if (current.data > value) {
                current = current.left;
            } else {
                current = current.right;
            }
        }

        /*
         * Return the cpointer closest node pointer
         */
        return(closest);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with an empty binary search tree. The node
         *         having closest value to a given value should be
         *         null.
         */
        binary_search_tree_find_closest_node_to_a_given_value obj0 =
               new binary_search_tree_find_closest_node_to_a_given_value();
        treenode closest0 = null;
        closest0 = obj0.get_closest_node_to_a_given_value(10);
        assert(null == closest0);

        /*
         * Test 1: Test with a binary search tree having only one node.
         *         The node having closest value to a given value should be
         *         non-null and its value should be the value in the root
         *         node.
         */
        binary_search_tree_find_closest_node_to_a_given_value obj1 =
               new binary_search_tree_find_closest_node_to_a_given_value();
        treenode closest1 = null;
        obj1.insert_into_binary_search_tree(10);
        closest1 = obj1.get_closest_node_to_a_given_value(obj1.root.data);
        assert((null != closest1) && (closest1.data == obj1.root.data));;
        closest1 = obj1.get_closest_node_to_a_given_value(obj1.root.data - 1);
        assert((null != closest1) && (closest1.data == (obj1.root.data)));;
        closest1 = obj1.get_closest_node_to_a_given_value(obj1.root.data + 1);
        assert((null != closest1) && (closest1.data == (obj1.root.data)));;

        /*
         * Test 2: Test with a binary search tree having only many nodes.
         *         The node having closest value to a given value should be
         *         non-null and its value should be the closest to the input
         *         value.
         */
        binary_search_tree_find_closest_node_to_a_given_value obj2 =
               new binary_search_tree_find_closest_node_to_a_given_value();
        treenode closest2 = null;
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
        closest2 = obj2.get_closest_node_to_a_given_value(101);
        assert((null != closest2) && (100 == closest2.data));
        closest2 = obj2.get_closest_node_to_a_given_value(145);
        assert((null != closest2) && (140 == closest2.data));
        closest2 = obj2.get_closest_node_to_a_given_value(163);
        assert((null != closest2) && (160 == closest2.data));
    }
}
