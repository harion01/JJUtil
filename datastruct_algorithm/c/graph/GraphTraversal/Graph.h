#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum Visitmode {Visited, NotVisited};

typedef int ElementType;

//list structure of vertex
typedef struct tagVertex {
	ElementType Data;  //data
	int Visited;  //is this node visited?
	int Index;   //index number
	
	struct tagVertex* Next;  //next vertex(list data structure)
	struct tagEdge* AdjacencyList; //near by node list
} Vertex;

typedef struct tagEdge{
	int Weight;  //wight value (lengh of edge, etc)
	struct tagEdge* Next;  
	Vertex* From;  //source node
	Vertex* Target;  //dest node
} Edge;

typedef struct tagGraph{
	Vertex* vertices; //top pointer of vertex list
	int VertexCount; //number of total node
} Graph;


Graph* CreateGraph();
void DestroyGraph(Graph* G);

Vertex* CreateVertex(ElementType Data);
void DestroyVertex(Vertex* V);

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight);
void DestroyEdgt(Edge* E);

void AddVertex(Graph* G, Vertex* V);
void AddEdge(Vertex* V, Edge* E);
void PrintGraph(Graph* G);

#endif
