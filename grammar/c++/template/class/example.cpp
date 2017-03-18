#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
class Array{
	private: 
		T *buf;
		int size;
		int capacity;
	public:
		explicit Array(int cap=100);
		~Array();
		void add(T data);
		T operator[](int idx);
		int GetSize() const;

};

template <typename T>
Array<T>::Array(int cap ):buf(0), size(0), capacity(cap){
	cout << "set capacity : " << capacity << endl;
	buf = new T[capacity];
}

template <typename T>
Array<T>::~Array(){
	delete buf;
}

template <typename T>
void Array<T>::add(T data){
	buf[size++] = data;
}

template <typename T>
T Array<T>::operator[](int idx){
	return buf[idx];
}

template <typename T>
int Array<T>::GetSize() const{
	return size;
}

/////////////////////////////
template <typename Z>
class ObjectInfo{
	private :
		Z data;
	public :
		ObjectInfo(const Z& d);
		void Print();
};

template <typename Z>
ObjectInfo<Z>::ObjectInfo(const Z& d):data(d){
}

template <typename Z>
void ObjectInfo<Z>::Print(){
	cout << "type :" << typeid(data).name() << endl;
	cout << "size :" << sizeof(data) << endl;
	cout << "data :" << data << endl;
	cout << endl;
}

///////////////////////////////
template <>
class ObjectInfo<string>{
	private :
		string data;
	public :
		ObjectInfo(const string& d);
		void Print();
};

ObjectInfo<string>::ObjectInfo(const string& d):data(d){
}

void ObjectInfo<string>::Print(){
	cout << "type : string "<< endl;
	cout << "specilized length :" << data.length() << endl;
	cout << "data :" << data << endl;
	cout << endl;
}


int main(){
	Array<int> arr;
	arr.add(10);
	arr.add(20);
	arr.add(30);
	for(int i = 0 ; i < arr.GetSize() ; ++i){
		cout << arr[i] << endl;
	}
	cout << endl;


	Array<double> arr2;
	arr2.add(10.1);
	arr2.add(20.2);
	arr2.add(30.3);
	for(int i = 0 ; i < arr2.GetSize() ; ++i){
		cout << arr2[i] << endl;
	}
	cout << endl;


	Array<string> arr3;
	arr3.add("test1");
	arr3.add("test2");
	arr3.add("test3");
	for(int i = 0 ; i < arr3.GetSize() ; ++i){
		cout << arr3[i] << endl;
	}
	cout << endl;

	//specilized test
	ObjectInfo<int> d1(10);
	d1.Print();
	cout << endl;
	
	ObjectInfo<double> d2(5.5);
	d2.Print();
	cout << endl;

	ObjectInfo<string> d3("test");
	d3.Print();
	cout << endl;
	return 0;
}
