/*
 * This program rotates a list to the right by k places, where 'k' is
 * a positive number.
 * For example, if 'k' is 2 and the linked list is
 * 1->2->3->4->5->NULL, then the right rotated linked list will be
 * 4->5->1->2->3->NULL
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

/*
 * This function right rotates a linked list by 'k' places. The
 * linked list remains unchanged if the value of 'k' is more than
 * the length of the linked list. The time complexity of this
 * function is O(n), where 'n' is the number of elements in the
 * linked list. The space complexity of this function is O(1).
 */
void right_rotate_list_by_k_places (struct node** head, int k)
{
    struct node* break_node;
    struct node* break_node_next;
    struct node* last_node;

    /*
     * If the reference to the head node is not valid or if 'k'
     * is less than or equal to zero, then return from this function.
     * We cannot perform the linked list rotation.
     */
    if (!head || !(*head) || (k <= 0)) {
        return;
    }

    /*
     * Find the pointer to the previous node to the kth node from
     * end in the linked list. Let's call this node the 'break_node'.
     */
    break_node = get_kth_node_from_end(*head, k + 1);

    /*
     * Find the pointer to the last node in the linked list
     */
    last_node = get_kth_node_from_end(*head, 1);

    /*
     * If either of 'break_node' or the last node in the linked
     * list is NULL, return from the function. We cannot perform
     * the linked list rotation.
     */
    if (!break_node || !last_node) {
        return;
    }

    /*
     * Cache the next pointer in the 'break_node'. This will be
     * the new head in the right rotated linked list.
     */
    break_node_next = break_node->next;

    /*
     * Set the next pointer in the 'break_node' to NULL.
     */
    break_node->next = NULL;

    /*
     * Point the next of the last node in the linked list to
     * point to the current head. This rotates the linked list
     * by 'k' places
     */
    last_node->next = *head;

    /*
     * Set the head of the linked list to 'break_node_next'
     */
    *head = break_node_next;
}

int main ()
{
    /*
     * Test 0: Test with the head node being NULL. The head of the linked
     *         list should remain NULL after the rotation operation.
     */
    struct node* head0 = NULL;
    int k0 = 2;
    struct node* exp_head0 = NULL;
    right_rotate_list_by_k_places(&head0, k0);
    assert(true == compare_if_linked_lists_equal(head0, exp_head0));

    /*
     * Test 1: Test with the only one node in linked list. The linked list
     *         shouldn't change after running the rotate operation on the
     *         linked list.
     */
    struct node* head1 = NULL;
    int k1 = 2;
    struct node* exp_head1 = NULL;
    push(&head1, 9);
    push(&exp_head1, 9);
    right_rotate_list_by_k_places(&head1, k1);
    assert(true == compare_if_linked_lists_equal(head1, exp_head1));

    /*
     * Test 2: Test with the only two nodes in linked list. The order of
     *         two nodes should get changed in the linked list after
     *         running the rotate operation on the linked list with 'k'
     *         as one.
     */
    struct node* head2 = NULL;
    int k2 = 1;
    struct node* exp_head2 = NULL;
    push(&head2, 9);
    push(&head2, 8);
    push(&exp_head2, 8);
    push(&exp_head2, 9);
    right_rotate_list_by_k_places(&head2, k2);
    assert(true == compare_if_linked_lists_equal(head2, exp_head2));

    /*
     * Test 3: Test with the 'k' as two. The last two nodes in the
     *         linked list should appear in from of the list after the
     *         rotation operation on the linked list.
     */
    struct node* head3 = NULL;
    int k3 = 2;
    struct node* exp_head3 = NULL;
    push(&head3, 9);
    push(&head3, 8);
    push(&head3, 7);
    push(&head3, 6);
    push(&head3, 5);
    push(&exp_head3, 7);
    push(&exp_head3, 6);
    push(&exp_head3, 5);
    push(&exp_head3, 9);
    push(&exp_head3, 8);
    right_rotate_list_by_k_places(&head3, k3);
    assert(true == compare_if_linked_lists_equal(head3, exp_head3));

    /*
     * Test 4: Test with the value of 'k' being equal to the length of the
     *         linked list. After calling the right rotation function,
     *         there should not be any modification to the linked list.
     */
    struct node* head4 = NULL;
    int k4 = 6;
    struct node* exp_head4 = NULL;
    push(&head4, 10);
    push(&head4, 9);
    push(&head4, 8);
    push(&head4, 7);
    push(&head4, 6);
    push(&head4, 5);
    push(&exp_head4, 10);
    push(&exp_head4, 9);
    push(&exp_head4, 8);
    push(&exp_head4, 7);
    push(&exp_head4, 6);
    push(&exp_head4, 5);
    right_rotate_list_by_k_places(&head4, k4);
    assert(true == compare_if_linked_lists_equal(head4, exp_head4));

    /*
     * Test 5: Test with the value of 'k' being greater than the length of
     *         linked list. After calling the right rotation function,
     *         there should not be any modification to the linked list.
     */
    struct node* head5 = NULL;
    int k5 = 10;
    struct node* exp_head5 = NULL;
    push(&head5, 10);
    push(&head5, 9);
    push(&head5, 8);
    push(&head5, 7);
    push(&head5, 6);
    push(&head5, 5);
    push(&exp_head5, 10);
    push(&exp_head5, 9);
    push(&exp_head5, 8);
    push(&exp_head5, 7);
    push(&exp_head5, 6);
    push(&exp_head5, 5);
    right_rotate_list_by_k_places(&head5, k5);
    assert(true == compare_if_linked_lists_equal(head5, exp_head5));

    /*
     * Test 6: Test with an invalid value of 'k'. After calling the right
     *         rotation function, there should not be any modification to
     *         the linked list.
     */
    struct node* head6 = NULL;
    int k6 = -10;
    struct node* exp_head6 = NULL;
    push(&head6, 10);
    push(&head6, 9);
    push(&head6, 8);
    push(&head6, 7);
    push(&head6, 6);
    push(&head6, 5);
    push(&exp_head6, 10);
    push(&exp_head6, 9);
    push(&exp_head6, 8);
    push(&exp_head6, 7);
    push(&exp_head6, 6);
    push(&exp_head6, 5);
    right_rotate_list_by_k_places(&head6, k6);
    assert(true == compare_if_linked_lists_equal(head6, exp_head6));

    return(0);
}
