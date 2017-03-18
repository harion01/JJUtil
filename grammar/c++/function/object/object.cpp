#include <iostream>

using namespace std;

void Print(){
	cout << "global function! " << endl;
}

struct Functor{
		int callcount;
	public:
		explicit Functor(int n=0):callcount(n){
		}

		void operator()(){
			cout << "function object! total func call : " << callcount << endl;
			callcount= callcount+1;
		}

		void operator()(int a, int b){
			cout << "function object a : " << a << ", b : " << b << ", total func call : " << callcount << endl;
			callcount = callcount+1;
		}
};

int main(){
	Functor functor(0);
	Print();    //call global function
	functor();  //call member function - same as functor.operator()
	functor(1,2);  //call member function - same as functor.operator()

	return 0;
}

