#include <iostream>
#include <string.h>

using namespace std;

class Chulsoo{
	private :
		char* name;
	public :
		Chulsoo(char* name);
		Chulsoo();
		~Chulsoo();
		void introduce();
};

Chulsoo::Chulsoo(char* name){
	this->name = new char[strlen(name)+1];
	strncpy(this->name, name, strlen(name));
	cout << "+++ Chulsoo::Chulsoo(name) constructor done +++" << endl;
}

Chulsoo::Chulsoo(){
	cout << "+++ Chulsoo::Chulsoo() constructor done +++" << endl;
}

void Chulsoo::introduce(){
	cout << "name : " << this->name << endl;
}

Chulsoo::~Chulsoo(){
	delete[] name;
	cout << "+++ Chulsoo::Chulsoo() destructor done +++" << endl;
}

int main(void){
	Chulsoo chulsoo("chulsoo");
	chulsoo.introduce();
	return 0;
}
