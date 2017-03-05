#include <iostream>
using namespace std;

template <typename R, typename T, typename U>
R const add(T const& a, U const& b){
	return a+b;
}

int main(){
	double i = 5.1;
	double j = 10.2;

	int a = 5;
	int b = 10;

	cout << i << " + " << j << " = " << add<double>(i,j) << endl;
	cout << a << " + " << b << " = " << add<int>(a,b) << endl;
	cout << a << " + " << j << " = " << add<double>(a,j) << endl; //do not use multiple data type at same time. result is depends on compiler.

	return 0;
}
