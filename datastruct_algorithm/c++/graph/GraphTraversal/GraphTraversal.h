#ifndef CPP_GRAPH_TRAVALSAL
#define CPP_GRAPH_TRAVALSAL

#include "Graph.h"

using namespace std;

class GraphAlgorithm{
	private:
		Graph* graph;
	public :
		GraphAlgorithm(Graph* garph);
		void ClearFootStep();
		void DepthFirstSearch(int startindex);
		void BreadthFirstSearch(int startindex);
};

#endif
