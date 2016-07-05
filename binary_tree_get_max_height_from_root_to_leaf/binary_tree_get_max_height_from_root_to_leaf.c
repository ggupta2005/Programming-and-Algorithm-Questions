/*
 * This program finds the maximum length of path from the root node to
 * a leaf node in a binary tree (Also known as the height of the binary tree).
 * Look at this post for more details on the height of a binary tree:-
 * http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
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
 * This function returns the maximum length of a path from root node to a
 * leaf node in a binary tree. This maximum length is defined as the number
 * of nodes in a path from root to leaf node in terms of number of nodes.
 * The time complexity of this function is O(n) where 'n' is the number of
 * nodes in the binary tree.
 */
int get_max_length_root_to_leaf_binary_tree (struct treenode* root)
{
    int max_left_depth;
    int max_right_depth;

    /*
     * If the root element is NULL, then there is no depth of binary
     * tree. Return zero.
     */
    if (!root) {
        return(0);
    }

    /*
     * Recursively find the depth of left sub-tree
     */
    max_left_depth = get_max_length_root_to_leaf_binary_tree(root->left);

    /*
     * Recursively find the depth of right sub-tree
     */
    max_right_depth = get_max_length_root_to_leaf_binary_tree(root->right);

    /*
     * If the depth of left sub-tree is higher than right sub-tree, then
     * return '1 + max_left_depth'.
     */
    if (max_left_depth > max_right_depth) {
        return(1 + max_left_depth);
    }

    /*
     * Return '1 + max_right_depth'
     */
    return(1 + max_right_depth);
}

int main()
{
    /*
     * Test 1: In case root is NULL, the maximum height should be zero
     */
    struct treenode* root1 = NULL;
    assert(0 == get_max_length_root_to_leaf_binary_tree(root1));

    /*
     * Test2: Test a bsic case of root with two child nodes.
     */
    struct treenode* root2 = NULL;
    root2 = makenode(10);
    root2->left = makenode(20);
    root2->right = makenode(30);
    assert(2 == get_max_length_root_to_leaf_binary_tree(root2));

    /*
     * Test 3: Test a case when the binary tree is a complete binary
     *         tree.
     */
    struct treenode* root3 = NULL;
    root3 = makenode(10);
    root3->left = makenode(20);
    root3->right = makenode(30);
    root3->left->right = makenode(40);
    root3->left->left = makenode(40);
    root3->right->right = makenode(50);
    root3->right->left = makenode(50);
    assert(3 == get_max_length_root_to_leaf_binary_tree(root3));

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
    assert(4 == get_max_length_root_to_leaf_binary_tree(root4));

    /*
     * Test 5: Test a case when the binary tree is a linked list
     */
    struct treenode* root5 = NULL;
    root5 = makenode(10);
    root5->left = makenode(20);
    root5->left->left = makenode(40);
    root5->left->left->left = makenode(80);
    root5->left->left->left->left = makenode(160);
    root5->left->left->left->left->left = makenode(160);
    assert(6 == get_max_length_root_to_leaf_binary_tree(root5));

    return(0);
}
