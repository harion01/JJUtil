#include "ShortestPath.h"

void Dijkstra(Graph* G, Vertex* StartVertex, Graph* ShortestPath){
	int i =0 ;
	PQNode StartNode = {0,StartVertex};
	PriorityQueue* PQ = PQ_Create(10);
	
	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;

	int* Weights = (int*)calloc(G->VertexCount, sizeof(int));
	Vertex** ShortestPathVertices = 
		(Vertex**)calloc(G->VertexCount, sizeof(Vertex*));

	Vertex** Fringes = (Vertex**)calloc(G->VertexCount, sizeof(Vertex*));
	Vertex** Precedences = (Vertex**)calloc(G->VertexCount, sizeof(Vertex*));
	
	//init all vertex
	CurrentVertex = G->vertices;
	while(CurrentVertex!=NULL){
		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
		AddVertex(ShortestPath, NewVertex);
	
		Fringes[i] = NULL;
		Precedences[i] = NULL;
		ShortestPathVertices[i] = NewVertex;
		Weights[i] = MAX_WEIGHT;
		CurrentVertex = CurrentVertex->Next;
		i++;
	}
	
	//regist inital vertex
	PQ_Enqueue(PQ, StartNode);
	Weights[StartVertex->Index] = 0;


	while(! PQ_IsEmpty(PQ)){
		PQNode Popped;
		PQ_Dequeue(PQ, &Popped);
		CurrentVertex = (Vertex*)Popped.Data;
		
		//add vertex 
		Fringes[CurrentVertex->Index] = CurrentVertex;

		//check every edge of current vertex 
		CurrentEdge = CurrentVertex->AdjacencyList;
		while(CurrentEdge != NULL){
			Vertex* TargetVertex = CurrentEdge->Target;
			
			//if target is not in added vertex(not cycle) 
			//if weight from start node + weight of current edge <
			//previous Weigtht from start node to target
			if(Fringes[TargetVertex->Index] == NULL &&
				Weights[CurrentVertex->Index] + CurrentEdge->Weight <
					Weights[TargetVertex->Index]){
				
				//priority is weigth. thus popped data is always shortest path
				PQNode NewNode = {CurrentEdge->Weight, TargetVertex };
				PQ_Enqueue(PQ, NewNode);
				
				//save source node of edge (index number is target node index)
				Precedences[TargetVertex->Index] = CurrentEdge->From;
				Weights[TargetVertex->Index ] = Weights[CurrentVertex->Index]+
						CurrentEdge->Weight;
			}
			CurrentEdge = CurrentEdge->Next;
		}
	}

	for(i = 0; i<G->VertexCount; i++){

		int FromIndex, ToIndex;
		
		// skip non-linked vertex
		if(Precedences[i] == NULL){
			continue;
		}

		FromIndex = Precedences[i]->Index;
		ToIndex = i;
		
		//Pointer of ShortestPathVertices is same as ShortestPath
		AddEdge(ShortestPathVertices[FromIndex], 
			CreateEdge(
				ShortestPathVertices[FromIndex],
				ShortestPathVertices[ToIndex],
				Weights[i]));
	}

	free(Fringes);
	free(Precedences);
	free(ShortestPathVertices);
	free(Weights);

	PQ_Destroy(PQ);
}

