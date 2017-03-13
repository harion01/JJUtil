#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
	
	//default
	cout << " === unordered_multiset<int> s === " << endl;
	unordered_multiset<int> s;
	s.insert(10);
	s.insert(30);
	s.insert(60);
	s.insert(20);
	s.insert(50);
	//ret check of insert
	//pair<multiset<int>::iterator, bool>pr : return type of multiset::insert()
	s.insert(40);
	s.insert(40);
	s.insert(40);
	s.insert(40);



	//find data
	auto ret = s.find(40);
	if(ret!=s.end()){
		cout << "find data[" << *ret << "]" << endl;
	}else{
		cout << "find fail" << endl;
	}

	//count of found data
	cout << "count of 40 in multiset [" << s.count(40) << "]" << endl;
	

	ret = s.find(100);
	if(ret!=s.end()){
		cout << "find data[" << *ret << "]" << endl;
	}else{
		cout << "find 100 fail" << endl;
	}

	//erase data
	cout << "erase(30)" << endl;
	s.erase(30);
	for(auto i = s.begin(); i!=s.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;

	cout << "clear multiset" << endl;

	//clear multiset
	s.clear();

	for(auto i = s.begin(); i!=s.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;


	return 0;
}
