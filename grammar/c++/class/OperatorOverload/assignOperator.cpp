#include <iostream>
using namespace std;

class Chulsoo{
	private :
		int age;
	public :
		Chulsoo(int age);
		Chulsoo(const Chulsoo& obj);
		Chulsoo();
		~Chulsoo();

		Chulsoo& operator=(const Chulsoo& obj);

		void introduce();
};

Chulsoo::Chulsoo(int age) : age(age){
	cout << "+++ Chulsoo::Chulsoo(age) constructor done +++" << endl;
}

Chulsoo::Chulsoo(const Chulsoo& obj){
	cout << "+++ Chulsoo::Chulsoo(Chulsoo&) copy constructor done +++" << endl;
}

Chulsoo::Chulsoo(){
	cout << "+++ Chulsoo::Chulsoo() constructor done +++" << endl;
}

Chulsoo::~Chulsoo(){
	cout << "+++ Chulsoo::~Chulsoo() destructor done +++" << endl;
}

void Chulsoo::introduce(){
	cout << "the age of chulsoo is " << this->age << endl;

}

Chulsoo& Chulsoo::operator=(const Chulsoo& obj){
	cout << "assaign operator call " << endl;
	this->age = obj.age;
	return *this;
}

int main(void){
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);
	cout << "================ before ======================" << endl;
	chulsoo1 = chulsoo2;
	cout << "================ after ======================" << endl;
	return 0;
}
