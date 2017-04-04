#include <iostream>
#include <vector>

using namespace std;

int main(){
	int numArr[] = {2,4,6,8};

	for(int i: numArr){
		cout << i << " ";
	}
	cout << endl;
	
	vector<int> numvec;
	numvec.push_back(1);
	numvec.push_back(3);
	numvec.push_back(5);
	numvec.push_back(7);
	numvec.push_back(9);

	for(int i:numvec){
		cout << i << endl;
	}
	cout << endl;

	vector<string> strvec;
	strvec.push_back("a");
	strvec.push_back("b");
	strvec.push_back("c");
	strvec.push_back("d");
	for(auto i:strvec){
		cout << i << endl;
	}
	cout << endl;

	return 0;
}
