/*
 * This program rotates a list to the right by k places, where 'k' is
 * a positive number.
 * For example, if 'k' is 2 and the linked list is
 * 1->2->3->4->5->null, then the right rotated linked list will be
 * 4->5->1->2->3->null
 */
import java.io.*;
import java.util.*;

/*
 * Class definition of a linked list node
 */
class node
{
    int data;
    node next;

    node (int value)
    {
        data = value;
        next = null;
    }

}

public class linked_lists_right_rotate_list_by_k_places
{
    node head;

    linked_lists_right_rotate_list_by_k_places ()
    {
        head = null;
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
    public static boolean compare_if_linked_lists_equal (node head1,
                                                         node head2)
    {
        /*
         * If both linked lists are null, then return 'true'
         */
        if ((head1 == null) && (head2 == null)) {
            return(true);
        }

        /*
         * Iterate until either head of the linked lists points to
         * null
         */
        while ((head1 != null) && (head2 != null)) {

            /*
             * If the data in the two nodes is not equal, then
             * return 'false'
             */
            if (head1.data != head2.data) {
                return(false);
            }

            /*
             * Move the head pointers of the linked lists to point to
             * two the next nodes
             */
            head1 = head1.next;
            head2 = head2.next;
        }

        /*
         * If either of the heads of the two linked lists is not null,
         * then the linked lists are not identical. Return 'false'.
         */
        if ((head1 != null) || (head2 != null)) {
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
     * list, then this function returns null. We use the following
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
    public node get_kth_node_from_end (int k)
    {
        int i;
        node current;
        node kth_from_end;

        /*
         * If the head of the linked list is null or if the value
         * of 'k' is not legal, then return null
         */
        if ((head == null) || (k <= 0)) {
            return(null);
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
        while ((current != null) && (i < k)) {

            /*
             * Point 'current' to the next element in the linked list
             */
            current = current.next;

            /*
             * Increment the index
             */
            ++i;
        }

        /*
         * If the kth element from beginning in null, then we cannot
         * get the kth element from end. Return null.
         */
        if (current == null) {
            return(null);
        }

        /*
         * Place a pointer to the head of the linked list
         */
        kth_from_end = head;

        /*
         * Iterate until the kth element pointer reaches the last
         * node in the list
         */
        while (current.next != null) {

            /*
             * point the current pointer to the next element in the
             * linked list
             */
            current = current.next;

            /*
             * Move the 'kth_from_end' pointer to the next element
             * in the linked list
             */
            kth_from_end = kth_from_end.next;
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
    public void right_rotate_list_by_k_places (int k)
    {
        node break_node;
        node break_node_next;
        node last_node;

        /*
         * If the reference to the head node is not valid or if 'k'
         * is less than or equal to zero, then return from this function.
         * We cannot perform the linked list rotation.
         */
        if ((head == null) || (k <= 0)) {
            return;
        }

        /*
         * Find the pointer to the previous node to the kth node from
         * end in the linked list. Let's call this node the 'break_node'.
         */
        break_node = get_kth_node_from_end(k + 1);

        /*
         * Find the pointer to the last node in the linked list
         */
        last_node = get_kth_node_from_end(1);

        /*
         * If either of 'break_node' or the last node in the linked
         * list is null, return from the function. We cannot perform
         * the linked list rotation.
         */
        if ((break_node == null) || (last_node == null)) {
            return;
        }

        /*
         * Cache the next pointer in the 'break_node'. This will be
         * the new head in the right rotated linked list.
         */
        break_node_next = break_node.next;

        /*
         * Set the next pointer in the 'break_node' to null.
         */
        break_node.next = null;

        /*
         * Point the next of the last node in the linked list to
         * point to the current head. This rotates the linked list
         * by 'k' places
         */
        last_node.next = head;

        /*
         * Set the head of the linked list to 'break_node_next'
         */
        head = break_node_next;
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with the head node being null. The head of the linked
         *         list should remain null after the rotation operation.
         */
        linked_lists_right_rotate_list_by_k_places obj0 =
                    new linked_lists_right_rotate_list_by_k_places();
        int k0 = 2;
        node exp_head0 = null;
        obj0.right_rotate_list_by_k_places(k0);
        assert(true == compare_if_linked_lists_equal(obj0.head, exp_head0));

        /*
         * Test 1: Test with the only one node in linked list. The linked list
         *         shouldn't change after running the rotate operation on the
         *         linked list.
         */
        linked_lists_right_rotate_list_by_k_places obj1 =
                    new linked_lists_right_rotate_list_by_k_places();
        int k1 = 2;
        node exp_head1 = null;
        obj1.head = new node(9);
        exp_head1 = new node(9);
        obj1.right_rotate_list_by_k_places(k1);
        assert(true == compare_if_linked_lists_equal(obj1.head, exp_head1));

        /*
         * Test 2: Test with the only two nodes in linked list. The order of
         *         two nodes should get changed in the linked list after
         *         running the rotate operation on the linked list with 'k'
         *         as one.
         */
        linked_lists_right_rotate_list_by_k_places obj2 =
                    new linked_lists_right_rotate_list_by_k_places();;
        int k2 = 1;
        node exp_head2 = null;
        obj2.head = new node(9);
        obj2.head.next = new node(8);
        exp_head2 = new node(8);
        exp_head2.next = new node(9);
        obj2.right_rotate_list_by_k_places(k2);
        assert(true == compare_if_linked_lists_equal(obj2.head, exp_head2));

        /*
         * Test 3: Test with the 'k' as two. The last two nodes in the
         *         linked list should appear in from of the list after the
         *         rotation operation on the linked list.
         */
        linked_lists_right_rotate_list_by_k_places obj3 =
                    new linked_lists_right_rotate_list_by_k_places();
        int k3 = 2;
        node exp_head3 = null;
        obj3.head = new node(5);
        obj3.head.next = new node(6);
        obj3.head.next.next = new node(7);
        obj3.head.next.next.next = new node(8);
        obj3.head.next.next.next.next = new node(9);
        exp_head3 = new node(8);
        exp_head3.next = new node(9);
        exp_head3.next.next = new node(5);
        exp_head3.next.next.next = new node(6);
        exp_head3.next.next.next.next = new node(7);
        obj3.right_rotate_list_by_k_places(k3);
        assert(true == compare_if_linked_lists_equal(obj3.head, exp_head3));

        /*
         * Test 4: Test with the value of 'k' being equal to the length of the
         *         linked list. After calling the right rotation function,
         *         there should not be any modification to the linked list.
         */
        linked_lists_right_rotate_list_by_k_places obj4 =
                    new linked_lists_right_rotate_list_by_k_places();
        int k4 = 6;
        node exp_head4 = null;
        obj4.head = new node(5);
        obj4.head.next = new node(6);
        obj4.head.next.next = new node(7);
        obj4.head.next.next.next = new node(8);
        obj4.head.next.next.next.next = new node(9);
        obj4.head.next.next.next.next.next = new node(10);
        exp_head4 = new node(5);
        exp_head4.next = new node(6);
        exp_head4.next.next = new node(7);
        exp_head4.next.next.next = new node(8);
        exp_head4.next.next.next.next = new node(9);
        exp_head4.next.next.next.next.next = new node(10);
        obj4.right_rotate_list_by_k_places(k4);
        assert(true == compare_if_linked_lists_equal(obj4.head, exp_head4));

        /*
         * Test 5: Test with the value of 'k' being greater than the length of
         *         linked list. After calling the right rotation function,
         *         there should not be any modification to the linked list.
         */
        linked_lists_right_rotate_list_by_k_places obj5 =
                        new linked_lists_right_rotate_list_by_k_places();
        int k5 = 10;
        node exp_head5 = null;
        obj5.head = new node(5);
        obj5.head.next = new node(6);
        obj5.head.next.next = new node(7);
        obj5.head.next.next.next = new node(8);
        obj5.head.next.next.next.next = new node(9);
        obj5.head.next.next.next.next.next = new node(10);
        exp_head5 = new node(5);
        exp_head5.next = new node(6);
        exp_head5.next.next = new node(7);
        exp_head5.next.next.next = new node(8);
        exp_head5.next.next.next.next = new node(9);
        exp_head5.next.next.next.next.next = new node(10);
        obj5.right_rotate_list_by_k_places(k5);
        assert(true == compare_if_linked_lists_equal(obj5.head, exp_head5));

        /*
         * Test 6: Test with an invalid value of 'k'. After calling the right
         *         rotation function, there should not be any modification to
         *         the linked list.
         */
        linked_lists_right_rotate_list_by_k_places obj6 =
                        new linked_lists_right_rotate_list_by_k_places();
        int k6 = -10;
        node exp_head6 = null;
        obj6.head = new node(5);
        obj6.head.next = new node(6);
        obj6.head.next.next = new node(7);
        obj6.head.next.next.next = new node(8);
        obj6.head.next.next.next.next = new node(9);
        obj6.head.next.next.next.next.next = new node(10);
        exp_head6 = new node(5);
        exp_head6.next = new node(6);
        exp_head6.next.next = new node(7);
        exp_head6.next.next.next = new node(8);
        exp_head6.next.next.next.next = new node(9);
        exp_head6.next.next.next.next.next = new node(10);
        obj6.right_rotate_list_by_k_places(k6);
        assert(true == compare_if_linked_lists_equal(obj6.head, exp_head6));
    }
}
