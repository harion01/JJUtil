#include <stdio.h>

int main(){
	int args[3];
	args[0] = 0;
	args[1] = 1;
	args[2] = 2;
	args[3] = 3;

	int* argspointer;
	argspointer = args;

	int cnt;

	
	for(cnt =0 ; cnt < 3+1; cnt++){
		printf("args address [%p] args value [%d] \n", &args[cnt] , args[cnt]);
	}

	for(cnt =0 ; cnt < 3+1; cnt++){
		printf("argspointer [%p] args[] [%d] \n", argspointer , *argspointer);
		argspointer++;
	}

	return 0;
}
