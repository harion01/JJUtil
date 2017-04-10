#include "SingleLinkedList.h"

//create Node
Node* SLL_CreateNode(ElementType NewData){
	Node* NewNode = (Node*)calloc(1,sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

//destroy node
void SLL_DestroyNode(Node* Node){
	free(Node);
}

//append node
void SLL_AppendNode(Node** Head, Node* NewNode){
	//if there is no Head, new one will be head
	if (NULL == (*Head)){
		*Head = NewNode;
	}else {
		//search tail and append new node
		Node* Tail = (*Head);
		while(NULL != Tail->NextNode){
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

//insert new head node
void SLL_InsertNewHead(Node** Head, Node* NewHead){
	//if there is no Head, new one will be head
	if (NULL == (*Head)){
		(*Head) = NewHead;
	}else {
		NewHead->NextNode = (*Head); //set next node address into argument head address 
		(*Head) = NewHead;  //change head address into new node
	}
}

//insert node to current position
void SLL_InsertAfter(Node* Current, Node* NewNode){
	NewNode->NextNode = Current->NextNode; 
	Current->NextNode = NewNode;
}

//remove node from list
void SLL_RemoveNode(Node** Head, Node* Remove){
	//if target is head, change head
	if(*Head == Remove){
		*Head = Remove->NextNode;
	}else {
		Node* Current = *Head;
		//search node before target
		while(NULL != Current && Current->NextNode != Remove){
			Current = Current->NextNode;
		}

		//disconnect link to target. and connect it to the next node of target
		if(NULL != Current){
			Current->NextNode = Remove->NextNode;
		}
	}
}

//Get node of Location 
Node* SLL_GetNodeAt(Node* Head, int Location){
	Node* Current = Head;
	
	//search node of Location
	while(Current != NULL && (--Location)>=0){
		Current = Current->NextNode;
	}

	return Current;
}

//count total numbers of node in List
int SLL_GetNodeCount(Node* Head){
	int count = 0;
	Node* Current = Head;

	while(Current != NULL){
		Current = Current->NextNode;
		count++;
	}
	return count;
}
