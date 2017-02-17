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

		Chulsoo operator+(const Chulsoo& chulsooObj);
		Chulsoo operator-(const Chulsoo& chulsooObj);
		Chulsoo operator*(const Chulsoo& chulsooObj);
		Chulsoo operator/(const Chulsoo& chulsooObj);

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

	
Chulsoo Chulsoo::operator+(const Chulsoo& chulsooObj){ //each time you call this function, constructor/copyconstructor/destroctor will be called
	cout << "---- Chulsoo::operator+ call ---" << endl;
	Chulsoo chulsoo(this->age + chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator-(const Chulsoo& chulsooObj){
	cout << "---- Chulsoo::operator- call ---" << endl;
	Chulsoo chulsoo(this->age - chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator*(const Chulsoo& chulsooObj){
	cout << "---- Chulsoo::operator* call ---" << endl;
	Chulsoo chulsoo(this->age * chulsooObj.age);
	return chulsoo;
}
Chulsoo Chulsoo::operator/(const Chulsoo& chulsooObj){
	cout << "---- Chulsoo::operator/ call ---" << endl;
	Chulsoo chulsoo(this->age / chulsooObj.age);
	return chulsoo;
}

void Chulsoo::introduce(){
	cout << "the age of chulsoo is " << this->age << endl;
}


int main(void){
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);

	chulsoo1.introduce();
	chulsoo2.introduce();

	Chulsoo chulsooret = chulsoo1 + chulsoo2;
	chulsooret.introduce();

	chulsooret = chulsoo1 - chulsoo2;
	chulsooret.introduce();

	chulsooret = chulsoo1 * chulsoo2;
	chulsooret.introduce();

	chulsooret = chulsoo1 / chulsoo2;
	chulsooret.introduce();

	return 0;
}
