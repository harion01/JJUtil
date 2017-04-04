#include <iostream>
#include <deque>

using namespace std;

/*
deque (usually pronounced like "deck") is an irregular acronym of double-ended queue. Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).

it provide a functionality similar to vectors, but with efficient insertion and deletion of elements also at the beginning of the sequence, and not only at its end. But, unlike vectors, deques are not guaranteed to store all its elements in contiguous storage locations: accessing elements in a deque by offsetting a pointer to another element causes undefined behavior.

Both vectors and deques provide a very similar interface and can be used for similar purposes, but internally both work in quite different ways: While vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage, with the container keeping the necessary information internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators). 

Therefore, deques are a little more complex internally than vectors, but this allows them to grow more efficiently under certain circumstances, especially with very long sequences, where reallocations become more expensive.
*/

int main(){

	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	
	int c=0;
	for(deque<int>::iterator it = dq.begin() ; it != dq.end() ; it++){
		cout << "dq["<< c << "] : " << *it << endl;
		c++;
	}

	cout << "push front test" << endl;
	dq.push_front(-10);
	dq.push_front(-20);
	c = 0;
	for(deque<int>::iterator it = dq.begin() ; it != dq.end() ; it++){
		cout << "dq["<< c << "] : " << *it << endl;
		c++;
	}


	cout << "insert test " << endl;
	deque<int> insertq;
	dq.insert(dq.begin()+2, 0);
	dq.insert(dq.begin()+2, 0);
	c =0;
	for(auto i : dq){
		cout << i << " ";
	}
	cout << endl;

	cout << "pop test" << endl;
	int ret=0;
	ret = dq.back();
	cout << "bcck : " << ret << endl;
	dq.pop_back(); //remove last item
	ret = dq.back();
	cout << "after pop_bcck : " << ret << endl;

	ret = dq.front();
	cout << "front : " << ret << endl;
	dq.pop_front(); //remove first item
	ret = dq.front();
	cout << "after pop_front : " << ret << endl;

	dq.pop_front();
	dq.pop_front();



	//dangerous code
	ret = dq.front();
	////
	cout << "is there item in deque? " << endl;
	for(deque<int>::iterator it = dq.begin() ; it != dq.end() ; it++){
		cout << "dq["<< c << "] : " << *it << endl;
		c++;
	}
	cout << "ret of front for empty deque : " << ret << endl;

	//safe code
	if(0!=dq.size() ){
		ret = dq.front();
	}else{
		cout << "dq empty! " << endl;
		ret = -1;
	}
	cout << "ret of front for empty deque : " << ret << endl;


	return 0;
}
