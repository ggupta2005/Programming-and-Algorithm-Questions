/*
 * This program builds a linked list by pushing elements to the top of the
 * linked list. It then counts the number of elements in the linked list
 * by traversing the linked list iteratively and recursively.
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
 * Structure of the linked list node
 */
struct node {
    int data;
    struct node *next;
};

/*
 * This function allocates and new linked list node and sets the 'data' field
 * in the node to be equal to 'value'.
 */
struct node* makeNode(int value)
{
    struct node* data_node = (struct node *)malloc(sizeof(struct node));

    /*
     * If the node allocated was NULL, then return null.
     */
    if (!data_node)
        return(NULL);

    data_node->data = value;
    data_node->next = NULL;

    return data_node;
}

/*
 * This function adds the 'value' passed to it to the front of the linked
 * list (pointed to by 'head'.
 */
void push (struct node **head, int value)
{
    struct node *new_node = makeNode(value);

    /*
     * If the system in not able to allocate a new node for 'value',
     * then we need not add anything to the linked list.
     */
    if (!new_node) {
        return;
    }

    /*
     * If the heaad of the list is NULL, then set head to point to
     * new node otherwise set node's next to head and point head to
     * point to the node.
     */
    if (!(*head)) {
        *head = new_node;
    } else {
         new_node->next = *head;
         *head = new_node;
    }
}

/*
 * This function counts the number of nodes in a linked list iteratively.
 */
int count_nodes_iterative(struct node* head)
{
    int count = 0;
    struct node *current = head;

    /*
     * Iterate through the list and increment the counter for
     * counting the number of nodes in the list.
     */
    while (current != NULL) {
        ++count;
        current = current->next;
     }

    /*
     * Return 'count'
     */
    return count;
}

/*
 * This function counts the number of nodes in a linked list recursively.
 */
int count_nodes_recursive(struct node* head)
{
    /*
     * If head is NULL, then return 0
     */
    if (!head)
        return(0);

    /*
     * Return the sum of 'this node' and the number of nodes
     * pointed to by 'head->next'
     */
    return(1 + count_nodes_recursive(head->next));
}

int main()
{
    /*
     * Test 1: Head of the list points to NULL
     */
    struct node* head1 = NULL;
    assert(0 == count_nodes_iterative(head1));
    assert(0 == count_nodes_recursive(head1));

    /*
     * Test 2: There is only one node in the list
     */
    struct node* head2 = NULL;
    push(&head2, 1);
    assert(1 == count_nodes_iterative(head2));
    assert(1 == count_nodes_recursive(head2));

    /*
     * Test 3: There are some nodes in the list
     */
    struct node* head3 = NULL;
    push(&head3, 0);
    push(&head3, 1);
    push(&head3, 2);
    push(&head3, 3);
    push(&head3, 4);
    push(&head3, 5);
    push(&head3, 6);
    push(&head3, 7);
    push(&head3, 8);
    push(&head3, 9);
    assert(10 == count_nodes_iterative(head3));
    assert(10 == count_nodes_recursive(head3));

    return 0;
}

