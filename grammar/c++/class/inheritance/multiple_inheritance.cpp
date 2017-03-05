#include <iostream>
using namespace std;

class Person{
	public:
		Person();
		~Person();
		virtual void write()=0;
};

Person::Person(){
	cout << "Person::Person() " << endl;
}

Person::~Person(){
	cout << "Person::~Person() " << endl;
}

class Chulsoo : public Person {
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

class Younghee: public Person {
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

	return 0;
}
