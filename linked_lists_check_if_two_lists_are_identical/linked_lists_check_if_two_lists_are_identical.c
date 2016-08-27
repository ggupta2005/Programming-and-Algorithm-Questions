/*
 * This program checks if two linked lists are identical. Two linked lists
 * are said to be identical if there are lengths are same and also if the
 * contents of the two linked lists are same in the same relative order.
 * For information on this problem, please visit the following post:
 * http://www.geeksforgeeks.org/identical-linked-lists/
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

int main ()
{
    /*
     * Test 0: Both the linked lists point to NULL. These two
     *         lists should be identical.
     */
    struct node* head01 = NULL;
    struct node* head02 = NULL;
    assert(true == compare_if_linked_lists_equal(head01, head02));

    /*
     * Test 1: First of the linked lists point to NULL. The other list
     *         not NULL. These two lists should not be identical.
     */
    struct node* head11 = NULL;
    struct node* head12 = NULL;
    push(&head12, 9);
    assert(false == compare_if_linked_lists_equal(head11, head12));

    /*
     * Test 2: Second of the linked lists point to NULL. The other list
     *         not NULL. These two lists should not be identical.
     */
    struct node* head21 = NULL;
    struct node* head22 = NULL;
    push(&head21, 9);
    assert(false == compare_if_linked_lists_equal(head21, head22));

    /*
     * Test 3: Test a case when the lists are identical with the same
     *         number of elements and same ordering of elements.
     */
    struct node* head31 = NULL;
    struct node* head32 = NULL;
    push(&head31, 9);
    push(&head31, 8);
    push(&head31, 7);
    push(&head32, 9);
    push(&head32, 8);
    push(&head32, 7);
    assert(true == compare_if_linked_lists_equal(head31, head32));

    /*
     * Test 4: Test a case when the lists are not identical with the same
     *         number of elements but different ordering of elements.
     */
    struct node* head41 = NULL;
    struct node* head42 = NULL;
    push(&head41, 9);
    push(&head41, 8);
    push(&head41, 7);
    push(&head42, 9);
    push(&head42, 7);
    push(&head42, 8);
    assert(false == compare_if_linked_lists_equal(head41, head42));

    /*
     * Test 5: Test a case when the lists are not identical with
     *         different number of elements.
     */
    struct node* head51 = NULL;
    struct node* head52 = NULL;
    push(&head51, 9);
    push(&head51, 8);
    push(&head51, 7);
    push(&head52, 9);
    push(&head52, 8);
    assert(false == compare_if_linked_lists_equal(head51, head52));

    return(0);
}
