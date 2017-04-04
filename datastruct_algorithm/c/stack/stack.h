#ifndef ST_HEAD
#define ST_HEAD

#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct _ST_Node{
	DataType Data;
	struct _ST_Node* Next;
}ST_Node;

typedef struct _ST_Stack{
	ST_Node* ST_Top;
}ST_Stack;


void ST_Push(ST_Stack* Stack, DataType data);

ST_Node* ST_Pop(ST_Stack* Stack);

#endif
