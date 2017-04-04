#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, string> getAgeNname(){
	int age;
	string name;

	cout << "enter age" << endl;
	cin >> age;

	cout << "enter name" << endl;
	cin >> name;

	return make_tuple(age,name);
}


int main(){
	
	tuple<int,string> personInfo;
	personInfo = getAgeNname();

	cout << "Age : " << get<0>(personInfo) << endl;
	cout << "Name : " << get<1>(personInfo) << endl;

	return 0;
}
