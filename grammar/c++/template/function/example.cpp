#include <iostream>

using namespace std;


class test{
	public:
		int x,y;
		test(int a1,int a2):x(a1),y(a2){
		}
};

void Print(int a, int b){
	cout << a << ", " << b << endl;
}

void Print(string a, string b){ //function overload
	cout << a << ", " << b << endl;
}

template <typename T> //use template for handling various type
void PrintT(T a, T b){
	cout << "template func a : " << a << ", b: " << b << endl;
}
template <>
void PrintT(test a, test b){
	cout << "template specialized func a : " << a.x << ", b: " << b.y << endl;
}

template <typename ret, typename T, typename T2> //use template for handling numbers of various type
ret PrintMT(T a, T2 b){
	cout << "multi template func a : " << a << ", b: " << b << endl;
}

template <typename T, int roop=1> //use template with argument. (-std=c++11 option needed)
void PrintR(T arg){
	for (int i = 0 ; i <roop ; i++){
		cout << "roop - arg : " << arg << endl;
	}
}


int main(){
	//overload use case
	Print(10,20);
	Print("test","arg");
	cout << endl;

	//template use case
	PrintT<int>(10,20);
	PrintT<string>("test", "arg");
	cout << endl;
	
	//template specilized use case
	test objarg(10,20);
	PrintT<test>(objarg, objarg);
	cout << endl;

	//multiple template use case
	PrintMT<void,int,string>(10,"test");
	PrintMT<void, string,int>("test", 10);
	cout << endl;

	//argument template use case
	PrintR<string>("test");
	PrintR<string,3>("testroop");
	cout << endl;

	return 0;
}
