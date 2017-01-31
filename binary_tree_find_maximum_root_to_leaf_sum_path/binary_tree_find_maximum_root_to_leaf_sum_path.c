/*
 * This program finds the maximum sum for a root to leaf path. For more
 * infomation on this problem, please refer to the following link:-
 * http://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

/*
 * Structure definition for tree node
 */
struct treenode {
    int data;
    struct treenode* left;
    struct treenode* right;
};

/*
 * This function allocates a tree node and sets the data field
 * in the node to be equal to 'val'.
 */
struct treenode* make_treenode (int val)
{
    struct treenode* new_node =
            (struct treenode*)malloc(sizeof(struct treenode));

    if (!new_node) {
        return(NULL);
    }

    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    return(new_node);
}

/*
 * This fnction returns the maximum path sum from root of the binary
 * tree to any of its leaf. The time complexity of this function is
 * O(n), where 'n' is the number of nodes in the binary tree. The
 * space complexity of this function is O(n) since this function
 * uses recursion.
 */
int find_maximum_root_to_leaf_path_sum (struct treenode* root)
{
    int left_sum, right_sum;
    bool if_left_subtree, if_right_subtree;

    /*
     * If the root of the tree in NULL, then return zero
     */
    if (!root) {
        return(0);
    }

    if_left_subtree = false;
    if (root->left) {

        /*
         * Find the maximum path sum from root to some leaf in the
         * left leaf.
         */
        left_sum = root->data +
                    find_maximum_root_to_leaf_path_sum(root->left);
        if_left_subtree = true;
    }

    if_right_subtree = false;
    if (root->right) {

        /*
         * Find the maximum path sum from root to some leaf in the
         * right leaf.
         */
        right_sum = root->data +
                     find_maximum_root_to_leaf_path_sum(root->right);
        if_right_subtree = true;
    }

    if (if_left_subtree && if_right_subtree) {

        /*
         * If the root node has non-empty left and right subtrees,
         * then return the maximum path sum among the left and right
         * subtrees.
         */
        return(left_sum > right_sum ? left_sum : right_sum);
    } else if (if_left_subtree) {

        /*
         * If right subtree is NULL, then return the left subtree
         * maximum path sum.
         */
        return(left_sum);
    } else if (if_right_subtree) {

        /*
         * If left subtree is NULL, then return the right subtree
         * maximum path sum.
         */
        return(right_sum);
    }

    /*
     * Otherwise return the data value in the leaf node.
     */
    return(root->data);
}

int main ()
{
    /*
     * Test 0: Test with root being NULL. The maximum path sum from
     *         root to leaf should be zero.
     */
    struct treenode* root0 = NULL;
    assert(0 == find_maximum_root_to_leaf_path_sum(root0));

    /*
     * Test 1: Test with root being the only node. The maximum path sum
     *         from root to leaf should be value in root node.
     */
    struct treenode* root1 = NULL;
    root1 = make_treenode(10);
    assert(10 == find_maximum_root_to_leaf_path_sum(root1));

    /*
     * Test 2: Test with the root having one left and one right
     *         child. The maximum path sum from root to leaf should
     *         be maximum sum of value in root node and value in either
     *         left or right leaf node.
     */
    struct treenode* root2 = NULL;
    root2 = make_treenode(10);
    root2->left = make_treenode(20);
    root2->right = make_treenode(30);
    assert((root2->data +
            ((root2->left->data > root2->right->data) ?
                   (root2->left->data) : (root2->right->data))) ==
            find_maximum_root_to_leaf_path_sum(root2));

    /*
     * Test 3: Test with many leaves being present in both left and
     *         right subtrees. All nodes of binary tree contain positive
     *         values. The function should return the maximum path sum
     *         from root to leaf.
     */
    struct treenode* root3 = NULL;
    root3 = make_treenode(10);
    root3->left = make_treenode(20);
    root3->left->left = make_treenode(30);
    root3->right = make_treenode(40);
    root3->right->left = make_treenode(50);
    assert(100 == find_maximum_root_to_leaf_path_sum(root3));

    /*
     * Test 4: Test with many leaves being present in both left and
     *         right subtrees. All nodes of binary tree contain negative
     *         values. The function should return the maximum path sum
     *         from root to leaf.
     */
    struct treenode* root4 = NULL;
    root4 = make_treenode(-10);
    root4->left = make_treenode(-20);
    root4->left->left = make_treenode(-30);
    root4->right = make_treenode(-40);
    root4->right->left = make_treenode(-50);
    assert(-60 == find_maximum_root_to_leaf_path_sum(root4));

    return(0);
}
