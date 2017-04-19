#include "ExpressionTree.h"



TreeNode* EXPBtree::CreateExpNode(string data){
	TreeNode* NewNode = new TreeNode();
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = data;
	
	return NewNode;
}


void EXPBtree::CreateExpTree(TreeNode** Node){
	string curdata = "test";
	(*Node) = CreateExpNode(curdata);


	return;
}

void EXPBtree::Init(string PostExpression){
	CreateExpTree(&root);
}



