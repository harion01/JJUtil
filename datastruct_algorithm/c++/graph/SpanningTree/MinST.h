#ifndef MinimumSpanningTree_H
#define MinimumSpanningTree_H

#include <iostream>
#include <queue>
#include <vector>
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

class primcomp{
	public:
		bool operator()(primvertex primvertex1, primvertex primvertex2){
			return primvertex1.weight > primvertex2.weight ;
		}
};

class Graph{
	private:
		vector<vertex> graph;
		vector<primvertex> MST;
		vector<bool> inMST;
		priority_queue<primvertex, vector<primvertex> , primcomp > primQ;
	public:
		Graph(int vertexlimit);
		void addEdge(int from, int to, int weight);
		void MakePrimMST(int startindex);
		void printMST();
		void printVertex();
};

void Graph::printMST(){
	for(auto cur: MST){
		cout << cur.index << " " << cur.Parent << " " << cur.weight << endl;
	}
}

void Graph::printVertex(){
	for(auto cur: graph){
		cout << "index:" << cur.index << " " ;
		for(auto edge : cur.edges ){
			cout << "edge: to[" << edge.first << "] wieght [" 
			<< edge.second << "]    ";
		}
		cout << endl;
	}
}

Graph::Graph(int vertexlimit){
	vertex dummy;
	for(int i = 0; i<vertexlimit; i++){
		dummy.index = i;
		graph.push_back(dummy);
	}
}

void Graph::addEdge(int from, int to, int weight){
	graph[from].edges.push_back(make_pair(to, weight));
}

void Graph::MakePrimMST(int startindex){
	for(int i = 0; i<graph.size(); i++){
		primvertex dummy;
		inMST.push_back(false);
		dummy.index = i;
		dummy.Parent = -1;
		dummy.weight = 99999;
		MST.push_back(dummy);
	}

	primvertex start;
	start.index = startindex;
	start.Parent = startindex;
	start.weight = 0;
	primQ.push(start);

	while(!primQ.empty()){
		auto cur = primQ.top();
		cout << cur.index << " " << cur.Parent << " " << cur.weight << endl;
		cout << "inMST :" << inMST[cur.index] << endl;
		primQ.pop();
		if(inMST[cur.index] == false){
			inMST[cur.index] = true;
			MST[cur.index] = cur;
		}

		primvertex next;
		for(auto edge : graph[cur.index].edges){
			next = MST[edge.first];
			if(inMST[edge.first] == false && next.weight > edge.second){
				next.weight = edge.second;
				next.Parent = cur.index;
				next.index = edge.first;
				primQ.push(next);
			}
		}
	}
}




#endif
