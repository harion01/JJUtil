#include <iostream>
#include <list>

using namespace std;

/*
Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.

List containers are implemented as doubly-linked lists; Doubly linked lists can store each of the elements they contain in different and unrelated storage locations. The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.

good:
Compared to other base standard sequence containers (array, vector and deque), lists perform generally better in inserting, extracting and moving elements in any position within the container for which an iterator has already been obtained, and therefore also in algorithms that make intensive use of these, like sorting algorithms.

bad:
The main drawback of lists and forward_lists compared to these other sequence containers is that they lack direct access to the elements by their position; For example, to access the sixth element in a list, one has to iterate from a known position (like the beginning or the end) to that position, which takes linear time in the distance between these. They also consume some extra memory to keep the linking information associated to each element (which may be an important factor for large lists of small-sized elements).


- http://www.cplusplus.com/reference/list/list/
*/


int main(){
	list<int> lt;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	lt.push_front(-10);
	lt.push_front(-20);
	lt.push_front(-30);

	for(auto i = lt.begin(); i != lt.end(); i++){
		cout << *i << " " ;
	}
	cout << endl;
	
	for(auto p = lt.begin(); p != lt.end(); p++){
		if(*p == 10){
			//The container is extended by inserting new elements before the element at the specified position.
			lt.insert(p,0); //use iterator p as position
			break;
		}
	}
	
	cout << "========= after insert 0 ==============" << endl;
	for(auto i = lt.begin(); i != lt.end(); i++){
		cout << *i << " " ;
	}
	cout << endl;

	
	cout << "========= splice test  ==============" << endl;
	list<int> lt2;
	for(auto i = 1; i<10; i++){
		lt2.push_back(i);
	}

	for(auto i = lt2.begin(); i != lt2.end(); i++){
		cout << *i << " " ;
	}
	cout << endl;

	cout << "========= splice  ==============" << endl;
	for(auto p = lt.begin(); p != lt.end(); p++){
		if(*p == 10){
			//Transfers elements from x into the container, inserting them at position.
			lt.splice(p,lt2);
			break;
		}
	}

	for(auto i = lt.begin(); i != lt.end(); i++){
		cout << *i << " " ;
	}
	cout << endl;

	return 0;
}
