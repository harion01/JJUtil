#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class noseqsort {
	private :
		int originsize;
		int originarr[50];
		int shirinksize;
		int shirinkarr[50];

		void shirink();
		void sort();
		void nonseq();
	public :
		noseqsort(int *numbers, int size);
		void printargs();
		void nonseqsort();
		void checknswap(int index);

};

noseqsort::noseqsort(int *numbers, int size){
	this->originsize = size;
	for(int cnt=0; cnt < size ; cnt++){
		this->originarr[cnt] = numbers[cnt];
	}
	this->shirinksize = 0;
}

void noseqsort::printargs(){
	int count;
	cout << "origin size [" << this->originsize << "]" << endl;
	for ( count = 0 ; count < this->originsize; count++ ){
		cout <<  this->originarr[count] << " " ;
	}
	cout << endl;

	cout << "shirink size [" << this->shirinksize << "]" << endl;
	for ( count = 0 ; count < this->shirinksize; count++ ){
		cout <<  this->shirinkarr[count] << " " ;
	}	
	cout << endl;
}


void noseqsort::nonseqsort(){
	cout << "print inital values " << endl;
	printargs();
	
	sort();
	cout << "print sorted values " << endl;
	printargs();

	shirink();
	cout << "print shirinked values " << endl;
	printargs();

	nonseq();
	cout << "print non-seq values " << endl;
	printargs();
}


void noseqsort::sort(){
	//time complex : O(n^2)
	int count, swap, loop;
	for(loop = 0; loop< this->originsize; loop++ ) {   //T(n) = n
		for(count = 1 ; count < this->originsize-loop; count++){  //T(n) = (n-1)/2
			if(this->originarr[count-1] > this->originarr[count]){  //ordering point
				swap = this->originarr[count];
				this->originarr[count] = this->originarr[count-1];
				this->originarr[count-1] = swap;
			}
		}
		//printf("loop [%d] end \n",loop);
	}
	//T(n) = n(n-1)/2  ; therefore, O(n(n-1)/2) = O(n^2)
}

void noseqsort::shirink(){

}


void noseqsort::nonseq(){
	int cnt;
	int swap;
	for(cnt = 0 ; cnt+1 < this->originsize ; cnt++){
		if(this->originarr[cnt]+1 == this->originarr[cnt+1]){
			if(cnt+2 < this->originsize){
				if(this->originarr[cnt]+2 == this->originarr[cnt+2]){
					swap = this->originarr[cnt+1];
					this->originarr[cnt+1] = this->originarr[cnt+2];
					this->originarr[cnt+2] = swap;
					continue;
				}
			}
			swap = this->originarr[cnt];
			this->originarr[cnt] = this->originarr[cnt+1];
			this->originarr[cnt+1] = swap;
		}
	}
}


int main(){
	int array[100];
	int limit, count, comp, swap, ret;

	printf("Enter number of elements\n");
	scanf("%d", &limit);

	printf("Enter %d integers\n", limit);

	for (count = 0; count < limit; count++)
		scanf("%d", &array[count]);

	
	noseqsort nss(array, limit);
	nss.nonseqsort();


	return 0;

}
