#include <iostream>
#include <string.h>
using namespace std;

#define NAME_LEN 20

class Person{
	private:
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
		void write();
};

class Younghee : public Person{
	private:
		int numOfFlowers;
	public:
		Younghee(char* name, int age, int numOfFlowers);
		~Younghee();
		void shopping();
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


Younghee::Younghee(char *name, int age, int numOfFlowers) : Person(name, age){
	this->numOfFlowers = numOfFlowers;
	cout << "Younghee::Younghee(char* name, int age, int numOfFlowers constructor done" << endl;
}

void Younghee::shopping(){
	cout << "Younghee shopping " << endl;
}

Younghee::~Younghee(){
	cout << "Younghee::~Younghee destructor done" << endl;
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

	cout << "=== Before Younghee object create ===" << endl;
	Younghee yunghee("yunghee", 32, 10);
	yunghee.introduce();
	yunghee.eat();
	yunghee.sleep();
	yunghee.shopping();
	cout << "=== After Younghee object create ===" << endl;

	return 0;
}
