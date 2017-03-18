#include <iostream>
#include <typeinfo>
#include <exception>

using namespace std;

class MyException : public exception
{
	private:
		int myValue;

	public:
		MyException(int value):myValue(value){}
		virtual const char* what() const throw(){
			if(myValue < 10){
				return "value should be over than 10";
			}else if(myValue > 20){
				return "value should be less than 20";
			}else if(myValue%7 !=0){
				return "value should be multiples of 7" ;
			}
			return "wrong error";
		}
};

int getMultiple(){

	int value;
	cout << "enter number between 10 and 20, with multiples of 7" << endl;
	cin >> value;

	if(value < 10 | value > 20 | value%7 !=0){
		throw MyException(value);
	}
	return value;
}

int getValue(){
	int value;
	value = getMultiple();
	return value;
}

int main(){
	int value;
	try{
		value = getValue();
		cout << "multipile of 7 between 10 and 20 is : " << value << endl;

	}catch(MyException &e){
		cout << e.what() << endl;
	}
	return 0;
}

