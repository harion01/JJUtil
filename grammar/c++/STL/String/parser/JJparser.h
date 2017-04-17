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
		string padding(); // fill string 
		string remove(); // remove specific delimetor from original string

		template<typename Out>
		void parse(const string& s, string delim, Out result);
		vector<string> parse(string s, string delim);

};


#endif
