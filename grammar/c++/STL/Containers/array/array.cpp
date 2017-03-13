#include <iostream>
#include <array>

using namespace std;

/*
Arrays are fixed-size sequence containers: they hold a specific number of elements ordered in a strict linear sequence.

Unlike the other standard containers, arrays have a fixed size and do not manage the allocation of its elements through an allocator: they are an aggregate type encapsulating a fixed-size array of elements. Therefore, they cannot be expanded or contracted dynamically (see vector for a similar container that can be expanded).

- http://www.cplusplus.com/reference/array/array/
*/

int main(){

	array<int, 10> ar;
	ar = {1,2,3};

	for (auto i = ar.begin(); i != ar.end(); i++){
		cout << *i << " " ;
	}
	cout << endl;

	cout << " ==== fill ar ==== " << endl;
	ar.fill(5);
	for (auto i = ar.begin(); i != ar.end(); i++){
		cout << *i << " " ;
	}
	cout << endl;

	return 0;
}
