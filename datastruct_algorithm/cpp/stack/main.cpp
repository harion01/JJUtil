#include <iostream>
#include "Node.h"
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);

	cout << s.pop<int>() << endl;
	cout << s.getTop<int>() << endl;
	cout << s.pop<int>() << endl;
	cout << s.getTop<int>() << endl;
	cout << s.getTop<int>() << endl;
	cout << s.pop<int>() << endl;

	return 0;
}