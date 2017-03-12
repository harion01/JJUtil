#include <iostream>
#include <map>

using namespace std;


int main(){

	map<string, int> m;

	//insert.
	/*
	return :The single element versions (1) return a pair, with its member pair::first set to an iterator pointing to either the newly inserted element 
	or to the element with an equivalent key in the map. 
	The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.
	*/
	auto iret = m.insert(make_pair("A",10));
	if(iret.second == true){
		cout << "insert success" << endl;
	}else if(iret.second == false){
		cout << "insert fail" << endl;
	}

	iret = m.insert(make_pair("B",20));
	if(iret.second == true){
		cout << "insert success" << endl;
	}else if(iret.second == false){
		cout << "insert fail" << endl;
	}
	iret = m.insert(make_pair("C",100)); 
	if(iret.second == true){
		cout << "insert success" << endl;
	}else if(iret.second == false){
		cout << "insert fail" << endl;
	}
	iret = m.insert(make_pair("C",200));
	if(iret.second == true){
		cout << "insert success" << endl;
	}else if(iret.second == false){
		cout << "insert fail" << endl;
	}

	m["d"] = 100;

	//print all element
	for(auto i = m.begin(); i != m.end(); ++i){
		cout << "[" << i->first << " " << i->second << "] ";
	}
	cout << endl;

	//find value with key
	auto i = m.find("A");
	if(i!=m.end()){
		cout << "first : " << i->first << "/second : " << i->second << endl;
	}else if (i==m.end()){
		cout << "find fail" << endl;

	}

	i = m.find("G");
	if(i!=m.end()){
		cout << "first : " << i->first << "/second : " << i->second << endl;
	}else if (i==m.end()){
		cout << "find fail" << endl;

	}


	return 0;
}
