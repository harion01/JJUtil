#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(20, "AA"));
	v.push_back(pair<int, string>(30, "BZ"));
	v.push_back(pair<int, string>(30, "BA"));
	v.push_back(pair<int, string>(40, "GA"));
	v.push_back(pair<int, string>(40, "DA"));
	
	//sort by first element of pair. when first values are same, sort by second value
	sort(v.begin(), v.end());
	for(int i = 0; i<v.size(); i++)
		cout << v[i].first << ", " << v[i].second << endl;

	return 0;
}
