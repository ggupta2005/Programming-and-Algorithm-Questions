/*
 * This program inserts an element into a sorted linked list.
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

public class linked_lists_insert_into_sorted_list
{
    node head;

    linked_lists_insert_into_sorted_list ()
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
     * This function adds an element into a sorted linked list. The time
     * complexity of this function is O(n), where 'n' is the number of
     * elements in the linked list. The space complexity of this function
     * is O(1).
     */
    public void insert_into_sorted_list (int num)
    {
        node current, prev, temp;

        /*
         * Create a node to be inserted into the linked list
         */
        temp = new node(num);


        if (temp == null) {
            return;
        }

        /*
         * If the head of the linked list is null, so point the
         * head to the new node and return
         */
        if (head == null) {
            head = temp;
            return;
        }

        /*
         * Iterate into the sorted to find the location in the
         * linked list where the node could be inserted
         */
        current = head;
        prev = null;
        while (current != null) {

            if (temp.data < current.data) {
                break;
            }

            /*
             * Keep track of the previous pointer to keep track
             * of the position where the new element needs to
             * inserted
             */
            prev = current;
            current = current.next;
        }

        if (prev != null) {

            /*
             * If previous pointer is valid, then insert the
             * new element next to the previous pointer
             */
            temp.next = prev.next;
            prev.next = temp;
        } else {

            /*
             * Otherwise, insert the element in front of the
             * linked list
             */
            temp.next = head;
            head =temp;
        }
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Insert into an empty lined list.
         */
        linked_lists_insert_into_sorted_list obj0 =
                        new linked_lists_insert_into_sorted_list();
        node exp_head0 = new node(10);
        obj0.insert_into_sorted_list(10);
        assert(true == compare_if_linked_lists_equal(obj0.head, exp_head0));

        /*
         * Test 1: Insert into a sorted list such that the new node gets
         *         inserted to the head of the linked list.
         */
        linked_lists_insert_into_sorted_list obj1 =
                        new linked_lists_insert_into_sorted_list();
        node exp_head1 = null;
        obj1.head = new node(10);
        obj1.head.next = new node(100);
        obj1.head.next.next = new node(1000);
        obj1.head.next.next.next = new node(1000);
        obj1.head.next.next.next.next = new node(10000);
        exp_head1 = new node(1);
        exp_head1.next = new node(10);
        exp_head1.next.next = new node(100);
        exp_head1.next.next.next = new node(1000);
        exp_head1.next.next.next.next = new node(1000);
        exp_head1.next.next.next.next.next = new node(10000);
        obj1.insert_into_sorted_list(1);
        assert(true == compare_if_linked_lists_equal(obj1.head, exp_head1));

        /*
         * Test 2: Insert into a sorted list such that the new node gets
         *         inserted into the middle of the linked list.
         */
        linked_lists_insert_into_sorted_list obj2 =
                        new linked_lists_insert_into_sorted_list();
        node exp_head2 = null;
        obj2.head = new node(2);
        obj2.head.next = new node(20);
        obj2.head.next.next = new node(2000);
        obj2.head.next.next.next = new node(2000);
        obj2.head.next.next.next.next = new node(20000);
        exp_head2 = new node(2);
        exp_head2.next = new node(20);
        exp_head2.next.next = new node(200);
        exp_head2.next.next.next = new node(2000);
        exp_head2.next.next.next.next = new node(2000);
        exp_head2.next.next.next.next.next = new node(20000);
        obj2.insert_into_sorted_list(200);
        assert(true == compare_if_linked_lists_equal(obj2.head, exp_head2));

        /*
         * Test 3: Insert into a sorted list such that the new node gets
         *         inserted into the linked list which already has that value.
         */
        linked_lists_insert_into_sorted_list obj3 =
                        new linked_lists_insert_into_sorted_list();
        node exp_head3 = null;
        obj3.head = new node(3);
        obj3.head.next = new node(30);
        obj3.head.next.next = new node(300);
        obj3.head.next.next.next = new node(3000);
        obj3.head.next.next.next.next = new node(30000);
        exp_head3 = new node(3);
        exp_head3.next = new node(30);
        exp_head3.next.next = new node(300);
        exp_head3.next.next.next = new node(3000);
        exp_head3.next.next.next.next = new node(3000);
        exp_head3.next.next.next.next.next = new node(30000);
        obj3.insert_into_sorted_list(3000);
        assert(true == compare_if_linked_lists_equal(obj3.head, exp_head3));

        /*
         * Test 4: Insert into a sorted list such that the new node gets
         *         inserted to the end of the linked list.
         */
        linked_lists_insert_into_sorted_list obj4 =
                        new linked_lists_insert_into_sorted_list();
        node exp_head4 = null;
        obj4.head = new node(4);
        obj4.head.next = new node(40);
        obj4.head.next.next = new node(400);
        obj4.head.next.next.next = new node(4000);
        obj4.head.next.next.next.next = new node(4000);
        obj4.head.next.next.next.next.next = new node(40000);
        exp_head4 = new node(4);
        exp_head4.next = new node(40);
        exp_head4.next.next = new node(400);
        exp_head4.next.next.next = new node(4000);
        exp_head4.next.next.next.next = new node(4000);
        exp_head4.next.next.next.next.next = new node(40000);
        exp_head4.next.next.next.next.next.next = new node(400000);
        obj4.insert_into_sorted_list(400000);
        assert(true == compare_if_linked_lists_equal(obj4.head, exp_head4));
    }
}
