#ifndef EXPTRESSION_TREE_CPP
#define EXPTRESSION_TREE_CPP

#include "JJparser.h"
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode{
	struct TreeNode* Left;
	struct TreeNode* Right;
	string Data;
};


class EXPBtree : private JJparser{
	private:
		TreeNode* root;
		TreeNode* CreateExpNode(string data);
		vector<string> Exp;
		void PrintOrder(TreeNode* Node, int Type);
		double Calculate(TreeNode* Node);

	public:
		EXPBtree(string PostExpression);
		void CreateExpTree(TreeNode** Node);
		
		void PrintPostOrder();
		void PrintInOrder();
		void PrintPreOrder();

		double GetAnswer();
};



#endif
