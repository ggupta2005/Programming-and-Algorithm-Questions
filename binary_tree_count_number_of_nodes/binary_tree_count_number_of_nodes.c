/*
 * This program finds the number of nodes in a binary tree.
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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
 * This function recursively computes the number of nodes in a binary tree.
 * The time complexity of this function is O(n) since we are visiting each
 * node once.
 */
int find_number_of_nodes_binary_tree (struct treenode* root)
{
    /*
     * If the root node is NULL, then return zero.
     */
    if (!root) {
        return(0);
    }

    /*
     * Otherwise return the sum of the following:-
     * 1. '1' for the node itself.
     * 2. number of nodes in the left sub-tree
     * 3. number of nodes in the right sub-tree
     */
    return(1 + find_number_of_nodes_binary_tree(root->left)
           + find_number_of_nodes_binary_tree(root->right));
}

int main()
{
    /*
     * Test 1: In case root is NULL, the number of nodes in the
     * tree should be zero.
     */
    struct treenode* root1 = NULL;
    assert(0 == find_number_of_nodes_binary_tree(root1));

    /*
     * Test2: Test a bsic case of root with two child nodes.
     */
    struct treenode* root2 = NULL;
    root2 = makenode(10);
    root2->left = makenode(20);
    root2->right = makenode(30);
    assert(3 == find_number_of_nodes_binary_tree(root2));

    /*
     * Test 3: Test a case when the binary tree is a complete binary
     *         tree.
     */
    struct treenode* root3 = NULL;
    root3 = makenode(10);
    root3->left = makenode(20);
    root3->right = makenode(30);
    root3->left->right = makenode(40);
    root3->right->right = makenode(50);
    assert(5 == find_number_of_nodes_binary_tree(root3));

    /*
     * Test 4: Test a case when the tree is not a complete binary tree.
     */
    struct treenode* root4 = NULL;
    root4 = makenode(10);
    root4->left = makenode(20);
    root4->right = makenode(30);
    root4->left->left = makenode(40);
    root4->left->right = makenode(50);
    root4->right->left = makenode(60);
    root4->right->left->right = makenode(70);
    root4->right->left->left = makenode(80);
    assert(8 == find_number_of_nodes_binary_tree(root4));

    return(0);
}
