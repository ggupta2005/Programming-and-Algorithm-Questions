/*
 * This program sorts a linked list haing zeros and ones. For example:-
 * List : 0->1->0->1->0->1->0->//
 * Sorted list: 0->0->0->0->1->1->1->//
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
 * This function sorts a linked list containing zeros and ones
 * in-place. The time complexity of this function is O(n), where
 * 'n' is the number of elements in the linked list. The space
 * complexity of this function is O(1).
 */
void sort_list_zeros_and_ones (struct node** head)
{
    struct node* new_head;
    struct node* new_tail;
    struct node* temp;
    struct node* current;

    /*
     * If the list is empty or the address of the head of the
     * list is NULL, then return from the function
     */
    if (!head || !(*head)) {
        return;
    }

    /*
     * Get the reference of the head of the list
     */
    current = *head;
    new_head = NULL;
    new_tail = NULL;

    /*
     * Iterate until we reach to the end of the list
     */
    while (current) {

        /*
         * Point 'temp' to 'current' and advance 'current'
         * down the list
         */
        temp = current;
        current = current->next;
        temp->next = NULL;

        if (temp->data == 0) {

            /*
             * If the data in the node is zero, then add the node
             * to the front of the new list
             */
            if (!new_head) {

                /*
                 * If the new list is empty, then set the head and tail
                 * to the node
                 */
                new_head = new_tail = temp;
            } else {

                /*
                 * Add the node to the head of the new list
                 */
                temp->next = new_head;
                new_head = temp;
            }
        } else {

            /*
             * If the data in the node is one, then add the node
             * to the to the end of the new list
             */
            if (!new_head) {

                /*
                 * If the new list is empty, then set the head and tail
                 * to the node
                 */
                new_head = new_tail = temp;
            } else {

                /*
                 * Add the node to the tail of the new list
                 */
                new_tail->next = temp;
                new_tail = temp;
            }
        }
    }

    /*
     * Set the original head to the head of the new list
     */
    *head = new_head;
}

int main ()
{
    /*
     * Test 0: Sort an empty linked list. The linked list should
     *         remain empty after sorting as well.
     */
    struct node* head0 = NULL;
    struct node* sort0 = NULL;
    sort_list_zeros_and_ones(&head0);
    assert(true == compare_if_linked_lists_equal(head0, sort0));

    /*
     * Test 1: Sort a linked list having only one element which
     *         is zero. The linked list should not change after
     *         sorting.
     */
    struct node* head1 = NULL;
    struct node* sort1 = NULL;
    push(&head1, 0);
    push(&sort1, 0);
    sort_list_zeros_and_ones(&head1);
    assert(true == compare_if_linked_lists_equal(head1, sort1));

    /*
     * Test 2: Sort a linked list having only one element which
     *         is one. The linked list should not change after
     *         sorting.
     */
    struct node* head2 = NULL;
    struct node* sort2 = NULL;
    push(&head2, 1);
    push(&sort2, 1);
    sort_list_zeros_and_ones(&head2);
    assert(true == compare_if_linked_lists_equal(head2, sort2));

    /*
     * Test 3: Sort a linked list having mix of zeros and ones.
     *         The linked list after sorting should have zeros
     *         followed by ones.
     */
    struct node* head3 = NULL;
    struct node* sort3 = NULL;
    push(&head3, 1);
    push(&head3, 0);
    push(&head3, 1);
    push(&head3, 1);
    push(&head3, 0);
    push(&head3, 1);
    push(&sort3, 1);
    push(&sort3, 1);
    push(&sort3, 1);
    push(&sort3, 1);
    push(&sort3, 0);
    push(&sort3, 0);
    sort_list_zeros_and_ones(&head3);
    assert(true == compare_if_linked_lists_equal(head3, sort3));

    /*
     * Test 4: Sort a linked list having mix of zeros and ones.
     *         The linked list after sorting should have zeros
     *         followed by ones.
     */
    struct node* head4 = NULL;
    struct node* sort4 = NULL;
    push(&head4, 1);
    push(&head4, 0);
    push(&head4, 1);
    push(&head4, 1);
    push(&head4, 0);
    push(&head4, 0);
    push(&sort4, 1);
    push(&sort4, 1);
    push(&sort4, 1);
    push(&sort4, 0);
    push(&sort4, 0);
    push(&sort4, 0);
    sort_list_zeros_and_ones(&head4);
    assert(true == compare_if_linked_lists_equal(head4, sort4));

    /*
     * Test 5: Sort a linked list having only elements which are
     *         all ones. The linked list should not change after
     *         sorting.
     */
    struct node* head5 = NULL;
    struct node* sort5 = NULL;
    push(&head5, 1);
    push(&head5, 1);
    push(&head5, 1);
    push(&head5, 1);
    push(&head5, 1);
    push(&head5, 1);
    push(&sort5, 1);
    push(&sort5, 1);
    push(&sort5, 1);
    push(&sort5, 1);
    push(&sort5, 1);
    push(&sort5, 1);
    sort_list_zeros_and_ones(&head5);
    assert(true == compare_if_linked_lists_equal(head5, sort5));

    /*
     * Test 6: Sort a linked list having only elements which are
     *         all zeros. The linked list should not change after
     *         sorting.
     */
    struct node* head6 = NULL;
    struct node* sort6 = NULL;
    push(&head6, 0);
    push(&head6, 0);
    push(&head6, 0);
    push(&head6, 0);
    push(&head6, 0);
    push(&head6, 0);
    push(&sort6, 0);
    push(&sort6, 0);
    push(&sort6, 0);
    push(&sort6, 0);
    push(&sort6, 0);
    push(&sort6, 0);
    sort_list_zeros_and_ones(&head6);
    assert(true == compare_if_linked_lists_equal(head6, sort6));

    return(0);
}
