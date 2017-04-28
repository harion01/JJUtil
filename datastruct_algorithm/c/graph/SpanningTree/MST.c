#include "MST.h"


void Prim(Graph* G, Vertex* StartVertex, Graph* MST){
	int i =0 ;
	PQNode  StartNode = {0, (void*)StartVertex};
	PriorityQueue* PQ = PQ_Create(10);

	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;

	int* Weight = (int*)calloc(G->VertexCount, sizeof(Vertex*));
	Vertex** MSTVertices = 
			(Vertex**)calloc(G->VertexCount, sizeof(Vertex*));
	Vertex** Fringes =
			(Vertex**)calloc(G->VertexCount, sizeof(Vertex*));
	Vertex** Precedences =
			(Vertex**)calloc(G->VertexCount, sizeof(Vertex*));

	CurrentVertex = G->vertices;
	//copy every vertex and set weight infinity(MAX value)
	while(CurrentVertex != NULL){
		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
		AddVertex(MST, NewVertex);

		Fringes[i] = NULL;
		Precedences[i] = NULL;
		MSTVertices[i] = NewVertex; //copy evert vertex (no edge included)
		Weight[i] = MAX_WEIGHT;
		CurrentVertex = CurrentVertex->Next;
		i++;
	}
	
	//in Minimum Spanning Tree, weight of start node is 0
	PQ_Enqueue(PQ, StartNode);
	Weight[StartVertex->Index] = 0;

	while(! PQ_IsEmpty(PQ)){
		PQNode Popped;
		PQ_Dequeue(PQ, &Popped);
		//check added vertex
		CurrentVertex = (Vertex*)Popped.Data;
		//to vertex
		Fringes[CurrentVertex->Index] = CurrentVertex;

		//check weight of every edge from current node
		CurrentEdge = CurrentVertex->AdjacencyList;
		while(CurrentEdge != NULL){
			//target is destination of edge
			Vertex* TargetVertex = CurrentEdge->Target;

			//if target vertex is not added as from node && 
			//weight of edge is less than previous weight 
			//(from current node to target node)
			if(Fringes[TargetVertex->Index] == NULL &&
				CurrentEdge->Weight < Weight[TargetVertex->Index])
			{
				//add node for next check
				//next check will start with smallest weigh (by Priority)
				PQNode NewNode = {CurrentEdge->Weight, TargetVertex};
				PQ_Enqueue (PQ,NewNode);
				
				//from vertex
				Precedences[TargetVertex->Index] = CurrentEdge->From;
				//weight of edge between Fringes and Precedences
				//(smallest - by Priority queue)
				Weight[TargetVertex->Index] = CurrentEdge->Weight;

			}
			CurrentEdge = CurrentEdge->Next;
		}
	}

	for(i = 0 ; i < G->VertexCount; i++){
		int FromIndex, ToIndex;
		if(Precedences[i] == NULL)
			continue;
		
		FromIndex = Precedences[i] -> Index;
		ToIndex = i;
		
		//for non-direct edge (both vertex have same edge)
		AddEdge(MSTVertices[FromIndex],
			CreateEdge(MSTVertices[FromIndex],  MSTVertices[ToIndex], Weight[i]));
		AddEdge(MSTVertices[ToIndex],
			CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], Weight[i]));
	
	}
	
	free(Fringes);
	free(Precedences);
	free(MSTVertices);
	free(Weight);
	
	PQ_Destroy(PQ);
}


void Kruskal(Graph* G, Graph* MST);

