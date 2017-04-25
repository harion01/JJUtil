#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagData
{
	int Key;
	char* Value;
}Data;

typedef Data ElementType;

typedef struct tagBSTNode{
	struct tagBSTNode* Left;
	struct tagBSTNode* Right;
	Data* DataNode;
}BSTNode;


BSTNode* BST_CreateNode(int Key, char* value);
void BST_DestroyNode(BSTNode* Node);
void BST_DestroyTree(BSTNode* Tree);

BSTNode* BST_SearchNode(BSTNode* Tree, int Target);
BSTNode* BST_SearchMinNode(BSTNode* Tree);
void BST_InsertNode(BSTNode* Tree, BSTNode* Child);
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, int Target);


void BST_InorderPrintTree(BSTNode* Node);

#endif
