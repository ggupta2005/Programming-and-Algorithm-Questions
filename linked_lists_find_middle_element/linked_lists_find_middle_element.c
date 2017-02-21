/*
 * Given a singly linked list, find middle of the linked list. For example,
 * if given linked list is 1->2->3->4->5 then output should be 3. If there are
 * even nodes, then there would be two middle nodes, we need to find the second
 * middle element. For example, if given linked list is 1->2->3->4->5->6 then
 * output should be 4.
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
 * This function returns the middle element in a linear linked list. The time
 * complexity of this function is O(n), where 'n' is the number of elements in
 * the linked list. The space complexity of this function is O(1).
 */
struct node* find_linked_list_middle_element (struct node* head)
{
    struct node* fast;
    struct node* slow;

    /*
     * If the head of the linked list is NULL, then return NULL
     */
    if (!head) {
        return(NULL);
    }

    /*
     * Point both 'fast' and 'slow' pointers to the head of the
     * linked list
     */
    fast = head;
    slow = head;

    /*
     * Iterate through the list linked list
     */
    while (fast && fast->next) {

        /*
         * Move the 'fast' pointer by two nodes
         */
        fast = fast->next->next;

        /*
         * Move the 'slow' pointer by one node
         */
        slow = slow->next;
    }

    /*
     * Return the 'slow' pointer
     */
    return(slow);
}

int main ()
{
    /*
     * Test 1: Head of the list points to NULL. The middle element
     *         should also point to NULL.
     */
    struct node* head1 = NULL;
    struct node* middle1 = NULL;
    middle1 = find_linked_list_middle_element(head1);
    assert(NULL == middle1);

    /*
     * Test 2: There is only one node in the list. The middle element
     *         should be the only element in the linked list.
     */
    struct node* head2 = NULL;
    struct node* middle2 = NULL;
    push(&head2, 1);
    middle2 = find_linked_list_middle_element(head2);
    assert((NULL != middle2) && (middle2->data == 1));

    /*
     * Test 3: There are only two nodes in the list. The middle element
     *         should be the last element in the linked list.
     */
    struct node* head3 = NULL;
    struct node* middle3 = NULL;
    push(&head3, 2);
    push(&head3, 1);
    middle3 = find_linked_list_middle_element(head3);
    assert((NULL != middle3) && (middle3->data == 2));

    /*
     * Test 4: There are odd number of nodes in the list. The middle
     *         element should be the middle element in the linked list.
     */
    struct node* head4 = NULL;
    struct node* middle4 = NULL;
    push(&head4, 5);
    push(&head4, 4);
    push(&head4, 3);
    push(&head4, 2);
    push(&head4, 1);
    middle4 = find_linked_list_middle_element(head4);
    assert((NULL != middle4) && (middle4->data == 3));

    /*
     * Test 5: There are even number of nodes in the list. The middle
     *         element should be the first element in the second half of
     *         the linked list.
     */
    struct node* head5 = NULL;
    struct node* middle5 = NULL;
    push(&head5, 6);
    push(&head5, 5);
    push(&head5, 4);
    push(&head5, 3);
    push(&head5, 2);
    push(&head5, 1);
    middle5 = find_linked_list_middle_element(head5);
    assert((NULL != middle5) && (middle5->data == 4));

    return(0);
}
