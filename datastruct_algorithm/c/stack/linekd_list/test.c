#include "LinkedListStack.h"

int main(){
	
	int count;
	Node* Popped;
	LinkedListStack* Stack;

	LLS_CreateStack(&Stack);

	LLS_Push(Stack, LLS_CreateNode("abc"));
	LLS_Push(Stack, LLS_CreateNode("def"));
	LLS_Push(Stack, LLS_CreateNode("efg"));
	LLS_Push(Stack, LLS_CreateNode("hij"));


	while(!LLS_IsEmpty(Stack)){
		count = LLS_GetSize(Stack);
		printf("Size: %d, Top: %s\n\n", count, LLS_Top(Stack)->Data);
		Popped = LLS_Pop(Stack);
		printf(" Popped : %s, ", Popped->Data);

		LLS_DestroyNode(Popped);
		if(LLS_Top(Stack) != NULL){
			printf(" Current Top : %s \n", LLS_Top(Stack)->Data);
		} else {
			printf(" Current Top is null\n");
		}
	}
	
	LLS_DestroyStack(Stack);

	
	return 0;
}
