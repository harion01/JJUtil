#include "CircularQ.h"

void CQ_CreateQueue(CircularQueue** Queue, int Capacity){
	(*Queue) = (CircularQueue*)calloc(1,sizeof(CircularQueue));
	(*Queue)->Nodes = (Node*)calloc(Capacity, sizeof(Node));
	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_FreeQueue(CircularQueue* Queue){
	free(Queue->Nodes);
	free(Queue);
}

void CQ_Enqueue(CircularQueue* Queue, ElementType Data){
	int Position = 0;

	//When Rear meats end of capacity, change position for circular operation
	if(Queue->Rear == Queue->Capacity){ 
		Position = Queue->Rear;
		Queue->Rear = 0;

	}else {
		Position = Queue->Rear++; //keep move Rear position
	}
	
	Queue->Nodes[Position].Data = Data; //Data insert
}

ElementType CQ_Dequeue(CircularQueue* Queue){
	int Position = Queue->Front;

	//When Front meats end of capacity, change position for circular operation
	if(Queue->Front == Queue->Capacity){
		Queue->Front = 0;
	}else {
		Queue->Front++;
	}

	return Queue->Nodes[Position].Data;
}

int CQ_IsEmpty(CircularQueue* Queue){
	return (Queue->Front == Queue->Rear);
}

int CQ_IsFull(CircularQueue* Queue){
	if(Queue->Front < Queue->Rear){
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	}else {
		return (Queue->Rear + 1 ) == Queue->Front;
	}
}

int CQ_GetSize(CircularQueue* Queue){
	if (Queue->Front <= Queue-> Rear ){
		return Queue->Rear - Queue->Front;
	}else {
		return Queue->Rear + (Queue->Capacity - Queue->Front) +1 ;
	}

}
