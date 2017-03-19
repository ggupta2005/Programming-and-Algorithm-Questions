/*
 * This program finds the binary search tree node which has the
 * the closest data value to a given input value.
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
 * This unction inserts an integer value in the binary search tree.
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
 * This functon finds the the binary search tree node whose data value
 * is the closest to a given value. If the root node of the binary search
 * tree is NULL, then this function returns NULL. the time complexity of
 * this function is O(log(n)) in best and average case, where 'n' is the
 * number of nodes in the binary search tree. The worst case time
 * complexity of this function is O(n).
 */
struct treenode* get_closest_node_to_a_given_value (struct treenode* root,
                                                    int value)
{
    struct treenode* current;
    struct treenode* closest;
    int min;

    /*
     * If root node is NULL, then return NULL from the function
     */
    if (!root) {
        return(NULL);
    }

    min = INT_MAX; /* Set minimum value difference to maximum integer
                      value */
    current = root; /* Set the current pointer to root of the tree */
    closest = NULL;  /* Set the closest value node to NULL */
    while (current) {

        /*
         * If the difference between the current node value and the
         * 'value' is less than the minimum difference, then update
         * the minimum value difference and the closest node pointer
         */
        if (min > abs(current->data - value)) {
            closest = current;
            min = abs(current->data - value);
        }

        /*
         * If 'value' is lesser than the current node data value,
         * then move to the left subtree otherwise move to the
         * right subtree.
         */
        if (current->data > value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    /*
     * Return the cpointer closest node pointer
     */
    return(closest);
}

int main ()
{
    /*
     * Test 0: Test with an empty binary search tree. The node
     *         having closest value to a given value should be
     *         NULL.
     */
    struct treenode* root0 = NULL;
    struct treenode* closest0 = NULL;
    closest0 = get_closest_node_to_a_given_value(root0, 10);
    assert(NULL == closest0);

    /*
     * Test 1: Test with a binary search tree having only one node.
     *         The node having closest value to a given value should be
     *         non-NULL and its value should be the value in the root
     *         node.
     */
    struct treenode* root1 = NULL;
    struct treenode* closest1 = NULL;
    insert_into_binary_search_tree(&root1, 10);
    closest1 = get_closest_node_to_a_given_value(root1, root1->data);
    assert((NULL != closest1) && (closest1->data == root1->data));;
    closest1 = get_closest_node_to_a_given_value(root1, root1->data - 1);
    assert((NULL != closest1) && (closest1->data == (root1->data)));;
    closest1 = get_closest_node_to_a_given_value(root1, root1->data + 1);
    assert((NULL != closest1) && (closest1->data == (root1->data)));;

    /*
     * Test 2: Test with a binary search tree having only many nodes.
     *         The node having closest value to a given value should be
     *         non-NULL and its value should be the closest to the input
     *         value.
     */
    struct treenode* root2 = NULL;
    struct treenode* closest2 = NULL;
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
    closest2 = get_closest_node_to_a_given_value(root2, 101);
    assert((NULL != closest2) && (100 == closest2->data));
    closest2 = get_closest_node_to_a_given_value(root2, 145);
    assert((NULL != closest2) && (140 == closest2->data));
    closest2 = get_closest_node_to_a_given_value(root2, 163);
    assert((NULL != closest2) && (160 == closest2->data));

    return(0);
}
