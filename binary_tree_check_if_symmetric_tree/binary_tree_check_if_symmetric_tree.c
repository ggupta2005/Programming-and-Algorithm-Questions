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
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

/*
 * Structure definition for tree node
 */
struct treenode
{
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

    if (!new_node)
        return(NULL);

    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    return(new_node);
}

/*
 * This function returns 'true' if the two input binary trees are mirror
 * images of each other and 'false' otherwise. The time complexity of
 * this function is O(n), where 'n' is the number of nodes in the two
 * binary trees.
 */
bool if_trees_mirror_images (struct treenode* root1, struct treenode* root2)
{
    /*
     * If both root nodes of the binary trees are NULL, then
     * return 'true'
     */
    if (!root1 && !root2) {
        return(true);
    }

    /*
     * If one of the root nodes of the binary trees is not NULL,
     * then return 'false'
     */
    if (!root1 || !root2) {
        return(false);
    }

    /*
     * If the data in the two root nodes is not same, then
     * return 'false'
     */
    if (root1->data != root2->data) {
        return(false);
    }

    /*
     * Recursively check if the left subtree of first tree is
     * same as the right subtree of second tree and if the right
     * subtree of the of the first tree is same as the left
     * subtree of the second tree.
     */
    return(if_trees_mirror_images(root1->left, root2->right)
           && if_trees_mirror_images(root1->right, root2->left));
}

/*
 * This function returns 'true' if the left subtree and right subtree
 * are mirror images of each other otherwise this function returns
 * 'false'. The time complexity of this function O(n), where 'n' is
 * the number of nodes in the tree.
 */
bool check_if_tree_is_symmetric (struct treenode* root)
{
    /*
     * If the root node is NULL, then return 'true'
     */
    if (!root) {
        return(true);
    }

    /*
     * Check if the left and right subtrees are mirror images
     * of each other
     */
    return(if_trees_mirror_images(root->left, root->right));
}

int main ()
{
    /*
     * Test 0: Test with an empty tree. This tree should be
     *         symmetric.
     */
    struct treenode* root0 = NULL;
    assert(check_if_tree_is_symmetric(root0));

    /*
     * Test 1: Test with an empty tree. This tree should be
     *         symmetric.
     */
    struct treenode* root1 = NULL;
    root1 = makenode(10);
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
    struct treenode* root2 = NULL;
    root2 = makenode(1);
    root2->left = makenode(2);
    root2->right = makenode(2);
    root2->left->left = makenode(3);
    root2->left->right = makenode(4);
    root2->right->left = makenode(4);
    root2->right->right = makenode(3);
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
    struct treenode* root3 = NULL;
    root3 = makenode(1);
    root3->left = makenode(2);
    root3->right = makenode(2);
    root3->left->right = makenode(3);
    root3->right->right = makenode(3);
    assert(!check_if_tree_is_symmetric(root3));

    return(0);
}

