#include <iostream>
#include "Node.h"
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int> q;

	q.enqueue(10);
	q.enqueue(20);
	cout << q.isEmpty() << endl;
	cout << q.getSize() << endl;
	cout << q.dequeue<int>() << endl;
	cout << q.dequeue<int>() << endl;


	return 0;
}