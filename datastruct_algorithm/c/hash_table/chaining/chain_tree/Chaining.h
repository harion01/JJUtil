#ifndef CHAINING_HASH_TABLE_H
#define CHAINING_HASH_TABLE_H

#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagHashTable
{
	int TableSize;
	BSTNode** Table;
} HashTable;
typedef BSTNode* List;

HashTable* CHT_CreateHashTable(int TableSize);
void CHT_DestroyHashTable(HashTable* HT);

void CHT_Set(HashTable* HT, int Key, char* Value);
char* CHT_Get(HashTable* HT, int Key);
int CHT_Hash(int Key, int TableSize);

#endif
