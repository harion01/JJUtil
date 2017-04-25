#include "BinarySearchTree.h"
/*
typedef int ElementType;

typedef struct tagBSTNode{
	struct tagBSTNode* Left;
	struct tagBSTNode* Right;
	ElementType Data;
}BSTNode;
*/

BSTNode* BST_CreateNode(int key, char* value ){
	BSTNode* NewNode= (BSTNode*)calloc(1,sizeof(BSTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->DataNode = (Data*)calloc(1,sizeof(Data));
	NewNode->DataNode->Key = key;
	NewNode->DataNode->Value = (char*)malloc(sizeof(char)*(strlen(value)+1));
	strcpy(NewNode->DataNode->Value, value);

	return NewNode;
}

void BST_DestroyNode(BSTNode* Node){
	free(Node->DataNode->Value);
	free(Node->DataNode);
	free(Node);
}

void BST_DestroyTree(BSTNode* Tree){
	if(Tree->Right != NULL){
		BST_DestroyTree(Tree->Right);
	}

	if(Tree->Left != NULL){
		BST_DestroyTree(Tree->Left);
	}

	Tree->Left = NULL;
	Tree->Right = NULL;

	BST_DestroyNode(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, int Target){
	if(Tree==NULL){
		return NULL;
	}

	printf("Target : %d Tree : %d \n", Target, Tree->DataNode->Key);
	
	if(Tree->DataNode->Key < Target){
		return BST_SearchNode(Tree->Right, Target);
	}else if(Tree->DataNode->Key > Target){
		return BST_SearchNode(Tree->Left, Target);
	}

	return Tree;
}


BSTNode* BST_SearchMinNode(BSTNode* Tree){
	if(Tree == NULL){
		return NULL;
	}

	if(Tree->Left == NULL){
		return Tree;
	}else {
		return BST_SearchMinNode(Tree->Left);
	}
}


void BST_InsertNode(BSTNode* Tree, BSTNode* Child){
	if(Tree->DataNode->Key < Child->DataNode->Key){
		if(Tree->Right == NULL){
			Tree->Right = Child;
		}else {
			BST_InsertNode(Tree->Right, Child);
		}
	}else if(Tree->DataNode->Key > Child->DataNode->Key){
		if(Tree->Left == NULL){
			Tree->Left = Child;
		}else {
			BST_InsertNode(Tree->Left, Child);
		}
	}else{
		//if same key, replace data
		printf("Replace Data \n");
		free(Tree->DataNode->Value);
		Tree->DataNode = Child->DataNode;
	}
}


BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, int Target){
	BSTNode* Removed = NULL;

	if(Tree == NULL){
		return NULL;
	}

	if(Tree->DataNode->Key > Target){
		Removed = BST_RemoveNode(Tree->Left, Tree, Target);
	}else if (Tree->DataNode->Key < Target){
		Removed = BST_RemoveNode(Tree->Right, Tree, Target);
	}else { //found target
		Removed = Tree;
		
		//when target is leaf node, remove directly.
		if(Tree->Left == NULL && Tree->Right == NULL){
			if(Parent->Left == Tree){
				Parent->Left = NULL;
			}else {
				Parent->Right= NULL;
			}
		} else {
			//when target have both left and right, 
			//find the min value node and move it to current position.
			if(Tree->Left != NULL && Tree->Right != NULL){
				BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
				MinNode = BST_RemoveNode(Tree, NULL, MinNode->DataNode->Key);
				Tree->DataNode = MinNode->DataNode;


			//when target have left or right child,
			//remove target and connect child to current position.
			}else {
				BSTNode* Temp = NULL;
				if(Tree->Left != NULL){
					Temp = Tree->Left;
				}else{
					Temp = Tree->Right;
				}
				
				if(Parent->Left == Tree){
					Parent->Left = Temp;
				}else {
					Parent->Right = Temp;
				}
			}
		}
	}

	return Removed;
}

void BST_InorderPrintTree(BSTNode* Node){
	if(Node == NULL){
		return;
	}
	
	BST_InorderPrintTree(Node->Left);
	printf("key: %d ,value :%s \n", Node->DataNode->Key, Node->DataNode->Value );
	BST_InorderPrintTree(Node->Right);

}

