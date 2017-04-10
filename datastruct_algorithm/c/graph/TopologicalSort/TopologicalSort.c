#include "TopologicalSort.h"

void TopologicalSort(Vertex* V, Node** List){
	Edge* E = NULL;

	printf("[%d] ", V->Data);
	V->Visited = Visited;

	E = V->AdjacencyList;

	while(E != NULL){
		if(E->Target != NULL && E->Target->Visited == NotVisited)
			TopologicalSort(E->Target, List);

		E = E->Next;
	}

	Node* NewHead  = NULL;
	NewHead = SLL_CreateNode(V->Data);
	SLL_InsertNewHead(List, NewHead);
}

