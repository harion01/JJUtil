#include "ExpressionTree.h"

/*
struct TreeNode{
	struct TreeNode* Left;
	struct TreeNode* Right;
	string Data;
};


class Btree : private JJparser{
	private:
		TreeNode* root;
		TreeNode* CreateExpNode(string data);
	public:
		void CreateExpTree(string InorderExpression);
		
		void PrintPostOrder();
		void PrintInOrder();
		void PrintPreOrder();

		double Calculate();
};
*/


TreeNode* EXPBtree::CreateExpNode(string data){
	TreeNode* NewNode = new TreeNode();
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = data;
	
	return NewNode;
}


void EXPBtree::CreateExpTree(TreeNode** Node){
	string curdata;
	if(Exp.size() > 0){
		curdata = Exp.back();
		Exp.pop_back();
	}else {
		return;
	}

	if(this->IsNumber(curdata[0])){
		(*Node) = CreateExpNode(curdata);
	}else{
		(*Node) = CreateExpNode(curdata);
		CreateExpTree(&(*Node)->Right);
		CreateExpTree(&(*Node)->Left);
	}

}

EXPBtree::EXPBtree(string PostExpression){
	Exp = this->parseMathExpression(PostExpression);
	cout << "=====" << endl;
	for(auto i:Exp){
		cout << i << endl;
	}
	cout << "=====" << endl;
	CreateExpTree(&root);
}


void EXPBtree::PrintOrder(TreeNode* Node, int Type){
	if(Node == NULL){
		return;
	}

	switch(Type){
		case 1: //Pre
			cout << " "  << Node->Data ;
			PrintOrder(Node->Left, 1);
			PrintOrder(Node->Right, 1);
			break;

		case 2: //In
			PrintOrder(Node->Left, 2);
			cout << " "  << Node->Data ;
			PrintOrder(Node->Right, 2);
			break;

		case 3: //Post
			PrintOrder(Node->Left, 3);
			PrintOrder(Node->Right, 3);
			cout << " "  << Node->Data ;
			break;
	}
}


void EXPBtree::PrintPreOrder(){
	PrintOrder(root, 1);
	cout << endl;
}

void EXPBtree::PrintInOrder(){
	PrintOrder(root, 2);
	cout << endl;
}

void EXPBtree::PrintPostOrder(){
	PrintOrder(root, 3);
	cout << endl;
}

double EXPBtree::Calculate(TreeNode* Node){
	if(Node == NULL){
		return 0;
	}

	double ret;

	if(this->IsNumber(Node->Data[0])){
		return std::stod(Node->Data, NULL);
	}else {
		double Left = Calculate(Node->Left);
		double Right = Calculate(Node->Right);

		if(Node->Data[0] == '+'){
			ret = Left + Right;
		}else if (Node->Data[0] == '-'){
			ret = Left - Right;
		}else if (Node->Data[0] == '*'){
			ret = Left * Right;
		}else if (Node->Data[0] == '/'){
			ret = Left / Right;
		}
	}

	return ret;
}

double EXPBtree::GetAnswer(){
	return Calculate(root);
}
