#include <iostream>

using namespace std;

class Chulsoo{
	public:
		void Eat(int SteakWeight);
		inline void EatInline(int SeakWeight);

};

void Chulsoo::Eat(int SteakWeight){
	cout << "Eat() :: chulsoo eat " << SteakWeight << " g steak" << endl;
}


inline void Chulsoo::EatInline(int SteakWeight){
	cout << "EatInline() :: chulsoo eat " << SteakWeight << " g steak" << endl;
}

int main(void){
	Chulsoo chulsoo;
	chulsoo.Eat(500);
	chulsoo.EatInline(500);
	[] (int steakWeight){
		cout << "EatLambda() :: chulsoo eat " << steakWeight << " g steak" << endl;
		return 0;
	}(1000);
	return 0;
}

