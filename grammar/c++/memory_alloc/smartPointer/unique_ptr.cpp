#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <memory>

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
}

void Chulsoo::setAge(int age){
	this->setage = age;
}

void Chulsoo::setprint(){
	cout << "setage is "<< this->setage << endl;
}

int main(void){
	//Chulsoo* chulsooPtr = new Chulsoo(32);
	//chulsooPtr->introduce();
	//delete chulsooPtr;

	unique_ptr<Chulsoo> chulsooSmptr(new Chulsoo("chulsoo",32));
	chulsooSmptr->introduce();
	cout << "===============================" << endl;
	//unique pointer permit only one address
	unique_ptr<Chulsoo> chulsooSmptr2 = chulsooSmptr; //this line occur compler error.
	//similler concept as auto_ptr, but compiler can check address usage.

	chulsooSmptr->introduce();  
	chulsooSmptr2->introduce(); 


	return 0;
}
