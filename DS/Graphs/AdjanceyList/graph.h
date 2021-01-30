#ifndef __GRAPH__H
#define __GRAPH__H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
 int dest;
 struct GraphVertex* next;
}GraphVertex;

typedef struct
{
  GraphVertex* head;
}adjList;

typedef struct
{
   int Vertices;
   adjList* pAdjList;
}graph;


graph* graph_create(int verticies);

void graph_insert_node (graph* pGraph,int src,int dest);


void graph_dump (graph* pGraph);

#endif // __GRAPH__H

