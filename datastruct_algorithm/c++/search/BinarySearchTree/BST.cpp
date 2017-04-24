#include "BST.h"

/*
class BST_Node{
	private:

	public:
		int Data;
		class BST_Node* Left;
		class BST_Node* Right;
		BST_Node(int val):Data(val) {}
};

class BST{
	private :
		BST_Node* Root;
		BST_Node* FindMinNode(BST_Node* Node);

	public :
		BST():Root(NULL) {}
		bool InsertNode(int data);
		bool SearchData(int target);
		bool DeleteNode(int data);
}
*/

void BST::DeleteAndFix(BST_Node** Parent, BST_Node* Target, bool isLeft){
	cout << "Parent : " << (*Parent)->Data << "/Target : " << Target->Data << endl;
	if(Target-> Left == NULL && Target-> Right == NULL){
		cout << "leaf node case" << endl;
		if(isLeft){
			(*Parent)->Left = NULL;
		}else{
			(*Parent)->Right = NULL;
		}
		delete Target;
		return;
	}

	if(Target->Right == NULL){
		cout << "left node case" << endl;
		if(isLeft){
			(*Parent)->Left = Target->Left;
			delete Target;
			return;
		}else {
			(*Parent)->Right = Target->Left;
			delete Target;
			return;
		}
	}

	if(Target->Left == NULL){
		cout << "right node case" << endl;
		if(isLeft){
			(*Parent)->Left = Target->Right;
			delete Target;
			return;
		}else {
			(*Parent)->Right = Target->Right;
			delete Target;
			return;
		}


	}
	
	cout << "both node case" << endl;
	Target->Data = Target->Left->Data;
	DeleteAndFix(&Target, Target->Left, true);

	return;
}


bool BST::InsertNode(int data){
	if(Root == NULL){
		Root = new BST_Node(data);
		return true;
	}
	
	BST_Node* CurNode;
	BST_Node* Parent;
	CurNode = Root;

	while(true){
		Parent = CurNode;
		if( data > CurNode->Data){
			CurNode = CurNode->Right;
			if(CurNode == NULL){
				CurNode = new BST_Node(data);
				Parent->Right = CurNode;
				break;
			}
			continue;
		}else if(data < CurNode->Data){
			CurNode = CurNode->Left;
			if(CurNode == NULL){
				CurNode = new BST_Node(data);
				Parent->Left = CurNode;
				break;
			}
			continue;
		}
		return false;
	}

	return true;
}

bool BST::SearchData(int target){
	if(Root == NULL){
		return false;
	}
	
	BST_Node* CurNode;
	CurNode = Root;

	while(true){
		if( target > CurNode->Data){
			CurNode = CurNode->Right;
			if(CurNode == NULL){
				break;
			}
			continue;
		}else if(target < CurNode->Data){
			CurNode = CurNode->Left;
			if(CurNode == NULL){
				break;
			}
			continue;
		}
		cout << "target:" << target << "/curr:" << CurNode->Data << endl;
		return true;
	}
	
	return false;
}


bool BST::DeleteNode(int data){
	if(Root == NULL){
		return false;
	}
	
	BST_Node* CurNode;
	BST_Node* Parent;
	CurNode = Root;
	bool isLeft;

	while(true){
		if( data > CurNode->Data){
			Parent = CurNode;
			CurNode = CurNode->Right;
			isLeft = false;
			if(CurNode == NULL){
				break;
			}
			continue;
		}else if(data < CurNode->Data){
			Parent = CurNode;
			CurNode = CurNode->Left;
			isLeft = true;
			if(CurNode == NULL){
				break;
			}
			continue;
		}
		cout << "delete target:" << data << "/curr:" << CurNode->Data << endl;
		DeleteAndFix(&Parent, CurNode, isLeft);

		return true;
	}
	
	cout << "No data in tree - target :" << data << endl;
	return false;
}

void BST::InOrderPrint(BST_Node* Node, int depth){
	if(Node == NULL){
		return;
	}

	InOrderPrint(Node->Left, depth++);
	cout << Node->Data << " " ;
	InOrderPrint(Node->Right, depth++);
	return;
}


void BST::PrintTree(){
	InOrderPrint(Root,0);
	cout << endl;
	return;
}
