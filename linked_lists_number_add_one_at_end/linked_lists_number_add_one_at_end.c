/*
 * Given a non-negative integer represented as non-empty a singly linked
 * list of digits, plus one to the integer. You may assume the integer do
 * not contain any leading zero, except the number 0 itself. The digits are
 * stored such that the most significant digit is at the head of the list.
 *
 * Example:
 * Input:
 * 1->2->3
 *
 * Output:
 * 1->2->4
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


int add_one_and_get_carry_at_end_to_number (struct node* head)
{
    int carry;

    if (!head) {
        return(0);
    }

    if (!(head->next)) {
        if (head->data == 9) {
            head->data = 0;
            return(1);
        } else {
            head->data += 1;
            return(0);
        }
    }

    carry = add_one_and_get_carry_at_end_to_number(head->next);

    if (head->data + carry > 9) {
        head->data = 0;
        return(1);
    }

    head->data += carry;
    return(0);
}

void add_one_at_end_to_number (struct node** head)
{
    int carry;
    struct node* temp;

    if (!head || !(*head)) {
        return;
    }

    carry = add_one_and_get_carry_at_end_to_number(*head);

    if (carry > 0) {
        temp = makeNode(carry);
        temp->next = *head;
        *head = temp;
    }
}

void add_one_at_end_to_number_v1 (struct node** head)
{
    struct node* current;
    struct node* temp;
    struct node* head_rev;
    int carry;

    if (!head || !(*head)) {
        return;
    }

    head_rev = NULL;
    current = *head;
    while (current) {

        temp = current;
        current = current->next;
        temp->next = NULL;

        if (!head_rev) {
            head_rev = temp;
        } else {
            temp->next = head_rev;
            head_rev = temp;
        }
    }

    carry = 1;
    current = head_rev;
    while (current) {
        if (current->data + carry > 9) {
            current->data = 0;
            carry = 1;
        } else {
            current->data += carry;
            carry = 0;
        }

        current = current->next;
    }

    *head = NULL;
    current = head_rev;
    while (current) {
        temp = current;
        current = current->next;
        temp->next = NULL;

        if (!(*head)) {
            *head = temp;
        } else {
            temp->next = *head;
            *head = temp;
        }
    }

    if (carry == 1) {
        temp = makeNode(1);

        if (*head) {
            temp->next = *head;
            *head = temp;
        } else {
            *head = temp;
        }
    }
}

int main ()
{
    struct node* head0 = NULL;
    struct node* exp_head0 = NULL;
    add_one_at_end_to_number(&head0);
    assert(true == compare_if_linked_lists_equal(head0, exp_head0));

    struct node* head1 = NULL;
    struct node* exp_head1 = NULL;
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);
    push(&exp_head1, 4);
    push(&exp_head1, 2);
    push(&exp_head1, 1);
    add_one_at_end_to_number(&head1);
    assert(true == compare_if_linked_lists_equal(head1, exp_head1));

    struct node* head2 = NULL;
    struct node* exp_head2 = NULL;
    push(&head2, 9);
    push(&head2, 9);
    push(&head2, 5);
    push(&exp_head2, 0);
    push(&exp_head2, 0);
    push(&exp_head2, 6);
    add_one_at_end_to_number(&head2);
    assert(true == compare_if_linked_lists_equal(head2, exp_head2));

    struct node* head3 = NULL;
    struct node* exp_head3 = NULL;
    push(&head3, 9);
    push(&head3, 9);
    push(&head3, 9);
    push(&exp_head3, 0);
    push(&exp_head3, 0);
    push(&exp_head3, 0);
    push(&exp_head3, 1);
    add_one_at_end_to_number(&head3);
    assert(true == compare_if_linked_lists_equal(head3, exp_head3));

    struct node* head4 = NULL;
    struct node* exp_head4 = NULL;
    push(&head4, 9);
    push(&head4, 9);
    push(&head4, 8);
    push(&head4, 6);
    push(&exp_head4, 0);
    push(&exp_head4, 0);
    push(&exp_head4, 9);
    push(&exp_head4, 6);
    add_one_at_end_to_number(&head4);
    assert(true == compare_if_linked_lists_equal(head4, exp_head4));

    return(0);
}
