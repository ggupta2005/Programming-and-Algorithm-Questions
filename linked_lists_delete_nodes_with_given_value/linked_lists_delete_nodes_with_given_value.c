/*
 * This program deletes all nodes from the linked lists having a given value.
 * For Example
 * Given list: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * After deletion list: 1 --> 2 --> 3 --> 4 --> 5
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
 * This function deletes all nodes having a given value from the linked
 * list. The time complexity of this function is O(n), where 'n' is the
 * number of elements in the linked list. The space complexity of this
 * function is O(1).
 */
void delete_nodes_having_value_from_linked_list (struct node** head,
                                                 int val)
{
    struct node* current;
    struct node* prev;
    struct node* temp;
    struct node* new_head;

    /*
     * If the pointer to the head of the linked list is NULL or
     * if the head of the linked list is NULL, then return NULL
     * from this function.
     */
    if (!head || (!*head)) {
        return;
    }

    /*
     * Iterate from the beginning of the list and remove all
     * elements whose value is same as 'val'
     */
    current = *head;
    while (current && (current->data == val)) {

        /*
         * Point 'temp' to 'current'
         */
        temp = current;

        /*
         * Move 'current' to the next element
         */
        current = current->next;

        /*
         * Free 'temp'
         */
        free(temp);
    }

    /*
     * If 'current' is NULL, then all elements in the linked
     * list have been deleted. Set 'head' to NULL and return.
     */
    if (!current) {
        *head = NULL;
        return;
    }

    /*
     * Set 'new_head' to current
     */
    new_head = current;
    prev = NULL;

    /*
     * Iterate until the next pointer in 'current' becomes
     * NULL
     */
    while (current && current->next) {

        /*
         * Set 'prev' to 'cuurent'
         */
        prev = current;

        /*
         * If the match for 'val' is found in 'current-next',
         * then delete this node.
         */
        if (current->next->data == val) {

            /*
             * Point 'temp' to 'current->next'
             */
            temp = current->next;

            /*
             * Move 'current' to the next next element
             */
            current = current->next->next;

            /*
             * Join 'prev' ad the 'current' nodes
             */
            prev->next = current;

            /*
             * Free 'temp'
             */
            free(temp);
        } else {

            /*
             * Otherwise, move current to the next element
             */
            current = current->next;
        }
    }

    /*
     * Point the list head to the 'new_head' pointer
     */
    *head = new_head;
}

int main ()
{
    /*
     * Test 0: Test when the linked list is NULL or empty. The
     *         linked list should remain empty.
     */
    struct node* head0 = NULL;
    int val0 = 1;
    struct node* exp_head0 = NULL;
    delete_nodes_having_value_from_linked_list(&head0, val0);
    assert(true == compare_if_linked_lists_equal(head0, exp_head0));

    /*
     * Test 1: Test when the linked list is non-empty and we try to
     *         delete a non-existent value. The linked list should
     *         remain unchanged.
     */
    struct node* head1 = NULL;
    int val1 = 1;
    struct node* exp_head1 = NULL;
    push(&head1, 9);
    push(&head1, 8);
    push(&head1, 7);
    push(&head1, 9);
    push(&head1, 8);
    push(&head1, 7);
    push(&exp_head1, 9);
    push(&exp_head1, 8);
    push(&exp_head1, 7);
    push(&exp_head1, 9);
    push(&exp_head1, 8);
    push(&exp_head1, 7);
    delete_nodes_having_value_from_linked_list(&head1, val1);
    assert(true == compare_if_linked_lists_equal(head1, exp_head1));

    /*
     * Test 2: Test when the linked list is non-empty and we try to
     *         delete a value which is present in all the nodes of the
     *         linked list. The linked list should be NULL after the
     *         delete operation.
     */
    struct node* head2 = NULL;
    int val2 = 6;
    struct node* exp_head2 = NULL;
    push(&head2, 6);
    push(&head2, 6);
    push(&head2, 6);
    push(&head2, 6);
    push(&head2, 6);
    push(&head2, 6);
    delete_nodes_having_value_from_linked_list(&head2, val2);
    assert(true == compare_if_linked_lists_equal(head2, exp_head2));

    /*
     * Test 3: Test when the linked list is non-empty and we try to
     *         delete a value which occurs alternately in the linked
     *         list starting from the first node. The linked list
     *         not have the nodes having that value.
     */
    struct node* head3 = NULL;
    int val3 = 9;
    struct node* exp_head3 = NULL;
    push(&head3, 9);
    push(&head3, 8);
    push(&head3, 9);
    push(&head3, 8);
    push(&head3, 9);
    push(&head3, 7);
    push(&exp_head3, 8);
    push(&exp_head3, 8);
    push(&exp_head3, 7);
    delete_nodes_having_value_from_linked_list(&head3, val3);
    assert(true == compare_if_linked_lists_equal(head3, exp_head3));

    /*
     * Test 4: Test when the linked list is non-empty and we try to
     *         delete a value which occurs alternately in the linked
     *         list starting from the second node. The linked list
     *         not have the nodes having that value.
     */
    struct node* head4 = NULL;
    int val4 = 9;
    struct node* exp_head4 = NULL;
    push(&head4, 8);
    push(&head4, 9);
    push(&head4, 8);
    push(&head4, 9);
    push(&head4, 7);
    push(&head4, 9);
    push(&exp_head4, 8);
    push(&exp_head4, 8);
    push(&exp_head4, 7);
    delete_nodes_having_value_from_linked_list(&head4, val4);
    assert(true == compare_if_linked_lists_equal(head4, exp_head4));

    return(0);
}
