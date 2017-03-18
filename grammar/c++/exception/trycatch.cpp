#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void inputName(char* name){
	cout << "insert name." << endl;
	cin >> name;
	if(strlen(name) <= 2){
		throw name;
	}
}

int inputAge(){
	int age;
	cout << "insert age." << endl;
	cin >> age;
	if(age < 1){
		throw age;
	}
	return age;
}


int main(){
	char* name;
	int age;

	try{
		name = new char[100];
		inputName(name);
		age = inputAge();

		cout << "My name :" << name << endl;
		cout << "My age :" << age << endl;
		delete name;
		name = NULL;

	}catch (char *e){
		cout << "wrong name! name: " << e << endl;
	}catch (int e){
		cout << "wrong age! age: " << e << endl;
	}

	cout << "name size :" << sizeof(*name) << endl;

	

	return 0;
}
