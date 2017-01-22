#include "class.h"

Chulsoo::Chulsoo(char* name, char* sex, char* job, char* character, int age, bool marriageStatus){
	strcpy(this->name, name);
	strcpy(this->sex, sex);
	strcpy(this->job, job);
	strcpy(this->character, character);
	this->age = age;
	this->marriageStatus = marriageStatus;

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




Younghee::Younghee(char* name, char* sex, char* job, char* character, int age, bool marriageStatus){
	strcpy(this->name, name);
	strcpy(this->sex, sex);
	strcpy(this->job, job);
	strcpy(this->character, character);
	this->age = age;
	this->marriageStatus = marriageStatus;

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

