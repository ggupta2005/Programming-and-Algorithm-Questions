/*
 * This program gets the out-degree and in-degree of a particular node in
 * a graph represented by adjacency list. The out-degree is the number of
 * nodes to which a given node has out-going edges. The in-degree of a node
 * in the graph is the number of nodes which have edges going into this
 * node.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define MAX_GRAPH_NODES 100
#define ILLEGAL         -1

/*
 * Structure of the linked list node
 */
struct node {
    int data;
    struct node *next;
};

/*
 * This function allocates and new linked list node and sets the 'data' field
 * in the node to be equal to 'value'.
 */
struct node* makeNode(int value)
{
    struct node* data_node;

    data_node = (struct node *)malloc(sizeof(struct node));

    /*
     * If the node allocated was NULL, then return null.
     */
    if (!data_node)
        return(NULL);

    data_node->data = value;
    data_node->next = NULL;

    return data_node;
}

/*
 * This function adds the 'value' passed to it to the front of the linked
 * list (pointed to by 'head'.
 */
void push (struct node **head, int value)
{
    struct node *new_node = makeNode(value);

    /*
     * If the system in not able to allocate a new node for 'value',
     * then we need not add anything to the linked list.
     */
    if (!new_node) {
        return;
    }

    /*
     * If the heaad of the list is NULL, then set head to point to
     * new node otherwise set node's next to head and point head to
     * point to the node.
     */
    if (!(*head)) {
        *head = new_node;
    } else {
         new_node->next = *head;
         *head = new_node;
    }
}

struct graph {
    struct node* adj_list[MAX_GRAPH_NODES];
    int max_nodes;
};

void init_graph (struct graph* g, int max_nodes)
{
    int index;

    if (!g) {
        return;
    }

    if ((max_nodes <= 0) || (max_nodes > MAX_GRAPH_NODES)) {
        g->max_nodes = 0;
        return;
    }

    g->max_nodes = max_nodes;

    for (index = 0; index < max_nodes; ++index) {
        g->adj_list[index] = NULL;
    }
}

void add_edge_to_graph (struct graph* g, int src, int dest)
{
    if (!g || !(g->max_nodes) ||
        (src < 0) || (src >= g->max_nodes) ||
        (dest < 0) || (dest >= g->max_nodes)) {
        return;
    }

    push(&(g->adj_list[src]), dest);
}

int get_out_degree_of_node (struct graph* g, int node_num)
{
    int out_degree;
    struct node* current;

    if (!g || !(g->max_nodes) || (node_num < 0) ||
        (node_num >= g->max_nodes)) {
        return(ILLEGAL);
    }

    current = g->adj_list[node_num];
    out_degree = 0;
    while (current) {
        ++out_degree;
        current = current->next;
    }

    return(out_degree);
}

int get_in_degree_of_node (struct graph* g, int node_num)
{
    int in_degree, index;
    struct node* current;

    if (!g || !(g->max_nodes) || (node_num < 0) ||
        (node_num >= g->max_nodes)) {
        return(ILLEGAL);
    }

    in_degree = 0;
    for (index = 0; index < g->max_nodes; ++index) {

        if (index != node_num) {

            current = g->adj_list[index];
            while (current) {

                if (node_num == current->data) {
                    ++in_degree;
                }

                current = current->next;
            }
        }
    }

    return(in_degree);
}

int main ()
{
    int index;

    struct graph g0;
    init_graph(&g0, 7);
    add_edge_to_graph(&g0, 0, 1);
    add_edge_to_graph(&g0, 0, 2);
    add_edge_to_graph(&g0, 2, 3);
    add_edge_to_graph(&g0, 3, 1);
    add_edge_to_graph(&g0, 3, 4);
    add_edge_to_graph(&g0, 3, 5);
    add_edge_to_graph(&g0, 4, 6);
    add_edge_to_graph(&g0, 4, 1);
    add_edge_to_graph(&g0, 4, 2);
    assert(2 == get_out_degree_of_node(&g0, 0));
    assert(0 == get_out_degree_of_node(&g0, 1));
    assert(1 == get_out_degree_of_node(&g0, 2));
    assert(3 == get_out_degree_of_node(&g0, 3));
    assert(3 == get_out_degree_of_node(&g0, 4));
    assert(0 == get_out_degree_of_node(&g0, 5));
    assert(0 == get_out_degree_of_node(&g0, 6));
    assert(-1 == get_out_degree_of_node(&g0, 7));
    assert(-1 == get_out_degree_of_node(&g0, -1));
    assert(0 == get_in_degree_of_node(&g0, 0));
    assert(3 == get_in_degree_of_node(&g0, 1));
    assert(2 == get_in_degree_of_node(&g0, 2));
    assert(1 == get_in_degree_of_node(&g0, 3));
    assert(1 == get_in_degree_of_node(&g0, 4));
    assert(1 == get_in_degree_of_node(&g0, 5));
    assert(1 == get_in_degree_of_node(&g0, 6));
    assert(-1 == get_in_degree_of_node(&g0, 7));
    assert(-1 == get_in_degree_of_node(&g0, -1));

    struct graph g1;
    init_graph(&g1, MAX_GRAPH_NODES);
    for (index = 1; index < MAX_GRAPH_NODES; ++index) {
        add_edge_to_graph(&g1, 0, index);
    }
    assert(99 == get_out_degree_of_node(&g1, 0));
    assert(0 == get_in_degree_of_node(&g1, 0));
    for (index = 1; index < MAX_GRAPH_NODES; ++index) {
        assert(0 == get_out_degree_of_node(&g1, index));
        assert(1 == get_in_degree_of_node(&g1, index));
    }

    struct graph g2;
    init_graph(&g2, MAX_GRAPH_NODES);
    for (index = 0; index < MAX_GRAPH_NODES; ++index) {
        if (index == (MAX_GRAPH_NODES - 1)) {
            add_edge_to_graph(&g2, index, 0);
        } else {
            add_edge_to_graph(&g2, index, index + 1);
        }
    }
    for (index = 0; index < MAX_GRAPH_NODES; ++index) {
        assert(1 == get_out_degree_of_node(&g2, index));
        assert(1 == get_in_degree_of_node(&g2, index));
    }

    return(0);
}
