/*
 * This program swaps nodes in pairs in a linked list. For example if the
 * linked list is 1.2.3.4.5.6, then after the pairwise swap of the nodes
 * the linked list will look like:- 2.1.4.3.6.5. This swap operation
 * should be done in place and the values of the nodes should not be swapped.
 * For more information on the problem, please visit the post:-
 * https://leetcode.com/problems/swap-nodes-in-pairs/
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

public class linked_lists_swap_node_in_pairs
{
    node head;

    linked_lists_swap_node_in_pairs ()
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
     * This function takes a pointer reference to the head of a linked list
     * and swaps the consecutive elements in the list.
     */
    public void swap_linked_list_nodes_pairwise ()
    {
        node current;
        node first;
        node second;
        node prev;

        /*
         * If the reference to the head node is null or the head of the
         * linked list it self null, then return from this function.
         */
        if (head == null) {
            return;
        }

        /*
         * If there is only one node present in the linked list, then we
         * need not perform any pairwise swaps in the linked list. Return
         * from the function
         */
        if (head.next == null) {
            return;
        }

        /*
         * Point 'current' to the head of the linked list
         */
        current = head;

        /*
         * Point the head of the list to null
         */
        head = null;

        /*
         * Point the tracking pointer 'prev' to null
         */
        prev = null;

        /*
         * Iterate until the 'current' is not null or the pointer to the
         * next node is not null
         */
        while ((current != null) && (current.next != null)) {

            /*
             * Let 'first' point to the current node
             */
            first = current;

            /*
             * Let 'second' point to the next node to the 'current' node
             */
            second = current.next;

            /*
             * Point 'current' to the next node to the 'second' node
             */
            current = current.next.next;

            /*
             * Swap the positions of the 'first' and 'second' nodes
             */
            first.next = current;
            second.next = first;

            /*
             * If 'prev' is not null, then point the next pointer in 'prev'
             * to the 'second' node and move 'prev' ahead by two nodes
             */
            if (prev != null) {
                prev.next = second;
                prev = prev.next.next;
            } else {

                /*
                 * If 'prev' is null, then point the 'prev' to the 'second'
                 * node and move 'prev' ahead by one nodes
                 */

                prev = second;
                prev = prev.next;
            }

            /*
             * If the head of the linked list is null, then point the head
             * of the linked list to the 'second' node
             */
            if (head == null) {
                head = second;
            }
        }
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with the head node being null. The head of the linked
         *         list should remain null.
         */
        linked_lists_swap_node_in_pairs obj0 =
                            new linked_lists_swap_node_in_pairs();
        node exp_head0 = null;
        obj0.swap_linked_list_nodes_pairwise();
        assert(true == compare_if_linked_lists_equal(obj0.head, exp_head0));

        /*
         * Test 1: Test with the only one node in linked list. The linked list
         *         shouldn't change after running the swap operation on the
         *         linked list.
         */
        linked_lists_swap_node_in_pairs obj1 =
                            new linked_lists_swap_node_in_pairs();
        node exp_head1 = null;
        obj1.head = new node(9);
        exp_head1 = new node(9);
        obj1.swap_linked_list_nodes_pairwise();
        assert(true == compare_if_linked_lists_equal(obj1.head, exp_head1));

        /*
         * Test 2: Test with the only two nodes in linked list. The order of
         *         two nodes should get changed in the linked list after
         *         running the swap operation on the linked list.
         */
        linked_lists_swap_node_in_pairs obj2 =
                            new linked_lists_swap_node_in_pairs();
        node exp_head2 = null;
        obj2.head = new node(8);
        obj2.head.next = new node(9);
        exp_head2 = new node(9);
        exp_head2.next = new node(8);
        obj2.swap_linked_list_nodes_pairwise();
        assert(true == compare_if_linked_lists_equal(obj2.head, exp_head2));

        /*
         * Test 3: Test with the odd number of elements in linked list.
         *         The order of nodes should get changed in the linked list
         *         after running the swap operation on the linked list.
         */
        linked_lists_swap_node_in_pairs obj3 =
                            new linked_lists_swap_node_in_pairs();
        node exp_head3 = null;
        obj3.head = new node(5);
        obj3.head.next = new node(6);
        obj3.head.next.next = new node(7);
        obj3.head.next.next.next = new node(8);
        obj3.head.next.next.next.next = new node(9);
        exp_head3 = new node(6);
        exp_head3.next = new node(5);
        exp_head3.next.next = new node(8);
        exp_head3.next.next.next = new node(7);
        exp_head3.next.next.next.next = new node(9);
        obj3.swap_linked_list_nodes_pairwise();
        assert(true == compare_if_linked_lists_equal(obj3.head, exp_head3));

        /*
         * Test 4: Test with the even number of elements in linked list.
         *         The order of nodes should get changed in the linked list
         *         after running the swap operation on the linked list.
         */
        linked_lists_swap_node_in_pairs obj4 =
                            new linked_lists_swap_node_in_pairs();
        node exp_head4 = null;
        obj4.head = new node(5);
        obj4.head.next = new node(6);
        obj4.head.next.next = new node(7);
        obj4.head.next.next.next = new node(8);
        obj4.head.next.next.next.next = new node(9);
        obj4.head.next.next.next.next.next = new node(10);
        exp_head4 = new node(6);
        exp_head4.next = new node(5);
        exp_head4.next.next = new node(8);
        exp_head4.next.next.next = new node(7);
        exp_head4.next.next.next.next = new node(10);
        exp_head4.next.next.next.next.next = new node(9);
        obj4.swap_linked_list_nodes_pairwise();
        assert(true == compare_if_linked_lists_equal(obj4.head, exp_head4));
    }
}
