#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<char> v;
	v.push_back('c');
	v.push_back('b');
	v.push_back('d');
	v.push_back('a');

	sort(v.begin(), v.end());

	for(int i = 0; i < 4; i++){
		cout << v[i] << endl;
	}

	return 0;
}
