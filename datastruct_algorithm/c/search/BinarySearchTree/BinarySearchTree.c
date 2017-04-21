#include "BinarySearchTree.h"
/*
typedef int ElementType;

typedef struct tagBSTNode{
	struct tagBSTNode* Left;
	struct tagBSTNode* Right;
	ElementType Data;
}BSTNode;
*/

BSTNode* BST_CreateNode( ElementType NewData){
	BSTNode* NewNode= (BSTNode*)calloc(1,sizeof(BSTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	return NewNode;
}

void BST_DestroyNode(BSTNode* Node){
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

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target){
	if(Tree==NULL){
		return NULL;
	}
	
	if(Tree->Data < Target){
		return BST_SearchNode(Tree->Left, Target);
	}else if(Tree->Data > Target){
		return BST_SearchNode(Tree->Right, Target);
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
	if(Tree->Data < Child->Data){
		if(Tree->Right == NULL){
			Tree->Right = Child;
		}else {
			BST_InsertNode(Tree->Right, Child);
		}
	}else if(Tree->Data > Child->Data){
		if(Tree->Left == NULL){
			Tree->Left = Child;
		}else {
			BST_InsertNode(Tree->Left, Child);
		}
	}
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target){
	BSTNode* Removed = NULL;

	if(Tree == NULL){
		return NULL;
	}

	if(Tree->Data > Target){
		Removed = BST_RemoveNode(Tree->Left, Tree, Target);
	}else if (Tree->Data < Target){
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
				MinNode = BST_RemoveNode(Tree, NULL, MinNode->Data);
				Tree->Data = MinNode->Data;

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
	printf("%d ", Node->Data);
	BST_InorderPrintTree(Node->Right);

}

