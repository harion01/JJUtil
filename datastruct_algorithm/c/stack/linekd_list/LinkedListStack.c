#include "LinkedListStack.h"


void LLS_CreateStack(LinkedListStack** Stack){
	(*Stack) = (LinkedListStack*)calloc(1,sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack){
	while(!LLS_IsEmpty(Stack)){
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}
		
	free(Stack);
}

Node* LLS_CreateNode(char* Data){
	Node* NewNode = (Node*)calloc(1,sizeof(Node));
	NewNode->Data = (char*)calloc(1, (strlen(Data)+1));

	strncpy(NewNode->Data, Data, strlen(Data));

	NewNode->NextNode = NULL;

	return NewNode;
}

void LLS_DestroyNode(Node* _Node){
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode){
	if(Stack->List == NULL){
		Stack->List = NewNode;
		Stack->Top = NewNode;
	}else {
		Node* OldTop = Stack->List;
		while(OldTop->NextNode != NULL){
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;
		Stack->Top = NewNode;
	}
}

Node* LLS_Pop(LinkedListStack* Stack){
	Node* TopNode = Stack->Top;

	if(Stack->List == Stack->Top){
		Stack->List = NULL;
		Stack->Top = NULL;
	}else {
		Node* CurrendTop = Stack->List;
		while(CurrendTop->NextNode != Stack->Top){
			CurrendTop = CurrendTop->NextNode;
		}
		
		Stack->Top = CurrendTop;
		CurrendTop->NextNode = NULL;
	}

	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack){
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack){
	int count = 0;
	Node* CurrentTop = Stack->List;

	while(CurrentTop != NULL){
		CurrentTop = CurrentTop->NextNode;
		count++;
	}
	return count;
}

int LLS_IsEmpty(LinkedListStack* Stack){
	return (Stack->List == NULL);
}

