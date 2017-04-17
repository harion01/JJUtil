#include "JJparser.h"
/*
class JJparser(){
	
	private :

	public : 
		template<typename Out>
		string split(const string& s, string delim);

		void parse(const string& s, string delim, Out result);
		vector<string> parse(const string& s, string delim);
		


};
*/

string JJparser::getToken(string s, int startpos, string delim, int* nextpos){
	string ret = "";
	size_t pos = s.find(delim, startpos);
	if(pos == string::npos){
		*nextpos = -1;
		return ret;
	}
	cout <<"startpos: " << startpos << " pos : " << pos << endl;
	ret = s.substr(startpos, pos-startpos);
	*nextpos = (int)pos+delim.length();
	return ret;
}


template<typename Out>
void JJparser::parse(const string& s, string delim, Out result){
	stringstream ss;
	ss.str(s);
	string token;

}



vector<string> JJparser::parse(string s, string delim){
	vector<string> ret;
	string token;
	int pos = 0;
	int next = 0;
	while(true){
		pos = next;
		token = getToken(s, pos, delim, &next);
		if(next < 0){
			if(pos > 0){
				token = s.substr(pos);
				ret.push_back(token);
			}
			break;
		}
		ret.push_back(token);
	}
	
	return ret;
}


