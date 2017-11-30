/*
 * This program performs deletions of a node having a value from the binary
 * search tree.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

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
     * Set 'current' to the root node
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

void delete_binary_search_tree_node_having_value (struct treenode** root,
                                                  int value)
{
    struct treenode* value_node;
    struct treenode* parent_node;
    struct treenode* successor_node;
    struct treenode* parent_successor_node;

    if (!root || !(*root)) {
        return;
    }

    parent_node = NULL;
    value_node = *root;
    while (value_node && (value_node->data != value)) {
        parent_node = value_node;

        if (value < value_node->data) {
            value_node = value_node->left;
        } else {
            value_node = value_node->right;
        }
    }

    if (!value_node) {
        return;
    }

    if (!(value_node->left) && !(value_node->right)) {

        /*
         * Case 1: The node containing the value is a leaf. In this
         *         case, simply point the parent node left or right child
         *         to NULL.
         */
        if (!parent_node) {
            *root = NULL;
        } else {
            if (parent_node->left == value_node) {
                parent_node->left = NULL;
            } else {
                parent_node->right = NULL;
            }
        }

        free(value_node);

    } else if (!(value_node->left) || !(value_node->right)) {

        /*
         * Case 2: The node containing the value has only one child
         *         node. In this case we simply point join the parent
         *         node to the child node of the value node.
         */
        if (!parent_node) {
            if (value_node->left) {
                *root = value_node->left;
            } else {
                *root = value_node->right;
            }
        } else {

            if (value_node->left) {
                if (parent_node->left == value_node) {
                    parent_node->left = value_node->left;
                } else {
                    parent_node->right = value_node->left;
                }
            } else {
                if (parent_node->left == value_node) {
                    parent_node->left = value_node->right;
                } else {
                    parent_node->right = value_node->right;
                }
            }
        }
    } else {
        /*
         * Case 3: The node containing the value has both left and right
         *         child node. In this case we modify the value node to
         *         contain the value of the value node's successor and
         *         delete the successor
         */
        parent_successor_node = NULL;
        successor_node = value->right;
        while (successor_node->left) {
            parent_successor_node = successor_node;
            successor_node = successor_node->left;
        }

        value->data = successor_node->data;
    }
}
