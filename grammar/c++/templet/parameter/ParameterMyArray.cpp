#include <iostream>
#include <vector>

using namespace std;

template <typename T, int init>
class MyArray{
	private:
		vector<T> list;
	public:
		MyArray();
		void add_list(T const&);
		void delete_last_list(void);
		void show_list(void);
};


template <typename T, int init>
MyArray<T,init>::MyArray(){
	for(int i=0; i<init; ++i){
		list.push_back(i);
	}
}


template <typename T, int init>
void MyArray<T, init>::add_list(T const& element){
	list.push_back(element);
}

template <typename T, int init>
void MyArray<T, init>::delete_last_list(void){
	list.pop_back();
}

template <typename T, int init>
void MyArray<T, init>::show_list(void){
	cout << "[myArray list look up]" << endl;
	for(typename vector<T>::iterator i = list.begin(); i!=list.end(); ++i){
		cout << *i << endl;
	}
}

int main(){
	MyArray<int,3> array1;
	array1.add_list(10);
	array1.add_list(20);
	array1.add_list(30);
	array1.add_list(40);
	array1.add_list(50);

	array1.show_list();

	array1.delete_last_list();
	array1.delete_last_list();

	array1.show_list();

	MyArray<double,4> array2;
	array2.add_list(10.1);
	array2.add_list(20.2);
	array2.add_list(30.3);
	array2.add_list(40.4);
	array2.add_list(50.5);

	array2.show_list();

	array2.delete_last_list();
	array2.delete_last_list();

	array2.show_list();

	return 0;
}
