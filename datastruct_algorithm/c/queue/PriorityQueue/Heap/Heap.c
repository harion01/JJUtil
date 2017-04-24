#include "Heap.h"
/*
typedef int ElementType;

typedef struct tagHeapNode{
	ElementType Data;
}HeapNode;

typedef struct tagHeap{
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
}Heap;
*/

Heap* HEAP_Create(int InitSize){
	Heap* NewHeap = (Heap*)calloc(1, sizeof(Heap));
	NewHeap->Capacity = InitSize;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (HeapNode*)calloc(NewHeap->Capacity, sizeof(HeapNode));

	printf("size : %d\n", sizeof(HeapNode));

	return NewHeap;
}

void HEAP_Destroy(Heap* H){
	free(H->Nodes);
	free(H);
}

void HEAP_Insert(Heap* H, ElementType NewData){
	int CurrentPosition = H->UsedSize; //last data.
	int ParentPosition = HEAP_GetParent(CurrentPosition);

	//when capacity is full, reallocate memory
	if(H->UsedSize == H->Capacity){
		H->Capacity *=2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}

	H->Nodes[CurrentPosition].Data = NewData; //insert data into last position
	
	//swap every parent and target which has larger value than it's parent
	while(CurrentPosition > 0 
		&& H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data){

		HEAP_SwapNodes(H, CurrentPosition, ParentPosition);
		//check changed node and it's parent again
		CurrentPosition =  ParentPosition;
		ParentPosition = HEAP_GetParent(CurrentPosition);
	}

	H->UsedSize++;
}

void HEAP_DeleteMin(Heap* H, HeapNode* Root){
	int ParentPosition = 0;
	int LeftPosition = 0;
	int RightPosition = 0;

	memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
	memset(&H->Nodes[0], 0, sizeof(HeapNode)); //delete root

	H->UsedSize--;
	HEAP_SwapNodes(H,0,H->UsedSize); //move last data to root
	
	LeftPosition = HEAP_GetLeftChild(0); 
	RightPosition = LeftPosition+1;

	while(1){
		int SelectedChild = 0;
		
		//No child
		if(LeftPosition >= H->UsedSize){
			break; 
		}
		
		//there is no right child
		if(RightPosition >= H->UsedSize){
			SelectedChild = LeftPosition;
		}else {	
			//selectchild = smaller value
			if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data){
				SelectedChild = RightPosition;
			}else {
				SelectedChild = LeftPosition;
			}
		}
	
		//check parent and child
		if(H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data){
			HEAP_SwapNodes(H, ParentPosition, SelectedChild);
			ParentPosition = SelectedChild;
		}else {
			break;
		}
		
		LeftPosition = HEAP_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition+1;
	}
	
	//when there is too many idle nodes, reallocate memory
	if(H->UsedSize < (H->Capacity / 2)){
		H->Capacity /= 2;
		H->Nodes = (HeapNode*) realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}

}

int HEAP_GetParent(int Index){
	return (int) ((Index-1) /2);
}

int HEAP_GetLeftChild(int Index){
	return (2*Index)+1;
}

void HEAP_SwapNodes(Heap* H, int Index1, int Index2){
	HeapNode* Temp = (HeapNode*)calloc(1,sizeof(HeapNode));
	memcpy(Temp, &H->Nodes[Index1], sizeof(HeapNode));
	memcpy(&H->Nodes[Index1], &H->Nodes[Index2], sizeof(HeapNode));
	memcpy(&H->Nodes[Index2], Temp, sizeof(HeapNode));
	
	free(Temp);
}

void HEAP_PrintNodes(Heap* H){
	int i = 0;
	for(i = 0 ; i < H->UsedSize; i++){
		printf("%d ", H->Nodes[i].Data);
	}
	printf("\n");
}


