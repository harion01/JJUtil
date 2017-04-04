#include <iostream>
#include <typeinfo>

using namespace std;

int main(){

	auto text = "auto variable" ; //char* type
	cout << typeid(text).name() << endl;

	auto integer = 10; //int type
	cout << typeid(integer).name() << endl;

	//text = 10; //-once auto type changed, it will be fixed.
	//cout << typeid(text).name() << endl;
	return 0;
}
