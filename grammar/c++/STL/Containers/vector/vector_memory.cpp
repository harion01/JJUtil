#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<int> v(6,1);
	
	//vector.capacity() : Return size of allocated storage capacity
	//vector.size() : Returns the number of elements in the vector.
	cout << " === initalzie - v(6,1) === " << endl;
	cout << "v.capacity() : " << v.capacity() << " // v.size() : " << v.size() << endl; 
	for(int i = 0; i < v.size(); i++){
		cout << "v[" << i << "] : " << v[i] << endl;
	}

	cout << " === reassign : v.assign(4,3) === " << endl;
	v.assign(4,3);
	cout << "v.capacity() : " << v.capacity() << " // v.size() : " << v.size() << endl; 
	for(int i = 0; i < v.size(); i++){
		cout << "v[" << i << "] : " << v[i] << endl;
	}

 	//dangerous code
	cout << " check value based on capacity" << endl;
	for(int i = 0; i < v.capacity(); i++){
		cout << "v[" << i << "] : " << v[i] << endl;
	}
	////

	cout << "push 10,20 and check " << endl;
	v.push_back(10);
	v.push_back(20);
	cout << "v.capacity() : " << v.capacity() << " // v.size() : " << v.size() << endl; 
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << "value : " << *it << endl;
	}

	cout << "push 30 and check " << endl;
	v.push_back(30);
	cout << "v.capacity() : " << v.capacity() << " // v.size() : " << v.size() << endl; 
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << "value : " << *it << endl;
	}

 	//dangerous code
	cout << " check value based on capacity" << endl;
	for(int i = 0; i < v.capacity(); i++){
		cout << "v[" << i << "] : " << v[i] << endl;
	}
	////

	cout << "resize vector into 17" << endl;
	v.resize(17);
	cout << "v.capacity() : " << v.capacity() << " // v.size() : " << v.size() << endl; 
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << "value : " << *it << endl;
	}

	return 0;
}
