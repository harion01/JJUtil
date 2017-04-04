#ifndef CPP_GRAPH_HEAD
#define CPP_GRAPH_HEAD

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex{
	int searchcount;
	int searchcost;

	int index;
	bool isVisited;
	vector<pair<int,int> > edges;
};


class Graph{
	private:
		int vertnum;
		vector<Vertex> vertices;
	public:
		Graph(int nodenum);
		void BFS(int startindex);
		void addEdge(int from, int to, int cost);
};


#endif
