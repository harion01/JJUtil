#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main(void){
	priority_queue<int> pq1;
	pq1.push(40);
	pq1.push(20);
	pq1.push(30);
	pq1.push(50);
	pq1.push(10);

	cout << "pq[less] " << endl;
	while(!pq1.empty()){
		cout << pq1.top() << endl;
		pq1.pop();
	}

	cout << "===========" << endl;

	priority_queue<int, deque<int>, greater<int> > pq2;
	pq2.push(40);
	pq2.push(20);
	pq2.push(30);
	pq2.push(50);
	pq2.push(10);

	cout << "pq[greater] " << endl;
	while(!pq2.empty()){
		cout << pq2.top() << endl;
		pq2.pop();
	}

	cout << "===========" << endl;

	return 0;
}
