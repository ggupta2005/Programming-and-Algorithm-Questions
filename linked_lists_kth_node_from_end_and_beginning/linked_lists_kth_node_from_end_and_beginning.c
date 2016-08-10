/*
 * This program finds the kth node from end and kth node from
 * beginning in a linear linked list. For more information on
 * this, please refer to the following post:-
 * http://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
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
    struct node* data_node = (struct node *)malloc(sizeof(struct node*));

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
 * This function returns pointer to the kth node from the beginning
 * of a linear linked list. If the value of 'k' is less than or equal
 * to 0 or if 'k' is greater than the number of elements in the linked
 * list, then this function returns NULL. The time complexity of this
 * function is O(n), where 'n' is the number of elements in the linked
 * list.
 */
struct node* get_kth_node_from_beginning (struct node* head, int k)
{
    int i;
    struct node* current;

    /*
     * If the head of the linked list is NULL or if the value
     * of 'k' is not legal, then return NULL
     */
    if (!head || (k <= 0)) {
        return(NULL);
    }

    /*
     * Set 'current' to point to the head of the linked list
     */
    current = head;

    /*
     * Have an index to keep track of the number of elements
     * traversed in the linked list. This is set to one because
     * we are starting from the head of the list.
     */
    i = 1;

    /*
     * Iterate until current is valid or the index is strictly
     * less than 'k'
     */
    while (current && (i < k)) {

        /*
         * Point 'current' to the next element in the linked list
         */
        current = current->next;

        /*
         * Increment the index
         */
        ++i;
    }

    /*
     * Return the pointer to the kth element from beginning
     */
    return(current);
}

/*
 * This function returns pointer to the kth node from the end of a
 * linear linked list. If the value of 'k' is less than or equal to 0
 * or if 'k' is greater than the number of elements in the linked
 * list, then this function returns NULL. We use the following
 * approach to find the kth element from end in the linked list:-
 * 1. Get to the kth element from beginning in the linked list
 * 2. Put a pointer to the beginning of the list
 * 3. Iterate through the linked list till the pointer to the
 *    kth element points to the last node in the linked list.
 *    simultaneously move the head pointer to point to the next
 *    element.After the end of the while loop, the pointer to
 *    head of the node will point to the 'kth' element from end.
 * The time complexity of this function is O(n), where 'n' is the
 * number of elements in the linked list.
 */
struct node* get_kth_node_from_end (struct node* head, int k)
{
    int i;
    struct node* current;
    struct node* kth_from_end;

    /*
     * If the head of the linked list is NULL or if the value
     * of 'k' is not legal, then return NULL
     */
    if (!head || (k <= 0)) {
        return(NULL);
    }

    /*
     * Set 'current' to point to the head of the linked list
     */
    current = head;

    /*
     * Have an index to keep track of the number of elements
     * traversed in the linked list. This is set to one because
     * we are starting from the head of the list.
     */
    i = 1;

    /*
     * Iterate until current is valid or the index is strictly
     * less than 'k'
     */
    while (current && (i < k)) {

        /*
         * Point 'current' to the next element in the linked list
         */
        current = current->next;

        /*
         * Increment the index
         */
        ++i;
    }

    /*
     * If the kth element from beginning in NULL, then we cannot
     * get the kth element from end. Return NULL.
     */
    if (!current) {
        return(NULL);
    }

    /*
     * Place a pointer to the head of the linked list
     */
    kth_from_end = head;

    /*
     * Iterate until the kth element pointer reaches the last
     * node in the list
     */
    while (current->next) {

        /*
         * point the current pointer to the next element in the
         * linked list
         */
        current = current->next;

        /*
         * Move the 'kth_from_end' pointer to the next element
         * in the linked list
         */
        kth_from_end = kth_from_end->next;
    }

    /*
     * Return the pointer to the kth-element from end of list
     */
    return(kth_from_end);
}

int main ()
{
    /*
     * Test 0: Test with head pointer being NULL. The kth element
     *         from beginning and end should point to NULL.
     */
    struct node* head0 = NULL;
    int k0 = 10;
    assert(NULL == get_kth_node_from_beginning(head0, k0));
    assert(NULL == get_kth_node_from_end(head0, k0));

    /*
     * Test 1: Test with 'k' being illegal. The kth element from
     *         beginning and end should point to NULL.
     */
    struct node* head1 = NULL;
    int k1 = -10;
    push(&head1, 1);
    assert(NULL == get_kth_node_from_beginning(head1, k1));
    assert(NULL == get_kth_node_from_end(head1, k1));

    /*
     * Test 2: Test with 'k' being greater than the total number of
     *         elements in the linked list. The kth element from
     *         beginning and end should point to NULL.
     */
    struct node* head2 = NULL;
    int k2 = 2;
    push(&head2, 1);
    assert(NULL == get_kth_node_from_beginning(head2, k2));
    assert(NULL == get_kth_node_from_end(head2, k2));

    /*
     * Test 3: Test with 'k' being equal to the total number of
     *         elements in the linked list. The kth element from
     *         beginning should be the last element in the list
     *         and kth element from end should be the first
     *         element in the linked list.
     */
    struct node* head3 = NULL;
    int k3 = 2;
    struct node* expected_beg3 = NULL;
    struct node* expected_end3 = NULL;
    push(&head3, 1);
    push(&head3, 2);
    expected_beg3 = get_kth_node_from_beginning(head3, k3);
    expected_end3 = get_kth_node_from_end(head3, k3);
    assert(expected_beg3 && expected_beg3->data == 1);
    assert(expected_end3 && expected_end3->data == 2);

    /*
     * Test 4: Test with 'k' being equal to half of number of
     *         elements in the linked list. The kth element from
     *         beginning and end should be the middle element in
     *         the list.
     */
    struct node* head4 = NULL;
    int k4 = 3;
    struct node* expected_beg4 = NULL;
    struct node* expected_end4 = NULL;
    push(&head4, 1);
    push(&head4, 2);
    push(&head4, 3);
    push(&head4, 4);
    push(&head4, 5);
    expected_beg4 = get_kth_node_from_beginning(head4, k4);
    expected_end4 = get_kth_node_from_end(head4, k4);
    assert(expected_beg4 && expected_beg4->data == 3);
    assert(expected_end4 && expected_end4->data == 3);

    return(0);
}
