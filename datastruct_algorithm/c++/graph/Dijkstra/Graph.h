#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node{
	bool isvisited;
	vector<pair<int,int> > edges
};

class graph{
	private:
		map<int,Node> vertecis;
	public:
		void AddVertex(int index);
		void AddEdge(int from, int to, int cost);
	

		void Dijkstra
};

#endif
