#include "CircularQ.h"

int main(){
	
	int i;
	CircularQueue* Queue;
	CQ_CreateQueue(&Queue, 10);

	CQ_Enqueue(Queue, 1);
	CQ_Enqueue(Queue, 2);
	CQ_Enqueue(Queue, 3);
	CQ_Enqueue(Queue, 4);

	for ( i = 0 ; i<3; i++){
		printf("Dequeue : %d, ", CQ_Dequeue(Queue));
		printf("Front : %d, Rear : %d\n", Queue->Front, Queue->Rear);
		printf("Capacity : %d, Size : %d \n\n", Queue->Capacity, CQ_GetSize(Queue));
	}

	printf("insert untill queue full\n");
	i = 100;
	while(0 == CQ_IsFull(Queue)){
		CQ_Enqueue(Queue, i++);	
	}
	printf("Capacity : %d, Size : %d \n\n", Queue->Capacity, CQ_GetSize(Queue));

	while(0 == CQ_IsEmpty(Queue)){
		printf("Dequeue : %d, ", CQ_Dequeue(Queue));
		printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
	}
	
	printf("Capacity : %d, Size : %d \n\n", Queue->Capacity, CQ_GetSize(Queue));
	CQ_FreeQueue(Queue);

	return 0;
}
