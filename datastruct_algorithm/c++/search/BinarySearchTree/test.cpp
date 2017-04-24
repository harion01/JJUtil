#include "BST.h"

using namespace std;

int main(void){
	int i;
	BST test;
	/*
	test.InsertNode(4);
	test.InsertNode(2);
	test.InsertNode(1);
	test.InsertNode(3);
	test.InsertNode(6);
	test.InsertNode(5);
	test.InsertNode(7);
	*/
	test.InsertNode(123);

	test.InsertNode(22);
	test.InsertNode(9918);
	test.InsertNode(424);
	test.InsertNode(17);
	test.InsertNode(3);

	test.InsertNode(98);
	test.InsertNode(34);

	test.InsertNode(760);
	test.InsertNode(317);
	test.InsertNode(1);

	test.PrintTree();
	cout << endl;
	cin >> i;
	
	test.DeleteNode(98);
	test.PrintTree();
	cout << endl;
	cin >> i;

	test.InsertNode(111);

	test.PrintTree();
	cout << endl;
	cin >> i;

	test.DeleteNode(111);
	test.PrintTree();
	cout << endl;
	cin >> i;

	return 0;
}
