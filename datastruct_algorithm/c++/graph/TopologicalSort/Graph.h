
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

void graph::TopologicalSortIndex(int startindex){
	Node node;

	auto ret = vertecis.find(startindex);
	if(ret!=vertecis.end()){
		if((ret->second).isvisited == false){
			(ret->second).isvisited = true;
			node = ret->second;
		}else {
			return ;
		}
	}
	int next;
	int count = 0;
	
	count++;
	for(auto i: node.edges){
		next = i.first;
		auto nextnode = vertecis.find(next);
		if(nextnode != vertecis.end()){
			if(!(nextnode->second).isvisited){
				graph::TopologicalSortIndex(nextnode->first);
			}
		}
	}

	
	cout << "DFS search [" << startindex << "]" << endl;
	TopoSort.push_front(startindex);
}

void graph::TopoSortAll(){
	for(int i =1 ; i < vertecis.size(); i++){
		TopologicalSortIndex(i);
	}
}


void graph::printfTopo(){
	for(auto i:TopoSort){
		cout << "Topo [" << i << "]" << endl;
	}

}
