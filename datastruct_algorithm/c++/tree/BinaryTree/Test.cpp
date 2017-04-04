#include "BinaryTree.h"

int main(){

	BTREE_Node<char> A('A');
	BTREE_Node<char> B('B');
	BTREE_Node<char> C('C');
	BTREE_Node<char> D('D');
	BTREE_Node<char> E('E');
	BTREE_Node<char> F('F');
	BTREE_Node<char> G('G');

	A.Left = &B;
	B.Left = &C;
	B.Right = &D;

	A.Right = &E;
	E.Left = &F;
	E.Right = &G;

	BTREE_Util<char> util;

	util.PrintPreorder(&A);
	cout << endl;

	util.PrintInorder(&A);
	cout << endl;

	util.PrintPostorder(&A);
	cout << endl;

	return 0;
}
