#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Chulsoo{
	private : 
		char *name;
		int *age;
		int setage;
	public :
		Chulsoo(char* name, int age);
		~Chulsoo();
		void introduce();
		void setAge(int age);
		void setprint();
};


Chulsoo::Chulsoo(char* name, int age){
	this->name = new char[strlen(name)+1];
	strncpy(this->name, name, strlen(name));
	this->age = new int;
	*this->age = age;  //copy argument
	cout << "+++ Chulsoo::Chulsoo(name ,age) constructor done +++" << endl;
}

Chulsoo::~Chulsoo(){
	delete[] name;
	delete age;
	cout << "+++ Chulsoo::~Chulsoo() destructor done +++" << endl;
}

void Chulsoo::introduce(){
	cout << "chulsoo name : " << this->name << endl;
	cout << "chulsoo age : " << *this->age << endl;
	cout << "chulsoo setage : " << this->setage << endl;
}

void Chulsoo::setAge(int age){
	this->setage = age;
}

void Chulsoo::setprint(){
	cout << "setage is "<< this->setage << endl;
}

int main(void){
	Chulsoo chulsoo("chulsoo", 32);
	//chulsoo.introduce();
	chulsoo.setprint();
	
	Chulsoo* chulsooPtr = (Chulsoo*)malloc(sizeof(Chulsoo));
	chulsooPtr->setAge(10);
	chulsooPtr->setprint();
	free(chulsooPtr);
	chulsooPtr = NULL;

	Chulsoo* Newchulsoo = new Chulsoo("newman", 10);


	Newchulsoo->introduce();
	Newchulsoo->setprint();
	// in this case, address of  Newchulsoo might be same as chulsooPtr.
	// notice that chulsooPtr->setage assigned as 10 and not be changed. 
	// so, allocated memory does not garranty non-assanged value.
	// When we use allocated memory, we must initialize values.
	delete Newchulsoo;

	return 0;
}
