#include "JJparser.h"

using namespace std;

int main(){


	string s = "test is bad test is good";
	string delim = "is";

	JJparser JJ;
	int next = 0;
	cout << "[" <<  JJ.getToken(s,0, delim,&next) << "]"<< endl;
	cout << "next : " << next << endl;
	cout << "[" <<  JJ.getToken(s,next, delim,&next) << "]"<< endl;


	next = 0;
	string delim2 = " ";
	cout << "[" <<  JJ.getToken(s,0, delim2,&next) << "]"<< endl;
	cout << "next : " << next << endl;
	cout << "[" <<  JJ.getToken(s,next, delim2,&next) << "]"<< endl;


	next = 0;
	string delim3 = "noway";
	cout << "[" <<  JJ.getToken(s,0, delim3,&next) << "]"<< endl;
	cout << "next : " << next << endl;

	vector<string> parse;
	parse = JJ.parse(s, " ");

	for(auto i:parse){
		cout << "[" <<  i  << "]" <<endl;
	}

	return 0;
}
