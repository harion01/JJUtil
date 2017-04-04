#include <iostream>
#include <typeinfo>
#include <exception>

using namespace std;

class MyException : public exception
//class MyException
{
	private:
		int myValue;

	public:
		MyException(int value):myValue(value){
			cout << "teststsetet" << endl;
		}
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
		/*
		~MyException(){
			cout << "~~~~~~:teststsetet" << endl;
		}
		*/
};

int main(){
	int value;
	try{
		cout << "enter number between 10 and 20, with multiples of 7" << endl;
		cin >> value;

		if(value < 10 || value > 20 || value%7 !=0){
			throw MyException(value);
		}
		MyException* test = NULL;
		typeid(*test); //throw bad_typeid std exception

	}catch(MyException &e){
		cout << e.what() << endl;
	}

	cout << "=-=================" << endl;

	return 0;
}

