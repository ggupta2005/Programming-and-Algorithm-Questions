/*
 * This program adds two numbers represented as linked lists. The head
 * of the linked lists point to the units place digit in the linked list.
 * For more information on this problem, please refer to the following
 * link:-
 *
 * http://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
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

public class add_two_numbers_as_linked_lists_with_head_as_lsb
{
    node head, tail;

    add_two_numbers_as_linked_lists_with_head_as_lsb ()
    {
        head = tail = null;
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
     * This function create a new node and appends it the end of the
     * linked list at the tail pointer. The time and space complexity of
     * this function is O(1).
     */
    void insert_at_end_with_tail_ptr (int value)
    {
        node new_node;
        node current;

        new_node = new node(value);

        if (new_node == null) {
            return;
        }

        if (head == null) {
            head = new_node;
            tail = new_node;
        } else {
            tail.next = new_node;
            tail = tail.next;
        }
    }

    /*
     * This function adds two numbers represented by linked lists and returns
     * the sum as a linked list. The time complexity of this function is O(m + n),
     * where, 'm' and 'n' are lengths of the two linked list numbers.
     */
    public void add_two_linked_lists_as_numbers (node num1, node num2)
    {
        node new_node;
        node current1;
        node current2;
        int carry;
        int rem;

        /*
         * If both the linked lists are empty, then return null.
         */
        if (num1 == null && num2 == null) {
            return;
        }

        current1 = num1;
        current2 = num2;
        carry = 0;

        /*
         * Iterate until we reach to the end of either linked lists
         */
        while (current1 != null && current2 != null) {

            /*
             * Calculate the carry and remainder of the sum of linked list
             * nodes
             */
            rem = (current1.data + current2.data + carry) % 10;
            carry = (current1.data + current2.data + carry) / 10;

            /*
             * Insert the remainder towards the end of the new linked list
             */
            insert_at_end_with_tail_ptr(rem);

            /*
             * Move down either of the two linked lists
             */
            current1 = current1.next;
            current2 = current2.next;
        }

        /*
         * Iterate until we reach to the end of the first linked lists
         */
        while (current1 != null) {

            /*
             * Calculate the carry and remainder of the sum of linked list
             * nodes
             */
            rem = (current1.data + carry) % 10;
            carry = (current1.data + carry) / 10;

            /*
             * Insert the remainder towards the end of the new linked list
             */
            insert_at_end_with_tail_ptr(rem);

            /*
             * Move down the first linked lists
             */
            current1 = current1.next;
        }

        /*
         * Iterate until we reach to the end of the second linked lists
         */
        while (current2 != null) {

            /*
             * Calculate the carry and remainder of the sum of linked list
             * nodes
             */
            rem = (current2.data + carry) % 10;
            carry = (current2.data + carry) / 10;

            /*
             * Insert the remainder towards the end of the new linked list
             */
            insert_at_end_with_tail_ptr(rem);

            /*
             * Move down the second linked lists
             */
            current2 = current2.next;
        }

        /*
         * If carry is greater than zero, insert carry at the end of the
         * new linked list
         */
        if (carry > 0) {
            insert_at_end_with_tail_ptr(carry);
        }
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test when both linked lists are empty. The sum linked list
         *         should also be empty.
         */
        node num11 = null;
        node num12 = null;
        node exp_add1 = null;
        add_two_numbers_as_linked_lists_with_head_as_lsb obj1 =
                        new add_two_numbers_as_linked_lists_with_head_as_lsb();
        obj1.add_two_linked_lists_as_numbers(num11, num12);
        assert(compare_if_linked_lists_equal(exp_add1, obj1.head));

        /*
         * Test 3: Test with one linked list being empty. The sum linked
         *         list should be same as the first linked list.
         */
        node num31 = null;
        node num32 = null;
        node exp_add3 = null;
        num31 = new node(2);
        num31.next = new node(3);
        num31.next.next = new node(3);
        exp_add3 = new node(2);
        exp_add3.next = new node(3);
        exp_add3.next.next = new node(3);
        add_two_numbers_as_linked_lists_with_head_as_lsb obj3 =
                        new add_two_numbers_as_linked_lists_with_head_as_lsb();
        obj3.add_two_linked_lists_as_numbers(num31, num32);
        assert(compare_if_linked_lists_equal(exp_add3, obj3.head));

        /*
         * Test 4: Test with two linked lists, whose sum will not result
         *         in additional digit in the sum linked list.
         */
        node num41 = null;
        node num42 = null;
        node exp_add4 = null;
        num41 = new node(2);
        num41.next = new node(4);
        num41.next.next = new node(3);
        num42 = new node(5);
        num42.next = new node(6);
        num42.next.next = new node(4);
        exp_add4 = new node(7);
        exp_add4.next = new node(0);
        exp_add4.next.next = new node(8);
        add_two_numbers_as_linked_lists_with_head_as_lsb obj4 =
                        new add_two_numbers_as_linked_lists_with_head_as_lsb();
        obj4.add_two_linked_lists_as_numbers(num41, num42);
        assert(compare_if_linked_lists_equal(exp_add4, obj4.head));

        /*
         * Test 5: Test with two linked lists, whose sum will result
         *         in additional digit in the sum linked list.
         */
        node num51 = null;
        node num52 = null;
        node exp_add5 = null;
        num51 = new node(9);
        num51.next = new node(9);
        num51.next.next = new node(9);
        num51.next.next.next = new node(9);
        num51.next.next.next.next = new node(9);
        num52 = new node(1);
        exp_add5 = new node(0);
        exp_add5.next = new node(0);
        exp_add5.next.next = new node(0);
        exp_add5.next.next.next = new node(0);
        exp_add5.next.next.next.next = new node(0);
        exp_add5.next.next.next.next.next = new node(1);
        add_two_numbers_as_linked_lists_with_head_as_lsb obj5 =
                        new add_two_numbers_as_linked_lists_with_head_as_lsb();
        obj5.add_two_linked_lists_as_numbers(num51, num52);
        assert(compare_if_linked_lists_equal(exp_add5, obj5.head));
    }
}
