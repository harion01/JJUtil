#include <iostream>
using namespace std;

class Chulsoo{
	private :
		int age;
	public :
		Chulsoo(int age);
		Chulsoo();
		Chulsoo(const Chulsoo& source);
		~Chulsoo();
		void introduce();
		
		Chulsoo returnConstructor();
};

Chulsoo::Chulsoo(int age) : age(age){
	cout << "+++ Chulsoo::Chulsoo(age) constructor done +++" << endl;
}

Chulsoo::Chulsoo(){
	cout << "+++ Chulsoo::Chulsoo() constructor done +++" << endl;
}

Chulsoo::Chulsoo(const Chulsoo& source) : age(source.age){
	cout << "+++  Chulsoo::Chulsoo(const Chulsoo& source) copyconstructor call +++" << endl;

}

Chulsoo::~Chulsoo(){
	cout << "+++ Chulsoo::~Chulsoo() destructor done +++" << endl;
}

void Chulsoo::introduce(){
	cout << "age : " << this->age << endl;
}
	

Chulsoo Chulsoo::returnConstructor(){
	cout << "returnConstructor function call" << endl;
	Chulsoo chulsoo2(100);
	return chulsoo2;
}

int main(void){
	Chulsoo chulsoo1(32);
	cout << "check before returnConstructor call " << endl;
	Chulsoo chulsoo2 = chulsoo1.returnConstructor();
//	chulsoo1.returnConstructor();
	cout << "check after returnConstructor call " << endl;
	chulsoo1.introduce();
	chulsoo2.introduce();
	return 0;
}
