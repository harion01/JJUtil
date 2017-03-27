#include "LinkedQueue.h"

int main(){
	
	Node* Poped;
	LinkedQueue* Queue;

	LQ_CreateQueue(&Queue);
	LQ_Enqueue(Queue, LQ_CreateNode("abc"));
	LQ_Enqueue(Queue, LQ_CreateNode("ABC"));
	LQ_Enqueue(Queue, LQ_CreateNode("def"));
	LQ_Enqueue(Queue, LQ_CreateNode("DEF"));

	printf("Queue Size : %d\n", Queue->Count);
	while(LQ_IsEmpty(Queue) == 0){
		Poped = LQ_Dequeue(Queue);
		printf("Dqueue data : %s \n", Poped->Data);
		LQ_DestroyNode(Poped);

	}

	LQ_DestroyQueue(Queue);

	
	return 0;
}
