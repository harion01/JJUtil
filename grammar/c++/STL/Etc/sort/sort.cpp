#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v;
	v.push_back(40);
	v.push_back(10);
	v.push_back(20);
	v.push_back(50);
	v.push_back(30);
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;

	list<int> lt;
	lt.push_back(40);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(10);
	lt.push_back(50);
	for(int i : lt){
		cout << i << " " ;
	}
	cout << endl;

	//sort(v.begin(), v.end(), less<int>());
	sort(v.begin(), v.end(), greater<int>());
	for(int i : v){
		cout << i << " " ;
	}
	cout << endl;

	//sort(lt.begin(), lt.end(), greater<int>());  //only deque and vector can be used as arguments
	
	return 0;
}
