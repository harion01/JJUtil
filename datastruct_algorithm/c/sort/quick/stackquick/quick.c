#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct tagNode{
	int arg;
	struct tagNode* Next;
} Node;

Node* Top;

void push(int arg){
	Node* node;
	node = (Node*)calloc(1,sizeof(Node));
	node->arg = arg;
	node->Next = NULL;
	if(Top == NULL){
		Top = node;
	}else {
		node->Next = Top;
		Top = node;
	}
}

int pop(){
	if(Top == NULL){
		return -1;
	}

	int ret;
	Node* node;
	node = Top;
	ret = node->arg;
	Top = node->Next;
	free(node);
	
	return ret;
}



void swap(int* a, int* b){
	printf("swap \n");
	int swap;
	swap = *a;
	*a = *b;
	*b = swap;
}

int Partition(int Dataset[], int left, int right){

	int first = left;
	int pivot = Dataset[first];

	printf("\n");
	printf("left :%d , right:%d, pivot:%d", left,right,pivot);
	printf("======\n");
	for(int i =0 ; i<6; i++){
		printf("%d \n", Dataset[i]);
	}
	printf("======\n");

	++left;

	int count = 0;
	while(left <= right){
		count++;
		while(Dataset[left] <= pivot && left < right)
			++left;

		while(Dataset[right] > pivot && left <= right)
			--right;
	

		printf("left :%d , right:%d\n", left,right);
		if(left < right)
			swap(&Dataset[left], &Dataset[right]);
		else
			break;
	}

	swap(&Dataset[first], &Dataset[right]);
	
	if(count ==1){
		return -1;
	}

	return right;
}

void quick(int Dataset[], int left, int right){
	int index = Partition(Dataset, left, right);
	push(index);
	int popindex = pop();

	while(popindex < 0){
		index = Partition(Dataset, left, popindex-1);
		if(index > 0){
			push(index);
		}
		index = Partition(Dataset, popindex+1, right);
		if(index > 0){
			push(index);
		}
		popindex = pop();
	}
}


int main(){
	Top = NULL;
	//int set[] = {6,4,3,1,2,5};
	int set[] = {6,4,3,1,2,5};
	int len = sizeof(set) / sizeof(set[0]);
	quick(set, 0, len-1);

	int i;
	for(i =0 ; i<len; i++){
		printf("%d \n", set[i]);
	}
}
