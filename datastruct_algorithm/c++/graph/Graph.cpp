#include "Graph.h"


using namespace std;

Vertex::Vertex(int index, int data) : Index(index), Data(data), isVisited(false) {
	cout << "Vertex created!" << endl;
}

Vertex::~Vertex(){
	AdjacencyVector.clear();
	cout << "Vertex Destroyed" << endl;
}

void Vertex::AddEdge(int To, int Weight){
	AdjacencyVector.push_back(make_pair(To,Weight));
}

void Vertex::PrintVertex(){
	cout << "Vertex[" << Index << "] : ";
	pair<int,int> imsi;
	for(auto i = AdjacencyVector.begin(); i!=AdjacencyVector.end(); i++){
		imsi = *i;
		cout << " [Edge- To :" << imsi.first << " Weight :" << imsi.second <<"]";
	}
	cout << endl;
}

///
Graph::Graph(){
	cout << "Graph create! " << endl;
	Vertex dummy(0, 0);
	Vertices.push_back(dummy);
	VertexCount = 0;
}

Graph::~Graph(){
	cout << "Graph Destroy " << endl;
	Vertices.clear();
}

void Graph::AddVertex(int VertIndex, int  Data){
	Vertex NewVert(VertIndex, Data);
	Vertices.push_back(NewVert);

	VertexCount++;
}


void Graph::AddVertexDirectedEdge(int From, int To ,int Weight){
	Vertex imsi = Vertices.at(From);
	imsi.AddEdge(To, Weight);
	Vertices.at(From) = imsi;
}

void Graph::PrintGraph(){
	cout << "Print Graph. VertexCount: " << VertexCount << endl;
	for(auto i = Vertices.begin(); i!= Vertices.end(); i++){
		(*i).PrintVertex();
	}
}
