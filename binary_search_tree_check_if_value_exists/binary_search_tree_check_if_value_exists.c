/*
 * This program check if a value exists in a binary search tree.
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<limits.h>

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
struct treenode* make_treenode (int val)
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
 * This function inserts an integer value in the binary search tree.
 * As per the definitions of a binary search tree the values in the
 * left subtree are strictly less than the values in the right sub-tree.
 */
void insert_into_binary_search_tree (struct treenode** root, int val)
{
    struct treenode* new_node = NULL;
    struct treenode* current;
    struct treenode* parent;

    /*
     * If the address reference of the pointer to the root of the
     * binary search tree is NULL, then return.
     */
    if (!root) {
        return;
    }

    /*
     * Allocate a new node for 'val'
     */
    new_node = make_treenode(val);

    /*
     * If the allocation of memory is unsuccessful, then return from
     * this function.
     */
    if (!new_node) {
        return;
    }

    /*
     * If the root pointer is NULL, then set the root pointer of the
     * binary search tree to point to the new_node and return.
     */
    if (!(*root)) {
        *root = new_node;
        return;
    }

    /*
     * Iterate hrough the binary search tree unless, we find the
     * appropriate parent node to insert the new node.
     */
    current = *root;
    parent = NULL;
    while (current) {
        parent = current;

        /*
         * The the value of the current node is greater than the
         * 'val', then move to the left sub-tree otherwise move to
         * right sub-tree.
         */
        if (current->data > val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    /*
     * If there is a valid parent node, then insert the new_node
     * in the binary search tree.
     */
    if (parent) {

        /*
         * If the 'val' is less than the parent's data, then insert
         * the new_node as the left child otherwise insert the child
         * as the right child.
         */
        if (parent->data > val) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    } else {
        /*
         * If parent node is NULL, then free the allocated node
         */
        free(new_node);
    }
}

/*
 * This function returns the reference of a node which contains the
 * data as 'val' in a binary search tree. If the 'val' does not
 * exists in the binary search tree, then this function returns
 * NULL. The time complxity of this function is O(log(n)) is best
 * average case and O(n) in worst case, where 'n' is the number of
 * nodes in the binary search tree.
 */
struct treenode* search_value_in_binary_search_tree (
                                      struct treenode* root, int val)
{
    struct treenode* current;

    /*
     * If the root is NULL, then return NULL
     */
    if (!root) {
        return(NULL);
    }

    /*
     * Attempt to find 'val' in the tree while iterating
     * from root to leaf node in the binary search tree
     */
    current = root;
    while (current && (current->data != val)) {

        if (current->data > val) {

            /*
             * If the data value in the current node is
             * greater than 'val', then move to the left
             * subtree.
             */
            current = current->left;
        } else {
            /*
             * If the data value in the current node is
             * lesser than 'val', then move to the right
             * subtree.
             */
            current = current->right;
        }
    }

    /*
     * Return the reference of the node containing the
     * 'val'
     */
    return(current);
}

int main ()
{
    /*
     * Test 0: Test to search for a value in an empty BST. The
     *         reference returned for the value should be NULL.
     */
    struct treenode* root0 = NULL;
    struct treenode* value0 = NULL;
    value0 = search_value_in_binary_search_tree(root0, 10);
    assert(NULL == value0);

    /*
     * Test 1: Test to search for a value in a BST having one node.
     *         Following should be the test results for different
     *         cases:-
     *         1. If the value doesn't exist in the BST, then the
     *            reference returned for the value should be NULL.
     *         2. If the value exists in the BST, then the
     *            reference returned for the value should not be
     *            NULL.
     */
    struct treenode* root1 = NULL;
    struct treenode* value1 = NULL;
    insert_into_binary_search_tree(&root1, 10);
    value1 = search_value_in_binary_search_tree(root1, root1->data);
    assert((NULL != value1) && (value1->data == root1->data));;
    value1 = search_value_in_binary_search_tree(root1, root1->data - 1);
    assert(NULL == value1);
    value1 = search_value_in_binary_search_tree(root1, root1->data + 1);
    assert(NULL == value1);

    /*
     * Test 2: Test to search for a value in a BST having many nodes.
     *         Following should be the test results for different
     *         cases:-
     *         1. If the value doesn't exist in the BST, then the
     *            reference returned for the value should be NULL.
     *         2. If the value exists in the BST, then the
     *            reference returned for the value should not be
     *            NULL.
     */
    struct treenode* root2 = NULL;
    struct treenode* value2 = NULL;
    insert_into_binary_search_tree(&root2, 100);
    insert_into_binary_search_tree(&root2, 70);
    insert_into_binary_search_tree(&root2, 40);
    insert_into_binary_search_tree(&root2, 90);
    insert_into_binary_search_tree(&root2, 50);
    insert_into_binary_search_tree(&root2, 60);
    insert_into_binary_search_tree(&root2, 170);
    insert_into_binary_search_tree(&root2, 140);
    insert_into_binary_search_tree(&root2, 190);
    insert_into_binary_search_tree(&root2, 150);
    insert_into_binary_search_tree(&root2, 160);
    value2 = search_value_in_binary_search_tree(root2, 100);
    assert((NULL != value2) && (100 == value2->data));
    value2 = search_value_in_binary_search_tree(root2, 160);
    assert((NULL != value2) && (160 == value2->data));
    value2 = search_value_in_binary_search_tree(root2, 40);
    assert((NULL != value2) && (40 == value2->data));
    value2 = search_value_in_binary_search_tree(root2, 45);
    assert(NULL == value2);
    value2 = search_value_in_binary_search_tree(root2, 85);
    assert(NULL == value2);

    return(0);
}
