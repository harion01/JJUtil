#include <iostream>
using namespace std;

class Chulsoo{
	private :
		int age;

	public :
		Chulsoo(int age);
		Chulsoo();
		~Chulsoo();
		void setAge(int age);
		void introduce();
		Chulsoo* returnThisPointer();
		Chulsoo  returnThis();
		Chulsoo& returnThisRef();
};

Chulsoo::Chulsoo(int age){
	this->age = age;
	cout << "+++ Chulsoo::Chulsoo(age) constructor done +++" << endl;
}

Chulsoo::Chulsoo(){
}

Chulsoo::~Chulsoo(){
}

void Chulsoo::setAge(int age){
	this->age = age;
}

void Chulsoo::introduce(){
	cout << "age of chulsoo is : "<< this->age << endl;
}


Chulsoo* Chulsoo::returnThisPointer(){
	return this;
}

Chulsoo  Chulsoo::returnThis(){
	return *this;
}

Chulsoo& Chulsoo::returnThisRef(){
	return *this;
}

	
int main(void){
	Chulsoo chulsoo1(32);
	cout << "normal case" << endl;
	chulsoo1.introduce();
	chulsoo1.setAge(50);
	chulsoo1.introduce();


	Chulsoo chulsoo2(32);
	cout << "chulsooPointer case" << endl;
	chulsoo2.returnThisPointer()->introduce();
	chulsoo2.returnThisPointer()->setAge(50);
	chulsoo2.returnThisPointer()->introduce();

	Chulsoo chulsoo3(32);
	cout << "return this case" << endl;
	chulsoo3.returnThis().introduce();
	chulsoo3.returnThis().setAge(50);
	chulsoo3.returnThis().introduce();

	Chulsoo chulsoo4(32);
	cout << "return this ref case" << endl;
	chulsoo4.returnThisRef().introduce();
	chulsoo4.returnThisRef().setAge(50);
	chulsoo4.returnThisRef().introduce();

	return 0;
}
