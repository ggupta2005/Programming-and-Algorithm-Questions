/*
 * This program reverses the linked list recursively and iteratively.
 *
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

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
    struct node* data_node;

    data_node = (struct node *)malloc(sizeof(struct node));

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

void reverse_linked_list_iterative (struct node** head)
{
    struct node* current;
    struct node* new_head;
    struct node* temp;

    if (!head || !(*head)) {
        return;
    }

    current = *head;
    new_head = NULL;
    while (current) {

        temp = current;

        current = current->next;

        temp->next = NULL;

        if (!new_head) {
            new_head = temp;
        } else {
            temp->next = new_head;
            nwe_head = temp;
        }
    }

    *head = new_head;
}

void reverse_linked_list_recursive (struct node** head, struct node* current)
{
    struct node* current;
    struct node* new_head;
    struct node* temp;

    if (!head || !(*head)) {
        return;
    }

    if (current->next == NULL) {
        *head = current;
        current->next = NULL;
        return;
    }

    current = temp;
    temp = (*head)->next;

    reverse_linked_list_recursive(head, &temp);
    temp->next = current;
}
