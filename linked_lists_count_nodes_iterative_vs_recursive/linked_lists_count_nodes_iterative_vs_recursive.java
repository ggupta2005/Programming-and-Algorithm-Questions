/*
 * This program builds a linked list by pushing elements to the top of the
 * linked list. It then counts the number of elements in the linked list
 * by traversing the linked list iteratively and recursively.
 */
import java.io.*;
import java.util.*;

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

public class linked_lists_count_nodes_iterative_vs_recursive
{
    /*
     * This function counts the number of nodes in a linked list iteratively.
     */
    public static int count_nodes_iterative(node head)
    {
        int count = 0;
        node current = head;

        /*
         * Iterate through the list and increment the counter for
         * counting the number of nodes in the list.
         */
        while (current != null) {
            ++count;
            current = current.next;
         }

        /*
         * Return 'count'
         */
        return count;
    }

    /*
     * This function counts the number of nodes in a linked list recursively.
     */
    public static int count_nodes_recursive(node head)
    {
        /*
         * If head is null, then return 0
         */
        if (head == null)
            return(0);

        /*
         * Return the sum of 'this node' and the number of nodes
         * pointed to by 'head->next'
         */
        return(1 + count_nodes_recursive(head.next));
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Head of the list points to null
         */
        node head1 = null;
        assert 0 == count_nodes_iterative(head1);
        assert 0 == count_nodes_recursive(head1);

        /*
         * Test 2: There is only one node in the list
         */
        node head2 = null;
        head2 = new node(1);
        assert 1 == count_nodes_iterative(head2);
        assert 1 == count_nodes_recursive(head2);

        /*
         * Test 3: There are some nodes in the list
         */
        node head3 = null;
        head3 = new node(0);
        head3.next = new node(1);
        head3.next.next = new node(2);
        head3.next.next.next = new node(3);
        head3.next.next.next.next = new node(4);
        head3.next.next.next.next.next = new node(5);
        head3.next.next.next.next.next.next = new node(6);
        assert 7 == count_nodes_iterative(head3);
        assert 7 == count_nodes_recursive(head3);
    }
}
