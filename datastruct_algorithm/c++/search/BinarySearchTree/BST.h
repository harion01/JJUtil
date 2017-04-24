#ifndef BST_CPP_H
#define BST_CPP_H

#include <iostream>

using namespace std;

class BST_Node{
	private:

	public:
		int Data;
		class BST_Node* Left;
		class BST_Node* Right;
		BST_Node(int val):Data(val),Left(NULL),Right(NULL) {}
};

class BST{
	private :
		BST_Node* Root;
		void InOrderPrint(BST_Node* Node, int depth);
		void DeleteAndFix(BST_Node** Parent, BST_Node* Target, bool isLeft);

	public :
		BST():Root(NULL) {}	
		bool InsertNode(int data);
		bool SearchData(int target);
		bool DeleteNode(int data);

		void PrintTree();
};

#endif
