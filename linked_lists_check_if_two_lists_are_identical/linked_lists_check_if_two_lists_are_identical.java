/*
 * This program checks if two linked lists are identical. Two linked lists
 * are said to be identical if there are lengths are same and also if the
 * contents of the two linked lists are same in the same relative order.
 * For information on this problem, please visit the following post:
 * http://www.geeksforgeeks.org/identical-linked-lists/
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

public class linked_lists_check_if_two_lists_are_identical
{
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

    public static void main (String[] args)
    {
        /*
         * Test 0: Both the linked lists point to null. These two
         *         lists should be identical.
         */
        node head01 = null;
        node head02 = null;
        assert(true == compare_if_linked_lists_equal(head01, head02));

        /*
         * Test 1: First of the linked lists point to null. The other list
         *         not null. These two lists should not be identical.
         */
        node head11 = null;
        node head12 = null;
        head12 = new node(9);
        assert(false == compare_if_linked_lists_equal(head11, head12));

        /*
         * Test 2: Second of the linked lists point to null. The other list
         *         not null. These two lists should not be identical.
         */
        node head21 = null;
        node head22 = null;
        head21 = new node(9);
        assert(false == compare_if_linked_lists_equal(head21, head22));

        /*
         * Test 3: Test a case when the lists are identical with the same
         *         number of elements and same ordering of elements.
         */
        node head31 = null;
        node head32 = null;
        head31 = new node(9);
        head31.next = new node(8);
        head31.next.next = new node(7);
        head32 = new node(9);
        head32.next = new node(8);
        head32.next.next = new node(7);
        assert(true == compare_if_linked_lists_equal(head31, head32));

        /*
         * Test 4: Test a case when the lists are not identical with the same
         *         number of elements but different ordering of elements.
         */
        node head41 = null;
        node head42 = null;
        head41 = new node(9);
        head41.next = new node(8);
        head41.next.next = new node(7);
        head42 = new node(9);
        head42.next = new node(7);
        head42.next.next = new node(8);
        assert(false == compare_if_linked_lists_equal(head41, head42));

        /*
         * Test 5: Test a case when the lists are not identical with
         *         different number of elements.
         */
        node head51 = null;
        node head52 = null;
        head51 = new node(9);
        head51.next = new node(8);
        head51.next.next = new node(7);
        head52 = new node(9);
        head52.next = new node(8);
        assert(false == compare_if_linked_lists_equal(head51, head52));
    }
}
