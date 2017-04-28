#include "PriorityQueue.h"

void PrintNode(PQNode* Node){
	printf("name : %s (Priority : %d) \n", Node->Data, Node->Priority);
}


int main(void){
	PriorityQueue* PQueue = PQ_Create(3);
	PQNode Popped;

	PQNode Nodes[7] =
	{
		{34, (void*)"coding"},
		{12, (void*)"meeting"},
		{87, (void*)"coffee"},
		{45, (void*)"document"},
		{35, (void*)"debug"},
		{66, (void*)"shower"},
	};

	PQ_Enqueue(PQueue, Nodes[0]);
	PQ_Enqueue(PQueue, Nodes[1]);
	PQ_Enqueue(PQueue, Nodes[2]);
	PQ_Enqueue(PQueue, Nodes[3]);
	PQ_Enqueue(PQueue, Nodes[4]);
	PQ_Enqueue(PQueue, Nodes[5]);

	printf("Q element : %d \n", PQueue->UsedSize);
	while(!PQ_IsEmpty(PQueue)){
		PQ_Dequeue(PQueue, &Popped);
		PrintNode(&Popped);
	}

	return 0;
}
