/*
 * This program swaps nodes in pairs in a linked list. For example if the
 * linked list is 1->2->3->4->5->6, then after the pairwise swap of the nodes
 * the linked list will look like:- 2->1->4->3->6->5. This swap operation
 * should be done in place and the values of the nodes should not be swapped.
 * For more information on the problem, please visit the post:-
 * https://leetcode.com/problems/swap-nodes-in-pairs/
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
 * This function takes a pointer reference to the head of a linked list
 * and swaps the consecutive elements in the list.
 */
void swap_linked_list_nodes_pairwise (struct node** head)
{
    struct node* current;
    struct node* first;
    struct node* second;
    struct node* prev;

    /*
     * If the reference to the head node is NULL or the head of the
     * linked list it self NULL, then return from this function.
     */
    if (!(head) || !(*head)) {
        return;
    }

    /*
     * If there is only one node present in the linked list, then we
     * need not perform any pairwise swaps in the linked list. Return
     * from the function
     */
    if (!(*head)->next) {
        return;
    }

    /*
     * Point 'current' to the head of the linked list
     */
    current = *head;

    /*
     * Point the head of the list to NULL
     */
    *head = NULL;

    /*
     * Point the tracking pointer 'prev' to NULL
     */
    prev = NULL;

    /*
     * Iterate until the 'current' is not NULL or the pointer to the
     * next node is not NULL
     */
    while (current && current->next) {

        /*
         * Let 'first' point to the current node
         */
        first = current;

        /*
         * Let 'second' point to the next node to the 'current' node
         */
        second = current->next;

        /*
         * Point 'current' to the next node to the 'second' node
         */
        current = current->next->next;

        /*
         * Swap the positions of the 'first' and 'second' nodes
         */
        first->next = current;
        second->next = first;

        /*
         * If 'prev' is not NULL, then point the next pointer in 'prev'
         * to the 'second' node and move 'prev' ahead by two nodes
         */
        if (prev) {
            prev->next = second;
            prev = prev->next->next;
        } else {

            /*
             * If 'prev' is NULL, then point the 'prev' to the 'second'
             * node and move 'prev' ahead by one nodes
             */

            prev = second;
            prev = prev->next;
        }

        /*
         * If the head of the linked list is NULL, then point the head
         * of the linked list to the 'second' node
         */
        if (!(*head)) {
            *head = second;
        }
    }
}

int main ()
{
    /*
     * Test 0: Test with the head node being NULL. The head of the linked
     *         list should remain NULL.
     */
    struct node* head0 = NULL;
    struct node* exp_head0 = NULL;
    swap_linked_list_nodes_pairwise(&head0);
    assert(true == compare_if_linked_lists_equal(head0, exp_head0));

    /*
     * Test 1: Test with the only one node in linked list. The linked list
     *         shouldn't change after running the swap operation on the
     *         linked list.
     */
    struct node* head1 = NULL;
    struct node* exp_head1 = NULL;
    push(&head1, 9);
    push(&exp_head1, 9);
    swap_linked_list_nodes_pairwise(&head1);
    assert(true == compare_if_linked_lists_equal(head1, exp_head1));

    /*
     * Test 2: Test with the only two nodes in linked list. The order of
     *         two nodes should get changed in the linked list after
     *         running the swap operation on the linked list.
     */
    struct node* head2 = NULL;
    struct node* exp_head2 = NULL;
    push(&head2, 9);
    push(&head2, 8);
    push(&exp_head2, 8);
    push(&exp_head2, 9);
    swap_linked_list_nodes_pairwise(&head2);
    assert(true == compare_if_linked_lists_equal(head2, exp_head2));

    /*
     * Test 3: Test with the odd number of elements in linked list.
     *         The order of nodes should get changed in the linked list
     *         after running the swap operation on the linked list.
     */
    struct node* head3 = NULL;
    struct node* exp_head3 = NULL;
    push(&head3, 9);
    push(&head3, 8);
    push(&head3, 7);
    push(&head3, 6);
    push(&head3, 5);
    push(&exp_head3, 9);
    push(&exp_head3, 7);
    push(&exp_head3, 8);
    push(&exp_head3, 5);
    push(&exp_head3, 6);
    swap_linked_list_nodes_pairwise(&head3);
    assert(true == compare_if_linked_lists_equal(head3, exp_head3));

    /*
     * Test 4: Test with the even number of elements in linked list.
     *         The order of nodes should get changed in the linked list
     *         after running the swap operation on the linked list.
     */
    struct node* head4 = NULL;
    struct node* exp_head4 = NULL;
    push(&head4, 10);
    push(&head4, 9);
    push(&head4, 8);
    push(&head4, 7);
    push(&head4, 6);
    push(&head4, 5);
    push(&exp_head4, 9);
    push(&exp_head4, 10);
    push(&exp_head4, 7);
    push(&exp_head4, 8);
    push(&exp_head4, 5);
    push(&exp_head4, 6);
    swap_linked_list_nodes_pairwise(&head4);
    assert(true == compare_if_linked_lists_equal(head4, exp_head4));

    return(0);
}
