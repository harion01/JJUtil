#include <iostream>
#include <deque>

using namespace std;

int main(){

	
	deque<string> dq;

	dq.push_back("abc");
	dq.push_back("ABC");
	dq.push_back("def");
	dq.push_back("DEF");

	for(deque<string>::iterator it = dq.begin(); it!= dq.end() ; it++){
		cout << *it << endl;
	}

	return 0;
}
