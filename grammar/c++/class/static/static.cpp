#include <iostream>
using namespace std;

class Chulsoo{
	private :
		int age;
		static int chulsooPrivateCounter;

	protected :
		static int chulsooProtedtedCounter;

	public :
		static int chulsooPublicCounter;
		Chulsoo(int age);
		Chulsoo();
		~Chulsoo();
		void check();
};

Chulsoo::Chulsoo(int age) : age(age){
	cout << "+++ Chulsoo::Chulsoo(age) constructor done +++" << endl;
	chulsooPublicCounter++;
	chulsooProtedtedCounter++;
	chulsooPrivateCounter++;

	cout << "static private counter : " << chulsooPrivateCounter << endl;
	cout << "static protedted counter : " << chulsooProtedtedCounter << endl;
	cout << "static public counter : " << chulsooPublicCounter << endl;

}

Chulsoo::Chulsoo(){
}

Chulsoo::~Chulsoo(){
}

void Chulsoo::check(){
	cout << "static private counter : " << chulsooPrivateCounter << endl;
	cout << "static protedted counter : " << chulsooProtedtedCounter << endl;
	cout << "static public counter : " << chulsooPublicCounter << endl;
}

//static initialization must be non-dynamic
int Chulsoo::chulsooPrivateCounter = 0;
int Chulsoo::chulsooProtedtedCounter = 0;
int Chulsoo::chulsooPublicCounter = 0;



class Younghee{
	private :
		int age;
	public :
		Younghee(int age);
		Younghee();
		~Younghee();
};

Younghee::Younghee(int age) : age(age){
	cout << "+++ Younghee::Younghee(age) constructor done +++" << endl;
	Chulsoo::chulsooPublicCounter++;

	cout << "Younghee::Younghee(age) constructor will add chulsoo object :" << Chulsoo::chulsooPublicCounter  << endl;
}

Younghee::Younghee(){
}

Younghee::~Younghee(){
}




	
int main(void){
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(32);
	Younghee younghee1(35);
	Younghee younghee2(35);
	

	Chulsoo chulsoo3(32);
	chulsoo1.check();
	return 0;
}
