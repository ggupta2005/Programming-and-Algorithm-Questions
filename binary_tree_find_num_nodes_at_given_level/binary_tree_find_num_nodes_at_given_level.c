/*
 * This program finds the number of nodes at a given level in a
 * binary tree. If there are not as many levels in the binary tree
 * then the function returns zero.
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
 * This function returns the number of nodes at a given level in the
 * binary tree. If there are not as many levels in the binary tree or
 * the level is not valid, then this function returns zero. The time
 * complexity of this function is O(n), where 'n' is the number of
 * nodes in the binary tree. The space complexity of this function is
 * O(n).
 */
int get_number_of_node_at_level_k (struct treenode* root, int level)
{
    /*
     * If the root of the binary tree is not valid or the number
     * of the level is not valid, then return zero.
     */
    if (!root || (level <= 0)) {
        return(0);
    }

    /*
     * If the value of the level is one, then retrun one
     */
    if (level == 1) {
        return(1);
    }

    /*
     * Recursively, find the number of nodes at the given level
     * in the right and the left subtrees.
     */
    return(get_number_of_node_at_level_k(root->left, level - 1) +
           get_number_of_node_at_level_k(root->right, level - 1));
}

int main()
{
    /*
     * Test 1: In case root is NULL, the number of nodes at any level
     *         in the tree should be zero.
     */
    struct treenode* root1 = NULL;
    assert(0 == get_number_of_node_at_level_k(root1, -1));
    assert(0 == get_number_of_node_at_level_k(root1, 0));
    assert(0 == get_number_of_node_at_level_k(root1, 1));

    /*
     * Test 2: Test a basic case of root with two child nodes. Test the
     *         number of nodes at all valid and invalid levels in the
     *         binary tree.
     */
    struct treenode* root2 = NULL;
    root2 = makenode(10);
    root2->left = makenode(20);
    root2->right = makenode(30);
    assert(0 == get_number_of_node_at_level_k(root2, 0));
    assert(1 == get_number_of_node_at_level_k(root2, 1));
    assert(2 == get_number_of_node_at_level_k(root2, 2));
    assert(0 == get_number_of_node_at_level_k(root2, 3));

    /*
     * Test 3: Test a basic case of binary tree having three levels. Test
     *         the number of nodes at all valid and invalid levels in the
     *         binary tree.
     */
    struct treenode* root3 = NULL;
    root3 = makenode(10);
    root3->left = makenode(20);
    root3->right = makenode(30);
    root3->left->right = makenode(40);
    root3->right->right = makenode(50);
    assert(0 == get_number_of_node_at_level_k(root3, 0));
    assert(1 == get_number_of_node_at_level_k(root3, 1));
    assert(2 == get_number_of_node_at_level_k(root3, 2));
    assert(2 == get_number_of_node_at_level_k(root3, 3));
    assert(0 == get_number_of_node_at_level_k(root3, 4));

    /*
     * Test 4: Test a basic case of binary tree having many levels. Test
     *         the number of nodes at all valid and invalid levels in the
     *         binary tree.
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
    assert(0 == get_number_of_node_at_level_k(root4, 0));
    assert(1 == get_number_of_node_at_level_k(root4, 1));
    assert(2 == get_number_of_node_at_level_k(root4, 2));
    assert(3 == get_number_of_node_at_level_k(root4, 3));
    assert(2 == get_number_of_node_at_level_k(root4, 4));
    assert(0 == get_number_of_node_at_level_k(root4, 5));

    return(0);
}
