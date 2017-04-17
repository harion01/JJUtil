
#include "Graph.h"

/*
struct Node{
	bool isvisited;
	vector<pair<int,int> > edges
	list<int> TopoSort;
};

class graph{
	private:
		map<int,Node> vertecis;
	public:
		void AddVertex(int index);
		void AddEdge(int from, int to, int cost);

		//void TopologicalSort(int statindex);
};
*/
void graph::AddVertex(int index){
	Node node;
	node.isvisited = false;
	
	vertecis.insert(make_pair(index, node));
}

void graph::AddEdge(int from, int to, int cost){	
	Node node;
	auto ret = vertecis.find(from);
	if(ret !=vertecis.end()){
		(ret->second).edges.push_back(make_pair(to,cost));
	}
}


}
