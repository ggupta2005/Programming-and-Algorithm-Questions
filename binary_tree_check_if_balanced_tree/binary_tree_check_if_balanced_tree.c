/*
 * This program checks if a binary tree is balanced. A binary tree is
 * balanced if the difference in maximum heights of the sub-trees is
 * not more than one and the left and right sub-trees are themselves
 * height balanced. For more information on balanced binary trees,
 * please refer to the following link:-
 * http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
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
struct treenode* makenode (int val)
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
 * This function recursively checks if a binary tree is height balanced
 * and returns 'true' if the binary tree is height balanced and 'false'
 * otherwise. A binary tree is balanced if the difference in maximum
 * heights of the sub-trees is not more than one and the left and right
 * sub-trees are themselves height balanced. This function implements the
 * following algorithm to check if a binary tree is balanced or not:-
 * 1. First check if each of the subtrees are height balanced and also
 *    get the maximum height from subtree root to its leaves. If one of
 *    the subtrees is not height balanced, then this function returns
 *    'false'.
 * 2. If the subtrees are themselves height balanced, then check the
 *    height difference between the maximum heights in the left and the
 *    right subtrees. If the difference in height is more than one, then
 *    return 'false'.
 * 3. Return 'true' since the tree is found to be height balanced.
 * The time complexity of this function is O(n), where 'n' is the number
 * of nodes in the binary tree. The space complexity is o(n), since we are
 * making one recursive call per node in the tree.
 */
bool check_if_binary_tree_is_height_balanced_recursive (struct treenode* root,
                                                        int* max_height)
{
    int left_depth;
    int right_depth;

    /*
     * If the current tree node is NULL, then set the 'max_height' as
     * zero and return 'true'.
     */
    if (!root) {
        *max_height = 0;
        return(true);
    }

    /*
     * If the current tree node is a leaf, then set the 'max_height' as
     * one and return 'true'.
     */
    if ((root->left == NULL) && (root->right == NULL)) {
        *max_height = 1;
        return(true);
    }

    /*
     * Recursively check if the left subtree is height balanced and also
     * get the maximum depth of the subtree. If the subtree is not
     * height balanced, then return 'false'.
     */
    if (!check_if_binary_tree_is_height_balanced_recursive(
                                           root->left, &left_depth)) {
        return(false);
    }

    /*
     * Recursively check if the right subtree is height balanced and also
     * get the maximum depth of the subtree. If the subtree is not
     * height balanced, then return 'false'.
     */
    if (!check_if_binary_tree_is_height_balanced_recursive(
                                           root->right, &right_depth)) {
        return(false);
    }

    /*
     * If the difference between the left and right subtree is more than
     * one, then return 'false'
     */
    if ((left_depth - right_depth) > 1) {
        *max_height = left_depth + 1;
        return(false);
    } else if ((right_depth - left_depth) > 1) {
        *max_height = right_depth + 1;
        return(false);
    }

    /*
     * Set 'max_height' as the maximum depth of the tree
     */
    if (left_depth > right_depth) {
        *max_height = left_depth + 1;
    } else {
        *max_height = right_depth + 1;
    }

    /*
     * Return 'true' as the tree is found to be height balanced
     */
    return(true);
}

/*
 * This function calls a recursive function to find if the binary tree
 * is height balanced.
 */
bool check_if_binary_tree_is_height_balanced (struct treenode* root)
{
    int max_height;

    return(check_if_binary_tree_is_height_balanced_recursive(
                                                root, &max_height));
}

int main ()
{
    /*
     * Test 0: In case root is NULL, then the tree is height balanced.
     */
    struct treenode* root0 = NULL;
    assert(true == check_if_binary_tree_is_height_balanced(root0));

    /*
     * Test 1: In this case the tree has only one node.
     *         So the tree is height balanced.
     */
    struct treenode* root1 = NULL;
    root1 = makenode(10);
    assert(true == check_if_binary_tree_is_height_balanced(root1));

    /*
     * Test 2: Test a basic case of root with two child nodes. This
     *         tree should be a height balanced  binary tree.
     */
    struct treenode* root2 = NULL;
    root2 = makenode(10);
    root2->left = makenode(20);
    root2->right = makenode(30);
    assert(true == check_if_binary_tree_is_height_balanced(root2));

    /*
     * Test 3: Test a case when the binary tree has the height
     *         difference of one with left subtree having a larger
     *         height. Then this tree should be a height balanced binary
     *         tree.
     */
    struct treenode* root3 = NULL;
    root3 = makenode(10);
    root3->left = makenode(20);
    root3->right = makenode(40);
    root3->left->left = makenode(50);
    assert(true == check_if_binary_tree_is_height_balanced(root3));

    /*
     * Test 4: Test a case when the binary tree has the height
     *         difference of one with right subtree having a larger
     *         height. Then this tree should be a height balanced binary
     *         tree.
     */
    struct treenode* root4 = NULL;
    root4 = makenode(10);
    root4->left = makenode(20);
    root4->right = makenode(40);
    root4->right->left = makenode(50);
    assert(true == check_if_binary_tree_is_height_balanced(root4));

    /*
     * Test 5: Test a case when the binary tree has the height
     *         difference of two with left subtree having a larger
     *         height. Then this tree should not be a height balanced
     *         binary tree.
     */
    struct treenode* root5 = NULL;
    root5 = makenode(10);
    root5->left = makenode(20);
    root5->right = makenode(40);
    root5->left->left = makenode(50);
    root5->left->left->right = makenode(60);
    assert(false == check_if_binary_tree_is_height_balanced(root5));

    /*
     * Test 6: Test a case when the binary tree has the height
     *         difference of two with right subtree having a larger
     *         height. Then this tree should not be a height balanced
     *         binary tree.
     */
    struct treenode* root6 = NULL;
    root6 = makenode(10);
    root6->left = makenode(20);
    root6->right = makenode(40);
    root6->right->left = makenode(50);
    root6->right->left->right = makenode(60);
    assert(false == check_if_binary_tree_is_height_balanced(root6));

    return(0);
}
