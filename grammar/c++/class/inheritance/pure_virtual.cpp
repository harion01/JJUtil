#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define NAME_LEN 20

class person{
	protected:
		char name[NAME_LEN];
		int age;
	public:
		person(char* name, int age);
		virtual void introduce()=0;//pure virtual function allow no realization of function 
		//virtual void introduce(); //error occur when using inheritence without realization of function
		virtual void eat()=0;
		virtual void sleep();
};

person::person(char* name, int age) : age(age) {
	strncpy(this->name, name, strlen(name));
}

void person::sleep(){
	cout << "person::sleep()" << endl;
}

class Chulsoo : public person{
	private:
		int numOfBooks;
	public:
		Chulsoo(char *name, int age, int numOfBooks);
		virtual void introduce();
		virtual void eat();
		virtual void sleep();
};

Chulsoo::Chulsoo(char* name, int age, int numOfBooks):person(name,age), numOfBooks(numOfBooks){
	strncpy(this->name, name, strlen(name));
}

void Chulsoo::introduce(){
	cout << "Chulsoo::intorduce()" << endl;
}

void Chulsoo::eat(){
	cout << "Chulsoo::eat()" << endl;
}

void Chulsoo::sleep(){
	cout << "Chulsoo::sleep()" << endl;
}

int main(){
	person* person = new Chulsoo("chulsoo", 32,3);
	person->introduce();
	person->eat();
	person->sleep();


	return 0;
}
