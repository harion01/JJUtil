#include <iostream>
#include <set>

using namespace std;

int main(){
	
	//default
	cout << " === set<int> s === " << endl;
	set<int> s;
	s.insert(10);
	s.insert(30);
	s.insert(60);
	s.insert(20);
	s.insert(50);
	//ret check of insert
	//pair<set<int>::iterator, bool>pr : return type of set::insert()
	auto pr = s.insert(40);
	if(pr.second == true){
		cout << " insert(40) success " << endl;
	}else if(pr.second == false){
		cout << " insert fail" << endl;
	}

	pr = s.insert(40);
	if(pr.second == true){
		cout << " insert success " << endl;
	}else if(pr.second == false){
		cout << " insert(40) fail" << endl;
	}

	for(auto i = s.begin(); i!=s.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;


	//find data
	auto ret = s.find(30);
	if(ret!=s.end()){
		cout << "find data[" << *ret << "]" << endl;
	}else{
		cout << "find fail" << endl;
	}

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

	cout << "clear set" << endl;

	//clear set
	s.clear();

	for(auto i = s.begin(); i!=s.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;


	cout << " === set<int, greater<int>> s2 : descending order === " << endl;
	set<int, greater<int>> s2;
	s2.insert(10);
	s2.insert(30);
	s2.insert(60);
	s2.insert(20);
	s2.insert(50);

	for(auto i = s2.begin(); i!=s2.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;

	cout << " === set<int, less<int>> s3 : ascending order === " << endl;
	set<int, less<int>> s3;
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
	set<int, greater<int>> s4(s3.begin(), s3.end()); //you have to define new set

	for(auto i = s4.begin(); i!=s4.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;

	return 0;
}
