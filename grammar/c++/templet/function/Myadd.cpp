#include <iostream>
using namespace std;

template <typename T>
T const add(T const& a, T const& b){
	return a+b;
}

int main(){
	double i = 5.1;
	double j = 10.2;

	int a = 5;
	int b = 10;

	cout << i << " + " << j << " = " << add(i,j) << endl;
	cout << a << " + " << b << " = " << add(a,b) << endl;
	//cout << a << " + " << j << " = " << add(a,j) << endl; //do not use multiple data type at same time. copiler error

	return 0;
}
