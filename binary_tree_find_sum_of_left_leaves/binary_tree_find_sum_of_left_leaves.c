/*
 * This program finds the sum of all left leaves in a binary tree.
 * For more information on the problem, please refer to the following
 * link:- http://www.geeksforgeeks.org/find-sum-left-leaves-given-binary-tree/
 */
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

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
 * This function returns 'true' if the left and right subtrees of the
 * nodes are empty and 'false' otherwise.
 */
bool is_leaf (struct treenode* root)
{
    /*
     * If the node itself is NULL, then the return 'false'
     */
    if (!root) {
        return(false);
    }

    /*
     * If the left and right subtrees of the node are NULL, then
     * return 'true'
     */
    if ((root->left == NULL) && (root->right == NULL)) {
        return(true);
    }

    /*
     * In all other cases, the node is not a leaf node, so return
     * 'false'
     */
    return(false);
}

/*
 * This function returns the sum of all the leaf nodes in the binary
 * tree which are the left child of their parent node.
 */
int find_sum_of_left_leaves (struct treenode* root)
{
    int sum = 0;

    /*
     * If the root of the binary tree is NULL, then return zero
     */
    if (!root) {
        return(0);
    }

    /*
     * If the left subtree is not empty and the left subtree is a
     * leaf node, then return the sum of the left child and the find
     * sum of all left leaves in the right subtree.
     */
    if ((root->left != NULL) && is_leaf(root->left)) {
        return(root->left->data +
                  find_sum_of_left_leaves(root->right));
    }

    /*
     * Otherwiae return the sum of left leaves in left and right
     * subtrees.
     */
    return(find_sum_of_left_leaves(root->left)
                + find_sum_of_left_leaves(root->right));
}

int main ()
{
    /*
     * Test 0: Test with root being NULL. The sum of left leaves
     *         should be zero.
     */
    struct treenode* root0 = NULL;
    assert(0 == find_sum_of_left_leaves(root0));

    /*
     * Test 1: Test with root being the only node. The sum of left
     *         leaves should be zero as there are no left leaves.
     */
    struct treenode* root1 = NULL;
    root1 = makenode(10);
    assert(0 == find_sum_of_left_leaves(root1));

    /*
     * Test 2: Test with the root having one left and one right
     *         child. The sum of left leaves should be equal to the
     *         value in the left child.
     */
    struct treenode* root2 = NULL;
    root2 = makenode(10);
    root2->left = makenode(20);
    root2->right = makenode(30);
    assert(20 == find_sum_of_left_leaves(root2));

    /*
     * Test 3: Test with left leaves being present in both left and
     *         right subtrees.
     */
    struct treenode* root3 = NULL;
    root3 = makenode(10);
    root3->left = makenode(20);
    root3->left->left = makenode(30);
    root3->right = makenode(40);
    root3->right->left = makenode(50);
    assert(80 == find_sum_of_left_leaves(root3));

    /*
     * Test 4: Test with a case when there are no left leaves in the
     *         binary tree. The sum of left leaves in this case should
     *         zero.
     */
    struct treenode* root4 = NULL;
    root4 = makenode(10);
    root4->left = makenode(20);
    root4->left->right = makenode(30);
    root4->right = makenode(40);
    root4->right->right = makenode(50);
    assert(0 == find_sum_of_left_leaves(root4));

    return(0);
}
