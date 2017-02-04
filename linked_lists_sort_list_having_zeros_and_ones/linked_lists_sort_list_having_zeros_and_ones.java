/*
 * This program sorts a linked list haing zeros and ones. For example:-
 * List : 0.1.0.1.0.1.0.//
 * Sorted list: 0.0.0.0.1.1.1.//
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

public class linked_lists_sort_list_having_zeros_and_ones
{
    node head;

    linked_lists_sort_list_having_zeros_and_ones ()
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
     * This function sorts a linked list containing zeros and ones
     * in-place. The time complexity of this function is O(n), where
     * 'n' is the number of elements in the linked list. The space
     * complexity of this function is O(1).
     */
    public void sort_list_zeros_and_ones ()
    {
        node new_head;
        node new_tail;
        node temp;
        node current;

        /*
         * If the list is empty or the address of the head of the
         * list is null, then return from the function
         */
        if (head == null) {
            return;
        }

        /*
         * Get the reference of the head of the list
         */
        current = head;
        new_head = null;
        new_tail = null;

        /*
         * Iterate until we reach to the end of the list
         */
        while (current != null) {

            /*
             * Point 'temp' to 'current' and advance 'current'
             * down the list
             */
            temp = current;
            current = current.next;
            temp.next = null;

            if (temp.data == 0) {

                /*
                 * If the data in the node is zero, then add the node
                 * to the front of the new list
                 */
                if (new_head == null) {

                    /*
                     * If the new list is empty, then set the head and tail
                     * to the node
                     */
                    new_head = new_tail = temp;
                } else {

                    /*
                     * Add the node to the head of the new list
                     */
                    temp.next = new_head;
                    new_head = temp;
                }
            } else {

                /*
                 * If the data in the node is one, then add the node
                 * to the to the end of the new list
                 */
                if (new_head == null) {

                    /*
                     * If the new list is empty, then set the head and tail
                     * to the node
                     */
                    new_head = new_tail = temp;
                } else {

                    /*
                     * Add the node to the tail of the new list
                     */
                    new_tail.next = temp;
                    new_tail = temp;
                }
            }
        }

        /*
         * Set the original head to the head of the new list
         */
        head = new_head;
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Sort an empty linked list. The linked list should
         *         remain empty after sorting as well.
         */
        linked_lists_sort_list_having_zeros_and_ones obj0 =
                    new linked_lists_sort_list_having_zeros_and_ones();
        node exp_head0 = null;
        obj0.sort_list_zeros_and_ones();
        assert(true == compare_if_linked_lists_equal(obj0.head, exp_head0));

        /*
         * Test 1: Sort a linked list having only one element which
         *         is zero. The linked list should not change after
         *         sorting.
         */
        linked_lists_sort_list_having_zeros_and_ones obj1 =
                    new linked_lists_sort_list_having_zeros_and_ones();
        node exp_head1 = null;
        obj1.head = new node(0);
        exp_head1 = new node(0);
        obj1.sort_list_zeros_and_ones();
        assert(true == compare_if_linked_lists_equal(obj1.head, exp_head1));

        /*
         * Test 2: Sort a linked list having only one element which
         *         is one. The linked list should not change after
         *         sorting.
         */
        linked_lists_sort_list_having_zeros_and_ones obj2 =
                    new linked_lists_sort_list_having_zeros_and_ones();
        node exp_head2 = null;
        obj2.head = new node(1);
        exp_head2 = new node(1);
        obj2.sort_list_zeros_and_ones();
        assert(true == compare_if_linked_lists_equal(obj2.head, exp_head2));

        /*
         * Test 3: Sort a linked list having mix of zeros and ones.
         *         The linked list after sorting should have zeros
         *         followed by ones.
         */
        linked_lists_sort_list_having_zeros_and_ones obj3 =
                    new linked_lists_sort_list_having_zeros_and_ones();
        node exp_head3 = null;
        obj3.head = new node(1);
        obj3.head.next = new node(0);
        obj3.head.next.next = new node(1);
        obj3.head.next.next.next = new node(1);
        obj3.head.next.next.next.next = new node(0);
        obj3.head.next.next.next.next.next = new node(1);
        exp_head3 = new node(0);
        exp_head3.next = new node(0);
        exp_head3.next.next = new node(1);
        exp_head3.next.next.next = new node(1);
        exp_head3.next.next.next.next = new node(1);
        exp_head3.next.next.next.next.next = new node(1);
        obj3.sort_list_zeros_and_ones();
        assert(true == compare_if_linked_lists_equal(obj3.head, exp_head3));

        /*
         * Test 4: Sort a linked list having mix of zeros and ones.
         *         The linked list after sorting should have zeros
         *         followed by ones.
         */
        linked_lists_sort_list_having_zeros_and_ones obj4 =
                    new linked_lists_sort_list_having_zeros_and_ones();
        node exp_head4 = null;
        obj4.head = new node(1);
        obj4.head.next = new node(0);
        obj4.head.next.next = new node(0);
        obj4.head.next.next.next = new node(1);
        obj4.head.next.next.next.next = new node(0);
        obj4.head.next.next.next.next.next = new node(1);
        exp_head4 = new node(0);
        exp_head4.next = new node(0);
        exp_head4.next.next = new node(0);
        exp_head4.next.next.next = new node(1);
        exp_head4.next.next.next.next = new node(1);
        exp_head4.next.next.next.next.next = new node(1);
        obj4.sort_list_zeros_and_ones();
        assert(true == compare_if_linked_lists_equal(obj4.head, exp_head4));

        /*
         * Test 5: Sort a linked list having only elements which are
         *         all ones. The linked list should not change after
         *         sorting.
         */
        linked_lists_sort_list_having_zeros_and_ones obj5 =
                    new linked_lists_sort_list_having_zeros_and_ones();
        node exp_head5 = null;
        obj5.head = new node(1);
        obj5.head.next = new node(1);
        obj5.head.next.next = new node(1);
        obj5.head.next.next.next = new node(1);
        obj5.head.next.next.next.next = new node(1);
        obj5.head.next.next.next.next.next = new node(1);
        exp_head5 = new node(1);
        exp_head5.next = new node(1);
        exp_head5.next.next = new node(1);
        exp_head5.next.next.next = new node(1);
        exp_head5.next.next.next.next = new node(1);
        exp_head5.next.next.next.next.next = new node(1);
        obj5.sort_list_zeros_and_ones();
        assert(true == compare_if_linked_lists_equal(obj5.head, exp_head5));

        /*
         * Test 6: Sort a linked list having only elements which are
         *         all zeros. The linked list should not change after
         *         sorting.
         */
        linked_lists_sort_list_having_zeros_and_ones obj6 =
                    new linked_lists_sort_list_having_zeros_and_ones();
        node exp_head6 = null;
        obj6.head = new node(0);
        obj6.head.next = new node(0);
        obj6.head.next.next = new node(0);
        obj6.head.next.next.next = new node(0);
        obj6.head.next.next.next.next = new node(0);
        obj6.head.next.next.next.next.next = new node(0);
        exp_head6 = new node(0);
        exp_head6.next = new node(0);
        exp_head6.next.next = new node(0);
        exp_head6.next.next.next = new node(0);
        exp_head6.next.next.next.next = new node(0);
        exp_head6.next.next.next.next.next = new node(0);
        obj6.sort_list_zeros_and_ones();
        assert(true == compare_if_linked_lists_equal(obj6.head, exp_head6));
    }
}
