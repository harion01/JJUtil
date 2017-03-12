#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
	unordered_multimap<string, int> um;
	//insert data
	um.insert({"A", 100});
	um.insert({{"C", 1000},{"D",2000}});
	um.insert(make_pair("B", 200));

	um.insert({"E", 10});
	um.insert({"E", 10});
	um.insert({"E", 20});

	//print data
	for(auto i = um.begin(); i!=um.end();++i){
		cout << "[" << i->first << " " << i->second << "] " ;
	}
	cout << endl;

	//find data
	cout << "=== data find ===" << endl;
	cout << "values of Key E by equal_range : " ;

	auto eq_ra = um.equal_range("E");
	if(eq_ra.first != eq_ra.second){
		for(auto i = eq_ra.first; i!=eq_ra.second; ++i){
			cout << i->second << " ";
		}
	}else if (eq_ra.first == eq_ra.second){
		cout << "there is no data " ;
	}
	cout << endl;


	cout << "values of Key Z by equal_range : " ;
	eq_ra = um.equal_range("Z");
	if(eq_ra.first != eq_ra.second){
		for(auto i = eq_ra.first; i!=eq_ra.second; ++i){
			cout << i->second << " ";
		}
	}else if (eq_ra.first == eq_ra.second){
		cout << "there is no data " ;
	}
	cout << endl;



	//erase data
	cout << "=== erase data E ===" << endl;
	um.erase("E");
	for(auto i = um.begin(); i!=um.end();++i){
		cout << "[" << i->first << " " << i->second << "] " ;
	}
	cout << endl;
	return 0;
}
