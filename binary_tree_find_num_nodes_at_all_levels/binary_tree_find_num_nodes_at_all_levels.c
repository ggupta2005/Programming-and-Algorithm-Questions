/*
 * This program finds the number of nodes at all levels in a binary tree.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

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

int get_depth (struct treenode* root)
{
    int l_depth, r_depth;

    if (!root) {
        return(0);
    }

    l_depth = 1 + get_depth(root->left);
    r_depth = 1 + get_depth(root->right);

    return(l_depth > r_depth ? l_depth:r_depth);
}

void populate_num_nodes_at_levels (struct treenode* root, int* levels,
                                   int index, int max_levels)
{
    if (root && levels && (index >= 0) && (max_levels >= 1) &&
        (index < max_levels)) {

        levels[index]++;

        populate_num_nodes_at_levels(root->left, levels, index + 1,
                                     max_levels);
        populate_num_nodes_at_levels(root->right, levels, index + 1,
                                     max_levels);
    }
}

int* get_number_of_nodes_at_levels (struct treenode* root, int* len)
{
    int* num_nodes_in_level;
    int index, depth;

    if (!len) {
        return(NULL);
    }

    if (!root) {
        *len = 0;
        return(NULL);
    }

    depth = get_depth(root);

    if (depth == 0) {
        *len = 0;
        return(NULL);
    }

    num_nodes_in_level = (int*)malloc(sizeof(int) * depth);

    if (!num_nodes_in_level) {
        *len = 0;
        return(NULL);
    }

    memset(num_nodes_in_level, 0, sizeof(int) * depth);

    populate_num_nodes_at_levels(root, num_nodes_in_level, 0, depth);

    *len = depth;
    return(num_nodes_in_level);
}

int main ()
{


    return(0);
}
