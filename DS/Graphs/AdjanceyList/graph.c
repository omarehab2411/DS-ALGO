#include "graph.h"

graph* graph_create(int verticies)
{
 graph* Graph =(graph*) malloc( sizeof(graph ) );
 Graph->Vertices =verticies;
 Graph->pAdjList =(adjList*) malloc(sizeof(adjList)*verticies);
for(int i=0;i<verticies ;i++)
{
   Graph->pAdjList[i].head =NULL;
}

return Graph;
}

void graph_insert_node (graph* pGraph,int src,int dest)
{

/* Create vertex */
GraphVertex* newVertex =(GraphVertex*) malloc(sizeof(GraphVertex));
newVertex->dest = dest;
newVertex->next = NULL;


/*append vertex to the adj list*/
newVertex->next = pGraph->pAdjList[src].head;

/*update head*/
pGraph->pAdjList[src].head = newVertex ;


/* this graph will be un-directed so we will also make an edge from dest to src*/
GraphVertex* NewVertex =(GraphVertex*) malloc(sizeof(GraphVertex));
NewVertex->dest =src;
NewVertex->next =NULL;
NewVertex->next= pGraph->pAdjList[dest].head;
pGraph->pAdjList[dest].head = NewVertex;

}

void graph_dump (graph* pGraph)
{
    for(int i=0;i<pGraph->Vertices ;i++)
    {
        printf("Vertex[%d] is connected to ",i);
        GraphVertex* pVertex =pGraph->pAdjList[i].head;
        while(pVertex != NULL)
        {
            printf("->%d",pVertex->dest);
            pVertex =pVertex->next;
        }
        printf("\r\n");
    }
}


