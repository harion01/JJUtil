#include "Graph.h"

/*
struct vertex{
	private:
	public:
		bool isVisited;
		int index;
		vector<pair<int, int> > edges;
};


class Graph{
	private:
		vector<vertex> vertices;
		vector<vertex> dijkstra;

	public:
		Graph(int vertexlimit);
		void AddEdge(int from, int to, int weight);
		void Dijkstra(int start);
}
*/


Graph::Graph(int vertexlimit){
	vertex dummy;
	for(int i = 0; i < vertexlimit; i++){
		dummy.index = i;
		dummy.isVisited = false;
		vertices.push_back(dummy);
	}
}

void Graph::AddEdge(int from, int to, int weight){
	vertices[from].edges.push_back(make_pair(to, weight));
}

void Graph::Dijkstra(int start){
	DijstraNode Dnode;
	for(auto i : vertices){
		Dnode.index = i.index;
		Dnode.isVisited = false;
		Dnode.parent = -1;
		Dnode.weight = 999999999;
		dijkstra.push_back(Dnode);
	}

	vertex curnode;
	shortest_edge curedge;
	curnode = vertices[start];
	dijkstra[start].isVisited = true;
	dijkstra[start].parent = start;
	dijkstra[start].weight = 0;;
	for(int i = 0; i < curnode.edges.size(); i++){
		curedge.from = curnode.index;
		curedge.to =  curnode.edges[i].first;
		curedge.weight=  curnode.edges[i].second;
		edgeQ.push(curedge);
	}

	while(!edgeQ.empty()){
		curedge = edgeQ.top();
		edgeQ.pop();

		cout << "check node. index: " << dijkstra[curedge.to].index
			<<"  parent : " << dijkstra[curedge.to].parent
			<<"  weight : " << dijkstra[curedge.to].weight 
			<< " is visited : " << dijkstra[curedge.to].isVisited << endl;
		

		//if(dijkstra[curedge.to].isVisited == false && 
		if((dijkstra[curedge.from].weight + curedge.weight)
		< dijkstra[curedge.to].weight){
			dijkstra[curedge.to].isVisited = true;
			dijkstra[curedge.to].parent = curedge.from;
			dijkstra[curedge.to].weight = 
				dijkstra[curedge.from].weight + curedge.weight;
			cout << "update node. index: " << dijkstra[curedge.to].index
				<<"  parent : " << dijkstra[curedge.to].parent
				<<"  weight : " << dijkstra[curedge.to].weight << endl;
			shortest_edge nextedge;
			vertex nextnode = vertices[curedge.to];
			for(int i = 0; i < nextnode.edges.size(); i++){
				nextedge.from = nextnode.index;
				nextedge.to = nextnode.edges[i].first;
				nextedge.weight=  nextnode.edges[i].second;
				edgeQ.push(nextedge);
			}
		}
	}
}

void Graph::printDijkstra(){
	for(auto i : dijkstra){
		cout << "index : " << i.index << ",  " ;
		cout << "parent : " << i.parent << ",  " ;
		cout << "weight : " << i.weight << ",  " ;
		cout << "isVisited : " << i.isVisited ;
		cout << endl;
	}
	cout << endl;
}
