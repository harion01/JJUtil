#include "LinkedList.h"

Node* SLL_CreadNode(ElementType NewData){
	Node* NewNode = (Node*)calloc(1,sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_DestroyNode(Node* Node){
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode){
	//
	if (NULL == (*Head)){
		*Head = newNode;
	}else {
		Node* Tail = (*Head);
		while(NULL != Tail->NextNode){
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

void SLL_InsertNewHead(Node** Head, Node* NewHead){
	if (NULL == (*Head)){
		(*Head) = NewHead;
	}else {
		NewHead->NextNode = (*Head); //set next node address into argument head address 
		(*Head) = NewHead;  //change head address into new node
	}
}

void SLL_InsertAfter(Node* Current, Node* NewNode){
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NextNode;
}

int SLL_RemoveNode(Node** Head, Node* Remove){
	if(*Head == Remove){
		*Head = Remove->NextNode;
	}else {
		Node* Current = *Head;
		while(NULL != Current && Current->NextNode != Remove){
			Current = Current->NextNode;
		}

		if(NULL != Current){
			Current->NextNode = Remove->NextNode;
		}else {
			return -1;
		}
	}
}

Node* SLL_GetNodeAT(){
}


//
int SLL_SetNode(Node** Head, Node* NewNode, int Position){
	if (0 == Position){
		if(NULL == (*Head)){
			*Head = NewNode;
		}else{
			NewNode->NextNode = *Head;
			*Head = NewNode;
		}
	}else {
		Node* Node = (*Head);
		while(0< Position){
			if(NULL == Node->NextNode){
				return -1;
			}
			Node = Node->NextNode;
			Position--;
		}
		//what about current node?
	}
	return 0;
}
