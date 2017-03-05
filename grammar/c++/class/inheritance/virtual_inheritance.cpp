#include <iostream>
using namespace std;

class Person{
	public:
		Person();
		~Person();
		virtual void write()=0;
		void sleep(); 
};

Person::Person(){
	cout << "Person::Person() " << endl;
}

Person::~Person(){
	cout << "Person::~Person() " << endl;
}

void Person::sleep(){
	cout << "Person::sleep() " << endl;
}

class Chulsoo : public virtual Person { //virtual inheritance allows no duplicate parent class. also, remove ambiguous of sleep function 
	public:
		Chulsoo();
		~Chulsoo();
		void write();
};

Chulsoo::Chulsoo() : Person() {
	cout << "Chulsoo::Chulsoo()" << endl;
}

Chulsoo::~Chulsoo(){
	cout << "Chulsoo::~Chulsoo()" << endl;
}

void Chulsoo::write(){
	cout << "Chulsoo::write()" << endl;
}

class Younghee: public virtual Person { //virtual inheritance
	public:
		Younghee();
		~Younghee();
		void write();
};


Younghee::Younghee() : Person() {
	cout << "Younghee::Younghee()" << endl;
}

Younghee::~Younghee(){
	cout << "Younghee::~Younghee()" << endl;
}

void Younghee::write(){
	cout << "Younghee::write()" << endl;
}


class YoungCHul : public Chulsoo, public Younghee {
	public:
		YoungCHul();
		~YoungCHul();
		void write();
};

YoungCHul::YoungCHul() : Chulsoo(),Younghee() {
	cout << "YoungCHul::YoungCHul()" << endl;
}

YoungCHul::~YoungCHul(){
	cout << "YoungCHul::~YoungCHul()" << endl;
}

void YoungCHul::write(){
	cout << "YoungCHul::write()" << endl;
	Chulsoo::write(); //do not use just write()
}


int main(){
	
	YoungCHul young;
	young.write();
	young.sleep();

	return 0;
}
