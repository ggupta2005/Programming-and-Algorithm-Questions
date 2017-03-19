/*
 * Given a binary tree, check whether it is a mirror of itself.
 *
 * For example, this binary tree is symmetric:
 *
 *      1
 *    /   \
 *   2     2
 *  / \   / \
 * 3   4 4   3
 *
 * But the following is not:
 *
 *    1
 *   / \
 *  2   2
 *   \   \
 *   3    3
 *
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

public class binary_tree_check_if_symmetric_tree
{
    /*
     * This function returns 'true' if the two input binary trees are mirror
     * images of each other and 'false' otherwise. The time complexity of
     * this function is O(n), where 'n' is the number of nodes in the two
     * binary trees.
     */
    public static boolean if_trees_mirror_images (treenode root1,
                                                  treenode root2)
    {
        /*
         * If both root nodes of the binary trees are null, then
         * return 'true'
         */
        if ((root1 == null) && (root2 == null)) {
            return(true);
        }

        /*
         * If one of the root nodes of the binary trees is not null,
         * then return 'false'
         */
        if ((root1 == null) || (root2 == null)) {
            return(false);
        }

        /*
         * If the data in the two root nodes is not same, then
         * return 'false'
         */
        if (root1.data != root2.data) {
            return(false);
        }

        /*
         * Recursively check if the left subtree of first tree is
         * same as the right subtree of second tree and if the right
         * subtree of the of the first tree is same as the left
         * subtree of the second tree.
         */
        return(if_trees_mirror_images(root1.left, root2.right)
               && if_trees_mirror_images(root1.right, root2.left));
    }

    /*
     * This function returns 'true' if the left subtree and right subtree
     * are mirror images of each other otherwise this function returns
     * 'false'. The time complexity of this function O(n), where 'n' is
     * the number of nodes in the tree.
     */
    public static boolean check_if_tree_is_symmetric (treenode root)
    {
        /*
         * If the root node is NULL, then return 'true'
         */
        if (root == null) {
            return(true);
        }

        /*
         * Check if the left and right subtrees are mirror images
         * of each other
         */
        return(if_trees_mirror_images(root.left, root.right));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with an empty tree. This tree should be
         *         symmetric.
         */
        treenode root0 = null;
        assert(check_if_tree_is_symmetric(root0));

        /*
         * Test 1: Test with an empty tree. This tree should be
         *         symmetric.
         */
        treenode root1 = null;
        root1 = new treenode(10);
        assert(check_if_tree_is_symmetric(root1));

        /*
         * Test 2: Test with the following subtree which is
         *         symmetric.
         *      1
         *    /   \
         *   2     2
         *  / \   / \
         * 3   4 4   3
         *
         */
        treenode root2 = null;
        root2 = new treenode(1);
        root2.left = new treenode(2);
        root2.right = new treenode(2);
        root2.left.left = new treenode(3);
        root2.left.right = new treenode(4);
        root2.right.left = new treenode(4);
        root2.right.right = new treenode(3);
        assert(check_if_tree_is_symmetric(root2));

        /*
         * Test 3: Test with the following subtree which is
         *         not symmetric.
         *    1
         *   / \
         *  2   2
         *   \   \
         *   3    3
         *
         */
        treenode root3 = null;
        root3 = new treenode(1);
        root3.left = new treenode(2);
        root3.right = new treenode(2);
        root3.left.right = new treenode(3);
        root3.right.right = new treenode(3);
        assert(!check_if_tree_is_symmetric(root3));
    }
}
