#ifndef CHAINING_HASH_TABLE_H
#define CHAINING_HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int KeyType;
typedef int ValueType;

typedef struct tagNode
{
	KeyType Key;
	ValueType Value;
} Node;

typedef Node* List;

typedef struct tagHashTable
{
	int TableSize;
	List* Table;
} HashTable;

HashTable* CHT_CreateHashTable(int TableSize);
void CHT_DestroyHashTable(HashTable* HT);

Node* CHT_CreateNode(KeyType Key, ValueType Value);
Node* CHT_DestroyNode(Node* TheNode);

void CHT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType CHT_Get(HashTable* HT, KeyType Key);
int CHT_Hash(KeyType Key, int KeyLength, int TableSize);

#endif
