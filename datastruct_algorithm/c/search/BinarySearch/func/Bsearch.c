#include <stdlib.h>
#include <stdio.h>
#include "Score.h"

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
	Score target;
	Score* found = NULL;

	qsort((void*) DataSetOri, Len, sizeof(Score), CompareScore);

	target.number = 0;
	target.score = 671.78;
	
	found = bsearch(
		(void*)&target,
		(void*)DataSetOri,
		Len,
		sizeof(Score),
		CompareScore);


	printf("found : %d %f \n", found->number, found->score);


	return 0;
}
