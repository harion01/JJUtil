#include <stdlib.h>
#include <stdio.h>
#include "Score.h"

Score* BinarySearch(Score List[], int Size, double Target){
	int Left, Right, Mid;

	Left = 0 ;
	Right = Size -1;

	while(Left <= Right){
		Mid = (Left + Right)/2;

		if(Target == List[Mid].score){
			return &(List[Mid]);
		}else if(Target > List[Mid].score){
			Left = Mid+1;
		}else {
			Right = Mid-1;
		}

	}
	return NULL;
}

int CompareScore(const void *_elem1, const void *_elem2){
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if(elem1->score > elem2->score){
		return 1;
	}else if (elem1->score < elem2->score){
		return -1;
	}
	return 0;
}

int main(void){
	int Len = sizeof(DataSetOri)/sizeof(DataSetOri[0]) ;
	int i = 0;
	Score* found = NULL;

	qsort((void*) DataSetOri, Len, sizeof(Score), CompareScore);

	found = BinarySearch(DataSetOri, Len, 671.78);

	printf("found : %d %f \n", found->number, found->score);


	return 0;
}
