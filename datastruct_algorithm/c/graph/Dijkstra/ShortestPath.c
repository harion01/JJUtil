#include "ShortestPath.h"

void Dijkstra(Graph* G, Vertex* StartVertex, Graph* MST){
	int i =0;
	
	PQNode	Start Node = {0, (void*)StartVertex};
	PriorityQueue* PQ = PQ_Create(10);

	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;

	int* Weights = (int*)calloc(G->VertexCount, sizeof(int));
	
	Vertex** ShortestPathVertices =
			(Vertex**)calloc(G->VertexCount, sizeof(Vertex*));

	Vertex** Fringes = 
			(Vertex**)calloc(G->VertexCount, sizeof(Vertex*));

	Vertex** Precedences = 
			(Vertex**)calloc(G->VertexCount, sizeof(Vertex*));

	CurrentVertex = G->vertices;

}

