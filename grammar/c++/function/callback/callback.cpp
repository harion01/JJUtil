#include <iostream>
#include <algorithm> //for using for_each() STL

using namespace std;


// server side
// virtualized for processing client function
void For_each(int *begin, int *end, void (*pf)(int)){
	while(begin !=end){
		pf(*begin++); //call bakc(client function)
	}
}


// client side
void Print1(int n){
	cout << n << " ";
}

void Print2(int n){
	cout << n*n << " " ;
}

void Print3(int n){
	cout << " int : " << n << endl;
}

int main(){
	int arr[5] = {10,20,30,40,50};

	For_each(arr, arr+5, Print1); //operation is decided by function pointer
	cout << endl;
	for_each(arr, arr+5, Print1);
	cout << endl << endl;

	For_each(arr, arr+5, Print2);
	cout << endl;
	for_each(arr, arr+5, Print2);
	cout << endl << endl;

	For_each(arr, arr+5, Print3);
	cout << endl;
	for_each(arr, arr+5, Print3);
	cout << endl << endl;
}
