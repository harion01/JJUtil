#ifndef PQ_H
#define PQ_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct tagPQNode{
	PriorityType Priority;
	void* Data;
}PQNode;

typedef struct tagPQ{
	PQNode* Nodes;
	int Capacity;
	int UsedSize;
}PriorityQueue;

PriorityQueue* PQ_Create(int InitSize);
void PQ_Destroy(PriorityQueue* H);
void PQ_Enqueue(PriorityQueue* H, PQNode NewData);
void PQ_Dequeue(PriorityQueue* H, PQNode* Root);
int PQ_GetParent(int Index);
int PQ_GetLeftChild(int Index);
void PQ_SwapNodes(PriorityQueue* H, int Index1, int Index2);
int PQ_IsEmpty(PriorityQueue* Q);

#endif
