#include <iostream>
#include <set>

using namespace std;

int main(){
	
	//default
	cout << " === multiset<int> s === " << endl;
	multiset<int> s;
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


	cout << " === multiset<int, greater<int>> s2 : descending order === " << endl;
	multiset<int, greater<int>> s2;
	s2.insert(10);
	s2.insert(30);
	s2.insert(60);
	s2.insert(20);
	s2.insert(50);

	for(auto i = s2.begin(); i!=s2.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;

	cout << " === multiset<int, less<int>> s3 : ascending order === " << endl;
	multiset<int, less<int>> s3;
	s3.insert(10);
	s3.insert(30);
	s3.insert(60);
	s3.insert(20);
	s3.insert(50);

	for(auto i = s3.begin(); i!=s3.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;

	cout << " === swap (change ordering) === " << endl;
	multiset<int, greater<int>> s4(s3.begin(), s3.end()); //you have to define new multiset

	for(auto i = s4.begin(); i!=s4.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;

	return 0;
}
