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
};

Chulsoo::Chulsoo(int age) : age(age){
	cout << "+++ Chulsoo::Chulsoo(age) constructor done +++" << endl;
}

Chulsoo::Chulsoo(){
	cout << "+++ Chulsoo::Chulsoo() constructor done +++" << endl;
}

Chulsoo::~Chulsoo(){
	cout << "+++ Chulsoo::~Chulsoo() destructor done +++" << endl;
}

void Chulsoo::introduce(){
	cout << "age : " << this->age << endl;
}
	
int main(void){
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(chulsoo1); //Chulsoo chulsoo2 = chulsoo1;   - compiler will automatically generate default copy constructor
	chulsoo1.introduce();
	chulsoo2.introduce();

	return 0;
}
