#include <iostream>
#include <vector>

using namespace std;

class MyContainer{
	private:
		vector<int>* bucket;
		vector<int> v;
		int count;
		int value;

	public:
		MyContainer(int cnt, int val); //constructor
		MyContainer(const MyContainer& copy); //copy constructor
		MyContainer(MyContainer&& move); //move constructor
		MyContainer operator=(MyContainer&& move); //move substituce operator

		void showContainer();
};


MyContainer::MyContainer(int cnt, int val){
	cout << "call constructor " << endl;
	for(auto i = 0 ; i<cnt; ++i){
		v.push_back(val);
	}
	bucket = &v;
	count = cnt;
	value = val;
	cout << "bucket: " << bucket << endl;
}

MyContainer::MyContainer(const MyContainer& copy){
	cout << "call copy constructor " << endl;
	auto val = copy.v.begin();
	for ( auto i = 0; i<copy.count; ++i){
		v.push_back(*(val+i));
	}
	bucket = &v;
	count = copy.count;
	cout << "bucket: " << bucket << endl;
}

MyContainer::MyContainer(MyContainer&& move){
	cout << "call move constructor " << endl;
	bucket = &(move.v);
	count = move.count;
	move.count =0;
	cout << "bucket: " << bucket << endl;
}

MyContainer MyContainer::operator=(MyContainer&& move){
	cout << "call operator= " << endl;
	count = move.count;
	v.clear();
	for(auto i = move.v.begin(); i!=move.v.end(); ++i){
		v.push_back(move.value);
	}
	bucket = &v;
	cout << "bucket: " << bucket << endl;
	return *this;
}

void MyContainer::showContainer(){
	cout << "[showContainer]" << endl;
	for(auto i=(*bucket).begin(); i!=(*bucket).end(); ++i){
		cout << *i << " " ;
	}
	cout << endl;
	auto i = (*bucket).begin();
	cout << &(*i) << endl;
}

MyContainer CreateMyContainer(int m, int n){
	return MyContainer(m,n);
}

int main(){
	MyContainer myCon1(20,1);
	myCon1.showContainer();

	MyContainer myCon2 = myCon1;
	myCon2.showContainer();

	MyContainer myCon3(20,3);
	myCon3.showContainer();

	MyContainer myCon4(move(myCon3));
	myCon4.showContainer();

	MyContainer myCon5(20,5);
	myCon5.showContainer();
	myCon5 = CreateMyContainer(20,7);
	myCon5.showContainer();


	return 0;
}
