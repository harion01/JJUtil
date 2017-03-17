#include <iostream>
#include <stdio.h>
using namespace std;

void Print(int arg){
	cout << "global function call, int :" << arg << endl;
}

class Point{
	public:
		static void Print(int arg){ //only static function can be called without object
			cout << "static member function call, int :" << arg << endl;
		}

		void FPrint() const { 
			cout << "call member function const" << endl;
		}

		void FintPrint(int arg){
			cout << "call member function int :" << arg << endl;
		}

};

namespace A{
	void Print(int arg){
		cout << "namespace global function call, int :" << arg << endl;
	}
}

int main(){

	void (*pf)(int); //define static function poionter
	pf = Print; //set pointer of Print function

	
	Print(10); //call function
	pf = Print;
	pf(10); //call by function pointer

	A::Print(10);
	pf = A::Print;
	pf(10);

	Point::Print(10);
	pf=Point::Print;
	pf(10);

	cout << endl;
	printf("%p\n", Print);
	printf("%p\n", pf);
	printf("%p\n", *pf);

	cout << endl;
	Point pt;
	Point* p =&pt;
	Print(1);
	pt.Print(2);
	p->Print(3);


	cout << "=== member function pointer ===" << endl;
	Point obj;
	Point *objp = &obj;

	obj.FPrint(); //call member function const

	void (Point::*pf1)() const;
	pf1 = &Point::FPrint;

	(obj.*pf1)();
	(objp->*pf1)();
	cout << endl;

	obj.FintPrint(100); //call member function

	void (Point::*pf2)(int);
	pf2= &Point::FintPrint;

	(obj.*pf2)(100);
	(objp->*pf2)(100);
	cout << endl;

	return 0;
}
