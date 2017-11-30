/*
 * This program prints all paths root to leaf paths in a binary tree.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
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

int get_num_leaves (struct treenode* root)
{
    if (!root) {
        return(0);
    }

    if (!root->left && !root->right) {
        return(1);
    }

    return(get_num_leaves(root->left) + get_num_leaves(root->right));
}

char**
get_all_paths_from_root_to_leaves (struct treenode* root)
{
    if (!root) {
        return(NULL);
    }


}

