#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
	unordered_map<string, int> um;
	//insert data
	um.insert({"A", 100});
	um.insert({{"C", 1000},{"D",2000}});
	um.insert(make_pair("B", 200));

	auto check = um.insert({"E", 10});
	if(check.second==true){
		cout << "insert E success " << endl;
	}else if (check.second==false){
		cout << "insert fail " << endl;
	}

	check = um.insert({"E", 10});
	if(check.second==true){
		cout << "insert E success " << endl;
	}else if (check.second==false){
		cout << "insert fail " << endl;
	}

	//print data
	for(auto i = um.begin(); i!=um.end();++i){
		cout << "[" << i->first << " " << i->second << "] " ;
	}
	cout << endl;

	//find data
	cout << "=== data find ===" << endl;
	auto ret = um.find("B");
	if(ret != um.end()){
		cout << "["<< ret->first << ": " << ret->second << "]" ; 
	}else {
		cout << "data find fail" << endl;
	}
	cout << endl;
	
	ret = um.find("Z");
	if(ret != um.end()){
		cout << "["<< ret->first << ": " << ret->second << "]" ; 
	}else {
		cout << "data find fail" << endl;
	}
	cout << endl;

	//erase data
	cout << "=== erase data A ===" << endl;
	um.erase("A");
	for(auto i = um.begin(); i!=um.end();++i){
		cout << "[" << i->first << " " << i->second << "] " ;
	}
	cout << endl;
	return 0;
}
