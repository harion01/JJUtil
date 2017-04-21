#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode{
	int Data;
	struct tagNode* Prev;
	struct tagNode* Next;
}Node;

Node* DLL_CreateNode(int NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);


int LinearSearch(Node* Head, int target);

//search and move target node to front (Move To Front method)
int LinearSearchMTF(Node** Head, int target);

//search and move target node to one step forward (Transpose method)
int LinearSearchTM(Node** Head, int target);
#endif
