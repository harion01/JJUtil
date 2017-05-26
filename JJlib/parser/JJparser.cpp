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
JJparser::JJparser(){
	numbers.push_back('0');
	numbers.push_back('1');
	numbers.push_back('2');
	numbers.push_back('3');
	numbers.push_back('4');
	numbers.push_back('5');
	numbers.push_back('6');
	numbers.push_back('7');
	numbers.push_back('8');
	numbers.push_back('9');
	numbers.push_back('.');
}

JJparser::~JJparser(){

}


bool JJparser::IsNumber(char Cipher){
	//cout << "check : " << Cipher << endl;
	for(auto i:numbers){
		if(Cipher == i){
			return true;
		}
	}
	return false;
}

vector<string> JJparser::parseMathExpression(string Expression){
	vector <string>ret;
	int pos = 0;
	string token;

	for(int checkpos = 0; (unsigned int)checkpos < Expression.length(); checkpos++){
		if(!IsNumber(Expression[checkpos])){
			//parse number - operator between operator
			if(pos != checkpos){
				token = Expression.substr(pos, checkpos-pos);
				//cout << "number token : " << token << endl;
				ret.push_back(token);
			}
			
			//parse operator - one char
			if(Expression.compare(checkpos,1," ") != 0){
				string ch(1,Expression[checkpos]);
				//cout << "operator token : " << ch << endl;
				ret.push_back(ch);
			}
			pos = checkpos+1;
		}
	}

	//check if last one is not operator
	if((unsigned int)pos != Expression.length()){
		token = Expression.substr(pos,Expression.length()-pos);
		ret.push_back(token);
	}


	return ret;
}


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

//find data from file
bool JJparser::findFromFile(const char* keyNdelim, const char* path, string& retstr){
	bool ret = false;
	string strbuf;
	string key = keyNdelim;
	ifstream filedata(path);

	while(getline(filedata, strbuf)){
		//cout << strbuf << endl;
		string::size_type pos = strbuf.find(key);
		if(pos != string::npos){
			retstr = strbuf.substr(pos+key.size(), strbuf.size());
			ret = true;
			break;
		}
		strbuf.clear();
	}

	filedata.close();
	return ret;
}


