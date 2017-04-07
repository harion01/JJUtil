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

string JJparser::removeL(string s, string delim){
	string ret;
	if(s.compare(0,delim.length(),delim)==0){
		ret.append(s.substr(delim.length(),s.length()));
	}
	
	return ret;
}

string JJparser::removeR(string s, string delim){
	string ret;
	if(s.compare(s.length()-delim.length(), delim.length(), delim)==0){
		ret.append(s.substr(0,s.length()-delim.length()));
	}
	
	return ret;
}


string JJparser::removeall(string s, string delim){
	string ret;
	int startpos = 0;
	size_t pos = s.find(delim, startpos);
	while(pos != string::npos){
		cout <<"startpos: " << startpos << " pos : " << pos << endl;
		ret.append(s.substr(startpos, pos-startpos));
		startpos = (int)pos+delim.length();
		pos = s.find(delim, startpos);
	}
	if(startpos > 0){
		ret.append(s.substr(startpos));
	}
	
	return ret;
}


string JJparser::getToken(string s, int startpos, string delim, int* nextpos){
	string ret = "";
	size_t pos = s.find(delim, startpos);
	if(pos == string::npos){
		*nextpos = -1;
		return ret;
	}
	//cout <<"startpos: " << startpos << " pos : " << pos << endl;
	ret = s.substr(startpos, pos-startpos);
	*nextpos = (int)pos+delim.length();
	return ret;
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


