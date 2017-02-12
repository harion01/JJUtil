#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20


class Chulsoo{
	private :
		char name[NAME_LEN];
		char sex[SEX_LEN];
		char job[JOB_LEN];
		char character[CHARACTER_LEN];
		int age;
		bool marriageStatus;

	public :
		Chulsoo(char* name, char* sex, char* job, char* character, int age, bool marriageStatus);
		Chulsoo();
		void introduce();
		void eat(char* food);
		void sleep();
		void drive(char* destination );
		void write();
		void read();
};



Chulsoo::Chulsoo(char* name, char* sex, char* job, char* character, int age, bool marriageStatus){
	cout << "++++ chulsoo(name, sex, job, char, age, marriage) constructor start +++" << endl;

	strcpy(this->name, name);
	strcpy(this->sex, sex);
	strcpy(this->job, job);
	strcpy(this->character, character);
	this->age = age;
	this->marriageStatus = marriageStatus;

	cout << "++++ chulsoo(name, sex, job, char, age, marriage) constructor end +++" << endl;
}

Chulsoo::Chulsoo(){
	cout << "++++ chulsoo() constructor done +++" << endl;
}


void Chulsoo::introduce(){
	cout << "name : " << name << endl;
	cout << "sex  : " << sex << endl;
	cout << "job  : " << job << endl;
	cout << "character : " << character << endl;
	cout << "age : " << age << endl;
	cout << "marriage status : " << (marriageStatus ? "Yes" : "NO") << endl;
}

void Chulsoo::eat(char* food){
	cout << "chulsoo eat [" << food << "]" << endl;
}

void Chulsoo::sleep(){
	cout << "chulsoo sleep" << endl;
}

void Chulsoo::drive(char* destination ){
	cout << "chulsoo drive to [" << destination << "]" << endl;
}

void Chulsoo::write(){
	cout << "chulsoo write a book" << endl;
}

void Chulsoo::read(){
	cout << "chulsoo read a book" << endl;
}

///////


class Younghee{
	private :
		char name[NAME_LEN];
		char sex[SEX_LEN];
		char job[JOB_LEN];
		char character[CHARACTER_LEN];
		int age;
		bool marriageStatus;

	public :
		Younghee(char* name, char* sex, char* job, char* character, int age, bool marriageStatus);
		Younghee();
		void introduce();
		void eat(char* food);
		void sleep();
		void shopping();
};



Younghee::Younghee(char* name, char* sex, char* job, char* character, int age, bool marriageStatus){
	cout << "++++ Younghee(name, sex, job, char, age, marriage) constructor start +++" << endl;
	strcpy(this->name, name);
	strcpy(this->sex, sex);
	strcpy(this->job, job);
	strcpy(this->character, character);
	this->age = age;
	this->marriageStatus = marriageStatus;

	cout << "++++ Younghee(name, sex, job, char, age, marriage) constructor end +++" << endl;
}


Younghee::Younghee(){
	cout << "++++ Younghee() constructor done +++" << endl;
}

void Younghee::introduce(){
	cout << "name : " << name << endl;
	cout << "sex  : " << sex << endl;
	cout << "job  : " << job << endl;
	cout << "character : " << character << endl;
	cout << "age : " << age << endl;
	cout << "marriage status : " << (marriageStatus ? "Yes" : "NO") << endl;
}

void Younghee::eat(char* food){
	cout << "Younghee eat [" << food << "]" << endl;
}

void Younghee::sleep(){
	cout << "Younghee sleep" << endl;
}

void Younghee::shopping(){
	cout << "Younghee shopping" << endl;
}

///////////

class DailyLife{
	private :
		Chulsoo chulsoo;
		Younghee younghee;
	public :
		DailyLife(char* cname, char* csex, char* cjob, char* ccharacter, int cage, bool cmarriageStatus, char* yname, char* ysex, char* yjob, char* ycharacter, int yage, bool ymarriageStatus);
		void run();

};

/*
DailyLife::DailyLife(Chulsoo chulsooObject, Younghee youngheeObject){ //this code will call default constructor of Chulsoo and Younghee
	cout << "+++ DailyLife constructor start +++" << endl;
	chulsoo = chulsooObject;
	younghee = youngheeObject ;
	cout << "+++ DailyLife constructor end +++" << endl;
}
*/


DailyLife::DailyLife(char* cname, char* csex, char* cjob, char* ccharacter, int cage, bool cmarriageStatus, char* yname, char* ysex, char* yjob, char* ycharacter, int yage, bool ymarriageStatus) : chulsoo(cname, csex, cjob, ccharacter, cage, cmarriageStatus), younghee(yname, ysex, yjob, ycharacter, yage, ymarriageStatus){
	cout << "+++ dailyLife (member init) constructor done +++" <<endl;
	// member initialization remove the default constructor call
}

void DailyLife::run(){
	chulsoo.drive("restaurant");
	chulsoo.eat("steak");
	younghee.eat("steak");
	chulsoo.drive("house");
	younghee.sleep();
	chulsoo.write();
	chulsoo.read();
	chulsoo.sleep();
	cout << endl;

	chulsoo.introduce();
	cout << endl;
	younghee.introduce();
	
}

////////

int main(void){
	

	DailyLife dailyliefe("chulsoo", "male" , "writter", "deligent", 32, true, "younghee", "female" , "housewife", "impatient", 32, true);
	dailyliefe.run();

	return 0;

}
