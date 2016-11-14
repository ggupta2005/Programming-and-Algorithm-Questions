/*
 * This program deletes all nodes from the linked lists having a given value.
 * For Example
 * Given list: 1 -. 2 -. 6 -. 3 -. 4 -. 5 -. 6, val = 6
 * After deletion list: 1 -. 2 -. 3 -. 4 -. 5
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

public class linked_lists_delete_nodes_with_given_value
{
    node head;

    linked_lists_delete_nodes_with_given_value ()
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
     * This function deletes all nodes having a given value from the linked
     * list. The time complexity of this function is O(n), where 'n' is the
     * number of elements in the linked list. The space complexity of this
     * function is O(1).
     */
    public void delete_nodes_having_value_from_linked_list (int val)
    {
        node current;
        node prev;
        node temp;
        node new_head;

        /*
         * If the pointer to the head of the linked list is null or
         * if the head of the linked list is null, then return null
         * from this function.
         */
        if (head == null) {
            return;
        }

        /*
         * Iterate from the beginning of the list and remove all
         * elements whose value is same as 'val'
         */
        current = head;
        while ((current != null) && (current.data == val)) {

            /*
             * Point 'temp' to 'current'
             */
            temp = current;

            /*
             * Move 'current' to the next element
             */
            current = current.next;
        }

        /*
         * If 'current' is null, then all elements in the linked
         * list have been deleted. Set 'head' to null and return.
         */
        if (current == null) {
            head = null;
            return;
        }

        /*
         * Set 'new_head' to current
         */
        new_head = current;
        prev = null;

        /*
         * Iterate until the next pointer in 'current' becomes
         * null
         */
        while ((current != null) && (current.next != null)) {

            /*
             * Set 'prev' to 'cuurent'
             */
            prev = current;

            /*
             * If the match for 'val' is found in 'current.next',
             * then delete this node.
             */
            if (current.next.data == val) {

                /*
                 * Point 'temp' to 'current.next'
                 */
                temp = current.next;

                /*
                 * Move 'current' to the next next element
                 */
                current = current.next.next;

                /*
                 * Join 'prev' ad the 'current' nodes
                 */
                prev.next = current;
            } else {

                /*
                 * Otherwise, move current to the next element
                 */
                current = current.next;
            }
        }

        /*
         * Point the list head to the 'new_head' pointer
         */
        head = new_head;
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test when the linked list is null or empty. The
         *         linked list should remain empty.
         */
        linked_lists_delete_nodes_with_given_value obj0 =
                    new linked_lists_delete_nodes_with_given_value();
        int val0 = 1;
        node exp_head0 = null;
        obj0.delete_nodes_having_value_from_linked_list(val0);
        assert(true == compare_if_linked_lists_equal(obj0.head, exp_head0));

        /*
         * Test 1: Test when the linked list is non-empty and we try to
         *         delete a non-existent value. The linked list should
         *         remain unchanged.
         */
        linked_lists_delete_nodes_with_given_value obj1 =
                    new linked_lists_delete_nodes_with_given_value();
        int val1 = 1;
        node exp_head1 = null;
        obj1.head = new node(7);
        obj1.head.next = new node(8);
        obj1.head.next.next = new node(9);
        obj1.head.next.next.next = new node(7);
        obj1.head.next.next.next.next = new node(8);
        obj1.head.next.next.next.next.next = new node(9);
        exp_head1 = new node(7);
        exp_head1.next = new node(8);
        exp_head1.next.next = new node(9);
        exp_head1.next.next.next = new node(7);
        exp_head1.next.next.next.next = new node(8);
        exp_head1.next.next.next.next.next = new node(9);
        obj1.delete_nodes_having_value_from_linked_list(val1);
        assert(true == compare_if_linked_lists_equal(obj1.head, exp_head1));

        /*
         * Test 2: Test when the linked list is non-empty and we try to
         *         delete a value which is present in all the nodes of the
         *         linked list. The linked list should be null after the
         *         delete operation.
         */
        linked_lists_delete_nodes_with_given_value obj2 =
                    new linked_lists_delete_nodes_with_given_value();
        int val2 = 6;
        node exp_head2 = null;
        obj2.head = new node(6);
        obj2.head.next = new node(6);
        obj2.head.next.next = new node(6);
        obj2.head.next.next.next = new node(6);
        obj2.head.next.next.next.next = new node(6);
        obj2.head.next.next.next.next.next = new node(6);
        obj2.delete_nodes_having_value_from_linked_list(val2);
        assert(true == compare_if_linked_lists_equal(obj2.head, exp_head2));

        /*
         * Test 3: Test when the linked list is non-empty and we try to
         *         delete a value which occurs alternately in the linked
         *         list starting from the first node. The linked list
         *         not have the nodes having that value.
         */
        linked_lists_delete_nodes_with_given_value obj3 =
                    new linked_lists_delete_nodes_with_given_value();
        int val3 = 9;
        node exp_head3 = null;
        obj3.head = new node(9);
        obj3.head.next = new node(7);
        obj3.head.next.next = new node(9);
        obj3.head.next.next.next = new node(7);
        obj3.head.next.next.next.next = new node(9);
        obj3.head.next.next.next.next.next = new node(7);
        exp_head3 = new node(7);
        exp_head3.next = new node(7);
        exp_head3.next.next = new node(7);
        obj3.delete_nodes_having_value_from_linked_list(val3);
        assert(true == compare_if_linked_lists_equal(obj3.head, exp_head3));

        /*
         * Test 4: Test when the linked list is non-empty and we try to
         *         delete a value which occurs alternately in the linked
         *         list starting from the second node. The linked list
         *         not have the nodes having that value.
         */
        linked_lists_delete_nodes_with_given_value obj4 =
                    new linked_lists_delete_nodes_with_given_value();
        int val4 = 9;
        node exp_head4 = null;
        obj4.head = new node(9);
        obj4.head.next = new node(7);
        obj4.head.next.next = new node(9);
        obj4.head.next.next.next = new node(8);
        obj4.head.next.next.next.next = new node(9);
        obj4.head.next.next.next.next.next = new node(8);
        exp_head4 = new node(7);
        exp_head4.next = new node(8);
        exp_head4.next.next = new node(8);
        obj4.delete_nodes_having_value_from_linked_list(val4);
        assert(true == compare_if_linked_lists_equal(obj4.head, exp_head4));
    }
}
