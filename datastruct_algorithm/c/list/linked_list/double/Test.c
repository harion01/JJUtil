#include "DoubleLinkedList.h"

int main(){
	int i = 0;
	int cnt = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	for(i = 0 ; i < 5; i++){
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	cnt = DLL_GetNodeCount(List);
	for(i = 0 ; i<cnt; i++){
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d \n", i, Current->Data);
	}
	
	printf("insert test \n");
	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	cnt = DLL_GetNodeCount(List);
	for(i = 0 ; i<cnt; i++){
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d \n", i, Current->Data);
	}


	cnt = DLL_GetNodeCount(List);
	for(i = 0 ; i<cnt; i++){
		Current = DLL_GetNodeAt(List, 0);
		if(Current != NULL){
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}
	
	return 0;
}
