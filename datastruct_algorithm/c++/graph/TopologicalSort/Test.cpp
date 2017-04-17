#include "Graph.h"

int main(){
	graph G;
	G.AddVertex(1);
	G.AddVertex(2);
	G.AddVertex(3);
	G.AddVertex(4);
	G.AddVertex(5);
	G.AddVertex(6);
	G.AddVertex(7);
	G.AddVertex(8);

	G.AddEdge(1,3,0);
	G.AddEdge(1,4,0);

	G.AddEdge(2,3,0);
	G.AddEdge(2,5,0);

	G.AddEdge(3,6,0);
	
	G.AddEdge(4,6,0);
	G.AddEdge(4,7,0);

	G.AddEdge(5,7,0);

	G.AddEdge(6,8,0);

	G.AddEdge(7,8,0);

	G.TopoSortAll();
	G.printfTopo();

	return 0;
}
