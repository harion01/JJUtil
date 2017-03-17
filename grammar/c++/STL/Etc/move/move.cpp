#include <iostream>

using namespace std;

class MyArray{
	private :
		int num;
		int index;
	public :
		static int constval;
		MyArray();
		MyArray(int n);
		MyArray(const MyArray& copy);
		MyArray(MyArray&& move);
		MyArray operator = (MyArray&& move);
		~MyArray();

		int getNum();
};

int MyArray::constval = 0;

MyArray::MyArray(){
	constval++;
	index = constval;
	cout << "call constructor my index: " << index << endl;
}


MyArray::MyArray(int n){
	constval++;
	index = constval;
	cout << "call int constructor my index: " << index << endl;

	num = n;
}

MyArray::MyArray(const MyArray& copy){
	cout << "call copy constructor. index: "<< index << endl;
	num = copy.num;
}

MyArray::MyArray(MyArray&& move){
	cout << "call move constructor. index "<< index << endl;
	num = move.num;
	move.num = 0;
}

MyArray MyArray::operator = (MyArray&& move){ //create object move
	cout << "move substituce constructor. index: " << index << endl;
	swap(num, move.num); //swap does not call constructor
}

MyArray::~MyArray(){
	cout << "call destructor. index : " << index << endl;
}

int MyArray::getNum(){
	return num;
}

MyArray CreateMyArray(){
	cout << "call create func " << endl;
	return MyArray(100);
}

/*
MyArray CreateMyArray(){
	cout << "call create func " << endl;
	MyArray test(100);
	cout << "create func end" << endl;
	return test; //call move constructor
}
*/
int main(){
	MyArray ar1(10);
	MyArray ar2(ar1);
	cout << "ar1.getNum: " << ar1.getNum() << endl;
	cout << "ar2.getNum: " << ar2.getNum() << endl;
	cout << endl;

	CreateMyArray();
	cout << endl;

	ar2=CreateMyArray();
	cout << "ar1.getNum: " << ar1.getNum() << endl;
	cout << "ar2.getNum: " << ar2.getNum() << endl;
	cout << endl;

	MyArray ar3(move(ar1));
	cout << "ar1.getNum: " << ar1.getNum() << endl;
	cout << "ar3.getNum: " << ar3.getNum() << endl;
	cout << endl;


	return 0;
}
