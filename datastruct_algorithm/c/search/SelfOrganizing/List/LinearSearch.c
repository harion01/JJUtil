#include <stdio.h>


int LinearSearchMTF(int Set[], int target, int size){
	int i = 0;
	for(i = 0 ; i < size ; i++){
		if(Set[i] == target){
			for(int j = i; j > 0 ; j--){
				Set[j] = Set[j-1];
			}
			Set[0] = target;

			return 1;
		}
	}
	return 0;
}

int LinearSearchTM(int Set[], int target, int size){
	int i = 0;
	for(i = 0 ; i < size ; i++){
		if(Set[i] == target){
			if(i != 0){
				Set[i] = Set[i-1];
				Set[i-1] = target;
			}

			return 1;
		}
	}
	return 0;


}



int main(){
	int list[] = {1,2,3,4,100,200};
	
	for(int i = 0; i < 6; i++){
		printf("List[%d]: %d\n", i, list[i] );
	}
	
	printf("============= \n");
	LinearSearchMTF(list, 100, 6);
	for(int i = 0; i < 6; i++){
		printf("List[%d]: %d\n", i, list[i] );
	}
	
	printf("============= \n");
	LinearSearchTM(list, 200, 6);
	for(int i = 0; i < 6; i++){
		printf("List[%d]: %d\n", i, list[i] );
	}
	
	printf("============= \n");
	LinearSearchTM(list, 200, 6);
	for(int i = 0; i < 6; i++){
		printf("List[%d]: %d\n", i, list[i] );
	}
	return 0;
}
