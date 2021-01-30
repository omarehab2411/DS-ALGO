#include"graph.h"

int main()
{
    /*driver code*/
    graph* pGraph =graph_create(5);
    graph_insert_node(pGraph,0,1);
    graph_insert_node(pGraph,0,4);
    graph_insert_node(pGraph,1,2);
    graph_insert_node(pGraph,1,3);
    graph_insert_node(pGraph,1,4);
    graph_insert_node(pGraph,2,3);
    graph_insert_node(pGraph,3,4);
    graph_insert_node(pGraph,4,2);
    graph_dump(pGraph);
    return 0;
}
