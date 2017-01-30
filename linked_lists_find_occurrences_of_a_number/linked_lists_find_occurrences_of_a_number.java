/*
 * This function finds the number of times a given number occurs in a
 * linked list of numbers. For more information about this problem, please
 * refer to the following link:-
 * http://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/
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

public class linked_lists_find_occurrences_of_a_number
{
    /*
     * This function returns the number of occurrences of a given number in
     * a linked list. If the number doesn't exist within the linked list, then
     * this function returns zero. The time complexity of this function is
     * O(n), where 'n' is the number of elements in the linked list. The space
     * complexity of this function is O(1).
     */
    public static int
            get_num_occurrences_in_linked_list (node head, int num)
    {
        node current;
        int count;

        /*
         * If the head of the linked list is null, then return zero
         */
        if (head == null) {
            return(0);
        }

        current = head;
        count = 0;

        /*
         * Iterate over the elements in the linked list
         */
        while (current != null) {

            /*
             * Check if the node's data value matches with
             * 'num'. If so, increment 'count'.
             */
            if (current.data == num) {
                ++count;
            }

            current = current.next;
        }

        /*
         * Return the number of occurrences of 'num'
         */
        return(count);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Head of the list points to null. Searching a number
         *         in an empty list should return zero.
         */
        node head0 = null;
        assert(0 == get_num_occurrences_in_linked_list(head0, 0));

        /*
         * Test 1: There is only one node in the list. Searching a
         *         number is this list should return one.
         */
        node head1 = null;
        head1 = new node(1);
        assert(1 == get_num_occurrences_in_linked_list(head1, 1));

        /*
         * Test 2: Test a case with multiple nodes in the list. Test two
         *         cases:-
         *         a. Case when a number exists in the list. The function
         *            should return the number of times that number occurs in
         *            the list.
         *         b. Case when a number does not exists in the list. The
         *            in this case should return zero.
         */
        node head2 = null;
        head2 = new node(0);
        head2.next = new node(1);
        head2.next.next = new node(2);
        head2.next.next.next = new node(1);
        head2.next.next.next.next = new node(3);
        head2.next.next.next.next.next = new node(1);
        head2.next.next.next.next.next.next = new node(3);
        head2.next.next.next.next.next.next.next = new node(1);
        head2.next.next.next.next.next.next.next.next = new node(4);
        head2.next.next.next.next.next.next.next.next.next = new node(2);
        head2.next.next.next.next.next.next.next.next.next.next = new node(1);
        assert(5 == get_num_occurrences_in_linked_list(head2, 1));
        assert(0 == get_num_occurrences_in_linked_list(head2, 10));
    }
}
