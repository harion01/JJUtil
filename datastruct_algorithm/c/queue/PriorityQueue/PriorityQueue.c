#include "PriorityQueue.h"
/*
typedef int ElementType;

typedef struct tagPQNode{
	ElementType Data;
}PQNode;

typedef struct tagPQ{
	PQNode* Nodes;
	int Capacity;
	int UsedSize;
}PQ;
*/

PriorityQueue* PQ_Create(int InitSize){
	PriorityQueue* NewPQ = (PriorityQueue*)calloc(1, sizeof(PriorityQueue));
	NewPQ->Capacity = InitSize;
	NewPQ->UsedSize = 0;
	NewPQ->Nodes = (PQNode*)calloc(NewPQ->Capacity, sizeof(PQNode));

	printf("size : %d\n", sizeof(PQNode));

	return NewPQ;
}

void PQ_Destroy(PriorityQueue* H){
	free(H->Nodes);
	free(H);
}

void PQ_Enqueue(PriorityQueue* H, PQNode NewData){
	int CurrentPosition = H->UsedSize; //last data.
	int ParentPosition = PQ_GetParent(CurrentPosition);

	//when capacity is full, reallocate memory
	if(H->UsedSize == H->Capacity){
		if(H->Capacity ==0){
			H->Capacity = 1;
		}

		H->Capacity *=2;
		H->Nodes = (PQNode*)realloc(H->Nodes, sizeof(PQNode) * H->Capacity);
	}

	H->Nodes[CurrentPosition] = NewData; //insert data into last position
	
	//swap every parent and target which has larger value than it's parent
	while(CurrentPosition > 0 
		&& H->Nodes[CurrentPosition].Priority< H->Nodes[ParentPosition].Priority){

		PQ_SwapNodes(H, CurrentPosition, ParentPosition);
		//check changed node and it's parent again
		CurrentPosition =  ParentPosition;
		ParentPosition = PQ_GetParent(CurrentPosition);
	}

	H->UsedSize++;
}

void PQ_Dequeue(PriorityQueue* H, PQNode* Root){
	int ParentPosition = 0;
	int LeftPosition = 0;
	int RightPosition = 0;

	memcpy(Root, &H->Nodes[0], sizeof(PQNode));
	memset(&H->Nodes[0], 0, sizeof(PQNode)); //delete root

	H->UsedSize--;
	PQ_SwapNodes(H,0,H->UsedSize); //move last data to root
	
	LeftPosition = PQ_GetLeftChild(0); 
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
			if (H->Nodes[LeftPosition].Priority > H->Nodes[RightPosition].Priority){
				SelectedChild = RightPosition;
			}else {
				SelectedChild = LeftPosition;
			}
		}
	
		//check parent and child
		if(H->Nodes[SelectedChild].Priority < H->Nodes[ParentPosition].Priority){
			PQ_SwapNodes(H, ParentPosition, SelectedChild);
			ParentPosition = SelectedChild;
		}else {
			break;
		}
		
		LeftPosition = PQ_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition+1;
	}
	
	//when there is too many idle nodes, reallocate memory
	if(H->UsedSize < (H->Capacity / 2)){
		H->Capacity /= 2;
		H->Nodes = (PQNode*) realloc(H->Nodes, sizeof(PQNode) * H->Capacity);
	}

}

int PQ_GetParent(int Index){
	return (int) ((Index-1) /2);
}

int PQ_GetLeftChild(int Index){
	return (2*Index)+1;
}

void PQ_SwapNodes(PriorityQueue* H, int Index1, int Index2){
	PQNode* Temp = (PQNode*)calloc(1,sizeof(PQNode));
	memcpy(Temp, &H->Nodes[Index1], sizeof(PQNode));
	memcpy(&H->Nodes[Index1], &H->Nodes[Index2], sizeof(PQNode));
	memcpy(&H->Nodes[Index2], Temp, sizeof(PQNode));
	
	free(Temp);
}


