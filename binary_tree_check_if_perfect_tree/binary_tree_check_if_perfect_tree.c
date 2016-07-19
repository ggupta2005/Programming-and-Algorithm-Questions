/*
 * This program checks if a binary tree is a perfect binary tree or not.
 * More on perfect binary tree can be found in the link:-
 * http://quiz.geeksforgeeks.org/binary-tree-set-3-types-of-binary-tree/
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
struct treenode* makeNode (int val)
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
 * This function recursively computes the number of nodes in the
 * binary tree. We should pass the root of the binary tree to find
 * number of nodes in that binary tree. The time complexity of this
 * function is O(n), where 'n' is the number of nodes in the binary
 * tree.
 */
unsigned int count_nodes (struct treenode* root)
{
    /*
     * If the root node is NULL, then there are no nodes in the
     * binary tree. So return zero.
     */
    if (!root) {
        return(0);
    }

    /*
     * Recursively find the number of nodes in the left and right
     * subtrees and return the sum of nodes in the left, right subtrees
     * and the node itself.
     */
    return(1 + count_nodes(root->left) + count_nodes(root->right));
}

/*
 * This function finds the maximum height of the binary tree using
 * recursion. The time complexity of this function function is O(n),
 * where 'n' is the number of nodes in the binary
 */
unsigned int height (struct treenode* root)
{
    if (!root) {
        return(0);
    }

    unsigned int l_depth = 1 + height(root->left);
    unsigned int r_depth = 1 + height(root->right);

    if (l_depth > r_depth) {
        return(l_depth);
    }

    return(r_depth);
}

/*
 * This function computes the power of 'base' to 'exponent' efficiently.
 * The time complexity of this function is O(log(exponent)). This is a
 * recursive function.
 */
unsigned int power (unsigned int base, unsigned int exponent)
{
    /*
     * Base case. If exponent is zero, then return one
     */
    if (exponent == 0) {
        return(1);
    }

    /*
     * Base case. If exponent is one, then return base itself
     */
    if (exponent == 1) {
        return(base);
    }

    /*
     * Calculate the number base^(exponent/2) by recursively calling
     * calling this function
     */
    unsigned int product = power(base, exponent/2);

    /*
     * Incase of even value of 'exponent', return the complete
     * product once we have the base^(exponent/2)
     */
    if ((exponent%2) == 0) {
        return(product * product);
    }

    /*
     * Incase of odd value of 'exponent', return the complete
     * product once we have the base^(exponent/2)
     */
    return(base * product * product);
}

/*
 * This function checks if a binary tree is a perfect binary tree.
 * A tree is a perfect binary tree if it has (2^h - 1) nodes, where
 * h is the height of the tree. This function returns 'true' if the
 * binary tree is perfect and false otherwise. The overall time complexity
 * of this function is O(n), where 'n' is the number of nodes in the
 * binary tree.
 */
bool if_binary_tree_full_and_complete (struct treenode* root)
{
    /*
     * An empty tree is always a perfect binary tree, so
     * return 'true'.
     */
    if (!root) {
        return(true);
    }

    /*
     * Compute the height of the binary tree
     */
    unsigned int max_height = height(root);

    /*
     * Compute the number of nodes in the binary tree
     */
    unsigned int node_count = count_nodes(root);

    /*
     * Find the number of nodes in the perfect binary tree having
     * height 'max_height'
     */
    unsigned int expected_node_count = power(2, max_height) - 1;

    /*
     * Check if the number of nodes in the binary is same as the
     * number of nodes that should be in a perfect  binary tree
     * having the same height
     */
    return(expected_node_count == node_count);
}

int main()
{
    /*
     * Test 0: Test the case when the binary tree is empty
     */
    struct treenode* root0 = NULL;
    assert(true == if_binary_tree_full_and_complete(root0));

    /*
     * Test 1: Test the case when the binary tree has one node
     */
    struct treenode* root1 = makeNode(10);
    assert(true == if_binary_tree_full_and_complete(root1));

    /*
     * Test 2: Test the case when the binary tree is a perfect
     *         tree having 15 nodes
     */
    struct treenode* root2 = makeNode(10);
    root2->left = makeNode(20);
    root2->right = makeNode(30);

    root2->left->right = makeNode(40);
    root2->left->left = makeNode(50);
    root2->right->left = makeNode(60);
    root2->right->right = makeNode(70);

    root2->left->left->left = makeNode(80);
    root2->left->left->right = makeNode(90);
    root2->left->right->left = makeNode(80);
    root2->left->right->right = makeNode(90);
    root2->right->left->left = makeNode(80);
    root2->right->left->right = makeNode(90);
    root2->right->right->left = makeNode(80);
    root2->right->right->right = makeNode(90);
    assert(true == if_binary_tree_full_and_complete(root2));

    /*
     * Test 3:  Test a case when a tree is not a complete binary tree
     */
    struct treenode* root3 = makeNode(10);
    root3->left = makeNode(20);
    root3->right = makeNode(30);

    root3->left->right = makeNode(40);
    root3->left->left = makeNode(50);
    root3->right->left = makeNode(60);
    root3->right->right = makeNode(70);

    root3->left->left->left = makeNode(80);
    assert(false == if_binary_tree_full_and_complete(root3));

    return(0);
}
