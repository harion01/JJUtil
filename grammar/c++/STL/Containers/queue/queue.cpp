#include <iostream>
#include <queue>

/*
queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out), where elements are inserted into one end of the container and extracted from the other.

queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are pushed into the "back" of the specific container and popped from its "front".

The standard container classes deque and list fulfill these requirements. By default, if no container class is specified for a particular queue class instantiation, the standard container deque is used.

- http://www.cplusplus.com/reference/queue/queue/
*/

using namespace std;

int main(){
	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	//for(auto i= q.begin(); i!= q.end; i++){  //queue does not support iterator
	while(!q.empty()){
		cout << q.front() << " " ;
		q.pop();
	}
	cout << endl;
	
	return 0;
}

