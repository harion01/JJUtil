#include <iostream>
#include <functional>
using namespace std;

template <typename T>
struct Less{
	bool operator()(T a, T b){
		return a<b;
	}
};

template <typename T>
struct Greater{
	bool operator()(T a, T b){
		return a>b;
	}
};

int main(){
	cout << Less<int>()(10,20) << endl; //custom Less
	cout << Less<int>()(20,10) << endl; //custom Less
	cout << Greater<int>()(10,20) << endl; //custom Greater
	cout << Greater<int>()(20,10) << endl; //custom Greater
	cout << endl;

	cout << less<int>()(10,20) << endl; //STL
	cout << less<int>()(20,10) << endl; //
	cout << greater<int>()(10,20) << endl; //
	cout << greater<int>()(20,10) << endl; //
	cout << endl;
	return 0;
}
