/*
 * This program inserts an element into a sorted linked list.
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
 * This function returns true if the two linked lists are identical i.e.
 * if the two linked lists satify the following conditions:-
 * 1. The two linked lists have the same number of elements
 * 2. The two linked have the same elements
 * 3. The two linked lists have the same ordering among these elements
 * If the two linked lists do not satify any of the above the conditions,
 * then this function will return 'false' otherwise this function will
 * return 'true'. The time complexity of this function is O(n), where 'n'
 * is the number of elements in either linked lists. The space complexity
 * of this function is O(1).
 */
bool compare_if_linked_lists_equal (struct node* head1,
                                    struct node* head2)
{
    /*
     * If both linked lists are NULL, then return 'true'
     */
    if (!head1 && !head2) {
        return(true);
    }

    /*
     * Iterate until either head of the linked lists points to
     * NULL
     */
    while (head1 && head2) {

        /*
         * If the data in the two nodes is not equal, then
         * return 'false'
         */
        if (head1->data != head2->data) {
            return(false);
        }

        /*
         * Move the head pointers of the linked lists to point to
         * two the next nodes
         */
        head1 = head1->next;
        head2 = head2->next;
    }

    /*
     * If either of the heads of the two linked lists is not NULL,
     * then the linked lists are not identical. Return 'false'.
     */
    if (head1 || head2) {
        return(false);
    }

    /*
     * At this point, the linked lists are identical So eturn'true'.
     */
    return(true);
}

/*
 * This function adds an element into a sorted linked list. The time
 * complexity of this function is O(n), where 'n' is the number of
 * elements in the linked list. The space complexity of this function
 * is O(1).
 */
void insert_into_sorted_list (struct node** head, int num)
{
    struct node *current, *prev, *temp;

    /*
     * If the reference to a node in the linked list head is NULL,
     * then return from the function.
     */
    if (!head) {
        return;
    }

    /*
     * Create a node to be inserted into the linked list
     */
    temp = makeNode(num);


    if (!temp) {
        return;
    }

    /*
     * If the head of the linked list is NULL, so point the
     * head to the new node and return
     */
    if (!(*head)) {
        *head = temp;
        return;
    }

    /*
     * Iterate into the sorted to find the location in the
     * linked list where the node could be inserted
     */
    current = *head;
    prev = NULL;
    while (current) {

        if (temp->data < current->data) {
            break;
        }

        /*
         * Keep track of the previous pointer to keep track
         * of the position where the new element needs to
         * inserted
         */
        prev = current;
        current = current->next;
    }

    if (prev) {

        /*
         * If previous pointer is valid, then insert the
         * new element next to the previous pointer
         */
        temp->next = prev->next;
        prev->next = temp;
    } else {

        /*
         * Otherwise, insert the element in front of the
         * linked list
         */
        temp->next = *head;
        *head =temp;
    }
}

int main ()
{
    /*
     * Test 0: Insert into an empty lined list.
     */
    struct node* head0 = NULL;
    struct node* exp_head0 = NULL;
    push(&exp_head0, 10);
    insert_into_sorted_list(&head0, 10);
    assert(true == compare_if_linked_lists_equal(head0, exp_head0));

    /*
     * Test 1: Insert into a sorted list such that the new node gets inserted
     *         to the head of the linked list.
     */
    struct node* head1 = NULL;
    struct node* exp_head1 = NULL;
    push(&head1, 10000);
    push(&head1, 1000);
    push(&head1, 1000);
    push(&head1, 100);
    push(&head1, 10);
    push(&exp_head1, 10000);
    push(&exp_head1, 1000);
    push(&exp_head1, 1000);
    push(&exp_head1, 100);
    push(&exp_head1, 10);
    push(&exp_head1, 1);
    insert_into_sorted_list(&head1, 1);
    assert(true == compare_if_linked_lists_equal(head1, exp_head1));

    /*
     * Test 2: Insert into a sorted list such that the new node gets inserted
     *         into the middle of the linked list.
     */
    struct node* head2 = NULL;
    struct node* exp_head2 = NULL;
    push(&head2, 20000);
    push(&head2, 2000);
    push(&head2, 2000);
    push(&head2, 20);
    push(&head2, 2);
    push(&exp_head2, 20000);
    push(&exp_head2, 2000);
    push(&exp_head2, 2000);
    push(&exp_head2, 200);
    push(&exp_head2, 20);
    push(&exp_head2, 2);
    insert_into_sorted_list(&head2, 200);
    assert(true == compare_if_linked_lists_equal(head2, exp_head2));

    /*
     * Test 3: Insert into a sorted list such that the new node gets inserted
     *         into the linked list which already has that value.
     */
    struct node* head3 = NULL;
    struct node* exp_head3 = NULL;
    push(&head3, 30000);
    push(&head3, 3000);
    push(&head3, 300);
    push(&head3, 30);
    push(&head3, 3);
    push(&exp_head3, 30000);
    push(&exp_head3, 3000);
    push(&exp_head3, 3000);
    push(&exp_head3, 300);
    push(&exp_head3, 30);
    push(&exp_head3, 3);
    insert_into_sorted_list(&head3, 3000);
    assert(true == compare_if_linked_lists_equal(head3, exp_head3));

    /*
     * Test 4: Insert into a sorted list such that the new node gets inserted
     *         to the end of the linked list.
     */
    struct node* head4 = NULL;
    struct node* exp_head4 = NULL;
    push(&head4, 40000);
    push(&head4, 4000);
    push(&head4, 4000);
    push(&head4, 400);
    push(&head4, 40);
    push(&head4, 4);
    push(&exp_head4, 400000);
    push(&exp_head4, 40000);
    push(&exp_head4, 4000);
    push(&exp_head4, 4000);
    push(&exp_head4, 400);
    push(&exp_head4, 40);
    push(&exp_head4, 4);
    insert_into_sorted_list(&head4, 400000);
    assert(true == compare_if_linked_lists_equal(head4, exp_head4));

    return(0);
}
