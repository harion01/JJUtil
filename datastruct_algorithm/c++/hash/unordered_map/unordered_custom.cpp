#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Key
{
	std::string first;
	std::string second;
	int         third;

	bool operator==(const Key &other) const
	{ return (first == other.first
			&& second == other.second
			&& third == other.third);
	}
};


struct KeyHasher{
	std::size_t operator()(const Key& k) const{
		using std::size_t;
		using std::hash;
		using std::string;
		
		return ((hash<string>()(k.first) 
			^ (hash<string>()(k.second) << 1)) >>1)
			^ (hash<int>()(k.third) << 1);
	}
};

int main(void){
	std::unordered_map<Key,std::string,KeyHasher> test = {
		{ {"John", "Doe", 12}, "example"},
		{ {"Mary", "Sue", 21}, "another"}
	};
	
	struct Key key;
	key = {"Mary", "Sue", 21};

	auto ret = test.find(key);
	if(ret != test.end()){
		cout << "["<< ret->first.first << "/" << ret->first.second <<":" << ret->second << "]" ;
	}else {
		cout << "data find fail" << endl;
	}
	cout << endl;


	return 0;
}

