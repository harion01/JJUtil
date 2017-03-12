#include <iostream>
#include <string.h>
using namespace std;

template <typename R, typename T, typename U>
R const add(T const& a, U const& b){
	cout << "use three templete" << endl;
	return a+b;
}

/*
template <>
double const add<char*>(char* const& a, int b){
	cout << "specialized char and int" << endl;
	cout << a << " + " << b << endl;
	return 1.0;
}
*/

template <typename T>
T const add(T const& a, T const& b){
	cout << "use one templete" << endl;
	return a+b;
}


template <>
char* const add<char*>(char* const& a, char* const& b){
	cout << "specialized" << endl;
	return strcat(a,b);
}

char* const add(char* const& a, char* const& b){
	cout << "overload" << endl;
	return strcat(a,b);
}


int main(){
	double i = 5.1;
	double j = 10.2;

	int a = 5;
	int b = 10;

	char m[20] = "hello";
	char n[20] = "World";

	cout << i << " + " << j << " = " << add<double>(i,j) << endl;
	cout << a << " + " << b << " = " << add<int>(a,b) << endl;
	cout << a << " + " << j << " = " << add<double>(a,j) << endl; //do not use multiple data type at same time. result is depends on compiler.
	cout << m << " + " << n << " = " << add<char*>(m,n) << endl; //specialized
	cout << m << " + " << n << " = " << add(m,n) << endl; //overload
	//add<double>(m,b); //TODO: study specialization with multi data type



	return 0;
}
