/*
 * This program adds two numbers represented as linked lists. The head
 * of the linked lists point to the units place digit in the linked list.
 * For more information on this problem, please refer to the following
 * link:-
 *
 * http://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
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

    if ((value > 9) || (value < 0)) {
        return(NULL);
    }

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
 * This function create a new node and appends it the end of the
 * linked list. The time complexity of this function is O(n), where
 * 'n' is the number of nodes in the linked list. The space complexity
 * of this function is O(1).
 */
void insert_at_end_without_tail_ptr (struct node** head, int value)
{
    struct node* new_node;
    struct node* current;

    if (!head) {
        return;
    }

    new_node = makeNode(value);

    if (!new_node) {
        return;
    }

    if (!(*head)) {
        *head = new_node;
    } else {
        current = *head;
        while (current->next) {
            current = current->next;
        }

        current->next = new_node;
    }
}

/*
 * This function create a new node and appends it the end of the
 * linked list at the tail pointer. The time and space complexity of
 * this function is O(1).
 */
void insert_at_end_with_tail_ptr (struct node** head,
                                  struct node** tail, int value)
{
    struct node* new_node;
    struct node* current;

    if (!head || !tail) {
        return;
    }

    new_node = makeNode(value);

    if (!new_node) {
        return;
    }

    if (!(*head)) {
        *head = new_node;
        *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = (*tail)->next;
    }
}

/*
 * This function adds two numbers represented by linked lists and returns
 * the sum as a linked list. The time complexity of this function is O(m + n),
 * where, 'm' and 'n' are lengths of the two linked list numbers.
 */
struct node* add_two_linked_lists_as_numbers (struct node* num1,
                                              struct node* num2)
{
    struct node* head;
    struct node* tail;
    struct node* new_node;
    struct node* current1;
    struct node* current2;
    int carry;
    int rem;

    /*
     * If both the linked lists are empty, then return NULL.
     */
    if (!num1 && !num2) {
        return(NULL);
    }

    current1 = num1;
    current2 = num2;
    carry = 0;
    head = NULL;
    tail = NULL;

    /*
     * Iterate until we reach to the end of either linked lists
     */
    while (current1 && current2) {

        /*
         * Calculate the carry and remainder of the sum of linked list
         * nodes
         */
        rem = (current1->data + current2->data + carry) % 10;
        carry = (current1->data + current2->data + carry) / 10;

        /*
         * Insert the remainder towards the end of the new linked list
         */
        insert_at_end_with_tail_ptr(&head, &tail, rem);

        /*
         * Move down either of the two linked lists
         */
        current1 = current1->next;
        current2 = current2->next;
    }

    /*
     * Iterate until we reach to the end of the first linked lists
     */
    while (current1) {

        /*
         * Calculate the carry and remainder of the sum of linked list
         * nodes
         */
        rem = (current1->data + carry) % 10;
        carry = (current1->data + carry) / 10;

        /*
         * Insert the remainder towards the end of the new linked list
         */
        insert_at_end_with_tail_ptr(&head, &tail, rem);

        /*
         * Move down the first linked lists
         */
        current1 = current1->next;
    }

    /*
     * Iterate until we reach to the end of the second linked lists
     */
    while (current2) {

        /*
         * Calculate the carry and remainder of the sum of linked list
         * nodes
         */
        rem = (current2->data + carry) % 10;
        carry = (current2->data + carry) / 10;

        /*
         * Insert the remainder towards the end of the new linked list
         */
        insert_at_end_with_tail_ptr(&head, &tail, rem);

        /*
         * Move down the second linked lists
         */
        current2 = current2->next;
    }

    /*
     * If carry is greater than zero, insert carry at the end of the
     * new linked list
     */
    if (carry > 0) {
        insert_at_end_with_tail_ptr(&head, &tail, carry);
    }

    /*
     * Return the head of the sum linked list
     */
    return(head);
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

int main ()
{
    /*
     * Test 1: Test when both linked lists are empty. The sum linked list
     *         should also be empty.
     */
    struct node* num11 = NULL;
    struct node* num12 = NULL;
    struct node* exp_add1 = NULL;
    struct node* act_add1 =
                 add_two_linked_lists_as_numbers(num11, num12);
    assert(compare_if_linked_lists_equal(exp_add1, act_add1));

    /*
     * Test 3: Test with one linked list being empty. The sum linked
     *         list should be same as the first linked list.
     */
    struct node* num31 = NULL;
    struct node* num32 = NULL;
    struct node* exp_add3 = NULL;
    insert_at_end_without_tail_ptr(&num31, 2);
    insert_at_end_without_tail_ptr(&num31, 3);
    insert_at_end_without_tail_ptr(&num31, 3);
    insert_at_end_without_tail_ptr(&exp_add3, 2);
    insert_at_end_without_tail_ptr(&exp_add3, 3);
    insert_at_end_without_tail_ptr(&exp_add3, 3);
    struct node* act_add3 =
                 add_two_linked_lists_as_numbers(num31, num32);
    assert(compare_if_linked_lists_equal(exp_add3, act_add3));
    act_add3 = add_two_linked_lists_as_numbers(num32, num31);
    assert(compare_if_linked_lists_equal(exp_add3, act_add3));

    /*
     * Test 4: Test with two linked lists, whose sum will not result
     *         in additional digit in the sum linked list.
     */
    struct node* num41 = NULL;
    struct node* num42 = NULL;
    struct node* exp_add4 = NULL;
    insert_at_end_without_tail_ptr(&num41, 2);
    insert_at_end_without_tail_ptr(&num41, 4);
    insert_at_end_without_tail_ptr(&num41, 3);
    insert_at_end_without_tail_ptr(&num42, 5);
    insert_at_end_without_tail_ptr(&num42, 6);
    insert_at_end_without_tail_ptr(&num42, 4);
    insert_at_end_without_tail_ptr(&exp_add4, 7);
    insert_at_end_without_tail_ptr(&exp_add4, 0);
    insert_at_end_without_tail_ptr(&exp_add4, 8);
    struct node* act_add4 =
                 add_two_linked_lists_as_numbers(num41, num42);
    assert(compare_if_linked_lists_equal(exp_add4, act_add4));

    /*
     * Test 5: Test with two linked lists, whose sum will result
     *         in additional digit in the sum linked list.
     */
    struct node* num51 = NULL;
    struct node* num52 = NULL;
    struct node* exp_add5 = NULL;
    insert_at_end_without_tail_ptr(&num51, 9);
    insert_at_end_without_tail_ptr(&num51, 9);
    insert_at_end_without_tail_ptr(&num51, 9);
    insert_at_end_without_tail_ptr(&num51, 9);
    insert_at_end_without_tail_ptr(&num51, 9);
    insert_at_end_without_tail_ptr(&num52, 1);
    insert_at_end_without_tail_ptr(&exp_add5, 0);
    insert_at_end_without_tail_ptr(&exp_add5, 0);
    insert_at_end_without_tail_ptr(&exp_add5, 0);
    insert_at_end_without_tail_ptr(&exp_add5, 0);
    insert_at_end_without_tail_ptr(&exp_add5, 0);
    insert_at_end_without_tail_ptr(&exp_add5, 1);
    struct node* act_add5 =
                 add_two_linked_lists_as_numbers(num51, num52);
    assert(compare_if_linked_lists_equal(exp_add5, act_add5));
    act_add5 = add_two_linked_lists_as_numbers(num52, num51);
    assert(compare_if_linked_lists_equal(exp_add5, act_add5));

    return(0);
}
