#include <iostream>

using namespace std;

//begin, end : start, end point of array. 
//(*pf) : function pointer
template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf){
	while (begin != end){
		pf(*begin++); //lvalue is inital value. after pf call, ++ operate will be done
	}
}

void PrintInt(int n){
	cout << n << " " ;
}

void PrintStr(string n){
	cout << n << " " ;
}


//function template
template <typename T>
void Print(T n){
	cout << n << " " ;
}

//function object
template <typename T>
struct PrintFunctor{
	string sep; //seperator
	explicit PrintFunctor(const string& s=" "):sep(s){}
	void operator()(T data) const{
		cout << data << sep;
	}
};

int main(){
	int arr[5] = {10,20,30,40,50};
	For_each(arr, arr+5, PrintInt);
	cout << endl;
	For_each<int*, void(*)(int)>(arr, arr+5, PrintInt);
	cout << endl;
	For_each(arr, arr+5, Print<int>);
	cout << endl;
	For_each(arr, arr+5, PrintFunctor<int>(","));
	cout << endl;


	string sarr[3] = {"abc", "test", "ABC"};
	For_each(sarr, sarr+3, PrintStr);
	cout << endl;
	For_each<string*, void(*)(string)>(sarr, sarr+3, PrintStr);
	cout << endl;
	For_each(sarr, sarr+3, Print<string>);
	cout << endl;
	For_each(sarr, sarr+3, PrintFunctor<string>(","));
	cout << endl;
	return 0;
}
