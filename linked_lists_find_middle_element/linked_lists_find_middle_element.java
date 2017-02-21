/*
 * Given a singly linked list, find middle of the linked list. For example,
 * if given linked list is 1.2.3.4.5 then output should be 3. If there are
 * even nodes, then there would be two middle nodes, we need to find the second
 * middle element. For example, if given linked list is 1.2.3.4.5.6 then
 * output should be 4.
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

public class linked_lists_find_middle_element
{
    /*
     * This function returns the middle element in a linear linked list.
     * The time complexity of this function is O(n), where 'n' is the number
     * of elements in the linked list. The space complexity of this function
     * is O(1).
     */
    public static node find_linked_list_middle_element (node head)
    {
        node fast;
        node slow;

        /*
         * If the head of the linked list is null, then return null
         */
        if (head == null) {
            return(null);
        }

        /*
         * Point both 'fast' and 'slow' pointers to the head of the
         * linked list
         */
        fast = head;
        slow = head;

        /*
         * Iterate through the list linked list
         */
        while ((fast != null) && (fast.next != null)) {

            /*
             * Move the 'fast' pointer by two nodes
             */
            fast = fast.next.next;

            /*
             * Move the 'slow' pointer by one node
             */
            slow = slow.next;
        }

        /*
         * Return the 'slow' pointer
         */
        return(slow);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Head of the list points to null. The middle element
         *         should also point to null.
         */
        node head1 = null;
        node middle1 = null;
        middle1 = find_linked_list_middle_element(head1);
        assert(null == middle1);

        /*
         * Test 2: There is only one node in the list. The middle element
         *         should be the only element in the linked list.
         */
        node head2 = null;
        node middle2 = null;
        head2 = new node(1);
        middle2 = find_linked_list_middle_element(head2);
        assert((null != middle2) && (middle2.data == 1));

        /*
         * Test 3: There are only two nodes in the list. The middle element
         *         should be the last element in the linked list.
         */
        node head3 = null;
        node middle3 = null;
        head3 = new node(1);
        head3.next = new node(2);
        middle3 = find_linked_list_middle_element(head3);
        assert((null != middle3) && (middle3.data == 2));

        /*
         * Test 4: There are odd number of nodes in the list. The middle
         *         element should be the middle element in the linked list.
         */
        node head4 = null;
        node middle4 = null;
        head4 = new node(1);
        head4.next = new node(2);
        head4.next.next = new node(3);
        head4.next.next.next = new node(4);
        head4.next.next.next.next = new node(5);
        middle4 = find_linked_list_middle_element(head4);
        assert((null != middle4) && (middle4.data == 3));

        /*
         * Test 5: There are even number of nodes in the list. The middle
         *         element should be the first element in the second half of
         *         the linked list.
         */
        node head5 = null;
        node middle5 = null;
        head5 = new node(1);
        head5.next = new node(2);
        head5.next.next = new node(3);
        head5.next.next.next = new node(4);
        head5.next.next.next.next = new node(5);
        head5.next.next.next.next.next = new node(5);
        middle5 = find_linked_list_middle_element(head5);
        assert((null != middle5) && (middle5.data == 4));
    }
}
