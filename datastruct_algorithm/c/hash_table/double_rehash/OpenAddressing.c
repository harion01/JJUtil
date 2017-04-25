#include "OpenAddressing.h"


HashTable* OAHT_CreateHashTable(int TableSize){
	HashTable* NewHT = (HashTable*)calloc(1, sizeof(HashTable));
	NewHT->Table = (ElementType*)calloc(TableSize, sizeof(ElementType));
	NewHT->OccupiedCount = 0;
	NewHT->TableSize = TableSize;
	
	return NewHT;
}

void OAHT_Set(HashTable** HT, KeyType Key, ValueType Value){
	int KeyLen, Address, StepSize;
	double Usage;

	Usage = (double)(*HT)->OccupiedCount / (*HT)->TableSize;
	
	//reallocate memory of hash table when usage is over than 50%
	if(Usage > 0.5){
		OAHT_Rehash(HT);
	}

	KeyLen = strlen(Key);
	Address = OAHT_Hash(Key,KeyLen,(*HT)->TableSize);
	StepSize = OAHT_Hash2(Key,KeyLen,(*HT)->TableSize);
	
	//loop until find empty space 
	while((*HT)->Table[Address].Status != EMPTY &&
		strcmp((*HT)->Table[Address].Key, Key) !=0){
		printf("Collision ocured! : Key[%s], Address[%d], StepSize[%d]\n"
			, Key, Address, StepSize);
		Address = (Address + StepSize) % (*HT)->TableSize;
	}
	
	//if there is data with same key, replace it.
	OAHT_ClearElement(&(*HT)->Table[Address]);

	(*HT)->Table[Address].Key = (char*)calloc(KeyLen+1,sizeof(char));
	strcpy((*HT)->Table[Address].Key, Key);

	(*HT)->Table[Address].Value = (char*)calloc(strlen(Value)+1, sizeof(char));
	strcpy((*HT)->Table[Address].Value, Value);

	(*HT)->Table[Address].Status = OCCUPIED;
	(*HT)->OccupiedCount++;

	printf("Key[%s], entered ad address[%d]\n", Key, Address);
}



void OAHT_DestroyHashTable(HashTable* HT){
	int i=0;
	for(i=0; i<HT->TableSize; i++){
		OAHT_ClearElement(&(HT->Table[i]));
	}

	free(HT->Table);
	free(HT);
}

void OAHT_ClearElement(ElementType* Element){
	if(Element->Status == EMPTY){
		return;
	}

	free(Element->Key);
	free(Element->Value);
}

ValueType OAHT_Get(HashTable* HT, KeyType Key){
	int KeyLen = strlen(Key);
	int Address = OAHT_Hash(Key, KeyLen, HT->TableSize);
	int StepSize = OAHT_Hash2(Key, KeyLen, HT->TableSize);

	while(HT->Table[Address].Status != EMPTY &&
		strcmp(HT->Table[Address].Key, Key) !=0){
		Address = (Address + StepSize) % HT->TableSize;
	}
	
	return HT->Table[Address].Value;
}


int OAHT_Hash(KeyType Key, int KeyLength, int TableSize){
	int i =0;
	int HashValue = 0;

	for(i = 0; i<KeyLength; i++){
		HashValue = (HashValue << 3) + Key[i];
	}

	HashValue = HashValue % TableSize;

	return HashValue;
}

int OAHT_Hash2(KeyType Key, int KeyLength, int TableSize){
	int i = 0;
	int HashValue = 0;

	for(i = 0 ; i < KeyLength; i++){
		HashValue = (HashValue << 2) + Key[i];
	}
	
	//change tablesize value for different hash value from hash1
	HashValue = HashValue % (TableSize - 3);
	
	return HashValue+1;
}

void OAHT_Rehash(HashTable** HT){
	int i = 0;
	ElementType* OldTable = (*HT)->Table;
	
	//create new hash table
	HashTable* NewHT = OAHT_CreateHashTable((*HT)->TableSize * 2);
	printf("\n Reashed. New table size if [%d]\n\n", NewHT->TableSize);
	
	//migrate data
	for(i = 0; i <(*HT)->TableSize; i++){
		if(OldTable[i].Status == OCCUPIED){
			OAHT_Set(&NewHT, OldTable[i].Key, OldTable[i].Value);
		}
	}
	
	OAHT_DestroyHashTable((*HT));

	(*HT) = NewHT;
}

