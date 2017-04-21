#include "DoubleLinkedList.h"
/*
typedef struct tagNode{
	int Data;
	struct tagNode* Prev;
	struct tagNode* Next;
}Node;
*/

Node* DLL_CreateNode(int NewData){
	Node* NewNode = (Node*)calloc(1,sizeof(Node));
	NewNode->Data = NewData;
	NewNode->Prev = NULL;
	NewNode->Next = NULL;

	return NewNode;
}

void DLL_DestroyNode(Node* Node){
	free(Node);
}


void DLL_AppendNode(Node** Head, Node* NewNode){
	if((*Head) == NULL){
		*Head = NewNode;
	}else {
		Node* Tail = (*Head);
		while(Tail->Next != NULL){
			Tail = Tail->Next;
		}

		Tail->Next = NewNode;
		NewNode->Prev = Tail;
	}
}

void DLL_InsertAfter(Node* Current, Node* NewNode){
	NewNode->Next = Current->Next;
	NewNode->Prev = Current;

	if(Current->Next != NULL){
		Current->Next->Prev = NewNode;
	}

	Current->Next = NewNode;
}


void DLL_RemoveNode(Node** Head, Node* Remove){
	if(*Head == Remove){
		*Head = Remove->Next;
		if((*Head) != NULL){
			(*Head)->Prev = NULL;
		}
		
		Remove->Prev = NULL;
		Remove->Next = NULL;
	}else {
		Node* Temp = Remove;

		if(Remove->Prev != NULL)
			Remove->Prev->Next = Temp->Next;

		if(Remove->Next != NULL)
			Remove->Next->Prev = Temp->Prev;

		Remove->Prev = NULL;
		Remove->Next = NULL;
	}

}

Node* DLL_GetNodeAt(Node* Head, int Location){
	Node* Current = Head;
	while(Current != NULL && (--Location) >=0){
		Current = Current->Next;
	}

	return Current;
}

int DLL_GetNodeCount(Node* Head){
	unsigned int cnt = 0;
	Node* Current = Head;

	while(Current != NULL){
		Current = Current->Next;
		cnt++;
	}
	
	return cnt;
}


int LinearSearch(Node* Head, int target){
	Node* Current = Head;

	while(Current != NULL){
		if(Current->Data == target){
			return 1;
		}
		Current = Current->Next;
	}
	return 0;
}


int LinearSearchMTF(Node** Head, int target){
	Node* Current = (*Head);

	while(Current != NULL){
		if(Current->Data == target){
			DLL_RemoveNode(Head, Current);		
			Current->Next = *Head;
			(*Head)->Prev = Current;
			(*Head) = Current;
			return 1;
		}
		Current = Current->Next;
	}
	return 0;
}

int LinearSearchTM(Node** Head, int target){
	Node* Current = (*Head);
	Node* PrevNode = NULL;
	Node* NextNode = NULL;

	while(Current != NULL){
		if(Current->Data == target){
			if(Current != (*Head)){
				PrevNode = Current->Prev;
				NextNode = Current->Next;
				PrevNode->Next = NextNode;
				if(NextNode != NULL){
					NextNode->Prev = PrevNode;
				}

				Current->Next = PrevNode;
				if(PrevNode == (*Head)){
					Current->Prev = NULL;
					(*Head) = Current;
				}else {
					Current->Prev = PrevNode->Prev;
					PrevNode->Prev->Next = Current;
				}
			}
			return 1;
		}
		Current = Current->Next;
	}
	return 0;

}

