#ifndef CPP_GRAPH
#define CPP_GRAPH
#include <iostream>
#include <vector>
#include <deque>

using namespace std;


class Vertex{
	private:

	public:
		int Data;
		bool isVisited;
		int Index;
		//Form current vertex to vertex(pair fist), with weight value (pair second)
		vector<pair<int,int>> AdjacencyVector; 
		
		Vertex(int index, int data);
		~Vertex();

		void AddEdge(int To, int Weight);
		void PrintVertex();
};

class Graph{
	public:
		int VertexCount;
		vector<Vertex> Vertices;

		Graph();
		~Graph();

		void AddVertex(int VertIndex, int Data);
		void AddVertexDirectedEdge(int From, int To, int Weight);

		void PrintGraph();
};

#endif
