#include <stdio.h>


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

	while(left <= right){
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


	return right;
}

void quick(int Dataset[], int left, int right){
	if(left < right){
		int index = Partition(Dataset, left, right);
		quick(Dataset, left, index-1);
		quick(Dataset, index+1, right);
	}
}


int main(){
	//int set[] = {6,4,3,1,2,5};
	int set[] = {6,4,3,1,2,5};
	int len = sizeof(set) / sizeof(set[0]);
	quick(set, 0, len-1);

	int i;
	for(i =0 ; i<len; i++){
		printf("%d \n", set[i]);
	}
}
