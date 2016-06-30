/*
 * This program finds if two values belong to the nodes who
 * are siblings of each other. That is the value nodes have
 * a common parent.
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

public class binary_tree_if_two_nodes_siblings
{

    /*
     * This function returs true if the node which have values 'val1' and
     * 'val2' are siblings of each other, that is if the nodes having
     * values 'val1' and 'val2' belong to the same parent.
     */
    public static boolean if_val_belong_to_siblings (treenode root,
                                                     int val1,
                                                     int val2)
    {
        /*
         * Base case when root node is NULL. The sibling pair could
         * not be found. Return false.
         */
        if (root == null) {
            return(false);
        }

        /*
         * Base case when root node and its child nodes are not NULL.
         * The sibling pair could be found. Test the left and the right
         * child nodes.
         */
        if ((root.left != null) && (root.right != null)) {
            if (root.left.data == val1 &&
                root.right.data == val2) {
                return(true);
            }

            if (root.left.data == val2 &&
                root.right.data == val1) {
                return(true);
            }
        }

        /*
         * If the sibling pair could not be found in the current root
         * node, then recursively find the values in the left and
         * the right subtrees.
         */
        return(if_val_belong_to_siblings(root.left, val1, val2) ||
               if_val_belong_to_siblings(root.right, val1, val2));
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Find siblings in NULL tree root
         */
        treenode root1 = null;
        assert false == if_val_belong_to_siblings(root1, 10, 20);

        /*
         * Test2: The root itself contains the sibling pair
         */
        treenode root2 = null;
        root2 = new treenode(10);
        root2.left = new treenode(20);
        root2.right = new treenode(30);
        assert true == if_val_belong_to_siblings(root2, 30, 20);
        assert true == if_val_belong_to_siblings(root2, 20, 30);

        /*
         * Test 3: Even though the values exist in the binary
         *         tree, they are not sibling nodes
         */
        treenode root3 = null;
        root3 = new treenode(10);
        root3.left = new treenode(20);
        root3.right = new treenode(30);
        root3.left.right = new treenode(40);
        root3.right.right = new treenode(50);
        assert false == if_val_belong_to_siblings(root3, 40, 50);

        /*
         * Test 4: Test a sibling pair in the left sub-tree whose
         *         parent is not the root node.
         */
        treenode root4 = null;
        root4 = new treenode(10);
        root4.left = new treenode(20);
        root4.right = new treenode(30);
        root4.left.left = new treenode(40);
        root4.left.right = new treenode(50);
        root4.right.left = new treenode(60);
        root4.right.right = new treenode(70);
        assert true == if_val_belong_to_siblings(root4, 40, 50);
        assert true == if_val_belong_to_siblings(root4, 50, 40);

        /*
         * Test 5: Test a sibling pair in the right sub-tree whose
         *         parent is not the root node.
         */
        treenode root5 = null;
        root5 = new treenode(10);
        root5.left = new treenode(20);
        root5.right = new treenode(30);
        root5.left.left = new treenode(40);
        root5.left.right = new treenode(50);
        root5.right.left = new treenode(60);
        root5.right.left.right = new treenode(70);
        root5.right.left.left = new treenode(80);
        assert true == if_val_belong_to_siblings(root5, 70, 80);
        assert true == if_val_belong_to_siblings(root5, 80, 70);
    }
}
