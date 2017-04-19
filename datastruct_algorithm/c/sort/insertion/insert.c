#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void insert(int set[], int size){
	for(int i=1; i< size; i++){
		if(set[i-1] <= set[i])
			continue;
		
		int value = set[i];
		
		for(int j = 0 ; j<i; j++){
			if(set[j] > value){
				memmove(&set[j+1], &set[j], sizeof(set[0])*(i-j));
				set[j] = value;
				break;
			}
		}
	}
}

int main(){
	
	int set[] = {6,4,3,1,2,5};
	int len = sizeof(set) / sizeof(set[0]);
	insert(set, len);

	int i;
	for(i =0 ; i<len; i++){
		printf("%d \n", set[i]);
	}




	return 0;
}
