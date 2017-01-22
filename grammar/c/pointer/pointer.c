#include <stdio.h>

int main(){
	
	int arg;
	arg = 10;

	int* argpoint;
	argpoint = &arg; //copy address 

	printf("arg is [%d] \n", arg);
	printf("argpoint is [%p] value of argpoint is [%d] address of arg [%p] \n", argpoint, *argpoint, &arg);
	
	return 0;
}
