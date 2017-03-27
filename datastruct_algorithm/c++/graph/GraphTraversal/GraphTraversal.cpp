#include "GraphTraversal.h"

using namespace std;

GraphAlgorithm::GraphAlgorithm(Graph* ){
	this->graph = graph;
}


void GraphAlgorithm::ClearFootStep(){
	cout << endl << "Clear Footstep!" << endl << endl;
	for (auto i = graph->Vertices.begin() ; i!= graph->Vertices.end(); i++){
		i->isVisited = false;
	}
}

void GraphAlgorithm::DepthFirstSearch(int startindex){
	Vertex start = graph->Vertices.at(startindex);
	start.isVisited = true;
	graph->Vertices.at(startindex) = start;
	cout << "visit vertex! : index [" << start.Index << "] data [" << start.Data << "]" << endl;
	for(auto i = start.AdjacencyVector.begin() ; i!= start.AdjacencyVector.end(); i++){
		Vertex imsi = graph->Vertices.at(i->first);
		if(!imsi.isVisited){
			GraphAlgorithm::DepthFirstSearch(i->first);
		}
	}
}


void GraphAlgorithm::BreadthFirstSearch(int startindex){
	deque<int> BFSQ;
	Vertex start = graph->Vertices.at(startindex);
	start.isVisited = true;
	graph->Vertices.at(startindex) = start;
	BFSQ.push_back(startindex);

	while(0!=BFSQ.size()){
		int imsiindex = BFSQ.front();
		BFSQ.pop_front();
		Vertex imsi = graph->Vertices.at(imsiindex);
		cout << "visit vertex! : index [" << imsi.Index << "] data [" << imsi.Data << "]" << endl;


		for(auto i = imsi.AdjacencyVector.begin() ; i!= imsi.AdjacencyVector.end(); i++){
			Vertex next = graph->Vertices.at(i->first);
			if(!next.isVisited){
				next.isVisited = true;
				graph->Vertices.at(next.Index) = next;
				BFSQ.push_back(next.Index);
			}
		}
	}
}





