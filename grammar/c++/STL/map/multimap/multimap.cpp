#include <iostream>
#include <map>

using namespace std;


int main(){

	multimap<string, int> mm;
	
	//insert
	mm.insert(make_pair("A", 10));
	mm.insert(make_pair("B", 20));
	mm.insert(make_pair("C", 30));
	mm.insert(make_pair("D", 40));
	mm.insert(make_pair("E", 50));
	mm.insert(make_pair("C", 100));
	mm.insert(make_pair("C", 200));

	for (auto i = mm.begin(); i != mm.end(); ++i){
		cout << "[" << i-> first << " " << i->second << "]" ;
	}
	cout << endl;

	//search
	auto lo_bo = mm.lower_bound("C");
	auto up_bo = mm.upper_bound("C");
	cout << "values of Key C : " ;
	for (auto i = lo_bo; i!=up_bo; ++i){
		cout << i->second << " " ;
	}
	cout << endl;

	//search by range
	auto eq_ra = mm.equal_range("C");
	cout << "values of Key C by equal_range : " ;

	if(eq_ra.first != eq_ra.second){
		for(auto i = eq_ra.first; i!=eq_ra.second; ++i){
			cout << i->second << " ";
		}
	}else if (eq_ra.first == eq_ra.second){
		cout << "there is no data " ;
	}
	cout << endl;

	//erase data by key
	cout << "===== erase data ===== " << endl;
	mm.erase("C");
	for (auto i = mm.begin(); i != mm.end(); ++i){
		cout << "[" << i-> first << " " << i->second << "]" ;
	}
	cout << endl;


	//search fail case
	eq_ra = mm.equal_range("C");
	cout << "values of Key C by equal_range : " ;

	if(eq_ra.first != eq_ra.second){
		for(auto i = eq_ra.first; i!=eq_ra.second; ++i){
			cout << i->second << " ";
		}
	}else if (eq_ra.first == eq_ra.second){
		cout << "there is no data " ;
	}
	cout << endl;

	//clear multimap
	cout << "===== clear data ===== " << endl;
	mm.clear();
	mm.insert(make_pair("cleared", 1));
	for (auto i = mm.begin(); i != mm.end(); ++i){
		cout << "[" << i-> first << " " << i->second << "]" ;
	}
	cout << endl;

	return 0;
}
