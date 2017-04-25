#include "Chaining.h"


HashTable* CHT_CreateHashTable(int TableSize){
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (List*)malloc(sizeof(List)*TableSize);
	memset(HT->Table, 0x00, sizeof(List)*TableSize);

	HT->TableSize = TableSize;

	return HT;
}

void CHT_Set(HashTable* HT, int Key, char* Value){
	int Address = CHT_Hash(Key,  HT->TableSize);

	if(HT->Table[Address] == NULL){
		HT->Table[Address] = BST_CreateNode(Key, Value);
	//chain data by using BST 
	}else{
		BST_InsertNode(HT->Table[Address], BST_CreateNode(Key, Value));
	}
}

char* CHT_Get(HashTable* HT, int Key){
	int Address = CHT_Hash(Key, HT->TableSize);

	List TheList = HT->Table[Address];
	BST_InorderPrintTree(TheList);
	BSTNode* ret = BST_SearchNode(TheList, Key);
	if(ret == NULL){
		return NULL;
	}
	printf("ret :%d,%s\n",ret->DataNode->Key, ret->DataNode->Value);

	return ret->DataNode->Value;
}

void CHT_DestroyList( List L){
	if(L == NULL){
		return;
	}
	
	BST_DestroyTree(L);
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
