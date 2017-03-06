/*
 * This program checks if a binary tree has a path from root to leaf
 * which has a given sum. More information on this problem can be found
 * on the following link:-
 * http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
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
 * This function returns 'true' if there is some root to leaf path in binary
 * tree which has sum of all nodes from root to leaf nodes as 'sum'. If there
 * is no such path exists, then this function returns 'false'. The time
 * complexity of this function is O(n), where 'n' is the number of nodes
 * in the binary tree. The space complexity of this function is O(n).
 */
bool check_if_some_root_leaf_path_has_given_sum (struct treenode* root,
                                                 int sum)
{
    /*
     * If the root node is NULL, then return 'false'
     */
    if (!root) {
        return(false);
    }

    /*
     * If the node is a leaf node and the value in the node is same
     * as the 'sum', then return 'true' otherwise return 'false'
     */
    if (!(root->left) && !(root->right)) {
        return(sum == root->data);
    }

    /*
     * Recursively check the left and right sub-trees to check if the
     * sub-tress have a path to the leaf nodes which have path sum as
     * 'sum - root->data'.
     */
    return(check_if_some_root_leaf_path_has_given_sum(
                                        root->left, sum - root->data) ||
           check_if_some_root_leaf_path_has_given_sum(
                                        root->right, sum - root->data));
}

int main()
{
    /*
     * Test 0: In case root is NULL, then the tree does not have a
     *         path from root to leaf which has a path sum
     */
    struct treenode* root0 = NULL;
    int sum0 = 0;
    assert(false == check_if_some_root_leaf_path_has_given_sum(root0, sum0));

    /*
     * Test 1: In case root is NULL, and sum is non-zero then the tree does
     *         not have a path from root to leaf which has a path sum
     */
    struct treenode* root1 = NULL;
    int sum1 = 10;
    assert(false == check_if_some_root_leaf_path_has_given_sum(root1, sum1));

    /*
     * Test 2: In case root is not NULL, and sum is same as the value in
     *         root node, then the tree has a path from root to leaf which
     *         has a path sum
     */
    struct treenode* root2 = NULL;
    root2 = makenode(10);
    int sum2 = 10;
    assert(true == check_if_some_root_leaf_path_has_given_sum(root2, sum2));

    /*
     * Test 3: In case root is not NULL, and sum is not same as the value in
     *         root node, then the tree does not have a path from root to leaf
     *         which has a path sum
     */
    struct treenode* root3 = NULL;
    root3 = makenode(10);
    int sum3 = 30;
    assert(false == check_if_some_root_leaf_path_has_given_sum(root3, sum3));

    /*
     * Test 4: In case root is a big tree, and there is a path from root to
     *         leaf which has a path sum
     */
    struct treenode* root4 = NULL;
    root4 = makenode(10);
    root4->right = makenode(30);
    root4->left = makenode(40);
    root4->right->left = makenode(60);
    root4->right->right = makenode(-100);
    root4->left->right = makenode(70);
    root4->right->right->right = makenode(80);
    root4->right->right->left = makenode(90);
    int sum4 = 20;
    assert(true == check_if_some_root_leaf_path_has_given_sum(root4, sum4));

    /*
     * Test 5: In case root is a big tree, and there is no  path from root to
     *         leaf which has a path sum
     */
    struct treenode* root5 = NULL;
    root5 = makenode(10);
    root5->right = makenode(30);
    root5->left = makenode(40);
    root5->right->left = makenode(60);
    root5->right->right = makenode(-100);
    root5->left->right = makenode(70);
    root5->right->right->right = makenode(80);
    root5->right->right->left = makenode(90);
    int sum5 = -120;
    assert(false == check_if_some_root_leaf_path_has_given_sum(root5, sum5));

    return(0);
}
