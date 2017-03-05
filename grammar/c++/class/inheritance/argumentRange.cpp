#include <iostream>
#include <string.h>
using namespace std;

class Person{
	private:
		int privatePerson;
	protected:
		int protectedPerson;
	public:
		int publicPerson;
		Person(int age) : privatePerson(age), protectedPerson(age), publicPerson(age){
		}
		~Person(){}
};	

class Chulsoo: public Person{
	private:
		int numofBooks;
	public:
		Chulsoo(int age, int numofBooks) : Person(age), numofBooks(numofBooks){
		}
		~Chulsoo(){}
		void introduce(){
			//cout << "privatePerson : " << privatePerson << endl; //chulsoo can not handle private arguments of Person class
			cout << "protectedPerson : " << protectedPerson << endl;
			cout << "publicPerson : " << publicPerson<< endl;
		}
};	

int main(){
	Chulsoo chulsoo(32,3);
	chulsoo.introduce();


	return 0;
}
