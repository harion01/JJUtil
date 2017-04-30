#ifndef MinimumSpanningTree_H
#define MinimumSpanningTree_H

#include <iostream>
#include <queue>
#include <vector>
#include "DisjointSet.h"
using namespace std;

struct vertex{
	private :

	public :
		int index;
		vector<pair<int, int> > edges; //to, weight of edge
};

struct primvertex{
	private:
	public:
		int index;
		int Parent;
		int weight;
};

struct kruskaledge{
	public:
		int from;
		int to;
		int weight;
};

class primcomp{
	public:
		bool operator()(primvertex primvertex1, primvertex primvertex2){
			return primvertex1.weight > primvertex2.weight ;
		}
};

class kruskalcomp{
	public:
		bool operator()(kruskaledge edge1, kruskaledge edge2){
			return edge1.weight > edge2.weight;
		}
};

class Graph : public DisjointUtil{
	private:
		vector<vertex> graph;
		vector<primvertex> MST;
		vector<vertex> KruskalMST;
		vector<bool> inMST;
		priority_queue<primvertex, vector<primvertex> , primcomp > primQ;
		priority_queue<kruskaledge, vector<kruskaledge>, kruskalcomp> kruskalQ;
	public:
		Graph(int vertexlimit);
		void addEdge(int from, int to, int weight);
		void MakePrimMST(int startindex);
		void MakeKruskalMST();
		void printMST();
		void printKruskalMST();
		void printVertex();

};


#endif
