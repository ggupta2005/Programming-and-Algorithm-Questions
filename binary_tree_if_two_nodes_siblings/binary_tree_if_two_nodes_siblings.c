/*
 * This program finds if two values belong to the nodes who
 * are siblings of each other. That is the value nodes have
 * a common parent.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

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
 * This function returs true if the node which have values 'val1' and
 * 'val2' are siblings of each other, that is if the nodes having
 * values 'val1' and 'val2' belong to the same parent.
 */
bool if_val_belong_to_siblings (struct treenode* root, int val1,
                                int val2)
{
    /*
     * Base case when root node is NULL. The sibling pair could
     * not be found. Return false.
     */
    if (!root) {
        return(false);
    }

    /*
     * Base case when root node and its child nodes are not NULL.
     * The sibling pair could be found. Test the left and the right
     * child nodes.
     */
    if (root->left && root->right) {
        if (root->left->data == val1 &&
            root->right->data == val2) {
            return(true);
        }

        if (root->left->data == val2 &&
            root->right->data == val1) {
            return(true);
        }
    }

    /*
     * If the sibling pair could not be found in the current root
     * node, then recursively find the values in the left and
     * the right subtrees.
     */
    return(if_val_belong_to_siblings(root->left, val1, val2) ||
           if_val_belong_to_siblings(root->right, val1, val2));
}

int main()
{
    /*
     * Test 1: Find siblings in NULL tree root
     */
    struct treenode* root1 = NULL;
    assert(false == if_val_belong_to_siblings(root1, 10, 20));

    /*
     * Test2: The root itself contains the sibling pair
     */
    struct treenode* root2 = NULL;
    root2 = makenode(10);
    root2->left = makenode(20);
    root2->right = makenode(30);
    assert(true == if_val_belong_to_siblings(root2, 30, 20));
    assert(true == if_val_belong_to_siblings(root2, 20, 30));

    /*
     * Test 3: Even though the values exist in the binary
     *         tree, they are not sibling nodes
     */
    struct treenode* root3 = NULL;
    root3 = makenode(10);
    root3->left = makenode(20);
    root3->right = makenode(30);
    root3->left->right = makenode(40);
    root3->right->right = makenode(50);
    assert(false == if_val_belong_to_siblings(root3, 40, 50));

    /*
     * Test 4: Test a sibling pair in the left sub-tree whose
     *         parent is not the root node.
     */
    struct treenode* root4 = NULL;
    root4 = makenode(10);
    root4->left = makenode(20);
    root4->right = makenode(30);
    root4->left->left = makenode(40);
    root4->left->right = makenode(50);
    root4->right->left = makenode(60);
    root4->right->right = makenode(70);
    assert(true == if_val_belong_to_siblings(root4, 40, 50));
    assert(true == if_val_belong_to_siblings(root4, 50, 40));

    /*
     * Test 5: Test a sibling pair in the right sub-tree whose
     *         parent is not the root node.
     */
    struct treenode* root5 = NULL;
    root5 = makenode(10);
    root5->left = makenode(20);
    root5->right = makenode(30);
    root5->left->left = makenode(40);
    root5->left->right = makenode(50);
    root5->right->left = makenode(60);
    root5->right->left->right = makenode(70);
    root5->right->left->left = makenode(80);
    assert(true == if_val_belong_to_siblings(root5, 70, 80));
    assert(true == if_val_belong_to_siblings(root5, 80, 70));

    return(0);
}
