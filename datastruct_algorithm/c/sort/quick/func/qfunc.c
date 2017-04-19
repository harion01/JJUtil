#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int CopareScore(const void *_elem1, const void *_elem2){
	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if(*elem1 > *elem2){
		return 1;
	}else if (*elem1 < *elem2){
		return -1;
	}

	return 0;
}

int main(void){

	int Dataset[] = {6,4,2,3,1,5};
	int len = sizeof(Dataset)/ sizeof(Dataset[0]) ;
	int i = 0;

	qsort((void*)Dataset, len, sizeof(int), CopareScore);

	for(i = 0; i<len; i++){
		printf("%d ", Dataset[i]);
	}

	printf("\n");



	return 0;
}
