#include <iostream>
#include <string.h>
using namespace std;

#define NAME_LEN 20

class Person{
	protected:
		char name[NAME_LEN];
		int age;
	public:
		Person(char *name, int age);
		~Person();
		void introduce();
		void eat();
		void sleep();
};

class Chulsoo : public Person{
	private:
		int numOfBooks;
	public:
		Chulsoo(char* name, int age, int numOfBooks);
		~Chulsoo();
		void introduce();
		void write();
};

Person::Person(char* name, int age){
	strcpy(this->name, name);
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
	cout << "Person::~Person destructor done" << endl;
}


Chulsoo::Chulsoo(char* name, int age, int numOfBooks) : Person(name, age){
	this->numOfBooks = numOfBooks;
	cout << "Chulsoo::Chulsoo(name age, numOfBook) constructor done " << endl;
}

void Chulsoo::write(){
	cout << "chulsoo write a book " << endl;
}

Chulsoo::~Chulsoo(){
	cout << "chulsoo destructor done " << endl;
}

void Chulsoo::introduce(){
	cout << "Chulsoo name : " << name << endl;
	cout << "Chulsoo age : " << age << endl;
	cout << "Chulsoo numofbooks: " << this->numOfBooks << endl;
}


int main(){
	cout << "=== Before Person object create ===" << endl;
	Person person("Person", 100);
	person.introduce();
	person.eat();
	person.sleep();
	cout << "=== After Person object create ===" << endl;
	
	cout << "=== Before Chulsoo object create ===" << endl;
	Chulsoo chulsoo("chulsoo", 32, 3);
	chulsoo.introduce();
	chulsoo.eat();
	chulsoo.sleep();
	chulsoo.write();
	cout << "=== After Chulsoo object create ===" << endl;
	
	cout << "=== Before Chulsoo -> Person upcasting ===" << endl;
	person = chulsoo; //upcasting 
	person.introduce(); //in this case, Person::introduce will be called. not Chulsoo::intoroduce.
	cout << "=== After Chulsoo -> Person upcasting ===" << endl;


	return 0;
}
