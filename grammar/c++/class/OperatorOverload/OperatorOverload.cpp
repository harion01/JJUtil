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
		friend Chulsoo operator+(const Chulsoo& chulsooObj1 , const Chulsoo& chulsooOjb2);
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

void Chulsoo::introduce(){
	cout << "the age of chulsoo is " << this->age << endl;

}

Chulsoo operator+(const Chulsoo& chulsooObj1 ,const Chulsoo& chulsooObj2){ //
	cout << "---- friend Chulsoo::operator+(global) call ---" << endl;
	Chulsoo chulsoo(chulsooObj1.age + chulsooObj2.age);
	return chulsoo;
}


int main(void){
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);
	
	cout << "Chulsoo chulsooAdd1 = chulsoo1 + chulsoo2" << endl;
	Chulsoo ret = chulsoo1 + chulsoo2;
	ret.introduce();

	cout << "Chulsoo chulsooAdd2 = chulsoo1 + 3" << endl;
	ret = chulsoo1 + 3;
	ret.introduce();

	cout << "Chulsoo chulsooAdd3 = 3 + chulsoo2" << endl;
	ret = 3 + chulsoo2;
	ret.introduce();
	return 0;
}
