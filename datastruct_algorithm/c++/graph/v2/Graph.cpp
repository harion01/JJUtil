#include "Graph.h"

Graph::Graph(int nodenum): vertnum(nodenum+1){
	for(int i = 0; i < vertnum ; i++){
		Vertex one;
		one.index = i;
		one.isVisited = false;
		vertices.push_back(one);
	}
}

void Graph::addEdge(int from, int to, int cost){
	if(from > this->vertnum ){
		cout << "out of index range" << endl;
		return;
	}
	Vertex target = vertices.at(from);
	target.edges.push_back(make_pair(to,cost));
	vertices.at(from) = target;
}

void Graph::BFS(int startindex){
	if(startindex > this->vertnum ){
		cout << "out of index range" << endl;
		return ;
	}
	queue<Vertex> Q;
	
	Vertex one =  vertices.at(startindex);
	one.isVisited = true;
	one.searchcount = 1;
	one.searchcost = 0;
	vertices.at(startindex) = one;
	
	Q.push(one);
	cout << "check" << endl;
	while(!Q.empty()){
		Vertex visitnode = Q.front();
		cout << "visit node : " << visitnode.index << 
		", search count : " << visitnode.searchcount << 
		", search cost : " <<  visitnode.searchcost << endl;
		for(auto i = visitnode.edges.begin(); i != visitnode.edges.end(); i++){
			//i is pair(to , cost)
			Vertex Destination = vertices.at(i->first);
			if(Destination.isVisited == false){
				Destination.isVisited = true;
				Destination.searchcount = visitnode.searchcount+1;
				Destination.searchcost = visitnode.searchcost + i->second;
				vertices.at(i->first) = Destination;
				
				Q.push(Destination);
			}
		}
		Q.pop();
	}
}



