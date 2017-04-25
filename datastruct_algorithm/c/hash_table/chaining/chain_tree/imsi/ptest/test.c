#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagimsi{
	int key;
	char* data;
}imsi;

typedef struct tagtest{
	imsi* Data;
}test;

void copy(test* a, test* b){
	a->Data = b->Data;
}



int main(void){
	test* p1;
	test* p2;
	test* p3;
	
	p2 = (test*)malloc(sizeof(test));
	p3 = (test*)malloc(sizeof(test));
	p2->Data = (imsi*)calloc(1, sizeof(imsi));
	p2->Data->key = 1;
	p2->Data->data = (char*)calloc(10, sizeof(char));
	sprintf(p2->Data->data, "%s" , "123456789");
	p1 = p2;
	copy(p3, p2);

	printf("p2: %d, %s \n", p2->Data->key, p2->Data->data);
	printf("p1: %d, %s \n", p1->Data->key, p1->Data->data);

	copy(p3, p2);
	free(p2);
	p2 = NULL;
	printf("p3: %d, %s \n", p3->Data->key, p3->Data->data);

	
	return 0;
}
