#include "stack.h"

int main(){
	ST_Stack Stack;
	Stack.ST_Top = NULL;
	
	ST_Push(&Stack, 'A');
	ST_Push(&Stack, 'B');
	ST_Push(&Stack, 'C');

	ST_Node* ret = ST_Pop(&Stack);
	printf("%c\n", ret->Data);
	free(ret);

	ret = ST_Pop(&Stack);
	printf("%c\n", ret->Data);
	free(ret);

	ret = ST_Pop(&Stack);
	printf("%c\n", ret->Data);
	free(ret);

	return 0;
}
