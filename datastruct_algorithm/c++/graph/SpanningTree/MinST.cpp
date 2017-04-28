
#include <iostream>
#include <priority_queue>
#include <vector>

struct vertex{
	private :

	public :
		int index;
		bool isVisited;
		vector<pair<int, int> > edges;
};

struct primvertex{
	private:
	public:
		int index;
		int fromVertex;
		int weight;
		bool operator()(struct primvertex1, struct primvertex2){
			return primvertex1.weight < primvertex2.weight ;
		}
}

class Graph{
	private:
		vector<vertex> graph;
		vector<vertex> MST;
		priority_queue<primvertex, vector<primvertex> , primvertex> primQ;
	public:
		Graph(int vertexlimit);
		void addEdge(int from, int to, int weight);
		void MakePrimMST(int startindex);
};


Graph::Graph(int vertexlimit){
	vertex dummy;
	dummy.isVisited = false;
	for(int i = 0; i<vertexlimit; i++){
		dummy.index = i;
		graph.push_back(dummy);
	}
}

void Graph::addEdge(int from, int to, int weight){
	graph[from].edges.push_back(make_pair(to, weight));
}

void Graph::MakePrimMST(int startindex){
	for(int i =0; i < graph.size(); i++){
		primvertex dummy;
		dummy.index = i;
		dummy.fromVertex = 0;
		dummy.weight = 99999999;
		primQ.push(dummy);
	}

	primvertex start;
	start.index = startindex;
	start.fromVertex = startindex;
	start.weight = 0;
	primQ.push(start);

	for(auto i: primQ){
		cout << i.index << " " << i.fromVertex << " " << i.weight << endl;

	}

}



int main(void){

	
	return 0;
}

