#include "Graph.h"

Graph* CreateGraph(){
	Graph* graph = (Graph*)calloc(1, sizeof(Graph));
	graph->vertices= NULL;
	graph->VertexCount = 0;
	return graph;
}

void DestroyGraph(Graph* G){
	while(G->vertices != NULL){
		Vertex* Vertices = G->vertices->Next;
		DestroyVertex(G->vertices);
		G->vertices = Vertices;
	}
	free(G);
}


Vertex* CreateVertex(ElementType Data){
	Vertex* ver = (Vertex*)calloc(1, sizeof(Vertex));

	ver->Data = Data;
	ver->Next = NULL;
	ver->AdjacencyList = NULL;
	ver->Visited = NotVisited;
	ver->Index = -1;

	return ver;
}

void DestroyVertex(Vertex* V){
	while(V->AdjacencyList != NULL){
		Edge* Edge = V->AdjacencyList->Next;
		DestroyEdgt(V->AdjacencyList);
		V->AdjacencyList = Edge;
	}

	free(V);
}


Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight){
	Edge* E = (Edge*)calloc(1, sizeof(Edge));
	E->From = From;
	E->Target = Target;
	E->Next = NULL;
	E->Weight = Weight;

	return E;
}

void DestroyEdgt(Edge* E){
	free(E);
}

void AddVertex(Graph* G, Vertex* V){
	Vertex* VerList = G->vertices;

	if(VerList == NULL){
		G->vertices = V;
	}else {
		while(VerList->Next != NULL){
			VerList = VerList->Next;
		}
		VerList->Next = V;
	}

	V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E){

	if(V->AdjacencyList == NULL){
		V->AdjacencyList = E;
	}else {
		Edge* AdjacencyList = V->AdjacencyList;
		while(AdjacencyList->Next != NULL){
			AdjacencyList = AdjacencyList->Next;
		}
		AdjacencyList->Next = E;
	}

}

void PrintGraph(Graph* G){
	Vertex* V = NULL;
	Edge* E = NULL;
	printf("Graph info. VertexCount [%d]\n", G->VertexCount);

	V = G->vertices;
	if( V == NULL){
		return;
	}

	while(V!=NULL){
		printf("Vertex [%c] : ", V->Data);
		E = V->AdjacencyList;
		if(E == NULL){
			printf("No Edge\n");
			V = V->Next;
			continue;
		}

		while(E != NULL){
			printf("Vertex[%c]:Weight[%d] ", E->Target->Data, E->Weight);
			E = E->Next;
		}
		printf("\n");

		V = V->Next;
	}
	printf("\n");
}

