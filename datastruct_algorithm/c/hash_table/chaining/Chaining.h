#ifndef CHAINING_HASH_TABLE_H
#define CHAINING_HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	int Key;
	char* Value;
	struct tagNode* Next;
} Node;

typedef Node* List;

typedef struct tagHashTable
{
	int TableSize;
	Node** Table;
} HashTable;

HashTable* CHT_CreateHashTable(int TableSize);
void CHT_DestroyHashTable(HashTable* HT);

Node* CHT_CreateNode(int Key, char* Value);
void CHT_DestroyNode(Node* TheNode);

void CHT_Set(HashTable* HT, int Key, char* Value);
char* CHT_Get(HashTable* HT, int Key);
int CHT_Hash(int Key, int TableSize);

#endif
