/*
 * This function finds the number of times a given number occurs in a
 * linked list of numbers. For more information about this problem, please
 * refer to the following link:-
 * http://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/
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

/*
 * This function returns the number of occurrences of a given number in
 * a linked list. If the number doesn't exist within the linked list, then
 * this function returns zero. The time complexity of this function is O(n),
 * where 'n' is the number of elements in the linked list. The space
 * complexity of this function is O(1).
 */
int get_num_occurrences_in_linked_list (struct node* head, int num)
{
    struct node* current;
    int count;

    /*
     * If the head of the linked list is NULL, then return zero
     */
    if (!head) {
        return(0);
    }

    current = head;
    count = 0;

    /*
     * Iterate over the elements in the linked list
     */
    while (current) {

        /*
         * Check if the node's data value matches with
         * 'num'. If so, increment 'count'.
         */
        if (current->data == num) {
            ++count;
        }

        current = current->next;
    }

    /*
     * Return the number of occurrences of 'num'
     */
    return(count);
}

int main ()
{
    /*
     * Test 0: Head of the list points to NULL. Searching a number
     *         in an empty list should return zero.
     */
    struct node* head0 = NULL;
    assert(0 == get_num_occurrences_in_linked_list(head0, 0));

    /*
     * Test 1: There is only one node in the list. Searching a
     *         number is this list should return one.
     */
    struct node* head1 = NULL;
    push(&head1, 1);
    assert(1 == get_num_occurrences_in_linked_list(head1, 1));

    /*
     * Test 2: Test a case with multiple nodes in the list. Test two
     *         cases:-
     *         a. Case when a number exists in the list. The function
     *            should return the number of times that number occurs in
     *            the list.
     *         b. Case when a number does not exists in the list. The
     *            in this case should return zero.
     */
    struct node* head2 = NULL;
    push(&head2, 0);
    push(&head2, 1);
    push(&head2, 2);
    push(&head2, 1);
    push(&head2, 3);
    push(&head2, 1);
    push(&head2, 3);
    push(&head2, 1);
    push(&head2, 4);
    push(&head2, 2);
    push(&head2, 1);
    push(&head2, 1);
    push(&head2, 0);
    assert(6 == get_num_occurrences_in_linked_list(head2, 1));
    assert(0 == get_num_occurrences_in_linked_list(head2, 10));

    return(0);
}
