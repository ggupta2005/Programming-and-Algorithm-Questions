/*
 * This program checks if two binary trees are identical. Two binary trees
 * are said to identical if they are structurally same and if the nodes have
 * the same value. For more iformation on this problem, please refer to the
 * following link:-
 * http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
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
     * Test 0: The two tree root nodes are NULL. The binary trees
     *         should be identical.
     */
    struct treenode* root10 = NULL;
    struct treenode* root20 = NULL;
    assert(true == check_if_two_binary_tree_are_dentical(
                                                root10, root20));

    /*
     * Test 1: The one of tree root node is not NULL while other
     *         is  NULL. The binary trees should not be identical.
     */
    struct treenode* root11 = NULL;
    struct treenode* root21 = NULL;
    root11 = makenode(10);
    assert(false == check_if_two_binary_tree_are_dentical(
                                                root11, root21));

    /*
     * Test 2: The one of tree root node is not NULL while other
     *         is  NULL. The binary trees should not be identical.
     */
    struct treenode* root12 = NULL;
    struct treenode* root22 = NULL;
    root22 = makenode(10);
    assert(false == check_if_two_binary_tree_are_dentical(
                                                root12, root22));

    /*
     * Test 3: Both the binary tree root nodes are non-NULL and
     *         contain only one element with same value. The
     *         binary trees should be identical.
     */
    struct treenode* root13 = NULL;
    struct treenode* root23 = NULL;
    root13 = makenode(10);
    root23 = makenode(10);
    assert(true == check_if_two_binary_tree_are_dentical(
                                                root13, root23));

    /*
     * Test 4: Both the binary tree root nodes are non-NULL and
     *         contain only one element with different values. The
     *         binary trees should not be identical.
     */
    struct treenode* root14 = NULL;
    struct treenode* root24 = NULL;
    root14 = makenode(10);
    root24 = makenode(20);
    assert(false == check_if_two_binary_tree_are_dentical(
                                                root14, root24));

    /*
     * Test 5: Test with two binary trees having many nodes. The
     *         trees are structurally same and have the same value
     *         in the nodes. The two binary trees should be same.
     */
    struct treenode* root15 = NULL;
    struct treenode* root25 = NULL;
    root15 = makenode(20);
    root15->left = makenode(40);
    root15->right = makenode(60);
    root15->left->right = makenode(80);
    root15->left->left = makenode(100);
    root15->right->left = makenode(120);
    root15->right->left->left = makenode(140);
    root15->right->left->right = makenode(160);
    root25 = makenode(20);
    root25->left = makenode(40);
    root25->right = makenode(60);
    root25->left->right = makenode(80);
    root25->left->left = makenode(100);
    root25->right->left = makenode(120);
    root25->right->left->left = makenode(140);
    root25->right->left->right = makenode(160);
    assert(true == check_if_two_binary_tree_are_dentical(
                                                root15, root25));

    /*
     * Test 6: Test with two binary trees having many nodes. The
     *         trees are structurally same and but have different
     *         value in the nodes. The two binary trees should be
     *         different.
     */
    struct treenode* root16 = NULL;
    struct treenode* root26 = NULL;
    root16 = makenode(20);
    root16->left = makenode(40);
    root16->right = makenode(60);
    root16->left->right = makenode(80);
    root16->left->left = makenode(100);
    root16->right->left = makenode(120);
    root16->right->left->left = makenode(140);
    root16->right->left->right = makenode(160);
    root26 = makenode(20);
    root26->left = makenode(40);
    root26->right = makenode(60);
    root26->left->right = makenode(80);
    root26->left->left = makenode(110);
    root26->right->left = makenode(130);
    root26->right->left->left = makenode(140);
    root26->right->left->right = makenode(160);
    assert(false == check_if_two_binary_tree_are_dentical(
                                                root16, root26));

    /*
     * Test 7: Test with two binary trees having many nodes. The
     *         trees are structurally different  The two binary
     *         trees should be different.
     */
    struct treenode* root17 = NULL;
    struct treenode* root27 = NULL;
    root17 = makenode(20);
    root17->left = makenode(40);
    root17->right = makenode(70);
    root17->left->right = makenode(80);
    root17->left->left = makenode(100);
    root17->right->left = makenode(120);
    root27 = makenode(20);
    root27->left = makenode(40);
    root27->right = makenode(70);
    root27->left->right = makenode(80);
    root27->left->left = makenode(100);
    root27->right->left = makenode(120);
    root27->right->left->left = makenode(140);
    root27->right->left->right = makenode(160);
    assert(false == check_if_two_binary_tree_are_dentical(
                                                root17, root27));

    return(0);
}

