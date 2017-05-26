#include "JJparser.h"

using namespace std;

int main(){

	
	string s = "test is bad test is good";
	string delim = "is";

	JJparser JJ;

	//test config path /home/jjlee/git/JJlib/parser/config.test
	/*
	testkey=testvalue

	testkey=tet

	ttt = 123

	123 = ttt
	*/
	string value;
	
	if(JJ.findFromFile("testkey=", "/home/jjlee/git/JJlib/parser/config.test", value)){
		cout << "data found! value [" << value << "]" << endl;
	}else{
		cout << "no data" << endl;
	}

	if(JJ.findFromFile("ttt = ", "/home/jjlee/git/JJlib/parser/config.test", value)){
		cout << "data found! value [" << value << "]" << endl;
	}else{
		cout << "no data" << endl;
	}

	if(JJ.findFromFile("nodatanono", "/home/jjlee/git/JJlib/parser/config.test", value)){
		cout << "data found! value [" << value << "]" << endl;
	}else{
		cout << "no data" << endl;
	}

	/*
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

	cout <<  JJ.removeall(s, " ") << endl;
	cout << JJ.removeL(s, "test is") << endl;
	cout << JJ.removeR(s, "is good") << endl;

	cout << "Math : Inexpression parse - (1+2)+34+56 * 78 / 90 " << endl;
	string inexpression = "(1+2)+34+56 * 78 / 90";
	vector<string> math = JJ.parseMathExpression(inexpression);
	for(auto i:math){
		cout << "[" <<  i  << "]" <<endl;
	}
	
	cout << "Math : Postexpression parse - 117.32 83 + 49*" << endl;
	math.clear();
	string postexpression = "117.32 83 + 49*";
	math = JJ.parseMathExpression(postexpression);
	for(auto i:math){
		cout << "[" <<  i  << "]" <<endl;
	}




	*/
	return 0;
}
