#include "Graph.h"
#include "MST.h"

int main(void){
	Graph* graph = CreateGraph();
	Graph* PrimMST = CreateGraph();
	Graph* KruskalMST = CreateGraph();

	Vertex* A = CreateVertex('A');
	Vertex* B = CreateVertex('B');
	Vertex* C = CreateVertex('C');
	Vertex* D = CreateVertex('D');
	Vertex* E = CreateVertex('E');
	Vertex* F = CreateVertex('F');
	Vertex* G = CreateVertex('G');
	Vertex* H = CreateVertex('H');
	Vertex* I = CreateVertex('I');

	AddVertex(graph, A); //0
	AddVertex(graph, B); //1
	AddVertex(graph, C); //2
	AddVertex(graph, D); //3
	AddVertex(graph, E);//4
	AddVertex(graph, F);//5
	AddVertex(graph, G);//6
	AddVertex(graph, H);//7
	AddVertex(graph, I);//8

	AddEdge(A, CreateEdge(A, B, 35));
	AddEdge(A, CreateEdge(A, E, 247));

	AddEdge(B, CreateEdge(B, A, 35));
	AddEdge(B, CreateEdge(B, C, 126));
	AddEdge(B, CreateEdge(B, F, 150));

	AddEdge(C, CreateEdge(C, B, 126));
	AddEdge(C, CreateEdge(C, D, 117));
	AddEdge(C, CreateEdge(C, F, 162));
	AddEdge(C, CreateEdge(C, G, 220));

	AddEdge(D, CreateEdge(D, C, 117));

	AddEdge(E, CreateEdge(E, A, 247));
	AddEdge(E, CreateEdge(E, F, 82));
	AddEdge(E, CreateEdge(E, H, 98));


	AddEdge(F, CreateEdge(F, B, 150));
	AddEdge(F, CreateEdge(F, C, 162));
	AddEdge(F, CreateEdge(F, E, 82));
	AddEdge(F, CreateEdge(F, G, 154));
	AddEdge(F, CreateEdge(F, H, 120));

	AddEdge(G, CreateEdge(G, C, 220));
	AddEdge(G, CreateEdge(G, F, 154));
	AddEdge(G, CreateEdge(G, I, 106));

	AddEdge(H, CreateEdge(H, E, 98));
	AddEdge(H, CreateEdge(H, F, 120));

	AddEdge(I, CreateEdge(I, G, 106));

	printf("Prim's Algorithm\n");
	Prim(graph, B, PrimMST);
	PrintGraph(PrimMST);

	return 0;
}
