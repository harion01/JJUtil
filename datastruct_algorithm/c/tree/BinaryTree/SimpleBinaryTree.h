#ifndef BINARY+TREE_H
#define BINARY+TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNode{
	ElementType Data;
	struct tagSBTNode* Left;
	struct tagSBTNode* Right;
} SBTNode;

SBTNode* SBT_CreateNode(ElementType NewData);
void SBT_DestroyTree(SBTNode* Root);

void SBT_DestroyNode(SBTNode* Node);
void SBT_PrintPreorderTree(SBTNode* Node);
void SBT_PrintInorderTree(SBTNode* Node);
void SBT_PrintPostorderTree(SBTNode* Node);

#endif
