#include "Graph.h"
#include "GraphTraversal.h"
using namespace std;

int main(){
	Graph G;

	G.AddVertex(1, 10);
	G.AddVertex(2, 20);
	G.AddVertex(3, 30);
	G.AddVertex(4, 40);
	G.AddVertex(5, 50);
	G.AddVertex(6, 60);
	G.AddVertex(7, 70);

	G.AddVertexDirectedEdge(1, 2, 1);
	G.AddVertexDirectedEdge(1, 3, 1);
	
	G.AddVertexDirectedEdge(2, 4, 1);
	G.AddVertexDirectedEdge(2, 5, 1);

	G.AddVertexDirectedEdge(3, 4, 1);
	G.AddVertexDirectedEdge(3, 6, 1);

	G.AddVertexDirectedEdge(4, 5, 1);
	G.AddVertexDirectedEdge(4, 7, 1);

	G.AddVertexDirectedEdge(5, 7, 1);

	G.AddVertexDirectedEdge(6, 7, 1);
	G.PrintGraph();

	cout << endl;

	GraphAlgorithm Galgo(&G);
	Galgo.DepthFirstSearch(1);

	Galgo.ClearFootStep();

	Galgo.BreadthFirstSearch(1);

	return 0;
}
