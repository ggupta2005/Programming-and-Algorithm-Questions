/*
 * This program gets the out-degree and in-degree of a particular node in
 * a graph represented by adjacency matrix. The out-degree is the number of
 * nodes to which a given node has out-going edges. The in-degree of a node
 * in the graph is the number of nodes which have edges going into this
 * node.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define MAX_GRAPH_NODES 100
#define ILLEGAL         -1

/*
 * Structure definition for graph as adjacency matrix
 */
struct graph {
    int** adj_matrix;        /* Matrix for graph */
    int max_nodes;           /* Number of nodes in the graph */
};

/*
 * This function initializes the graph as adjacency matrix  The
 * function allocates the adjacency matrix with 'max_nodes' nodes.
 */
void init_graph (struct graph* g, int max_nodes)
{
    int index, inner_index;

    /*
     * If the graph pointer is NULL, then return from the
     * function.
     */
    if (!g) {
        return;
    }

    /*
     * IF the number of graph nodes is not valid, then return from
     * this function.
     */
    if ((max_nodes <= 0) || (max_nodes > MAX_GRAPH_NODES)) {
        g->max_nodes = 0;
        return;
    }

    g->max_nodes = max_nodes;

    g->adj_matrix = (int**)malloc(sizeof(int*) * max_nodes);

    if (!(g->adj_matrix)) {
        g->max_nodes = 0;
        return;
    }

    for (index = 0; index < max_nodes; ++index) {

        g->adj_matrix[index] =
                    (int*)malloc(sizeof(int) * max_nodes);

        if (!(g->adj_matrix[index])) {
            for (inner_index = 0; inner_index < index;
                 ++inner_index) {
                free(g->adj_matrix[inner_index]);
            }
            g->max_nodes = 0;
            return;
        }

        memset(g->adj_matrix[index], 0, sizeof(int) * max_nodes);
    }
}

void add_edge_to_graph (struct graph* g, int src, int dest)
{
    if (!g || !(g->max_nodes) ||
        (src < 0) || (src >= g->max_nodes) ||
        (dest < 0) || (dest >= g->max_nodes)) {
        return;
    }

    g->adj_matrix[src][dest] = 1;
}

int get_out_degree_of_node (struct graph* g, int node_num)
{
    int out_degree;
    int index;

    if (!g || !(g->max_nodes) || (node_num < 0) ||
        (node_num >= g->max_nodes)) {
        return(ILLEGAL);
    }

    out_degree = 0;
    for (index = 0; index < g->max_nodes; ++index) {
        if (g->adj_matrix[node_num][index] == 1) {
            ++out_degree;
        }
    }

    return(out_degree);
}

int get_in_degree_of_node (struct graph* g, int node_num)
{
    int in_degree;
    int node_index, edge_index;

    if (!g || !(g->max_nodes) || (node_num < 0) ||
        (node_num >= g->max_nodes)) {
        return(ILLEGAL);
    }

    in_degree = 0;
    for (node_index = 0; node_index < g->max_nodes;
         ++node_index) {

        if (node_index == node_num) {
            continue;
        }

        if (g->adj_matrix[node_index][node_num] == 1) {
            ++in_degree;
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
