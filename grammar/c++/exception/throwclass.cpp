#include <iostream>

using namespace std;

class MyException{
	private:
		int myValue;
	public:	
		MyException(int value);
		void exceptionResult();
};

MyException::MyException(int value):myValue(value){}

void MyException::exceptionResult(){
	if(myValue < 10){
		cout << "value should be over than 10" << endl;
	}else if(myValue > 20){
		cout << "value should be less than 20" << endl;
	}else if(myValue%7 !=0){
		cout << "value should be multiples of 7" << endl;
	}
}

int main(){
	int value;
	try{
		cout << "enter number between 10 and 20, with multiples of 7" << endl;
		cin >> value;

		if(value < 10 | value > 20 | value%7 !=0){
			throw MyException(value);
		}

	}catch(MyException &e){
		e.exceptionResult();
	}
	return 0;
}
