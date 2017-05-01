#include "Graph.h"

int main(void){

	Graph test(9);

	test.AddEdge(0,1,35);
	test.AddEdge(0,4,247);

	test.AddEdge(1,0,35);
	test.AddEdge(1,2,126);
	test.AddEdge(1,5,150);

	test.AddEdge(2,1,126);
	test.AddEdge(2,3,117);
	test.AddEdge(2,5,162);
	test.AddEdge(2,6,220);

	test.AddEdge(3,2,117);

	test.AddEdge(4,0,247);
	test.AddEdge(4,5,82);
	test.AddEdge(4,7,98);

	test.AddEdge(5,1,150);
	test.AddEdge(5,2,162);
	test.AddEdge(5,4,82);
	test.AddEdge(5,6,154);
	test.AddEdge(5,7,120);

	test.AddEdge(6,2,220);
	test.AddEdge(6,5,154);
	test.AddEdge(6,8,106);

	test.AddEdge(7,4,98);
	test.AddEdge(7,5,120);

	test.AddEdge(8,6,106);

	test.Dijkstra(1);

	test.printDijkstra();


	return 0;
}
