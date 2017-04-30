#include "MinST.h"

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
	MST.clear();
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

void Graph::MakeKruskalMST(){
	KruskalMST.clear();
	KruskalMST = graph;
	for(int i=0; i<graph.size(); i++){
		KruskalMST[i].edges.clear();
	}

	vector<DisjointSet> setvec;

	for(auto cur: graph){
		for(auto edge : cur.edges ){
			kruskaledge krus = {cur.index , edge.first, edge.second};
			kruskalQ.push(krus);
		}
		DisjointSet set = {NULL, (void*)&cur};
		setvec.push_back(set);
	}

	while(!kruskalQ.empty()){
		kruskaledge minedge = kruskalQ.top();
		kruskalQ.pop();
		if(DS_FindRoot(&setvec[minedge.from]) !=
			DS_FindRoot(&setvec[minedge.to])){
			KruskalMST[minedge.from].edges.push_back(make_pair(minedge.to, minedge.weight));
			KruskalMST[minedge.to].edges.push_back(make_pair(minedge.from, minedge.weight));
			DS_UnionSet(&setvec[minedge.to], &setvec[minedge.from]);
		}
	}
}

void Graph::printKruskalMST(){
	for(auto cur: KruskalMST){
		cout << "index:" << cur.index << " " ;
		for(auto edge : cur.edges ){
			cout << "edge: to[" << edge.first << "] wieght ["
				<< edge.second << "]    ";
		}
		cout << endl;
	}

}

