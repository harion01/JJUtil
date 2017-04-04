#include "SimpleBinaryTree.h"


SBTNode* SBT_CreateNode(ElementType NewData){
	SBTNode* NewNode = (SBTNode*)calloc(1,sizeof(SBTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void SBT_DestroyNode(SBTNode* Node){
	free(Node);
}

void SBT_DestroyTree(SBTNode* Root){
	if(Root == NULL){
		return;
	}
	
	SBT_DestroyNode(Root->Left);

	SBT_DestroyNode(Root->Right);

	SBT_DestroyNode(Root);
}



void SBT_PrintPreorderTree(SBTNode* Node){
	if(Node == NULL){
		return;
	}

	printf("%c\n", Node->Data);

	SBT_PrintPreorderTree(Node->Left);

	SBT_PrintPreorderTree(Node->Right);
}

void SBT_PrintInorderTree(SBTNode* Node){
	if(Node == NULL){
		return;
	}

	SBT_PrintInorderTree(Node->Left);

	printf("%c\n", Node->Data);

	SBT_PrintInorderTree(Node->Right);
}

void SBT_PrintPostorderTree(SBTNode* Node){
	if(Node == NULL){
		return;
	}

	SBT_PrintPostorderTree(Node->Left);


	SBT_PrintPostorderTree(Node->Right);

	printf("%c\n", Node->Data);
}
