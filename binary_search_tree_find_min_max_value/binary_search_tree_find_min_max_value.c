/*
 * This program finds the minimum and maximum value in a binary
 * search tree. This binary search tree can have only distinct values.
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_ARRAY_SIZE 100
#define MAX_RANDOM_NUMBER_SEED 100

/*
 * Generate array of random numbers. The array should have only
 * distinct numbers in the array after a call to this function.
 * This function is used for testing purposes.
 */
void generate_and_store_random_numbers (int* array, int len)
{
    int i, j, random_number;
    bool should_continue, found;

    /*
     * If the array pointer is not valid or its length is not valid,
     * then return from this function.
     */
    if (!array || (len <= 0)) {
        return;
    }

    /*
     * Init the random number generator with a seed value.
     */
    srand(MAX_RANDOM_NUMBER_SEED);

    /*
     * Continue generation of random numbers unless the array is populated
     * with distinct integers
     */
    i = 0;
    while (i < len) {

        while (true) {

            /*
             * Generate a new random number
             */
            random_number = rand();

            /*
             * Find if this random number has already been generated
             * previously
             */
            j = 0;
            found = false;
            while (j < i) {
                if (random_number == array[j]) {
                    found = true;
                    break;
                }

                ++j;
            }

            /*
             * If this random number was not generated previously,
             * then add this random number into the ith position in the
             * array
             */
            if (!found) {
                array[i] = random_number;
                break;
            }
        }

        ++i;
    }
}

/*
 * This function returns the reference of the minimum number in an
 * array. If the array pointer is NULL or the length of the array is
 * not valid, then this function returns NULL. This function is used
 * for testing purposes.
 */
int* get_min_value_reference_from_array (int* array, int len)
{
    int i;
    int* min_ptr = NULL;

    /*
     * If the array pointer or its length are not valid, then return
     * NULL.
     */
    if (!array ||(len <= 0))
        return(NULL);

    /*
     * Set the minimum element pointer to the zeroth element and iterate
     * through the array to find the minimum element
     */
    min_ptr = &array[0];
    for (i = 1; i < len; ++i) {
        if (*min_ptr > array[i]) {
            min_ptr = &array[i];
        }
    }

    /*
     * Return the reference of the minimum element in the array
     */
    return(min_ptr);
}

/*
 * This function returns the reference of the maximum number in an
 * array. If the array pointer is NULL or the length of the array is
 * not valid, then this function returns NULL. This function is used
 * for testing purposes.
 */
int* get_max_value_reference_from_array (int* array, int len)
{
    int i;
    int* max_ptr = NULL;

    /*
     * If the array pointer or its length are not valid, then return
     * NULL.
     */
    if (!array ||(len <= 0))
        return(NULL);

    /*
     * Set the maximum element pointer to the zeroth element and iterate
     * through the array to find the maximum element
     */
    max_ptr = &array[0];
    for (i = 1; i < len; ++i) {
        if (*max_ptr < array[i]) {
            max_ptr = &array[i];
        }
    }

    /*
     * Return the reference of the maximum element in the array
     */
    return(max_ptr);
}

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
 * This function returns the pointer reference the node which carries
 * the maximum value in the binary search tree. THe maximum value in the
 * binary search tree is the right most node in the tree.
 */
struct treenode* get_maximum_val_binary_search_tree (struct treenode* root)
{
    struct treenode* current;

    /*
     * If root node is NULL, then return NULL from the function.
     */
    if (!root) {
        return(NULL);
    }

    /*
     * Set 'current' to the root of the tree. Iterate unless the right
     * child of 'current' is found to be NULL.
     */
    current = root;
    while (current->right) {
        current = current->right;
    }

    /*
     * Return the reference to the node carrying maximum value.
     */
    return(current);
}

int main()
{
    /*
     * Test 0: The root node is NULL. The treenode returned by the minimum
     *         or maximum functions should be NULL.
     */
    struct treenode* root0 = NULL;
    assert(NULL == get_minimum_val_binary_search_tree(root0));
    assert(NULL == get_maximum_val_binary_search_tree(root0));

    /*
     * Test 1: The binary search tree has only one node. The get minimum
     *         or maximum functions should return this node itself
     */
    struct treenode* root1 = NULL;
    insert_into_binary_search_tree(&root1, 10);
    assert(10 == (get_minimum_val_binary_search_tree(root1))->data);
    assert(10 == (get_maximum_val_binary_search_tree(root1))->data);

    /*
     * Test 2: The binary search tree has many nodes inserted one after
     *         another. The get minimum function should return the smallest
     *         value. The get maximum function should return the largest
     *         value.
     */
    struct treenode* root2 = NULL;
    int test_array2[100];
    int len2 = sizeof(test_array2)/sizeof(int);
    int index2;
    int* min_ptr2;
    int* max_ptr2;

    /*
     * Generate an array of random numbers
     */
    generate_and_store_random_numbers(test_array2, len2);

    /*
     * Add the random numbers into a binary search tree
     */
    for (index2 = 0; index2 < len2; ++index2) {
        insert_into_binary_search_tree(&root2, test_array2[index2]);
    }

    /*
     * Get the minimum value from the array containing random numbers
     */
    min_ptr2 = get_min_value_reference_from_array(test_array2, len2);

    /*
     * Check if the minimum value exists is same as the minimum value
     * gotten from the binary search tree
     */
    assert(*min_ptr2
           == (get_minimum_val_binary_search_tree(root2))->data);

    /*
     * Get the maximum value from the array containing random numbers
     */
    max_ptr2 = get_max_value_reference_from_array(test_array2, len2);

    /*
     * Check if the maximum value exists is same as the maximum value
     * gotten from the binary search tree
     */
    assert(*max_ptr2
           == (get_maximum_val_binary_search_tree(root2))->data);

    return(0);
}
