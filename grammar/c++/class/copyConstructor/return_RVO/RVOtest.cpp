#include <iostream>
#include <string.h>

using namespace std;

class Chulsoo{
	private :
		char* name;
	public :
		Chulsoo(char* name);
		Chulsoo();
		Chulsoo(const Chulsoo& source);
		~Chulsoo();
		void introduce();
		
		Chulsoo RVOtest();
};

Chulsoo::Chulsoo(char* name){
	this->name = new char[strlen(name)+1];
	strncpy(this->name, name, strlen(name));
	cout << "+++ Chulsoo::Chulsoo(name) constructor done +++" << endl;
}

Chulsoo::Chulsoo(){
	cout << "+++ Chulsoo::Chulsoo() constructor done +++" << endl;
}

Chulsoo::Chulsoo(const Chulsoo& source){ //defining copyconstrutor provides shallowcopy to chulsoo class
	this->name = new char[strlen(source.name)+1]; //if you use default copyconstructor, allocation for this->name paprameter will be skiped. 
	strncpy(this->name, source.name, strlen(source.name));
	cout << "+++ Chulsoo::Chulsoo(Chulsoo& source) copyconstructor done +++" << endl;
}


Chulsoo::~Chulsoo(){
	delete[] this->name; //If you does not define shallowCopyConstructor, this delete function may occur double free error
	cout << "+++ Chulsoo::Chulsoo() destructor done +++" << endl;
}

void Chulsoo::introduce(){
	cout << "name : " << this->name << endl;
}

Chulsoo Chulsoo::RVOtest(){
	Chulsoo RVO("RVOname");
	return RVO;
}

Chulsoo rettest(){
	Chulsoo chulsoo("chulsoo");
	Chulsoo chulhee(chulsoo); //Chulsoo chulhee = chulsoo  - copy constructor occor 

	chulsoo.introduce();
	chulhee.introduce();

	Chulsoo RVOtest = chulhee.RVOtest();
	
	return RVOtest;
}

int main(void){
	Chulsoo ret = rettest();
	ret.introduce();

	return 0;
}
