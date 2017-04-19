#include <stdio.h>



void bubble(int set[], int size){
	int i;
	int j;
	int count ;
	//int swap;
	for(i = 0 ; i < size ; i++){
		count =0;
		for(j = 0 ; j < size - i -1 ; j++){
			count ++;
			if(set[j] < set[j+1]){
				count = 0;
				/*
				swap = set[j];
				set[j] = set[j+1];
				set[j+1] = swap;
				*/
				set[j] = set[j]^set[j+1];
				set[j+1] = set[j+1]^set[j];
				set[j] = set[j]^set[j+1];
			}
			if(count == size-1){
				printf("aready sorted! \n");
				return;
			}
		}
	}
}

int main(void){
	//int set[] = {6,4,3,1,2,5};
	int set[] = {6,5,4,3,2,1};
	int len = sizeof(set) / sizeof(set[0]);
	bubble(set, len);
	
	int i;
	for(i =0 ; i<len; i++){
		printf("%d \n", set[i]);
	}

	return 0;
}
