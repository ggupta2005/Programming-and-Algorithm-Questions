/*
 * This program gets the inorder traversal of a binary tree both
 * recursively and iterativaly.
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define MAX_STACK_SIZE 1000

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

int get_binary_tree_size (struct treenode* root)
{
    if (!root) {
        return(0);
    }

    return(1 + get_binary_tree_size(root->left)
           + get_binary_tree_size(root->right));
}

int* get_inorder_traversal_v1 (struct treenode* root, int* len)
{
    int num_nodes, cur_index;
    int* inorder_array;
    struct treenode* stack[MAX_STACK_SIZE];
    struct treenode* p;
    int top = -1;

    if (!len) {
        return(NULL);
    }

    if (!root) {
        *len = 0;
        return(NULL);
    }

    num_nodes = get_binary_tree_size(root);

    inorder_array = (int*)malloc(sizeof(int) * num_nodes);

    if (!inorder_array) {
        *len = 0;
        return(NULL);
    }

    *len = num_nodes;
    cur_index = 0;
    p = root;
    do {
        while (p) {
            stack[++top] = p;
            p = p->left;
        }

        p = stack[top];
        --top;

        inorder_array[cur_index] = p->data;
        ++cur_index;

        if (cur_index >= num_nodes) {
            free(inorder_array);
            *len = 0;
            return(NULL);
        }

        p = p->right;

    } while ((top != -1) || p);

    return(inorder_array);
}

int main ()
{
    struct treenode* root0 = NULL;
    int exp_len0, act_len0;
    int* exp_inorder_array0 = NULL;
    int* act_inorder_array0 = NULL;
    act_inorder_array0 = get_inorder_traversal_v1(root0, &act_len0);
    assert((act_inorder_array0 == exp_inorder_array0) &&
           (act_len0 == exp_len0));

    struct treenode* root1 = NULL;
    int exp_len1, act_len1;
    int exp_inorder_array1[] = {10};
    int* act_inorder_array1 = NULL;
    root1 = makenode(10);
    act_inorder_array1 = get_inorder_traversal_v1(root1, &act_len1);
    assert(
           !memcmp(act_inorder_array1,
                   exp_inorder_array1, sizeof(int) * exp_len1)
           && (act_len1 == exp_len1));

    struct treenode* root2 = NULL;
    int exp_len2, act_len2;
    int exp_inorder_array2[] = {10, 20};
    int* act_inorder_array2 = NULL;
    root2 = makenode(10);
    root2->right = makenode(20);
    act_inorder_array2 = get_inorder_traversal_v1(root2, &act_len2);
    assert(
           !memcmp(act_inorder_array2,
                   exp_inorder_array2, sizeof(int) * exp_len2)
           && (act_len2 == exp_len2));

    return(0);
}
