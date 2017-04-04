#include "Graph.h"

int main(){

	Graph graph(3);

	graph.addEdge(0,2,10);
	graph.addEdge(0,1,20);
	graph.addEdge(2,0,10);
	graph.addEdge(2,3,20);
	graph.addEdge(3,3,0);

	graph.BFS(2);

	return 0;
}
