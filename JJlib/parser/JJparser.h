#ifndef JJPARSER_HEAD
#define JJPARSER_HEAD

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class JJparser{
	
	private :
		vector<char> numbers;
		bool IsNumber(char Cipher);

	public : 
		JJparser();
		~JJparser();
		string getToken(string s, int startpos, string delim, int* nextpos);
		//string padding(); // fill string 
		string removeall(string s, string delim); // remove specific delimetor from original string
		string removeL(string s, string delim);
		string removeR(string s, string delim);

		vector<string> parseMathExpression(string exptrssion);
		vector<string> parse(string s, string delim);

};


#endif
