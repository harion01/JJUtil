#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Multiplier{
	int first;
	int second;

	public:
		Multiplier(int f, int s):first(f),second(s){}
		int getResult(){
			return first*second;
		}
};


int main(){
	vector<Multiplier> multipleData;

	for(int i=0; i<10 ; i++){
		Multiplier mul = Multiplier(rand()%10, rand()%10);
		multipleData.push_back(mul);
	}

	cout << "unsorted data " << endl;
	for(auto iter = multipleData.begin(); iter != multipleData.end(); iter++){
		cout << iter->getResult() << " " ;
	}
	cout << endl;

	sort(multipleData.begin(), multipleData.end(), 
		[](Multiplier& m1, Multiplier& m2){  //define lambda function
			return m1.getResult() < m2.getResult();
		} );

	cout << "sourted data " << endl;
	for(auto iter = multipleData.begin(); iter != multipleData.end(); iter++){
		cout << iter->getResult() << " " ;
	}
	cout << endl;

	return 0;
}
