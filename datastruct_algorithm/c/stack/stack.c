#include "stack.h"

void ST_Push(ST_Stack* Stack  ,DataType NewData){
	ST_Node* NewNode = (ST_Node*)calloc(1,sizeof(ST_Node));
	NewNode->Data = NewData;
	NewNode->Next = NULL;

	if(Stack->ST_Top == NULL){
		Stack->ST_Top = NewNode;
	}else {
		NewNode->Next = Stack->ST_Top;
		Stack->ST_Top = NewNode;
	}
}

ST_Node* ST_Pop(ST_Stack* Stack){
	if(Stack->ST_Top == NULL ){
		return NULL;
	}
	ST_Node* ret;
	ret = Stack->ST_Top;
	if(Stack->ST_Top->Next != NULL){
		Stack->ST_Top = Stack->ST_Top->Next;
	}
	return ret;
}
