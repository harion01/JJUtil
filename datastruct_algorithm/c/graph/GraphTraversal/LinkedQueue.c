#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** Queue){
	(*Queue	) = (LinkedQueue*)calloc(1, sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}
void LQ_DestroyQueue(LinkedQueue* Queue){
	while(!LQ_IsEmpty(Queue)){
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Popped);
	}

	free(Queue);
}

Node* LQ_CreateNode(Vertex* NewData){
	Node* NewNode = (Node*)calloc(1,sizeof(Node));
	NewNode->Data = (Vertex*)calloc(1,sizeof(Vertex)); //memory allocate for data 
	memcpy(NewNode->Data ,NewData, sizeof(Vertex));

	NewNode->NextNode = NULL;

	return NewNode;
}

void LQ_DestroyNode(Node* _Node){
	free(_Node->Data);
	free(_Node);
}

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode ){
	if (Queue->Front == NULL){
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}else {
		Queue->Rear->NextNode = NewNode; //last input at Rear
		Queue->Rear = NewNode;
		Queue->Count++;
	}

}


Node* LQ_Dequeue(LinkedQueue* Queue){
	Node* imsi;
	if(Queue->Front == NULL){
		return NULL;
	}else {
		imsi = Queue->Front;
		if(Queue->Front->NextNode != NULL){
			Queue->Front = Queue->Front->NextNode;
		} else if(Queue->Front->NextNode == NULL){
			Queue->Front = NULL;
			Queue->Rear = NULL;
		}
	}
	Queue->Count--;
	return imsi;
}

int LQ_IsEmpty(LinkedQueue* Queue){
	return (Queue->Front == NULL);
}
