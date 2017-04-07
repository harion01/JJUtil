#ifndef JJPARSER_HEAD
#define JJPARSER_HEAD

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class JJparser{
	
	private :

	public : 
		string getToken(string s, int startpos, string delim, int* nextpos);
		//string padding(); // fill string 
		string removeall(string s, string delim); // remove specific delimetor from original string
		string removeL(string s, string delim);
		string removeR(string s, string delim);

		vector<string> parse(string s, string delim);

};


#endif
