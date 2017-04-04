#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;


class Graph{
	private :
		set<int> visitvertex;
		
	public:
		void BFS(int start, int target);
};


void Graph::BFS(int start, int destination){
	queue<pair<int, int> > Q;
	//pos, count

	visitvertex.insert(start);
	Q.push(make_pair(start,0));

	while(!Q.empty()){
		pair<int,int> pos = Q.front();
		if(pos.first == destination){
			cout << pos.second << endl;
			break;
		}

		int nextpos;
		int count;
		nextpos = pos.first +1;
		if(nextpos <= 100000){
			auto pr = visitvertex.insert(nextpos);
			if(pr.second == true){
				Q.push(make_pair(nextpos, pos.second+1));
			}
		}

		nextpos = pos.first -1;
		if(nextpos > 0){
			auto pr = visitvertex.insert(nextpos);
			if(pr.second == true){
				Q.push(make_pair(nextpos, pos.second+1));
			}
		}
		
		nextpos = pos.first*2;
		if(nextpos <= 100000){
			auto pr = visitvertex.insert(nextpos);
			if(pr.second == true){
				Q.push(make_pair(nextpos, pos.second+1));
			}
		}

		Q.pop();
	}
	
}

int main(){
	int N,K;
	cin >> N >> K ;

	Graph graph;
	graph.BFS(N,K);

	
	return 0;
}
