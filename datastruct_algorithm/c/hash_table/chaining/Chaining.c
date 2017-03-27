#include "Chaining.h"


HashTable* CHT_CreateHashTable(int TableSize){
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (List*)malloc(sizeof(List)*TableSize);
	memset(HT->Table, 0x00, sizeof(List)*TableSize);

	HT->TableSize = TableSize;

	return HT;
}


Node* CHT_CreateNode(int Key, char* Value){
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Key = Key;
	NewNode->Value = (char*)malloc(sizeof(char)*(strlen(Value)+1));
	strcpy(NewNode->Value, Value);

	return NewNode;
}

void CHT_DestroyNode(Node* TheNode){
	free(TheNode->Value);
	free(TheNode);
}

void CHT_Set(HashTable* HT, int Key, char* Value){
	int Address = CHT_Hash(Key,  HT->TableSize);
	Node* NewNode = CHT_CreateNode(Key, Value);

	if(HT->Table[Address] == NULL){
		HT->Table[Address] = NewNode;
	}else { //use linked list for collision case
		List L = HT->Table[Address];
		NewNode->Next = L;
		HT-> Table[Address] = NewNode;
		printf("collision occured! \n");
	}
}

char* CHT_Get(HashTable* HT, int Key){
	int Address = CHT_Hash(Key, HT->TableSize);

	List TheList = HT->Table[Address];
	List Target = NULL;

	if(TheList == NULL)
		return NULL;

	while(1){
		if(TheList->Key == Key){
			Target = TheList;
			break;
		}

		if(TheList->Next == NULL){
			return NULL;
		}else{
			TheList = TheList->Next;
		}
	}

	return Target->Value;
}

void CHT_DestroyList( List L){
	if(L == NULL){
		return;
	}

	if(L->Next != NULL){ //recursive call for free all node
		CHT_DestroyNode(L->Next);
	}

	CHT_DestroyNode(L);
}


void CHT_DestroyHashTable(HashTable* HT){
	int i =0;
	for (i=0 ; i<HT->TableSize; i++){
		List L = HT->Table[i];
		CHT_DestroyList(L);
	}

	free(HT);

}

int CHT_Hash(int Key , int TableSize){

	return Key % TableSize;
}
