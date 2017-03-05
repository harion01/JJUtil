#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class Person{
	protected:
		char* name;
		int age;
	public:
		Person(char *name, int age);
		//virtual ~Person();  //if you forget virtual destructor, memory leak can be occured.
		~Person();  //omit virtual keywork for memory leak test.
		virtual void introduce();
		void eat();
		void sleep();
};

class Chulsoo : public Person{
	private:
		char* bookname;
	public:
		Chulsoo(char* name, int age, char* bookname);
		~Chulsoo();
		void introduce();
		void write();
};

Person::Person(char* name, int age){
	this->name = new char[strlen(name)+1];
	strncpy(this->name, name, strlen(name));
	this->age = age;
	cout << "Person::Person(name,age) constructor done" << endl;
}

void Person::introduce(){
	cout << "Person name : " << this->name << endl;
	cout << "Person age : " << this->age << endl;
}

void Person::eat(){
	cout << "Person eat " << endl;
}

void Person::sleep(){
	cout << "Person sleep " << endl;
}

Person::~Person(){
	delete[] name;
	cout << "Person::~Person destructor done" << endl;
}


Chulsoo::Chulsoo(char* name, int age, char* bookname) : Person(name, age){
	this->bookname = new char[strlen(bookname)+1];
	strncpy(this->bookname, bookname, strlen(bookname));
	cout << "Chulsoo::Chulsoo(name age, bookname) constructor done " << endl;
}

void Chulsoo::write(){
	cout << "chulsoo write a book " << endl;
}

Chulsoo::~Chulsoo(){
	delete[] bookname;
	cout << "Chulsoo::~chulsoo destructor done " << endl;
}

void Chulsoo::introduce(){
	cout << "Chulsoo name : " << name << endl;
	cout << "Chulsoo age : " << age << endl;
	cout << "Chulsoo bookname: " << this->bookname<< endl;
}


int main(){
	while(1){
		Person* personPtr = new Chulsoo("chulsoo", 32, "c++");  //upcasting without virtual destructor makes memory leak
		personPtr->introduce();
		delete personPtr; //without virtual destructor, dynamic memory space will be leaked.
		sleep(1);
	}
	return 0;
}
