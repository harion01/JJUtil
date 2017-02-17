#include <iostream>
using namespace std;

class Chulsoo{
	private :
		int age;
	public :
		Chulsoo(int age);
		Chulsoo();
		~Chulsoo();
		void introduce();

		friend class Younghee;
};

Chulsoo::Chulsoo(int age) : age(age){
	cout << "+++ Chulsoo::Chulsoo(age) constructor done +++" << endl;
}

Chulsoo::Chulsoo(){
}

Chulsoo::~Chulsoo(){
}

void Chulsoo::introduce(){
	cout << "chulsoo age : " << this->age << endl;
}



class Younghee{
	private :
		int age;
	public :
		Younghee(int age);
		Younghee();
		~Younghee();
		void introduce();
		void whoIsOlder(const Chulsoo& chulsooObj);
};

Younghee::Younghee(int age) : age(age){
	cout << "+++ Younghee::Younghee(age) constructor done +++" << endl;
}

Younghee::Younghee(){
}

Younghee::~Younghee(){
}

void Younghee::introduce(){
	cout << "yunghee age : " << this->age << endl;
}


void Younghee::whoIsOlder(const Chulsoo& chulsooObj){
	cout << "age of younghee is " << ((this->age > chulsooObj.age) ? "larger":"younger") << " than chulsoo" << endl;
}

	
int main(void){
	Chulsoo chulsoo1(32);
	chulsoo1.introduce();
	Younghee younghee1(35);
	younghee1.introduce();

	younghee1.whoIsOlder(chulsoo1);

	return 0;
}
