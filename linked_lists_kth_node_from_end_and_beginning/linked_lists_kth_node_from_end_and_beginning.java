/*
 * This program finds the kth node from end and kth node from
 * beginning in a linear linked list. For more information on
 * this, please refer to the following post:-
 * http://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
 */
import java.io.*;
import java.util.*;

/*
 * Class definition for the node in the linked list
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

public class linked_lists_kth_node_from_end_and_beginning
{
    /*
     * This function returns pointer to the kth node from the beginning
     * of a linear linked list. If the value of 'k' is less than or equal
     * to 0 or if 'k' is greater than the number of elements in the linked
     * list, then this function returns null. The time complexity of this
     * function is O(n), where 'n' is the number of elements in the linked
     * list.
     */
    public static node get_kth_node_from_beginning (node head, int k)
    {
        int i;
        node current;

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
         * Return the pointer to the kth element from beginning
         */
        return(current);
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
    public static node get_kth_node_from_end (node head, int k)
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

    public static void main (String[] args)
    {
        /*
         * Test 0: Test with head pointer being null. The kth element
         *         from beginning and end should point to null.
         */
        node head0 = null;
        int k0 = 10;
        assert(null == get_kth_node_from_beginning(head0, k0));
        assert(null == get_kth_node_from_end(head0, k0));

        /*
         * Test 1: Test with 'k' being illegal. The kth element from
         *         beginning and end should point to null.
         */
        node head1 = null;
        int k1 = -10;
        head1 = new node(1);
        assert(null == get_kth_node_from_beginning(head1, k1));
        assert(null == get_kth_node_from_end(head1, k1));

        /*
         * Test 2: Test with 'k' being greater than the total number of
         *         elements in the linked list. The kth element from
         *         beginning and end should point to null.
         */
        node head2 = null;
        int k2 = 2;
        head2 = new node(2);
        assert(null == get_kth_node_from_beginning(head2, k2));
        assert(null == get_kth_node_from_end(head2, k2));

        /*
         * Test 3: Test with 'k' being equal to the total number of
         *         elements in the linked list. The kth element from
         *         beginning should be the last element in the list
         *         and kth element from end should be the first
         *         element in the linked list.
         */
        node head3 = null;
        int k3 = 2;
        node expected_beg3 = null;
        node expected_end3 = null;
        head3 = new node(2);
        head3.next = new node(1);
        expected_beg3 = get_kth_node_from_beginning(head3, k3);
        expected_end3 = get_kth_node_from_end(head3, k3);
        assert(expected_beg3 != null && expected_beg3.data == 1);
        assert(expected_end3 != null && expected_end3.data == 2);

        /*
         * Test 4: Test with 'k' being equal to half of number of
         *         elements in the linked list. The kth element from
         *         beginning and end should be the middle element in
         *         the list.
         */
        node head4 = null;
        int k4 = 3;
        node expected_beg4 = null;
        node expected_end4 = null;
        head4 = new node(5);
        head4.next = new node(4);
        head4.next.next = new node(3);
        head4.next.next.next = new node(2);
        head4.next.next.next.next = new node(1);
        expected_beg4 = get_kth_node_from_beginning(head4, k4);
        expected_end4 = get_kth_node_from_end(head4, k4);
        assert(expected_beg4 != null && expected_beg4.data == 3);
    }
}
