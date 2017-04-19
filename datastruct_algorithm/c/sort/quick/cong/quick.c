#include "Score.h"

#include <stdio.h>


void swap(Score* a, Score* b){
	Score swap;
	swap = *a;
	*a = *b;
	*b = swap;
}

int Partition(Score Dataset[], int left, int right){

	int first = left;
	Score pivot = Dataset[first];

	++left;

	while(left <= right){
		while(Dataset[left].score <= pivot.score && left < right)
			++left;

		while(Dataset[right].score > pivot.score && left <= right)
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

void quick(Score Dataset[], int left, int right){
	if(left < right){
		int index = Partition(Dataset, left, right);
		quick(Dataset, left, index-1);
		quick(Dataset, index+1, right);
	}
}


int main(){
	//int set[] = {6,4,3,1,2,5};
	//int set[] = {6,4,3,1,2,5};
	int len = sizeof(DataSetOri) / sizeof(DataSetOri[0]);
	quick(DataSetOri, 0, len-1);

	printf("ans : num[%d], score[%f]\n", DataSetOri[17213].number, DataSetOri[17213].score);

}
