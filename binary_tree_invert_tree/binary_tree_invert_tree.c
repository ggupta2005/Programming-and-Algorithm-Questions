/*
 * This program inverts the left and right subtrees of a binary tree that
 * is the right child of the root becomes its left child and the left child
 * of the root becomes its right child.
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
 * This function recursively inverts the left and right subtrees, that
 * is the left child of the root node becomes the right child and the
 * right child of the root child becomes its left child. The time
 * complexity of this function is O(n), where 'n' is the number of nodes
 * in the binary tree. The space complexity of this function is O(n),
 * since this a recursive function.
 */
void invert_tree (struct treenode* root)
{
    struct treenode* temp;

    /*
     * If the root node is NULL, then we do not need to perform
     * any inversions. So return from this function.
     */
    if (!root) {
        return;
    }

    /*
     * Swap the left and the right child nodes
     */
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    /*
     * Recursively invert the left and right subtrees
     */
    invert_tree(root->left);
    invert_tree(root->right);
}

/*
 * This function returns 'true' if the two binary trees are identical and
 * 'false' otherwise. Two binary trees are said to identical if they are
 * structurally same and if the nodes have the same value. The time
 * complexity of this function is O(n), where 'n' is the number of nodes
 * in the binary tree. The space complexity of this function is O(n),
 * since this a recursive function.
 */
bool check_if_two_binary_tree_are_dentical (struct treenode* root1,
                                            struct treenode* root2)
{
    /*
     * If both root1 and root2 are NULL, then binary tress are
     * identical. Return 'true'.
     */
    if (!root1 && !root2) {
        return(true);
    }

    /*
     * If either one of root1 and root2 are not NULL, then binary
     * tress are not identical. Return 'false'.
     */
    if (!root1 || !root2) {
        return(false);
    }

    /*
     * Check the following to find if the two binary trees
     * identical:-
     * 1. The data value in the root nodes are equal.
     * 2. The left subtree is identical
     * 3. The right subtree is identical
     */
    return((root1->data == root2->data) &&
           check_if_two_binary_tree_are_dentical(
                                root1->left, root2->left) &&
           check_if_two_binary_tree_are_dentical(
                                root1->right, root2->right));
}

int main ()
{
    /*
     * Test 0: Invert an empty binary tree. The binary tree should
     *         empty even after inversion.
     */
    struct treenode* root0 = NULL;
    struct treenode* exp_root0 = NULL;
    invert_tree(root0);
    assert(true == check_if_two_binary_tree_are_dentical(
                                            root0, exp_root0));

    /*
     * Test 1: Invert a binary tree having one node only. The binary
     *         tree should have the same node even after inversion.
     */
    struct treenode* root1 = NULL;
    struct treenode* exp_root1 = NULL;
    root1 = makenode(10);
    exp_root1 = makenode(10);
    invert_tree(root1);
    assert(true == check_if_two_binary_tree_are_dentical(
                                            root1, exp_root1));

    /*
     * Test 2: Invert a binary tree having one left child node and one
     *         right child node. The binary tree should have the left
     *         and right child nodes inter-changed after inversion.
     */
    struct treenode* root2 = NULL;
    struct treenode* exp_root2 = NULL;
    root2 = makenode(10);
    root2->left = makenode(20);
    root2->right = makenode(30);
    exp_root2 = makenode(10);
    exp_root2->left = makenode(30);
    exp_root2->right = makenode(20);
    invert_tree(root2);
    assert(true == check_if_two_binary_tree_are_dentical(
                                            root2, exp_root2));

    /*
     * Test 3: Invert a binary tree having empty left or right subtrees.
     *         The binary tree should have the left and right child nodes
     *         inter-changed after inversion.
     */
    struct treenode* root3 = NULL;
    struct treenode* exp_root3 = NULL;
    root3 = makenode(10);
    root3->left = makenode(20);
    root3->left->left = makenode(40);
    root3->right = makenode(30);
    root3->right->right = makenode(50);
    exp_root3 = makenode(10);
    exp_root3->left = makenode(30);
    exp_root3->left->left = makenode(50);
    exp_root3->right = makenode(20);
    exp_root3->right->right = makenode(40);
    invert_tree(root3);
    assert(true == check_if_two_binary_tree_are_dentical(
                                            root3, exp_root3));
    return(0);
}
