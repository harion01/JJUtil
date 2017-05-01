#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex{
	private:
	public:
		bool isVisited;
		int index;
		vector<pair<int, int> > edges;
};

struct shortest_edge{
	public:
		int from;
		int to;
		int weight;
};

struct DijstraNode{
	public:
		int index;
		int parent;
		int weight;
		bool isVisited;
};

class shortcomp{
	public:
		bool operator()(shortest_edge edge1, shortest_edge edge2){
			return edge1.weight > edge2.weight;
		}
};


class Graph{
	private:
		vector<vertex> vertices;
		vector<DijstraNode> dijkstra;
		priority_queue<shortest_edge, vector<shortest_edge>, shortcomp > edgeQ;

	public:
		Graph(int vertexlimit);
		void AddEdge(int from, int to, int weight);
		void Dijkstra(int start);
		void printDijkstra();
};
