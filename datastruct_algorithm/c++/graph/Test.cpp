#include "Graph.h"
using namespace std;

int main(){
	Graph G;

	G.AddVertex(1, 1);
	G.AddVertex(2, 1);
	G.AddVertex(3, 1);
	G.AddVertex(4, 1);
	G.AddVertex(5, 1);

	G.AddVertexDirectedEdge(1, 2, 1);
	G.AddVertexDirectedEdge(1, 3, 1);
	
	G.AddVertexDirectedEdge(2, 4, 2);
	G.AddVertexDirectedEdge(2, 5, 2);


	G.AddVertexDirectedEdge(3, 4, 3);
	G.AddVertexDirectedEdge(4, 5, 4);
	G.AddVertexDirectedEdge(5, 1, 5);


	G.PrintGraph();
	return 0;
}
