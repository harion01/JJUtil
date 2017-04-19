#ifndef EXPTRESSION_TREE_CPP
#define EXPTRESSION_TREE_CPP

#include <iostream>
#include <vector>

using namespace std;
typedef struct Node{
	struct Node* Left;
	struct Node* Right;
	string Data;
}TreeNode;


class EXPBtree {
	private:
		TreeNode* root;
		TreeNode* CreateExpNode(string data);
		vector<string> Exp;
	public:
		void Init(string PostExpression);
		void CreateExpTree(TreeNode** Node);
};



#endif
