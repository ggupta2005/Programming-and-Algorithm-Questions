/*
 * This program finds the inorder successor of a value in the binary search
 * tree. If the value doesn't exist in the binary search tree or if the value
 * is the maximum value in the binary search tree, then the successor returned
 * is NULL. For more information on this problem, please visit the following
 * link:- http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
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
 * This function returns the pointer reference the node which carries
 * the minimum value in the binary search tree. THe minimum value in the
 * binary search tree is the left most node in the tree.
 */
struct treenode* get_minimum_val_binary_search_tree (struct treenode* root)
{
    struct treenode* current;

    /*
     * If root node is NULL, then return NULL from the function.
     */
    if (!root) {
        return(NULL);
    }

    /*
     * Set 'current' to the root of the tree. Iterate unless the left
     * child of 'current' is found to be NULL.
     */
    current = root;
    while (current->left) {
        current = current->left;
    }

    /*
     * Return the reference to the node carrying minimum value.
     */
    return(current);
}

/*
 * This function returns the address reference to the binary search tree
 * node which contains the number equal to 'value'. If no such value exists
 * in the binary search tree, then this function returns NULL.
 */
struct treenode* find_node_for_value_binary_search_tree (
                                                   struct treenode* root,
                                                   int value)
{
    struct treenode* current;

    /*
     * If the root node of the binary search tree in NULL,
     * then return NULL from this function.
     */
    if (!root) {
        return(NULL);
    }

    /*
     * Set 'current' to the rroot node
     */
    current = root;

    /*
     * Iterate in the binary search tree, until 'current' is
     * NULL
     */
    while (current) {

        if (current->data == value) {

            /*
             * If the 'value' is found in the current node, then
             * dis-continue the loop
             */
            break;
        } else if (value < current->data) {

            /*
             * If the 'value' is less than the data in the
             * current node, then move to the left sub-tree
             */
            current = current->left;
        } else {

            /*
             * If the 'value' is more than the data in the
             * current node, then move to the right sub-tree
             */
            current = current->right;
        }
    }

    /*
     * Return the address reference of the node containing
     * 'value'
     */
    return(current);
}

/*
 * This function returns the address reference of the binary search tree
 * node which is the successor to the node containing the data which is
 * equal to the 'value'. If the 'value' does not exist in the binary
 * search tree or the successor is not valid, then this function returns
 * NULL.
 */
struct treenode* get_successor_binary_search_tree (struct treenode* root,
                                                   int value)
{
    struct treenode* value_node = NULL;
    struct treenode* successor_node = NULL;

    /*
     * If the root of the binary search tree is NULL, then return
     * NULL from this function.
     */
    if (!root) {
        return(NULL);
    }

    /*
     * Find the address reference to the binary search tree node
     * containing 'value'.
     */
    value_node = find_node_for_value_binary_search_tree(root, value);

    /*
     * If the reference to the binary search tree node containing
     * 'value' is NULL, then return NULL from this function.
     */
    if (!value_node) {
        return(NULL);
    }

    /*
     * If the right child of the binary search tree node containing
     * 'value' is not NULL, then find the minimum value of in the
     * right sub-tree as this minimum value is the successor of
     * 'value'
     */
    if (value_node->right) {
        successor_node =
            get_minimum_val_binary_search_tree(value_node->right);
    } else {

        /*
         * Otherwise, if the right subtree of the binary search
         * tree node containing 'value' is NULL, then find the
         * successor from the top of the tree.
         */
        successor_node = NULL;
        while (root) {

            if (value < root->data) {

                /*
                 * If 'value' is less than the current node, then
                 * record the successor and move to the left subtree
                 */
                successor_node = root;
                root = root->left;
            } else if (value > root->data) {

                /*
                 * If 'value' is more than the current node, move to
                 * the right subtree
                 */
                root = root->right;
            } else {

                /*
                 * If 'value' is equal to the current node, then break
                 * from this loop
                 */
                break;
            }
        }
    }

    /*
     * Return the reference to the successor node
     */
    return(successor_node);
}

int main ()
{
    /*
     * Test 0: The root node is NULL. The successor treenode returned by
     *         the function should be NULL.
     */
    struct treenode* root0 = NULL;
    assert(NULL == get_successor_binary_search_tree(root0, 10));

    /*
     * Test 1: The binary search tree has only one node. The successor
     *         of the root node should be NULL.
     */
    struct treenode* root1 = NULL;
    insert_into_binary_search_tree(&root1, 10);
    assert(NULL == get_successor_binary_search_tree(root1, 10));

    /*
     * Test 2: The binary search tree has more than one node. The
     *         successor of the following cases should be following:-
     *         1. The successor of the maximum value in the BST should
     *            be NULL.
     *         2. The successor of the minimum value in the BST should
     *            not be NULL.
     *         3. The successor of a value having a valid right child
     *            shouldn't be NULL
     *         4. The successor of a non-maximum value not having a
     *            valid right child shouldn't be NULL.
     */
    struct treenode* root2 = NULL;
    struct treenode* successor_node2 = NULL;
    insert_into_binary_search_tree(&root2, 100);
    insert_into_binary_search_tree(&root2, 50);
    insert_into_binary_search_tree(&root2, 40);
    insert_into_binary_search_tree(&root2, 70);
    insert_into_binary_search_tree(&root2, 80);
    insert_into_binary_search_tree(&root2, 20);
    insert_into_binary_search_tree(&root2, 10);
    insert_into_binary_search_tree(&root2, 150);
    insert_into_binary_search_tree(&root2, 130);
    insert_into_binary_search_tree(&root2, 170);
    insert_into_binary_search_tree(&root2, 180);
    insert_into_binary_search_tree(&root2, 110);
    insert_into_binary_search_tree(&root2, 140);
    successor_node2 = get_successor_binary_search_tree(root2, 180);
    assert(NULL == successor_node2);
    successor_node2 = get_successor_binary_search_tree(root2, 10);
    assert((NULL != successor_node2) && (20 == successor_node2->data));
    successor_node2 = get_successor_binary_search_tree(root2, 100);
    assert((NULL != successor_node2) && (110 == successor_node2->data));
    successor_node2 = get_successor_binary_search_tree(root2, 40);
    assert((NULL != successor_node2) && (50 == successor_node2->data));

    /*
     * Test 3: The binary search tree has more than one node. The
     *         successor of a value which does not exist in the binary
     *         search tree should be NULL.
     */
    struct treenode* root3 = NULL;
    insert_into_binary_search_tree(&root3, 100);
    insert_into_binary_search_tree(&root3, 50);
    insert_into_binary_search_tree(&root3, 40);
    insert_into_binary_search_tree(&root3, 70);
    assert(NULL == get_successor_binary_search_tree(root3, 10));
    return(0);
}
