#include <iostream>
#include <functional>
using namespace std;

bool pred_less(int a, int b){
	return a<b;
}

struct Less{
	bool operator()(int a, int b){
		return a<b;
	}
};

int main(){
	Less l;

	cout << pred_less(10,20) << endl;
	cout << pred_less(20,10) << endl;
	cout << endl;

	cout << l(10,20) << endl;
	cout << l(20,10) << endl;
	cout << endl;

	cout << Less()(10,20) << endl;
	cout << Less()(20,10) << endl;
	cout << endl;

	cout << l.operator()(10,20) << endl;
	cout << Less().operator()(10,20) << endl;
	cout << endl;

	less<int> stdless;
	cout << stdless(10,20) << endl;
	cout << stdless(20,10) << endl;
	cout << stdless.operator()(10,20) << endl;
	cout << endl;

	cout << less<int>()(10,20) << endl;
	cout << less<int>()(20,10) << endl;
	cout << less<int>().operator()(10,20) << endl;

	return 0;
}
