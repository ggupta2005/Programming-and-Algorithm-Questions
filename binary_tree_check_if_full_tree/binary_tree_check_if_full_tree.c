/*
 * This program checks if a binary tree is a full binary tree. A binary tree
 * is a full binary tree if each node in the tree has either two or zero child
 * nodes.
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
 * This function returns true, if a binary tree node is a leaf
 * node and false if it is not.
 */
static inline bool if_treenode_is_leaf (struct treenode* root)
{
    if (!root) {
        return(false);
    }

    if (!(root->left) && !(root->right)) {
        return(true);
    }

    return(false);
}

/*
 * This function returns true, if a binary tree node is an internal
 * node with two children and false if does not.
 */
static inline bool if_treenode_has_two_children (struct treenode* root)
{
    if (!root) {
        return(false);
    }

    if (root->left && root->right) {
        return(true);
    }

    return(false);
}

/*
 * This function returns true in case a binary tree is a full tree
 * and false otherwise.
 */
bool check_if_binary_tree_is_full (struct treenode* root)
{
    /*
     * If the root node is NULL, then return true as empty
     * tree is a full binary tree.
     */
    if (!root) {
        return(true);
    }

    /*
     * If the root node is not a leaf node and it is also not
     * an internal node with two child nodes, then return false.
     */
    if (!if_treenode_is_leaf(root) &&
        !if_treenode_has_two_children(root)) {
        return(false);
    }

    /*
     * Recursively check the left and right subtrees, if both the
     * subtrees are full binary trees themselves.
     */
    return(check_if_binary_tree_is_full(root->left) &&
           check_if_binary_tree_is_full(root->right));
}

int main()
{
    /*
     * Test 0: In case root is NULL, then the tree is full
     */
    struct treenode* root0 = NULL;
    assert(true == check_if_binary_tree_is_full(root0));

    /*
     * Test 1: In this case the tree has only one node.
     *         Then the tree is full
     */
    struct treenode* root1 = NULL;
    root1 = makenode(10);
    assert(true == check_if_binary_tree_is_full(root1));

    /*
     * Test2: Test a basic case of root with two child nodes. This
     *        tree should be a full binary tree.
     */
    struct treenode* root2 = NULL;
    root2 = makenode(10);
    root2->left = makenode(20);
    root2->right = makenode(30);
    assert(true == check_if_binary_tree_is_full(root2));

    /*
     * Test 3: Test a case when the binary tree is not a full tree.
     *         That is this tree has an internal node with one child
     *         and that is the left child for this node.
     */
    struct treenode* root3 = NULL;
    root3 = makenode(10);
    root3->left = makenode(20);
    root3->right = makenode(20);
    root3->left->left = makenode(40);
    assert(false == check_if_binary_tree_is_full(root3));

    /*
     * Test 4: Test a case when the binary tree is not a full tree.
     *         That is this tree has an internal node with one child
     *         and that is the right child for this node.
     */
    struct treenode* root4 = NULL;
    root4 = makenode(10);
    root4->left = makenode(20);
    root4->right = makenode(20);
    root4->left->right = makenode(40);
    assert(false == check_if_binary_tree_is_full(root4));

    return(0);
}
