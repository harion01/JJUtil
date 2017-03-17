#include <iostream>
#include <string>

using namespace std;

int main(){

	string name1 = "allen";
	cout << "name1: " << name1 << endl;

	//move func just make lvalue into rvalue.
	//diffent result is made by operator= of string and int
	string name2 = std::move(name1);
	cout << "After, name2 = std::move(name1)" << endl;
	cout << "-> name1: " << name1 << endl;
	cout << "-> name2: " << name2 << endl << endl;
	
	int zipcode1 = 90031;
	cout << "zipcode1: " << zipcode1 << endl;

	int zipcode2 = move(zipcode1);
	cout << "After, zipcode2 = std::move(zipcode1)" << endl;
	cout << "-> zipcode1: " << zipcode1 << endl;
	cout << "-> zipcode2: " << zipcode2 << endl << endl;


	return 0;
}
