#include <iostream>
#include <vector>

using namespace std;

/*
Vectors are sequence containers representing arrays that can change in size.

Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

good:
Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end. For operations that involve inserting or removing elements at positions other than the end, they perform worse than the others, and have less consistent iterators and references than lists and forward_lists.

bad:
Instead, vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size). Libraries can implement different strategies for growth to balance between memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual elements at the end of the vector can be provided with amortized constant time complexity (see push_back).

- http://www.cplusplus.com/reference/vector/vector/
*/


int main(){
	vector<int> v;
	
	v.push_back(10);
	v.push_back(20);

	cout << "V[0] : " << v[0] << endl;
	cout << "V.at(0) : " << v.at(0) << endl;

	cout << "V[1] : " << v[1] << endl;
	cout << "V.at(1) : " << v.at(1) << endl;

	cout << "V[2] : " << v[2] << endl; //run time error will not occur. but not a right code
	//cout << "V.at(2) : " << v.at(2) << endl; //run time error will occur. at(2) is out of range

	// initialize
	cout << " ========== initailize ===============" << endl;
	vector<int> v2(5); //initialize vector size as 5 and set them into 0
	v2.push_back(10);  //allocate memory and set value 10. add that memory space into end of v2
	v2.push_back(20);  //allocate memory and set value 20. add that memory space into end of v2

	vector<int> v3(5,3); //initialize vector size as 5 and set them into 3
	v3.push_back(10);  //allocate memory and set value 10. add that memory space into end of v3
	v3.push_back(20);  //allocate memory and set value 20. add that memory space into end of v3

	// roop
	cout << " ========== size check and roop ==============" << endl;
	cout << " size of v2 - v2.size()  : " << v2.size() << endl;
	for(int i=0; i<v2.size(); i++){
		cout << "v2["<<i<<"] : " << v2[i] << endl;
	}

	cout << " size of v3 - v3.size()  : " << v3.size() << endl;
	for(int i=0; i<v3.size(); i++){
		cout << "v3["<<i<<"] : " << v3[i] << endl;
	}

	//swap
	v2.swap(v3);
	cout << " ========== swap check ==============" << endl;
	cout << " size of v2 - v2.size()  : " << v2.size() << endl;
	for(int i=0; i<v2.size(); i++){
		cout << "v2["<<i<<"] : " << v2[i] << endl;
	}

	cout << " size of v3 - v3.size()  : " << v3.size() << endl;
	for(int i=0; i<v3.size(); i++){
		cout << "v3["<<i<<"] : " << v3[i] << endl;
	}

	// reassign
	cout << "=== re assaign ===" << endl;
	v3.assign(4,1); //change total size of v3 to 4 and set data as 1
	for(int i=0; i<v3.size(); i++){
		cout << "v3["<<i<<"] : " << v3[i] << endl;
	}
	
	cout << "change v3[2] : 2 " << endl;
	v3[2] = 2;
	for(int i=0; i<v3.size(); i++){
		cout << "v3["<<i<<"] : " << v3[i] << endl;
	}

	//iterator
	cout << "use iterator " << endl;
	for(vector<int>::iterator it = v3.begin(); it != v3.end(); it++){
		cout << "value : " << *it << endl;
	}

	cout << "change value by iterator" << endl;
	int val = 0;
	for(vector<int>::iterator it = v3.begin(); it != v3.end(); it++){
		cout << "value : " << *it << endl;
		*it = val;
		cout << "changed value : " << *it << endl;
		val++;
	}

	cout << "==== check by iterator " << endl;
	for(vector<int>::iterator it = v3.begin(); it != v3.end(); it++){
		cout << "value : " << *it << endl;
	}
	cout <<"==== check by reverse_iterator " << endl;
	for(vector<int>::reverse_iterator it = v3.rbegin(); it != v3.rend(); it++){
		cout << "value : " << *it << endl;
	}


	cout << "==== check by by []" << endl;
	for(int i=0; i<v3.size(); i++){
		cout << "v3["<<i<<"] : " << v3[i] << endl;
	}

	//const iterator
	cout << "==== iterator & const_iterator ===" << endl;
	vector<int>::iterator iter = v.begin();
	vector<int>::const_iterator citer = v2.begin();

	*iter = 100;
	//*citer = 100; //const iterator can not change value

	cout << "*iter :" << *iter << endl;
	cout << "*const_iter :" << *citer << endl;

	//insert test
	cout << "==== insert test ===" << endl;
	vector<int> inv(5,1);
	vector<int>::iterator idx = inv.begin() +2;
	inv.insert(idx, 3, 100); //insert 100, 100, 100 to idx potision of inv
	for(auto i : inv){
		cout << i << " " ;
	}
	cout << endl;

	vector<int> inv2(2,200);
	idx = inv.begin()+1;
	inv.insert(idx, inv2.begin(), inv2.end()); //insert inv2 to inv at idx potision
	for(auto i : inv){
		cout << i << " " ;
	}
	cout << endl;
	
	//erase test
	cout << "==== erase test ===" << endl;
	idx = inv.begin();
	inv.erase(idx);
	for(auto i : inv){
		cout << i << " " ;
	}
	cout << endl;

	inv.erase(inv.begin()+3, inv.end());
	inv.erase(idx);
	for(auto i : inv){
		cout << i << " " ;
	}
	cout << endl;

	return 0;
}
