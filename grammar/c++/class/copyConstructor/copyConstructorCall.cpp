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

		void copyConstructorCall(Chulsoo chulsooObj1);
};

Chulsoo::Chulsoo(int age) : age(age){
	cout << "+++ Chulsoo::Chulsoo(age) constructor done +++" << endl;
}

Chulsoo::Chulsoo(){
	cout << "+++ Chulsoo::Chulsoo() constructor done +++" << endl;
}

Chulsoo::Chulsoo(const Chulsoo& source): age(source.age){
	cout << "+++  Chulsoo::Chulsoo(const Chulsoo& source) copyconstructor call +++" << endl;

}

Chulsoo::~Chulsoo(){
	cout << "+++ Chulsoo::~Chulsoo() destructor done +++" << endl;
}

void Chulsoo::introduce(){
	cout << "age : " << this->age << endl;
}
	
void Chulsoo::copyConstructorCall(Chulsoo chulsooObj1){  //"Chulsoo chulsooObj1"  sentence will call  "Chulsoo(const Chulsoo& source);"
	cout << "Chulsoo::copyConstructorCall done" << endl;

	//at this point, local object chulsooObj1 will be freed. thus, destructor of chulsooObj1 will occr.
}

int main(void){
	Chulsoo chulsoo1(32);
	cout << "check before copyConstructorCall " << endl;
	chulsoo1.copyConstructorCall(chulsoo1);
	cout << "check after copyConstructorCall " << endl;

	return 0;
}
