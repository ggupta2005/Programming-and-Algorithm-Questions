/*
 * This program finds whether a binary tree is a degenerate binary tree. A binary tree
 * is a degenerate binary tree if each node in the tree has exactly one child node. For
 * more on degenerate trees look at the link:-
 * https://webdocs.cs.ualberta.ca/~holte/T26/pb-with-bst.html
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
 * This function checks if the binary tree is de-generated. If the binary
 * tree is de-generated then this function rturns false else this function
 * returns true. To check if a binary tree is de-generated, we check if the
 * binary tree more than one child nodes. If the binary tree has more than
 * one child nodes, then the binary tree is not degenerated.
 */
bool check_if_binary_tree_is_degenerate (struct treenode* root)
{
    /*
     * If the root node is NULL, then the binary tree is de-genrated.
     * Return 'true'.
     */
    if (!root) {
        return(true);
    }

    /*
     * If the root node has both right and left sub-tress, then the
     * binary tree is not de-genrated. Return 'false'.
     */
    if (root->left && root->right) {
        return(false);
    }

    /*
     * If the root node is a part of de-generated binary tree, then
     * make sure both left and right sub-trees are de-generated binary
     * trees.
     */
    return(check_if_binary_tree_is_degenerate(root->left)
           && check_if_binary_tree_is_degenerate(root->right));
}

int main()
{
    /*
     * Test 0: In case root is NULL, then the tree is degenerated
     */
    struct treenode* root0 = NULL;
    assert(true == check_if_binary_tree_is_degenerate(root0));

    /*
     * Test 1: In this case the tree has only one node.
     *         Then the tree is degenerated
     */
    struct treenode* root1 = NULL;
    root1 = makenode(10);
    assert(true == check_if_binary_tree_is_degenerate(root1));

    /*
     * Test2: Test a basic case of root with two child nodes. This
     *        tree should not be a degenerated binary tree.
     */
    struct treenode* root2 = NULL;
    root2 = makenode(10);
    root2->left = makenode(20);
    root2->right = makenode(30);
    assert(false == check_if_binary_tree_is_degenerate(root2));

    /*
     * Test 3: Test a case when the binary tree is a linear linked list .
     *         That is this tree is degenrated towards the left subtree.
     */
    struct treenode* root3 = NULL;
    root3 = makenode(10);
    root3->left = makenode(20);
    root3->left->left = makenode(40);
    root3->left->left->left = makenode(40);
    assert(true == check_if_binary_tree_is_degenerate(root3));

    /*
     * Test 4: Test a case when the binary tree is a linear linked list .
     *         That is this tree is degenrated towards the right subtree.
     */
    struct treenode* root4 = NULL;
    root4 = makenode(10);
    root4->right = makenode(30);
    root4->right->right = makenode(60);
    root4->right->right->right = makenode(70);
    root4->right->right->right->right = makenode(80);
    assert(true == check_if_binary_tree_is_degenerate(root4));

    /*
     * Test 5: Test a case when the binary tree is a linear linked list .
     *         That is this tree is degenrated either towards the right or
     *         left subtrees.
     */
    struct treenode* root5 = NULL;
    root5 = makenode(10);
    root5->right = makenode(30);
    root5->right->right = makenode(60);
    root5->right->right->left = makenode(70);
    root5->right->right->left->left = makenode(80);
    root5->right->right->left->left->right = makenode(80);
    assert(true == check_if_binary_tree_is_degenerate(root5));

    return(0);
}
